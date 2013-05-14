/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkRecentFilter.xs. Do not edit this file, edit GtkRecentFilter.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkRecentFilter.xs"
/*
 * Copyright (c) 2006 by the gtk2-perl team (see the file AUTHORS)
 *
 * Licensed under the LGPL, see LICENSE file for more information.
 *
 * $Id$
 */

#include "gtk2perl.h"

 /* For gtk2perl_sv_to_strv and gtk2perl_sv_from_strv. */
#include "gtk2perl-private.h"

/*
struct _GtkRecentFilterInfo
{
  GtkRecentFilterFlags contains;

  const gchar *uri;
  const gchar *display_name;
  const gchar *mime_type;
  const gchar **applications;
  const gchar **groups;

  gint age;
};
*/

static SV *
newSVGtkRecentFilterInfo (const GtkRecentFilterInfo *info)
{
  HV *hv;

  if (!info)
    return &PL_sv_undef;

  hv = newHV ();

  gperl_hv_take_sv_s (hv, "contains",
                      newSVGtkRecentFilterFlags (info->contains));

  if (info->uri)
    gperl_hv_take_sv_s (hv, "uri", newSVpv (info->uri, PL_na));

  if (info->display_name)
    gperl_hv_take_sv_s (hv, "display_name", newSVGChar (info->display_name));

  if (info->mime_type)
    gperl_hv_take_sv_s (hv, "mime_type", newSVGChar (info->mime_type));

  if (info->applications)
    gperl_hv_take_sv_s (hv, "applications", gtk2perl_sv_from_strv (info->applications));

  if (info->groups)
    gperl_hv_take_sv_s (hv, "groups", gtk2perl_sv_from_strv (info->groups));

  gperl_hv_take_sv_s (hv, "age", newSViv (info->age));

  return newRV_noinc ((SV *) hv);
}

static GtkRecentFilterInfo *
SvGtkRecentFilterInfo (SV *sv)
{
  HV *hv;
  SV **svp;
  GtkRecentFilterInfo *info;

  if (!gperl_sv_is_hash_ref (sv))
    croak ("invalid recent filter info - expecting a hash reference");

  hv = (HV *) SvRV (sv);
  info = gperl_alloc_temp (sizeof (GtkRecentFilterInfo));

  if ((svp = hv_fetch (hv, "contains", 8, 0)))
    info->contains = SvGtkRecentFilterFlags (*svp);

  if ((svp = hv_fetch (hv, "uri", 3, 0)))
    info->uri = SvPV_nolen (*svp);

  if ((svp = hv_fetch (hv, "display_name", 12, 0)))
    info->display_name = SvGChar (*svp);

  if ((svp = hv_fetch (hv, "mime_type", 9, 0)))
    info->mime_type = SvGChar (*svp);

  if ((svp = hv_fetch (hv, "applications", 12, 0)))
    info->applications = gtk2perl_sv_to_strv (*svp);

  if ((svp = hv_fetch (hv, "groups", 6, 0)))
    info->groups = gtk2perl_sv_to_strv (*svp);

  if ((svp = hv_fetch (hv, "age", 3, 0)))
    info->age = SvIV (*svp);

  return info;
}

static gboolean
gtk2perl_recent_filter_func (const GtkRecentFilterInfo *filter_info,
			     gpointer                   user_data)
{
  GPerlCallback *callback = (GPerlCallback *) user_data;
  GValue value = { 0, };
  gboolean retval;
  SV *sv;

  g_value_init (&value, G_TYPE_BOOLEAN);
  sv = newSVGtkRecentFilterInfo (filter_info);

  gperl_callback_invoke (callback, &value, sv);
  retval = g_value_get_boolean (&value);

  SvREFCNT_dec (sv);
  g_value_unset (&value);

  return retval;
}

#line 130 "xs\\GtkRecentFilter.c"
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

#line 272 "xs\\GtkRecentFilter.c"

XS_EUPXS(XS_Gtk2__RecentFilter_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentFilter_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	GtkRecentFilter *	RETVAL;

	RETVAL = gtk_recent_filter_new(/* void */);
	ST(0) = newSVGtkRecentFilter (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__RecentFilter_set_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentFilter_set_name)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "filter, name");
    {
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(0))
;
	const gchar *	name;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	name = (const gchar *)SvPV_nolen (ST(1))
;

	gtk_recent_filter_set_name(filter, name);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentFilter_get_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentFilter_get_name)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "filter");
    {
	const gchar *	RETVAL;
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(0))
;

	RETVAL = gtk_recent_filter_get_name(filter);
	ST(0) = sv_newmortal();
	/* same as newSVGChar(), but not in a function */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__RecentFilter_add_mime_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentFilter_add_mime_type)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "filter, mime_type");
    {
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(0))
;
	const gchar *	mime_type;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	mime_type = (const gchar *)SvPV_nolen (ST(1))
