/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkAdjustment.xs. Do not edit this file, edit GtkAdjustment.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkAdjustment.xs"
/*
 * Copyright (c) 2003, 2009 by the gtk2-perl team (see the file AUTHORS)
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

#line 34 "xs\\GtkAdjustment.c"
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

#line 176 "xs\\GtkAdjustment.c"

XS_EUPXS(XS_Gtk2__Adjustment_value); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Adjustment_value)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items < 1 || items > 2)
       croak_xs_usage(cv,  "adjustment, newval= 0");
    {
	gdouble	RETVAL;
	dXSTARG;
	GtkAdjustment *	adjustment = SvGtkAdjustment (ST(0))
;
	gdouble	newval;

	if (items < 2)
	    newval = 0;
	else {
	    newval = (double)SvNV(ST(1))
;
	}
#line 76 "xs\\\\GtkAdjustment.xs"
	switch (ix) {
	    case 0:
		RETVAL = adjustment->value;
		if (items > 1) adjustment->value = newval;
		break;
	    case 1:
		RETVAL = adjustment->lower;
		if (items > 1) adjustment->lower = newval;
		break;
	    case 2:
		RETVAL = adjustment->upper;
		if (items > 1) adjustment->upper = newval;
		break;
	    case 3:
		RETVAL = adjustment->step_increment;
		if (items > 1) adjustment->step_increment = newval;
		break;
	    case 4:
		RETVAL = adjustment->page_increment;
		if (items > 1) adjustment->page_increment = newval;
		break;
	    case 5:
		RETVAL = adjustment->page_size;
		if (items > 1) adjustment->page_size = newval;
		break;
	    default:
		RETVAL = 0.0;
		g_assert_not_reached ();
	}
#line 228 "xs\\GtkAdjustment.c"
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Adjustment_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Adjustment_new)
{
    dVAR; dXSARGS;
    if (items != 7)
       croak_xs_usage(cv,  "class, value, lower, upper, step_increment, page_increment, page_size");
    {
	gdouble	value = (double)SvNV(ST(1))
;
	gdouble	lower = (double)SvNV(ST(2))
;
	gdouble	upper = (double)SvNV(ST(3))
;
	gdouble	step_increment = (double)SvNV(ST(4))
;
	gdouble	page_increment = (double)SvNV(ST(5))
;
	gdouble	page_size = (double)SvNV(ST(6))
;
	GtkObject *	RETVAL;

	RETVAL = gtk_adjustment_new(value, lower, upper, step_increment, page_increment, page_size);
	ST(0) = newSVGtkObject (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Adjustment_changed); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Adjustment_changed)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "adjustment");
    {
	GtkAdjustment *	adjustment = SvGtkAdjustment (ST(0))
;

	gtk_adjustment_changed(adjustment);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Adjustment_value_changed); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Adjustment_value_changed)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "adjustment");
    {
	GtkAdjustment *	adjustment = SvGtkAdjustment (ST(0))
;

	gtk_adjustment_value_changed(adjustment);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Adjustment_clamp_page); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Adjustment_clamp_page)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "adjustment, lower, upper");
    {
	GtkAdjustment *	adjustment = SvGtkAdjustment (ST(0))
;
	gdouble	lower = (double)SvNV(ST(1))
;
	gdouble	upper = (double)SvNV(ST(2))
;

	gtk_adjustment_clamp_page(adjustment, lower, upper);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Adjustment_get_value); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Adjustment_get_value)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "adjustment");
    {
	GtkAdjustment *	adjustment = SvGtkAdjustment (ST(0))
;
	gdouble	RETVAL;
	dXSTARG;

	RETVAL = gtk_adjustment_get_value(adjustment);
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Adjustment_set_value); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Adjustment_set_value)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "adjustment, value");
    {
	GtkAdjustment *	adjustment = SvGtkAdjustment (ST(0))
;
	gdouble	value = (double)SvNV(ST(1))
;

	gtk_adjustment_set_value(adjustment, value);
    }
    XSRETURN_EMPTY;
}

#if GTK_CHECK_VERSION (2, 14, 0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__Adjustment_configure); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Adjustment_configure)
{
    dVAR; dXSARGS;
    if (items != 7)
       croak_xs_usage(cv,  "adjustment, value, lower, upper, step_increment, page_increment, page_size");
    {
	GtkAdjustment *	adjustment = SvGtkAdjustment (ST(0))
;
	gdouble	value = (double)SvNV(ST(1))
;
	gdouble	lower = (double)SvNV(ST(2))
;
	gdouble	upper = (double)SvNV(ST(3))
;
	gdouble	step_increment = (double)SvNV(ST(4))
;
	gdouble	page_increment = (double)SvNV(ST(5))
;
	gdouble	page_size = (double)SvNV(ST(6))
;

	gtk_adjustment_configure(adjustment, value, lower, upper, step_increment, page_increment, page_size);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Adjustment_set_lower); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Adjustment_set_lower)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 2)
       croak_xs_usage(cv,  "adjustment, newval");
    {
	GtkAdjustment *	adjustment = SvGtkAdjustment (ST(0))
;
	gdouble	newval = (double)SvNV(ST(1))
;
#line 194 "xs\\\\GtkAdjustment.xs"
	switch (ix) {
	    case 0: gtk_adjustment_set_lower (adjustment, newval);
	            break;
	    case 1: gtk_adjustment_set_page_increment (adjustment, newval);
	            break;
	    case 2: gtk_adjustment_set_page_size (adjustment, newval);
	            break;
	    case 3: gtk_adjustment_set_step_increment (adjustment, newval);
	            break;
	    case 4: gtk_adjustment_set_upper (adjustment, newval);
	            break;
	}
#line 409 "xs\\GtkAdjustment.c"
    }
    XSRETURN_EMPTY;
}

#endif /* 2.14 */
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__Adjustment); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__Adjustment)
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

        cv = newXS("Gtk2::Adjustment::page_increment", XS_Gtk2__Adjustment_value, file);
        XSANY.any_i32 = 4;
        cv = newXS("Gtk2::Adjustment::step_increment", XS_Gtk2__Adjustment_value, file);
        XSANY.any_i32 = 3;
        cv = newXS("Gtk2::Adjustment::lower", XS_Gtk2__Adjustment_value, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::Adjustment::value", XS_Gtk2__Adjustment_value, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::Adjustment::page_size", XS_Gtk2__Adjustment_value, file);
        XSANY.any_i32 = 5;
        cv = newXS("Gtk2::Adjustment::upper", XS_Gtk2__Adjustment_value, file);
        XSANY.any_i32 = 2;
        newXS("Gtk2::Adjustment::new", XS_Gtk2__Adjustment_new, file);
        newXS("Gtk2::Adjustment::changed", XS_Gtk2__Adjustment_changed, file);
        newXS("Gtk2::Adjustment::value_changed", XS_Gtk2__Adjustment_value_changed, file);
        newXS("Gtk2::Adjustment::clamp_page", XS_Gtk2__Adjustment_clamp_page, file);
        newXS("Gtk2::Adjustment::get_value", XS_Gtk2__Adjustment_get_value, file);
        newXS("Gtk2::Adjustment::set_value", XS_Gtk2__Adjustment_set_value, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::Adjustment::configure", XS_Gtk2__Adjustment_configure, file);
        cv = newXS("Gtk2::Adjustment::set_page_size", XS_Gtk2__Adjustment_set_lower, file);
        XSANY.any_i32 = 2;
        cv = newXS("Gtk2::Adjustment::set_step_increment", XS_Gtk2__Adjustment_set_lower, file);
        XSANY.any_i32 = 3;
        cv = newXS("Gtk2::Adjustment::set_lower", XS_Gtk2__Adjustment_set_lower, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::Adjustment::set_page_increment", XS_Gtk2__Adjustment_set_lower, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::Adjustment::set_upper", XS_Gtk2__Adjustment_set_lower, file);
        XSANY.any_i32 = 4;
#endif
    }

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#line 475 "xs\\GtkAdjustment.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
