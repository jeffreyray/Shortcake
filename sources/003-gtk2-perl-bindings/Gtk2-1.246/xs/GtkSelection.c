/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkSelection.xs. Do not edit this file, edit GtkSelection.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkSelection.xs"
/*
 * Copyright (c) 2003-2006, 2009 by the gtk2-perl team (see the file AUTHORS)
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


#if !GTK_CHECK_VERSION (2, 16, 0)
#  define gtk_selection_data_get_selection(d) ((d)->selection)
#endif /* 2.16 */

#if !GTK_CHECK_VERSION (2, 14, 0)
#  define gtk_selection_data_get_target(d)    ((d)->target)
#  define gtk_selection_data_get_data_type(d) ((d)->type)
#  define gtk_selection_data_get_data(d)      ((d)->data)
#  define gtk_selection_data_get_format(d)    ((d)->format)
#  define gtk_selection_data_get_length(d)    ((d)->length)
#  define gtk_selection_data_get_display(d)   ((d)->display)
#endif /* 2.14 */


SV *
newSVGtkTargetEntry (GtkTargetEntry * e)
{
	HV * h;
	SV * r;

	if (!e)
		return &PL_sv_undef;

	h = newHV ();
	r = newRV_noinc ((SV*)h);

	gperl_hv_take_sv_s (h, "target", e->target ? newSVpv (e->target, 0) : newSVsv (&PL_sv_undef));
	gperl_hv_take_sv_s (h, "flags", newSVGtkTargetFlags (e->flags));
	gperl_hv_take_sv_s (h, "info", newSViv (e->info));

	return r;
}

GtkTargetEntry *
SvGtkTargetEntry (SV * sv)
{
	GtkTargetEntry * entry = gperl_alloc_temp (sizeof (GtkTargetEntry));
	gtk2perl_read_gtk_target_entry (sv, entry);
	return entry;
}

void
gtk2perl_read_gtk_target_entry (SV * sv,
                                GtkTargetEntry * e)
{
	HV * h;
	AV * a;
	SV ** s;
	STRLEN len;

	if (gperl_sv_is_hash_ref (sv)) {
		h = (HV*) SvRV (sv);
		if ((s=hv_fetch (h, "target", 6, 0)) && gperl_sv_is_defined (*s))
			e->target = SvPV (*s, len);
		if ((s=hv_fetch (h, "flags", 5, 0)) && gperl_sv_is_defined (*s))
			e->flags = SvGtkTargetFlags (*s);
		if ((s=hv_fetch (h, "info", 4, 0)) && gperl_sv_is_defined (*s))
			e->info = SvUV (*s);
	} else if (gperl_sv_is_array_ref (sv)) {
		a = (AV*)SvRV (sv);
		if ((s=av_fetch (a, 0, 0)) && gperl_sv_is_defined (*s))
			e->target = SvPV (*s, len);
		if ((s=av_fetch (a, 1, 0)) && gperl_sv_is_defined (*s))
			e->flags = SvGtkTargetFlags (*s);
		if ((s=av_fetch (a, 2, 0)) && gperl_sv_is_defined (*s))
			e->info = SvUV (*s);
	} else {
		croak ("a target entry must be a reference to a hash "
		       "containing the keys 'target', 'flags', and 'info', "
		       "or a reference to a three-element list containing "
		       "the information in the order target, flags, info");
	}
}

/* gtk+ 2.10 introduces a boxed type for GtkTargetList. */

#if GTK_CHECK_VERSION (2, 10, 0)

static GPerlBoxedWrapperClass *default_wrapper_class;
static GPerlBoxedWrapperClass gtk_target_list_wrapper_class;

static SV *
gtk_target_list_wrap (GType gtype,
                      const char *package,
                      gpointer boxed,
                      gboolean own)
{
	/* To keep compatibility with the old wrappers, we always assume
	 * ownership of the list. */
	PERL_UNUSED_VAR (own);
	gtk_target_list_ref ((GtkTargetList *) boxed);
	return default_wrapper_class->wrap (gtype, package, boxed, TRUE);
}

