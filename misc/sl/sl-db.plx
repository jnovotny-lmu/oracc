#!/usr/bin/perl
use warnings; use strict; use utf8;
use lib "$ENV{'ORACC'}/lib";
use open 'utf8'; binmode STDERR, 'utf8';
use ORACC::XML;
use ORACC::NS;
use Encode;
use Fcntl;
use NDBM_File;
use ORACC::SE::Indexer;
use ORACC::SE::XML;
use ORACC::SE::DBM;
use ORACC::SE::TSV;

use constant { TOP=>0, SUB=>1 };

# This database uses the value as the primary key, with extensions
# to index homophones, containers, etc.  The value may be lower or
# upper case depending on whether the key data is a value or a sign
# name.
#
# The following extensions and cases are used:
#
#  <lower>		sign value
#  <lower>,h    	sign value homophones (gi1, gi2, gi3 etc.)
#  <lower>,aka    	sign value aliases (ga2 => ja2 etc.)
#  <lower>,forms    	sign forms (KA×GU, URU×GU etc.)
#
#  <upper>		sign name
#  <upper>,uchar       	sign in Unicode/utf8
#  <upper>,ucode       	sign's Unicode hex code
#  <upper>,c		sign names used in compounds
#  <upper>,cinit	sign names used in initial position in compounds
#  <upper>,clast	sign names used in final position in compounds
#  <upper>,contains	sign names used as containers
#  <upper>,contained	sign names used within containers
#  <upper>,multi	sign names repeated two-up, crossed, etc.
#  
# In addition, the special convention m,<mod> is used as a key which
# returns all the signs utilising a given mod, e.g., m,g returns all
# gunufied signs.
#
# Besides the actual data, the db also contains the XHTML link code to
# find the article for a sign by id; this is given under <id>,link.

my $project = `oraccopt`;
my $dc_uri = 'http://dublincore.org/documents/2003/06/02/dces/';
my $html_uri = 'http://www.w3.org/1999/xhtml';
my $sl_uri = 'http://oracc.org/ns/sl/1.0';
my $xml_uri = 'http://www.w3.org/XML/1998/namespace';
my $gdl_uri = 'http://oracc.org/ns/gdl/1.0';

my $dbdir = '02pub/'; system 'mkdir','-p',$dbdir;
my $dbbase = shift @ARGV;
my $dbname = "$dbbase-db";
my %db;

my %values = ();

my $xp = XML::LibXML->new();
my $sl = $xp->parse_file("02xml/$dbbase-sl.xml");
my $do_aliases = 1;
my $global_id = '';

# first load up %values with the sign names and values
foreach my $s ($sl->getDocumentElement()->getElementsByTagNameNS($sl_uri,
								 'sign')) {
    my $parent_id = subsign($s,TOP,undef);
    foreach my $f ($s->getElementsByTagNameNS($sl_uri,'form')) {
	subsign($f,SUB,$parent_id);
    }
}

add_aliases() if $do_aliases;

dump_db();

##################################################################

# add the sign components: each value is a space-delimited string of IDs
#   ,c entry for each one
#   ,cinit entry for each initial one (e.g., KI of KI.BI.GAR)
#   ,clast entry for each last one (e.g., GAR of KI.BI.GAR)
#   ,m<MOD> entry for each one followed by a modifier, e.g., ,mg for mod=gunu
#   ,xc entry for each container
#   ,xi entry for each inner sign (no attempt to preserve grouping etc.)
#   ,d<DELIM> for each sign that is repeated with DELIM, e.g., ,dover for NUN-over-NUN
sub
add_comp {
    my($id,$cg) = @_;
#    warn "add_comp $id ", $cg->toString(), "\n";
    my $atf = $cg->getAttribute('form');
    $atf =~ tr/\|//d;
    $values{$atf} = $id;
#    push @{$values{$id,'values'}}, "|$atf|";
#    my @g = $cg->getElementsByTagNameNS($gdl_uri,'g');
    add_comp_children($cg,$id);
}

