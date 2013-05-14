/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkRecentChooser.xs. Do not edit this file, edit GtkRecentChooser.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkRecentChooser.xs"
/*
 * Copyright (c) 2006 by the gtk2-perl team (see the file AUTHORS)
 *
 * Licensed under the LGPL, see LICENSE file for more information.
 *
 * $Id$
 */

#include "gtk2perl.h"

static gint
gtk2perl_recent_sort_func (GtkRecentInfo *a,
			   GtkRecentInfo *b,
			   gpointer       user_data)
{
  GPerlCallback *callback = (GPerlCallback *) user_data;
  GValue value = { 0, };
  gint retval;

  g_value_init (&value, callback->return_type);

  gperl_callback_invoke (callback, &value, a, b);
  retval = g_value_get_int (&value);

  g_value_unset (&value);

  return retval;
}

static GPerlCallback *
gtk2perl_recent_sort_func_create (SV *func,
				  SV *data)
{
  GType param_types[2];

  param_types[0] = GTK_TYPE_RECENT_INFO;
  param_types[1] = GTK_TYPE_RECENT_INFO;

  return gperl_callback_new (func, data,
		  	     G_N_ELEMENTS (param_types), param_types,
			     G_TYPE_INT);
}

#line 54 "xs\\GtkRecentChooser.c"
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

#line 196 "xs\\GtkRecentChooser.c"

XS_EUPXS(XS_Gtk2__RecentChooser_set_show_private); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_set_show_private)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, show_private");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	gboolean	show_private = (bool)SvTRUE(ST(1))
;

	gtk_recent_chooser_set_show_private(chooser, show_private);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_get_show_private); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_get_show_private)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    {
	gboolean	RETVAL;
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;

	RETVAL = gtk_recent_chooser_get_show_private(chooser);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__RecentChooser_set_show_not_found); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_set_show_not_found)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, show_not_found");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	gboolean	show_not_found = (bool)SvTRUE(ST(1))
;

	gtk_recent_chooser_set_show_not_found(chooser, show_not_found);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_get_show_not_found); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_get_show_not_found)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    {
	gboolean	RETVAL;
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;

	RETVAL = gtk_recent_chooser_get_show_not_found(chooser);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__RecentChooser_set_select_multiple); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_set_select_multiple)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, select_multiple");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	gboolean	select_multiple = (bool)SvTRUE(ST(1))
;

	gtk_recent_chooser_set_select_multiple(chooser, select_multiple);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_get_select_multiple); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_get_select_multiple)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    {
	gboolean	RETVAL;
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;

	RETVAL = gtk_recent_chooser_get_select_multiple(chooser);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__RecentChooser_set_limit); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_set_limit)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, limit");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	gint	limit = (gint)SvIV(ST(1))
;

	gtk_recent_chooser_set_limit(chooser, limit);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_get_limit); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_get_limit)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    {
	gint	RETVAL;
	dXSTARG;
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;

	RETVAL = gtk_recent_chooser_get_limit(chooser);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__RecentChooser_set_local_only); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_set_local_only)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, local_only");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	gboolean	local_only = (bool)SvTRUE(ST(1))
;

	gtk_recent_chooser_set_local_only(chooser, local_only);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_get_local_only); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_get_local_only)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    {
	gboolean	RETVAL;
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;

	RETVAL = gtk_recent_chooser_get_local_only(chooser);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__RecentChooser_set_show_tips); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_set_show_tips)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, show_tips");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	gboolean	show_tips = (bool)SvTRUE(ST(1))
;

	gtk_recent_chooser_set_show_tips(chooser, show_tips);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_get_show_tips); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_get_show_tips)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    {
	gboolean	RETVAL;
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;

	RETVAL = gtk_recent_chooser_get_show_tips(chooser);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__RecentChooser_set_show_icons); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_set_show_icons)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, show_icons");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	gboolean	show_icons = (bool)SvTRUE(ST(1))
;

	gtk_recent_chooser_set_show_icons(chooser, show_icons);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_get_show_icons); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_get_show_icons)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    {
	gboolean	RETVAL;
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;

	RETVAL = gtk_recent_chooser_get_show_icons(chooser);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__RecentChooser_set_sort_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_set_sort_type)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, sort_type");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	GtkRecentSortType	sort_type = SvGtkRecentSortType (ST(1))
;

	gtk_recent_chooser_set_sort_type(chooser, sort_type);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_get_sort_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_get_sort_type)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    {
	GtkRecentSortType	RETVAL;
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;

	RETVAL = gtk_recent_chooser_get_sort_type(chooser);
	ST(0) = newSVGtkRecentSortType (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__RecentChooser_set_sort_func); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_set_sort_func)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "chooser, sort_func, sort_data=NULL");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	SV *	sort_func = ST(1)
