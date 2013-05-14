/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkScrolledWindow.xs. Do not edit this file, edit GtkScrolledWindow.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkScrolledWindow.xs"
/*
 * Copyright (c) 2003-2006 by the gtk2-perl team (see the file AUTHORS)
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

#line 34 "xs\\GtkScrolledWindow.c"
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

#line 176 "xs\\GtkScrolledWindow.c"

XS_EUPXS(XS_Gtk2__ScrolledWindow_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_new)
{
    dVAR; dXSARGS;
    if (items < 1 || items > 3)
       croak_xs_usage(cv,  "class, hadjustment=NULL, vadjustment=NULL");
    {
	GtkAdjustment_ornull *	hadjustment;
	GtkAdjustment_ornull *	vadjustment;
	GtkWidget *	RETVAL;

	if (items < 2)
	    hadjustment = NULL;
	else {
	    hadjustment = SvGtkAdjustment_ornull (ST(1))
;
	}

	if (items < 3)
	    vadjustment = NULL;
	else {
	    vadjustment = SvGtkAdjustment_ornull (ST(2))
;
	}

	RETVAL = gtk_scrolled_window_new(hadjustment, vadjustment);
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ScrolledWindow_set_hadjustment); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_set_hadjustment)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "scrolled_window, hadjustment");
    {
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;
	GtkAdjustment *	hadjustment = SvGtkAdjustment (ST(1))
;

	gtk_scrolled_window_set_hadjustment(scrolled_window, hadjustment);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ScrolledWindow_set_vadjustment); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_set_vadjustment)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "scrolled_window, hadjustment");
    {
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;
	GtkAdjustment *	hadjustment = SvGtkAdjustment (ST(1))
;

	gtk_scrolled_window_set_vadjustment(scrolled_window, hadjustment);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ScrolledWindow_get_hadjustment); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_get_hadjustment)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "scrolled_window");
    {
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;
	GtkAdjustment *	RETVAL;

	RETVAL = gtk_scrolled_window_get_hadjustment(scrolled_window);
	ST(0) = newSVGtkAdjustment (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ScrolledWindow_get_vadjustment); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_get_vadjustment)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "scrolled_window");
    {
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;
	GtkAdjustment *	RETVAL;

	RETVAL = gtk_scrolled_window_get_vadjustment(scrolled_window);
	ST(0) = newSVGtkAdjustment (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ScrolledWindow_set_policy); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_set_policy)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "scrolled_window, hscrollbar_policy, vscrollbar_policy");
    {
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;
	GtkPolicyType	hscrollbar_policy = SvGtkPolicyType (ST(1))
;
	GtkPolicyType	vscrollbar_policy = SvGtkPolicyType (ST(2))
;

	gtk_scrolled_window_set_policy(scrolled_window, hscrollbar_policy, vscrollbar_policy);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ScrolledWindow_get_policy); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_get_policy)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "scrolled_window");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 67 "xs\\\\GtkScrolledWindow.xs"
	GtkPolicyType hscrollbar_policy;
	GtkPolicyType vscrollbar_policy;
#line 317 "xs\\GtkScrolledWindow.c"
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;
#line 70 "xs\\\\GtkScrolledWindow.xs"
	gtk_scrolled_window_get_policy (scrolled_window, &hscrollbar_policy, &vscrollbar_policy);
	EXTEND (SP, 2);
	PUSHs (sv_2mortal (newSVGtkPolicyType (hscrollbar_policy)));
	PUSHs (sv_2mortal (newSVGtkPolicyType (vscrollbar_policy)));
#line 325 "xs\\GtkScrolledWindow.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__ScrolledWindow_set_placement); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_set_placement)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "scrolled_window, window_placement");
    {
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;
	GtkCornerType	window_placement = SvGtkCornerType (ST(1))
;

	gtk_scrolled_window_set_placement(scrolled_window, window_placement);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ScrolledWindow_get_placement); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_get_placement)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "scrolled_window");
    {
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;
	GtkCornerType	RETVAL;

	RETVAL = gtk_scrolled_window_get_placement(scrolled_window);
	ST(0) = newSVGtkCornerType (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ScrolledWindow_set_shadow_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_set_shadow_type)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "scrolled_window, type");
    {
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;
	GtkShadowType	type = SvGtkShadowType (ST(1))
;

	gtk_scrolled_window_set_shadow_type(scrolled_window, type);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ScrolledWindow_get_shadow_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_get_shadow_type)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "scrolled_window");
    {
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;
	GtkShadowType	RETVAL;

	RETVAL = gtk_scrolled_window_get_shadow_type(scrolled_window);
	ST(0) = newSVGtkShadowType (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ScrolledWindow_add_with_viewport); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_add_with_viewport)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "scrolled_window, child");
    {
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;

	gtk_scrolled_window_add_with_viewport(scrolled_window, child);
    }
    XSRETURN_EMPTY;
}

#if GTK_CHECK_VERSION (2, 8, 0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__ScrolledWindow_get_hscrollbar); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_get_hscrollbar)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "scrolled_window");
    {
	GtkWidget_ornull *	RETVAL;
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;

	RETVAL = gtk_scrolled_window_get_hscrollbar(scrolled_window);
	ST(0) = newSVGtkWidget_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ScrolledWindow_get_vscrollbar); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_get_vscrollbar)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "scrolled_window");
    {
	GtkWidget_ornull *	RETVAL;
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;

	RETVAL = gtk_scrolled_window_get_vscrollbar(scrolled_window);
	ST(0) = newSVGtkWidget_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif
#if GTK_CHECK_VERSION (2, 10, 0)
#define XSubPPtmpAAAB 1


XS_EUPXS(XS_Gtk2__ScrolledWindow_unset_placement); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ScrolledWindow_unset_placement)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "scrolled_window");
    {
	GtkScrolledWindow *	scrolled_window = SvGtkScrolledWindow (ST(0))
;

	gtk_scrolled_window_unset_placement(scrolled_window);
    }
    XSRETURN_EMPTY;
}

#endif
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__ScrolledWindow); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__ScrolledWindow)
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

        newXS("Gtk2::ScrolledWindow::new", XS_Gtk2__ScrolledWindow_new, file);
        newXS("Gtk2::ScrolledWindow::set_hadjustment", XS_Gtk2__ScrolledWindow_set_hadjustment, file);
        newXS("Gtk2::ScrolledWindow::set_vadjustment", XS_Gtk2__ScrolledWindow_set_vadjustment, file);
        newXS("Gtk2::ScrolledWindow::get_hadjustment", XS_Gtk2__ScrolledWindow_get_hadjustment, file);
        newXS("Gtk2::ScrolledWindow::get_vadjustment", XS_Gtk2__ScrolledWindow_get_vadjustment, file);
        newXS("Gtk2::ScrolledWindow::set_policy", XS_Gtk2__ScrolledWindow_set_policy, file);
        newXS("Gtk2::ScrolledWindow::get_policy", XS_Gtk2__ScrolledWindow_get_policy, file);
        newXS("Gtk2::ScrolledWindow::set_placement", XS_Gtk2__ScrolledWindow_set_placement, file);
        newXS("Gtk2::ScrolledWindow::get_placement", XS_Gtk2__ScrolledWindow_get_placement, file);
        newXS("Gtk2::ScrolledWindow::set_shadow_type", XS_Gtk2__ScrolledWindow_set_shadow_type, file);
        newXS("Gtk2::ScrolledWindow::get_shadow_type", XS_Gtk2__ScrolledWindow_get_shadow_type, file);
        newXS("Gtk2::ScrolledWindow::add_with_viewport", XS_Gtk2__ScrolledWindow_add_with_viewport, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::ScrolledWindow::get_hscrollbar", XS_Gtk2__ScrolledWindow_get_hscrollbar, file);
        newXS("Gtk2::ScrolledWindow::get_vscrollbar", XS_Gtk2__ScrolledWindow_get_vscrollbar, file);
#endif
#if XSubPPtmpAAAB
        newXS("Gtk2::ScrolledWindow::unset_placement", XS_Gtk2__ScrolledWindow_unset_placement, file);
#endif

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#if XSubPPtmpAAAB
#endif
#line 531 "xs\\GtkScrolledWindow.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

