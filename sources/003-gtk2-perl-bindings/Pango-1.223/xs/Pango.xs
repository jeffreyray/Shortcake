/*
 * Copyright (c) 2008 by the gtk2-perl team (see the file AUTHORS)
 *
 * Licensed under the LGPL, see LICENSE file for more information.
 */

#include "pango-perl.h"

MODULE = Pango		PACKAGE = Pango		PREFIX = PANGO_

BOOT:
#include "register.xsh"
#include "boot.xsh"
	gperl_handle_logs_for ("Pango");

# Don't doc these in Pango, or we'll clobber the main POD page!

=for object Pango::version
=cut

=for see_also L<Gtk2::version>
=cut

=for see_also L<Glib::version>
=cut

=for apidoc
=for signature (MAJOR, MINOR, MICRO) = Pango->GET_VERSION_INFO
Fetch as a list the version of pango with which the Perl module was built.
=cut
void
GET_VERSION_INFO (class)
    PPCODE:
	EXTEND (SP, 3);
	PUSHs (sv_2mortal (newSViv (PANGO_MAJOR_VERSION)));
	PUSHs (sv_2mortal (newSViv (PANGO_MINOR_VERSION)));
	PUSHs (sv_2mortal (newSViv (PANGO_MICRO_VERSION)));
	PERL_UNUSED_VAR (ax);

bool
PANGO_CHECK_VERSION (class, int major, int minor, int micro)
    C_ARGS:
	major, minor, micro
