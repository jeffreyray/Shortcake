/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkPrintOperation.xs. Do not edit this file, edit GtkPrintOperation.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkPrintOperation.xs"
/*
 * Copyright (c) 2006 by the gtk2-perl team (see the file AUTHORS)
 *
 * Licensed under the LGPL, see LICENSE file for more information.
 *
 * $Id$
 */

#include "gtk2perl.h"

static GPerlCallback *
gtk2perl_page_setup_done_func_create (SV * func, SV * data)
{
	GType param_types [1];
	param_types[0] = GTK_TYPE_PAGE_SETUP;
	return gperl_callback_new (func, data, G_N_ELEMENTS (param_types),
				   param_types, 0);
}

static void
gtk2perl_page_setup_done_func (GtkPageSetup *page_setup, gpointer data)
{
	gperl_callback_invoke ((GPerlCallback *) data, NULL, page_setup);
	/* The callback is always called exactly once, so free it now. */
	gperl_callback_destroy ((GPerlCallback *) data);
}

#line 38 "xs\\GtkPrintOperation.c"
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

#line 180 "xs\\GtkPrintOperation.c"

XS_EUPXS(XS_Gtk2__PrintOperation_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	GtkPrintOperation_noinc *	RETVAL;

	RETVAL = gtk_print_operation_new(/* void */);
	ST(0) = newSVGtkPrintOperation_noinc (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_default_page_setup); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_default_page_setup)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, default_page_setup");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	GtkPageSetup_ornull *	default_page_setup = SvGtkPageSetup_ornull (ST(1))
;

	gtk_print_operation_set_default_page_setup(op, default_page_setup);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_get_default_page_setup); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_get_default_page_setup)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "op");
    {
	GtkPageSetup_ornull *	RETVAL;
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;

	RETVAL = gtk_print_operation_get_default_page_setup(op);
	ST(0) = newSVGtkPageSetup_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_print_settings); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_print_settings)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, print_settings");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	GtkPrintSettings_ornull *	print_settings = SvGtkPrintSettings_ornull (ST(1))
;

	gtk_print_operation_set_print_settings(op, print_settings);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_get_print_settings); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_get_print_settings)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "op");
    {
	GtkPrintSettings_ornull *	RETVAL;
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;

	RETVAL = gtk_print_operation_get_print_settings(op);
	ST(0) = newSVGtkPrintSettings_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_job_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_job_name)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, job_name");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	const gchar *	job_name;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	job_name = (const gchar *)SvPV_nolen (ST(1))
;

	gtk_print_operation_set_job_name(op, job_name);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_n_pages); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_n_pages)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, n_pages");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	gint	n_pages = (gint)SvIV(ST(1))
;

	gtk_print_operation_set_n_pages(op, n_pages);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_current_page); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_current_page)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, current_page");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	gint	current_page = (gint)SvIV(ST(1))
;

	gtk_print_operation_set_current_page(op, current_page);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_use_full_page); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_use_full_page)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, full_page");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	gboolean	full_page = (bool)SvTRUE(ST(1))
;

	gtk_print_operation_set_use_full_page(op, full_page);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_unit); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_unit)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, unit");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	GtkUnit	unit = SvGtkUnit (ST(1))
;

	gtk_print_operation_set_unit(op, unit);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_export_filename); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_export_filename)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, filename");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	const gchar *	filename;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	filename = (const gchar *)SvPV_nolen (ST(1))
;

	gtk_print_operation_set_export_filename(op, filename);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_track_print_status); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_track_print_status)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, track_status");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	gboolean	track_status = (bool)SvTRUE(ST(1))
;

	gtk_print_operation_set_track_print_status(op, track_status);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_show_progress); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_show_progress)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, show_progress");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	gboolean	show_progress = (bool)SvTRUE(ST(1))
;

	gtk_print_operation_set_show_progress(op, show_progress);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_allow_async); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_allow_async)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, allow_async");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	gboolean	allow_async = (bool)SvTRUE(ST(1))
;

	gtk_print_operation_set_allow_async(op, allow_async);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_custom_tab_label); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_custom_tab_label)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, label");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	const gchar *	label;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	label = (const gchar *)SvPV_nolen (ST(1))
