/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkColorSelection.xs. Do not edit this file, edit GtkColorSelection.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkColorSelection.xs"
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

#line 34 "xs\\GtkColorSelection.c"
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

#line 176 "xs\\GtkColorSelection.c"

XS_EUPXS(XS_Gtk2__ColorSelection_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	GtkWidget *	RETVAL;

	RETVAL = gtk_color_selection_new(/* void */);
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ColorSelection_get_has_opacity_control); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_get_has_opacity_control)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "colorsel");
    {
	GtkColorSelection *	colorsel = SvGtkColorSelection (ST(0))
;
	gboolean	RETVAL;

	RETVAL = gtk_color_selection_get_has_opacity_control(colorsel);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ColorSelection_set_has_opacity_control); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_set_has_opacity_control)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "colorsel, has_opacity");
    {
	GtkColorSelection *	colorsel = SvGtkColorSelection (ST(0))
;
	gboolean	has_opacity = (bool)SvTRUE(ST(1))
;

	gtk_color_selection_set_has_opacity_control(colorsel, has_opacity);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ColorSelection_get_has_palette); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_get_has_palette)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "colorsel");
    {
	GtkColorSelection *	colorsel = SvGtkColorSelection (ST(0))
;
	gboolean	RETVAL;

	RETVAL = gtk_color_selection_get_has_palette(colorsel);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ColorSelection_set_has_palette); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_set_has_palette)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "colorsel, has_palette");
    {
	GtkColorSelection *	colorsel = SvGtkColorSelection (ST(0))
;
	gboolean	has_palette = (bool)SvTRUE(ST(1))
;

	gtk_color_selection_set_has_palette(colorsel, has_palette);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ColorSelection_set_current_color); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_set_current_color)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "colorsel, color");
    {
	GtkColorSelection *	colorsel = SvGtkColorSelection (ST(0))
;
	GdkColor *	color = SvGdkColor (ST(1))
;

	gtk_color_selection_set_current_color(colorsel, color);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ColorSelection_set_current_alpha); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_set_current_alpha)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "colorsel, alpha");
    {
	GtkColorSelection *	colorsel = SvGtkColorSelection (ST(0))
;
	guint16	alpha = (guint16)SvUV(ST(1))
;

	gtk_color_selection_set_current_alpha(colorsel, alpha);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ColorSelection_get_current_color); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_get_current_color)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "colorsel");
    {
	GtkColorSelection *	colorsel = SvGtkColorSelection (ST(0))
;
#line 70 "xs\\\\GtkColorSelection.xs"
	GdkColor color;
#line 316 "xs\\GtkColorSelection.c"
	GdkColor_copy *	RETVAL;
#line 72 "xs\\\\GtkColorSelection.xs"
	gtk_color_selection_get_current_color (colorsel, &color);
	RETVAL = &color;
#line 321 "xs\\GtkColorSelection.c"
	ST(0) = newSVGdkColor_copy (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ColorSelection_get_current_alpha); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_get_current_alpha)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "colorsel");
    {
	GtkColorSelection *	colorsel = SvGtkColorSelection (ST(0))
;
	guint16	RETVAL;
	dXSTARG;

	RETVAL = gtk_color_selection_get_current_alpha(colorsel);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ColorSelection_set_previous_color); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_set_previous_color)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "colorsel, color");
    {
	GtkColorSelection *	colorsel = SvGtkColorSelection (ST(0))
;
	GdkColor *	color = SvGdkColor (ST(1))
;

	gtk_color_selection_set_previous_color(colorsel, color);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ColorSelection_set_previous_alpha); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_set_previous_alpha)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "colorsel, alpha");
    {
	GtkColorSelection *	colorsel = SvGtkColorSelection (ST(0))
;
	guint16	alpha = (guint16)SvUV(ST(1))
;

	gtk_color_selection_set_previous_alpha(colorsel, alpha);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ColorSelection_get_previous_color); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_get_previous_color)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "colorsel");
    {
	GtkColorSelection *	colorsel = SvGtkColorSelection (ST(0))
;
#line 99 "xs\\\\GtkColorSelection.xs"
	GdkColor color;
#line 395 "xs\\GtkColorSelection.c"
	GdkColor_copy *	RETVAL;
#line 101 "xs\\\\GtkColorSelection.xs"
	gtk_color_selection_get_previous_color (colorsel, &color);
	RETVAL = &color;
#line 400 "xs\\GtkColorSelection.c"
	ST(0) = newSVGdkColor_copy (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ColorSelection_get_previous_alpha); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_get_previous_alpha)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "colorsel");
    {
	GtkColorSelection *	colorsel = SvGtkColorSelection (ST(0))
;
	guint16	RETVAL;
	dXSTARG;

	RETVAL = gtk_color_selection_get_previous_alpha(colorsel);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ColorSelection_is_adjusting); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_is_adjusting)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "colorsel");
    {
	GtkColorSelection *	colorsel = SvGtkColorSelection (ST(0))
;
	gboolean	RETVAL;

	RETVAL = gtk_color_selection_is_adjusting(colorsel);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ColorSelection_palette_from_string); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_palette_from_string)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, string");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	gchar *	string;
