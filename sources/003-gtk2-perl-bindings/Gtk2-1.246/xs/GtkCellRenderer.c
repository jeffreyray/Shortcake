/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkCellRenderer.xs. Do not edit this file, edit GtkCellRenderer.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkCellRenderer.xs"
/*
 * Copyright (c) 2003-2004, 2009 by the gtk2-perl team (see the file AUTHORS)
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

static void
warn_deprecated (const char * old_and_busted,
              const char * new_hotness)
{
	static int debugging_on = -1;
	if (debugging_on < 0) {
		HV * env = get_hv ("::ENV", FALSE);
		SV ** v = hv_fetch (env, "GTK2PERL_DEBUG", 14, 0);
		debugging_on = (v && SvTRUE (*v));
	}
	if (debugging_on) {
		if (new_hotness)
			warn ("%s is deprecated, use %s instead",
			      old_and_busted, new_hotness);
		else
			warn ("%s is deprecated", old_and_busted);
	}
}

#define newSVGChar_ornull(s)	\
	((s) ? newSVGChar(s) : newSVsv (&PL_sv_undef))


static void gtk2perl_cell_renderer_class_init
                                      (GtkCellRendererClass * class);
static void gtk2perl_cell_renderer_get_size
                                      (GtkCellRenderer      * cell,
				       GtkWidget            * widget,
				       GdkRectangle         * cell_area,
				       gint                 * x_offset,
				       gint                 * y_offset,
				       gint                 * width,
				       gint                 * height);
static void gtk2perl_cell_renderer_render
                                      (GtkCellRenderer      * cell,
#if GTK_CHECK_VERSION(2,4,0)
                                       GdkDrawable          * window,
#else
				       GdkWindow            * window,
#endif
				       GtkWidget            * widget,
				       GdkRectangle         * background_area,
				       GdkRectangle         * cell_area,
				       GdkRectangle         * expose_area,
				       GtkCellRendererState   flags);
static gboolean gtk2perl_cell_renderer_activate
                                      (GtkCellRenderer      * cell,
				       GdkEvent             * event,
				       GtkWidget            * widget,
				       const gchar          * path,
				       GdkRectangle         * background_area,
				       GdkRectangle         * cell_area,
				       GtkCellRendererState   flags);
static GtkCellEditable * gtk2perl_cell_renderer_start_editing
                                      (GtkCellRenderer      * cell,
				       GdkEvent             * event,
				       GtkWidget            * widget,
				       const gchar          * path,
				       GdkRectangle         * background_area,
				       GdkRectangle         * cell_area,
				       GtkCellRendererState   flags);

/*
 * this mangles a CellRendererClass to call the local marshallers.
 * you should only ever call this on a new subclass of CellRenderer, never
 * directly on a preexisting CellRendererClass.
 */
static void
gtk2perl_cell_renderer_class_init (GtkCellRendererClass * class)
{
	class->get_size      = gtk2perl_cell_renderer_get_size;
	class->render        = gtk2perl_cell_renderer_render;
	class->activate      = gtk2perl_cell_renderer_activate;
	class->start_editing = gtk2perl_cell_renderer_start_editing;
}

/*
 * the following functions look for WHATEVER in the package belonging
 * to a cell.  this is our custom override, since CellRenderer does not
 * have signals for these virtual methods.
 */

#define GET_METHOD(cell, method, fallback)	\
	HV * stash = gperl_object_stash_from_type (G_OBJECT_TYPE (cell)); \
	GV * slot = gv_fetchmethod (stash, fallback);			  \
									  \
	if (slot && GvCV (slot))					  \
		warn_deprecated (fallback, method);			  \
	else								  \
		slot = gv_fetchmethod (stash, method);

