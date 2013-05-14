/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkEditable.xs. Do not edit this file, edit GtkEditable.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkEditable.xs"
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
#include <gperl_marshal.h>

/*
GtkEditable's insert-text signal uses an integer pointer as a write-through
parameter; unlike GtkWidget's size-request signal, we can't just pass an
editable object, because an integer is an integral type.

   void user_function  (GtkEditable *editable,
                        gchar *new_text,
                        gint new_text_length,
                        gint *position,  <<=== that's the problem
                        gpointer user_data);
*/
static void
gtk2perl_editable_insert_text_marshal (GClosure * closure,
                                       GValue * return_value,
                                       guint n_param_values,
                                       const GValue * param_values,
                                       gpointer invocation_hint,
                                       gpointer marshal_data)
{
	STRLEN len;
	gint * position_p;
	SV * string, * position;
	dGPERL_CLOSURE_MARSHAL_ARGS;

	GPERL_CLOSURE_MARSHAL_INIT (closure, marshal_data);

	PERL_UNUSED_VAR (return_value);
	PERL_UNUSED_VAR (n_param_values);
	PERL_UNUSED_VAR (invocation_hint);

	ENTER;
	SAVETMPS;

	PUSHMARK (SP);

	GPERL_CLOSURE_MARSHAL_PUSH_INSTANCE (param_values);

	/* string and position are cleaned up manually further down, so they
	 * don't need sv_2mortal. */

	/* new_text */
	string = newSVGChar (g_value_get_string (param_values+1));
	XPUSHs (string);

	/* text length is redundant, but documented.  it doesn't hurt
	 * anything to include it, but would be a doc hassle to omit it. */
	XPUSHs (sv_2mortal (newSViv (g_value_get_int (param_values+2))));

	/* insert position */
	position_p = g_value_get_pointer (param_values+3);
	position = newSViv (*position_p);
	XPUSHs (position);

	GPERL_CLOSURE_MARSHAL_PUSH_DATA;

	PUTBACK;

	GPERL_CLOSURE_MARSHAL_CALL (G_ARRAY);

	/* refresh the param_values with whatever changes the callback may
	 * have made.  values returned on the stack take precedence over
	 * modifications to @_. */
	if (count == 2) {
		SV * sv;
		/* get the values off the end of the stack.  why do my
		 * attempts to use ST() result in segfaults? */
		*position_p = POPi;
		sv = POPs;
		sv_utf8_upgrade (sv);
		g_value_set_string ((GValue*)param_values+1, SvPV (sv, len));
		g_value_set_int ((GValue*)param_values+2, len);
		PUTBACK;

	} else if (count == 0) {
		/* returned no values, then refresh string and position
		 * params from the callback's args, which may have been
		 * modified. */
		sv_utf8_upgrade (string);
		g_value_set_string ((GValue*)param_values+1,
		                    SvPV (string, len));
		g_value_set_int ((GValue*)param_values+2, len);
		*position_p = SvIV (position);
		if (*position_p < 0)
			*position_p = 0;

	} else {
		/* NOTE: croaking here can cause bad things to happen to the
		 * app, because croaking in signal handlers is bad juju. */
		croak ("an insert-text signal handler must either return"
		       " two items (text and position)\nor return no items"
		       " and possibly modify its @_ parameters.\n"
		       "  callback returned %d items", count);
	}

	/*
	 * clean up
	 */
	SvREFCNT_dec (string);
	SvREFCNT_dec (position);

	PUTBACK;
	FREETMPS;
	LEAVE;
}


#line 141 "xs\\GtkEditable.c"
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

#line 283 "xs\\GtkEditable.c"

XS_EUPXS(XS_Gtk2__Editable_select_region); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Editable_select_region)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "editable, start, end");
    {
	GtkEditable *	editable = SvGtkEditable (ST(0))
;
	gint	start = (gint)SvIV(ST(1))
;
	gint	end = (gint)SvIV(ST(2))
;

	gtk_editable_select_region(editable, start, end);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Editable_get_selection_bounds); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Editable_get_selection_bounds)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "editable");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	GtkEditable *	editable = SvGtkEditable (ST(0))
;
#line 205 "xs\\\\GtkEditable.xs"
	gint start;
	gint end;
#line 319 "xs\\GtkEditable.c"
#line 208 "xs\\\\GtkEditable.xs"
	if (!gtk_editable_get_selection_bounds (editable, &start, &end))
		XSRETURN_EMPTY;
	EXTEND (SP, 2);
	PUSHs (sv_2mortal (newSViv (start)));
	PUSHs (sv_2mortal (newSViv (end)));
