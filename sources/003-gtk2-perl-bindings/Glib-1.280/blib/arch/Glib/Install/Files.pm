package Glib::Install::Files;

$self = {
          'inc' => ' -I. -mms-bitfields -IC:/devel/Shortcake/sandbox/perl/include/glib-2.0 -IC:/devel/Shortcake/sandbox/perl/lib/glib-2.0/include   -mms-bitfields -IC:/devel/Shortcake/sandbox/perl/include/glib-2.0 -IC:/devel/Shortcake/sandbox/perl/lib/glib-2.0/include  ',
          'typemaps' => [
                          'typemap'
                        ],
          'deps' => [],
          'libs' => '-LC:/devel/Shortcake/sandbox/perl/lib -lgobject-2.0 -lgthread-2.0 -lglib-2.0 -lintl   -LC:/devel/Shortcake/sandbox/perl/lib -lgthread-2.0 -lglib-2.0 -lintl  '
        };


# this is for backwards compatiblity
@deps = @{ $self->{deps} };
@typemaps = @{ $self->{typemaps} };
$libs = $self->{libs};
$inc = $self->{inc};

	$CORE = undef;
	foreach (@INC) {
		if ( -f $_ . "/Glib/Install/Files.pm") {
			$CORE = $_ . "/Glib/Install/";
			last;
		}
	}

1;
