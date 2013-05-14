/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkBuilder.xs. Do not edit this file, edit GtkBuilder.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkBuilder.xs"
/*
 * Copyright (c) 2007, 2012 by the gtk2-perl team (see the file AUTHORS)
 *
 * Licensed under the LGPL, see LICENSE file for more information.
 *
 * $Id$
 */

#include "gtk2perl.h"

/* This doesn't belong here.  But currently, this is the only place a GType for
 * GConnectFlags is needed, so adding extra API to Glib doesn't seem justified.
 */
static GType
gtk2perl_connect_flags_get_type (void)
{
	static GType etype = 0;
	if (etype == 0) {
		static const GFlagsValue values[] = {
			{ G_CONNECT_AFTER, "G_CONNECT_AFTER", "after" },
			{ G_CONNECT_SWAPPED, "G_CONNECT_SWAPPED", "swapped" },
			{ 0, NULL, NULL }
		};
		/* This is actually a race condition, but I don't think it
		 * matters too much in this case. */
		etype = g_type_from_name ("GConnectFlags");
		if (etype == 0) {
			etype = g_flags_register_static ("GConnectFlags", values);
		}
	}
	return etype;
}

static GPerlCallback *
gtk2perl_builder_connect_func_create (SV *func, SV *data)
{
	GType param_types[] = {
		GTK_TYPE_BUILDER,
		G_TYPE_OBJECT,
		G_TYPE_STRING,
		G_TYPE_STRING,
		G_TYPE_OBJECT,
		gtk2perl_connect_flags_get_type ()
	};
	return gperl_callback_new (func, data,
	                           G_N_ELEMENTS (param_types),
	                           param_types,
	                           G_TYPE_NONE);
}

static void
gtk2perl_builder_connect_func (GtkBuilder    *builder,
			       GObject       *object,
			       const gchar   *signal_name,
			       const gchar   *handler_name,
			       GObject       *connect_object,
			       GConnectFlags  flags,
			       gpointer       user_data)
{
	gperl_callback_invoke ((GPerlCallback *) user_data,
			       NULL,
	                       builder,
			       object,
			       signal_name,
			       handler_name,
			       connect_object,
			       flags);
}

#line 80 "xs\\GtkBuilder.c"
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

#line 222 "xs\\GtkBuilder.c"

XS_EUPXS(XS_Gtk2__Builder_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Builder_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	GtkBuilder_noinc *	RETVAL;

	RETVAL = gtk_builder_new(/* void */);
	ST(0) = newSVGtkBuilder_noinc (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Builder_add_from_file); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Builder_add_from_file)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "builder, filename");
    {
#line 88 "xs\\\\GtkBuilder.xs"
	GError *error = NULL;
#line 250 "xs\\GtkBuilder.c"
	guint	RETVAL;
	dXSTARG;
	GtkBuilder *	builder = SvGtkBuilder (ST(0))
;
	GPerlFilename	filename = (GPerlFilename) gperl_filename_from_sv (ST(1))
;
#line 90 "xs\\\\GtkBuilder.xs"
	RETVAL = gtk_builder_add_from_file (builder, filename, &error);
	if (error)
		gperl_croak_gerror (NULL, error);
#line 261 "xs\\GtkBuilder.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Builder_add_from_string); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Builder_add_from_string)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "builder, buffer");
    {
#line 101 "xs\\\\GtkBuilder.xs"
	gsize length;
	GError *error = NULL;
#line 278 "xs\\GtkBuilder.c"
	guint	RETVAL;
	dXSTARG;
	GtkBuilder *	builder = SvGtkBuilder (ST(0))
;
	const gchar *	buffer;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	buffer = (const gchar *)SvPV_nolen (ST(1))
;
#line 104 "xs\\\\GtkBuilder.xs"
	length = sv_len (ST (1));
	RETVAL = gtk_builder_add_from_string (builder, buffer, length, &error);
	if (error)
		gperl_croak_gerror (NULL, error);
#line 294 "xs\\GtkBuilder.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Builder_get_object); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Builder_get_object)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "builder, name");
    {
	GObject *	RETVAL;
	GtkBuilder *	builder = SvGtkBuilder (ST(0))
;
	const gchar *	name;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	name = (const gchar *)SvPV_nolen (ST(1))
;

	RETVAL = gtk_builder_get_object(builder, name);
	ST(0) = newSVGObject (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Builder_get_objects); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Builder_get_objects)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "builder");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 117 "xs\\\\GtkBuilder.xs"
	GSList *list, *i;
#line 337 "xs\\GtkBuilder.c"
	GtkBuilder *	builder = SvGtkBuilder (ST(0))
;
#line 119 "xs\\\\GtkBuilder.xs"
	list = gtk_builder_get_objects (builder);
	for (i = list; i != NULL; i = i->next) {
		XPUSHs (sv_2mortal (newSVGObject (i->data)));
	}
	g_slist_free (list);
#line 346 "xs\\GtkBuilder.c"
	PUTBACK;
	return;
    }
}