sub
add_comp_children {
    my($parent,$id) = @_;
    my @g = grep ($_->isa('XML::LibXML::Element'), $parent->childNodes());
    foreach (my $i = 0; $i <= $#g; ++$i) {
	if ($g[$i]->localName() eq 'g') {
	    add_comp_children($g[$i]);
	} else {
	    next if $g[$i]->localName() eq 'o';
	    my $g = $g[$i];
	    my $n = $g->nextSibling();
	    my $gt = gtext($g,$n,$id);
	    push @{$values{$gt,'c'}}, $id;
	    if ($i == 0) {
		push @{$values{$gt,'cinit'}}, $id;
	    } elsif ($i == $#g) {
		push @{$values{$gt,'clast'}}, $id;
	    }
	    if ($n && $n->localName() eq 'o') {
		my $ng = $g[$i+2];
		if ($ng) {
		    my $ngt = gtext($ng,$ng->nextSibling(),$id);
		    if ($n->getAttributeNS($gdl_uri,'type') eq 'containing') {
			push @{$values{$gt,'contains'}}, $id;
			push @{$values{$ngt,'contained'}}, $id;
		    } elsif ($gt eq $ngt) {
			push @{$values{$gt,'multi'}}, $id;
		    }
		}
		++$i; # don't gtext this node
	    }
	}
    }
}

sub
gtext {
    my ($g,$n,$id) = @_;
    my $gt = undef;
    if ($g->nodeName() eq 'g:g') {
	$gt = join('', map { gval($_) } $g->childNodes());
    } else {
	$gt = $g->getAttribute('n') || $g->getAttribute('form') || $g->textContent();
    }
    warn "empty gtext in ", $g->toString(0), "\n"
	unless $gt;
    if ($gt) {
	$gt =~ tr/a-zšŋ/A-ZŠŊ/;
	if ($n && $n->localName() eq 'mod') {
	    my $mod = $n->getAttribute('c');
	    push @{$values{$gt,'m'}}, $id;
	    $gt .= '@' . $mod;
	    if ($values{$gt}) {
		push @{$values{'m',$mod}}, $values{$gt};
	    } else {
		my $xid = ($g->findnodes("ancestor::*[\@xml:id]/\@xml:id"))[0]->getValue();
		print STDERR "$xid: Component $gt not independently listed\n";
	    }
	}
	$gt;
    } else {
	my $xid = ($g->findnodes("ancestor::*[\@xml:id]/\@xml:id"))[0]->getValue();
	print STDERR "$xid: couldn't set \$gt\n";
	'';
    }
}

sub
gval {
    my $g = shift;
    return('') unless $g->isa('XML::LibXML::Element');
    my $n = $g->nodeName();
    if ($n eq 'g:s') {
	return $g->textContent();
    } elsif ($n eq 'g:o') {
	my $o = $g->getAttributeNS($GDL,'type');
	if ($o eq 'beside') {
	    return '.';
	} elsif ($o eq 'containing') {
	    return '×';
	} elsif ($o eq 'above') {
	    return '&';
	} elsif ($o eq 'crossing') {
	    return '%';
	} else {
	    warn "gval: unhandled o attr $o\n";
	    return '';
	}
    } else {
	warn "gval: unhandled tag $n\n";
	return '';
    }
}

sub
add_aliases {
    if (open(IN,'00lib/aliases.asa')) {
	while (<IN>) {
	    next if /^\#/ || /^\s+/ || /=>/;
	    my @v = split(/\s+/,$_);
	    my $aka = shift @v;
	    foreach my $v (@v) {
		$values{$v,'aka'} = $aka;
	    }
	}
	close(IN);
    } else {
	warn "sl-db.plx: no aliases file 00lib/aliases.asa\n";
	return;
    }
}

