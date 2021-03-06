/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkNotebook.xs. Do not edit this file, edit GtkNotebook.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkNotebook.xs"
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

static GtkWidget *
ensure_label_widget (SV * sv)
{
	if (!gperl_sv_is_defined (sv))
		return NULL;
	if (sv_derived_from (sv, "Gtk2::Widget"))
		return SvGtkWidget (sv);
	/* assume it's a string, and automagickally wrap a label around it */
	return gtk_label_new (SvPV_nolen (sv));
}

#if !GTK_CHECK_VERSION(2,4,0)
static int
notebook_return_value_spoof_helper (GtkNotebook * notebook,
				    int position)
{
	/* Adapted from gtk+ 2.6.2's gtk_notebook_insert_page_menu().
	 * They calculate the new position before doing the actual
	 * insertion, so call this *before* calling the function whose
	 * return value it spoofs.  Dirty, dirty, dirty. */
	int nchildren = g_list_length (notebook->children);
	if ((position < 0) || (position > nchildren))
		position = nchildren;
	return position;
}
#endif

#if GTK_CHECK_VERSION (2, 10, 0)

static GPerlCallback *
gtk2perl_notebook_window_creation_func_create (SV * func,
                                               SV * data)
{
        GType param_types[4];
        param_types[0] = GTK_TYPE_NOTEBOOK;
        param_types[1] = GTK_TYPE_WIDGET;
        param_types[2] = G_TYPE_INT;
        param_types[3] = G_TYPE_INT;
        return gperl_callback_new (func, data, G_N_ELEMENTS (param_types),
                                   param_types, GTK_TYPE_NOTEBOOK);
}

static GtkNotebook *
gtk2perl_notebook_window_creation_func (GtkNotebook *source,
                                        GtkWidget   *page,
                                        gint         x,
                                        gint         y,
                                        gpointer     data)
{
        GtkNotebook * retval;
        GValue value = {0, };
        g_value_init (&value, GTK_TYPE_NOTEBOOK);
        gperl_callback_invoke ((GPerlCallback*) data, &value, source, page, x, y);
        retval = g_value_get_object (&value);
        g_value_unset (&value);
        return retval;
}

#endif /* 2.10 */

#line 94 "xs\\GtkNotebook.c"
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

#line 236 "xs\\GtkNotebook.c"

XS_EUPXS(XS_Gtk2__Notebook_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	GtkWidget *	RETVAL;

	RETVAL = gtk_notebook_new(/*void*/);
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_append_page); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_append_page)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "notebook, child, tab_label=NULL");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	SV *	tab_label;
	gint	RETVAL;
	dXSTARG;

	if (items < 3)
	    tab_label = NULL;
	else {
	    tab_label = ST(2)
;
	}
#line 114 "xs\\\\GtkNotebook.xs"
	RETVAL =
#if !GTK_CHECK_VERSION(2,4,0)
		notebook_return_value_spoof_helper (notebook, -1);
#endif
		gtk_notebook_append_page (notebook, child,
					  ensure_label_widget (tab_label));
#line 283 "xs\\GtkNotebook.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_append_page_menu); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_append_page_menu)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "notebook, child, tab_label, menu_label");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	GtkWidget_ornull *	tab_label = SvGtkWidget_ornull (ST(2))
;
	GtkWidget_ornull *	menu_label = SvGtkWidget_ornull (ST(3))
;
	gint	RETVAL;
	dXSTARG;
#line 134 "xs\\\\GtkNotebook.xs"
	RETVAL =
#if !GTK_CHECK_VERSION(2,4,0)
		notebook_return_value_spoof_helper (notebook, -1);
#endif
		gtk_notebook_append_page_menu (notebook, child,
					       tab_label, menu_label);
#line 314 "xs\\GtkNotebook.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_prepend_page); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_prepend_page)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "notebook, child, tab_label=NULL");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	SV *	tab_label;
	gint	RETVAL;
	dXSTARG;

	if (items < 3)
	    tab_label = NULL;
	else {
	    tab_label = ST(2)
;
	}