#if 0 /* evil hack to convince Glib::GenPod to output docs for connect_signals */
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__Builder_connect_signals); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Builder_connect_signals)
{
    dVAR; dXSARGS;
    if (items < 1)
       croak_xs_usage(cv,  "builder, ...");
    {
	GtkBuilder *	builder = SvGtkBuilder (ST(0))
;

	gtk_builder_connect_signals(builder);
    }
    XSRETURN_EMPTY;
}

#endif /* evil hack */

XS_EUPXS(XS_Gtk2__Builder_connect_signals_full); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Builder_connect_signals_full)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "builder, func, user_data=NULL");
    {
#line 168 "xs\\\\GtkBuilder.xs"
	GPerlCallback *callback;
#line 382 "xs\\GtkBuilder.c"
	GtkBuilder *	builder = SvGtkBuilder (ST(0))
;
	SV *	func = ST(1)
;
	SV *	user_data;

	if (items < 3)
	    user_data = NULL;
	else {
	    user_data = ST(2)
;
	}
#line 170 "xs\\\\GtkBuilder.xs"
	callback = gtk2perl_builder_connect_func_create (func, user_data);
    	gtk_builder_connect_signals_full (
		builder,
		gtk2perl_builder_connect_func,
		callback);
	gperl_callback_destroy (callback);
#line 402 "xs\\GtkBuilder.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Builder_set_translation_domain); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Builder_set_translation_domain)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "builder, domain");
    {
	GtkBuilder *	builder = SvGtkBuilder (ST(0))
;
	const gchar_ornull *	domain;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		domain = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		domain = NULL;
	}
;

	gtk_builder_set_translation_domain(builder, domain);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Builder_get_translation_domain); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Builder_get_translation_domain)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "builder");
    {
	const gchar_ornull *	RETVAL;
	GtkBuilder *	builder = SvGtkBuilder (ST(0))
;

	RETVAL = gtk_builder_get_translation_domain(builder);
	ST(0) = sv_newmortal();
	/* newSVGChar() allows NULL, but T_GCHAR does not. allow NULL. */
	if (RETVAL) {
		sv_setpv ((SV*)ST(0), RETVAL);
		SvUTF8_on (ST(0));
	} else {
		SvSetSV (ST(0), &PL_sv_undef);
	}
    }
    XSRETURN(1);
}

#if GTK_CHECK_VERSION (2, 14, 0)
#define XSubPPtmpAAAB 1


