#!/usr/bin/perl
use warnings; use strict;
use utf8; use open 'utf8'; binmode(STDOUT, ':utf8');
use lib '/usr/local/oracc/lib';
use ORACC::P2::Util2;
use ORACC::XML;
use Encode;

my $list = '';
my %param = ();
my $res = undef;
my $search = '';
my $serialize = 1;
my $session = '';
my $tmpdir = '';
my %values = ();
my $verbose = 0;
my $xdata = undef;
my $xsl = "/usr/local/oracc/lib/scripts";

$xdata = ORACC::P2::Util2::decode_args_or_cgi();

if ($xdata) {
    my $payload = $xdata->getDocumentElement()->localName();
    if ($payload ne 'search') {
	die "p2-browse.plx: wrong XML payload; found `$payload' but expected 'search')\n";
    }
    %values = ORACC::P2::Util2::set_values($xdata)
}

# values on command line override those in an xml file
foreach my $p (keys %param) {
    $values{$p} = $param{$p};
}

($session,$list,$tmpdir) 
    = ORACC::P2::Util2::setup_tmpdir($xdata,\%values);

unless ($xdata) {
    $xdata = fake_search();
    die "p2-search.plx: failed to load or fake instance data\n"
	unless $xdata;
    %values = ORACC::P2::Util2::set_values($xdata);
}

ORACC::P2::Util2::save_instance($tmpdir,$xdata);

my $search_transform = load_xsl("$xsl/oas-SEARCH.xsl");
$res = eval { $search_transform->transform($xdata) };
unless ($res) {
    print STDERR "oas-SEARCH.xsl failed\n";
    print STDERR "---\nTransform reports:\n$@\n---\n";
    exit 1; # return error
} else {
    print STDERR " ok\n" if $verbose;
}

$search = $search_transform->output_string($res);
Encode::_utf8_on($search);
run_search($search);

my $return_transform = load_xsl("$xsl/oas-RETURN.xsl");
$res = eval { $return_transform->transform($xdata, 
					   results=>"'$tmpdir/results.xml'",
					   search=>"'$search'") };
unless ($res) {
    print STDERR "oas-RETURN.xsl failed\n";
    print STDERR "---\nTransform reports:\n$@\n---\n";
    exit 1; # return error
} else {
    print STDERR " ok\n" if $verbose;
}

$serialize = 0 if $values{'serialize'} eq 'false';
ORACC::P2::Util2::emit_instance($tmpdir, $res, 'search', $serialize);

1;

#######################################################

sub
fake_search {
    my %newdata = (
	session=>$session || '',
	list=>$list || '',
	project=>$values{'project'} || '',
	'default-index'=>$values{'default-index'} || '',
	'serialize'=>$values{'serialize'} || '',
	'use-unicode'=>$values{'use-unicode'} || '',
	);
    $newdata{'use-unicode'} = 'false'
	unless $newdata{'use-unicode'} =~ /^true|false$/;
    if ($values{'glossary'}) {
	$newdata{'default-index'} = "cbd/$values{'glossary'}";
    } else {
	$newdata{'default-index'} = 'txt'
	    unless $newdata{'default-index'} =~ /^cat|txt|lem|tra$/;
    }
    $xdata = ORACC::P2::Util2::load_default_instance('search');
    ORACC::P2::Util2::set_data($xdata,%newdata);
    my @toks = tags($xdata,undef,'toks');
    $toks[0]->appendTextNode($values{'search'})
	if $values{'search'};
    $xdata;
}

sub
run_search {
    open(D,">$tmpdir/search.txt");
    binmode(D,':raw');
    print D $_[0];
    close(D);
    my $use_unicode = $values{'use-unicode'};
    my $arg8 = '';
    $arg8 = "8" if $use_unicode eq 'true';
    system 'se', "-s${arg8}2x", $tmpdir;
}