#line 153 "xs\\\\GtkNotebook.xs"
	RETVAL =
#if !GTK_CHECK_VERSION(2,4,0)
		notebook_return_value_spoof_helper (notebook, 0);
#endif
		gtk_notebook_prepend_page (notebook, child,
					   ensure_label_widget (tab_label));
#line 349 "xs\\GtkNotebook.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_prepend_page_menu); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_prepend_page_menu)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "notebook, child, tab_label, menu_label");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	GtkWidget_ornull *	tab_label = SvGtkWidget_ornull (ST(2))
;
	GtkWidget_ornull *	menu_label = SvGtkWidget_ornull (ST(3))
;
	gint	RETVAL;
	dXSTARG;
#line 173 "xs\\\\GtkNotebook.xs"
	RETVAL =
#if !GTK_CHECK_VERSION(2,4,0)
		notebook_return_value_spoof_helper (notebook, 0);
#endif
		gtk_notebook_prepend_page_menu (notebook, child,
						tab_label, menu_label);
#line 380 "xs\\GtkNotebook.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_insert_page); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_insert_page)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "notebook, child, tab_label, position");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	SV *	tab_label = ST(2)
;
	gint	position = (gint)SvIV(ST(3))
;
	gint	RETVAL;
	dXSTARG;
#line 193 "xs\\\\GtkNotebook.xs"
	RETVAL =
#if !GTK_CHECK_VERSION(2,4,0)
		notebook_return_value_spoof_helper (notebook, position);
#endif
		gtk_notebook_insert_page (notebook, child,
					  ensure_label_widget (tab_label),
					  position);
#line 412 "xs\\GtkNotebook.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_insert_page_menu); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_insert_page_menu)
{
    dVAR; dXSARGS;
    if (items != 5)
       croak_xs_usage(cv,  "notebook, child, tab_label, menu_label, position");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	GtkWidget_ornull *	tab_label = SvGtkWidget_ornull (ST(2))
;
	GtkWidget_ornull *	menu_label = SvGtkWidget_ornull (ST(3))
;
	gint	position = (gint)SvIV(ST(4))
;
	gint	RETVAL;
	dXSTARG;
#line 215 "xs\\\\GtkNotebook.xs"
	RETVAL =
#if !GTK_CHECK_VERSION(2,4,0)
		notebook_return_value_spoof_helper (notebook, position);
#endif
		gtk_notebook_insert_page_menu (notebook, child, tab_label,
					       menu_label, position);
#line 445 "xs\\GtkNotebook.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_remove_page); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_remove_page)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, page_num");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	gint	page_num = (gint)SvIV(ST(1))
;

	gtk_notebook_remove_page(notebook, page_num);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_get_nth_page); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_nth_page)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, page_num");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	gint	page_num = (gint)SvIV(ST(1))
;
	GtkWidget_ornull *	RETVAL;

	RETVAL = gtk_notebook_get_nth_page(notebook, page_num);
	ST(0) = newSVGtkWidget_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_page_num); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_page_num)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, child");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	gint	RETVAL;
	dXSTARG;

	RETVAL = gtk_notebook_page_num(notebook, child);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_set_current_page); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_current_page)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, page_num");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	gint	page_num = (gint)SvIV(ST(1))
;

	gtk_notebook_set_current_page(notebook, page_num);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_next_page); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_next_page)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "notebook");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;

	gtk_notebook_next_page(notebook);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_prev_page); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_prev_page)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "notebook");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;

	gtk_notebook_prev_page(notebook);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_get_show_border); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_show_border)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "notebook");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	gboolean	RETVAL;

	RETVAL = gtk_notebook_get_show_border(notebook);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_set_show_tabs); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_show_tabs)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, show_tabs");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	gboolean	show_tabs = (bool)SvTRUE(ST(1))
