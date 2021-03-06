/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkCombo.xs. Do not edit this file, edit GtkCombo.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkCombo.xs"
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

#line 34 "xs\\GtkCombo.c"
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

#line 176 "xs\\GtkCombo.c"

XS_EUPXS(XS_Gtk2__Combo_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Combo_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "class");
    {
	GtkWidget *	RETVAL;

	RETVAL = gtk_combo_new(/* void */);
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Combo_disable_activate); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Combo_disable_activate)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "combo");
    {
	GtkCombo *	combo = SvGtkCombo (ST(0))
;

	gtk_combo_disable_activate(combo);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Combo_set_value_in_list); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Combo_set_value_in_list)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "combo, val, ok_if_empty");
    {
	GtkCombo *	combo = SvGtkCombo (ST(0))
;
	gboolean	val = (bool)SvTRUE(ST(1))
;
	gboolean	ok_if_empty = (bool)SvTRUE(ST(2))
;

	gtk_combo_set_value_in_list(combo, val, ok_if_empty);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Combo_set_use_arrows); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Combo_set_use_arrows)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "combo, val");
    {
	GtkCombo *	combo = SvGtkCombo (ST(0))
;
	gboolean	val = (bool)SvTRUE(ST(1))
;

	gtk_combo_set_use_arrows(combo, val);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Combo_set_use_arrows_always); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Combo_set_use_arrows_always)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "combo, val");
    {
	GtkCombo *	combo = SvGtkCombo (ST(0))
;
	gboolean	val = (bool)SvTRUE(ST(1))
;

	gtk_combo_set_use_arrows_always(combo, val);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Combo_set_case_sensitive); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Combo_set_case_sensitive)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "combo, val");
    {
	GtkCombo *	combo = SvGtkCombo (ST(0))
;
	gboolean	val = (bool)SvTRUE(ST(1))
;

	gtk_combo_set_case_sensitive(combo, val);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Combo_set_item_string); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Combo_set_item_string)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "combo, item, item_value");
    {
	GtkCombo *	combo = SvGtkCombo (ST(0))
;
	GtkItem *	item = SvGtkItem (ST(1))
;
	gchar *	item_value;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(2));
	item_value = (gchar *)SvPV_nolen (ST(2))
;

	gtk_combo_set_item_string(combo, item, item_value);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Combo_set_popdown_strings); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Combo_set_popdown_strings)
{
    dVAR; dXSARGS;
    if (items < 1)
       croak_xs_usage(cv,  "combo, ...");
    {
	GtkCombo *	combo = SvGtkCombo (ST(0))
;
#line 80 "xs\\\\GtkCombo.xs"
	GList * strings = NULL;
#line 320 "xs\\GtkCombo.c"
#line 82 "xs\\\\GtkCombo.xs"
	for( items--; items > 0; items-- )
		strings = g_list_prepend(strings, SvGChar(ST(items)));
	if( strings )
	{
		gtk_combo_set_popdown_strings(combo, strings);
		g_list_free(strings);
	}
#line 329 "xs\\GtkCombo.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Combo_entry); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Combo_entry)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items != 1)
       croak_xs_usage(cv,  "combo");
    {
	GtkCombo *	combo = SvGtkCombo (ST(0))
;
	GtkWidget *	RETVAL;
#line 96 "xs\\\\GtkCombo.xs"
	switch (ix) {
	    case 0: RETVAL = combo->entry; break;
	    case 1: RETVAL = combo->list;  break;
	    default:
		RETVAL = NULL;
		g_assert_not_reached ();
	}
#line 354 "xs\\GtkCombo.c"
	ST(0) = newSVGtkWidget (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__Combo); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__Combo)
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

        newXS("Gtk2::Combo::new", XS_Gtk2__Combo_new, file);
        newXS("Gtk2::Combo::disable_activate", XS_Gtk2__Combo_disable_activate, file);
        newXS("Gtk2::Combo::set_value_in_list", XS_Gtk2__Combo_set_value_in_list, file);
        newXS("Gtk2::Combo::set_use_arrows", XS_Gtk2__Combo_set_use_arrows, file);
        newXS("Gtk2::Combo::set_use_arrows_always", XS_Gtk2__Combo_set_use_arrows_always, file);
        newXS("Gtk2::Combo::set_case_sensitive", XS_Gtk2__Combo_set_case_sensitive, file);
        newXS("Gtk2::Combo::set_item_string", XS_Gtk2__Combo_set_item_string, file);
        newXS("Gtk2::Combo::set_popdown_strings", XS_Gtk2__Combo_set_popdown_strings, file);
        cv = newXS("Gtk2::Combo::list", XS_Gtk2__Combo_entry, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::Combo::entry", XS_Gtk2__Combo_entry, file);
        XSANY.any_i32 = 0;
    }
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

