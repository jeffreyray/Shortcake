use strict;
use warnings;

use File::Basename qw( fileparse );
#use File::Copy qw( copy );
#use File::Path qw( make_path );

# process args
my (  $snapshot, $output ) = @ARGV;

if ( ! $snapshot  ) {
    print "usage: $0 snapshot.txt [archive]\n";
    exit;
}

if ( ! -f $snapshot ) {
    print "file $snapshot does not exist\n";
    exit;
}

if ( ! $output ) {
    my ( $name ) = fileparse ( $snapshot );
    $name =~ s/\..+?$//;
    $output = $name;
}

chdir 'build';
`tar -cvf - -T../$snapshot > ../$output.tar`;


