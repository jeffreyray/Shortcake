/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkTreeSelection.xs. Do not edit this file, edit GtkTreeSelection.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkTreeSelection.xs"
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

/* descended directly from GObject */

static GPerlCallback *
gtk2perl_tree_selection_func_create (SV * func, SV * data)
{
	GType param_types [4];
	param_types[0] = GTK_TYPE_TREE_SELECTION;
	param_types[1] = GTK_TYPE_TREE_MODEL;
	param_types[2] = GTK_TYPE_TREE_PATH;
	param_types[3] = G_TYPE_BOOLEAN;
	return gperl_callback_new (func, data, G_N_ELEMENTS (param_types),
				   param_types, G_TYPE_BOOLEAN);
}

static gboolean
gtk2perl_tree_selection_func (GtkTreeSelection * selection,
			      GtkTreeModel * model,
			      GtkTreePath * path,
			      gboolean path_currently_selected,
			      gpointer data)
{
	GPerlCallback * callback = (GPerlCallback*)data;
	GValue value = {0,};
	gboolean retval;

	g_value_init (&value, callback->return_type);
	gperl_callback_invoke (callback, &value, selection, model, path,
			       path_currently_selected);
	retval = g_value_get_boolean (&value);
	g_value_unset (&value);

	return retval;
}


static GPerlCallback *
gtk2perl_tree_selection_foreach_func_create (SV * func, SV * data)
{
	GType param_types [3];
	param_types[0] = GTK_TYPE_TREE_MODEL;
	param_types[1] = GTK_TYPE_TREE_PATH;
	param_types[2] = GTK_TYPE_TREE_ITER;
	return gperl_callback_new (func, data, G_N_ELEMENTS (param_types),
				   param_types, 0);
}

static void
gtk2perl_tree_selection_foreach_func (GtkTreeModel * model,
				      GtkTreePath * path,
				      GtkTreeIter * iter,
				      gpointer data)
{
	gperl_callback_invoke ((GPerlCallback*)data, NULL, model, path, iter);
}

#if !GTK_CHECK_VERSION(2,2,0)
/* selected_foreach callbacks to implement get_selected_rows and 
 * count_selected_rows for gtk < 2.2 */
static void
get_selected_rows (GtkTreeModel * model,
                   GtkTreePath * path,
                   GtkTreeIter * iter,
                   GList ** paths)
{
	*paths = g_list_append (*paths, gtk_tree_path_copy (path));
}

static void
count_selected_rows (GtkTreeModel * model,
                     GtkTreePath * path,
                     GtkTreeIter * iter,
                     gint * n)
{
	++*n;
}
#endif /* <2.2.0 */

#line 111 "xs\\GtkTreeSelection.c"
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

#line 253 "xs\\GtkTreeSelection.c"

XS_EUPXS(XS_Gtk2__TreeSelection_set_mode); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_set_mode)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "selection, type");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	GtkSelectionMode	type = SvGtkSelectionMode (ST(1))
;

	gtk_tree_selection_set_mode(selection, type);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TreeSelection_get_mode); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_get_mode)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	GtkSelectionMode	RETVAL;

	RETVAL = gtk_tree_selection_get_mode(selection);
	ST(0) = newSVGtkSelectionMode (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__TreeSelection_set_select_function); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_set_select_function)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "selection, func, data=NULL");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	SV *	func = ST(1)
;
	SV *	data;
#line 122 "xs\\\\GtkTreeSelection.xs"
	GPerlCallback * callback;
#line 306 "xs\\GtkTreeSelection.c"

	if (items < 3)
	    data = NULL;
	else {
	    data = ST(2)
;
	}
#line 124 "xs\\\\GtkTreeSelection.xs"
	callback = gtk2perl_tree_selection_func_create (func, data);
	gtk_tree_selection_set_select_function (selection,
						gtk2perl_tree_selection_func,
						callback,
						(GDestroyNotify) gperl_callback_destroy);
#line 320 "xs\\GtkTreeSelection.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TreeSelection_get_user_data); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_get_user_data)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
#line 135 "xs\\\\GtkTreeSelection.xs"
	GPerlCallback *callback = NULL;
#line 337 "xs\\GtkTreeSelection.c"
	SV *	RETVAL;
