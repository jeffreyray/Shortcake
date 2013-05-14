package Pango::Install::Files;

$self = {
          'inc' => '-mms-bitfields -IC:/devel/Shortcake/sandbox/perl/include/pango-1.0 -IC:/devel/Shortcake/sandbox/perl/include/glib-2.0 -IC:/devel/Shortcake/sandbox/perl/lib/glib-2.0/include   -I./build -mms-bitfields -IC:/devel/Shortcake/sandbox/perl/include/pango-1.0 -IC:/devel/Shortcake/sandbox/perl/include/cairo -IC:/devel/Shortcake/sandbox/perl/include/glib-2.0 -IC:/devel/Shortcake/sandbox/perl/lib/glib-2.0/include -IC:/devel/Shortcake/sandbox/perl/include -IC:/devel/Shortcake/sandbox/perl/include/freetype2 -IC:/devel/Shortcake/sandbox/perl/include/libpng14  ',
          'typemaps' => [
                          'pango-perl.typemap',
                          'pango.typemap'
                        ],
          'deps' => [
                      'Glib',
                      'Cairo'
                    ],
          'libs' => '-LC:/devel/Shortcake/sandbox/perl/lib -lpango-1.0 -lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lglib-2.0 -lintl  -LC:/devel/Shortcake/sandbox/perl/lib -lpangocairo-1.0 -lpango-1.0 -lcairo -lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lglib-2.0 -lintl  '
        };


# this is for backwards compatiblity
@deps = @{ $self->{deps} };
@typemaps = @{ $self->{typemaps} };
$libs = $self->{libs};
$inc = $self->{inc};

	$CORE = undef;
	foreach (@INC) {
		if ( -f $_ . "/Pango/Install/Files.pm") {
			$CORE = $_ . "/Pango/Install/";
			last;
		}
	}

1;