;

	gtk_recent_filter_add_mime_type(filter, mime_type);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentFilter_add_pattern); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentFilter_add_pattern)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "filter, pattern");
    {
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(0))
;
	const gchar *	pattern;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	pattern = (const gchar *)SvPV_nolen (ST(1))
;

	gtk_recent_filter_add_pattern(filter, pattern);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentFilter_add_pixbuf_formats); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentFilter_add_pixbuf_formats)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "filter");
    {
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(0))
;

	gtk_recent_filter_add_pixbuf_formats(filter);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentFilter_add_application); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentFilter_add_application)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "filter, application");
    {
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(0))
;
	const gchar *	application;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	application = (const gchar *)SvPV_nolen (ST(1))
;

	gtk_recent_filter_add_application(filter, application);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentFilter_add_group); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentFilter_add_group)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "filter, group");
    {
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(0))
;
	const gchar *	group;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	group = (const gchar *)SvPV_nolen (ST(1))
;

	gtk_recent_filter_add_group(filter, group);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentFilter_add_age); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentFilter_add_age)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "filter, days");
    {
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(0))
;
	gint	days = (gint)SvIV(ST(1))
;

	gtk_recent_filter_add_age(filter, days);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentFilter_add_custom); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentFilter_add_custom)
{
    dVAR; dXSARGS;
    if (items < 3 || items > 4)
       croak_xs_usage(cv,  "filter, needed, func, data=NULL");
    {
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(0))
;
	GtkRecentFilterFlags	needed = SvGtkRecentFilterFlags (ST(1))
;
	SV *	func = ST(2)
;
	SV *	data;
#line 156 "xs\\\\GtkRecentFilter.xs"
        GType param_types[1];
	GPerlCallback *callback;
#line 473 "xs\\GtkRecentFilter.c"

	if (items < 4)
	    data = NULL;
	else {
	    data = ST(3)
;
	}
#line 159 "xs\\\\GtkRecentFilter.xs"
        param_types[0] = GPERL_TYPE_SV;
	callback = gperl_callback_new (func, data, 1, param_types, G_TYPE_BOOLEAN);
	gtk_recent_filter_add_custom (filter, needed,
				      gtk2perl_recent_filter_func, callback,
				      (GDestroyNotify) gperl_callback_destroy);
#line 487 "xs\\GtkRecentFilter.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__RecentFilter_get_needed); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentFilter_get_needed)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "filter");
    {
	GtkRecentFilterFlags	RETVAL;
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(0))
;

	RETVAL = gtk_recent_filter_get_needed(filter);
	ST(0) = newSVGtkRecentFilterFlags (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__RecentFilter_filter); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__RecentFilter_filter)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "filter, filter_info");
    {
	GtkRecentFilter *	filter = SvGtkRecentFilter (ST(0))
;
	SV *	filter_info = ST(1)
;
	gboolean	RETVAL;

	RETVAL = gtk_recent_filter_filter(filter, SvGtkRecentFilterInfo (filter_info));
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__RecentFilter); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__RecentFilter)
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

        newXS("Gtk2::RecentFilter::new", XS_Gtk2__RecentFilter_new, file);
        newXS("Gtk2::RecentFilter::set_name", XS_Gtk2__RecentFilter_set_name, file);
        newXS("Gtk2::RecentFilter::get_name", XS_Gtk2__RecentFilter_get_name, file);
        newXS("Gtk2::RecentFilter::add_mime_type", XS_Gtk2__RecentFilter_add_mime_type, file);
        newXS("Gtk2::RecentFilter::add_pattern", XS_Gtk2__RecentFilter_add_pattern, file);
        newXS("Gtk2::RecentFilter::add_pixbuf_formats", XS_Gtk2__RecentFilter_add_pixbuf_formats, file);
        newXS("Gtk2::RecentFilter::add_application", XS_Gtk2__RecentFilter_add_application, file);
        newXS("Gtk2::RecentFilter::add_group", XS_Gtk2__RecentFilter_add_group, file);
        newXS("Gtk2::RecentFilter::add_age", XS_Gtk2__RecentFilter_add_age, file);
        newXS("Gtk2::RecentFilter::add_custom", XS_Gtk2__RecentFilter_add_custom, file);
        newXS("Gtk2::RecentFilter::get_needed", XS_Gtk2__RecentFilter_get_needed, file);
        newXS("Gtk2::RecentFilter::filter", XS_Gtk2__RecentFilter_filter, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

