/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkToolItemGroup.xs. Do not edit this file, edit GtkToolItemGroup.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkToolItemGroup.xs"
/*
 * Copyright (c) 2010 by the gtk2-perl team (see the file AUTHORS)
 *
 * Licensed under the LGPL, see LICENSE file for more information.
 *
 * $Id$
 */

#include "gtk2perl.h"

#line 21 "xs\\GtkToolItemGroup.c"
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

#line 163 "xs\\GtkToolItemGroup.c"

XS_EUPXS(XS_Gtk2__ToolItemGroup_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_new)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, label");
    {
	GtkWidget *	RETVAL;
	const gchar *	label;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	label = (const gchar *)SvPV_nolen (ST(1))
;

	RETVAL = gtk_tool_item_group_new(label);
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_get_collapsed); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_get_collapsed)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "group");
    {
	gboolean	RETVAL;
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;

	RETVAL = gtk_tool_item_group_get_collapsed(group);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_get_drop_item); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_get_drop_item)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "group, x, y");
    {
	GtkToolItem *	RETVAL;
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;
	gint	x = (gint)SvIV(ST(1))
;
	gint	y = (gint)SvIV(ST(2))
;

	RETVAL = gtk_tool_item_group_get_drop_item(group, x, y);
	ST(0) = newSVGtkToolItem (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_get_ellipsize); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_get_ellipsize)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "group");
    {
	PangoEllipsizeMode	RETVAL;
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;

	RETVAL = gtk_tool_item_group_get_ellipsize(group);
	ST(0) = newSVPangoEllipsizeMode (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_get_item_position); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_get_item_position)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "group, item");
    {
	gint	RETVAL;
	dXSTARG;
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;
	GtkToolItem *	item = SvGtkToolItem (ST(1))
;

	RETVAL = gtk_tool_item_group_get_item_position(group, item);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_get_n_items); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_get_n_items)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "group");
    {
	guint	RETVAL;
	dXSTARG;
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;

	RETVAL = gtk_tool_item_group_get_n_items(group);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_get_label); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_get_label)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "group");
    {
	const gchar *	RETVAL;
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;

	RETVAL = gtk_tool_item_group_get_label(group);
	ST(0) = sv_newmortal();
	/* same as newSVGChar(), but not in a function */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_get_label_widget); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_get_label_widget)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "group");
    {
	GtkWidget *	RETVAL;
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;

	RETVAL = gtk_tool_item_group_get_label_widget(group);
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_get_nth_item); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_get_nth_item)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "group, index");
    {
	GtkToolItem *	RETVAL;
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;
	guint	index = (guint)SvUV(ST(1))
;

	RETVAL = gtk_tool_item_group_get_nth_item(group, index);
	ST(0) = newSVGtkToolItem (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_get_header_relief); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_get_header_relief)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "group");
    {
	GtkReliefStyle	RETVAL;
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;

	RETVAL = gtk_tool_item_group_get_header_relief(group);
	ST(0) = newSVGtkReliefStyle (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_insert); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_insert)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "group, item, position");
    {
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;
	GtkToolItem *	item = SvGtkToolItem (ST(1))
;
	gint	position = (gint)SvIV(ST(2))
;

	gtk_tool_item_group_insert(group, item, position);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_set_collapsed); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_set_collapsed)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "group, collapsed");
    {
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;
	gboolean	collapsed = (bool)SvTRUE(ST(1))
;

	gtk_tool_item_group_set_collapsed(group, collapsed);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_set_ellipsize); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_set_ellipsize)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "group, ellipsize");
    {
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;
	PangoEllipsizeMode	ellipsize = SvPangoEllipsizeMode (ST(1))
;

	gtk_tool_item_group_set_ellipsize(group, ellipsize);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_set_item_position); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_set_item_position)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "group, item, position");
    {
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;
	GtkToolItem *	item = SvGtkToolItem (ST(1))
;
	gint	position = (gint)SvIV(ST(2))
;

	gtk_tool_item_group_set_item_position(group, item, position);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_set_label); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_set_label)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "group, label");
    {
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;
	const gchar *	label;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	label = (const gchar *)SvPV_nolen (ST(1))
;

	gtk_tool_item_group_set_label(group, label);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_set_label_widget); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_set_label_widget)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "group, label_widget");
    {
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;
	GtkWidget *	label_widget = SvGtkWidget (ST(1))
;

	gtk_tool_item_group_set_label_widget(group, label_widget);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__ToolItemGroup_set_header_relief); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__ToolItemGroup_set_header_relief)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "group, style");
    {
	GtkToolItemGroup *	group = SvGtkToolItemGroup (ST(0))
;
	GtkReliefStyle	style = SvGtkReliefStyle (ST(1))
;

	gtk_tool_item_group_set_header_relief(group, style);
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__ToolItemGroup); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__ToolItemGroup)
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

        newXS("Gtk2::ToolItemGroup::new", XS_Gtk2__ToolItemGroup_new, file);
        newXS("Gtk2::ToolItemGroup::get_collapsed", XS_Gtk2__ToolItemGroup_get_collapsed, file);
        newXS("Gtk2::ToolItemGroup::get_drop_item", XS_Gtk2__ToolItemGroup_get_drop_item, file);
        newXS("Gtk2::ToolItemGroup::get_ellipsize", XS_Gtk2__ToolItemGroup_get_ellipsize, file);
        newXS("Gtk2::ToolItemGroup::get_item_position", XS_Gtk2__ToolItemGroup_get_item_position, file);
        newXS("Gtk2::ToolItemGroup::get_n_items", XS_Gtk2__ToolItemGroup_get_n_items, file);
        newXS("Gtk2::ToolItemGroup::get_label", XS_Gtk2__ToolItemGroup_get_label, file);
        newXS("Gtk2::ToolItemGroup::get_label_widget", XS_Gtk2__ToolItemGroup_get_label_widget, file);
        newXS("Gtk2::ToolItemGroup::get_nth_item", XS_Gtk2__ToolItemGroup_get_nth_item, file);
        newXS("Gtk2::ToolItemGroup::get_header_relief", XS_Gtk2__ToolItemGroup_get_header_relief, file);
        newXS("Gtk2::ToolItemGroup::insert", XS_Gtk2__ToolItemGroup_insert, file);
        newXS("Gtk2::ToolItemGroup::set_collapsed", XS_Gtk2__ToolItemGroup_set_collapsed, file);
        newXS("Gtk2::ToolItemGroup::set_ellipsize", XS_Gtk2__ToolItemGroup_set_ellipsize, file);
        newXS("Gtk2::ToolItemGroup::set_item_position", XS_Gtk2__ToolItemGroup_set_item_position, file);
        newXS("Gtk2::ToolItemGroup::set_label", XS_Gtk2__ToolItemGroup_set_label, file);
        newXS("Gtk2::ToolItemGroup::set_label_widget", XS_Gtk2__ToolItemGroup_set_label_widget, file);
        newXS("Gtk2::ToolItemGroup::set_header_relief", XS_Gtk2__ToolItemGroup_set_header_relief, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