#endif /* 2.10 */

SV *
newSVGtkTargetList (GtkTargetList * list)
{
#if GTK_CHECK_VERSION (2, 9, 0)
	return gperl_new_boxed (list, GTK_TYPE_TARGET_LIST, TRUE);
#else
	gtk_target_list_ref (list);
	return sv_setref_pv (newSV (0), "Gtk2::TargetList", list);
#endif
}

GtkTargetList *
SvGtkTargetList (SV * sv)
{
#if GTK_CHECK_VERSION (2, 9, 0)
	return gperl_get_boxed_check (sv, GTK_TYPE_TARGET_LIST);
#else
	if (!gperl_sv_is_defined (sv) || !SvROK (sv) ||
	    !sv_derived_from (sv, "Gtk2::TargetList"))
		croak ("variable is not of type Gtk2::TargetList");
	return INT2PTR (GtkTargetList*, SvUV (SvRV (sv)));
#endif
}


#line 156 "xs\\GtkSelection.c"
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

#line 298 "xs\\GtkSelection.c"
#if !GTK_CHECK_VERSION (2, 10, 0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__TargetList_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TargetList_DESTROY)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "list");
    {
	SV *	list = ST(0)
;
#line 203 "xs\\\\GtkSelection.xs"
	gtk_target_list_unref (SvGtkTargetList (list));
#line 314 "xs\\GtkSelection.c"
    }
    XSRETURN_EMPTY;
}

#endif /* !2.10 */

XS_EUPXS(XS_Gtk2__TargetList_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TargetList_new)
{
    dVAR; dXSARGS;
    if (items < 1)
       croak_xs_usage(cv,  "class, ...");
    {
#line 214 "xs\\\\GtkSelection.xs"
	GtkTargetEntry *targets;
	guint ntargets;
#line 331 "xs\\GtkSelection.c"
	GtkTargetList *	RETVAL;
#line 217 "xs\\\\GtkSelection.xs"
	GTK2PERL_STACK_ITEMS_TO_TARGET_ENTRY_ARRAY (1, targets, ntargets);
	RETVAL = gtk_target_list_new (targets, ntargets);
#line 336 "xs\\GtkSelection.c"
	ST(0) = newSVGtkTargetList (RETVAL);
	sv_2mortal(ST(0));
#line 222 "xs\\\\GtkSelection.xs"
	gtk_target_list_unref (RETVAL);
#line 341 "xs\\GtkSelection.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__TargetList_add); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TargetList_add)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "list, target, flags, info");
    {
	GtkTargetList *	list = SvGtkTargetList (ST(0))
;
	GdkAtom	target = SvGdkAtom (ST(1))
;
	guint	flags = (guint)SvUV(ST(2))
;
	guint	info = (guint)SvUV(ST(3))
;

	gtk_target_list_add(list, target, flags, info);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TargetList_add_table); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TargetList_add_table)
{
    dVAR; dXSARGS;
    if (items < 1)
       croak_xs_usage(cv,  "list, ...");
    {
#line 239 "xs\\\\GtkSelection.xs"
	GtkTargetEntry *targets;
	guint ntargets;
#line 379 "xs\\GtkSelection.c"
	GtkTargetList *	list = SvGtkTargetList (ST(0))
;
#line 242 "xs\\\\GtkSelection.xs"
	GTK2PERL_STACK_ITEMS_TO_TARGET_ENTRY_ARRAY (1, targets, ntargets);
	gtk_target_list_add_table (list, targets, ntargets);
#line 385 "xs\\GtkSelection.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TargetList_remove); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TargetList_remove)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "list, target");
    {
	GtkTargetList *	list = SvGtkTargetList (ST(0))
;
	GdkAtom	target = SvGdkAtom (ST(1))
;

	gtk_target_list_remove(list, target);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TargetList_find); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TargetList_find)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "list, target");
    {
	GtkTargetList *	list = SvGtkTargetList (ST(0))
;
	GdkAtom	target = SvGdkAtom (ST(1))
;
	guint	RETVAL;
	dXSTARG;
#line 257 "xs\\\\GtkSelection.xs"
	if (!gtk_target_list_find (list, target, &RETVAL))
		XSRETURN_UNDEF;
#line 425 "xs\\GtkSelection.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

#if GTK_CHECK_VERSION (2, 6, 0)
#define XSubPPtmpAAAB 1


XS_EUPXS(XS_Gtk2__TargetList_add_text_targets); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TargetList_add_text_targets)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "list, info");
    {
	GtkTargetList *	list = SvGtkTargetList (ST(0))
;
	guint	info = (guint)SvUV(ST(1))
;

	gtk_target_list_add_text_targets(list, info);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TargetList_add_image_targets); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TargetList_add_image_targets)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "list, info, writable");
    {
	GtkTargetList *	list = SvGtkTargetList (ST(0))
;
	guint	info = (guint)SvUV(ST(1))
;
	gboolean	writable = (bool)SvTRUE(ST(2))
;

	gtk_target_list_add_image_targets(list, info, writable);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__TargetList_add_uri_targets); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TargetList_add_uri_targets)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "list, info");
    {
	GtkTargetList *	list = SvGtkTargetList (ST(0))
;
	guint	info = (guint)SvUV(ST(1))
;

	gtk_target_list_add_uri_targets(list, info);
    }
    XSRETURN_EMPTY;
}

