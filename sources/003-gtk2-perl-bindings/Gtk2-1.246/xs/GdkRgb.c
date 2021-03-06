/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GdkRgb.xs. Do not edit this file, edit GdkRgb.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GdkRgb.xs"
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

/*
####MODULE = Gtk2::Gdk::Rgb	PACKAGE = Gtk2::Gdk::Drawable	PREFIX = gdk_

 ## no longer does anything, no need to bind it
##  void gdk_rgb_init (void) 

 ## deprecated
##  gulong gdk_rgb_xpixel_from_rgb (guint32 rgb) G_GNUC_CONST 
*/

static guchar *
SvImageDataPointer (SV * sv)
{
	if (gperl_sv_is_defined (sv)) {
		if (SvIOK (sv))
			return INT2PTR (guchar*, SvUV (sv));
		else if (SvPOK (sv))
			return (guchar *) SvPV_nolen (sv);
	}
	croak ("expecting either a string containing pixel data or "
	       "an integer pointing to the underlying C image data "
	       "buffer");
	return NULL; /* not reached */
}

static GdkRgbCmap *
SvGdkRgbCmap (SV *sv)
{
	GdkRgbCmap *cmap = NULL;
	AV *av;
	int length, i;

	if (!gperl_sv_is_array_ref (sv))
		croak ("cmap must be an array reference");

	av = (AV *) SvRV (sv);
	length = av_len (av);

	if (length > 255)
		croak ("a cmap may not consist of more than 256 colors");

	cmap = gperl_alloc_temp (sizeof (GdkRgbCmap));
	cmap->n_colors = length + 1;

	for (i = 0; i <= length; i++) {
		SV **color = av_fetch (av, i, 0);
		if (color && gperl_sv_is_defined (*color))
			cmap->colors[i] = SvIV (*color);
	}

	return cmap;
}

#line 86 "xs\\GdkRgb.c"
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

#line 228 "xs\\GdkRgb.c"

