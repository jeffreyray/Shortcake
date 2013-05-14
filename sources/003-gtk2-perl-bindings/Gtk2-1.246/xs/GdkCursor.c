/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GdkCursor.xs. Do not edit this file, edit GdkCursor.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GdkCursor.xs"
/*
 * Copyright (c) 2003-2005, 2010 by the gtk2-perl team (see the file AUTHORS)
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

#line 34 "xs\\GdkCursor.c"
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

#line 176 "xs\\GdkCursor.c"

XS_EUPXS(XS_Gtk2__Gdk__Cursor_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Cursor_type)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "cursor");
    {
	GdkCursor *	cursor = SvGdkCursor (ST(0))
;
	GdkCursorType	RETVAL;
#line 46 "xs\\\\GdkCursor.xs"
	RETVAL = cursor->type;
#line 190 "xs\\GdkCursor.c"
	ST(0) = newSVGdkCursorType (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#if GTK_CHECK_VERSION(2,2,0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__Gdk__Cursor_new_for_display); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Cursor_new_for_display)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "class, display, cursor_type");
    {
	GdkDisplay *	display = SvGdkDisplay (ST(1))
;
	GdkCursorType	cursor_type = SvGdkCursorType (ST(2))
;
	GdkCursor_own *	RETVAL;

	RETVAL = gdk_cursor_new_for_display(display, cursor_type);
	ST(0) = newSVGdkCursor_own (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Gdk__Cursor_get_display); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Cursor_get_display)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "cursor");
    {
	GdkCursor *	cursor = SvGdkCursor (ST(0))
;
	GdkDisplay *	RETVAL;

	RETVAL = gdk_cursor_get_display(cursor);
	ST(0) = newSVGdkDisplay (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif

XS_EUPXS(XS_Gtk2__Gdk__Cursor_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Cursor_new)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, cursor_type");
    {
	GdkCursorType	cursor_type = SvGdkCursorType (ST(1))
;
	GdkCursor_own *	RETVAL;

	RETVAL = gdk_cursor_new(cursor_type);
	ST(0) = newSVGdkCursor_own (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Gdk__Cursor_new_from_pixmap); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Cursor_new_from_pixmap)
{
    dVAR; dXSARGS;
    if (items != 7)
       croak_xs_usage(cv,  "class, source, mask, fg, bg, x, y");
    {
	GdkPixmap *	source = SvGdkPixmap (ST(1))
;
	GdkPixmap *	mask = SvGdkPixmap (ST(2))
;
	GdkColor *	fg = SvGdkColor (ST(3))
;
	GdkColor *	bg = SvGdkColor (ST(4))
;
	gint	x = (gint)SvIV(ST(5))
;
	gint	y = (gint)SvIV(ST(6))
;
	GdkCursor_own *	RETVAL;

	RETVAL = gdk_cursor_new_from_pixmap(source, mask, fg, bg, x, y);
	ST(0) = newSVGdkCursor_own (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#if GTK_CHECK_VERSION(2, 4, 0)
#define XSubPPtmpAAAB 1


XS_EUPXS(XS_Gtk2__Gdk__Cursor_new_from_pixbuf); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Cursor_new_from_pixbuf)
{
    dVAR; dXSARGS;
    if (items != 5)
       croak_xs_usage(cv,  "class, display, pixbuf, x, y");
    {
	GdkDisplay *	display = SvGdkDisplay (ST(1))
;
	GdkPixbuf *	pixbuf = SvGdkPixbuf (ST(2))
;
	gint	x = (gint)SvIV(ST(3))
;
	gint	y = (gint)SvIV(ST(4))
;
	GdkCursor_own *	RETVAL;

	RETVAL = gdk_cursor_new_from_pixbuf(display, pixbuf, x, y);
	ST(0) = newSVGdkCursor_own (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif
#if GTK_CHECK_VERSION (2, 8, 0)
#define XSubPPtmpAAAC 1


XS_EUPXS(XS_Gtk2__Gdk__Cursor_new_from_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Cursor_new_from_name)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "class, display, name");
    {
	GdkDisplay *	display = SvGdkDisplay (ST(1))
;
	const gchar *	name;
	GdkCursor_own *	RETVAL;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(2));
	name = (const gchar *)SvPV_nolen (ST(2))
;

	RETVAL = gdk_cursor_new_from_name(display, name);
	ST(0) = newSVGdkCursor_own (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Gdk__Cursor_get_image); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Cursor_get_image)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "cursor");
    {
	GdkPixbuf_noinc *	RETVAL;
	GdkCursor *	cursor = SvGdkCursor (ST(0))
;

	RETVAL = gdk_cursor_get_image(cursor);
	ST(0) = newSVGdkPixbuf_noinc (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif
#if GTK_CHECK_VERSION (2, 22, 0)
#define XSubPPtmpAAAD 1


XS_EUPXS(XS_Gtk2__Gdk__Cursor_get_cursor_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Cursor_get_cursor_type)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "cursor");
    {
	GdkCursorType	RETVAL;
	GdkCursor *	cursor = SvGdkCursor (ST(0))
;

	RETVAL = gdk_cursor_get_cursor_type(cursor);
	ST(0) = newSVGdkCursorType (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif /* 2.22 */
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__Gdk__Cursor); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__Gdk__Cursor)
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

        newXS("Gtk2::Gdk::Cursor::type", XS_Gtk2__Gdk__Cursor_type, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::Gdk::Cursor::new_for_display", XS_Gtk2__Gdk__Cursor_new_for_display, file);
        newXS("Gtk2::Gdk::Cursor::get_display", XS_Gtk2__Gdk__Cursor_get_display, file);
#endif
        newXS("Gtk2::Gdk::Cursor::new", XS_Gtk2__Gdk__Cursor_new, file);
        newXS("Gtk2::Gdk::Cursor::new_from_pixmap", XS_Gtk2__Gdk__Cursor_new_from_pixmap, file);
#if XSubPPtmpAAAB
        newXS("Gtk2::Gdk::Cursor::new_from_pixbuf", XS_Gtk2__Gdk__Cursor_new_from_pixbuf, file);
#endif
#if XSubPPtmpAAAC
        newXS("Gtk2::Gdk::Cursor::new_from_name", XS_Gtk2__Gdk__Cursor_new_from_name, file);
        newXS("Gtk2::Gdk::Cursor::get_image", XS_Gtk2__Gdk__Cursor_get_image, file);
#endif
#if XSubPPtmpAAAD
        newXS("Gtk2::Gdk::Cursor::get_cursor_type", XS_Gtk2__Gdk__Cursor_get_cursor_type, file);
#endif

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#if XSubPPtmpAAAB
#endif
#if XSubPPtmpAAAC
#endif
#if XSubPPtmpAAAD
#endif
#line 437 "xs\\GdkCursor.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