#line 124 "xs\\\\GtkColorSelection.xs"
	GdkColor * colors;
	gint n_colors;
	int i;
#line 460 "xs\\GtkColorSelection.c"

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	string = (gchar *)SvPV_nolen (ST(1))
;
#line 128 "xs\\\\GtkColorSelection.xs"
	if (!gtk_color_selection_palette_from_string (string,
						&colors, &n_colors))
		XSRETURN_EMPTY;
	EXTEND (SP, n_colors);
	for (i = 0; i < n_colors; i++)
		PUSHs (sv_2mortal (newSVGdkColor_copy (&(colors[i]))));
	g_free (colors);
#line 474 "xs\\GtkColorSelection.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__ColorSelection_palette_to_string); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ColorSelection_palette_to_string)
{
    dVAR; dXSARGS;
    if (items < 1)
       croak_xs_usage(cv,  "class, ...");
    {
#line 145 "xs\\\\GtkColorSelection.xs"
	GdkColor * colors;
	gint n_colors;
	gchar * string;
	int i;
#line 493 "xs\\GtkColorSelection.c"
	SV *	RETVAL;
#line 150 "xs\\\\GtkColorSelection.xs"
	n_colors = items - 1;
	for (i = 0 ; i < n_colors ; i++) {
		/* this will croak if any of the items are not valid */
		gperl_get_boxed_check (ST (i+1), GDK_TYPE_COLOR);
	}
	/* now that we know we won't croak, it's safe to alloc some memory. */
	colors = g_new0 (GdkColor, n_colors);
	for (i = 0 ; i < n_colors ; i++) {
		GdkColor * c =
			gperl_get_boxed_check (ST (i+1), GDK_TYPE_COLOR);
		colors[i] = *c;
	}
	string = gtk_color_selection_palette_to_string (colors, n_colors);
	RETVAL = newSVpv (string, 0);
	g_free (colors);
	g_free (string);
#line 512 "xs\\GtkColorSelection.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__ColorSelection); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__ColorSelection)
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

        newXS("Gtk2::ColorSelection::new", XS_Gtk2__ColorSelection_new, file);
        newXS("Gtk2::ColorSelection::get_has_opacity_control", XS_Gtk2__ColorSelection_get_has_opacity_control, file);
        newXS("Gtk2::ColorSelection::set_has_opacity_control", XS_Gtk2__ColorSelection_set_has_opacity_control, file);
        newXS("Gtk2::ColorSelection::get_has_palette", XS_Gtk2__ColorSelection_get_has_palette, file);
        newXS("Gtk2::ColorSelection::set_has_palette", XS_Gtk2__ColorSelection_set_has_palette, file);
        newXS("Gtk2::ColorSelection::set_current_color", XS_Gtk2__ColorSelection_set_current_color, file);
        newXS("Gtk2::ColorSelection::set_current_alpha", XS_Gtk2__ColorSelection_set_current_alpha, file);
        newXS("Gtk2::ColorSelection::get_current_color", XS_Gtk2__ColorSelection_get_current_color, file);
        newXS("Gtk2::ColorSelection::get_current_alpha", XS_Gtk2__ColorSelection_get_current_alpha, file);
        newXS("Gtk2::ColorSelection::set_previous_color", XS_Gtk2__ColorSelection_set_previous_color, file);
        newXS("Gtk2::ColorSelection::set_previous_alpha", XS_Gtk2__ColorSelection_set_previous_alpha, file);
        newXS("Gtk2::ColorSelection::get_previous_color", XS_Gtk2__ColorSelection_get_previous_color, file);
        newXS("Gtk2::ColorSelection::get_previous_alpha", XS_Gtk2__ColorSelection_get_previous_alpha, file);
        newXS("Gtk2::ColorSelection::is_adjusting", XS_Gtk2__ColorSelection_is_adjusting, file);
        newXS("Gtk2::ColorSelection::palette_from_string", XS_Gtk2__ColorSelection_palette_from_string, file);
        newXS("Gtk2::ColorSelection::palette_to_string", XS_Gtk2__ColorSelection_palette_to_string, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
