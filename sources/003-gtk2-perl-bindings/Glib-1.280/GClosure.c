/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GClosure.xs. Do not edit this file, edit GClosure.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "GClosure.xs"
/*
 * Copyright (C) 2003-2009, 2012 by the gtk2-perl team (see the file AUTHORS
 * for the full list)
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
#line 36 "GClosure.xs"

#include "gperl.h"
#include <gobject/gvaluecollector.h>

#include "gperl_marshal.h"
#include "gperl-private.h"


static void
gperl_closure_invalidate (gpointer data,
			  GClosure * closure)
{
	GPerlClosure * pc = (GPerlClosure *)closure;
	
	PERL_UNUSED_VAR (data);
	
#ifdef NOISY
	warn ("Invalidating closure for %s\n", SvPV_nolen (pc->callback));
#endif
	if (pc->callback) {
		SvREFCNT_dec (pc->callback);     
		pc->callback = NULL;
	}
	if (pc->data) {
		SvREFCNT_dec (pc->data);
		pc->data = NULL;
	}
}

#ifdef PERL_IMPLICIT_CONTEXT
# define INVOKED_FROM_FOREIGN_THREAD (!PERL_GET_CONTEXT)
#else
# define INVOKED_FROM_FOREIGN_THREAD \
	(_gperl_get_main_tid () != g_thread_self ())
#endif

static void _closure_hand_to_main (GClosure * closure,
                                   GValue * return_value,
                                   guint n_param_values,
                                   const GValue * param_values,
                                   gpointer invocation_hint,
                                   gpointer marshal_data);

static void
gperl_closure_marshal (GClosure * closure,
		       GValue * return_value,
		       guint n_param_values,
		       const GValue * param_values,
		       gpointer invocation_hint,
		       gpointer marshal_data)
{
	gboolean want_return_value;
	int flags;
	guint i;
	dGPERL_CLOSURE_MARSHAL_ARGS;

	/* If the current thread doesn't have a Perl context associated with
	 * it, then we have no choice but to hand over everything to the main
	 * thread and let it handle marshalling.
	 *
	 * We cannot simply use the main thread's Perl context here because the
	 * Perl interpreter is not thread-safe.  For the same reason, we cannot
	 * use perl_clone to create a new Perl interpreter from the main one.
	 */
	if (INVOKED_FROM_FOREIGN_THREAD) {
		g_printerr ("*** GPerl asked to invoke callback from a foreign thread; "
		            "handing it over to the main loop\n");
		_closure_hand_to_main (closure, return_value,
		                       n_param_values, param_values,
		                       invocation_hint, marshal_data);
		return;
	}

	GPERL_CLOSURE_MARSHAL_INIT (closure, marshal_data);

	PERL_UNUSED_VAR (invocation_hint);

	ENTER;
	SAVETMPS;

	PUSHMARK (SP);

	if (n_param_values == 0) {
		data = SvREFCNT_inc (pc->data);
	} else {
		GPERL_CLOSURE_MARSHAL_PUSH_INSTANCE (param_values);

		/* the rest of the params should be quite straightforward. */
		for (i = 1; i < n_param_values; i++) {
			SV * arg = SAVED_STACK_SV (
				gperl_sv_from_value ((GValue*) param_values + i));
			/* make these mortal as they go onto the stack */
			XPUSHs (sv_2mortal (arg));
		}
	}
	GPERL_CLOSURE_MARSHAL_PUSH_DATA;

	PUTBACK;

	want_return_value = return_value && G_VALUE_TYPE (return_value);
	flags = want_return_value ? G_SCALAR : G_VOID|G_DISCARD;

	SPAGAIN;

	GPERL_CLOSURE_MARSHAL_CALL (flags);
	PERL_UNUSED_VAR (count);

	if (want_return_value) {
		gperl_value_from_sv (return_value, POPs);
		PUTBACK; /* vitally important */
	}

	/*
	 * clean up 
	 */

	FREETMPS;
	LEAVE;
}

