/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GSignal.xs. Do not edit this file, edit GSignal.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "GSignal.xs"
/*
 * Copyright (C) 2003-2004, 2009, 2012 by the gtk2-perl team (see the file
 * AUTHORS for the full list)
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

#if 0
  "Skipped embedded POD."
#endif
#line 27 "GSignal.xs"

/* #define NOISY */

#include "gperl.h"
#include "gperl-private.h" /* for SAVED_STACK_SV */

/*
 * here's a nice G_LOCK-like front-end to GStaticRecMutex.  we need this 
 * to keep other threads from fiddling with the closures list while we're
 * modifying it.
 */
#ifdef G_THREADS_ENABLED
# define GPERL_REC_LOCK_DEFINE_STATIC(name)	\
	GStaticRecMutex G_LOCK_NAME (name) = G_STATIC_REC_MUTEX_INIT
# define GPERL_REC_LOCK(name)	\
	g_static_rec_mutex_lock (&G_LOCK_NAME (name))
# define GPERL_REC_UNLOCK(name)	\
	g_static_rec_mutex_unlock (&G_LOCK_NAME (name))
#else
# define GPERL_REC_LOCK_DEFINE_STATIC(name) extern void glib_dummy_decl (void)
# define GPERL_REC_LOCK(name)
# define GPERL_REC_UNLOCK(name)
#endif


/*
GLib doesn't include a GFlags type for GSignalFlags, so we have to do
this by hand.  watch for fallen cruft.
*/

