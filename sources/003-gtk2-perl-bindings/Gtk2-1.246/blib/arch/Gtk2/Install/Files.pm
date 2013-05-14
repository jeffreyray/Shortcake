package Gtk2::Install::Files;

$self = {
          'inc' => '-mms-bitfields -IC:/devel/Shortcake/sandbox/perl/include/gtk-2.0 -IC:/devel/Shortcake/sandbox/perl/lib/gtk-2.0/include -IC:/devel/Shortcake/sandbox/perl/include/atk-1.0 -IC:/devel/Shortcake/sandbox/perl/include/cairo -IC:/devel/Shortcake/sandbox/perl/include/gdk-pixbuf-2.0 -IC:/devel/Shortcake/sandbox/perl/include/pango-1.0 -IC:/devel/Shortcake/sandbox/perl/include/glib-2.0 -IC:/devel/Shortcake/sandbox/perl/lib/glib-2.0/include -IC:/devel/Shortcake/sandbox/perl/include -IC:/devel/Shortcake/sandbox/perl/include/freetype2 -IC:/devel/Shortcake/sandbox/perl/include/libpng14   -I./build ',
          'typemaps' => [
                          'gtk2perl.typemap',
                          'gdk.typemap',
                          'gtk.typemap'
                        ],
          'deps' => [
                      'Pango',
                      'Glib',
                      'Cairo'
                    ],
          'libs' => '-LC:/devel/Shortcake/sandbox/perl/lib -lgtk-win32-2.0 -lgdk-win32-2.0 -latk-1.0 -lgio-2.0 -lpangowin32-1.0 -lgdi32 -lpangocairo-1.0 -lgdk_pixbuf-2.0 -lpango-1.0 -lcairo -lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lglib-2.0 -lintl  '
        };


# this is for backwards compatiblity
@deps = @{ $self->{deps} };
@typemaps = @{ $self->{typemaps} };
$libs = $self->{libs};
$inc = $self->{inc};

	$CORE = undef;
	foreach (@INC) {
		if ( -f $_ . "/Gtk2/Install/Files.pm") {
			$CORE = $_ . "/Gtk2/Install/";
			last;
		}
	}

1;