static void
gtk2perl_cell_renderer_get_size (GtkCellRenderer      * cell,
				 GtkWidget            * widget,
				 GdkRectangle         * cell_area,
				 gint                 * x_offset,
				 gint                 * y_offset,
				 gint                 * width,
				 gint                 * height)
{
	GET_METHOD (cell, "GET_SIZE", "on_get_size");

	if (slot && GvCV (slot)) {
		int count, i;
		dSP;

		ENTER;
		SAVETMPS;
		PUSHMARK (SP);

		EXTEND (SP, 3);
		PUSHs (sv_2mortal (newSVGtkCellRenderer (cell)));
		PUSHs (sv_2mortal (newSVGtkWidget (widget)));
		PUSHs (sv_2mortal (newSVGdkRectangle_ornull (cell_area)));

		PUTBACK;
		count = call_sv ((SV *)GvCV (slot), G_ARRAY);
		SPAGAIN;
		if (count != 4)
			croak ("GET_SIZE must return four values -- "
			       "the x_offset, y_offset, width, and height");

		i = POPi;  if (height)   *height   = i;
		i = POPi;  if (width)    *width    = i;
		i = POPi;  if (y_offset) *y_offset = i;
		i = POPi;  if (x_offset) *x_offset = i;

		PUTBACK;
		FREETMPS;
		LEAVE;
	}
}

static void
gtk2perl_cell_renderer_render (GtkCellRenderer      * cell,
#if GTK_CHECK_VERSION(2,4,0)
			       GdkDrawable          * drawable,
#else
			       GdkWindow            * drawable,
#endif
			       GtkWidget            * widget,
			       GdkRectangle         * background_area,
			       GdkRectangle         * cell_area,
			       GdkRectangle         * expose_area,
			       GtkCellRendererState   flags)
{
	GET_METHOD (cell, "RENDER", "on_render");

	if (slot && GvCV (slot)) {
		dSP;

		ENTER;
		SAVETMPS;
		PUSHMARK (SP);

		EXTEND (SP, 7);
		PUSHs (sv_2mortal (newSVGtkCellRenderer (cell)));
		PUSHs (sv_2mortal (newSVGdkDrawable_ornull (drawable)));
		PUSHs (sv_2mortal (newSVGtkWidget_ornull (widget)));
		PUSHs (sv_2mortal (newSVGdkRectangle_ornull (background_area)));
		PUSHs (sv_2mortal (newSVGdkRectangle_ornull (cell_area)));
		PUSHs (sv_2mortal (newSVGdkRectangle_ornull (expose_area)));
		PUSHs (sv_2mortal (newSVGtkCellRendererState (flags)));

		PUTBACK;
		call_sv ((SV *)GvCV (slot), G_VOID|G_DISCARD);

		FREETMPS;
		LEAVE;
	}
}

static gboolean
gtk2perl_cell_renderer_activate (GtkCellRenderer      * cell,
				 GdkEvent             * event,
				 GtkWidget            * widget,
				 const gchar          * path,
				 GdkRectangle         * background_area,
				 GdkRectangle         * cell_area,
				 GtkCellRendererState   flags)
{
	gboolean retval = FALSE;

	GET_METHOD (cell, "ACTIVATE", "on_activate");

	if (slot && GvCV (slot)) {
		dSP;

		ENTER;
		SAVETMPS;
		PUSHMARK (SP);

		XPUSHs (sv_2mortal (newSVGtkCellRenderer (cell)));
		XPUSHs (sv_2mortal (newSVGdkEvent_ornull (event)));
		XPUSHs (sv_2mortal (newSVGtkWidget_ornull (widget)));
		XPUSHs (sv_2mortal (newSVGChar_ornull (path)));
		XPUSHs (sv_2mortal (newSVGdkRectangle_ornull (background_area)));
		XPUSHs (sv_2mortal (newSVGdkRectangle_ornull (cell_area)));
		XPUSHs (sv_2mortal (newSVGtkCellRendererState (flags)));

		PUTBACK;
		call_sv ((SV*) GvCV (slot), G_SCALAR);
		SPAGAIN;

		retval = POPi;

		PUTBACK;
		FREETMPS;
		LEAVE;
	}

	return retval;
}

