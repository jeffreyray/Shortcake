#!/usr/bin/perl -w
use strict;


chdir 'sandbox\perl\lib' 
        or die "Could not change to target directory";

for my $file ( <*.dll.a> ) {
    my $new = $file;
    $new =~ s/.dll//;
    print "$file -> $new\n";
    rename $file, $new;
}