static GType
gperl_signal_flags_get_type (void)
{
  static GType etype = 0;
  if ( etype == 0 ) {
    static const GFlagsValue values[] = {
      { G_SIGNAL_RUN_FIRST,    "G_SIGNAL_RUN_FIRST",   "run-first" },
      { G_SIGNAL_RUN_LAST,     "G_SIGNAL_RUN_LAST",    "run-last" },
      { G_SIGNAL_RUN_CLEANUP,  "G_SIGNAL_RUN_CLEANUP", "run-cleanup" },
      { G_SIGNAL_NO_RECURSE,   "G_SIGNAL_NO_RECURSE",  "no-recurse" },
      { G_SIGNAL_DETAILED,     "G_SIGNAL_DETAILED",    "detailed" },
      { G_SIGNAL_ACTION,       "G_SIGNAL_ACTION",      "action" },
      { G_SIGNAL_NO_HOOKS,     "G_SIGNAL_NO_HOOKS",    "no-hooks" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("GSignalFlags", values);
  }
  return etype;
}

SV *
newSVGSignalFlags (GSignalFlags flags)
{
	return gperl_convert_back_flags (gperl_signal_flags_get_type (), flags);
}

GSignalFlags
SvGSignalFlags (SV * sv)
{
	return gperl_convert_flags (gperl_signal_flags_get_type (), sv);
}

/* GConnectFlags doesn't come with a GType either.  We don't use it in Glib
 * directly, but other bindings might need it. */
static GType
gperl_connect_flags_get_type (void)
{
  static GType etype = 0;
  if ( etype == 0 ) {
    static const GFlagsValue values[] = {
      { G_CONNECT_AFTER,   "G_CONNECT_AFTER",   "after" },
      { G_CONNECT_SWAPPED, "G_CONNECT_SWAPPED", "swapped" },
      { 0, NULL, NULL }
    };
    etype = g_flags_register_static ("GConnectFlags", values);
  }
  return etype;
}

SV *
newSVGSignalInvocationHint (GSignalInvocationHint * ihint)
{
	HV * hv = newHV ();
	gperl_hv_take_sv_s (hv, "signal_name",
	                    newSVGChar (g_signal_name (ihint->signal_id)));
	gperl_hv_take_sv_s (hv, "detail",
	                    newSVGChar (g_quark_to_string (ihint->detail)));
	gperl_hv_take_sv_s (hv, "run_type",
	                    newSVGSignalFlags (ihint->run_type));
	return newRV_noinc ((SV*)hv);
}


#define GET_NAME(name, gtype)				\
	(name) = gperl_package_from_type (gtype);	\
	if (!(name))					\
		(name) = g_type_name (gtype);
SV *
newSVGSignalQuery (GSignalQuery * query)
{
	HV * hv;
	AV * av;
	guint j;
	const char * pkgname;

	if (!query)
		return &PL_sv_undef;

	hv = newHV ();
	gperl_hv_take_sv_s (hv, "signal_id", newSViv (query->signal_id));
	gperl_hv_take_sv_s (hv, "signal_name",
	                    newSVpv (query->signal_name, 0));
	GET_NAME (pkgname, query->itype);
	if (pkgname)
		gperl_hv_take_sv_s (hv, "itype", newSVpv (pkgname, 0));
	gperl_hv_take_sv_s (hv, "signal_flags",
	                    newSVGSignalFlags (query->signal_flags));
	if (query->return_type != G_TYPE_NONE) {
		GType t = query->return_type & ~G_SIGNAL_TYPE_STATIC_SCOPE;
		GET_NAME (pkgname, t);
		if (pkgname)
			gperl_hv_take_sv_s (hv, "return_type",
			                    newSVpv (pkgname, 0));
	}
	av = newAV ();
	for (j = 0; j < query->n_params; j++) {
		GType t = query->param_types[j] & ~G_SIGNAL_TYPE_STATIC_SCOPE;
		GET_NAME (pkgname, t);
		av_push (av, newSVpv (pkgname, 0));
	}
	gperl_hv_take_sv_s (hv, "param_types", newRV_noinc ((SV*)av));
	/* n_params is inferred by the length of the av in param_types */

	return newRV_noinc ((SV*)hv);
}
#undef GET_NAME


/*
now back to our regularly-scheduled bindings.
*/

static GSList * closures = NULL;
GPERL_REC_LOCK_DEFINE_STATIC (closures);

static void
forget_closure (SV * callback,
                GPerlClosure * closure)
{
#ifdef NOISY
	warn ("forget_closure %p / %p", callback, closure);
#else
	PERL_UNUSED_VAR (callback);
#endif
	
	GPERL_REC_LOCK (closures);
	closures = g_slist_remove (closures, closure);
	GPERL_REC_UNLOCK (closures);
}

static void
remember_closure (GPerlClosure * closure)
{
#ifdef NOISY
	warn ("remember_closure %p / %p", closure->callback, closure);
	warn ("   callback %s\n", SvPV_nolen (closure->callback));
#endif
	GPERL_REC_LOCK (closures);
	closures = g_slist_prepend (closures, closure);
	GPERL_REC_UNLOCK (closures);
	g_closure_add_invalidate_notifier ((GClosure *) closure,
	                                   closure->callback,
	                                   (GClosureNotify) forget_closure);
}

#if 0
  "Skipped embedded POD."
#endif
#line 227 "GSignal.xs"

/* We need to store the custom marshallers indexed by (type, signal) tuples
 * since signal names are not unique (GtkDialog and GtkInfoBar both have a
 * "response" signal, for example). */
static GHashTable * marshallers_by_type = NULL;
G_LOCK_DEFINE_STATIC (marshallers_by_type);

/* gobject treats hyphens and underscores in signal names as equivalent.  We
 * thus need to do this as well to ensure that a custom marshaller is used for
 * all spellings of a signal name. */
static char *
canonicalize_signal_name (char * signal_name)
{
	return g_strdelimit (signal_name, "_", '-');
}

void
gperl_signal_set_marshaller_for (GType instance_type,
                                 char * detailed_signal,
                                 GClosureMarshal marshaller)
{
	g_return_if_fail (instance_type != 0);
	g_return_if_fail (detailed_signal != NULL);
	G_LOCK (marshallers_by_type);
	if (!marshaller && !marshallers_by_type) {
		/* nothing to do */
	} else {
		GHashTable *marshallers_by_signal;
		char *canonical_detailed_signal;
		if (!marshallers_by_type)
			marshallers_by_type =
				g_hash_table_new_full (g_direct_hash,
				                       g_direct_equal,
				                       NULL,
				                       (GDestroyNotify)
				                         g_hash_table_destroy);
		marshallers_by_signal = g_hash_table_lookup (
		                          marshallers_by_type,
		                          (gpointer) instance_type);
		if (!marshallers_by_signal) {
			marshallers_by_signal = g_hash_table_new_full (
			                          g_str_hash,
			                          g_str_equal,
			                          g_free,
			                          NULL);
			g_hash_table_insert (marshallers_by_type,
			                     (gpointer) instance_type,
			                     marshallers_by_signal);
		}
		canonical_detailed_signal = canonicalize_signal_name (
			g_strdup (detailed_signal));
		if (marshaller) {
			g_hash_table_insert
					(marshallers_by_signal,
					 canonical_detailed_signal,
					 marshaller);
		} else {
			g_hash_table_remove (marshallers_by_signal,
			                     canonical_detailed_signal);
			g_free (canonical_detailed_signal);
		}
	}
	G_UNLOCK (marshallers_by_type);
}

/* Called with lock on marshallers_by_type held. */
static GClosureMarshal
lookup_specific_marshaller (GType specific_type,
                            char * detailed_signal)
{
	GHashTable *marshallers_by_signal =
		g_hash_table_lookup (marshallers_by_type,
		                     (gpointer) specific_type);
	if (marshallers_by_signal) {
		char *canonical_detailed_signal;
		GClosureMarshal marshaller;
		canonical_detailed_signal = canonicalize_signal_name (
			g_strdup (detailed_signal));
		marshaller = g_hash_table_lookup (marshallers_by_signal,
		                                  canonical_detailed_signal);
		g_free (canonical_detailed_signal);
		return marshaller;
	}
	return NULL;
}

static GClosureMarshal
lookup_marshaller (GType instance_type,
                   char * detailed_signal)
{
	GClosureMarshal marshaller = NULL;
	G_LOCK (marshallers_by_type);
	if (marshallers_by_type) {
		GType type = instance_type;
		/* We need to walk the ancestry to make sure that, say,
		 * GtkFileChooseDialog also gets the custom "response"
		 * marshaller from GtkDialog.  This always terminates because
		 * g_type_parent (G_TYPE_OBJECT) == 0. */
		while (marshaller == NULL && type != 0) {
			marshaller = lookup_specific_marshaller (
			               type, detailed_signal);
			type = g_type_parent (type);
		}
		/* We also need to look at interfaces. */
		if (marshaller == NULL) {
			GType *interface_types =
				g_type_interfaces (instance_type, NULL);
			GType *interface = interface_types;
			/* interface_types is 0-terminated. */
			while (marshaller == NULL && *interface != 0) {
				marshaller = lookup_specific_marshaller (
			                       *interface, detailed_signal);
				interface++;
			}
		}
	}
	G_UNLOCK (marshallers_by_type);
	return marshaller;
}

#if 0
  "Skipped embedded POD."
#endif
#line 359 "GSignal.xs"
gulong
gperl_signal_connect (SV * instance,
                      char * detailed_signal,
                      SV * callback, SV * data,
                      GConnectFlags flags)
{
	GObject * object;
	GPerlClosure * closure;
	GClosureMarshal marshaller = NULL;
	gulong id;

	object = gperl_get_object (instance);
	marshaller = lookup_marshaller (G_OBJECT_TYPE (object), detailed_signal);
	closure = (GPerlClosure *)
			gperl_closure_new_with_marshaller
			                     (callback, data,
			                      flags & G_CONNECT_SWAPPED,
			                      marshaller);

	/* after is true only if we're called as signal_connect_after */
	id =	g_signal_connect_closure (object,
		                          detailed_signal,
		                          (GClosure*) closure, 
		                          flags & G_CONNECT_AFTER);

	if (id > 0) {
		closure->id = id;
		remember_closure (closure);
	} else {
		/* not connected, usually bad detailed_signal name */
		g_closure_unref ((GClosure*) closure);
	}
	return id;
}

/*
G_SIGNAL_MATCH_ID        The signal id must be equal.
G_SIGNAL_MATCH_DETAIL    The signal detail be equal.
G_SIGNAL_MATCH_CLOSURE   The closure must be the same.
G_SIGNAL_MATCH_FUNC      The C closure callback must be the same.
G_SIGNAL_MATCH_DATA      The closure data must be the same.
G_SIGNAL_MATCH_UNBLOCKED Only unblocked signals may matched.

at the perl level, the CV replaces both the FUNC and CLOSURE.  it's rare
people will specify any of the others than FUNC and DATA, but i can see
how they would be useful so let's support them.
*/
typedef guint (*sig_match_callback) (gpointer           instance,
                                     GSignalMatchType   mask,
                                     guint              signal_id,
                                     GQuark             detail,
                                     GClosure         * closure,
                                     gpointer           func,
                                     gpointer           data);

static guint
foreach_closure_matched (gpointer instance,
                         GSignalMatchType mask,
                         guint signal_id,
                         GQuark detail,
                         SV * func,
                         SV * data,
                         sig_match_callback callback)
{
	guint n = 0;
	GSList * i;

	if (mask & G_SIGNAL_MATCH_CLOSURE || /* this isn't too likely */
	    mask & G_SIGNAL_MATCH_FUNC ||
	    mask & G_SIGNAL_MATCH_DATA) {
		/*
		 * to match against a function or data, we need to find the
		 * scalars for those in the GPerlClosures; we'll have to
		 * proxy this stuff.  we'll replace the func and data bits
		 * with closure in the mask.
		 *    however, we can't do the match for any of the other
		 * flags at this level, so even though our design means one
		 * closure per handler id, we still have to pass that closure
		 * on to the real C functions to do any other filtering for
		 * us.
		 */
		/* we'll compare SVs by their stringified values.  cache the
		 * stringified needles, but there's no way to cache the
		 * haystack. */
		const char * str_func = func ? SvPV_nolen (func) : NULL;
		const char * str_data = data ? SvPV_nolen (data) : NULL;

		mask &= ~(G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA);
		mask |= G_SIGNAL_MATCH_CLOSURE;

		/* this is a little hairy because the callback may disconnect
		 * a closure, which would modify the list while we're iterating
		 * over it. */
		GPERL_REC_LOCK (closures);
		i = closures;
		while (i != NULL) {
			GPerlClosure * c = (GPerlClosure*) i->data;
			i = i->next;
			if ((!func || strEQ (str_func, SvPV_nolen (c->callback))) &&
			    (!data || strEQ (str_data, SvPV_nolen (c->data)))) {
				n += callback (instance, mask, signal_id,
				               detail, (GClosure*)c,
				               NULL, NULL);
			}
		}
		GPERL_REC_UNLOCK (closures);
	} else {
		/* we're not matching against a closure, so we can just
		 * pass this on through. */
		n = callback (instance, mask, signal_id, detail,
		              NULL, NULL, NULL);
	}
	return n;
}


static GType
get_gtype_or_croak (SV * object_or_class_name)
{
	GType gtype;

	if (gperl_sv_is_ref (object_or_class_name)) {
		GObject * object = SvGObject (object_or_class_name);
		if (!object)
			croak ("bad object in signal_query");
		gtype = G_OBJECT_TYPE (object);
	} else {
		gtype = gperl_object_type_from_package
					(SvPV_nolen (object_or_class_name));
		if (!gtype)
			croak ("package %s is not registered with GPerl",
			       SvPV_nolen (object_or_class_name));
	}
	
	return gtype;
}

static guint
parse_signal_name_or_croak (const char * detailed_name,
			    GType instance_type,
			    GQuark * detail) /* return, NULL if not wanted */
{
	guint signal_id;
	if (!g_signal_parse_name (detailed_name, instance_type, &signal_id,
				  detail, TRUE))
		croak ("Unknown signal %s for object of type %s", 
			detailed_name, g_type_name (instance_type));
	return signal_id;
}

static GPerlCallback *
gperl_signal_emission_hook_create (SV * func,
				   SV * data)
{
	GType param_types[2];
	param_types[0] = GPERL_TYPE_SV;
	param_types[1] = GPERL_TYPE_SV;
	return gperl_callback_new (func, data, G_N_ELEMENTS (param_types),
				   param_types, G_TYPE_BOOLEAN);
}

static gboolean
gperl_signal_emission_hook (GSignalInvocationHint * ihint,
			    guint n_param_values,
			    const GValue * param_values,
			    gpointer data)
{
	GPerlCallback * callback = (GPerlCallback *) data;
	gboolean retval;
	AV * av;
	guint i;
	GValue return_value = {0, };
	g_value_init (&return_value, G_TYPE_BOOLEAN);
	av = newAV();
	for (i = 0 ; i < n_param_values ; i++)
		av_push (av, sv_2mortal (gperl_sv_from_value (param_values+i)));
	gperl_callback_invoke (callback, &return_value,
			       newSVGSignalInvocationHint (ihint),
			       newRV_noinc ((SV*) av));
	retval = g_value_get_boolean (&return_value);
	g_value_unset (&return_value);
	return retval;
}


#if 0
  "Skipped embedded POD."
#endif
#line 547 "GSignal.xs"


#line 530 "GSignal.c"
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

#line 672 "GSignal.c"

XS_EUPXS(XS_Glib__Object_signal_emit); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Object_signal_emit)
{
    dVAR; dXSARGS;
    if (items < 2)
       croak_xs_usage(cv,  "instance, name, ...");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	GObject *	instance = SvGObject (ST(0))
;
	char *	name = (char *)SvPV_nolen(ST(1))
;
#line 647 "GSignal.xs"
	guint signal_id, i;
	GQuark detail;
	GSignalQuery query;
	GValue * params;
#line 692 "GSignal.c"
#line 652 "GSignal.xs"
#define ARGOFFSET 2
	signal_id = parse_signal_name_or_croak
				(name, G_OBJECT_TYPE (instance), &detail);

	g_signal_query (signal_id, &query);

	if (((guint)(items-ARGOFFSET)) != query.n_params) 
		croak ("Incorrect number of arguments for emission of signal %s in class %s; need %d but got %d",
		       name, G_OBJECT_TYPE_NAME (instance),
		       query.n_params, (gint) items-ARGOFFSET);

	/* set up the parameters to g_signal_emitv.   this is an array
	 * of GValues, where [0] is the emission instance, and the rest 
	 * are the query.n_params arguments. */
	params = g_new0 (GValue, query.n_params + 1);

	g_value_init (&params[0], G_OBJECT_TYPE (instance));
	g_value_set_object (&params[0], instance);

	for (i = 0 ; i < query.n_params ; i++) {
		g_value_init (&params[i+1], 
			      query.param_types[i] & ~G_SIGNAL_TYPE_STATIC_SCOPE);
		if (!gperl_value_from_sv (&params[i+1], ST (ARGOFFSET+i)))
			croak ("Couldn't convert value %s to type %s for parameter %d of signal %s on a %s",
			       SvPV_nolen (ST (ARGOFFSET+i)),
			       g_type_name (G_VALUE_TYPE (&params[i+1])),
			       i, name, G_OBJECT_TYPE_NAME (instance));
	}

	/* now actually call it.  what we do depends on the return type of
	 * the signal; if the signal returns anything we need to capture it
	 * and push it onto the return stack. */
	if (query.return_type != G_TYPE_NONE) {
		/* signal returns a value, woohoo! */
		GValue ret = {0,};
		g_value_init (&ret, query.return_type);
		g_signal_emitv (params, signal_id, detail, &ret);
		EXTEND (SP, 1);
		SAVED_STACK_PUSHs (sv_2mortal (gperl_sv_from_value (&ret)));
		g_value_unset (&ret);
	} else {
		g_signal_emitv (params, signal_id, detail, NULL);
	}

	/* clean up */
	for (i = 0 ; i < query.n_params + 1 ; i++)
		g_value_unset (&params[i]);
	g_free (params);
#undef ARGOFFSET
#line 743 "GSignal.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Glib__Object_signal_query); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Object_signal_query)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "object_or_class_name, name");
    {
#line 721 "GSignal.xs"
	GType itype;
	guint signal_id;
	GSignalQuery query;
	GObjectClass * oclass = NULL;
#line 762 "GSignal.c"
	SV *	RETVAL;
	SV *	object_or_class_name = ST(0)
;
	const char *	name = (const char *)SvPV_nolen(ST(1))
;
#line 726 "GSignal.xs"
	itype = get_gtype_or_croak (object_or_class_name);
	if (G_TYPE_IS_CLASSED (itype)) {
		/* ref the class to ensure that the signals get created,
		 * otherwise they may not exist at the time we query. */
		oclass = g_type_class_ref (itype);
		if (!oclass)
			croak ("couldn't ref type %s", g_type_name (itype));
	}
	signal_id = g_signal_lookup (name, itype);
	if (0 == signal_id) {
		RETVAL = &PL_sv_undef;
	} else {
		g_signal_query (signal_id, &query);
		RETVAL = newSVGSignalQuery (&query);
	}
	if (oclass)
		g_type_class_unref (oclass);
#line 786 "GSignal.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Glib__Object_signal_get_invocation_hint); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Object_signal_get_invocation_hint)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "instance");
    {
#line 784 "GSignal.xs"
        GSignalInvocationHint *ihint;
#line 803 "GSignal.c"
	SV *	RETVAL;
	GObject *	instance = SvGObject (ST(0))
;
#line 786 "GSignal.xs"
        ihint = g_signal_get_invocation_hint (instance);
        RETVAL = ihint ? newSVGSignalInvocationHint (ihint) : &PL_sv_undef;
#line 810 "GSignal.c"
	ST(0) = RETVAL;
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Glib__Object_signal_stop_emission_by_name); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Object_signal_stop_emission_by_name)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "instance, detailed_signal");
    {
	GObject *	instance = SvGObject (ST(0))
;
	const gchar *	detailed_signal;

	/* same as SvGChar(), but not in a function */
	sv_utf8_upgrade (ST(1));
	detailed_signal = (const gchar *)SvPV_nolen (ST(1))
;

	g_signal_stop_emission_by_name(instance, detailed_signal);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Glib__Object_signal_add_emission_hook); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Object_signal_add_emission_hook)
{
    dVAR; dXSARGS;
    if (items < 3 || items > 4)
       croak_xs_usage(cv,  "object_or_class_name, detailed_signal, hook_func, hook_data=NULL");
    {
	SV *	object_or_class_name = ST(0)
;
	const char *	detailed_signal = (const char *)SvPV_nolen(ST(1))
;
	SV *	hook_func = ST(2)
;
	SV *	hook_data;
#line 833 "GSignal.xs"
	GType           itype;
	GObjectClass *  object_class;
	guint           signal_id;
	GQuark          quark;
	GPerlCallback * callback;
#line 860 "GSignal.c"
	gulong	RETVAL;
	dXSTARG;

	if (items < 4)
	    hook_data = NULL;
	else {
	    hook_data = ST(3)
;
	}
#line 839 "GSignal.xs"
	itype = get_gtype_or_croak (object_or_class_name);

	/* See the xsub for g_object_find_property in GObject.xs for why the
	 * class ref/unref stunt is necessary. */
	object_class = g_type_class_ref (itype);

	signal_id = parse_signal_name_or_croak (detailed_signal, itype, &quark);
	callback = gperl_signal_emission_hook_create (hook_func, hook_data);
	RETVAL = g_signal_add_emission_hook
			(signal_id, quark, gperl_signal_emission_hook,
			 callback, (GDestroyNotify)gperl_callback_destroy);

	g_type_class_unref (object_class);
#line 884 "GSignal.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Glib__Object_signal_remove_emission_hook); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Object_signal_remove_emission_hook)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "object_or_class_name, signal_name, hook_id");
    {
#line 865 "GSignal.xs"
	guint signal_id;
	GType gtype;
#line 901 "GSignal.c"
	SV *	object_or_class_name = ST(0)
;
	const char *	signal_name = (const char *)SvPV_nolen(ST(1))
;
	gulong	hook_id = (gulong)SvUV(ST(2))
;
#line 868 "GSignal.xs"
	gtype = get_gtype_or_croak (object_or_class_name);
	signal_id = parse_signal_name_or_croak (signal_name, gtype, NULL);
	g_signal_remove_emission_hook (signal_id, hook_id);
#line 912 "GSignal.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Glib__Object_signal_connect); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Object_signal_connect)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items < 3 || items > 4)
       croak_xs_usage(cv,  "instance, detailed_signal, callback, data=NULL");
    {
	SV *	instance = ST(0)
;
	char *	detailed_signal = (char *)SvPV_nolen(ST(1))
;
	SV *	callback = ST(2)
;
	SV *	data;
#line 939 "GSignal.xs"
	GConnectFlags flags = 0;
#line 935 "GSignal.c"
	gulong	RETVAL;
	dXSTARG;

	if (items < 4)
	    data = NULL;
	else {
	    data = ST(3)
;
	}
#line 941 "GSignal.xs"
	if (ix == 1) flags |= G_CONNECT_AFTER;
	if (ix == 2) flags |= G_CONNECT_SWAPPED;
	RETVAL = gperl_signal_connect (instance, detailed_signal,
	                               callback, data, flags);
#line 950 "GSignal.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Glib__Object_signal_handler_block); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Object_signal_handler_block)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "object, handler_id");
    {
	GObject *	object = SvGObject (ST(0))
;
	gulong	handler_id = (gulong)SvUV(ST(1))
;

	g_signal_handler_block(object, handler_id);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Glib__Object_signal_handler_unblock); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Object_signal_handler_unblock)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "object, handler_id");
    {
	GObject *	object = SvGObject (ST(0))
;
	gulong	handler_id = (gulong)SvUV(ST(1))
;

	g_signal_handler_unblock(object, handler_id);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Glib__Object_signal_handler_disconnect); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Object_signal_handler_disconnect)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "object, handler_id");
    {
	GObject *	object = SvGObject (ST(0))
;
	gulong	handler_id = (gulong)SvUV(ST(1))
;

	g_signal_handler_disconnect(object, handler_id);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Glib__Object_signal_handler_is_connected); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Object_signal_handler_is_connected)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "object, handler_id");
    {
	GObject *	object = SvGObject (ST(0))
;
	gulong	handler_id = (gulong)SvUV(ST(1))
;
	gboolean	RETVAL;

	RETVAL = g_signal_handler_is_connected(object, handler_id);
	ST(0) = boolSV(RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Glib__Object_signal_handlers_block_by_func); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Object_signal_handlers_block_by_func)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "instance, func, data=NULL");
    {
	GObject *	instance = SvGObject (ST(0))
;
	SV *	func = ST(1)
;
	SV *	data;
#line 1055 "GSignal.xs"
	sig_match_callback callback = NULL;
#line 1047 "GSignal.c"
	int	RETVAL;
	dXSTARG;

	if (items < 3)
	    data = NULL;
	else {
	    data = ST(2)
;
	}
#line 1057 "GSignal.xs"
	switch (ix) {
	    case 0: callback = g_signal_handlers_block_matched; break;
	    case 1: callback = g_signal_handlers_unblock_matched; break;
	    case 2: callback = g_signal_handlers_disconnect_matched; break;
	    default: g_assert_not_reached ();
	}
	RETVAL = foreach_closure_matched (instance, G_SIGNAL_MATCH_CLOSURE,
	                                  0, 0, func, data, callback);
#line 1066 "GSignal.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Glib__Object_signal_chain_from_overridden); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib__Object_signal_chain_from_overridden)
{
    dVAR; dXSARGS;
    if (items < 1)
       croak_xs_usage(cv,  "instance, ...");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 1094 "GSignal.xs"
	GSignalInvocationHint * ihint;
	GSignalQuery query;
	GValue * instance_and_params = NULL,
	         return_value = {0,};
	guint i;
#line 1088 "GSignal.c"
	GObject *	instance = SvGObject (ST(0))
;
#line 1101 "GSignal.xs"
	ihint = g_signal_get_invocation_hint (instance);
	if (!ihint)
		croak ("could not find signal invocation hint for %s(0x%p)",
		       G_OBJECT_TYPE_NAME (instance), instance);

	g_signal_query (ihint->signal_id, &query);

	if ((guint)items != 1 + query.n_params)
		croak ("incorrect number of parameters for signal %s, "
		       "expected %d, got %d",
		       g_signal_name (ihint->signal_id),
		       1 + query.n_params,
		       (gint) items);

	instance_and_params = g_new0 (GValue, 1 + query.n_params);

	g_value_init (&instance_and_params[0], G_OBJECT_TYPE (instance));
	g_value_set_object (&instance_and_params[0], instance);

	for (i = 0 ; i < query.n_params ; i++) {
		g_value_init (&instance_and_params[i+1],
		              query.param_types[i]
			         & ~G_SIGNAL_TYPE_STATIC_SCOPE);
		gperl_value_from_sv (&instance_and_params[i+1], ST (i+1));
	}

	if (query.return_type != G_TYPE_NONE)
		g_value_init (&return_value,
		              query.return_type
			         & ~G_SIGNAL_TYPE_STATIC_SCOPE);

	g_signal_chain_from_overridden (instance_and_params, &return_value);

	for (i = 0 ; i < 1 + query.n_params ; i++)
		g_value_unset (instance_and_params+i);
	g_free (instance_and_params);

	if (G_TYPE_NONE != (query.return_type & ~G_SIGNAL_TYPE_STATIC_SCOPE)) {
		SAVED_STACK_XPUSHs (sv_2mortal (gperl_sv_from_value (&return_value)));
		g_value_unset (&return_value);
	}
#line 1133 "GSignal.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Glib__Signal); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Glib__Signal)
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

        newXS("Glib::Object::signal_emit", XS_Glib__Object_signal_emit, file);
        newXS("Glib::Object::signal_query", XS_Glib__Object_signal_query, file);
        newXS("Glib::Object::signal_get_invocation_hint", XS_Glib__Object_signal_get_invocation_hint, file);
        newXS("Glib::Object::signal_stop_emission_by_name", XS_Glib__Object_signal_stop_emission_by_name, file);
        newXS("Glib::Object::signal_add_emission_hook", XS_Glib__Object_signal_add_emission_hook, file);
        newXS("Glib::Object::signal_remove_emission_hook", XS_Glib__Object_signal_remove_emission_hook, file);
        cv = newXS("Glib::Object::signal_connect_after", XS_Glib__Object_signal_connect, file);
        XSANY.any_i32 = 1;
        cv = newXS("Glib::Object::signal_connect_swapped", XS_Glib__Object_signal_connect, file);
        XSANY.any_i32 = 2;
        cv = newXS("Glib::Object::signal_connect", XS_Glib__Object_signal_connect, file);
        XSANY.any_i32 = 0;
        newXS("Glib::Object::signal_handler_block", XS_Glib__Object_signal_handler_block, file);
        newXS("Glib::Object::signal_handler_unblock", XS_Glib__Object_signal_handler_unblock, file);
        newXS("Glib::Object::signal_handler_disconnect", XS_Glib__Object_signal_handler_disconnect, file);
        newXS("Glib::Object::signal_handler_is_connected", XS_Glib__Object_signal_handler_is_connected, file);
        cv = newXS("Glib::Object::signal_handlers_unblock_by_func", XS_Glib__Object_signal_handlers_block_by_func, file);
        XSANY.any_i32 = 1;
        cv = newXS("Glib::Object::signal_handlers_block_by_func", XS_Glib__Object_signal_handlers_block_by_func, file);
        XSANY.any_i32 = 0;
        cv = newXS("Glib::Object::signal_handlers_disconnect_by_func", XS_Glib__Object_signal_handlers_block_by_func, file);
        XSANY.any_i32 = 2;
        newXS("Glib::Object::signal_chain_from_overridden", XS_Glib__Object_signal_chain_from_overridden, file);
    }

    /* Initialisation Section */

#line 581 "GSignal.xs"
	gperl_register_fundamental (gperl_signal_flags_get_type (),
	                            "Glib::SignalFlags");
	gperl_register_fundamental (gperl_connect_flags_get_type (),
	                            "Glib::ConnectFlags");

#line 1195 "GSignal.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}