static GtkCellEditable *
gtk2perl_cell_renderer_start_editing (GtkCellRenderer      * cell,
				      GdkEvent             * event,
				      GtkWidget            * widget,
				      const gchar          * path,
				      GdkRectangle         * background_area,
				      GdkRectangle         * cell_area,
				      GtkCellRendererState   flags)
{
	GtkCellEditable * editable = NULL;

	GET_METHOD (cell, "START_EDITING", "on_start_editing");

	if (slot && GvCV (slot)) {
		SV * sv;
		dSP;

		ENTER;
		SAVETMPS;
		PUSHMARK (SP);

		EXTEND (SP, 7);
		PUSHs (sv_2mortal (newSVGtkCellRenderer (cell)));
		PUSHs (sv_2mortal (newSVGdkEvent_ornull (event)));
		PUSHs (sv_2mortal (newSVGtkWidget_ornull (widget)));
		PUSHs (sv_2mortal (newSVGChar_ornull (path)));
		PUSHs (sv_2mortal (newSVGdkRectangle_ornull (background_area)));
		PUSHs (sv_2mortal (newSVGdkRectangle_ornull (cell_area)));
		PUSHs (sv_2mortal (newSVGtkCellRendererState (flags)));

		PUTBACK;
		call_sv ((SV*) GvCV (slot), G_SCALAR);
		SPAGAIN;

		sv = POPs;
		if (gperl_sv_is_defined (sv)) {
			editable = SvGtkCellEditable (sv);
#if GLIB_CHECK_VERSION (2, 10, 0)
			/* (*start_editing)() is basically a constructor and
			 * as such should return an object with a floating
			 * reference for the caller to take over.
			 *
			 * For GtkTreeView and GtkIconView for example that
			 * ref is sunk when gtk_tree_view_put() or
			 * gtk_icon_view_put() call gtk_widget_set_parent()
			 * to add "editable" as one of their container
			 * children.  (Eventually to be dereffed in the
			 * usual way by gtk_container_remove() from
			 * gtk_tree_view_remove_widget() or
			 * gtk_icon_view_remove_widget() at the end of
			 * editing.)
			 *
			 * Perl code constructors like Gtk2::Foo->new or
			 * Glib::Object->new sink any initial floating
			 * reference when making the wrapper (either if
			 * constructing in the START_EDITING code or from
			 * something made or wrapped previously).  So must
			 * explicitly add a floating ref for GtkTreeView etc
			 * to take over.
			 *
			 * If START_EDITING code gives a new object in "sv"
			 * and it's used nowhere else then FREETMPS below
			 * will SvREFCNT_dec it to zero and send it to the
			 * usual Glib::Object::DESTROY.  If there wasn't a
			 * floating ref added here on the GObject then that
			 * GObject would be destroyed before we ever got to
			 * return it.  With the extra floating ref the
			 * wrapper converts to undead (ie. unused from perl
			 * for the time being) and the GObject has a
			 * refcount of 1 and the floating flag set.
			 *
			 * It's conceivable there could be a floating ref
			 * already at this point.  That was the case in the
			 * past from chained-up perl SUPER::START_EDITING
			 * for instance.  Though it's abnormal let's assume
			 * any floating ref here is meant for the caller to
			 * take over and therefore should be left unchanged.
			 */
			if (! g_object_is_floating (editable)) {
				g_object_ref (editable);
				g_object_force_floating (G_OBJECT (editable));
			}
#else
			if (! GTK_OBJECT_FLOATING (editable)) {
				gtk_object_ref (GTK_OBJECT (editable));
				GTK_OBJECT_SET_FLAGS (editable, GTK_FLOATING);
			}
#endif
		} else {
			editable = NULL;
		}

		PUTBACK;
		FREETMPS;
		LEAVE;
	}

	return editable;
}



#line 350 "xs\\GtkCellRenderer.c"
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

#line 492 "xs\\GtkCellRenderer.c"

XS_EUPXS(XS_Gtk2__CellRenderer_set_fixed_size); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_set_fixed_size)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "cell, width, height");
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
	gint	width = (gint)SvIV(ST(1))
;
	gint	height = (gint)SvIV(ST(2))
;

	gtk_cell_renderer_set_fixed_size(cell, width, height);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__CellRenderer_get_fixed_size); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_get_fixed_size)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "cell");
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
	gint	width;
	gint	height;

	gtk_cell_renderer_get_fixed_size(cell, &width, &height);
	XSprePUSH;	EXTEND(SP,2);
	PUSHs(sv_newmortal());
	sv_setiv(ST(0), (IV)width);
	PUSHs(sv_newmortal());
	sv_setiv(ST(1), (IV)height);
    }
    XSRETURN(2);
}


XS_EUPXS(XS_Gtk2__CellRenderer_get_size); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_get_size)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "cell, widget, cell_area");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
	GtkWidget *	widget = SvGtkWidget (ST(1))
