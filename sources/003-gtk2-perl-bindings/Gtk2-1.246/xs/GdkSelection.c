/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GdkSelection.xs. Do not edit this file, edit GdkSelection.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GdkSelection.xs"
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

#line 33 "xs\\GdkSelection.c"
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

#line 175 "xs\\GdkSelection.c"

XS_EUPXS(XS_Gtk2__Gdk_SELECTION_PRIMARY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk_SELECTION_PRIMARY)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	GdkAtom	RETVAL;
#line 44 "xs\\\\GdkSelection.xs"
	switch (ix) {
	    case  0: RETVAL = GDK_SELECTION_PRIMARY; break;
	    case  1: RETVAL = GDK_SELECTION_SECONDARY; break;
	    case  2: RETVAL = GDK_SELECTION_CLIPBOARD; break;
	    case  3: RETVAL = GDK_TARGET_BITMAP; break;
	    case  4: RETVAL = GDK_TARGET_COLORMAP; break;
	    case  5: RETVAL = GDK_TARGET_DRAWABLE; break;
	    case  6: RETVAL = GDK_TARGET_PIXMAP; break;
	    case  7: RETVAL = GDK_TARGET_STRING; break;
	    case  8: RETVAL = GDK_SELECTION_TYPE_ATOM; break;
	    case  9: RETVAL = GDK_SELECTION_TYPE_BITMAP; break;
	    case 10: RETVAL = GDK_SELECTION_TYPE_COLORMAP; break;
	    case 11: RETVAL = GDK_SELECTION_TYPE_DRAWABLE; break;
	    case 12: RETVAL = GDK_SELECTION_TYPE_INTEGER; break;
	    case 13: RETVAL = GDK_SELECTION_TYPE_PIXMAP; break;
	    case 14: RETVAL = GDK_SELECTION_TYPE_WINDOW; break;
	    case 15: RETVAL = GDK_SELECTION_TYPE_STRING; break;
	    default:
		RETVAL = 0;
		g_assert_not_reached ();
	}
#line 208 "xs\\GdkSelection.c"
	ST(0) = newSVGdkAtom (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Gdk__Selection_owner_set); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Selection_owner_set)
{
    dVAR; dXSARGS;
    if (items != 5)
       croak_xs_usage(cv,  "class, owner, selection, time_, send_event");
    {
	GdkWindow_ornull *	owner = SvGdkWindow_ornull (ST(1))
;
	GdkAtom	selection = SvGdkAtom (ST(2))
;
	guint32	time_ = (guint32)SvUV(ST(3))
;
	gboolean	send_event = (bool)SvTRUE(ST(4))
;
	gboolean	RETVAL;

	RETVAL = gdk_selection_owner_set(owner, selection, time_, send_event);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Gdk__Selection_owner_get); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Selection_owner_get)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, selection");
    {
	GdkAtom	selection = SvGdkAtom (ST(1))
;
	GdkWindow_ornull *	RETVAL;

	RETVAL = gdk_selection_owner_get(selection);
	ST(0) = newSVGdkWindow_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#if GTK_CHECK_VERSION(2,2,0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__Gdk__Selection_owner_set_for_display); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Selection_owner_set_for_display)
{
    dVAR; dXSARGS;
    if (items != 6)
       croak_xs_usage(cv,  "class, display, owner, selection, time_, send_event");
    {
	GdkDisplay *	display = SvGdkDisplay (ST(1))
;
	GdkWindow *	owner = SvGdkWindow (ST(2))
;
	GdkAtom	selection = SvGdkAtom (ST(3))
;
	guint32	time_ = (guint32)SvUV(ST(4))
;
	gboolean	send_event = (bool)SvTRUE(ST(5))
;
	gboolean	RETVAL;

	RETVAL = gdk_selection_owner_set_for_display(display, owner, selection, time_, send_event);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Gdk__Selection_owner_get_for_display); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Selection_owner_get_for_display)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "class, display, selection");
    {
	GdkDisplay *	display = SvGdkDisplay (ST(1))
;
	GdkAtom	selection = SvGdkAtom (ST(2))
;
	GdkWindow_ornull *	RETVAL;

	RETVAL = gdk_selection_owner_get_for_display(display, selection);
	ST(0) = newSVGdkWindow_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif /* >=2.2.0 */

XS_EUPXS(XS_Gtk2__Gdk__Selection_convert); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Selection_convert)
{
    dVAR; dXSARGS;
    if (items != 5)
       croak_xs_usage(cv,  "class, requestor, selection, target, time_");
    {
	GdkWindow *	requestor = SvGdkWindow (ST(1))
;
	GdkAtom	selection = SvGdkAtom (ST(2))
;
	GdkAtom	target = SvGdkAtom (ST(3))
;
	guint32	time_ = (guint32)SvUV(ST(4))
;

	gdk_selection_convert(requestor, selection, target, time_);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Gdk__Selection_property_get); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Selection_property_get)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, requestor");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	GdkWindow *	requestor = SvGdkWindow (ST(1))
;
#line 133 "xs\\\\GdkSelection.xs"
	guchar * data;
	GdkAtom prop_type;
	gint prop_format;
