use strict;
use warnings;

use File::Basename qw( fileparse );
use File::Copy qw( copy );
use File::Path qw( make_path );

# process args
my (  $name ) = @ARGV;

if ( ! $name  ) {
    print "usage: $0 output.txt\n";
    exit;
}
if ( ! -d  'sandbox' ) {
    print "could not find sandbox directory\n";
    exit;
}

# prefix snapshot to $name
$name = 'snapshots/' . $name;

if ( -f $name ) {
    print "output file $name exists, overwrite? [y/N]\n";
    my $response = <STDIN>;
    exit if $response !~ /^y/i;
}

# determine package files
my @snapshot_files;
for ( split "\n", `xfind sandbox | sed -e "{/^sandbox\$/d;s/sandbox[\\]*//;s/\\/\//g;}"` ) {
    next if -d && ! -f;
    push @snapshot_files, $_;
}

open my $FILE, ">$name" or die "Could not open file $name for writing";
flock $FILE, 2;
print $FILE join "\n", @snapshot_files;
close $FILE;