#endif
#if GTK_CHECK_VERSION (2, 10, 0)
#define XSubPPtmpAAAC 1


XS_EUPXS(XS_Gtk2__TargetList_add_rich_text_targets); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__TargetList_add_rich_text_targets)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "list, info, deserializable, buffer");
    {
	GtkTargetList *	list = SvGtkTargetList (ST(0))
;
	guint	info = (guint)SvUV(ST(1))
;
	gboolean	deserializable = (bool)SvTRUE(ST(2))
;
	GtkTextBuffer *	buffer = SvGtkTextBuffer (ST(3))
;

	gtk_target_list_add_rich_text_targets(list, info, deserializable, buffer);
    }
    XSRETURN_EMPTY;
}

#endif

XS_EUPXS(XS_Gtk2__Selection_owner_set); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Selection_owner_set)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "class, widget, selection, time_");
    {
	GtkWidget_ornull *	widget = SvGtkWidget_ornull (ST(1))
;
	GdkAtom	selection = SvGdkAtom (ST(2))
;
	guint32	time_ = (guint32)SvUV(ST(3))
;
	gboolean	RETVAL;

	RETVAL = gtk_selection_owner_set(widget, selection, time_);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#if GTK_CHECK_VERSION(2,2,0)
#define XSubPPtmpAAAD 1


XS_EUPXS(XS_Gtk2__Selection_owner_set_for_display); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Selection_owner_set_for_display)
{
    dVAR; dXSARGS;
    if (items != 5)
       croak_xs_usage(cv,  "class, display, widget, selection, time_");
    {
	GdkDisplay *	display = SvGdkDisplay (ST(1))
;
	GtkWidget_ornull *	widget = SvGtkWidget_ornull (ST(2))
;
	GdkAtom	selection = SvGdkAtom (ST(3))
;
	guint32	time_ = (guint32)SvUV(ST(4))
;
	gboolean	RETVAL;

	RETVAL = gtk_selection_owner_set_for_display(display, widget, selection, time_);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif /* >= 2.2.0 */

XS_EUPXS(XS_Gtk2__Widget_selection_add_target); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Widget_selection_add_target)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "widget, selection, target, info");
    {
	GtkWidget *	widget = SvGtkWidget (ST(0))
;
	GdkAtom	selection = SvGdkAtom (ST(1))
;
	GdkAtom	target = SvGdkAtom (ST(2))
;
	guint	info = (guint)SvUV(ST(3))
;

	gtk_selection_add_target(widget, selection, target, info);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Widget_selection_add_targets); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Widget_selection_add_targets)
{
    dVAR; dXSARGS;
    if (items < 2)
       croak_xs_usage(cv,  "widget, selection, ...");
    {
	GtkWidget *	widget = SvGtkWidget (ST(0))
;
	GdkAtom	selection = SvGdkAtom (ST(1))
;
#line 325 "xs\\\\GtkSelection.xs"
	GtkTargetEntry *targets;
	guint ntargets;
#line 606 "xs\\GtkSelection.c"
#line 328 "xs\\\\GtkSelection.xs"
	GTK2PERL_STACK_ITEMS_TO_TARGET_ENTRY_ARRAY (2, targets, ntargets);
	gtk_selection_add_targets (widget, selection, targets, ntargets);
#line 610 "xs\\GtkSelection.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Widget_selection_clear_targets); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Widget_selection_clear_targets)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "widget, selection");
    {
	GtkWidget *	widget = SvGtkWidget (ST(0))
;
	GdkAtom	selection = SvGdkAtom (ST(1))
;

	gtk_selection_clear_targets(widget, selection);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Widget_selection_convert); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Widget_selection_convert)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "widget, selection, target, time_");
    {
	GtkWidget *	widget = SvGtkWidget (ST(0))
;
	GdkAtom	selection = SvGdkAtom (ST(1))
;
	GdkAtom	target = SvGdkAtom (ST(2))
;
	guint32	time_ = (guint32)SvUV(ST(3))
;
	gboolean	RETVAL;

	RETVAL = gtk_selection_convert(widget, selection, target, time_);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Widget_selection_remove_all); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Widget_selection_remove_all)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "widget");
    {
	GtkWidget *	widget = SvGtkWidget (ST(0))
;

	gtk_selection_remove_all(widget);
    }
    XSRETURN_EMPTY;
}