sub
dump_db {
    unlink "$dbdir/$dbname";
#    tie(%db, 'NDBM_File', "$dbdir/$dbname", O_RDWR|O_CREAT|O_TRUNC, 0644) 
#	|| die "mk-pslu.plx: can't write $dbdir/$dbname\n";
    my $ix = ORACC::SE::Indexer::index('ogsl','OGSL Index','x1',0,
				       [ qw/h aka c cinit clast contains contained forms multi mod link/ ],
				       [], 0, 10000, 0, 1);
    my %db = %$ix;
    foreach my $k (keys %values) {
	my $dbk = $k;
	Encode::_utf8_off($dbk);
	# sort the values here if the key otherwise contains a \^
	if ($dbk =~ /(?:link|name|atf|aka|uchar|ucode)$/) {
	    my $v = $values{$k};
	    Encode::_utf8_off($v);
	    $db{$dbk} = $v;
	} elsif ($dbk =~ /h$/) {
	    my $str = hsort(@{$values{$k}});	    
	    $db{$dbk} = $str;
	    if ($k =~ /₊/) {
		$k =~ s/h$//;
#		print STDERR "mk-pslu.plx: h-str for $k = $str\n";
	    }
	} elsif ($dbk =~ /forms$/) {
	    my $str = fsort(@{$values{$k}});
	    $db{$dbk} = $str;
	    if ($k =~ /₊/) {
		$k =~ s/h$//;
#		print STDERR "mk-pslu.plx: h-str for $k = $str\n";
	    }
	} elsif ($dbk =~ //) {
	    my $v = join(' ', sort uniq(grep(defined,@{$values{$k}}))); # FIXME: shouldn't be necessary to grep out defined
	    Encode::_utf8_off($v);
	    $db{$dbk} = $v;
	} else {
	    my $v = $values{$k};
	    Encode::_utf8_off($v);
	    $db{$dbk} = $v;
	}
    }

    ORACC::SE::DBM::setdir('./02pub');
#    ORACC::SE::XML::toXML(\%db);
    ORACC::SE::TSV::toTSV(\%db);
#    ORACC::SE::DBM::create($db{'#name'});

#    ORACC::SE::XML::toXML(\%db);
#    use Data::Dumper; open(D,'>./02pub/pslu.dump'); binmode(D, ':raw'); print D Dumper(\%db); close(D);
    untie %db;
}


sub
xdump_db {
    unlink "$dbdir/$dbname";
    tie(%db, 'NDBM_File', "$dbdir/$dbname", O_RDWR|O_CREAT|O_TRUNC, 0644) 
	|| die "sl-db.plx: can't write $dbdir/$dbname\n";
    foreach my $k (keys %values) {
	my $dbk = $k;
	Encode::_utf8_off($dbk);
	# This first group is keys which have singleton values
	if ($dbk =~ /(?:link|name|aka|uchar|ucode)$/) {
	    my $v = $values{$k};
	    Encode::_utf8_off($v);
	    $db{$dbk} = $v;
	} elsif ($dbk =~ /h$/) {
	    # sort homophones
	    my $str = hsort(@{$values{$k}});	    
	    $db{$dbk} = $str;
### WHAT WAS THIS SUPPOSED TO DO?
#	    if ($k =~ /ₓ/) {
#		$k =~ s/h$//;
#	    }
	} elsif ($dbk =~ //) {
	    if (defined $values{$k}) {
#		use Data::Dumper; warn "dbk=$dbk\n"; warn Dumper $values{$k};
		my $v = join(' ', sort uniq(grep(defined, @{$values{$k}})));
		Encode::_utf8_off($v);
		$db{$dbk} = $v;
	    } else {
		warn "sl-db.plx: unhandled key type $dbk\n";
	    }
	} else {
	    my $v = $values{$k};
	    Encode::_utf8_off($v);
	    $db{$dbk} = $v;
	}
    }
#    ORACC::SE::DBM::setdir('./02www/db');
    $db{'#name'} = $dbname;
    $db{'#fields'} = join(' ', qw/h aka c cinit clast contains contained multi mod link values/);
#    ORACC::SE::XML::toXML(\%db);
    use Data::Dumper; open(D,">./02pub/$dbname.dump"); binmode(D, ':raw'); print D Dumper(\%db); close(D);
    untie %db;
}