;

	gtk_notebook_set_show_tabs(notebook, show_tabs);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_get_show_tabs); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_show_tabs)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "notebook");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	gboolean	RETVAL;

	RETVAL = gtk_notebook_get_show_tabs(notebook);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_set_tab_pos); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_tab_pos)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, pos");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkPositionType	pos = SvGtkPositionType (ST(1))
;

	gtk_notebook_set_tab_pos(notebook, pos);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_get_tab_pos); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_tab_pos)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "notebook");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkPositionType	RETVAL;

	RETVAL = gtk_notebook_get_tab_pos(notebook);
	ST(0) = newSVGtkPositionType (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_set_tab_border); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_tab_border)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, border_width");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	guint	border_width = (guint)SvUV(ST(1))
;

	gtk_notebook_set_tab_border(notebook, border_width);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_set_tab_hborder); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_tab_hborder)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, tab_hborder");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	guint	tab_hborder = (guint)SvUV(ST(1))
;

	gtk_notebook_set_tab_hborder(notebook, tab_hborder);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_set_tab_vborder); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_tab_vborder)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, tab_vborder");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	guint	tab_vborder = (guint)SvUV(ST(1))
;

	gtk_notebook_set_tab_vborder(notebook, tab_vborder);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_set_scrollable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_scrollable)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, scrollable");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	gboolean	scrollable = (bool)SvTRUE(ST(1))
;

	gtk_notebook_set_scrollable(notebook, scrollable);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_get_scrollable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_scrollable)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "notebook");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	gboolean	RETVAL;

	RETVAL = gtk_notebook_get_scrollable(notebook);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_popup_disable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_popup_disable)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "notebook");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;

	gtk_notebook_popup_disable(notebook);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_set_tab_label); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_tab_label)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "notebook, child, tab_label=NULL");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	GtkWidget_ornull *	tab_label;

	if (items < 3)
	    tab_label = NULL;
	else {
	    tab_label = SvGtkWidget_ornull (ST(2))
;
	}

	gtk_notebook_set_tab_label(notebook, child, tab_label);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_set_tab_label_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_tab_label_text)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "notebook, child, tab_text");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	const gchar *	tab_text;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(2));
	tab_text = (const gchar *)SvPV_nolen (ST(2))
;

	gtk_notebook_set_tab_label_text(notebook, child, tab_text);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_get_menu_label); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_menu_label)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, child");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	GtkWidget_ornull *	RETVAL;

	RETVAL = gtk_notebook_get_menu_label(notebook, child);
	ST(0) = newSVGtkWidget_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_set_menu_label); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_menu_label)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "notebook, child, menu_label=NULL");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	GtkWidget_ornull *	menu_label;

	if (items < 3)
	    menu_label = NULL;
	else {
	    menu_label = SvGtkWidget_ornull (ST(2))
;
	}

	gtk_notebook_set_menu_label(notebook, child, menu_label);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_set_menu_label_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_menu_label_text)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "notebook, child, menu_text");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	const gchar *	menu_text;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(2));
	menu_text = (const gchar *)SvPV_nolen (ST(2))
;

	gtk_notebook_set_menu_label_text(notebook, child, menu_text);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_query_tab_label_packing); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_query_tab_label_packing)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, child");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 358 "xs\\\\GtkNotebook.xs"
	gboolean expand;
	gboolean fill;
	GtkPackType pack_type;
#line 896 "xs\\GtkNotebook.c"
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
#line 362 "xs\\\\GtkNotebook.xs"
	gtk_notebook_query_tab_label_packing (notebook, child, &expand, &fill, &pack_type);
	EXTEND (SP, 3);
	PUSHs (sv_2mortal (boolSV (expand)));
	PUSHs (sv_2mortal (boolSV (fill)));
	PUSHs (sv_2mortal (newSVGtkPackType (pack_type)));
