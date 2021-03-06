/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GError.xs. Do not edit this file, edit GError.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "GError.xs"
/*
 * Copyright (C) 2004-2009 by the gtk2-perl team (see the file AUTHORS for the full
 * list)
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Library General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or (at your
 * option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * $Id$
 */

#include "gperl.h"
#include "gperl-gtypes.h"

#if 0
  "Skipped embedded POD."
#endif
#line 58 "GError.xs"

typedef struct {
	GQuark  domain;
	GType   error_enum;
	char  * package;
} ErrorInfo;

static ErrorInfo *
error_info_new (GQuark domain, GType error_enum, const char * package)
{
	ErrorInfo * info = g_new (ErrorInfo, 1);
	info->domain = domain;
	info->error_enum = error_enum;
	info->package = package ? g_strdup (package) : NULL;
	return info;
}

static void
error_info_free (ErrorInfo * info)
{
	if (info) {
		info->domain = 0;
		info->error_enum = 0;
		if (info->package)
			g_free (info->package);
		info->package = NULL;
		g_free (info);
	}
}

static GHashTable * errors_by_domain = NULL;

#if 0
  "Skipped embedded POD."
#endif
#line 102 "GError.xs"
void
gperl_register_error_domain (GQuark domain,
                             GType error_enum,
                             const char * package)
{
	g_return_if_fail (domain != 0); /* pointless without this */
	g_return_if_fail (package != NULL); /* or this */

	if (!errors_by_domain)
		errors_by_domain = g_hash_table_new_full
					(g_direct_hash,
					 g_direct_equal,
					 NULL,
					 (GDestroyNotify) error_info_free);

	g_hash_table_insert (errors_by_domain,
	                     GUINT_TO_POINTER (domain),
	                     error_info_new (domain, error_enum, package));
	gperl_set_isa (package, "Glib::Error");
}

struct FindData {
	const char * package;
	ErrorInfo * info;
};

static void
find_package (gpointer key,
              ErrorInfo * info,
              struct FindData * find_data)
{
	PERL_UNUSED_VAR (key);
	if (g_str_equal (find_data->package, info->package))
		find_data->info = info;
}

static ErrorInfo *
error_info_from_package (const char * package)
{
	struct FindData find_data;
	find_data.package = package;
	find_data.info = NULL;
	g_hash_table_foreach (errors_by_domain,
	                      (GHFunc) find_package,
	                      &find_data);
	return find_data.info;
}

static ErrorInfo *
error_info_from_domain (GQuark domain)
{
	return (ErrorInfo*) g_hash_table_lookup (errors_by_domain,
	                                         GUINT_TO_POINTER (domain));
}

#if 0
  "Skipped embedded POD."
#endif
#line 163 "GError.xs"
SV *
gperl_sv_from_gerror (GError * error)
{
	HV * hv;
	ErrorInfo * info;
	char * package;

	if (!error)
		return newSVsv (&PL_sv_undef);

	info = error_info_from_domain (error->domain);

	hv = newHV ();
	gperl_hv_take_sv_s (hv, "domain",
	                    newSVGChar (g_quark_to_string (error->domain)));
	gperl_hv_take_sv_s (hv, "code", newSViv (error->code));
	if (info)
		gperl_hv_take_sv_s (hv, "value",
		                    gperl_convert_back_enum (info->error_enum,
		                                             error->code));
	gperl_hv_take_sv_s (hv, "message", newSVGChar (error->message));

	/* WARNING: using evil undocumented voodoo.  mess() is the function
	 * that die(), warn(), and croak() use to format messages, and it's
	 * what knows how to find the code location.  don't want to do that
	 * ourselves, since that's blacker magic, so we'll call this and 
	 * hope the perl API doesn't change.  */
	gperl_hv_take_sv_s (hv, "location", newSVsv (mess ("%s", "")));

	package = info ? info->package : "Glib::Error";

	return sv_bless (newRV_noinc ((SV*) hv), gv_stashpv (package, TRUE)); 
}


#if 0
  "Skipped embedded POD."
