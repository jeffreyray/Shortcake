/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkLinkButton.xs. Do not edit this file, edit GtkLinkButton.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkLinkButton.xs"
/*
 * Copyright (c) 2006 by the gtk2-perl team (see the file AUTHORS)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the 
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330, 
 * Boston, MA  02111-1307  USA.
 *
 * $Id$
 */

#include "gtk2perl.h"

static GPerlCallback *
gtk2perl_link_button_uri_func_create (SV * func,
                                      SV * data)
{
	GType param_types[2];
	param_types[0] = GTK_TYPE_LINK_BUTTON;
	param_types[1] = G_TYPE_STRING;
	return gperl_callback_new (func, data, G_N_ELEMENTS (param_types),
				   param_types, G_TYPE_NONE);
}

static void
gtk2perl_link_button_uri_func (GtkLinkButton *button,
                               const gchar *link,
                               gpointer user_data)
{
	GPerlCallback * callback = (GPerlCallback*) user_data;

	gperl_callback_invoke (callback, NULL, button, link);
}

#line 55 "xs\\GtkLinkButton.c"
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

#line 197 "xs\\GtkLinkButton.c"

XS_EUPXS(XS_Gtk2__LinkButton_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__LinkButton_new)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "class, url, label=NULL");
    {
	GtkWidget *	RETVAL;
	const gchar *	url;
	const gchar *	label;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	url = (const gchar *)SvPV_nolen (ST(1))
;

	if (items < 3)
	    label = NULL;
	else {
	    /* same as SvGChar(), but not in a function */
	    sv_utf8_upgrade (ST(2));
	    label = (const gchar *)SvPV_nolen (ST(2))
;
	}
#line 52 "xs\\\\GtkLinkButton.xs"
        PERL_UNUSED_VAR (ix);
        if (label)
                RETVAL = gtk_link_button_new_with_label (url, label);
        else
                RETVAL = gtk_link_button_new (url);
#line 230 "xs\\GtkLinkButton.c"
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__LinkButton_get_uri); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__LinkButton_get_uri)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "link_button");
    {
	const gchar *	RETVAL;
	GtkLinkButton *	link_button = SvGtkLinkButton (ST(0))
;

	RETVAL = gtk_link_button_get_uri(link_button);
	ST(0) = sv_newmortal();
	/* same as newSVGChar(), but not in a function */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__LinkButton_set_uri); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__LinkButton_set_uri)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "link_button, uri");
    {
	GtkLinkButton *	link_button = SvGtkLinkButton (ST(0))
;
	const gchar *	uri;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	uri = (const gchar *)SvPV_nolen (ST(1))
;

	gtk_link_button_set_uri(link_button, uri);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__LinkButton_set_uri_hook); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__LinkButton_set_uri_hook)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "class, func, data=NULL");
    {
	SV *	func = ST(1)
;
	SV *	data;

	if (items < 3)
	    data = NULL;
	else {
	    data = ST(2)
;
	}
#line 74 "xs\\\\GtkLinkButton.xs"
        if (!gperl_sv_is_defined (func)) {
		gtk_link_button_set_uri_hook (NULL, NULL, NULL);
	} else {
		GPerlCallback * callback;
		callback = gtk2perl_link_button_uri_func_create (func, data);
		gtk_link_button_set_uri_hook
			(gtk2perl_link_button_uri_func,
			 callback,
			 (GDestroyNotify) gperl_callback_destroy);
	}
#line 309 "xs\\GtkLinkButton.c"
    }
    XSRETURN_EMPTY;
}

#if GTK_CHECK_VERSION (2, 14, 0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__LinkButton_get_visited); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__LinkButton_get_visited)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "link_button");
    {
	gboolean	RETVAL;
	GtkLinkButton *	link_button = SvGtkLinkButton (ST(0))
;

	RETVAL = gtk_link_button_get_visited(link_button);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__LinkButton_set_visited); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__LinkButton_set_visited)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "link_button, visited");
    {
	GtkLinkButton *	link_button = SvGtkLinkButton (ST(0))
;
	gboolean	visited = (bool)SvTRUE(ST(1))
;

	gtk_link_button_set_visited(link_button, visited);
    }
    XSRETURN_EMPTY;
}

#endif /* 2.14 */
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__LinkButton); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__LinkButton)
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

        cv = newXS("Gtk2::LinkButton::new", XS_Gtk2__LinkButton_new, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::LinkButton::new_with_label", XS_Gtk2__LinkButton_new, file);
        XSANY.any_i32 = 1;
        newXS("Gtk2::LinkButton::get_uri", XS_Gtk2__LinkButton_get_uri, file);
        newXS("Gtk2::LinkButton::set_uri", XS_Gtk2__LinkButton_set_uri, file);
        newXS("Gtk2::LinkButton::set_uri_hook", XS_Gtk2__LinkButton_set_uri_hook, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::LinkButton::get_visited", XS_Gtk2__LinkButton_get_visited, file);
        newXS("Gtk2::LinkButton::set_visited", XS_Gtk2__LinkButton_set_visited, file);
#endif
    }

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#line 395 "xs\\GtkLinkButton.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
