/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkToolButton.xs. Do not edit this file, edit GtkToolButton.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkToolButton.xs"
/*
 * Copyright (c) 2003-2005 by the gtk2-perl team (see the file AUTHORS)
 *
 * Licensed under the LGPL, see LICENSE file for more information.
 *
 * $Id$
 */

#include "gtk2perl.h"

#line 21 "xs\\GtkToolButton.c"
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

#line 163 "xs\\GtkToolButton.c"

XS_EUPXS(XS_Gtk2__ToolButton_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_new)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "class, icon_widget, label");
    {
	GtkToolItem *	RETVAL;
	GtkWidget_ornull *	icon_widget = SvGtkWidget_ornull (ST(1))
;
	const gchar_ornull *	label;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(2))) {
		sv_utf8_upgrade (ST(2));
		label = (const gchar_ornull *)SvPV_nolen (ST(2));
	} else {
		label = NULL;
	}
;

	RETVAL = gtk_tool_button_new(icon_widget, label);
	ST(0) = newSVGtkToolItem (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolButton_new_from_stock); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_new_from_stock)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, stock_id");
    {
	GtkToolItem *	RETVAL;
	const gchar *	stock_id;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	stock_id = (const gchar *)SvPV_nolen (ST(1))
;

	RETVAL = gtk_tool_button_new_from_stock(stock_id);
	ST(0) = newSVGtkToolItem (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolButton_set_label); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_set_label)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "button, label");
    {
	GtkToolButton *	button = SvGtkToolButton (ST(0))
;
	const gchar_ornull *	label;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		label = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		label = NULL;
	}
;

	gtk_tool_button_set_label(button, label);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ToolButton_get_label); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_get_label)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "button");
    {
	const gchar_ornull *	RETVAL;
	GtkToolButton *	button = SvGtkToolButton (ST(0))
;

	RETVAL = gtk_tool_button_get_label(button);
	ST(0) = sv_newmortal();
	/* newSVGChar() allows NULL, but T_GCHAR does not. allow NULL. */
	if (RETVAL) {
		sv_setpv ((SV*)ST(0), RETVAL);
		SvUTF8_on (ST(0));
	} else {
		SvSetSV (ST(0), &PL_sv_undef);
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolButton_set_use_underline); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_set_use_underline)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "button, use_underline");
    {
	GtkToolButton *	button = SvGtkToolButton (ST(0))
;
	gboolean	use_underline = (bool)SvTRUE(ST(1))
;

	gtk_tool_button_set_use_underline(button, use_underline);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ToolButton_get_use_underline); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_get_use_underline)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "button");
    {
	gboolean	RETVAL;
	GtkToolButton *	button = SvGtkToolButton (ST(0))
;

	RETVAL = gtk_tool_button_get_use_underline(button);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolButton_set_stock_id); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_set_stock_id)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "button, stock_id");
    {
	GtkToolButton *	button = SvGtkToolButton (ST(0))
;
	const gchar_ornull *	stock_id;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		stock_id = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		stock_id = NULL;
	}
;

	gtk_tool_button_set_stock_id(button, stock_id);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ToolButton_get_stock_id); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_get_stock_id)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "button");
    {
	const gchar *	RETVAL;
	GtkToolButton *	button = SvGtkToolButton (ST(0))
;

	RETVAL = gtk_tool_button_get_stock_id(button);
	ST(0) = sv_newmortal();
	/* same as newSVGChar(), but not in a function */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolButton_set_icon_widget); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_set_icon_widget)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "button, icon_widget");
    {
	GtkToolButton *	button = SvGtkToolButton (ST(0))
;
	GtkWidget_ornull *	icon_widget = SvGtkWidget_ornull (ST(1))
;

	gtk_tool_button_set_icon_widget(button, icon_widget);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ToolButton_get_icon_widget); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_get_icon_widget)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "button");
    {
	GtkWidget_ornull *	RETVAL;
	GtkToolButton *	button = SvGtkToolButton (ST(0))
;

	RETVAL = gtk_tool_button_get_icon_widget(button);
	ST(0) = newSVGtkWidget_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolButton_set_label_widget); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_set_label_widget)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "button, label_widget");
    {
	GtkToolButton *	button = SvGtkToolButton (ST(0))
;
	GtkWidget_ornull *	label_widget = SvGtkWidget_ornull (ST(1))
;

	gtk_tool_button_set_label_widget(button, label_widget);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ToolButton_get_label_widget); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_get_label_widget)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "button");
    {
	GtkWidget_ornull *	RETVAL;
	GtkToolButton *	button = SvGtkToolButton (ST(0))
;

	RETVAL = gtk_tool_button_get_label_widget(button);
	ST(0) = newSVGtkWidget_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#if GTK_CHECK_VERSION (2, 8, 0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__ToolButton_set_icon_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_set_icon_name)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "button, icon_name");
    {
	GtkToolButton *	button = SvGtkToolButton (ST(0))
;
	const gchar_ornull *	icon_name;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		icon_name = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		icon_name = NULL;
	}
;

	gtk_tool_button_set_icon_name(button, icon_name);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ToolButton_get_icon_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolButton_get_icon_name)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "button");
    {
	const gchar_ornull *	RETVAL;
	GtkToolButton *	button = SvGtkToolButton (ST(0))
;

	RETVAL = gtk_tool_button_get_icon_name(button);
	ST(0) = sv_newmortal();
	/* newSVGChar() allows NULL, but T_GCHAR does not. allow NULL. */
	if (RETVAL) {
		sv_setpv ((SV*)ST(0), RETVAL);
		SvUTF8_on (ST(0));
	} else {
		SvSetSV (ST(0), &PL_sv_undef);
	}
    }
    XSRETURN(1);
}

#endif
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__ToolButton); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__ToolButton)
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

        newXS("Gtk2::ToolButton::new", XS_Gtk2__ToolButton_new, file);
        newXS("Gtk2::ToolButton::new_from_stock", XS_Gtk2__ToolButton_new_from_stock, file);
        newXS("Gtk2::ToolButton::set_label", XS_Gtk2__ToolButton_set_label, file);
        newXS("Gtk2::ToolButton::get_label", XS_Gtk2__ToolButton_get_label, file);
        newXS("Gtk2::ToolButton::set_use_underline", XS_Gtk2__ToolButton_set_use_underline, file);
        newXS("Gtk2::ToolButton::get_use_underline", XS_Gtk2__ToolButton_get_use_underline, file);
        newXS("Gtk2::ToolButton::set_stock_id", XS_Gtk2__ToolButton_set_stock_id, file);
        newXS("Gtk2::ToolButton::get_stock_id", XS_Gtk2__ToolButton_get_stock_id, file);
        newXS("Gtk2::ToolButton::set_icon_widget", XS_Gtk2__ToolButton_set_icon_widget, file);
        newXS("Gtk2::ToolButton::get_icon_widget", XS_Gtk2__ToolButton_get_icon_widget, file);
        newXS("Gtk2::ToolButton::set_label_widget", XS_Gtk2__ToolButton_set_label_widget, file);
        newXS("Gtk2::ToolButton::get_label_widget", XS_Gtk2__ToolButton_get_label_widget, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::ToolButton::set_icon_name", XS_Gtk2__ToolButton_set_icon_name, file);
        newXS("Gtk2::ToolButton::get_icon_name", XS_Gtk2__ToolButton_get_icon_name, file);
#endif

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#line 521 "xs\\GtkToolButton.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