#line 349 "xs\\GdkSelection.c"
#line 137 "xs\\\\GdkSelection.xs"
	if (!gdk_selection_property_get (requestor, &data, 
	                                 &prop_type, &prop_format))
		XSRETURN_EMPTY;
	EXTEND (SP, 3);
	PUSHs (sv_2mortal (newSVpv ((gchar *) data, 0)));
	PUSHs (sv_2mortal (newSVGdkAtom (prop_type)));
	PUSHs (sv_2mortal (newSViv (prop_format)));
	g_free (data);
#line 359 "xs\\GdkSelection.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__Gdk__Selection_send_notify); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Selection_send_notify)
{
    dVAR; dXSARGS;
    if (items != 6)
       croak_xs_usage(cv,  "class, requestor, selection, target, property, time_");
    {
	guint32	requestor = (guint32)SvUV(ST(1))
;
	GdkAtom	selection = SvGdkAtom (ST(2))
;
	GdkAtom	target = SvGdkAtom (ST(3))
;
	GdkAtom	property = SvGdkAtom (ST(4))
;
	guint32	time_ = (guint32)SvUV(ST(5))
;

	gdk_selection_send_notify(requestor, selection, target, property, time_);
    }
    XSRETURN_EMPTY;
}

#if GTK_CHECK_VERSION(2,2,0)
#define XSubPPtmpAAAB 1


XS_EUPXS(XS_Gtk2__Gdk__Selection_send_notify_for_display); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Selection_send_notify_for_display)
{
    dVAR; dXSARGS;
    if (items != 7)
       croak_xs_usage(cv,  "class, display, requestor, selection, target, property, time_");
    {
	GdkDisplay *	display = SvGdkDisplay (ST(1))
;
	guint32	requestor = (guint32)SvUV(ST(2))
;
	GdkAtom	selection = SvGdkAtom (ST(3))
;
	GdkAtom	target = SvGdkAtom (ST(4))
;
	GdkAtom	property = SvGdkAtom (ST(5))
;
	guint32	time_ = (guint32)SvUV(ST(6))
;

	gdk_selection_send_notify_for_display(display, requestor, selection, target, property, time_);
    }
    XSRETURN_EMPTY;
}

#endif /* >=2.2.0 */
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__Gdk__Selection); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__Gdk__Selection)
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

        cv = newXS("Gtk2::Gdk::TARGET_DRAWABLE", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 5;
        cv = newXS("Gtk2::Gdk::SELECTION_TYPE_WINDOW", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 14;
        cv = newXS("Gtk2::Gdk::TARGET_BITMAP", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 3;
        cv = newXS("Gtk2::Gdk::SELECTION_TYPE_STRING", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 15;
        cv = newXS("Gtk2::Gdk::TARGET_COLORMAP", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 4;
        cv = newXS("Gtk2::Gdk::SELECTION_TYPE_PIXMAP", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 13;
        cv = newXS("Gtk2::Gdk::SELECTION_PRIMARY", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::Gdk::SELECTION_SECONDARY", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::Gdk::SELECTION_TYPE_COLORMAP", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 10;
        cv = newXS("Gtk2::Gdk::SELECTION_TYPE_INTEGER", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 12;
        cv = newXS("Gtk2::Gdk::SELECTION_CLIPBOARD", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 2;
        cv = newXS("Gtk2::Gdk::SELECTION_TYPE_DRAWABLE", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 11;
        cv = newXS("Gtk2::Gdk::SELECTION_TYPE_BITMAP", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 9;
        cv = newXS("Gtk2::Gdk::TARGET_PIXMAP", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 6;
        cv = newXS("Gtk2::Gdk::TARGET_STRING", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 7;
        cv = newXS("Gtk2::Gdk::SELECTION_TYPE_ATOM", XS_Gtk2__Gdk_SELECTION_PRIMARY, file);
        XSANY.any_i32 = 8;
        newXS("Gtk2::Gdk::Selection::owner_set", XS_Gtk2__Gdk__Selection_owner_set, file);
        newXS("Gtk2::Gdk::Selection::owner_get", XS_Gtk2__Gdk__Selection_owner_get, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::Gdk::Selection::owner_set_for_display", XS_Gtk2__Gdk__Selection_owner_set_for_display, file);
        newXS("Gtk2::Gdk::Selection::owner_get_for_display", XS_Gtk2__Gdk__Selection_owner_get_for_display, file);
#endif
        newXS("Gtk2::Gdk::Selection::convert", XS_Gtk2__Gdk__Selection_convert, file);
        newXS("Gtk2::Gdk::Selection::property_get", XS_Gtk2__Gdk__Selection_property_get, file);
        newXS("Gtk2::Gdk::Selection::send_notify", XS_Gtk2__Gdk__Selection_send_notify, file);
#if XSubPPtmpAAAB
        newXS("Gtk2::Gdk::Selection::send_notify_for_display", XS_Gtk2__Gdk__Selection_send_notify_for_display, file);
#endif
    }

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#if XSubPPtmpAAAB
#endif
#line 494 "xs\\GdkSelection.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