typedef struct {
	GClosure * closure;
	GValue * return_value;
	guint n_param_values;
	const GValue * param_values;
	gpointer invocation_hint;
	gpointer marshal_data;
	GCond * done_cond;
	GMutex * done_mutex;
} MarshallerArgs;

static gboolean
_closure_remarshal (gpointer data)
{
	MarshallerArgs *args = data;
	g_mutex_lock (args->done_mutex);
		gperl_closure_marshal (args->closure,
		                       args->return_value,
		                       args->n_param_values,
		                       args->param_values,
		                       args->invocation_hint,
		                       args->marshal_data);
		g_cond_signal (args->done_cond);
	g_mutex_unlock (args->done_mutex);
	return FALSE;
}

static void
_closure_hand_to_main (GClosure * closure,
                       GValue * return_value,
                       guint n_param_values,
                       const GValue * param_values,
                       gpointer invocation_hint,
                       gpointer marshal_data)
{
	MarshallerArgs args;
	args.closure = closure;
	args.return_value = return_value;
	args.n_param_values = n_param_values;
	args.param_values = param_values;
	args.invocation_hint = invocation_hint;
	args.marshal_data = marshal_data;

	/* We need to wait for the other thread to finish marshalling to avoid
	 * gperl_closure_marshal returning prematurely. */
	args.done_cond = g_cond_new ();
	args.done_mutex = g_mutex_new ();
	g_mutex_lock (args.done_mutex);
		/* FIXME: Should we use a higher priority? */
		g_idle_add (_closure_remarshal, &args);
		g_cond_wait (args.done_cond, args.done_mutex);
	g_mutex_unlock (args.done_mutex);

	g_cond_free (args.done_cond);
	g_mutex_free (args.done_mutex);
}

#if 0
  "Skipped embedded POD."
#endif
#line 225 "GClosure.xs"
GClosure *
gperl_closure_new (SV * callback,
		   SV * data,
		   gboolean swap)
{
	return gperl_closure_new_with_marshaller (callback, data, swap, NULL);
}

#if 0
  "Skipped embedded POD."
#endif
#line 249 "GClosure.xs"
GClosure *
gperl_closure_new_with_marshaller (SV * callback,
				   SV * data,
				   gboolean swap,
				   GClosureMarshal marshaller)
{
	GPerlClosure *closure;
	g_return_val_if_fail (callback != NULL, NULL);
	if (marshaller == NULL)
		marshaller = gperl_closure_marshal;

	closure = (GPerlClosure*) g_closure_new_simple (sizeof (GPerlClosure), 
							NULL);
	g_closure_add_invalidate_notifier ((GClosure*) closure, 
					   NULL, gperl_closure_invalidate);
#ifndef PERL_IMPLICIT_CONTEXT
	g_closure_set_marshal ((GClosure*) closure, marshaller);
#else
	/* make sure the closure gets executed by the same interpreter that's
	 * creating it now; gperl_closure_marshal will interpret the 
	 * marshal_data as the proper aTHX. */
	g_closure_set_meta_marshal ((GClosure*) closure, aTHX, marshaller);
#endif

	/* 
	 * we have to take full copies of these SVs, rather than just
	 * SvREFCNT_inc'ing them, to avoid some bizarre things that can
	 * happen in special cases.   see the notes in perlcall section
	 * 'Using call_sv' for more info
	 */
	closure->callback = (callback && callback != &PL_sv_undef)
	                  ? newSVsv (callback)
	                  : NULL;

	closure->data = (data && data != &PL_sv_undef)
	              ? newSVsv (data)
	              : NULL;

	closure->swap = swap;

	return (GClosure*)closure;
}


#if 0
  "Skipped embedded POD."
