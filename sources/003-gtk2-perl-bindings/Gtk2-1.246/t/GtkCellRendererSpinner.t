#!/usr/bin/env perl
use Gtk2::TestHelper
  tests => 1,
  noinit => 1,
  at_least_version => [2, 20, 0, "Gtk2::CellRendererSpinner is new in 2.20"];

my $spinner = Gtk2::CellRendererSpinner->new;
isa_ok ($spinner, 'Gtk2::CellRendererSpinner');

__END__

Copyright (C) 2010 by the gtk2-perl team (see the file AUTHORS for the
full list).  See LICENSE for more information.
