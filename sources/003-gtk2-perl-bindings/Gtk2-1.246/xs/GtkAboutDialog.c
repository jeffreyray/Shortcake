/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkAboutDialog.xs. Do not edit this file, edit GtkAboutDialog.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkAboutDialog.xs"
 /*
 * Copyright (c) 2004-2005, 2010 by the gtk2-perl team (see the file AUTHORS)
 *
 * Licensed under the LGPL, see LICENSE file for more information.
 *
 * $Id$
 */

#include "gtk2perl.h"

#define GETTER(into)							\
	{								\
		if (!(into))						\
			XSRETURN_EMPTY;					\
		for (i = 0; (into)[i] != NULL; i++)			\
			XPUSHs (sv_2mortal (newSVGChar ((into)[i])));	\
	}

#define SETTER(outof)						\
	{							\
		gint num = items - 1;				\
		(outof) = g_new0 (gchar *, num + 1);		\
		for (i = 0; i < num; i++)			\
			(outof)[i] = SvGChar (ST (1 + i));	\
	}

static GPerlCallback *
gtk2perl_about_dialog_activate_link_func_create (SV * func, SV * data)
{
	GType param_types [2];
	param_types[0] = GTK_TYPE_ABOUT_DIALOG;
	param_types[1] = G_TYPE_STRING;
	return gperl_callback_new (func, data, G_N_ELEMENTS (param_types),
				   param_types, 0);
}

static void
gtk2perl_about_dialog_activate_link_func (GtkAboutDialog *about,
                                          const gchar    *link,
                                          gpointer        data)
{
	gperl_callback_invoke ((GPerlCallback*)data, NULL, about, link);
}

#line 55 "xs\\GtkAboutDialog.c"
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

#line 197 "xs\\GtkAboutDialog.c"

XS_EUPXS(XS_Gtk2_show_about_dialog); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2_show_about_dialog)
{
    dVAR; dXSARGS;
    if (items < 3)
       croak_xs_usage(cv,  "class, parent, first_property_name, ...");
    {
#line 81 "xs\\\\GtkAboutDialog.xs"
	static GtkWidget * global_about_dialog = NULL;
	GtkWidget * dialog = NULL;
#line 209 "xs\\GtkAboutDialog.c"
	GtkWindow_ornull *	parent = SvGtkWindow_ornull (ST(1))
;
#line 84 "xs\\\\GtkAboutDialog.xs"
	if (parent)
		dialog = g_object_get_data (G_OBJECT (parent), "gtk-about-dialog");
	else
		dialog = global_about_dialog;
	if (!dialog) {
		int i;

		dialog = gtk_about_dialog_new ();

		g_object_ref (dialog);
		gtk_object_sink (GTK_OBJECT (dialog));

		g_signal_connect (dialog, "delete_event",
				  G_CALLBACK (gtk_widget_hide_on_delete), NULL);

		/* See http://svn.gnome.org/viewcvs/gtk%2B?revision=14919&view=revision .
		 * We can't actually do this fully correctly, because the
		 * license and credits subdialogs are private. */
		g_signal_connect (dialog, "response",
				  G_CALLBACK (gtk_widget_hide), NULL);

		for (i = 2; i < items ; i+=2) {
			GParamSpec * pspec;
			char * name = SvPV_nolen (ST (i));
			SV * sv = ST (i + 1);

			/* Evil swizzling for #345822 */
			if (gtk_major_version > 2 ||
			    (gtk_major_version == 2 && gtk_minor_version >= 12))
			{
				/* map name to program-name. */
				if (strEQ (name, "name")) {
					warn ("Deprecation warning: Use the "
					      "\"program-name\" property instead "
					      "of \"name\"");
					name = "program-name";
				}
			} else {
				/* older gtk+; allow modern code. */
				if (gperl_str_eq (name, "program-name"))
					name = "name";
			}

			pspec = g_object_class_find_property
					(G_OBJECT_GET_CLASS (dialog), name);
			if (! pspec) {
				const char * classname =
					gperl_object_package_from_type
						(G_OBJECT_TYPE (dialog));
				croak ("type %s does not support property '%s'",
				       classname, name);
			} else {
				GValue value = {0, };
				g_value_init (&value,
					      G_PARAM_SPEC_VALUE_TYPE (pspec));
				gperl_value_from_sv (&value, sv);
				g_object_set_property (G_OBJECT (dialog),
						       name, &value);
				g_value_unset (&value);
			}
		}
		if (parent) {
			gtk_window_set_transient_for (
				GTK_WINDOW (dialog), parent);
			gtk_window_set_destroy_with_parent (
				GTK_WINDOW (dialog), TRUE);
			g_object_set_data_full (G_OBJECT (parent),
					       	"gtk-about-dialog",
						dialog, g_object_unref);
		} else {
			global_about_dialog = dialog;
		}
	}
	gtk_window_present (GTK_WINDOW (dialog));
#line 287 "xs\\GtkAboutDialog.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	GtkWidget *	RETVAL;

	RETVAL = gtk_about_dialog_new(/* void */);
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__AboutDialog_get_program_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_program_name)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    {
	const gchar_ornull *	RETVAL;
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
#line 174 "xs\\\\GtkAboutDialog.xs"
	if (ix == 1) {
		warn ("Deprecation warning: use "
		      "Gtk2::AboutDialog::get_program_name instead of "
		      "get_name");
	}
#if GTK_CHECK_VERSION (2, 12, 0)
	RETVAL = gtk_about_dialog_get_program_name (about);
#else
	RETVAL = gtk_about_dialog_get_name (about);
#endif
#line 332 "xs\\GtkAboutDialog.c"
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


XS_EUPXS(XS_Gtk2__AboutDialog_set_program_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_program_name)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 2)
       croak_xs_usage(cv,  "about, name");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
	const gchar_ornull *	name;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		name = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		name = NULL;
	}