;
	SV *	sort_data;
#line 117 "xs\\\\GtkRecentChooser.xs"
        GPerlCallback *func;
#line 508 "xs\\GtkRecentChooser.c"

	if (items < 3)
	    sort_data = NULL;
	else {
	    sort_data = ST(2)
;
	}
#line 119 "xs\\\\GtkRecentChooser.xs"
        func = gtk2perl_recent_sort_func_create (sort_func, sort_data);
	gtk_recent_chooser_set_sort_func (chooser,
					  gtk2perl_recent_sort_func,
					  func,
					  (GDestroyNotify) gperl_callback_destroy);
#line 522 "xs\\GtkRecentChooser.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_set_current_uri); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_set_current_uri)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, uri");
    {
#line 133 "xs\\\\GtkRecentChooser.xs"
        GError *error = NULL;
#line 537 "xs\\GtkRecentChooser.c"
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	const gchar *	uri;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	uri = (const gchar *)SvPV_nolen (ST(1))
;
#line 135 "xs\\\\GtkRecentChooser.xs"
        gtk_recent_chooser_set_current_uri (chooser, uri, &error);
	if (error)
		gperl_croak_gerror (NULL, error);
#line 550 "xs\\GtkRecentChooser.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_get_current_uri); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_get_current_uri)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    {
	gchar_own *	RETVAL;
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;

	RETVAL = gtk_recent_chooser_get_current_uri(chooser);
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


XS_EUPXS(XS_Gtk2__RecentChooser_get_current_item); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_get_current_item)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    {
	GtkRecentInfo *	RETVAL;
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;

	RETVAL = gtk_recent_chooser_get_current_item(chooser);
	ST(0) = newSVGtkRecentInfo (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__RecentChooser_select_uri); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_select_uri)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, uri");
    {
#line 150 "xs\\\\GtkRecentChooser.xs"
        GError *error = NULL;
#line 608 "xs\\GtkRecentChooser.c"
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	const gchar *	uri;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	uri = (const gchar *)SvPV_nolen (ST(1))
;
#line 152 "xs\\\\GtkRecentChooser.xs"
        gtk_recent_chooser_select_uri (chooser, uri, &error);
	if (error)
		gperl_croak_gerror (NULL, error);
#line 621 "xs\\GtkRecentChooser.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_unselect_uri); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_unselect_uri)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, uri");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	const gchar *	uri;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	uri = (const gchar *)SvPV_nolen (ST(1))
;

	gtk_recent_chooser_unselect_uri(chooser, uri);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_select_all); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_select_all)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;

	gtk_recent_chooser_select_all(chooser);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_unselect_all); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_unselect_all)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;

	gtk_recent_chooser_unselect_all(chooser);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_get_items); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_get_items)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 171 "xs\\\\GtkRecentChooser.xs"
        GList *items, *l;
#line 692 "xs\\GtkRecentChooser.c"
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
#line 173 "xs\\\\GtkRecentChooser.xs"
        items = gtk_recent_chooser_get_items (chooser);

	for (l = items; l != NULL; l = l->next)
		XPUSHs (sv_2mortal (newSVGtkRecentInfo_own (l->data)));

	g_list_free (items);
#line 702 "xs\\GtkRecentChooser.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__RecentChooser_get_uris); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_get_uris)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 186 "xs\\\\GtkRecentChooser.xs"
        gchar **uris;
	gsize length, i;
#line 721 "xs\\GtkRecentChooser.c"
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
#line 189 "xs\\\\GtkRecentChooser.xs"
        uris = gtk_recent_chooser_get_uris (chooser, &length);
	if (length == 0)
		XSRETURN_EMPTY;

	EXTEND (SP, length);
	for (i = 0; i < length; i++)
		PUSHs (sv_2mortal (newSVGChar (uris[i])));

	g_strfreev (uris);
#line 734 "xs\\GtkRecentChooser.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__RecentChooser_add_filter); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_add_filter)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, filter");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(1))
;

	gtk_recent_chooser_add_filter(chooser, filter);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_remove_filter); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_remove_filter)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, filter");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(1))
;

	gtk_recent_chooser_remove_filter(chooser, filter);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_list_filters); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_list_filters)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 214 "xs\\\\GtkRecentChooser.xs"
        GSList *filters, *i;
#line 788 "xs\\GtkRecentChooser.c"
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
#line 216 "xs\\\\GtkRecentChooser.xs"
        filters = gtk_recent_chooser_list_filters (chooser);
	for (i = filters; i != NULL; i = i->next)
		XPUSHs (sv_2mortal (newSVGtkRecentFilter (i->data)));
	g_slist_free (filters);