;
	GdkRectangle_ornull *	cell_area = SvGdkRectangle_ornull (ST(2))
;
#line 541 "xs\\\\GtkCellRenderer.xs"
	gint x_offset;
	gint y_offset;
	gint width;
	gint height;
#line 557 "xs\\GtkCellRenderer.c"
#line 546 "xs\\\\GtkCellRenderer.xs"
	PUTBACK;
	gtk_cell_renderer_get_size(cell, widget, cell_area,
		&x_offset, &y_offset, &width, &height);
	SPAGAIN;
	EXTEND(SP,4);
	PUSHs(sv_2mortal(newSViv(x_offset)));
	PUSHs(sv_2mortal(newSViv(y_offset)));
	PUSHs(sv_2mortal(newSViv(width)));
	PUSHs(sv_2mortal(newSViv(height)));
#line 568 "xs\\GtkCellRenderer.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__CellRenderer_render); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_render)
{
    dVAR; dXSARGS;
    if (items != 7)
       croak_xs_usage(cv,  "cell, drawable, widget, background_area, cell_area, expose_area, flags");
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
	GdkDrawable *	drawable = SvGdkDrawable (ST(1))
;
	GtkWidget *	widget = SvGtkWidget (ST(2))
;
	GdkRectangle *	background_area = SvGdkRectangle (ST(3))
;
	GdkRectangle *	cell_area = SvGdkRectangle (ST(4))
;
	GdkRectangle *	expose_area = SvGdkRectangle (ST(5))
;
	GtkCellRendererState	flags = SvGtkCellRendererState (ST(6))
;

	gtk_cell_renderer_render(cell, drawable, widget, background_area, cell_area, expose_area, flags);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__CellRenderer_activate); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_activate)
{
    dVAR; dXSARGS;
    if (items != 7)
       croak_xs_usage(cv,  "cell, event, widget, path, background_area, cell_area, flags");
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
	GdkEvent *	event = SvGdkEvent (ST(1))
;
	GtkWidget *	widget = SvGtkWidget (ST(2))
;
	const gchar *	path;
	GdkRectangle *	background_area = SvGdkRectangle (ST(4))
;
	GdkRectangle *	cell_area = SvGdkRectangle (ST(5))
;
	GtkCellRendererState	flags = SvGtkCellRendererState (ST(6))
;
	gboolean	RETVAL;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(3));
	path = (const gchar *)SvPV_nolen (ST(3))
;

	RETVAL = gtk_cell_renderer_activate(cell, event, widget, path, background_area, cell_area, flags);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__CellRenderer_start_editing); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_start_editing)
{
    dVAR; dXSARGS;
    if (items != 7)
       croak_xs_usage(cv,  "cell, event, widget, path, background_area, cell_area, flags");
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
	GdkEvent *	event = SvGdkEvent (ST(1))
;
	GtkWidget *	widget = SvGtkWidget (ST(2))
;
	const gchar *	path;
	GdkRectangle *	background_area = SvGdkRectangle (ST(4))
;
	GdkRectangle *	cell_area = SvGdkRectangle (ST(5))
;
	GtkCellRendererState	flags = SvGtkCellRendererState (ST(6))
;
	GtkWidget_ornull *	RETVAL;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(3));
	path = (const gchar *)SvPV_nolen (ST(3))
;
#line 607 "xs\\\\GtkCellRenderer.xs"
	RETVAL = GTK_WIDGET (gtk_cell_renderer_start_editing (cell, event, widget, path, background_area, cell_area, flags));
#line 666 "xs\\GtkCellRenderer.c"
	ST(0) = newSVGtkWidget_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#if GTK_CHECK_VERSION (2, 4, 0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__CellRenderer_editing_canceled); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_editing_canceled)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "cell");
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;

	gtk_cell_renderer_editing_canceled(cell);
    }
    XSRETURN_EMPTY;
}

#endif
#if GTK_CHECK_VERSION (2, 6, 0)
#define XSubPPtmpAAAB 1


XS_EUPXS(XS_Gtk2__CellRenderer_stop_editing); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_stop_editing)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "cell, canceled");
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
	gboolean	canceled = (bool)SvTRUE(ST(1))