;
#line 195 "xs\\\\GtkAboutDialog.xs"
	if (ix == 1) {
		warn ("Deprecation warning: use "
		      "Gtk2::AboutDialog::set_program_name instead of "
		      "set_name");
	}
#if GTK_CHECK_VERSION (2, 12, 0)
	gtk_about_dialog_set_program_name (about, name);
#else
	gtk_about_dialog_set_name (about, name);
#endif
#line 377 "xs\\GtkAboutDialog.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_get_version); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_version)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    {
	const gchar_ornull *	RETVAL;
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;

	RETVAL = gtk_about_dialog_get_version(about);
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


XS_EUPXS(XS_Gtk2__AboutDialog_set_version); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_version)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "about, version");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
	const gchar_ornull *	version;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		version = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		version = NULL;
	}
;

	gtk_about_dialog_set_version(about, version);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_get_copyright); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_copyright)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    {
	const gchar_ornull *	RETVAL;
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;

	RETVAL = gtk_about_dialog_get_copyright(about);
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


XS_EUPXS(XS_Gtk2__AboutDialog_set_copyright); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_copyright)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "about, copyright");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
	const gchar_ornull *	copyright;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		copyright = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		copyright = NULL;
	}
;

	gtk_about_dialog_set_copyright(about, copyright);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_get_comments); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_comments)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    {
	const gchar_ornull *	RETVAL;
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;

	RETVAL = gtk_about_dialog_get_comments(about);
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


XS_EUPXS(XS_Gtk2__AboutDialog_set_comments); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_comments)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "about, comments");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
	const gchar_ornull *	comments;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		comments = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		comments = NULL;
	}
;

	gtk_about_dialog_set_comments(about, comments);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_get_license); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_license)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    {
	const gchar_ornull *	RETVAL;
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;

	RETVAL = gtk_about_dialog_get_license(about);
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


XS_EUPXS(XS_Gtk2__AboutDialog_set_license); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_license)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "about, license");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
	const gchar_ornull *	license;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		license = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		license = NULL;
	}
;

	gtk_about_dialog_set_license(about, license);
    }
    XSRETURN_EMPTY;
}