#if GTK_CHECK_VERSION (2, 10, 0)
#define XSubPPtmpAAAE 1


XS_EUPXS(XS_Gtk2_targets_include_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2_targets_include_text)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items < 2)
       croak_xs_usage(cv,  "class, first_target_atom, ...");
    {
#line 361 "xs\\\\GtkSelection.xs"
        GdkAtom * targets;
        gint n_targets;
        gint i;
#line 690 "xs\\GtkSelection.c"
	gboolean	RETVAL;
	GdkAtom	first_target_atom = SvGdkAtom (ST(1))
;
#line 365 "xs\\\\GtkSelection.xs"
        n_targets = items - 1;
        targets = g_new (GdkAtom, n_targets);
	targets[0] = first_target_atom;
        for (i = 2; i < items ; i++)
                targets[i-1] = SvGdkAtom (ST (i));
        if (ix == 1)
                RETVAL = gtk_targets_include_uri (targets, n_targets);
        else
                RETVAL = gtk_targets_include_text (targets, n_targets);
        g_free (targets);
#line 705 "xs\\GtkSelection.c"
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2_targets_include_rich_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2_targets_include_rich_text)
{
    dVAR; dXSARGS;
    if (items < 3)
       croak_xs_usage(cv,  "class, buffer, first_target_atom, ...");
    {
#line 380 "xs\\\\GtkSelection.xs"
        GdkAtom * targets;
        gint n_targets;
        gint i;
#line 724 "xs\\GtkSelection.c"
	gboolean	RETVAL;
	GtkTextBuffer *	buffer = SvGtkTextBuffer (ST(1))
;
	GdkAtom	first_target_atom = SvGdkAtom (ST(2))
;
#line 384 "xs\\\\GtkSelection.xs"
        n_targets = items - 2;
        targets = g_new (GdkAtom, n_targets);
	targets[0] = first_target_atom;
        for (i = 3; i < items ; i++)
                targets[i-2] = SvGdkAtom (ST (i));
        RETVAL = gtk_targets_include_rich_text (targets, n_targets, buffer);
        g_free (targets);
#line 738 "xs\\GtkSelection.c"
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2_targets_include_image); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2_targets_include_image)
{
    dVAR; dXSARGS;
    if (items < 3)
       croak_xs_usage(cv,  "class, writable, first_target_atom, ...");
    {
#line 396 "xs\\\\GtkSelection.xs"
        GdkAtom * targets;
        gint n_targets;
        gint i;
#line 757 "xs\\GtkSelection.c"
	gboolean	RETVAL;
	gboolean	writable = (bool)SvTRUE(ST(1))
;
	GdkAtom	first_target_atom = SvGdkAtom (ST(2))
;
#line 400 "xs\\\\GtkSelection.xs"
        n_targets = items - 2;
        targets = g_new (GdkAtom, n_targets);
	targets[0] = first_target_atom;
        for (i = 3; i < items ; i++)
                targets[i-2] = SvGdkAtom (ST (i));
        RETVAL = gtk_targets_include_image (targets, n_targets, writable);
        g_free (targets);
#line 771 "xs\\GtkSelection.c"
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif /* 2.10 */

XS_EUPXS(XS_Gtk2__SelectionData_get_selection); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_get_selection)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 1)
       croak_xs_usage(cv,  "d");
    {
	GtkSelectionData *	d = SvGtkSelectionData (ST(0))
;
	SV *	RETVAL;
#line 458 "xs\\\\GtkSelection.xs"
	switch (ix) {
	    case 0:
	    case 1:
		RETVAL = newSVGdkAtom (gtk_selection_data_get_selection (d));
		break;
	    case 2:
	    case 3:
		RETVAL = newSVGdkAtom (gtk_selection_data_get_target (d));
		break;
	    case 4:
	    case 5:
		RETVAL = newSVGdkAtom (gtk_selection_data_get_data_type (d));
		break;
	    case 6:
	    case 7:
		RETVAL = newSViv (gtk_selection_data_get_format (d));
		break;
	    case 8:
	    case 9:
		RETVAL = newSVpv (
			(const gchar *) gtk_selection_data_get_data (d),
			gtk_selection_data_get_length (d)
		);
		break;
	    case 10:
	    case 11:
		RETVAL = newSViv (gtk_selection_data_get_length (d));
		break;
#if GTK_CHECK_VERSION(2, 2, 0)
	    case 12:
	    case 13:
		RETVAL = newSVGdkDisplay (gtk_selection_data_get_display (d));
		break;
#endif /* 2.2 */
	    default:
		RETVAL = NULL;
		g_assert_not_reached ();
	}
#line 830 "xs\\GtkSelection.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__SelectionData_set); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_set)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "selection_data, type, format, data");
    {
	GtkSelectionData *	selection_data = SvGtkSelectionData (ST(0))
;
	GdkAtom	type = SvGdkAtom (ST(1))
;
	gint	format = (gint)SvIV(ST(2))
;
	const guchar *	data = (const guchar *)SvPV_nolen (ST(3))
;

	gtk_selection_data_set(selection_data, type, format, data, sv_len (ST (3)));
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__SelectionData_set_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_set_text)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "selection_data, str, len=-1");
    {
	GtkSelectionData *	selection_data = SvGtkSelectionData (ST(0))
;
	const gchar *	str;
	gint	len;
	gboolean	RETVAL;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	str = (const gchar *)SvPV_nolen (ST(1))
;

	if (items < 3)
	    len = -1;
	else {
	    len = (gint)SvIV(ST(2))
;
	}

	RETVAL = gtk_selection_data_set_text(selection_data, str, len);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__SelectionData_get_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_get_text)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection_data");
    {
	GtkSelectionData *	selection_data = SvGtkSelectionData (ST(0))
;
	gchar_own *	RETVAL;
#line 522 "xs\\\\GtkSelection.xs"
	/* the C function returns guchar*, but the docs say it will return
	 * a UTF-8 string or NULL.  for our code to do the UTF-8 upgrade,
	 * we need to use a gchar* typemap, so we'll cast to keep the compiler
	 * happy. */
	RETVAL = (gchar*) gtk_selection_data_get_text (selection_data);
	/* the docs say get_text will return NULL if there is no text or it
	 * the text can't be converted to UTF-8.  (why don't we have a
	 * gchar_own_ornull typemap?) */
	if (!RETVAL)
		XSRETURN_UNDEF;
#line 914 "xs\\GtkSelection.c"
	ST(0) = sv_newmortal();
	/* used when we can directly own the returned string. */
	/* we have to copy in the case when perl's malloc != gtk's malloc,
         * so best copy all the time. */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
        g_free (RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__SelectionData_get_targets); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_get_targets)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection_data");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	GtkSelectionData *	selection_data = SvGtkSelectionData (ST(0))
