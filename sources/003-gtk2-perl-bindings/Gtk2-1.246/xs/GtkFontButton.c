/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkFontButton.xs. Do not edit this file, edit GtkFontButton.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkFontButton.xs"
/*
 * Copyright (c) 2003 by the gtk2-perl team (see the file AUTHORS)
 *
 * Licensed under the LGPL, see LICENSE file for more information.
 *
 * $Id$
 */

#include "gtk2perl.h"

#line 21 "xs\\GtkFontButton.c"
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

#line 163 "xs\\GtkFontButton.c"

XS_EUPXS(XS_Gtk2__FontButton_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__FontButton_new)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items < 1 || items > 2)
       croak_xs_usage(cv,  "class, fontname=NULL");
    {
	GtkWidget *	RETVAL;
	const gchar *	fontname;

	if (items < 2)
	    fontname = NULL;
	else {
	    /* same as SvGChar(), but not in a function */
	    sv_utf8_upgrade (ST(1));
	    fontname = (const gchar *)SvPV_nolen (ST(1))
;
	}
#line 20 "xs\\\\GtkFontButton.xs"
	PERL_UNUSED_VAR (ix);
	RETVAL = items == 2
	       ? gtk_font_button_new_with_font (fontname)
	       : gtk_font_button_new ();
#line 189 "xs\\GtkFontButton.c"
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__FontButton_get_title); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__FontButton_get_title)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "font_button");
    {
	const gchar *	RETVAL;
	GtkFontButton *	font_button = SvGtkFontButton (ST(0))
;

	RETVAL = gtk_font_button_get_title(font_button);
	ST(0) = sv_newmortal();
	/* same as newSVGChar(), but not in a function */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__FontButton_set_title); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__FontButton_set_title)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "font_button, title");
    {
	GtkFontButton *	font_button = SvGtkFontButton (ST(0))
;
	const gchar *	title;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	title = (const gchar *)SvPV_nolen (ST(1))
;

	gtk_font_button_set_title(font_button, title);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__FontButton_get_use_font); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__FontButton_get_use_font)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "font_button");
    {
	gboolean	RETVAL;
	GtkFontButton *	font_button = SvGtkFontButton (ST(0))
;

	RETVAL = gtk_font_button_get_use_font(font_button);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__FontButton_set_use_font); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__FontButton_set_use_font)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "font_button, use_font");
    {
	GtkFontButton *	font_button = SvGtkFontButton (ST(0))
;
	gboolean	use_font = (bool)SvTRUE(ST(1))
;

	gtk_font_button_set_use_font(font_button, use_font);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__FontButton_get_use_size); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__FontButton_get_use_size)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "font_button");
    {
	gboolean	RETVAL;
	GtkFontButton *	font_button = SvGtkFontButton (ST(0))
;

	RETVAL = gtk_font_button_get_use_size(font_button);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__FontButton_set_use_size); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__FontButton_set_use_size)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "font_button, use_size");
    {
	GtkFontButton *	font_button = SvGtkFontButton (ST(0))
;
	gboolean	use_size = (bool)SvTRUE(ST(1))
;

	gtk_font_button_set_use_size(font_button, use_size);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__FontButton_get_font_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__FontButton_get_font_name)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "font_button");
    {
	const gchar *	RETVAL;
	GtkFontButton *	font_button = SvGtkFontButton (ST(0))
;

	RETVAL = gtk_font_button_get_font_name(font_button);
	ST(0) = sv_newmortal();
	/* same as newSVGChar(), but not in a function */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__FontButton_set_font_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__FontButton_set_font_name)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "font_button, fontname");
    {
	gboolean	RETVAL;
	GtkFontButton *	font_button = SvGtkFontButton (ST(0))
;
	const gchar *	fontname;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	fontname = (const gchar *)SvPV_nolen (ST(1))
;

	RETVAL = gtk_font_button_set_font_name(font_button, fontname);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__FontButton_get_show_style); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__FontButton_get_show_style)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "font_button");
    {
	gboolean	RETVAL;
	GtkFontButton *	font_button = SvGtkFontButton (ST(0))
;

	RETVAL = gtk_font_button_get_show_style(font_button);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__FontButton_set_show_style); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__FontButton_set_show_style)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "font_button, show_style");
    {
	GtkFontButton *	font_button = SvGtkFontButton (ST(0))
;
	gboolean	show_style = (bool)SvTRUE(ST(1))
;

	gtk_font_button_set_show_style(font_button, show_style);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__FontButton_get_show_size); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__FontButton_get_show_size)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "font_button");
    {
	gboolean	RETVAL;
	GtkFontButton *	font_button = SvGtkFontButton (ST(0))
;

	RETVAL = gtk_font_button_get_show_size(font_button);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__FontButton_set_show_size); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__FontButton_set_show_size)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "font_button, show_size");
    {
	GtkFontButton *	font_button = SvGtkFontButton (ST(0))
;
	gboolean	show_size = (bool)SvTRUE(ST(1))
;

	gtk_font_button_set_show_size(font_button, show_size);
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__FontButton); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__FontButton)
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

        cv = newXS("Gtk2::FontButton::new", XS_Gtk2__FontButton_new, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::FontButton::new_with_font", XS_Gtk2__FontButton_new, file);
        XSANY.any_i32 = 1;
        newXS("Gtk2::FontButton::get_title", XS_Gtk2__FontButton_get_title, file);
        newXS("Gtk2::FontButton::set_title", XS_Gtk2__FontButton_set_title, file);
        newXS("Gtk2::FontButton::get_use_font", XS_Gtk2__FontButton_get_use_font, file);
        newXS("Gtk2::FontButton::set_use_font", XS_Gtk2__FontButton_set_use_font, file);
        newXS("Gtk2::FontButton::get_use_size", XS_Gtk2__FontButton_get_use_size, file);
        newXS("Gtk2::FontButton::set_use_size", XS_Gtk2__FontButton_set_use_size, file);
        newXS("Gtk2::FontButton::get_font_name", XS_Gtk2__FontButton_get_font_name, file);
        newXS("Gtk2::FontButton::set_font_name", XS_Gtk2__FontButton_set_font_name, file);
        newXS("Gtk2::FontButton::get_show_style", XS_Gtk2__FontButton_get_show_style, file);
        newXS("Gtk2::FontButton::set_show_style", XS_Gtk2__FontButton_set_show_style, file);
        newXS("Gtk2::FontButton::get_show_size", XS_Gtk2__FontButton_get_show_size, file);
        newXS("Gtk2::FontButton::set_show_size", XS_Gtk2__FontButton_set_show_size, file);
    }
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