#line 907 "xs\\GtkNotebook.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__Notebook_set_tab_label_packing); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_tab_label_packing)
{
    dVAR; dXSARGS;
    if (items != 5)
       croak_xs_usage(cv,  "notebook, child, expand, fill, pack_type");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	gboolean	expand = (bool)SvTRUE(ST(2))
;
	gboolean	fill = (bool)SvTRUE(ST(3))
;
	GtkPackType	pack_type = SvGtkPackType (ST(4))
;

	gtk_notebook_set_tab_label_packing(notebook, child, expand, fill, pack_type);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_reorder_child); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_reorder_child)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "notebook, child, position");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	gint	position = (gint)SvIV(ST(2))
;

	gtk_notebook_reorder_child(notebook, child, position);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_get_current_page); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_current_page)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "notebook");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	gint	RETVAL;
	dXSTARG;

	RETVAL = gtk_notebook_get_current_page(notebook);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_set_show_border); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_show_border)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, show_border");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	gboolean	show_border = (bool)SvTRUE(ST(1))
;

	gtk_notebook_set_show_border(notebook, show_border);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_popup_enable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_popup_enable)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "notebook");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;

	gtk_notebook_popup_enable(notebook);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_get_tab_label); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_tab_label)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, child");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	GtkWidget *	RETVAL;

	RETVAL = gtk_notebook_get_tab_label(notebook, child);
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_get_n_pages); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_n_pages)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "notebook");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	gint	RETVAL;
	dXSTARG;
#line 413 "xs\\\\GtkNotebook.xs"
#if GTK_CHECK_VERSION(2,2,0)
	RETVAL = gtk_notebook_get_n_pages (notebook);
#else
	/* this wasn't defined before 2.2.0...  but it's really handy and
	 * easy to implement, like so: */
	RETVAL = g_list_length (notebook->children);
#endif
#line 1051 "xs\\GtkNotebook.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_get_menu_label_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_menu_label_text)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, child");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	const gchar *	RETVAL;

	RETVAL = gtk_notebook_get_menu_label_text(notebook, child);
	ST(0) = sv_newmortal();
	/* same as newSVGChar(), but not in a function */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_get_tab_label_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_tab_label_text)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, child");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	const gchar *	RETVAL;

	RETVAL = gtk_notebook_get_tab_label_text(notebook, child);
	ST(0) = sv_newmortal();
	/* same as newSVGChar(), but not in a function */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
    }
    XSRETURN(1);
}

#if GTK_CHECK_VERSION (2, 10, 0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__Notebook_set_window_creation_hook); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_window_creation_hook)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "class, func, data=NULL");
    {
#line 439 "xs\\\\GtkNotebook.xs"
	GPerlCallback * callback;
#line 1116 "xs\\GtkNotebook.c"
	SV *	func = ST(1)
;
	SV *	data;

	if (items < 3)
	    data = NULL;
	else {
	    data = ST(2)
;
	}
#line 441 "xs\\\\GtkNotebook.xs"
	callback = gtk2perl_notebook_window_creation_func_create (func, data);
	gtk_notebook_set_window_creation_hook
		(gtk2perl_notebook_window_creation_func, callback,
		 (GDestroyNotify) gperl_callback_destroy);
#line 1132 "xs\\GtkNotebook.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_set_group_id); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_group_id)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, group_id");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	gint	group_id = (gint)SvIV(ST(1))
;

	gtk_notebook_set_group_id(notebook, group_id);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_get_group_id); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_group_id)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "notebook");
    {
	gint	RETVAL;
	dXSTARG;
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;

	RETVAL = gtk_notebook_get_group_id(notebook);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_set_tab_reorderable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_tab_reorderable)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "notebook, child, reorderable");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	gboolean	reorderable = (bool)SvTRUE(ST(2))
;

	gtk_notebook_set_tab_reorderable(notebook, child, reorderable);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_get_tab_reorderable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_tab_reorderable)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, child");
    {
	gboolean	RETVAL;
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;

	RETVAL = gtk_notebook_get_tab_reorderable(notebook, child);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_set_tab_detachable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_tab_detachable)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "notebook, child, detachable");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	gboolean	detachable = (bool)SvTRUE(ST(2))