#endif
#line 342 "GClosure.xs"
GPerlCallback *
gperl_callback_new (SV    * func,
                    SV    * data,
                    gint    n_params,
                    GType   param_types[],
		    GType   return_type)
{
	GPerlCallback * callback;

	callback = g_new0 (GPerlCallback, 1);

	/* copy the scalars, so we still have them when the time comes to
	 * be invoked.  see the perlcall manpage for more information. */
	callback->func = newSVsv (func);
	if (data)
		callback->data = newSVsv (data);

	callback->n_params = n_params;

	if (callback->n_params) {
		if (!param_types)
			croak ("n_params is %d but param_types is NULL in gperl_callback_new", n_params);
		callback->param_types = g_new (GType, n_params);
		memcpy (callback->param_types, param_types,
		        n_params * sizeof (GType));
	}

	callback->return_type = return_type;

#ifdef PERL_IMPLICIT_CONTEXT
	callback->priv = aTHX;
#endif

	return callback;
}


#if 0
  "Skipped embedded POD."
#endif
#line 384 "GClosure.xs"
void
gperl_callback_destroy (GPerlCallback * callback)
{
#ifdef NOISY
	warn ("gperl_callback_destroy 0x%p", callback);
#endif
	if (callback) {
		if (callback->func) {
			SvREFCNT_dec (callback->func);
			callback->func = NULL;
		}
		if (callback->data) {
			SvREFCNT_dec (callback->data);
			callback->data = NULL;
		}
		if (callback->param_types) {
			g_free (callback->param_types);
			callback->n_params = 0;
			callback->param_types = NULL;
		}
		g_free (callback);
	}
}


#if 0
  "Skipped embedded POD."
#endif
#line 435 "GClosure.xs"
void
gperl_callback_invoke (GPerlCallback * callback,
                       GValue * return_value,
                       ...)
{
	va_list var_args;
	dGPERL_CALLBACK_MARSHAL_SP;

	g_return_if_fail (callback != NULL);

	GPERL_CALLBACK_MARSHAL_INIT (callback);

	ENTER;
	SAVETMPS;

	PUSHMARK (SP);

	va_start (var_args, return_value);

	/* put args on the stack */
	if (callback->n_params > 0) {
		int i;
		GValue v = {0, };

                /* Crib note: must g_value_unset() even when asking for
                 * G_VALUE_NOCOPY_CONTENTS.  A GObject is always
                 * g_object_ref()ed for storage in a GValue, even under
                 * G_VALUE_NOCOPY_CONTENTS (see code in
                 * g_value_object_collect_value()).  Always reffing in
                 * G_VALUE_COLLECT is in fact the recommended behaviour for
                 * all ref-counted types (see the GTypeValueTable docs,
                 * apparently to ensure objects remain alive for the
                 * duration of a g_signal_emit_valist()).
                 */
		for (i = 0 ; i < callback->n_params ; i++) {
			gchar * error = NULL;
			SV * sv;
			g_value_init (&v, callback->param_types[i]);
			G_VALUE_COLLECT (&v, var_args, G_VALUE_NOCOPY_CONTENTS,
			                 &error);
			if (error) {
				SV * errstr;
				/* this should only happen if you've
				 * created the callback incorrectly */
				/* we modified the stack -- we need to make 
				 * sure perl sees that! */
				PUTBACK;
				errstr = newSVpvf ("error while collecting"
				                   " varargs parameters: %s\n"
						   "is your GPerlCallback "
						   "created properly? "
						   " bailing out",
						   error);
				g_free (error);
				/* this won't return */
				croak ("%s", SvPV_nolen (errstr));
			}
			sv = SAVED_STACK_SV (gperl_sv_from_value (&v));
			g_value_unset (&v);
			if (!sv) {
				/* this should be very rare, too. */
				PUTBACK;
				croak ("failed to convert GValue to SV");
			}
			XPUSHs (sv_2mortal (sv));
		}
	}

        /* Usual REFCNT_inc and 2mortal here for putting something on the
         * stack.  It's possible callback->func will disconnect itself, in
         * which case gperl_callback_destroy() will REFCNT_dec the data.
         * That's fine, it leaves the mortal ref on the stack as the only
         * one remaining, and the next FREETMPS will decrement and destroy
         * in the usual way.
         *
         * Being a plain push here means callback->func can modify its
         * $_[-1] to modify the stored userdata.  Slightly scary, but it's a
         * cute way to get a free bit of per-connection data you can play
         * with as a state variable or whatnot.  And not making a copy saves
         * a couple of bytes of memory :-).
         */
	{
		SV *data = callback->data;
		if (data) {
			XPUSHs (sv_2mortal (SvREFCNT_inc (data)));
		}
	}
	va_end (var_args);

	PUTBACK;

	/* invoke the callback */
	if (return_value && G_VALUE_TYPE (return_value)) {
		if (1 != call_sv (callback->func, G_SCALAR))
			croak ("callback returned more than one value in "
			       "scalar context --- something really bad "
			       "is happening");
		SPAGAIN;
		gperl_value_from_sv (return_value, POPs);
		PUTBACK; /* we modified the stack pointer */
	} else {
		call_sv (callback->func, G_DISCARD);
	}

	/* clean up */

	FREETMPS;
	LEAVE;
}