;

	gtk_print_operation_set_custom_tab_label(op, label);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_run); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_run)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "op, action, parent");
    {
#line 69 "xs\\\\GtkPrintOperation.xs"
	GError *error = NULL;
#line 474 "xs\\GtkPrintOperation.c"
	GtkPrintOperationResult	RETVAL;
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	GtkPrintOperationAction	action = SvGtkPrintOperationAction (ST(1))
;
	GtkWindow_ornull *	parent = SvGtkWindow_ornull (ST(2))
;
#line 71 "xs\\\\GtkPrintOperation.xs"
	RETVAL = gtk_print_operation_run (op, action, parent, &error);
	if (error)
		gperl_croak_gerror (NULL, error);
#line 486 "xs\\GtkPrintOperation.c"
	ST(0) = newSVGtkPrintOperationResult (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__PrintOperation_get_error); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_get_error)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "op");
    {
#line 82 "xs\\\\GtkPrintOperation.xs"
	GError *error = NULL;
#line 503 "xs\\GtkPrintOperation.c"
	SV *	RETVAL;
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
#line 84 "xs\\\\GtkPrintOperation.xs"
	gtk_print_operation_get_error (op, &error);
	RETVAL = gperl_sv_from_gerror (error);
#line 510 "xs\\GtkPrintOperation.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__PrintOperation_get_status); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_get_status)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "op");
    {
	GtkPrintStatus	RETVAL;
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;

	RETVAL = gtk_print_operation_get_status(op);
	ST(0) = newSVGtkPrintStatus (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__PrintOperation_get_status_string); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_get_status_string)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "op");
    {
	const gchar *	RETVAL;
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;

	RETVAL = gtk_print_operation_get_status_string(op);
	ST(0) = sv_newmortal();
	/* same as newSVGChar(), but not in a function */
	sv_setpv ((SV*)ST(0), RETVAL);
	SvUTF8_on (ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__PrintOperation_is_finished); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_is_finished)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "op");
    {
	gboolean	RETVAL;
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;

	RETVAL = gtk_print_operation_is_finished(op);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__PrintOperation_cancel); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_cancel)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "op");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;

	gtk_print_operation_cancel(op);
    }
    XSRETURN_EMPTY;
}

#if GTK_CHECK_VERSION (2, 16, 0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__PrintOperation_draw_page_finish); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_draw_page_finish)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "op");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;

	gtk_print_operation_draw_page_finish(op);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_defer_drawing); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_defer_drawing)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "op");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;

	gtk_print_operation_set_defer_drawing(op);
    }
    XSRETURN_EMPTY;
}

#endif /* 2.16 */
#if GTK_CHECK_VERSION (2, 18, 0)
#define XSubPPtmpAAAB 1


XS_EUPXS(XS_Gtk2__PrintOperation_set_embed_page_setup); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_embed_page_setup)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, embed");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	gboolean	embed = (bool)SvTRUE(ST(1))
;

	gtk_print_operation_set_embed_page_setup(op, embed);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_get_embed_page_setup); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_get_embed_page_setup)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "op");
    {
	gboolean	RETVAL;
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;

	RETVAL = gtk_print_operation_get_embed_page_setup(op);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_support_selection); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_support_selection)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, support_selection");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	gboolean	support_selection = (bool)SvTRUE(ST(1))
