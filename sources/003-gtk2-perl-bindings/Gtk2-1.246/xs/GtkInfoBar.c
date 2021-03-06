/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkInfoBar.xs. Do not edit this file, edit GtkInfoBar.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkInfoBar.xs"
/*
 * Copyright 2010 by the gtk2-perl team (see the file AUTHORS)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include "gtk2perl.h"
#include "gtk2perl-private.h" /* for the custom response id handling */

#line 31 "xs\\GtkInfoBar.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)    S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage        S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 173 "xs\\GtkInfoBar.c"

XS_EUPXS(XS_Gtk2__InfoBar_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__InfoBar_new)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items < 1)
       croak_xs_usage(cv,  "class, ...");
    {
#line 84 "xs\\\\GtkInfoBar.xs"
	int i;
	GtkWidget * info_bar;
#line 186 "xs\\GtkInfoBar.c"
	GtkWidget *	RETVAL;
#line 87 "xs\\\\GtkInfoBar.xs"
	PERL_UNUSED_VAR (ix);
	if (items == 1) {
		/* the easy way out... */
		info_bar = gtk_info_bar_new ();
	} else if ( !(items % 2) ) {
		croak ("USAGE: Gtk2::InfoBar->new ()\n"
		       "  or Gtk2::InfoBar->new (...)\n"
		       "  where ... is a series of button text and response id pairs");
	} else {
		/* we can't really pass on a varargs call (at least, i don't
		 * know how to convert from perl stack to C va_list), so we
		 * have to duplicate a bit of the functionality of the C
		 * version.  luckily it's nothing too intense. */

		info_bar = gtk_info_bar_new ();

		for (i = 1; i < items; i += 2) {
			gchar * text = SvGChar (ST (i));
			int response_id =
				gtk2perl_dialog_response_id_from_sv (ST (i+1));
			gtk_info_bar_add_button (GTK_INFO_BAR (info_bar), text,
			                         response_id);
		}
	}
	RETVAL = info_bar;
#line 214 "xs\\GtkInfoBar.c"
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__InfoBar_add_button); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__InfoBar_add_button)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "info_bar, button_text, response_id");
    {
	GtkInfoBar *	info_bar = SvGtkInfoBar (ST(0))
;
	const gchar *	button_text;
	SV *	response_id = ST(2)
;
	GtkWidget *	RETVAL;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	button_text = (const gchar *)SvPV_nolen (ST(1))
;
#line 122 "xs\\\\GtkInfoBar.xs"
	RETVAL = gtk_info_bar_add_button (info_bar, button_text,
	                                  gtk2perl_dialog_response_id_from_sv (
	                                    response_id));
#line 244 "xs\\GtkInfoBar.c"
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__InfoBar_add_buttons); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__InfoBar_add_buttons)
{
    dVAR; dXSARGS;
    if (items < 1)
       croak_xs_usage(cv,  "info_bar, ...");
    {
	GtkInfoBar *	info_bar = SvGtkInfoBar (ST(0))
;
#line 138 "xs\\\\GtkInfoBar.xs"
	int i;
#line 263 "xs\\GtkInfoBar.c"
#line 140 "xs\\\\GtkInfoBar.xs"
	if (!(items % 2))
		croak("gtk_info_bar_add_buttons: odd number of parameters");
	/* we can't make var args, so we'll call add_button for each */
	for (i = 1; i < items; i += 2)
		gtk_info_bar_add_button (info_bar, SvGChar (ST (i)),
		                         gtk2perl_dialog_response_id_from_sv (
		                           ST (i+1)));
#line 272 "xs\\GtkInfoBar.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__InfoBar_add_action_widget); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__InfoBar_add_action_widget)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "info_bar, child, response_id");
    {
	GtkInfoBar *	info_bar = SvGtkInfoBar (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	SV *	response_id = ST(2)
;
#line 157 "xs\\\\GtkInfoBar.xs"
	gtk_info_bar_add_action_widget (info_bar, child,
	                                gtk2perl_dialog_response_id_from_sv (
	                                  response_id));
#line 295 "xs\\GtkInfoBar.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__InfoBar_set_response_sensitive); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__InfoBar_set_response_sensitive)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "info_bar, response_id, setting");
    {
	GtkInfoBar *	info_bar = SvGtkInfoBar (ST(0))
;
	SV *	response_id = ST(1)
;
	gboolean	setting = (bool)SvTRUE(ST(2))
;
#line 171 "xs\\\\GtkInfoBar.xs"
	gtk_info_bar_set_response_sensitive (
		info_bar,
		gtk2perl_dialog_response_id_from_sv (response_id),
		setting);
#line 319 "xs\\GtkInfoBar.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__InfoBar_set_default_response); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__InfoBar_set_default_response)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "info_bar, response_id");
    {
	GtkInfoBar *	info_bar = SvGtkInfoBar (ST(0))
;
	SV *	response_id = ST(1)
;
#line 185 "xs\\\\GtkInfoBar.xs"
	gtk_info_bar_set_default_response (info_bar,
	                                   gtk2perl_dialog_response_id_from_sv (
	                                     response_id));
#line 340 "xs\\GtkInfoBar.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__InfoBar_response); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__InfoBar_response)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "info_bar, response_id");
    {
	GtkInfoBar *	info_bar = SvGtkInfoBar (ST(0))
;
	SV *	response_id = ST(1)
;

	gtk_info_bar_response(info_bar, gtk2perl_dialog_response_id_from_sv (response_id));
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__InfoBar_set_message_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__InfoBar_set_message_type)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "info_bar, type");
    {
	GtkInfoBar *	info_bar = SvGtkInfoBar (ST(0))
;
	GtkMessageType	type = SvGtkMessageType (ST(1))
;

	gtk_info_bar_set_message_type(info_bar, type);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__InfoBar_get_message_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__InfoBar_get_message_type)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "info_bar");
    {
	GtkInfoBar *	info_bar = SvGtkInfoBar (ST(0))
;
	GtkMessageType	RETVAL;

	RETVAL = gtk_info_bar_get_message_type(info_bar);
	ST(0) = newSVGtkMessageType (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__InfoBar_get_action_area); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__InfoBar_get_action_area)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "info_bar");
    {
	GtkInfoBar *	info_bar = SvGtkInfoBar (ST(0))
;
	GtkWidget *	RETVAL;

	RETVAL = gtk_info_bar_get_action_area(info_bar);
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__InfoBar_get_content_area); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__InfoBar_get_content_area)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "info_bar");
    {
	GtkInfoBar *	info_bar = SvGtkInfoBar (ST(0))
;
	GtkWidget *	RETVAL;

	RETVAL = gtk_info_bar_get_content_area(info_bar);
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__InfoBar); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__InfoBar)
{
    dVAR; dXSARGS;
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;

    {
        CV * cv;

        cv = newXS("Gtk2::InfoBar::new_with_buttons", XS_Gtk2__InfoBar_new, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::InfoBar::new", XS_Gtk2__InfoBar_new, file);
        XSANY.any_i32 = 0;
        newXS("Gtk2::InfoBar::add_button", XS_Gtk2__InfoBar_add_button, file);
        newXS("Gtk2::InfoBar::add_buttons", XS_Gtk2__InfoBar_add_buttons, file);
        newXS("Gtk2::InfoBar::add_action_widget", XS_Gtk2__InfoBar_add_action_widget, file);
        newXS("Gtk2::InfoBar::set_response_sensitive", XS_Gtk2__InfoBar_set_response_sensitive, file);
        newXS("Gtk2::InfoBar::set_default_response", XS_Gtk2__InfoBar_set_default_response, file);
        newXS("Gtk2::InfoBar::response", XS_Gtk2__InfoBar_response, file);
        newXS("Gtk2::InfoBar::set_message_type", XS_Gtk2__InfoBar_set_message_type, file);
        newXS("Gtk2::InfoBar::get_message_type", XS_Gtk2__InfoBar_get_message_type, file);
        newXS("Gtk2::InfoBar::get_action_area", XS_Gtk2__InfoBar_get_action_area, file);
        newXS("Gtk2::InfoBar::get_content_area", XS_Gtk2__InfoBar_get_content_area, file);
    }

    /* Initialisation Section */

#line 24 "xs\\\\GtkInfoBar.xs"
	gperl_signal_set_marshaller_for (GTK_TYPE_INFO_BAR, "response",
	                                 gtk2perl_dialog_response_marshal);

#line 483 "xs\\GtkInfoBar.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