#line 796 "xs\\GtkRecentChooser.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__RecentChooser_set_filter); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_set_filter)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "chooser, filter");
    {
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(1))
;

	gtk_recent_chooser_set_filter(chooser, filter);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentChooser_get_filter); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentChooser_get_filter)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "chooser");
    {
	GtkRecentFilter *	RETVAL;
	GtkRecentChooser *	chooser = SvGtkRecentChooser (ST(0))
;

	RETVAL = gtk_recent_chooser_get_filter(chooser);
	ST(0) = newSVGtkRecentFilter (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__RecentChooser); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__RecentChooser)
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

        newXS("Gtk2::RecentChooser::set_show_private", XS_Gtk2__RecentChooser_set_show_private, file);
        newXS("Gtk2::RecentChooser::get_show_private", XS_Gtk2__RecentChooser_get_show_private, file);
        newXS("Gtk2::RecentChooser::set_show_not_found", XS_Gtk2__RecentChooser_set_show_not_found, file);
        newXS("Gtk2::RecentChooser::get_show_not_found", XS_Gtk2__RecentChooser_get_show_not_found, file);
        newXS("Gtk2::RecentChooser::set_select_multiple", XS_Gtk2__RecentChooser_set_select_multiple, file);
        newXS("Gtk2::RecentChooser::get_select_multiple", XS_Gtk2__RecentChooser_get_select_multiple, file);
        newXS("Gtk2::RecentChooser::set_limit", XS_Gtk2__RecentChooser_set_limit, file);
        newXS("Gtk2::RecentChooser::get_limit", XS_Gtk2__RecentChooser_get_limit, file);
        newXS("Gtk2::RecentChooser::set_local_only", XS_Gtk2__RecentChooser_set_local_only, file);
        newXS("Gtk2::RecentChooser::get_local_only", XS_Gtk2__RecentChooser_get_local_only, file);
        newXS("Gtk2::RecentChooser::set_show_tips", XS_Gtk2__RecentChooser_set_show_tips, file);
        newXS("Gtk2::RecentChooser::get_show_tips", XS_Gtk2__RecentChooser_get_show_tips, file);
        newXS("Gtk2::RecentChooser::set_show_icons", XS_Gtk2__RecentChooser_set_show_icons, file);
        newXS("Gtk2::RecentChooser::get_show_icons", XS_Gtk2__RecentChooser_get_show_icons, file);
        newXS("Gtk2::RecentChooser::set_sort_type", XS_Gtk2__RecentChooser_set_sort_type, file);
        newXS("Gtk2::RecentChooser::get_sort_type", XS_Gtk2__RecentChooser_get_sort_type, file);
        newXS("Gtk2::RecentChooser::set_sort_func", XS_Gtk2__RecentChooser_set_sort_func, file);
        newXS("Gtk2::RecentChooser::set_current_uri", XS_Gtk2__RecentChooser_set_current_uri, file);
        newXS("Gtk2::RecentChooser::get_current_uri", XS_Gtk2__RecentChooser_get_current_uri, file);
        newXS("Gtk2::RecentChooser::get_current_item", XS_Gtk2__RecentChooser_get_current_item, file);
        newXS("Gtk2::RecentChooser::select_uri", XS_Gtk2__RecentChooser_select_uri, file);
        newXS("Gtk2::RecentChooser::unselect_uri", XS_Gtk2__RecentChooser_unselect_uri, file);
        newXS("Gtk2::RecentChooser::select_all", XS_Gtk2__RecentChooser_select_all, file);
        newXS("Gtk2::RecentChooser::unselect_all", XS_Gtk2__RecentChooser_unselect_all, file);
        newXS("Gtk2::RecentChooser::get_items", XS_Gtk2__RecentChooser_get_items, file);
        newXS("Gtk2::RecentChooser::get_uris", XS_Gtk2__RecentChooser_get_uris, file);
        newXS("Gtk2::RecentChooser::add_filter", XS_Gtk2__RecentChooser_add_filter, file);
        newXS("Gtk2::RecentChooser::remove_filter", XS_Gtk2__RecentChooser_remove_filter, file);
        newXS("Gtk2::RecentChooser::list_filters", XS_Gtk2__RecentChooser_list_filters, file);
        newXS("Gtk2::RecentChooser::set_filter", XS_Gtk2__RecentChooser_set_filter, file);
        newXS("Gtk2::RecentChooser::get_filter", XS_Gtk2__RecentChooser_get_filter, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