sub
fsort {
    my @srt = @_;
    my @ret = ();
    foreach my $s (sort { $$a[1] cmp $$b[1] } @srt) {
	push @ret, "$$s[0]/$$s[1]";
    }
    join(' ', @ret);
}

sub
hsort {
    my @srt = @_;
    my @ret = ();
    foreach my $s (sort { vkey($a) <=> vkey($b) } @srt) {
	push @ret, $$s[0].'/'.vkey($s);
    }
    join(' ', @ret);
}

sub
uniq {
    my %tmp;
    @tmp{@_} = ();
    keys %tmp;
}

sub
vkey {
    my $x = shift;
    my $v = $$x[1];
    my $num = 0;

    if ($v =~ /([0-9₀₁₂₃₄₅₆₇₈₉]+)$/) {
	my $n = $1;
	$n =~ tr/₀-₉/0-9/;
	$num = $n;
    } else {
	$num = 0;
    }

    if ($v =~ /ₓ/) {
	$num += 1000;
    }

    $num;
}

sub
subsign {
    my($node,$mode,$parent_id) = @_;

    return if $node->hasAttribute('deprecated') && $node->getAttribute('deprecated') eq '1';

    my $type = $node->getAttribute('type');
#    next unless $type eq 'normal' || $type eq 'numeric';

    my $id = $node->getAttributeNS($xml_uri,'id');
    my $sn = $node->getAttribute('n');

#    if ($parent_id) {
#	warn "FORM: parent-id=$parent_id; form id=$id; sn=$sn\n";
#    } else {
#	warn "SIGN: id=$id; sn=$sn\n";
#    }

    my($ucode,$uchar) = ('','');
    my @v = ();

    if ($parent_id) {
	my $var = $node->getAttribute('var');
	warn "FORM $sn in SIGN $values{$parent_id,'name'} has no VAR attribute\n" unless $var;
	push @{$values{$parent_id,'forms'}}, [$id,$var];
    }

    foreach my $c ($node->childNodes()) {
	my $lname = $c->localName();

	last if $lname eq 'form' && $mode == TOP;
	if ($lname eq 'utf8') {
	    $ucode = $c->getAttribute("hex");
	    $uchar = $c->textContent();
	} elsif ($lname eq 'list') {
	    # add the num entries (e.g. REC144)
	    my $n = $c->getAttribute('n');
	    my $n_orig = $n;
	    $values{$n} = $id;
	    $n =~ s/\d+[a-z]*$//;
	    push @{$values{$n,'h'}}, [$id,$n_orig];
	} elsif ($lname eq 'v') {
	    my $v = $c->getAttribute('n');
	    $v =~ tr/?//d;
	    $v =~ s/\{.*?\}//g;
	    next unless $v;
	    if ($values{$v}) {
		### FIXME: THIS IS A TODO LIST ITEM IN OGSL
#		warn "duplicate value in ogsl-sl.xml: $v occurs in $values{$values{$v},'name'} and $sn\n"
#		    unless !defined($v) || !length($v) || $v  =~ /ₓ/ || $v =~ /\.\.\./;
	    } else {
		$values{$v} = $id;
	    }
	    push(@{$values{$id,'values'}}, $v) if $v;
	    # homophones: each value is a space-delimited string of IDs
	    #   strip off the digits
	    #   add the id to the entry $v,h
	    my $v_orig = $v;
	    $v =~ s/[₊₀-₉]*$//;
	    push @{$values{$v,'h'}}, [$id,$v_orig];
	} elsif ($lname eq 'name') {
	    foreach my $gc (tags($c,$GDL,'c')) {
		add_comp($id,$gc);
	    }
	}
    }
    
    my $xsn = $sn;
    $xsn =~ tr/|//d;
    $values{$xsn} = $id;
    $values{$id,'ucode'} = $ucode if $ucode;
    $values{$id,'uchar'} = $uchar if $uchar;
    $values{$id,'name'} = $sn;
    $id;
}