;
#line 547 "xs\\\\GtkSelection.xs"
	GdkAtom *targets;
	gint n_atoms, i;
#line 941 "xs\\GtkSelection.c"
#line 550 "xs\\\\GtkSelection.xs"
	if (!gtk_selection_data_get_targets (selection_data,
	                                     &targets, &n_atoms))
		XSRETURN_EMPTY;
	EXTEND (SP, n_atoms);
	for (i = 0 ; i < n_atoms ; i++)
		PUSHs (sv_2mortal (newSVGdkAtom (targets[i])));
	g_free (targets);
#line 950 "xs\\GtkSelection.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__SelectionData_targets_include_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_targets_include_text)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection_data");
    {
	GtkSelectionData *	selection_data = SvGtkSelectionData (ST(0))
;
	gboolean	RETVAL;

	RETVAL = gtk_selection_data_targets_include_text(selection_data);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__SelectionData_gtk_selection_clear); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_gtk_selection_clear)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "widget, event");
    {
	GtkWidget *	widget = SvGtkWidget (ST(0))
;
	GdkEvent *	event = SvGdkEvent (ST(1))
;
	gboolean	RETVAL;

	RETVAL = gtk_selection_clear(widget, (GdkEventSelection*)event);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#if GTK_CHECK_VERSION (2, 6, 0)
#define XSubPPtmpAAAF 1


XS_EUPXS(XS_Gtk2__SelectionData_set_pixbuf); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_set_pixbuf)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "selection_data, pixbuf");
    {
	gboolean	RETVAL;
	GtkSelectionData *	selection_data = SvGtkSelectionData (ST(0))
;
	GdkPixbuf *	pixbuf = SvGdkPixbuf (ST(1))
;

	RETVAL = gtk_selection_data_set_pixbuf(selection_data, pixbuf);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__SelectionData_get_pixbuf); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_get_pixbuf)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection_data");
    {
	GdkPixbuf_noinc_ornull *	RETVAL;
	GtkSelectionData *	selection_data = SvGtkSelectionData (ST(0))
;

	RETVAL = gtk_selection_data_get_pixbuf(selection_data);
	ST(0) = newSVGdkPixbuf_noinc_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__SelectionData_set_uris); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_set_uris)
{
    dVAR; dXSARGS;
    if (items < 1)
       croak_xs_usage(cv,  "selection_data, ...");
    {
	GtkSelectionData *	selection_data = SvGtkSelectionData (ST(0))
;
#line 591 "xs\\\\GtkSelection.xs"
	gchar **uris = NULL;
	int i;
#line 1052 "xs\\GtkSelection.c"
	gboolean	RETVAL;
#line 594 "xs\\\\GtkSelection.xs"
	/* uris is NULL-terminated. */
	uris = g_new0 (gchar *, items);
	for (i = 1; i < items; i++)
		uris[i - 1] = SvGChar (ST (i));
	RETVAL = gtk_selection_data_set_uris (selection_data, uris);
	g_free (uris);
#line 1061 "xs\\GtkSelection.c"
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__SelectionData_get_uris); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_get_uris)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection_data");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	GtkSelectionData *	selection_data = SvGtkSelectionData (ST(0))
;
#line 608 "xs\\\\GtkSelection.xs"
	gchar **uris = NULL;
	int i;