#endif
#line 207 "GError.xs"
void
gperl_gerror_from_sv (SV * sv, GError ** error)
{
	ErrorInfo * info = NULL;
	const char * package;
	GError scratch;
	HV * hv;
	SV ** svp;

	/* pass back NULL if the sv is false.  we need to allow for the
	 * empty string because $@ is often '' rather than undef; as a 
	 * side effect, 0 is also allowed.  we just won't advertise that.
	 * the logic here is a bit ugly to avoid running the overloaded
	 * stringification operator via SvTRUE(). */
	if (!gperl_sv_is_defined (sv) ||		/* not defined */
	    (!SvROK (sv) && !SvTRUE (sv)))	/* not a ref, but still false */
	{
		*error = NULL;
		return;
	}

	/*
	 * now we must parse a hash.
	 */
	if (!gperl_sv_is_hash_ref (sv))
		croak ("expecting undef or a hash reference for a GError");

	/*
	 * error domain.  prefer the type into which the object is blessed,
	 * fall back to the 'domain' key.
	 */
	package = sv_reftype (SvRV (sv), TRUE);
	hv = (HV*) SvRV (sv);
	if (package)
		info = error_info_from_package (package);
	if (!info) {
		const char * domain;
		GQuark qdomain;
		svp = hv_fetch (hv, "domain", 6, FALSE);
		if (!svp || !gperl_sv_is_defined (*svp))
			g_error ("key 'domain' not found in plain hash for GError");
		domain = SvPV_nolen (*svp);
		qdomain = g_quark_try_string (domain);
		if (!qdomain)
			g_error ("%s is not a valid quark, did you remember to register an error domain?", domain);

		info = error_info_from_domain (qdomain);
	}
	if (!info)
		croak ("%s is neither a Glib::Error derivative nor a valid GError domain",
		       SvPV_nolen (sv));
		
	scratch.domain = info->domain;

	/*
	 * error code.  prefer the 'value' key, fall back to 'code'.
	 */
	svp = hv_fetch (hv, "value", 5, FALSE);
	if (svp && gperl_sv_is_defined (*svp))
		scratch.code = gperl_convert_enum (info->error_enum, *svp);
	else {
		svp = hv_fetch (hv, "code", 4, FALSE);
		if (!svp || !gperl_sv_is_defined (*svp))
			croak ("error hash contains neither a 'value' nor 'code' key; no error valid error code found");
		scratch.code = SvIV (*svp);
	}

	/*
	 * the message is the easy part.
	 */
	svp = hv_fetch (hv, "message", 7, FALSE);
	if (!svp || !gperl_sv_is_defined (*svp))
		croak ("error has contains no error message");
	scratch.message = SvGChar (*svp);

	*error = g_error_new_literal (scratch.domain,
	                              scratch.code,
	                              scratch.message);
}

#if 0
  "Skipped embedded POD."
#endif
#line 306 "GError.xs"
void
gperl_croak_gerror (const char * ignored, GError * err)
{
	PERL_UNUSED_VAR (ignored);
	/* this really could only happen if there's a problem with XS bindings
	 * so we'll use a assertion to catch it, rather than handle null */
	g_return_if_fail (err != NULL);

	sv_setsv (ERRSV, gperl_sv_from_gerror (err));

	/* croak() does not return; free this now to avoid leaking it. */
	g_error_free (err);
	croak (Nullch);
}

#if 0
  "Skipped embedded POD."
#endif
#line 324 "GError.xs"

#line 277 "GError.c"
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

#line 419 "GError.c"
#if 0
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Glib__Error_location); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Error_location)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "error");
    {
	char *	RETVAL;
	dXSTARG;
	SV *	error = ST(0)
;

	RETVAL = location(error);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Glib__Error_message); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Error_message)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "error");
    {
	char *	RETVAL;
	dXSTARG;
	SV *	error = ST(0)
;

	RETVAL = message(error);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Glib__Error_domain); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Error_domain)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "error");
    {
	char *	RETVAL;
	dXSTARG;
	SV *	error = ST(0)
;

	RETVAL = domain(error);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Glib__Error_value); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Error_value)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "error");
    {
	char *	RETVAL;
	dXSTARG;
	SV *	error = ST(0)
;

	RETVAL = value(error);
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Glib__Error_code); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Error_code)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "error");
    {
	int	RETVAL;
	dXSTARG;
	SV *	error = ST(0)
;

	RETVAL = code(error);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

#endif

XS_EUPXS(XS_Glib__Error_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Error_new)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 3)
       croak_xs_usage(cv,  "class, code, message");
    {
#line 508 "GError.xs"
	ErrorInfo * info = NULL;
#line 530 "GError.c"
	SV *	RETVAL;
	const char *	class = (const char *)SvPV_nolen(ST(0))
;
	SV *	code = ST(1)
;
	const gchar *	message;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(2));
	message = (const gchar *)SvPV_nolen (ST(2))
;
#line 510 "GError.xs"
	info = error_info_from_package (class);
	if (!info) {
		GQuark d;
		if (0 != (d = g_quark_try_string (class)))
			info = error_info_from_domain (d);
	}
	if (info) {
		/* this is rather wasteful, as it converts one way and
		 * then back, but that effectively launders everything
		 * for us. */
		GError error;
		error.domain = info->domain;
		error.code = gperl_convert_enum (info->error_enum, code);
		error.message = (gchar*)message;
		RETVAL = gperl_sv_from_gerror (&error);
	} else {
		warn ("%s is neither a Glib::Error derivative nor a valid GError domain",
		      class);
		RETVAL = newSVGChar (message);
	}
	if (ix == 1) {
		/* go ahead and throw it. */
		SvSetSV (ERRSV, RETVAL);
		croak (Nullch);
	}
