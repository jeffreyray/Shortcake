/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkCalendar.xs. Do not edit this file, edit GtkCalendar.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkCalendar.xs"
/*
 * Copyright (c) 2003 by the gtk2-perl team (see the file AUTHORS)
 *
 * Licensed under the LGPL, see LICENSE file for more information.
 *
 * $Id$
 */

#include "gtk2perl.h"

#if GTK_CHECK_VERSION (2, 14, 0)

static GPerlCallback *
gtk2perl_calendar_detail_func_create (SV * func, SV * data)
{
	GType param_types [4];
	param_types[0] = GTK_TYPE_CALENDAR;
	param_types[1] = G_TYPE_UINT;
	param_types[2] = G_TYPE_UINT;
	param_types[3] = G_TYPE_UINT;
	return gperl_callback_new (func, data, G_N_ELEMENTS (param_types),
				   param_types, G_TYPE_STRING);
}

static gchar *
gtk2perl_calendar_detail_func (GtkCalendar *calendar,
			       guint year,
			       guint month,
			       guint day,
			       gpointer user_data)
{
	GPerlCallback * callback = (GPerlCallback*)user_data;
	GValue value = {0,};
	gchar * retval;

	g_value_init (&value, callback->return_type);
	gperl_callback_invoke (callback, &value, calendar, year, month, day);
	/* caller owns return value */
	retval = g_value_dup_string (&value);
	g_value_unset (&value);

	return retval;
}

#endif /* 2.14 */

#line 57 "xs\\GtkCalendar.c"
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

#line 199 "xs\\GtkCalendar.c"

XS_EUPXS(XS_Gtk2__Calendar_num_marked_dates); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_num_marked_dates)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 1)
       croak_xs_usage(cv,  "cal");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	GtkCalendar*	cal = SvGtkCalendar (ST(0))
;
#line 82 "xs\\\\GtkCalendar.xs"
	switch (ix) {
	    case 0:
		PUSHs (sv_2mortal (newSViv (cal->num_marked_dates)));
		break;
 	    case 1:
		{
		int i;
		EXTEND (SP, 31);
		for (i = 0; i < 31; i++) {
			PUSHs (sv_2mortal (newSViv (cal->marked_date[i])));
		}
		}
		break;
	    case 2:
		PUSHs (sv_2mortal (newSViv (cal->year)));
		break;
	    case 3:
		PUSHs (sv_2mortal (newSViv (cal->month)));
		break;
	    case 4:
		PUSHs (sv_2mortal (newSViv (cal->selected_day)));
		break;
	    default:
		g_assert_not_reached ();
	}
#line 239 "xs\\GtkCalendar.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__Calendar_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	GtkWidget *	RETVAL;

	RETVAL = gtk_calendar_new(/*void*/);
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Calendar_select_month); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_select_month)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "calendar, month, year");
    {
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;
	guint	month = (guint)SvUV(ST(1))
;
	guint	year = (guint)SvUV(ST(2))
;
	gboolean	RETVAL;

	RETVAL = gtk_calendar_select_month(calendar, month, year);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Calendar_select_day); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_select_day)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "calendar, day");
    {
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;
	guint	day = (guint)SvUV(ST(1))
;

	gtk_calendar_select_day(calendar, day);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Calendar_mark_day); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_mark_day)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "calendar, day");
    {
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;
	guint	day = (guint)SvUV(ST(1))
;
	gboolean	RETVAL;

	RETVAL = gtk_calendar_mark_day(calendar, day);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Calendar_unmark_day); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_unmark_day)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "calendar, day");
    {
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;
	guint	day = (guint)SvUV(ST(1))
;
	gboolean	RETVAL;

	RETVAL = gtk_calendar_unmark_day(calendar, day);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Calendar_clear_marks); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_clear_marks)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "calendar");
    {
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;

	gtk_calendar_clear_marks(calendar);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Calendar_set_display_options); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_set_display_options)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 2)
       croak_xs_usage(cv,  "calendar, flags");
    {
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;
	GtkCalendarDisplayOptions	flags = SvGtkCalendarDisplayOptions (ST(1))
;
#line 157 "xs\\\\GtkCalendar.xs"
#if GTK_CHECK_VERSION(2,4,0)
	gtk_calendar_set_display_options (calendar, flags);
#else
	gtk_calendar_display_options (calendar, flags);
#endif
#line 380 "xs\\GtkCalendar.c"
#line 163 "xs\\\\GtkCalendar.xs"
	PERL_UNUSED_VAR (ix);
#line 383 "xs\\GtkCalendar.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Calendar_get_display_options); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_get_display_options)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "calendar");
    {
	GtkCalendarDisplayOptions	RETVAL;
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;
#line 168 "xs\\\\GtkCalendar.xs"
#if GTK_CHECK_VERSION(2,4,0)
	RETVAL = gtk_calendar_get_display_options (calendar);
#else
	RETVAL = calendar->display_flags;
#endif
#line 405 "xs\\GtkCalendar.c"
	ST(0) = newSVGtkCalendarDisplayOptions (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Calendar_get_date); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_get_date)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "calendar");
    {
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;
	guint	year;
	guint	month;
	guint	day;

	gtk_calendar_get_date(calendar, &year, &month, &day);
	XSprePUSH;	EXTEND(SP,3);
	PUSHs(sv_newmortal());
	sv_setuv(ST(0), (UV)year);
	PUSHs(sv_newmortal());
	sv_setuv(ST(1), (UV)month);
	PUSHs(sv_newmortal());
	sv_setuv(ST(2), (UV)day);
    }
    XSRETURN(3);
}