;

	gtk_notebook_set_tab_detachable(notebook, child, detachable);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_get_tab_detachable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_tab_detachable)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, child");
    {
	gboolean	RETVAL;
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;

	RETVAL = gtk_notebook_get_tab_detachable(notebook, child);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif /* 2.10 */
#if GTK_CHECK_VERSION (2, 20, 0)
#define XSubPPtmpAAAB 1


XS_EUPXS(XS_Gtk2__Notebook_set_action_widget); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_set_action_widget)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "notebook, widget, pack_type");
    {
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkWidget *	widget = SvGtkWidget (ST(1))
;
	GtkPackType	pack_type = SvGtkPackType (ST(2))
;

	gtk_notebook_set_action_widget(notebook, widget, pack_type);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Notebook_get_action_widget); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_action_widget)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "notebook, pack_type");
    {
	GtkWidget_ornull *	RETVAL;
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;
	GtkPackType	pack_type = SvGtkPackType (ST(1))
;

	RETVAL = gtk_notebook_get_action_widget(notebook, pack_type);
	ST(0) = newSVGtkWidget_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif /* 2.20 */
#if GTK_CHECK_VERSION (2, 22, 0)
#define XSubPPtmpAAAC 1


XS_EUPXS(XS_Gtk2__Notebook_get_tab_hborder); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_tab_hborder)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "notebook");
    {
	guint16	RETVAL;
	dXSTARG;
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;

	RETVAL = gtk_notebook_get_tab_hborder(notebook);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Notebook_get_tab_vborder); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Notebook_get_tab_vborder)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "notebook");
    {
	guint16	RETVAL;
	dXSTARG;
	GtkNotebook *	notebook = SvGtkNotebook (ST(0))
;

	RETVAL = gtk_notebook_get_tab_vborder(notebook);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

#endif /* 2.22 */
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__Notebook); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__Notebook)
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

        newXS("Gtk2::Notebook::new", XS_Gtk2__Notebook_new, file);
        newXS("Gtk2::Notebook::append_page", XS_Gtk2__Notebook_append_page, file);
        newXS("Gtk2::Notebook::append_page_menu", XS_Gtk2__Notebook_append_page_menu, file);
        newXS("Gtk2::Notebook::prepend_page", XS_Gtk2__Notebook_prepend_page, file);
        newXS("Gtk2::Notebook::prepend_page_menu", XS_Gtk2__Notebook_prepend_page_menu, file);
        newXS("Gtk2::Notebook::insert_page", XS_Gtk2__Notebook_insert_page, file);
        newXS("Gtk2::Notebook::insert_page_menu", XS_Gtk2__Notebook_insert_page_menu, file);
        newXS("Gtk2::Notebook::remove_page", XS_Gtk2__Notebook_remove_page, file);
        newXS("Gtk2::Notebook::get_nth_page", XS_Gtk2__Notebook_get_nth_page, file);
        newXS("Gtk2::Notebook::page_num", XS_Gtk2__Notebook_page_num, file);
        newXS("Gtk2::Notebook::set_current_page", XS_Gtk2__Notebook_set_current_page, file);
        newXS("Gtk2::Notebook::next_page", XS_Gtk2__Notebook_next_page, file);
        newXS("Gtk2::Notebook::prev_page", XS_Gtk2__Notebook_prev_page, file);
        newXS("Gtk2::Notebook::get_show_border", XS_Gtk2__Notebook_get_show_border, file);
        newXS("Gtk2::Notebook::set_show_tabs", XS_Gtk2__Notebook_set_show_tabs, file);
        newXS("Gtk2::Notebook::get_show_tabs", XS_Gtk2__Notebook_get_show_tabs, file);
        newXS("Gtk2::Notebook::set_tab_pos", XS_Gtk2__Notebook_set_tab_pos, file);
        newXS("Gtk2::Notebook::get_tab_pos", XS_Gtk2__Notebook_get_tab_pos, file);
        newXS("Gtk2::Notebook::set_tab_border", XS_Gtk2__Notebook_set_tab_border, file);
        newXS("Gtk2::Notebook::set_tab_hborder", XS_Gtk2__Notebook_set_tab_hborder, file);
        newXS("Gtk2::Notebook::set_tab_vborder", XS_Gtk2__Notebook_set_tab_vborder, file);
        newXS("Gtk2::Notebook::set_scrollable", XS_Gtk2__Notebook_set_scrollable, file);
        newXS("Gtk2::Notebook::get_scrollable", XS_Gtk2__Notebook_get_scrollable, file);
        newXS("Gtk2::Notebook::popup_disable", XS_Gtk2__Notebook_popup_disable, file);
        newXS("Gtk2::Notebook::set_tab_label", XS_Gtk2__Notebook_set_tab_label, file);
        newXS("Gtk2::Notebook::set_tab_label_text", XS_Gtk2__Notebook_set_tab_label_text, file);
        newXS("Gtk2::Notebook::get_menu_label", XS_Gtk2__Notebook_get_menu_label, file);
        newXS("Gtk2::Notebook::set_menu_label", XS_Gtk2__Notebook_set_menu_label, file);
        newXS("Gtk2::Notebook::set_menu_label_text", XS_Gtk2__Notebook_set_menu_label_text, file);
        newXS("Gtk2::Notebook::query_tab_label_packing", XS_Gtk2__Notebook_query_tab_label_packing, file);
        newXS("Gtk2::Notebook::set_tab_label_packing", XS_Gtk2__Notebook_set_tab_label_packing, file);
        newXS("Gtk2::Notebook::reorder_child", XS_Gtk2__Notebook_reorder_child, file);
        newXS("Gtk2::Notebook::get_current_page", XS_Gtk2__Notebook_get_current_page, file);
        newXS("Gtk2::Notebook::set_show_border", XS_Gtk2__Notebook_set_show_border, file);
        newXS("Gtk2::Notebook::popup_enable", XS_Gtk2__Notebook_popup_enable, file);
        newXS("Gtk2::Notebook::get_tab_label", XS_Gtk2__Notebook_get_tab_label, file);
        newXS("Gtk2::Notebook::get_n_pages", XS_Gtk2__Notebook_get_n_pages, file);
        newXS("Gtk2::Notebook::get_menu_label_text", XS_Gtk2__Notebook_get_menu_label_text, file);
        newXS("Gtk2::Notebook::get_tab_label_text", XS_Gtk2__Notebook_get_tab_label_text, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::Notebook::set_window_creation_hook", XS_Gtk2__Notebook_set_window_creation_hook, file);
        newXS("Gtk2::Notebook::set_group_id", XS_Gtk2__Notebook_set_group_id, file);
        newXS("Gtk2::Notebook::get_group_id", XS_Gtk2__Notebook_get_group_id, file);
        newXS("Gtk2::Notebook::set_tab_reorderable", XS_Gtk2__Notebook_set_tab_reorderable, file);
        newXS("Gtk2::Notebook::get_tab_reorderable", XS_Gtk2__Notebook_get_tab_reorderable, file);
        newXS("Gtk2::Notebook::set_tab_detachable", XS_Gtk2__Notebook_set_tab_detachable, file);
        newXS("Gtk2::Notebook::get_tab_detachable", XS_Gtk2__Notebook_get_tab_detachable, file);
#endif
#if XSubPPtmpAAAB
        newXS("Gtk2::Notebook::set_action_widget", XS_Gtk2__Notebook_set_action_widget, file);
        newXS("Gtk2::Notebook::get_action_widget", XS_Gtk2__Notebook_get_action_widget, file);
#endif
#if XSubPPtmpAAAC
        newXS("Gtk2::Notebook::get_tab_hborder", XS_Gtk2__Notebook_get_tab_hborder, file);
        newXS("Gtk2::Notebook::get_tab_vborder", XS_Gtk2__Notebook_get_tab_vborder, file);
#endif

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#if XSubPPtmpAAAB
#endif
#if XSubPPtmpAAAC
#endif
#line 1429 "xs\\GtkNotebook.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