#if GTK_CHECK_VERSION (2, 8, 0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__AboutDialog_get_wrap_license); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_wrap_license)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    {
	gboolean	RETVAL;
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;

	RETVAL = gtk_about_dialog_get_wrap_license(about);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__AboutDialog_set_wrap_license); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_wrap_license)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "about, wrap_license");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
	gboolean	wrap_license = (bool)SvTRUE(ST(1))
;

	gtk_about_dialog_set_wrap_license(about, wrap_license);
    }
    XSRETURN_EMPTY;
}

#endif

XS_EUPXS(XS_Gtk2__AboutDialog_get_website); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_website)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    {
	const gchar_ornull *	RETVAL;
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;

	RETVAL = gtk_about_dialog_get_website(about);
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


XS_EUPXS(XS_Gtk2__AboutDialog_set_website); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_website)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "about, website");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
	const gchar_ornull *	website;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		website = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		website = NULL;
	}
;

	gtk_about_dialog_set_website(about, website);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_get_website_label); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_website_label)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    {
	const gchar_ornull *	RETVAL;
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;

	RETVAL = gtk_about_dialog_get_website_label(about);
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


XS_EUPXS(XS_Gtk2__AboutDialog_set_website_label); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_website_label)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "about, website_label");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
	const gchar_ornull *	website_label;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		website_label = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		website_label = NULL;
	}
;

	gtk_about_dialog_set_website_label(about, website_label);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_get_authors); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_authors)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 242 "xs\\\\GtkAboutDialog.xs"
	gint     i;
	const gchar * const * authors = NULL;
#line 742 "xs\\GtkAboutDialog.c"
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
#line 245 "xs\\\\GtkAboutDialog.xs"
	authors = gtk_about_dialog_get_authors (about);
	GETTER (authors);
#line 748 "xs\\GtkAboutDialog.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__AboutDialog_set_authors); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_authors)
{
    dVAR; dXSARGS;
    if (items < 2)
       croak_xs_usage(cv,  "about, author1, ...");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
#line 256 "xs\\\\GtkAboutDialog.xs"
	gint    i;
	gchar ** authors;
#line 767 "xs\\GtkAboutDialog.c"
#line 259 "xs\\\\GtkAboutDialog.xs"
	SETTER (authors);
	gtk_about_dialog_set_authors (about, (const gchar **) authors);
	g_free (authors);
#line 772 "xs\\GtkAboutDialog.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_get_documenters); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_documenters)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 267 "xs\\\\GtkAboutDialog.xs"
	gint     i;
	const gchar * const * documenters = NULL;
#line 790 "xs\\GtkAboutDialog.c"
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
#line 270 "xs\\\\GtkAboutDialog.xs"
	documenters = gtk_about_dialog_get_documenters (about);
	GETTER (documenters);
#line 796 "xs\\GtkAboutDialog.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__AboutDialog_set_documenters); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_documenters)
{
    dVAR; dXSARGS;
    if (items < 2)
       croak_xs_usage(cv,  "about, documenter1, ...");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
#line 281 "xs\\\\GtkAboutDialog.xs"
	gint    i;
	gchar ** documenters;
#line 815 "xs\\GtkAboutDialog.c"
#line 284 "xs\\\\GtkAboutDialog.xs"
	SETTER (documenters);
	gtk_about_dialog_set_documenters (about, (const gchar **) documenters);
	g_free (documenters);
#line 820 "xs\\GtkAboutDialog.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_get_artists); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_artists)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 292 "xs\\\\GtkAboutDialog.xs"
	gint     i;
	const gchar * const * artists = NULL;
#line 838 "xs\\GtkAboutDialog.c"
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
#line 295 "xs\\\\GtkAboutDialog.xs"
	artists = gtk_about_dialog_get_artists (about);
	GETTER (artists);
#line 844 "xs\\GtkAboutDialog.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__AboutDialog_set_artists); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_artists)
{
    dVAR; dXSARGS;
    if (items < 2)
       croak_xs_usage(cv,  "about, artist1, ...");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
#line 306 "xs\\\\GtkAboutDialog.xs"
	gint    i;
	gchar ** artists;
#line 863 "xs\\GtkAboutDialog.c"
#line 309 "xs\\\\GtkAboutDialog.xs"
	SETTER (artists);
	gtk_about_dialog_set_artists (about, (const gchar **) artists);
	g_free (artists);
#line 868 "xs\\GtkAboutDialog.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_get_translator_credits); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_translator_credits)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    {
	const gchar_ornull *	RETVAL;
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;

	RETVAL = gtk_about_dialog_get_translator_credits(about);
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


XS_EUPXS(XS_Gtk2__AboutDialog_set_translator_credits); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_translator_credits)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "about, translator_credits");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
	const gchar_ornull *	translator_credits;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		translator_credits = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		translator_credits = NULL;
	}
