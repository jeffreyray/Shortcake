/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkProgressBar.xs. Do not edit this file, edit GtkProgressBar.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkProgressBar.xs"
/*
 * Copyright (c) 2003 by the gtk2-perl team (see the file AUTHORS)
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

#line 34 "xs\\GtkProgressBar.c"
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

#line 176 "xs\\GtkProgressBar.c"

XS_EUPXS(XS_Gtk2__ProgressBar_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ProgressBar_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	GtkWidget *	RETVAL;

	RETVAL = gtk_progress_bar_new(/* void */);
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ProgressBar_set_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ProgressBar_set_text)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "pbar, text");
    {
	GtkProgressBar *	pbar = SvGtkProgressBar (ST(0))
;
	const gchar_ornull *	text;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		text = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		text = NULL;
	}
;

	gtk_progress_bar_set_text(pbar, text);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ProgressBar_set_fraction); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ProgressBar_set_fraction)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "pbar, fraction");
    {
	GtkProgressBar *	pbar = SvGtkProgressBar (ST(0))
;
	gdouble	fraction = (double)SvNV(ST(1))
;

	gtk_progress_bar_set_fraction(pbar, fraction);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ProgressBar_set_pulse_step); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ProgressBar_set_pulse_step)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "pbar, fraction");
    {
	GtkProgressBar *	pbar = SvGtkProgressBar (ST(0))
;
	gdouble	fraction = (double)SvNV(ST(1))
;

	gtk_progress_bar_set_pulse_step(pbar, fraction);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ProgressBar_set_orientation); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ProgressBar_set_orientation)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "pbar, orientation");
    {
	GtkProgressBar *	pbar = SvGtkProgressBar (ST(0))
;
	GtkProgressBarOrientation	orientation = SvGtkProgressBarOrientation (ST(1))
;

	gtk_progress_bar_set_orientation(pbar, orientation);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ProgressBar_get_fraction); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ProgressBar_get_fraction)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "pbar");
    {
	GtkProgressBar *	pbar = SvGtkProgressBar (ST(0))
;
	gdouble	RETVAL;
	dXSTARG;

	RETVAL = gtk_progress_bar_get_fraction(pbar);
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ProgressBar_get_pulse_step); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ProgressBar_get_pulse_step)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "pbar");
    {
	GtkProgressBar *	pbar = SvGtkProgressBar (ST(0))
;
	gdouble	RETVAL;
	dXSTARG;

	RETVAL = gtk_progress_bar_get_pulse_step(pbar);
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ProgressBar_get_orientation); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ProgressBar_get_orientation)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "pbar");
    {
	GtkProgressBar *	pbar = SvGtkProgressBar (ST(0))
;
	GtkProgressBarOrientation	RETVAL;

	RETVAL = gtk_progress_bar_get_orientation(pbar);
	ST(0) = newSVGtkProgressBarOrientation (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ProgressBar_pulse); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ProgressBar_pulse)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "pbar");
    {
	GtkProgressBar *	pbar = SvGtkProgressBar (ST(0))
;

	gtk_progress_bar_pulse(pbar);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ProgressBar_get_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ProgressBar_get_text)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "pbar");
    {
	GtkProgressBar *	pbar = SvGtkProgressBar (ST(0))
;
	const gchar_ornull *	RETVAL;

	RETVAL = gtk_progress_bar_get_text(pbar);
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

#if GTK_CHECK_VERSION (2, 6, 0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__ProgressBar_set_ellipsize); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ProgressBar_set_ellipsize)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "pbar, mode");
    {
	GtkProgressBar *	pbar = SvGtkProgressBar (ST(0))
;
	PangoEllipsizeMode	mode = SvPangoEllipsizeMode (ST(1))
;

	gtk_progress_bar_set_ellipsize(pbar, mode);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ProgressBar_get_ellipsize); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ProgressBar_get_ellipsize)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "pbar");
    {
	PangoEllipsizeMode	RETVAL;
	GtkProgressBar *	pbar = SvGtkProgressBar (ST(0))
;

	RETVAL = gtk_progress_bar_get_ellipsize(pbar);
	ST(0) = newSVPangoEllipsizeMode (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__ProgressBar); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__ProgressBar)
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

        newXS("Gtk2::ProgressBar::new", XS_Gtk2__ProgressBar_new, file);
        newXS("Gtk2::ProgressBar::set_text", XS_Gtk2__ProgressBar_set_text, file);
        newXS("Gtk2::ProgressBar::set_fraction", XS_Gtk2__ProgressBar_set_fraction, file);
        newXS("Gtk2::ProgressBar::set_pulse_step", XS_Gtk2__ProgressBar_set_pulse_step, file);
        newXS("Gtk2::ProgressBar::set_orientation", XS_Gtk2__ProgressBar_set_orientation, file);
        newXS("Gtk2::ProgressBar::get_fraction", XS_Gtk2__ProgressBar_get_fraction, file);
        newXS("Gtk2::ProgressBar::get_pulse_step", XS_Gtk2__ProgressBar_get_pulse_step, file);
        newXS("Gtk2::ProgressBar::get_orientation", XS_Gtk2__ProgressBar_get_orientation, file);
        newXS("Gtk2::ProgressBar::pulse", XS_Gtk2__ProgressBar_pulse, file);
        newXS("Gtk2::ProgressBar::get_text", XS_Gtk2__ProgressBar_get_text, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::ProgressBar::set_ellipsize", XS_Gtk2__ProgressBar_set_ellipsize, file);
        newXS("Gtk2::ProgressBar::get_ellipsize", XS_Gtk2__ProgressBar_get_ellipsize, file);
#endif

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#line 452 "xs\\GtkProgressBar.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