#line 137 "xs\\\\GtkTreeSelection.xs"
	callback = (GPerlCallback *) gtk_tree_selection_get_user_data (selection);
	RETVAL = callback && gperl_sv_is_defined (callback->data) ?
	           callback->data :
	           &PL_sv_undef;
#line 344 "xs\\GtkTreeSelection.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__TreeSelection_get_tree_view); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_get_tree_view)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	GtkTreeView *	RETVAL;

	RETVAL = gtk_tree_selection_get_tree_view(selection);
	ST(0) = newSVGtkTreeView (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__TreeSelection_get_selected); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_get_selected)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
#line 160 "xs\\\\GtkTreeSelection.xs"
	GtkTreeModel * model;
	GtkTreeIter iter = {0, };
#line 385 "xs\\GtkTreeSelection.c"
#line 163 "xs\\\\GtkTreeSelection.xs"
	if (!gtk_tree_selection_get_selected (selection, &model, &iter))
		XSRETURN_EMPTY;
	if (GIMME_V == G_ARRAY)
		XPUSHs (sv_2mortal (newSVGtkTreeModel (model)));
	XPUSHs (sv_2mortal (newSVGtkTreeIter_copy (&iter)));
#line 392 "xs\\GtkTreeSelection.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__TreeSelection_get_selected_rows); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_get_selected_rows)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
#line 185 "xs\\\\GtkTreeSelection.xs"
#if GTK_CHECK_VERSION(2,2,0)
	GtkTreeModel * model = NULL;
#else
	GtkTreeView * view;
#endif
	GList * paths = NULL, * i;
#line 417 "xs\\GtkTreeSelection.c"
#line 192 "xs\\\\GtkTreeSelection.xs"
#if GTK_CHECK_VERSION(2,2,0)
	paths = gtk_tree_selection_get_selected_rows (selection, &model);
#else
	view = gtk_tree_selection_get_tree_view (selection);
	gtk_tree_selection_selected_foreach (selection,
					     (GtkTreeSelectionForeachFunc)
					       get_selected_rows, &paths);
#endif
	EXTEND (SP, (int)g_list_length (paths));
	for (i = paths ; i != NULL ; i = i->next)
		PUSHs (sv_2mortal (newSVGtkTreePath_own ((GtkTreePath*)i->data)));
	g_list_free (paths);
#line 431 "xs\\GtkTreeSelection.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__TreeSelection_count_selected_rows); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_count_selected_rows)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	gint	RETVAL;
	dXSTARG;
#line 210 "xs\\\\GtkTreeSelection.xs"
#if GTK_CHECK_VERSION(2,2,0)
	RETVAL = gtk_tree_selection_count_selected_rows (selection);
#else
	RETVAL = 0;
	gtk_tree_selection_selected_foreach (selection, 
					     (GtkTreeSelectionForeachFunc)
					        count_selected_rows, &RETVAL);
#endif /* 2.2.0 */
#line 458 "xs\\GtkTreeSelection.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__TreeSelection_selected_foreach); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_selected_foreach)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "selection, func, data=NULL");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	SV *	func = ST(1)
;
	SV *	data;
#line 232 "xs\\\\GtkTreeSelection.xs"
	GPerlCallback * callback;
#line 479 "xs\\GtkTreeSelection.c"

	if (items < 3)
	    data = NULL;
	else {
	    data = ST(2)
;
	}
#line 234 "xs\\\\GtkTreeSelection.xs"
	callback = gtk2perl_tree_selection_foreach_func_create (func, data);
	gtk_tree_selection_selected_foreach (selection,
					     gtk2perl_tree_selection_foreach_func,
					     callback);
	gperl_callback_destroy (callback);
#line 493 "xs\\GtkTreeSelection.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TreeSelection_select_path); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_select_path)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "selection, path");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	GtkTreePath *	path = SvGtkTreePath (ST(1))
;

	gtk_tree_selection_select_path(selection, path);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TreeSelection_unselect_path); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_unselect_path)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "selection, path");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	GtkTreePath *	path = SvGtkTreePath (ST(1))
;

	gtk_tree_selection_unselect_path(selection, path);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TreeSelection_select_iter); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_select_iter)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "selection, iter");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	GtkTreeIter *	iter = SvGtkTreeIter (ST(1))
;

	gtk_tree_selection_select_iter(selection, iter);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TreeSelection_unselect_iter); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_unselect_iter)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "selection, iter");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	GtkTreeIter *	iter = SvGtkTreeIter (ST(1))