;

	gtk_cell_renderer_stop_editing(cell, canceled);
    }
    XSRETURN_EMPTY;
}

#endif
#if GTK_CHECK_VERSION (2, 18, 0)
#define XSubPPtmpAAAC 1


XS_EUPXS(XS_Gtk2__CellRenderer_get_visible); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_get_visible)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "cell");
    {
	gboolean	RETVAL;
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;

	RETVAL = gtk_cell_renderer_get_visible(cell);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__CellRenderer_set_visible); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_set_visible)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "cell, visible");
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
	gboolean	visible = (bool)SvTRUE(ST(1))
;

	gtk_cell_renderer_set_visible(cell, visible);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__CellRenderer_get_sensitive); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_get_sensitive)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "cell");
    {
	gboolean	RETVAL;
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;

	RETVAL = gtk_cell_renderer_get_sensitive(cell);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__CellRenderer_set_sensitive); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_set_sensitive)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "cell, sensitive");
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
	gboolean	sensitive = (bool)SvTRUE(ST(1))
;

	gtk_cell_renderer_set_sensitive(cell, sensitive);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__CellRenderer_get_alignment); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_get_alignment)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "cell");
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
	gfloat	xalign;
	gfloat	yalign;

	gtk_cell_renderer_get_alignment(cell, &xalign, &yalign);
	XSprePUSH;	EXTEND(SP,2);
	PUSHs(sv_newmortal());
	sv_setnv(ST(0), (double)xalign);
	PUSHs(sv_newmortal());
	sv_setnv(ST(1), (double)yalign);
    }
    XSRETURN(2);
}


XS_EUPXS(XS_Gtk2__CellRenderer_set_alignment); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_set_alignment)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "cell, xalign, yalign");
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
	gfloat	xalign = (float)SvNV(ST(1))
;
	gfloat	yalign = (float)SvNV(ST(2))
;

	gtk_cell_renderer_set_alignment(cell, xalign, yalign);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__CellRenderer_get_padding); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_get_padding)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "cell");
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
	gint	xpad;
	gint	ypad;

	gtk_cell_renderer_get_padding(cell, &xpad, &ypad);
	XSprePUSH;	EXTEND(SP,2);
	PUSHs(sv_newmortal());
	sv_setiv(ST(0), (IV)xpad);
	PUSHs(sv_newmortal());
	sv_setiv(ST(1), (IV)ypad);
    }
    XSRETURN(2);
}


XS_EUPXS(XS_Gtk2__CellRenderer_set_padding); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_set_padding)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "cell, xpad, ypad");
    {
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
	gint	xpad = (gint)SvIV(ST(1))
;
	gint	ypad = (gint)SvIV(ST(2))
;

	gtk_cell_renderer_set_padding(cell, xpad, ypad);
    }
    XSRETURN_EMPTY;
}

#endif /* 2.18 */

