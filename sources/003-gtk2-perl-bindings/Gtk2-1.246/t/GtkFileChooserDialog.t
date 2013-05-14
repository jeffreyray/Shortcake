#
# $Id$
#

use Gtk2::TestHelper
	at_least_version => [2, 4, 0, "GtkFileChooser is new in 2.4"],
	tests => 6;


my $dialog = Gtk2::FileChooserDialog->new ('some title', undef, 'save',
                                           'gtk-cancel' => 'cancel',
                                           'gtk-ok' => 'ok');

isa_ok ($dialog, 'Gtk2::FileChooserDialog');
ginterfaces_ok($dialog);

is ($dialog->get_action, 'save');

$dialog = Gtk2::FileChooserDialog->new_with_backend ('some title', undef,
                                                     'open',
                                                     'backend',
                                                     'gtk-cancel' => 'cancel',
                                                     'gtk-ok' => 'ok');

isa_ok ($dialog, 'Gtk2::FileChooserDialog');
isa_ok ($dialog, 'Gtk2::FileChooser');

is ($dialog->get_action, 'open');


__END__

Copyright (C) 2003 by the gtk2-perl team (see the file AUTHORS for the
full list).  See LICENSE for more information.