#if 0
static const char *
dump_callback (GPerlCallback * c)
{
	SV * sv = newSVpvf ("{%d, [", c->n_params);
	int i;
	for (i = 0 ; i < c->n_params ; i++)
		sv_catpvf (sv, "%s%s", g_type_name (c->param_types[i]),
		           (i+1) == c->n_params ? "" : ", ");
	sv_catpvf (sv, "], %s, %s[%d], %s[%d], 0x%p}",
	           g_type_name (c->return_type),
		   SvPV_nolen (c->func), SvREFCNT (c->func), 
		   SvPV_nolen (c->data), SvREFCNT (c->data),
		   c->priv);
	sv_2mortal (sv);
	return SvPV_nolen (sv);
}

#endif






#if 0
  "Skipped embedded POD."
#endif
#line 588 "GClosure.xs"


typedef struct {
	gulong     tag;
	GClosure * closure;
} ExceptionHandler;

static GSList * exception_handlers = NULL;
G_LOCK_DEFINE_STATIC (exception_handlers);

/* this is modified only behind the exception_handlers lock. */
static gboolean in_exception_handler = FALSE;




#if 0
  "Skipped embedded POD."
#endif
#line 616 "GClosure.xs"
int
gperl_install_exception_handler (GClosure * closure)
{
	static int tag = 0;
	ExceptionHandler * h;

	h = g_new0 (ExceptionHandler, 1);

	G_LOCK (exception_handlers);

	h->tag = ++tag;
	h->closure = g_closure_ref (closure);
	g_closure_sink (closure);

	exception_handlers = g_slist_append (exception_handlers, h);

	G_UNLOCK (exception_handlers);

	return h->tag;
}

void
exception_handler_free (ExceptionHandler * h)
{
	g_closure_unref (h->closure);
	g_free (h);
}

static void
remove_exception_handler_unlocked (guint tag)
{
	GSList * i;

	for (i = exception_handlers ; i != NULL ; i = i->next) {
		ExceptionHandler * h = (ExceptionHandler*) i->data;
		if (h->tag == tag) {
			exception_handler_free (h);
			exception_handlers =
				g_slist_delete_link (exception_handlers, i);
			break;
		}
	}
}


#if 0
  "Skipped embedded POD."
#endif
#line 673 "GClosure.xs"
void
gperl_remove_exception_handler (guint tag)
{
	G_LOCK (exception_handlers);
	remove_exception_handler_unlocked (tag);
	G_UNLOCK (exception_handlers);
}