#line 568 "GError.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Glib__Error_register); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Error_register)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "package, enum_package");
    {
#line 550 "GError.xs"
	GQuark qdomain;
	GType enum_type;
#line 586 "GError.c"
	char *	package = (char *)SvPV_nolen(ST(0))
;
	char *	enum_package = (char *)SvPV_nolen(ST(1))
;
#line 553 "GError.xs"
	enum_type = gperl_fundamental_type_from_package (enum_package);
	if (!enum_type)
		croak ("%s is not registered as a Glib enum", enum_package);

	ENTER;
	SAVESPTR (DEFSV);
	sv_setpv (DEFSV, package);
	eval_pv ("$_ = lc $_; s/::/-/g;", G_VOID);
	qdomain = g_quark_from_string (SvPV_nolen (DEFSV));
	LEAVE;

	gperl_register_error_domain (qdomain, enum_type, package);
#line 604 "GError.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Glib__Error_matches); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Error_matches)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "error, domain, code");
    {
#line 576 "GError.xs"
	GError * real_error;
	ErrorInfo * info;
	int real_code;
#line 621 "GError.c"
	gboolean	RETVAL;
	SV *	error = ST(0)
;
	const char *	domain = (const char *)SvPV_nolen(ST(1))
;
	SV *	code = ST(2)
;
#line 580 "GError.xs"
	gperl_gerror_from_sv (error, &real_error);
	info = error_info_from_package (domain);
	if (!info) {
		GQuark q = g_quark_try_string (domain);
		if (!q)
			croak ("%s is not a valid error domain", domain);
		info = error_info_from_domain (q);
	}
	if (!info)
		croak ("%s is not a registered error domain", domain);
	real_code = looks_like_number (code)
	          ? SvIV (code)
	          : gperl_convert_enum (info->error_enum, code);
	RETVAL = g_error_matches (real_error, info->domain, real_code);
	if (real_error)
		g_error_free (real_error);
#line 646 "GError.c"
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Glib__Error); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Glib__Error)
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
        newXS("Glib::Error::location", XS_Glib__Error_location, file);
        newXS("Glib::Error::message", XS_Glib__Error_message, file);
        newXS("Glib::Error::domain", XS_Glib__Error_domain, file);
        newXS("Glib::Error::value", XS_Glib__Error_value, file);
        newXS("Glib::Error::code", XS_Glib__Error_code, file);
#endif
        cv = newXS("Glib::Error::new", XS_Glib__Error_new, file);
        XSANY.any_i32 = 0;
        cv = newXS("Glib::Error::throw", XS_Glib__Error_new, file);
        XSANY.any_i32 = 1;
        newXS("Glib::Error::register", XS_Glib__Error_register, file);
        newXS("Glib::Error::matches", XS_Glib__Error_matches, file);
    }

    /* Initialisation Section */

#line 328 "GError.xs"
	/* i can't quite decide whether i'm happy about registering all
	 * of these here.  in theory, it's possible to get any of these,
	 * so we should define them for later use; in practice, we may
	 * never see a few of them. */
#if GLIB_CHECK_VERSION (2, 12, 0)
	/* gbookmarkfile.h */
	gperl_register_error_domain (G_BOOKMARK_FILE_ERROR,
				     GPERL_TYPE_BOOKMARK_FILE_ERROR,
				     "Glib::BookmarkFile::Error");
#endif /* GLIB_CHECK_VERSION (2, 12, 0) */
	/* gconvert.h */
	gperl_register_error_domain (G_CONVERT_ERROR,
	                             GPERL_TYPE_CONVERT_ERROR,
	                             "Glib::Convert::Error");
	/* gfileutils.h */
	gperl_register_error_domain (G_FILE_ERROR,
	                             GPERL_TYPE_FILE_ERROR,
	                             "Glib::File::Error");
#if GLIB_CHECK_VERSION (2, 6, 0)
	/* gkeyfile.h */
	gperl_register_error_domain (G_KEY_FILE_ERROR,
				     GPERL_TYPE_KEY_FILE_ERROR,
				     "Glib::KeyFile::Error");
#endif /* GLIB_CHECK_VERSION (2, 6, 0) */
	/* giochannel.h */
	gperl_register_error_domain (G_IO_CHANNEL_ERROR,
	                             GPERL_TYPE_IO_CHANNEL_ERROR,
	                             "Glib::IOChannel::Error");
	/* gmarkup.h */
	gperl_register_error_domain (G_MARKUP_ERROR,
	                             GPERL_TYPE_MARKUP_ERROR,
	                             "Glib::Markup::Error");
	/* gshell.h */
	gperl_register_error_domain (G_SHELL_ERROR,
	                             GPERL_TYPE_SHELL_ERROR,
	                             "Glib::Shell::Error");
	/* gspawn.h */
	gperl_register_error_domain (G_SPAWN_ERROR,
	                             GPERL_TYPE_SPAWN_ERROR,
	                             "Glib::Spawn::Error");
	/* gthread.h */
	gperl_register_error_domain (G_THREAD_ERROR,
	                             GPERL_TYPE_THREAD_ERROR,
	                             "Glib::Thread::Error");

	PERL_UNUSED_VAR (file);

#if XSubPPtmpAAAA
#endif
#line 743 "GError.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