XS_EUPXS(XS_Gtk2__Builder_add_objects_from_file); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Builder_add_objects_from_file)
{
    dVAR; dXSARGS;
    if (items < 3)
       croak_xs_usage(cv,  "builder, filename, first_object_id, ...");
    {
#line 194 "xs\\\\GtkBuilder.xs"
	gchar **object_ids = NULL;
	GError *error = NULL;
	int i;
#line 473 "xs\\GtkBuilder.c"
	guint	RETVAL;
	dXSTARG;
	GtkBuilder *	builder = SvGtkBuilder (ST(0))
;
	const gchar *	filename;
	gchar *	first_object_id;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	filename = (const gchar *)SvPV_nolen (ST(1))
;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(2));
	first_object_id = (gchar *)SvPV_nolen (ST(2))
;
#line 198 "xs\\\\GtkBuilder.xs"
#define FIRST_ITEM 2
	object_ids = g_new0 (gchar *, items - FIRST_ITEM + 1); /* NULL-terminate */
	object_ids[0] = first_object_id;
	for (i = FIRST_ITEM + 1; i < items; i++) {
		object_ids[i - FIRST_ITEM] = SvGChar (ST (i));
	}
	RETVAL = gtk_builder_add_objects_from_file (
	       	   builder, filename, object_ids, &error);
	if (!RETVAL) {
		gperl_croak_gerror (NULL, error);
	}
	g_free (object_ids);
#undef FIRST_ITEM
#line 504 "xs\\GtkBuilder.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Builder_add_objects_from_string); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Builder_add_objects_from_string)
{
    dVAR; dXSARGS;
    if (items < 3)
       croak_xs_usage(cv,  "builder, buffer, first_object_id, ...");
    {
#line 218 "xs\\\\GtkBuilder.xs"
	gchar **object_ids = NULL;
	GError *error = NULL;
	int i;
#line 522 "xs\\GtkBuilder.c"
	guint	RETVAL;
	dXSTARG;
	GtkBuilder *	builder = SvGtkBuilder (ST(0))
;
	const gchar *	buffer;
	gchar *	first_object_id;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	buffer = (const gchar *)SvPV_nolen (ST(1))
;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(2));
	first_object_id = (gchar *)SvPV_nolen (ST(2))
;
#line 222 "xs\\\\GtkBuilder.xs"
#define FIRST_ITEM 2
	object_ids = g_new0 (gchar *, items - FIRST_ITEM + 1); /* NULL-terminate */
	object_ids[0] = first_object_id;
	for (i = FIRST_ITEM + 1; i < items; i++) {
		object_ids[i - FIRST_ITEM] = SvGChar (ST (i));
	}
	RETVAL = gtk_builder_add_objects_from_string (
	       	   builder, buffer, sv_len (ST (1)), object_ids, &error);
	if (!RETVAL) {
		gperl_croak_gerror (NULL, error);
	}
	g_free (object_ids);
#undef FIRST_ITEM
#line 553 "xs\\GtkBuilder.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

#endif
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__Builder); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__Builder)
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

        newXS("Gtk2::Builder::new", XS_Gtk2__Builder_new, file);
        newXS("Gtk2::Builder::add_from_file", XS_Gtk2__Builder_add_from_file, file);
        newXS("Gtk2::Builder::add_from_string", XS_Gtk2__Builder_add_from_string, file);
        newXS("Gtk2::Builder::get_object", XS_Gtk2__Builder_get_object, file);
        newXS("Gtk2::Builder::get_objects", XS_Gtk2__Builder_get_objects, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::Builder::connect_signals", XS_Gtk2__Builder_connect_signals, file);
#endif
        newXS("Gtk2::Builder::connect_signals_full", XS_Gtk2__Builder_connect_signals_full, file);
        newXS("Gtk2::Builder::set_translation_domain", XS_Gtk2__Builder_set_translation_domain, file);
        newXS("Gtk2::Builder::get_translation_domain", XS_Gtk2__Builder_get_translation_domain, file);
#if XSubPPtmpAAAB
        newXS("Gtk2::Builder::add_objects_from_file", XS_Gtk2__Builder_add_objects_from_file, file);
        newXS("Gtk2::Builder::add_objects_from_string", XS_Gtk2__Builder_add_objects_from_string, file);
#endif

    /* Initialisation Section */

#line 73 "xs\\\\GtkBuilder.xs"
	gperl_register_fundamental (gtk2perl_connect_flags_get_type (),
	                            "Glib::ConnectFlags");
	gperl_register_error_domain (GTK_BUILDER_ERROR,
				     GTK_TYPE_BUILDER_ERROR,
				     "Gtk2::Builder::Error");

#if XSubPPtmpAAAA
#endif
#if XSubPPtmpAAAB
#endif
#line 609 "xs\\GtkBuilder.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