#line 1083 "xs\\GtkSelection.c"
#line 611 "xs\\\\GtkSelection.xs"
	uris = gtk_selection_data_get_uris (selection_data);
	if (!uris)
		XSRETURN_EMPTY;
	for (i = 0; uris[i]; i++)
		XPUSHs (sv_2mortal (newSVGChar (uris[i])));
	g_strfreev (uris);
#line 1091 "xs\\GtkSelection.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__SelectionData_targets_include_image); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_targets_include_image)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "selection_data, writable");
    {
	gboolean	RETVAL;
	GtkSelectionData *	selection_data = SvGtkSelectionData (ST(0))
;
	gboolean	writable = (bool)SvTRUE(ST(1))
;

	RETVAL = gtk_selection_data_targets_include_image(selection_data, writable);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif /* 2.6 */
#if GTK_CHECK_VERSION (2, 10, 0)
#define XSubPPtmpAAAG 1


XS_EUPXS(XS_Gtk2__SelectionData_targets_include_rich_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_targets_include_rich_text)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "selection_data, buffer");
    {
	gboolean	RETVAL;
	GtkSelectionData *	selection_data = SvGtkSelectionData (ST(0))
;
	GtkTextBuffer *	buffer = SvGtkTextBuffer (ST(1))
;

	RETVAL = gtk_selection_data_targets_include_rich_text(selection_data, buffer);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__SelectionData_targets_include_uri); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__SelectionData_targets_include_uri)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "selection_data");
    {
	gboolean	RETVAL;
	GtkSelectionData *	selection_data = SvGtkSelectionData (ST(0))
;

	RETVAL = gtk_selection_data_targets_include_uri(selection_data);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif /* 2.10 */
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__Selection); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__Selection)
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