;

	gtk_print_operation_set_support_selection(op, support_selection);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_get_support_selection); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_get_support_selection)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "op");
    {
	gboolean	RETVAL;
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;

	RETVAL = gtk_print_operation_get_support_selection(op);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__PrintOperation_set_has_selection); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_set_has_selection)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "op, has_selection");
    {
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;
	gboolean	has_selection = (bool)SvTRUE(ST(1))
;

	gtk_print_operation_set_has_selection(op, has_selection);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__PrintOperation_get_has_selection); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_get_has_selection)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "op");
    {
	gboolean	RETVAL;
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;

	RETVAL = gtk_print_operation_get_has_selection(op);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__PrintOperation_get_n_pages_to_print); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__PrintOperation_get_n_pages_to_print)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "op");
    {
	gint	RETVAL;
	dXSTARG;
	GtkPrintOperation *	op = SvGtkPrintOperation (ST(0))
;

	RETVAL = gtk_print_operation_get_n_pages_to_print(op);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

#endif /* 2.18 */

XS_EUPXS(XS_Gtk2__Print_run_page_setup_dialog); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Print_run_page_setup_dialog)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "class, parent, page_setup, settings");
    {
	GtkPageSetup_noinc *	RETVAL;
	GtkWindow_ornull *	parent = SvGtkWindow_ornull (ST(1))
;
	GtkPageSetup_ornull *	page_setup = SvGtkPageSetup_ornull (ST(2))
;
	GtkPrintSettings *	settings = SvGtkPrintSettings (ST(3))
;

	RETVAL = gtk_print_run_page_setup_dialog(parent, page_setup, settings);
	ST(0) = newSVGtkPageSetup_noinc (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Print_run_page_setup_dialog_async); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Print_run_page_setup_dialog_async)
{
    dVAR; dXSARGS;
    if (items < 5 || items > 6)
       croak_xs_usage(cv,  "class, parent, page_setup, settings, func, data=NULL");
    {
#line 154 "xs\\\\GtkPrintOperation.xs"
	GPerlCallback *callback;
#line 795 "xs\\GtkPrintOperation.c"
	GtkWindow_ornull *	parent = SvGtkWindow_ornull (ST(1))
;
	GtkPageSetup_ornull *	page_setup = SvGtkPageSetup_ornull (ST(2))
;
	GtkPrintSettings *	settings = SvGtkPrintSettings (ST(3))
;
	SV *	func = ST(4)
;
	SV *	data;

	if (items < 6)
	    data = NULL;
	else {
	    data = ST(5)
;
	}
#line 156 "xs\\\\GtkPrintOperation.xs"
	callback = gtk2perl_page_setup_done_func_create (func, data);
	gtk_print_run_page_setup_dialog_async (
		parent, page_setup, settings,
		gtk2perl_page_setup_done_func,
		callback);
	/* Since it's always called exactly once, the callback is destroyed
	 * directly in the marshaller. */
#line 820 "xs\\GtkPrintOperation.c"
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__PrintOperation); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__PrintOperation)
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

        newXS("Gtk2::PrintOperation::new", XS_Gtk2__PrintOperation_new, file);
        newXS("Gtk2::PrintOperation::set_default_page_setup", XS_Gtk2__PrintOperation_set_default_page_setup, file);
        newXS("Gtk2::PrintOperation::get_default_page_setup", XS_Gtk2__PrintOperation_get_default_page_setup, file);
        newXS("Gtk2::PrintOperation::set_print_settings", XS_Gtk2__PrintOperation_set_print_settings, file);
        newXS("Gtk2::PrintOperation::get_print_settings", XS_Gtk2__PrintOperation_get_print_settings, file);
        newXS("Gtk2::PrintOperation::set_job_name", XS_Gtk2__PrintOperation_set_job_name, file);
        newXS("Gtk2::PrintOperation::set_n_pages", XS_Gtk2__PrintOperation_set_n_pages, file);
        newXS("Gtk2::PrintOperation::set_current_page", XS_Gtk2__PrintOperation_set_current_page, file);
        newXS("Gtk2::PrintOperation::set_use_full_page", XS_Gtk2__PrintOperation_set_use_full_page, file);
        newXS("Gtk2::PrintOperation::set_unit", XS_Gtk2__PrintOperation_set_unit, file);
        newXS("Gtk2::PrintOperation::set_export_filename", XS_Gtk2__PrintOperation_set_export_filename, file);
        newXS("Gtk2::PrintOperation::set_track_print_status", XS_Gtk2__PrintOperation_set_track_print_status, file);
        newXS("Gtk2::PrintOperation::set_show_progress", XS_Gtk2__PrintOperation_set_show_progress, file);
        newXS("Gtk2::PrintOperation::set_allow_async", XS_Gtk2__PrintOperation_set_allow_async, file);
        newXS("Gtk2::PrintOperation::set_custom_tab_label", XS_Gtk2__PrintOperation_set_custom_tab_label, file);
        newXS("Gtk2::PrintOperation::run", XS_Gtk2__PrintOperation_run, file);
        newXS("Gtk2::PrintOperation::get_error", XS_Gtk2__PrintOperation_get_error, file);
        newXS("Gtk2::PrintOperation::get_status", XS_Gtk2__PrintOperation_get_status, file);
        newXS("Gtk2::PrintOperation::get_status_string", XS_Gtk2__PrintOperation_get_status_string, file);
        newXS("Gtk2::PrintOperation::is_finished", XS_Gtk2__PrintOperation_is_finished, file);
        newXS("Gtk2::PrintOperation::cancel", XS_Gtk2__PrintOperation_cancel, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::PrintOperation::draw_page_finish", XS_Gtk2__PrintOperation_draw_page_finish, file);
        newXS("Gtk2::PrintOperation::set_defer_drawing", XS_Gtk2__PrintOperation_set_defer_drawing, file);
#endif
#if XSubPPtmpAAAB
        newXS("Gtk2::PrintOperation::set_embed_page_setup", XS_Gtk2__PrintOperation_set_embed_page_setup, file);
        newXS("Gtk2::PrintOperation::get_embed_page_setup", XS_Gtk2__PrintOperation_get_embed_page_setup, file);
        newXS("Gtk2::PrintOperation::set_support_selection", XS_Gtk2__PrintOperation_set_support_selection, file);
        newXS("Gtk2::PrintOperation::get_support_selection", XS_Gtk2__PrintOperation_get_support_selection, file);
        newXS("Gtk2::PrintOperation::set_has_selection", XS_Gtk2__PrintOperation_set_has_selection, file);
        newXS("Gtk2::PrintOperation::get_has_selection", XS_Gtk2__PrintOperation_get_has_selection, file);
        newXS("Gtk2::PrintOperation::get_n_pages_to_print", XS_Gtk2__PrintOperation_get_n_pages_to_print, file);
#endif
        newXS("Gtk2::Print::run_page_setup_dialog", XS_Gtk2__Print_run_page_setup_dialog, file);
        newXS("Gtk2::Print::run_page_setup_dialog_async", XS_Gtk2__Print_run_page_setup_dialog_async, file);

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#if XSubPPtmpAAAB
#endif
#line 888 "xs\\GtkPrintOperation.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