XS_EUPXS(XS_Gtk2__Calendar_freeze); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_freeze)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "calendar");
    {
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;

	gtk_calendar_freeze(calendar);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Calendar_thaw); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_thaw)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "calendar");
    {
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;

	gtk_calendar_thaw(calendar);
    }
    XSRETURN_EMPTY;
}

#if GTK_CHECK_VERSION (2, 14, 0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__Calendar_set_detail_func); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_set_detail_func)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "calendar, func, data=NULL");
    {
#line 195 "xs\\\\GtkCalendar.xs"
	GPerlCallback * callback;
#line 483 "xs\\GtkCalendar.c"
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;
	SV *	func = ST(1)
;
	SV *	data;

	if (items < 3)
	    data = NULL;
	else {
	    data = ST(2)
;
	}
#line 197 "xs\\\\GtkCalendar.xs"
	callback = gtk2perl_calendar_detail_func_create (func, data);
	gtk_calendar_set_detail_func (calendar,
				      gtk2perl_calendar_detail_func,
				      callback,
				      (GDestroyNotify) gperl_callback_destroy);
#line 502 "xs\\GtkCalendar.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Calendar_get_detail_width_chars); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_get_detail_width_chars)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "calendar");
    {
	gint	RETVAL;
	dXSTARG;
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;

	RETVAL = gtk_calendar_get_detail_width_chars(calendar);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Calendar_set_detail_width_chars); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_set_detail_width_chars)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "calendar, chars");
    {
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;
	gint	chars = (gint)SvIV(ST(1))
;

	gtk_calendar_set_detail_width_chars(calendar, chars);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Calendar_get_detail_height_rows); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_get_detail_height_rows)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "calendar");
    {
	gint	RETVAL;
	dXSTARG;
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;

	RETVAL = gtk_calendar_get_detail_height_rows(calendar);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Calendar_set_detail_height_rows); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Calendar_set_detail_height_rows)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "calendar, rows");
    {
	GtkCalendar *	calendar = SvGtkCalendar (ST(0))
;
	gint	rows = (gint)SvIV(ST(1))
;

	gtk_calendar_set_detail_height_rows(calendar, rows);
    }
    XSRETURN_EMPTY;
}

#endif /* 2.14 */
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__Calendar); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__Calendar)
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

        cv = newXS("Gtk2::Calendar::month", XS_Gtk2__Calendar_num_marked_dates, file);
        XSANY.any_i32 = 3;
        cv = newXS("Gtk2::Calendar::num_marked_dates", XS_Gtk2__Calendar_num_marked_dates, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::Calendar::selected_day", XS_Gtk2__Calendar_num_marked_dates, file);
        XSANY.any_i32 = 4;
        cv = newXS("Gtk2::Calendar::year", XS_Gtk2__Calendar_num_marked_dates, file);
        XSANY.any_i32 = 2;
        cv = newXS("Gtk2::Calendar::marked_date", XS_Gtk2__Calendar_num_marked_dates, file);
        XSANY.any_i32 = 1;
        newXS("Gtk2::Calendar::new", XS_Gtk2__Calendar_new, file);
        newXS("Gtk2::Calendar::select_month", XS_Gtk2__Calendar_select_month, file);
        newXS("Gtk2::Calendar::select_day", XS_Gtk2__Calendar_select_day, file);
        newXS("Gtk2::Calendar::mark_day", XS_Gtk2__Calendar_mark_day, file);
        newXS("Gtk2::Calendar::unmark_day", XS_Gtk2__Calendar_unmark_day, file);
        newXS("Gtk2::Calendar::clear_marks", XS_Gtk2__Calendar_clear_marks, file);
        cv = newXS("Gtk2::Calendar::display_options", XS_Gtk2__Calendar_set_display_options, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::Calendar::set_display_options", XS_Gtk2__Calendar_set_display_options, file);
        XSANY.any_i32 = 0;
        newXS("Gtk2::Calendar::get_display_options", XS_Gtk2__Calendar_get_display_options, file);
        newXS("Gtk2::Calendar::get_date", XS_Gtk2__Calendar_get_date, file);
        newXS("Gtk2::Calendar::freeze", XS_Gtk2__Calendar_freeze, file);
        newXS("Gtk2::Calendar::thaw", XS_Gtk2__Calendar_thaw, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::Calendar::set_detail_func", XS_Gtk2__Calendar_set_detail_func, file);
        newXS("Gtk2::Calendar::get_detail_width_chars", XS_Gtk2__Calendar_get_detail_width_chars, file);
        newXS("Gtk2::Calendar::set_detail_width_chars", XS_Gtk2__Calendar_set_detail_width_chars, file);
        newXS("Gtk2::Calendar::get_detail_height_rows", XS_Gtk2__Calendar_get_detail_height_rows, file);
        newXS("Gtk2::Calendar::set_detail_height_rows", XS_Gtk2__Calendar_set_detail_height_rows, file);
#endif
    }

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#line 642 "xs\\GtkCalendar.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