#line 326 "xs\\GtkEditable.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__Editable_insert_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Editable_insert_text)
{
    dVAR; dXSARGS;
    if (items < 2)
       croak_xs_usage(cv,  "editable, new_text, ...");
    {
	GtkEditable *	editable = SvGtkEditable (ST(0))
;
	gchar *	new_text;
#line 223 "xs\\\\GtkEditable.xs"
	gint new_text_length;
	gint position;
#line 346 "xs\\GtkEditable.c"
	gint	RETVAL;
	dXSTARG;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	new_text = (gchar *)SvPV_nolen (ST(1))
;
#line 226 "xs\\\\GtkEditable.xs"
	if (items == 3) {
		new_text_length = strlen (new_text);
		position = SvIV (ST (2));
	} else if (items == 4) {
		new_text_length = SvIV (ST (2));
		position = SvIV (ST (3));
	} else {
		croak ("Usage: Gtk2::Editable::insert_text(editable, new_text, position)");
	}

	gtk_editable_insert_text (editable, new_text,
				  new_text_length, &position);
	RETVAL = position;
#line 368 "xs\\GtkEditable.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Editable_delete_text); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Editable_delete_text)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "editable, start_pos, end_pos");
    {
	GtkEditable *	editable = SvGtkEditable (ST(0))
;
	gint	start_pos = (gint)SvIV(ST(1))
;
	gint	end_pos = (gint)SvIV(ST(2))
;

	gtk_editable_delete_text(editable, start_pos, end_pos);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Editable_get_chars); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Editable_get_chars)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "editable, start_pos, end_pos");
    {
	GtkEditable *	editable = SvGtkEditable (ST(0))
;
	gint	start_pos = (gint)SvIV(ST(1))
;
	gint	end_pos = (gint)SvIV(ST(2))
;
	gchar_own *	RETVAL;

	RETVAL = gtk_editable_get_chars(editable, start_pos, end_pos);
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


XS_EUPXS(XS_Gtk2__Editable_cut_clipboard); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Editable_cut_clipboard)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "editable");
    {
	GtkEditable *	editable = SvGtkEditable (ST(0))
;

	gtk_editable_cut_clipboard(editable);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Editable_copy_clipboard); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Editable_copy_clipboard)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "editable");
    {
	GtkEditable *	editable = SvGtkEditable (ST(0))
;

	gtk_editable_copy_clipboard(editable);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Editable_paste_clipboard); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Editable_paste_clipboard)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "editable");
    {
	GtkEditable *	editable = SvGtkEditable (ST(0))
;

	gtk_editable_paste_clipboard(editable);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Editable_delete_selection); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Editable_delete_selection)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "editable");
    {
	GtkEditable *	editable = SvGtkEditable (ST(0))
;

	gtk_editable_delete_selection(editable);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Editable_set_position); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Editable_set_position)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "editable, position");
    {
	GtkEditable *	editable = SvGtkEditable (ST(0))
;
	gint	position = (gint)SvIV(ST(1))
;

	gtk_editable_set_position(editable, position);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Editable_get_position); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Editable_get_position)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "editable");
    {
	GtkEditable *	editable = SvGtkEditable (ST(0))
;
	gint	RETVAL;
	dXSTARG;

	RETVAL = gtk_editable_get_position(editable);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Editable_set_editable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Editable_set_editable)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "editable, is_editable");
    {
	GtkEditable *	editable = SvGtkEditable (ST(0))
;
	gboolean	is_editable = (bool)SvTRUE(ST(1))
;

	gtk_editable_set_editable(editable, is_editable);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Editable_get_editable); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Editable_get_editable)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "editable");
    {
	GtkEditable *	editable = SvGtkEditable (ST(0))
;
	gboolean	RETVAL;

	RETVAL = gtk_editable_get_editable(editable);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__Editable); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__Editable)
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

        newXS("Gtk2::Editable::select_region", XS_Gtk2__Editable_select_region, file);
        newXS("Gtk2::Editable::get_selection_bounds", XS_Gtk2__Editable_get_selection_bounds, file);
        newXS("Gtk2::Editable::insert_text", XS_Gtk2__Editable_insert_text, file);
        newXS("Gtk2::Editable::delete_text", XS_Gtk2__Editable_delete_text, file);
        newXS("Gtk2::Editable::get_chars", XS_Gtk2__Editable_get_chars, file);
        newXS("Gtk2::Editable::cut_clipboard", XS_Gtk2__Editable_cut_clipboard, file);
        newXS("Gtk2::Editable::copy_clipboard", XS_Gtk2__Editable_copy_clipboard, file);
        newXS("Gtk2::Editable::paste_clipboard", XS_Gtk2__Editable_paste_clipboard, file);
        newXS("Gtk2::Editable::delete_selection", XS_Gtk2__Editable_delete_selection, file);
        newXS("Gtk2::Editable::set_position", XS_Gtk2__Editable_set_position, file);
        newXS("Gtk2::Editable::get_position", XS_Gtk2__Editable_get_position, file);
        newXS("Gtk2::Editable::set_editable", XS_Gtk2__Editable_set_editable, file);
        newXS("Gtk2::Editable::get_editable", XS_Gtk2__Editable_get_editable, file);

    /* Initialisation Section */

#line 186 "xs\\\\GtkEditable.xs"
	gperl_signal_set_marshaller_for (GTK_TYPE_EDITABLE, "insert_text",
	                                 gtk2perl_editable_insert_text_marshal);

#line 600 "xs\\GtkEditable.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
