/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkHSV.xs. Do not edit this file, edit GtkHSV.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkHSV.xs"
/*
 * Copyright (c) 2010 by the gtk2-perl team (see the file AUTHORS)
 *
 * Licensed under the LGPL, see LICENSE file for more information.
 *
 * $Id$
 */

#include "gtk2perl.h"

#line 21 "xs\\GtkHSV.c"
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

#line 163 "xs\\GtkHSV.c"

XS_EUPXS(XS_Gtk2__HSV_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__HSV_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	GtkWidget *	RETVAL;

	RETVAL = gtk_hsv_new(/* void */);
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__HSV_set_color); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__HSV_set_color)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "hsv, h, s, v");
    {
	GtkHSV *	hsv = SvGtkHSV (ST(0))
;
	double	h = (double)SvNV(ST(1))
;
	double	s = (double)SvNV(ST(2))
;
	double	v = (double)SvNV(ST(3))
;

	gtk_hsv_set_color(hsv, h, s, v);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__HSV_get_color); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__HSV_get_color)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "hsv");
    {
	GtkHSV *	hsv = SvGtkHSV (ST(0))
;
	gdouble	h;
	gdouble	s;
	gdouble	v;

	gtk_hsv_get_color(hsv, &h, &s, &v);
	XSprePUSH;	EXTEND(SP,3);
	PUSHs(sv_newmortal());
	sv_setnv(ST(0), (double)h);
	PUSHs(sv_newmortal());
	sv_setnv(ST(1), (double)s);
	PUSHs(sv_newmortal());
	sv_setnv(ST(2), (double)v);
    }
    XSRETURN(3);
}


XS_EUPXS(XS_Gtk2__HSV_set_metrics); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__HSV_set_metrics)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "hsv, size, ring_width");
    {
	GtkHSV *	hsv = SvGtkHSV (ST(0))
;
	gint	size = (gint)SvIV(ST(1))
;
	gint	ring_width = (gint)SvIV(ST(2))
;

	gtk_hsv_set_metrics(hsv, size, ring_width);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__HSV_get_metrics); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__HSV_get_metrics)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "hsv");
    {
	GtkHSV *	hsv = SvGtkHSV (ST(0))
;
	gint	size;
	gint	ring_width;

	gtk_hsv_get_metrics(hsv, &size, &ring_width);
	XSprePUSH;	EXTEND(SP,2);
	PUSHs(sv_newmortal());
	sv_setiv(ST(0), (IV)size);
	PUSHs(sv_newmortal());
	sv_setiv(ST(1), (IV)ring_width);
    }
    XSRETURN(2);
}


XS_EUPXS(XS_Gtk2__HSV_is_adjusting); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__HSV_is_adjusting)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "hsv");
    {
	gboolean	RETVAL;
	GtkHSV *	hsv = SvGtkHSV (ST(0))
;

	RETVAL = gtk_hsv_is_adjusting(hsv);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2_hsv_to_rgb); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2_hsv_to_rgb)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "h, s, v");
    {
	gdouble	h = (double)SvNV(ST(0))
;
	gdouble	s = (double)SvNV(ST(1))
;
	gdouble	v = (double)SvNV(ST(2))
;
	gdouble	r;
	gdouble	g;
	gdouble	b;

	gtk_hsv_to_rgb(h, s, v, &r, &g, &b);
	XSprePUSH;	EXTEND(SP,3);
	PUSHs(sv_newmortal());
	sv_setnv(ST(0), (double)r);
	PUSHs(sv_newmortal());
	sv_setnv(ST(1), (double)g);
	PUSHs(sv_newmortal());
	sv_setnv(ST(2), (double)b);
    }
    XSRETURN(3);
}


XS_EUPXS(XS_Gtk2_rgb_to_hsv); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2_rgb_to_hsv)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "r, g, b");
    {
	gdouble	r = (double)SvNV(ST(0))
;
	gdouble	g = (double)SvNV(ST(1))
;
	gdouble	b = (double)SvNV(ST(2))
;
	gdouble	h;
	gdouble	s;
	gdouble	v;

	gtk_rgb_to_hsv(r, g, b, &h, &s, &v);
	XSprePUSH;	EXTEND(SP,3);
	PUSHs(sv_newmortal());
	sv_setnv(ST(0), (double)h);
	PUSHs(sv_newmortal());
	sv_setnv(ST(1), (double)s);
	PUSHs(sv_newmortal());
	sv_setnv(ST(2), (double)v);
    }
    XSRETURN(3);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__HSV); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__HSV)
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

        newXS("Gtk2::HSV::new", XS_Gtk2__HSV_new, file);
        newXS("Gtk2::HSV::set_color", XS_Gtk2__HSV_set_color, file);
        newXS("Gtk2::HSV::get_color", XS_Gtk2__HSV_get_color, file);
        newXS("Gtk2::HSV::set_metrics", XS_Gtk2__HSV_set_metrics, file);
        newXS("Gtk2::HSV::get_metrics", XS_Gtk2__HSV_get_metrics, file);
        newXS("Gtk2::HSV::is_adjusting", XS_Gtk2__HSV_is_adjusting, file);
        newXS("Gtk2::hsv_to_rgb", XS_Gtk2_hsv_to_rgb, file);
        newXS("Gtk2::rgb_to_hsv", XS_Gtk2_rgb_to_hsv, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

