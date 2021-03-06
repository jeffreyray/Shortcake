/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GdkImage.xs. Do not edit this file, edit GdkImage.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GdkImage.xs"
/*
 * Copyright (c) 2010 by the gtk2-perl team (see the file AUTHORS)
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
 */

#include "gtk2perl.h"

#if ! GTK_CHECK_VERSION (2, 22, 0)
/* plain fields before the accessor funcs
   of course the plain fields are better :-( */
#define gdk_image_get_bits_per_pixel(image)  ((image)->bits_per_pixel)
#define gdk_image_get_bytes_per_pixel(image) ((image)->bpp)
#define gdk_image_get_bytes_per_line(image)  ((image)->bpl)
#define gdk_image_get_byte_order(image)      ((image)->byte_order)
#define gdk_image_get_depth(image)           ((image)->depth)
#define gdk_image_get_height(image)          ((image)->height)
#define gdk_image_get_image_type(image)      ((image)->type)
#define gdk_image_get_visual(image)          ((image)->visual)
#define gdk_image_get_width(image)   	     ((image)->width)
#define gdk_image_get_pixels(image)  	     ((image)->mem)
#endif

#line 47 "xs\\GdkImage.c"
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

#line 189 "xs\\GdkImage.c"

XS_EUPXS(XS_Gtk2__Gdk__Image_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Image_new)
{
    dVAR; dXSARGS;
    if (items != 5)
       croak_xs_usage(cv,  "class, type, visual, width, height");
    {
	GdkImageType	type = SvGdkImageType (ST(1))
;
	GdkVisual *	visual = SvGdkVisual (ST(2))
;
	gint	width = (gint)SvIV(ST(3))
;
	gint	height = (gint)SvIV(ST(4))
;
	GdkImage_noinc_ornull *	RETVAL;

	RETVAL = gdk_image_new(type, visual, width, height);
	ST(0) = newSVGdkImage_noinc_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Gdk__Image_put_pixel); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Image_put_pixel)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "image, x, y, pixel");
    {
	GdkImage *	image = SvGdkImage (ST(0))
;
	gint	x = (gint)SvIV(ST(1))
;
	gint	y = (gint)SvIV(ST(2))
;
	guint32	pixel = (guint32)SvUV(ST(3))
;

	gdk_image_put_pixel(image, x, y, pixel);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Gdk__Image_get_pixel); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Image_get_pixel)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "image, x, y");
    {
	GdkImage *	image = SvGdkImage (ST(0))
;
	gint	x = (gint)SvIV(ST(1))
;
	gint	y = (gint)SvIV(ST(2))
;
	guint32	RETVAL;
	dXSTARG;

	RETVAL = gdk_image_get_pixel(image, x, y);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Gdk__Image_set_colormap); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Image_set_colormap)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "image, colormap");
    {
	GdkImage *	image = SvGdkImage (ST(0))
;
	GdkColormap *	colormap = SvGdkColormap (ST(1))
;

	gdk_image_set_colormap(image, colormap);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Gdk__Image_get_colormap); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Image_get_colormap)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "image");
    {
	GdkImage *	image = SvGdkImage (ST(0))
;
	GdkColormap *	RETVAL;

	RETVAL = gdk_image_get_colormap(image);
	ST(0) = newSVGdkColormap (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef GDK_ENABLE_BROKEN
#endif /* GDK_ENABLE_BROKEN */

XS_EUPXS(XS_Gtk2__Gdk__Image_get_image_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Image_get_image_type)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "image");
    {
	GdkImage *	image = SvGdkImage (ST(0))
;
	GdkImageType	RETVAL;

	RETVAL = gdk_image_get_image_type(image);
	ST(0) = newSVGdkImageType (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Gdk__Image_get_visual); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Image_get_visual)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "image");
    {
	GdkImage *	image = SvGdkImage (ST(0))
;
	GdkVisual *	RETVAL;

	RETVAL = gdk_image_get_visual(image);
	ST(0) = newSVGdkVisual (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Gdk__Image_get_byte_order); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Image_get_byte_order)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "image");
    {
	GdkImage *	image = SvGdkImage (ST(0))
;
	GdkByteOrder	RETVAL;

	RETVAL = gdk_image_get_byte_order(image);
	ST(0) = newSVGdkByteOrder (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Gdk__Image_get_bytes_per_pixel); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Image_get_bytes_per_pixel)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 1)
       croak_xs_usage(cv,  "image");
    {
	GdkImage *	image = SvGdkImage (ST(0))
;
	gint	RETVAL;
	dXSTARG;
#line 174 "xs\\\\GdkImage.xs"
	/* the guint16 fields expand to gint for RETVAL */
	switch (ix) {
	case 0:  RETVAL = gdk_image_get_bytes_per_pixel(image); break;
	case 1:  RETVAL = gdk_image_get_bytes_per_line(image);  break;
	case 2:  RETVAL = gdk_image_get_bits_per_pixel(image);  break;
	case 3:  RETVAL = gdk_image_get_depth(image);           break;
	case 4:  RETVAL = gdk_image_get_width(image);           break;
	default: /* case 5 */
		 RETVAL = gdk_image_get_height(image);          break;
	}
#line 380 "xs\\GdkImage.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Gdk__Image_get_pixels); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Image_get_pixels)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "image");
    {
	GdkImage *	image = SvGdkImage (ST(0))
;
	SV *	RETVAL;
#line 212 "xs\\\\GdkImage.xs"
        /* Crib note: memory block size is "bytes_per_line * height" per the
           shmget() or malloc() in _gdk_image_new_for_depth() of
           gdkimage-x11.c */
	RETVAL = newSVpv ((char *) image->mem, image->bpl * image->height);
#line 402 "xs\\GdkImage.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__Gdk__Image); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__Gdk__Image)
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

        newXS("Gtk2::Gdk::Image::new", XS_Gtk2__Gdk__Image_new, file);
        newXS("Gtk2::Gdk::Image::put_pixel", XS_Gtk2__Gdk__Image_put_pixel, file);
        newXS("Gtk2::Gdk::Image::get_pixel", XS_Gtk2__Gdk__Image_get_pixel, file);
        newXS("Gtk2::Gdk::Image::set_colormap", XS_Gtk2__Gdk__Image_set_colormap, file);
        newXS("Gtk2::Gdk::Image::get_colormap", XS_Gtk2__Gdk__Image_get_colormap, file);
        newXS("Gtk2::Gdk::Image::get_image_type", XS_Gtk2__Gdk__Image_get_image_type, file);
        newXS("Gtk2::Gdk::Image::get_visual", XS_Gtk2__Gdk__Image_get_visual, file);
        newXS("Gtk2::Gdk::Image::get_byte_order", XS_Gtk2__Gdk__Image_get_byte_order, file);
        cv = newXS("Gtk2::Gdk::Image::get_width", XS_Gtk2__Gdk__Image_get_bytes_per_pixel, file);
        XSANY.any_i32 = 4;
        cv = newXS("Gtk2::Gdk::Image::get_bytes_per_line", XS_Gtk2__Gdk__Image_get_bytes_per_pixel, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::Gdk::Image::get_bytes_per_pixel", XS_Gtk2__Gdk__Image_get_bytes_per_pixel, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::Gdk::Image::get_height", XS_Gtk2__Gdk__Image_get_bytes_per_pixel, file);
        XSANY.any_i32 = 5;
        cv = newXS("Gtk2::Gdk::Image::get_depth", XS_Gtk2__Gdk__Image_get_bytes_per_pixel, file);
        XSANY.any_i32 = 3;
        cv = newXS("Gtk2::Gdk::Image::get_bits_per_pixel", XS_Gtk2__Gdk__Image_get_bytes_per_pixel, file);
        XSANY.any_i32 = 2;
        newXS("Gtk2::Gdk::Image::get_pixels", XS_Gtk2__Gdk__Image_get_pixels, file);
    }
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