;

	gtk_tree_selection_unselect_iter(selection, iter);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TreeSelection_path_is_selected); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_path_is_selected)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "selection, path");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	GtkTreePath *	path = SvGtkTreePath (ST(1))
;
	gboolean	RETVAL;

	RETVAL = gtk_tree_selection_path_is_selected(selection, path);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__TreeSelection_iter_is_selected); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_iter_is_selected)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "selection, iter");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	GtkTreeIter *	iter = SvGtkTreeIter (ST(1))
;
	gboolean	RETVAL;

	RETVAL = gtk_tree_selection_iter_is_selected(selection, iter);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__TreeSelection_select_all); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_select_all)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;

	gtk_tree_selection_select_all(selection);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TreeSelection_unselect_all); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_unselect_all)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;

	gtk_tree_selection_unselect_all(selection);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TreeSelection_select_range); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_select_range)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "selection, start_path, end_path");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	GtkTreePath *	start_path = SvGtkTreePath (ST(1))
;
	GtkTreePath *	end_path = SvGtkTreePath (ST(2))
;

	gtk_tree_selection_select_range(selection, start_path, end_path);
    }
    XSRETURN_EMPTY;
}

#if GTK_CHECK_VERSION(2,2,0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__TreeSelection_unselect_range); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TreeSelection_unselect_range)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "selection, start_path, end_path");
    {
	GtkTreeSelection *	selection = SvGtkTreeSelection (ST(0))
;
	GtkTreePath *	start_path = SvGtkTreePath (ST(1))
;
	GtkTreePath *	end_path = SvGtkTreePath (ST(2))
;

	gtk_tree_selection_unselect_range(selection, start_path, end_path);
    }
    XSRETURN_EMPTY;
}

#endif /* >= 2.2.0 */
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__TreeSelection); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__TreeSelection)
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

        newXS("Gtk2::TreeSelection::set_mode", XS_Gtk2__TreeSelection_set_mode, file);
        newXS("Gtk2::TreeSelection::get_mode", XS_Gtk2__TreeSelection_get_mode, file);
        newXS("Gtk2::TreeSelection::set_select_function", XS_Gtk2__TreeSelection_set_select_function, file);
        newXS("Gtk2::TreeSelection::get_user_data", XS_Gtk2__TreeSelection_get_user_data, file);
        newXS("Gtk2::TreeSelection::get_tree_view", XS_Gtk2__TreeSelection_get_tree_view, file);
        newXS("Gtk2::TreeSelection::get_selected", XS_Gtk2__TreeSelection_get_selected, file);
        newXS("Gtk2::TreeSelection::get_selected_rows", XS_Gtk2__TreeSelection_get_selected_rows, file);
        newXS("Gtk2::TreeSelection::count_selected_rows", XS_Gtk2__TreeSelection_count_selected_rows, file);
        newXS("Gtk2::TreeSelection::selected_foreach", XS_Gtk2__TreeSelection_selected_foreach, file);
        newXS("Gtk2::TreeSelection::select_path", XS_Gtk2__TreeSelection_select_path, file);
        newXS("Gtk2::TreeSelection::unselect_path", XS_Gtk2__TreeSelection_unselect_path, file);
        newXS("Gtk2::TreeSelection::select_iter", XS_Gtk2__TreeSelection_select_iter, file);
        newXS("Gtk2::TreeSelection::unselect_iter", XS_Gtk2__TreeSelection_unselect_iter, file);
        newXS("Gtk2::TreeSelection::path_is_selected", XS_Gtk2__TreeSelection_path_is_selected, file);
        newXS("Gtk2::TreeSelection::iter_is_selected", XS_Gtk2__TreeSelection_iter_is_selected, file);
        newXS("Gtk2::TreeSelection::select_all", XS_Gtk2__TreeSelection_select_all, file);
        newXS("Gtk2::TreeSelection::unselect_all", XS_Gtk2__TreeSelection_unselect_all, file);
        newXS("Gtk2::TreeSelection::select_range", XS_Gtk2__TreeSelection_select_range, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::TreeSelection::unselect_range", XS_Gtk2__TreeSelection_unselect_range, file);
#endif

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#line 734 "xs\\GtkTreeSelection.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

