#!/usr/bin/perl
use warnings; use strict; use open ':utf8'; use utf8; 
use Encode;

my $lang = '';
my($project,$k1) = @ARGV;

my $u = unescape($k1);
my $u_utf8;

if (!($u_utf8 = decode_utf8($u))) {
    $u_utf8 = encode_utf8($u);
}

my $un_k1 = $u_utf8;

$un_k1 =~ tr/\x{b1}\x{b4}\x{20e5}/+'\\/;

warn "p2-sig.plx: project=`$project'; k1=`$k1'; escaped=`$un_k1'\n";

my($p,$l) = ($un_k1 =~ /\@(.*?)\%(.*?):/);

if ($un_k1 =~ /\][A-Z]N'.*?\}::/ || $un_k1 =~ /\][A-Z]N/) {
    $lang = $l = 'qpn';
}

$p = '' unless $p;
$l = '' unless $l;

$lang = $l unless $lang;

my $map1 = "/usr/local/oracc/bld/$project/$lang/$lang.map"; # try the local project/lang first
my $map2 = "/usr/local/oracc/bld/$p/$l/$l.map"; # fall back to the source project/lang

if ($map1 eq $map2) {
    $map2 = '-';
}
warn "sigmap $map1 $map2 $un_k1\n";

exec("/usr/local/oracc/bin/sigmap", $un_k1, $map1, $map2, "$project/cbd/$lang", $lang)
    || die "p2-sig.plx: exec failed\n";

############################################################################################

sub
unescape {
    my $t = shift;
    $t =~ s/\%([0-9A-Za-z][0-9A-Za-z])/hex("0x$1")/eg;
    $t;
}