XS_EUPXS(XS_Gtk2__CellRenderer__INSTALL_OVERRIDES); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer__INSTALL_OVERRIDES)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 1)
       croak_xs_usage(cv,  "package");
    {
#line 668 "xs\\\\GtkCellRenderer.xs"
	GType gtype;
	GtkCellRendererClass * class;
#line 891 "xs\\GtkCellRenderer.c"
	const char *	package = (const char *)SvPV_nolen(ST(0))
;
#line 671 "xs\\\\GtkCellRenderer.xs"
	PERL_UNUSED_VAR (ix);
	gtype = gperl_object_type_from_package (package);
	if (!gtype)
		croak ("package '%s' is not registered with Gtk2-Perl",
		       package);
	if (! g_type_is_a (gtype, GTK_TYPE_CELL_RENDERER))
		croak ("%s(%s) is not a GtkCellRenderer",
		       package, g_type_name (gtype));
	/* peek should suffice, as the bindings should keep this class
	 * alive for us. */
	class = g_type_class_peek (gtype);
	if (! class)
		croak ("internal problem: can't peek at type class for %s(%d)",
		       g_type_name (gtype), gtype);
	gtk2perl_cell_renderer_class_init (class);
#line 910 "xs\\GtkCellRenderer.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__CellRenderer_GET_SIZE); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__CellRenderer_GET_SIZE)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items < 1)
       croak_xs_usage(cv,  "cell, ...");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 734 "xs\\\\GtkCellRenderer.xs"
	GtkCellRendererClass *parent_class = NULL;
	GType this, parent;
#line 929 "xs\\GtkCellRenderer.c"
	GtkCellRenderer *	cell = SvGtkCellRenderer (ST(0))
;
#line 737 "xs\\\\GtkCellRenderer.xs"
	/* look up the parent.
	 *
	 * FIXME: this approach runs into an endless loop with a hierarchy
	 * where a Perl class inherits from a C class which inherits from a
	 * Perl class.  Like this:
	 *
	 *   ...
	 *   +- GtkCellRenderer
	 *      +- Foo::RendererOne		(Perl subclass)
	 *         +- FooRendererTwo		(C subclass)
	 *            +- Foo::RendererThree	(Perl subclass)
	 *
	 * yes, this is contrived.  but possible!
	 */
	this = G_OBJECT_TYPE (cell);
	while ((parent = g_type_parent (this))) {
		if (! g_type_is_a (parent, GTK_TYPE_CELL_RENDERER))
			croak ("parent of %s is not a GtkCellRenderer",
			       g_type_name (this));

		parent_class = g_type_class_peek (parent);

		/* check if this class isn't actually one of ours.  if it is a
		 * Perl class, then we must not chain up to it: if it had a sub
		 * defined for the current vfunc, we wouldn't be in this
		 * fallback one here since perl's method resolution machinery
		 * would have found and called the sub.  so chaining up would
		 * result in the fallback being called again.  this will lead
		 * to an endless loop.
		 *
		 * so, if it's not a Perl class, we're done.  if it is,
		 * continue in the while loop to the next parent. */
		if (parent_class->get_size != gtk2perl_cell_renderer_get_size) {
			break;
		}

		this = parent;
	}

	/* the ancestry will always contain GtkCellRenderer, so parent and
	 * parent_class should never be NULL. */
	assert (parent != 0 && parent_class != NULL);

	switch (ix) {
	    case 4: /* deprecated parent_get_size */
	    case 0: /* GET_SIZE */
		if (parent_class->get_size) {
			gint x_offset, y_offset, width, height;
			parent_class->get_size (cell,
						SvGtkWidget (ST (1)),
						SvGdkRectangle_ornull (ST (2)),
						&x_offset,
						&y_offset,
						&width,
						&height);
			EXTEND (SP, 4);
			PUSHs (sv_2mortal (newSViv (x_offset)));
			PUSHs (sv_2mortal (newSViv (y_offset)));
			PUSHs (sv_2mortal (newSViv (width)));
			PUSHs (sv_2mortal (newSViv (height)));
		}
		break;
	    case 5: /* deprecated parent_render */
	    case 1: /* RENDER */
		if (parent_class->render)
			parent_class->render (cell,
					      SvGdkDrawable_ornull (ST (1)), /* drawable */
					      SvGtkWidget_ornull (ST (2)), /* widget */
					      SvGdkRectangle_ornull (ST (3)), /* background_area */
					      SvGdkRectangle_ornull (ST (4)), /* cell_area */
					      SvGdkRectangle_ornull (ST (5)), /* expose_area */
					      SvGtkCellRendererState (ST (6))); /* flags */
		break;
	    case 6: /* deprecated parent_activate */
	    case 2: /* ACTIVATE */
		if (parent_class->activate) {
			gboolean ret;
			ret = parent_class->activate (cell,
						      SvGdkEvent (ST (1)),
						      SvGtkWidget (ST (2)),
						      SvGChar (ST (3)),
						      SvGdkRectangle_ornull (ST (4)),
						      SvGdkRectangle_ornull (ST (5)),
						      SvGtkCellRendererState (ST (6)));
			EXTEND (SP, 1);
			PUSHs (sv_2mortal (newSViv (ret)));
		}
		break;
	    case 7: /* deprecated parent_start_editing */
	    case 3: /* START_EDITING */
		if (parent_class->start_editing) {
			GtkCellEditable * editable;
			editable = parent_class->start_editing (cell,
								SvGdkEvent_ornull (ST (1)),
								SvGtkWidget (ST (2)),
								SvGChar (ST (3)),
								SvGdkRectangle_ornull (ST (4)),
								SvGdkRectangle_ornull (ST (5)),
								SvGtkCellRendererState (ST (6)));
			EXTEND (SP, 1);
			/* Note newSVGtkWidget here instead of
			 * newSVGtkCellEditable so as to take ownership of
			 * any floating ref.  See comments with
			 * gtk_cell_renderer_start_editing() above.
			 */
			PUSHs (sv_2mortal (newSVGtkWidget_ornull (GTK_WIDGET (editable))));
		}
		break;
	    default:
		g_assert_not_reached ();
	}
#line 1044 "xs\\GtkCellRenderer.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__CellRenderer); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__CellRenderer)
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

        newXS("Gtk2::CellRenderer::set_fixed_size", XS_Gtk2__CellRenderer_set_fixed_size, file);
        newXS("Gtk2::CellRenderer::get_fixed_size", XS_Gtk2__CellRenderer_get_fixed_size, file);
        newXS("Gtk2::CellRenderer::get_size", XS_Gtk2__CellRenderer_get_size, file);
        newXS("Gtk2::CellRenderer::render", XS_Gtk2__CellRenderer_render, file);
        newXS("Gtk2::CellRenderer::activate", XS_Gtk2__CellRenderer_activate, file);
        newXS("Gtk2::CellRenderer::start_editing", XS_Gtk2__CellRenderer_start_editing, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::CellRenderer::editing_canceled", XS_Gtk2__CellRenderer_editing_canceled, file);
#endif
#if XSubPPtmpAAAB
        newXS("Gtk2::CellRenderer::stop_editing", XS_Gtk2__CellRenderer_stop_editing, file);
#endif
#if XSubPPtmpAAAC
        newXS("Gtk2::CellRenderer::get_visible", XS_Gtk2__CellRenderer_get_visible, file);
        newXS("Gtk2::CellRenderer::set_visible", XS_Gtk2__CellRenderer_set_visible, file);
        newXS("Gtk2::CellRenderer::get_sensitive", XS_Gtk2__CellRenderer_get_sensitive, file);
        newXS("Gtk2::CellRenderer::set_sensitive", XS_Gtk2__CellRenderer_set_sensitive, file);
        newXS("Gtk2::CellRenderer::get_alignment", XS_Gtk2__CellRenderer_get_alignment, file);
        newXS("Gtk2::CellRenderer::set_alignment", XS_Gtk2__CellRenderer_set_alignment, file);
        newXS("Gtk2::CellRenderer::get_padding", XS_Gtk2__CellRenderer_get_padding, file);
        newXS("Gtk2::CellRenderer::set_padding", XS_Gtk2__CellRenderer_set_padding, file);
#endif
        cv = newXS("Gtk2::CellRenderer::_INSTALL_OVERRIDES", XS_Gtk2__CellRenderer__INSTALL_OVERRIDES, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::CellRenderer::_install_overrides", XS_Gtk2__CellRenderer__INSTALL_OVERRIDES, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::CellRenderer::parent_get_size", XS_Gtk2__CellRenderer_GET_SIZE, file);
        XSANY.any_i32 = 4;
        cv = newXS("Gtk2::CellRenderer::parent_start_editing", XS_Gtk2__CellRenderer_GET_SIZE, file);
        XSANY.any_i32 = 7;
        cv = newXS("Gtk2::CellRenderer::RENDER", XS_Gtk2__CellRenderer_GET_SIZE, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::CellRenderer::parent_render", XS_Gtk2__CellRenderer_GET_SIZE, file);
        XSANY.any_i32 = 5;
        cv = newXS("Gtk2::CellRenderer::ACTIVATE", XS_Gtk2__CellRenderer_GET_SIZE, file);
        XSANY.any_i32 = 2;
        cv = newXS("Gtk2::CellRenderer::GET_SIZE", XS_Gtk2__CellRenderer_GET_SIZE, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::CellRenderer::parent_activate", XS_Gtk2__CellRenderer_GET_SIZE, file);
        XSANY.any_i32 = 6;
        cv = newXS("Gtk2::CellRenderer::START_EDITING", XS_Gtk2__CellRenderer_GET_SIZE, file);
        XSANY.any_i32 = 3;
    }

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#if XSubPPtmpAAAB
#endif
#if XSubPPtmpAAAC
#endif
#line 1125 "xs\\GtkCellRenderer.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