;

	gtk_about_dialog_set_translator_credits(about, translator_credits);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_get_logo); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_logo)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    {
	GdkPixbuf_ornull *	RETVAL;
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;

	RETVAL = gtk_about_dialog_get_logo(about);
	ST(0) = newSVGdkPixbuf_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__AboutDialog_set_logo); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_logo)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "about, logo");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
	GdkPixbuf_ornull *	logo = SvGdkPixbuf_ornull (ST(1))
;

	gtk_about_dialog_set_logo(about, logo);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_get_logo_icon_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_get_logo_icon_name)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "about");
    {
	const gchar_ornull *	RETVAL;
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;

	RETVAL = gtk_about_dialog_get_logo_icon_name(about);
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


XS_EUPXS(XS_Gtk2__AboutDialog_set_logo_icon_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_logo_icon_name)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "about, icon_name");
    {
	GtkAboutDialog *	about = SvGtkAboutDialog (ST(0))
;
	const gchar_ornull *	icon_name;

	/* same as SvGChar(), but allows undef as NULL */
	if (gperl_sv_is_defined (ST(1))) {
		sv_utf8_upgrade (ST(1));
		icon_name = (const gchar_ornull *)SvPV_nolen (ST(1));
	} else {
		icon_name = NULL;
	}
;

	gtk_about_dialog_set_logo_icon_name(about, icon_name);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_set_email_hook); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_email_hook)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "class, func, data = NULL");
    {
	SV *	func = ST(1)
;
	SV *	data;
#line 331 "xs\\\\GtkAboutDialog.xs"
	GPerlCallback *callback;
#line 1025 "xs\\GtkAboutDialog.c"

	if (items < 3)
	    data = NULL;
	else {
	    data = ST(2)
;
	}
#line 333 "xs\\\\GtkAboutDialog.xs"
	callback = gtk2perl_about_dialog_activate_link_func_create (func, data);
	gtk_about_dialog_set_email_hook (
		(GtkAboutDialogActivateLinkFunc)
		  gtk2perl_about_dialog_activate_link_func,
		callback,
		(GDestroyNotify) gperl_callback_destroy);
#line 1040 "xs\\GtkAboutDialog.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__AboutDialog_set_url_hook); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__AboutDialog_set_url_hook)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "class, func, data = NULL");
    {
	SV *	func = ST(1)
;
	SV *	data;
#line 346 "xs\\\\GtkAboutDialog.xs"
	GPerlCallback *callback;
#line 1058 "xs\\GtkAboutDialog.c"

	if (items < 3)
	    data = NULL;
	else {
	    data = ST(2)
;
	}
#line 348 "xs\\\\GtkAboutDialog.xs"
	callback = gtk2perl_about_dialog_activate_link_func_create (func, data);
	gtk_about_dialog_set_url_hook (
		(GtkAboutDialogActivateLinkFunc)
		  gtk2perl_about_dialog_activate_link_func,
		callback,
		(GDestroyNotify) gperl_callback_destroy);
#line 1073 "xs\\GtkAboutDialog.c"
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__AboutDialog); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__AboutDialog)
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

        newXS("Gtk2::show_about_dialog", XS_Gtk2_show_about_dialog, file);
        newXS("Gtk2::AboutDialog::new", XS_Gtk2__AboutDialog_new, file);
        cv = newXS("Gtk2::AboutDialog::get_name", XS_Gtk2__AboutDialog_get_program_name, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::AboutDialog::get_program_name", XS_Gtk2__AboutDialog_get_program_name, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::AboutDialog::set_program_name", XS_Gtk2__AboutDialog_set_program_name, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::AboutDialog::set_name", XS_Gtk2__AboutDialog_set_program_name, file);
        XSANY.any_i32 = 1;
        newXS("Gtk2::AboutDialog::get_version", XS_Gtk2__AboutDialog_get_version, file);
        newXS("Gtk2::AboutDialog::set_version", XS_Gtk2__AboutDialog_set_version, file);
        newXS("Gtk2::AboutDialog::get_copyright", XS_Gtk2__AboutDialog_get_copyright, file);
        newXS("Gtk2::AboutDialog::set_copyright", XS_Gtk2__AboutDialog_set_copyright, file);
        newXS("Gtk2::AboutDialog::get_comments", XS_Gtk2__AboutDialog_get_comments, file);
        newXS("Gtk2::AboutDialog::set_comments", XS_Gtk2__AboutDialog_set_comments, file);
        newXS("Gtk2::AboutDialog::get_license", XS_Gtk2__AboutDialog_get_license, file);
        newXS("Gtk2::AboutDialog::set_license", XS_Gtk2__AboutDialog_set_license, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::AboutDialog::get_wrap_license", XS_Gtk2__AboutDialog_get_wrap_license, file);
        newXS("Gtk2::AboutDialog::set_wrap_license", XS_Gtk2__AboutDialog_set_wrap_license, file);
#endif
        newXS("Gtk2::AboutDialog::get_website", XS_Gtk2__AboutDialog_get_website, file);
        newXS("Gtk2::AboutDialog::set_website", XS_Gtk2__AboutDialog_set_website, file);
        newXS("Gtk2::AboutDialog::get_website_label", XS_Gtk2__AboutDialog_get_website_label, file);
        newXS("Gtk2::AboutDialog::set_website_label", XS_Gtk2__AboutDialog_set_website_label, file);
        newXS("Gtk2::AboutDialog::get_authors", XS_Gtk2__AboutDialog_get_authors, file);
        newXS("Gtk2::AboutDialog::set_authors", XS_Gtk2__AboutDialog_set_authors, file);
        newXS("Gtk2::AboutDialog::get_documenters", XS_Gtk2__AboutDialog_get_documenters, file);
        newXS("Gtk2::AboutDialog::set_documenters", XS_Gtk2__AboutDialog_set_documenters, file);
        newXS("Gtk2::AboutDialog::get_artists", XS_Gtk2__AboutDialog_get_artists, file);
        newXS("Gtk2::AboutDialog::set_artists", XS_Gtk2__AboutDialog_set_artists, file);
        newXS("Gtk2::AboutDialog::get_translator_credits", XS_Gtk2__AboutDialog_get_translator_credits, file);
        newXS("Gtk2::AboutDialog::set_translator_credits", XS_Gtk2__AboutDialog_set_translator_credits, file);
        newXS("Gtk2::AboutDialog::get_logo", XS_Gtk2__AboutDialog_get_logo, file);
        newXS("Gtk2::AboutDialog::set_logo", XS_Gtk2__AboutDialog_set_logo, file);
        newXS("Gtk2::AboutDialog::get_logo_icon_name", XS_Gtk2__AboutDialog_get_logo_icon_name, file);
        newXS("Gtk2::AboutDialog::set_logo_icon_name", XS_Gtk2__AboutDialog_set_logo_icon_name, file);
        newXS("Gtk2::AboutDialog::set_email_hook", XS_Gtk2__AboutDialog_set_email_hook, file);
        newXS("Gtk2::AboutDialog::set_url_hook", XS_Gtk2__AboutDialog_set_url_hook, file);
    }

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#line 1147 "xs\\GtkAboutDialog.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