#if XSubPPtmpAAAA
        newXS("Gtk2::TargetList::DESTROY", XS_Gtk2__TargetList_DESTROY, file);
#endif
        newXS("Gtk2::TargetList::new", XS_Gtk2__TargetList_new, file);
        newXS("Gtk2::TargetList::add", XS_Gtk2__TargetList_add, file);
        newXS("Gtk2::TargetList::add_table", XS_Gtk2__TargetList_add_table, file);
        newXS("Gtk2::TargetList::remove", XS_Gtk2__TargetList_remove, file);
        newXS("Gtk2::TargetList::find", XS_Gtk2__TargetList_find, file);
#if XSubPPtmpAAAB
        newXS("Gtk2::TargetList::add_text_targets", XS_Gtk2__TargetList_add_text_targets, file);
        newXS("Gtk2::TargetList::add_image_targets", XS_Gtk2__TargetList_add_image_targets, file);
        newXS("Gtk2::TargetList::add_uri_targets", XS_Gtk2__TargetList_add_uri_targets, file);
#endif
#if XSubPPtmpAAAC
        newXS("Gtk2::TargetList::add_rich_text_targets", XS_Gtk2__TargetList_add_rich_text_targets, file);
#endif
        newXS("Gtk2::Selection::owner_set", XS_Gtk2__Selection_owner_set, file);
#if XSubPPtmpAAAD
        newXS("Gtk2::Selection::owner_set_for_display", XS_Gtk2__Selection_owner_set_for_display, file);
#endif
        newXS("Gtk2::Widget::selection_add_target", XS_Gtk2__Widget_selection_add_target, file);
        newXS("Gtk2::Widget::selection_add_targets", XS_Gtk2__Widget_selection_add_targets, file);
        newXS("Gtk2::Widget::selection_clear_targets", XS_Gtk2__Widget_selection_clear_targets, file);
        newXS("Gtk2::Widget::selection_convert", XS_Gtk2__Widget_selection_convert, file);
        newXS("Gtk2::Widget::selection_remove_all", XS_Gtk2__Widget_selection_remove_all, file);
