use strict;
use warnings;

use File::Basename qw( fileparse );
use File::Copy qw( copy );
use File::Path qw( make_path );

# process args
my ( $name, $file1, $file2 ) = @ARGV;

if ( ! $name || ! $file1 || ! $file2 ) {
    print "usage: $0 package-name snapshot-1.txt snapshot-2.txt\n";
    exit;
}

# add folder prefixes to file names
$name = 'packages/' . $name;
$file1 = 'snapshots/' . $file1 if $file1 !~ /^snapshots/;
$file2 = 'snapshots/' . $file2 if $file2 !~ /^snapshots/;

# check for $file1 and $file2
die "snapshot $file1 does not exist\n" if ! -f $file1;
die "snapshot $file2 does not exist\n" if ! -f $file2;

# diff file
my $diff = `diff -u $file1 $file2`;

# determine package files
my @package_files;
for ( split "\n", $diff ) {
    next if /^\+\+/;
    next if /^[^+]/;
    s/^\+//;
    next if ! -f "sandbox/$_";
    push @package_files, $_;
}

if ( -f "$name.txt" ) {
    print "$name.txt already exists, overwrite? [y/N]\n";
    my $response = <STDIN>;
    exit if $response !~ /^y/i;
}

# create package list
open my $LIST, ">$name.txt";
flock $LIST, 2;
print $LIST join "\n", @package_files;
close $LIST;

# make path for package
make_path( "$name" ) if ! -d "$name";

# copy files
for my $file ( @package_files ) {
    my $source = "sandbox/$file";
    
    my $target = "$name/$file";
    print $target, "\n";
    my ( $fname, $dir ) = fileparse( $target );
    make_path( $dir ) if ! -d $dir;
    
    copy( "sandbox/$file", "$name/$file" ) or die $!;
}