XS_EUPXS(XS_Gtk2__Gdk__GC_rgb_gc_set_foreground); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__GC_rgb_gc_set_foreground)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 2)
       croak_xs_usage(cv,  "gc, rgb");
    {
	GdkGC *	gc = SvGdkGC (ST(0))
;
	guint32	rgb = (guint32)SvUV(ST(1))
;

	gdk_rgb_gc_set_foreground(gc, rgb);
#line 83 "xs\\\\GdkRgb.xs"
	PERL_UNUSED_VAR (ix);
#line 246 "xs\\GdkRgb.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Gdk__GC_rgb_gc_set_background); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__GC_rgb_gc_set_background)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 2)
       croak_xs_usage(cv,  "gc, rgb");
    {
	GdkGC *	gc = SvGdkGC (ST(0))
;
	guint32	rgb = (guint32)SvUV(ST(1))
;

	gdk_rgb_gc_set_background(gc, rgb);
#line 90 "xs\\\\GdkRgb.xs"
	PERL_UNUSED_VAR (ix);
#line 268 "xs\\GdkRgb.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Gdk__Colormap_rgb_find_color); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Colormap_rgb_find_color)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "colormap, color");
    {
	GdkColormap *	colormap = SvGdkColormap (ST(0))
;
	GdkColor *	color = SvGdkColor (ST(1))
;

	gdk_rgb_find_color(colormap, color);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Gdk__Drawable_draw_rgb_image); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Drawable_draw_rgb_image)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 9)
       croak_xs_usage(cv,  "drawable, gc, x, y, width, height, dith, buf, rowstride");
    {
	GdkDrawable *	drawable = SvGdkDrawable (ST(0))
;
	GdkGC *	gc = SvGdkGC (ST(1))
;
	gint	x = (gint)SvIV(ST(2))
;
	gint	y = (gint)SvIV(ST(3))
;
	gint	width = (gint)SvIV(ST(4))
;
	gint	height = (gint)SvIV(ST(5))
;
	GdkRgbDither	dith = SvGdkRgbDither (ST(6))
;
	SV *	buf = ST(7)
;
	gint	rowstride = (gint)SvIV(ST(8))
;
#line 117 "xs\\\\GdkRgb.xs"
	switch (ix) {
	    case 0:
		gdk_draw_rgb_image (drawable, gc, x, y, width, height,
		                    dith, SvImageDataPointer(buf),
		                    rowstride);
		break;
	    case 1:
		gdk_draw_rgb_32_image (drawable, gc, x, y, width, height,
		                       dith, SvImageDataPointer(buf),
		                       rowstride);
		break;
	    case 2:
		gdk_draw_gray_image (drawable, gc, x, y, width, height,
		                     dith, SvImageDataPointer(buf),
		                     rowstride);
		break;
	    default:
		g_assert_not_reached ();
	}
#line 338 "xs\\GdkRgb.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Gdk__Drawable_draw_rgb_image_dithalign); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Drawable_draw_rgb_image_dithalign)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 11)
       croak_xs_usage(cv,  "drawable, gc, x, y, width, height, dith, rgb_buf, rowstride, xdith, ydith");
    {
	GdkDrawable *	drawable = SvGdkDrawable (ST(0))
;
	GdkGC *	gc = SvGdkGC (ST(1))
;
	gint	x = (gint)SvIV(ST(2))
;
	gint	y = (gint)SvIV(ST(3))
;
	gint	width = (gint)SvIV(ST(4))
;
	gint	height = (gint)SvIV(ST(5))
;
	GdkRgbDither	dith = SvGdkRgbDither (ST(6))
;
	SV *	rgb_buf = ST(7)
;
	gint	rowstride = (gint)SvIV(ST(8))
;
	gint	xdith = (gint)SvIV(ST(9))
;
	gint	ydith = (gint)SvIV(ST(10))
;
#line 155 "xs\\\\GdkRgb.xs"
	if (ix == 1)
		gdk_draw_rgb_32_image_dithalign (drawable, gc, x, y,
		                                 width, height, dith,
		                                 SvImageDataPointer (rgb_buf),
		                                 rowstride, xdith, ydith);
	else
		gdk_draw_rgb_image_dithalign (drawable, gc, x, y,
		                              width, height, dith,
		                              SvImageDataPointer(rgb_buf),
		                              rowstride, xdith, ydith);
#line 385 "xs\\GdkRgb.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Gdk__Drawable_draw_indexed_image); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Drawable_draw_indexed_image)
{
    dVAR; dXSARGS;
    if (items != 10)
       croak_xs_usage(cv,  "drawable, gc, x, y, width, height, dith, buf, rowstride, cmap");
    {
	GdkDrawable *	drawable = SvGdkDrawable (ST(0))
;
	GdkGC *	gc = SvGdkGC (ST(1))
;
	gint	x = (gint)SvIV(ST(2))
;
	gint	y = (gint)SvIV(ST(3))
;
	gint	width = (gint)SvIV(ST(4))
;
	gint	height = (gint)SvIV(ST(5))
;
	GdkRgbDither	dith = SvGdkRgbDither (ST(6))
;
	SV *	buf = ST(7)
;
	gint	rowstride = (gint)SvIV(ST(8))
;
	SV *	cmap = ST(9)
;
#line 180 "xs\\\\GdkRgb.xs"
	gdk_draw_indexed_image (drawable,
	                        gc,
	                        x,
	                        y,
	                        width,
	                        height,
	                        dith,
	                        SvImageDataPointer (buf),
	                        rowstride,
	                        SvGdkRgbCmap (cmap));
#line 429 "xs\\GdkRgb.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Gdk__Rgb_set_verbose); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Rgb_set_verbose)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, verbose");
    {
	gboolean	verbose = (bool)SvTRUE(ST(1))
;

	gdk_rgb_set_verbose(verbose);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Gdk__Rgb_set_install); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Rgb_set_install)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, install");
    {
	gboolean	install = (bool)SvTRUE(ST(1))
;

	gdk_rgb_set_install(install);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Gdk__Rgb_set_min_colors); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Rgb_set_min_colors)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, min_colors");
    {
	gint	min_colors = (gint)SvIV(ST(1))
;

	gdk_rgb_set_min_colors(min_colors);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Gdk__Rgb_ditherable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Rgb_ditherable)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	gboolean	RETVAL;

	RETVAL = gdk_rgb_ditherable(/*void*/);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#if GTK_CHECK_VERSION (2, 6, 0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__Gdk__Rgb_colormap_ditherable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Gdk__Rgb_colormap_ditherable)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, cmap");
    {
	GdkColormap *	cmap = SvGdkColormap (ST(1))
;
	gboolean	RETVAL;

	RETVAL = gdk_rgb_colormap_ditherable(cmap);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__Gdk__Rgb); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__Gdk__Rgb)
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

        cv = newXS("Gtk2::Gdk::GC::rgb_gc_set_foreground", XS_Gtk2__Gdk__GC_rgb_gc_set_foreground, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::Gdk::GC::set_rgb_foreground", XS_Gtk2__Gdk__GC_rgb_gc_set_foreground, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::Gdk::GC::rgb_gc_set_background", XS_Gtk2__Gdk__GC_rgb_gc_set_background, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::Gdk::GC::set_rgb_background", XS_Gtk2__Gdk__GC_rgb_gc_set_background, file);
        XSANY.any_i32 = 1;
        newXS("Gtk2::Gdk::Colormap::rgb_find_color", XS_Gtk2__Gdk__Colormap_rgb_find_color, file);
        cv = newXS("Gtk2::Gdk::Drawable::draw_gray_image", XS_Gtk2__Gdk__Drawable_draw_rgb_image, file);
        XSANY.any_i32 = 2;
        cv = newXS("Gtk2::Gdk::Drawable::draw_rgb_32_image", XS_Gtk2__Gdk__Drawable_draw_rgb_image, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::Gdk::Drawable::draw_rgb_image", XS_Gtk2__Gdk__Drawable_draw_rgb_image, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::Gdk::Drawable::draw_rgb_32_image_dithalign", XS_Gtk2__Gdk__Drawable_draw_rgb_image_dithalign, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::Gdk::Drawable::draw_rgb_image_dithalign", XS_Gtk2__Gdk__Drawable_draw_rgb_image_dithalign, file);
        XSANY.any_i32 = 0;
        newXS("Gtk2::Gdk::Drawable::draw_indexed_image", XS_Gtk2__Gdk__Drawable_draw_indexed_image, file);
        newXS("Gtk2::Gdk::Rgb::set_verbose", XS_Gtk2__Gdk__Rgb_set_verbose, file);
        newXS("Gtk2::Gdk::Rgb::set_install", XS_Gtk2__Gdk__Rgb_set_install, file);
        newXS("Gtk2::Gdk::Rgb::set_min_colors", XS_Gtk2__Gdk__Rgb_set_min_colors, file);
        newXS("Gtk2::Gdk::Rgb::ditherable", XS_Gtk2__Gdk__Rgb_ditherable, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::Gdk::Rgb::colormap_ditherable", XS_Gtk2__Gdk__Rgb_colormap_ditherable, file);
#endif
    }

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#line 578 "xs\\GdkRgb.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