#if XSubPPtmpAAAE
        cv = newXS("Gtk2::targets_include_text", XS_Gtk2_targets_include_text, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::targets_include_uri", XS_Gtk2_targets_include_text, file);
        XSANY.any_i32 = 1;
        newXS("Gtk2::targets_include_rich_text", XS_Gtk2_targets_include_rich_text, file);
        newXS("Gtk2::targets_include_image", XS_Gtk2_targets_include_image, file);
#endif
        cv = newXS("Gtk2::SelectionData::length", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 11;
        cv = newXS("Gtk2::SelectionData::display", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 13;
        cv = newXS("Gtk2::SelectionData::get_length", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 10;
        cv = newXS("Gtk2::SelectionData::format", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 7;
        cv = newXS("Gtk2::SelectionData::get_format", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 6;
        cv = newXS("Gtk2::SelectionData::get_display", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 12;
        cv = newXS("Gtk2::SelectionData::selection", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::SelectionData::type", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 5;
        cv = newXS("Gtk2::SelectionData::data", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 9;
        cv = newXS("Gtk2::SelectionData::get_target", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 2;
        cv = newXS("Gtk2::SelectionData::target", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 3;
        cv = newXS("Gtk2::SelectionData::get_data_type", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 4;
        cv = newXS("Gtk2::SelectionData::get_data", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 8;
        cv = newXS("Gtk2::SelectionData::get_selection", XS_Gtk2__SelectionData_get_selection, file);
        XSANY.any_i32 = 0;
        newXS("Gtk2::SelectionData::set", XS_Gtk2__SelectionData_set, file);
        newXS("Gtk2::SelectionData::set_text", XS_Gtk2__SelectionData_set_text, file);
        newXS("Gtk2::SelectionData::get_text", XS_Gtk2__SelectionData_get_text, file);
        newXS("Gtk2::SelectionData::get_targets", XS_Gtk2__SelectionData_get_targets, file);
        newXS("Gtk2::SelectionData::targets_include_text", XS_Gtk2__SelectionData_targets_include_text, file);
        newXS("Gtk2::SelectionData::gtk_selection_clear", XS_Gtk2__SelectionData_gtk_selection_clear, file);
#if XSubPPtmpAAAF
        newXS("Gtk2::SelectionData::set_pixbuf", XS_Gtk2__SelectionData_set_pixbuf, file);
        newXS("Gtk2::SelectionData::get_pixbuf", XS_Gtk2__SelectionData_get_pixbuf, file);
        newXS("Gtk2::SelectionData::set_uris", XS_Gtk2__SelectionData_set_uris, file);
        newXS("Gtk2::SelectionData::get_uris", XS_Gtk2__SelectionData_get_uris, file);
        newXS("Gtk2::SelectionData::targets_include_image", XS_Gtk2__SelectionData_targets_include_image, file);
#endif
#if XSubPPtmpAAAG
        newXS("Gtk2::SelectionData::targets_include_rich_text", XS_Gtk2__SelectionData_targets_include_rich_text, file);
        newXS("Gtk2::SelectionData::targets_include_uri", XS_Gtk2__SelectionData_targets_include_uri, file);
#endif
    }

    /* Initialisation Section */

#line 187 "xs\\\\GtkSelection.xs"
#if GTK_CHECK_VERSION (2, 9, 0)
	default_wrapper_class = gperl_default_boxed_wrapper_class ();
	gtk_target_list_wrapper_class = *default_wrapper_class;
	gtk_target_list_wrapper_class.wrap = gtk_target_list_wrap;
	gperl_register_boxed (GTK_TYPE_TARGET_LIST, "Gtk2::TargetList",
	                      &gtk_target_list_wrapper_class);
#endif

#if XSubPPtmpAAAA
#endif
#if XSubPPtmpAAAB
#endif
#if XSubPPtmpAAAC
#endif
#if XSubPPtmpAAAD
#endif
#if XSubPPtmpAAAE
#endif
#if XSubPPtmpAAAF
#endif
#if XSubPPtmpAAAG
#endif
#line 1291 "xs\\GtkSelection.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