static void
warn_of_ignored_exception (const char * message)
{
	/* there's a bit of extra nastiness here to strip the trailing
	 * newline from the contents of ERRSV for printing.
	 */
	/*
	 * don't clobber $_.  for some reason, SAVE_DEFSV doesn't work here.
	 * so we do it by hand.
	 */
	SV * saved_defsv = newSVsv (DEFSV);
	ENTER;
	SAVETMPS;
	sv_setsv (DEFSV, ERRSV);
	eval_pv ("s/^/***   /mg", FALSE);
	eval_pv ("s/\n$//s", FALSE);
	warn ("*** %s:\n"
	      "%s\n"
	      "***  ignoring",
	      message,
	      SvPV_nolen (DEFSV));

	FREETMPS;
	LEAVE;
	sv_setsv (DEFSV, saved_defsv);
	SvREFCNT_dec (saved_defsv);
}

#if 0
  "Skipped embedded POD."
#endif
#line 716 "GClosure.xs"
void
gperl_run_exception_handlers (void)
{
	GSList * i, * this;
	int n_run = 0;
	/* to avoid problems with handlers that fiddle with the value of
	 * the global $@, we'll pass a copy of $@ to all the handlers
	 * on the stack.  this way we know they all get the same one, and
	 * they can do whatever they want to it without actually affecting
	 * anyone else. */
	SV * errsv = newSVsv (ERRSV);

	if (in_exception_handler) {
		warn_of_ignored_exception ("died in an exception handler");
		return;
	}

	G_LOCK (exception_handlers);

	++in_exception_handler;

	/* call any registered handlers */
	for (i = exception_handlers ; i != NULL ; /* in loop */) {
		ExceptionHandler * h = (ExceptionHandler *) i->data;
		GValue param_values = {0, };
		GValue return_value = {0, };
		g_value_init (&param_values, GPERL_TYPE_SV);
		g_value_init (&return_value, G_TYPE_BOOLEAN);
		/* this will duplicate errsv each time, so that all
		 * callbacks get the same value. */
		g_value_set_boxed (&param_values, errsv);
		g_closure_invoke (h->closure, &return_value,
		                  1, &param_values, NULL);
		this = i;
		i = i->next;
		g_assert (i != this);
		if (!g_value_get_boolean (&return_value)) {
#ifdef NOISY
			warn ("handler %d returned FALSE, removing\n", h->tag);
#endif
			exception_handler_free (h);
			exception_handlers =
			      g_slist_delete_link (exception_handlers, this);
		}
		g_value_unset (&param_values);
		g_value_unset (&return_value);
		++n_run;
	}

	--in_exception_handler;

	G_UNLOCK (exception_handlers);

	if (n_run == 0) 
		warn_of_ignored_exception ("unhandled exception in callback");

	/* and clear the error */
	sv_setsv (ERRSV, &PL_sv_undef);
	SvREFCNT_dec (errsv);
}

#if 0
  "Skipped embedded POD."
#endif
#line 780 "GClosure.xs"

#line 663 "GClosure.c"
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

#line 805 "GClosure.c"

XS_EUPXS(XS_Glib_install_exception_handler); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib_install_exception_handler)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "class, func, data=NULL");
    {
	int	RETVAL;
	dXSTARG;
	SV *	func = ST(1)
;
	SV *	data;

	if (items < 3)
	    data = NULL;
	else {
	    data = ST(2)
;
	}

	RETVAL = gperl_install_exception_handler(gperl_closure_new (func, data, 0));
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Glib_remove_exception_handler); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Glib_remove_exception_handler)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "class, tag");
    {
	guint	tag = (guint)SvUV(ST(1))
;

	gperl_remove_exception_handler(tag);
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Glib__Closure); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Glib__Closure)
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

        newXS("Glib::install_exception_handler", XS_Glib_install_exception_handler, file);
        newXS("Glib::remove_exception_handler", XS_Glib_remove_exception_handler, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

