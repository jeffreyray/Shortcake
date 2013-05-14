/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.16 from the
 * contents of GtkContainer.xs. Do not edit this file, edit GtkContainer.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "xs\\\\GtkContainer.xs"
/*
 * Copyright (c) 2003, 2010 by the gtk2-perl team (see the file AUTHORS)
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

static void
init_child_property_value (GObject * object, 
		           const char * name, 
		           GValue * value)
{
	GParamSpec * pspec;
	pspec = gtk_container_class_find_child_property (G_OBJECT_GET_CLASS (object), 
	                                                 name);
	if (!pspec)
		croak ("property %s not found in object class %s",
		       name, G_OBJECT_TYPE_NAME (object));
	g_value_init (value, G_PARAM_SPEC_VALUE_TYPE (pspec));
}

static void
gtk2perl_foreach_callback (GtkWidget * widget,
                           GPerlCallback * callback)
{
	gperl_callback_invoke (callback, NULL, widget);
}


#line 56 "xs\\GtkContainer.c"
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

#line 198 "xs\\GtkContainer.c"

XS_EUPXS(XS_Gtk2__Container_set_border_width); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_set_border_width)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "container, border_width");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	guint	border_width = (guint)SvUV(ST(1))
;

	gtk_container_set_border_width(container, border_width);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_get_border_width); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_get_border_width)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "container");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	guint	RETVAL;
	dXSTARG;

	RETVAL = gtk_container_get_border_width(container);
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Container_add); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_add)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "container, widget");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	GtkWidget *	widget = SvGtkWidget (ST(1))
;

	gtk_container_add(container, widget);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_remove); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_remove)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "container, widget");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	GtkWidget *	widget = SvGtkWidget (ST(1))
;

	gtk_container_remove(container, widget);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_set_resize_mode); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_set_resize_mode)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "container, resize_mode");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	GtkResizeMode	resize_mode = SvGtkResizeMode (ST(1))
;

	gtk_container_set_resize_mode(container, resize_mode);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_get_resize_mode); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_get_resize_mode)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "container");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	GtkResizeMode	RETVAL;

	RETVAL = gtk_container_get_resize_mode(container);
	ST(0) = newSVGtkResizeMode (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Container_check_resize); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_check_resize)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "container");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;

	gtk_container_check_resize(container);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_foreach); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_foreach)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "container, callback, callback_data=NULL");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	SV *	callback = ST(1)
;
	SV *	callback_data;
#line 101 "xs\\\\GtkContainer.xs"
	GPerlCallback * real_callback;
	GType param_types [1];
#line 342 "xs\\GtkContainer.c"

	if (items < 3)
	    callback_data = NULL;
	else {
	    callback_data = ST(2)
;
	}
#line 104 "xs\\\\GtkContainer.xs"
    	param_types[0] = GTK_TYPE_WIDGET;
	real_callback = gperl_callback_new (callback, callback_data,
	                                    1, param_types, G_TYPE_NONE);
	if (ix == 1)
		gtk_container_forall (container, 
				      (GtkCallback)gtk2perl_foreach_callback,
				      real_callback);
	else
		gtk_container_foreach (container, 
				       (GtkCallback)gtk2perl_foreach_callback,
				       real_callback);
	gperl_callback_destroy (real_callback);
#line 363 "xs\\GtkContainer.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_get_children); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_get_children)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "container");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
#line 128 "xs\\\\GtkContainer.xs"
	GList * children, * i;
#line 382 "xs\\GtkContainer.c"
#line 130 "xs\\\\GtkContainer.xs"
	children = gtk_container_get_children (container);
	for (i = children ; i != NULL ; i = i->next)
		XPUSHs (sv_2mortal (newSVGtkWidget (GTK_WIDGET (i->data))));
	g_list_free (children);
#line 388 "xs\\GtkContainer.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__Container_propagate_expose); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_propagate_expose)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "container, child, event");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
	GdkEvent *	event = SvGdkEvent (ST(2))
;

	gtk_container_propagate_expose(container, child, (GdkEventExpose *) event);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_set_focus_chain); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_set_focus_chain)
{
    dVAR; dXSARGS;
    if (items < 1)
       croak_xs_usage(cv,  "container, ...");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
#line 159 "xs\\\\GtkContainer.xs"
	GList *focusable_widgets = NULL;
	int i;
#line 427 "xs\\GtkContainer.c"
#line 162 "xs\\\\GtkContainer.xs"
	for (i = items - 1 ; i > 0 ; i--)
		focusable_widgets = g_list_prepend (focusable_widgets,
		                                    SvGtkWidget (ST (i)));
	gtk_container_set_focus_chain (container, focusable_widgets);
	g_list_free (focusable_widgets);
#line 434 "xs\\GtkContainer.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_get_focus_chain); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_get_focus_chain)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "container");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
#line 176 "xs\\\\GtkContainer.xs"
	GList * i, * focusable_widgets = NULL;
#line 453 "xs\\GtkContainer.c"
#line 178 "xs\\\\GtkContainer.xs"
	if (!gtk_container_get_focus_chain (container, &focusable_widgets))
		XSRETURN_EMPTY;
	for (i = focusable_widgets; i != NULL ; i = i->next)
		XPUSHs (sv_2mortal (newSVGtkWidget (i->data)));
	g_list_free (focusable_widgets);
#line 460 "xs\\GtkContainer.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__Container_unset_focus_chain); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_unset_focus_chain)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "container");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;

	gtk_container_unset_focus_chain(container);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_set_focus_child); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_set_focus_child)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "container, child");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	GtkWidget_ornull *	child = SvGtkWidget_ornull (ST(1))
;

	gtk_container_set_focus_child(container, child);
    }
    XSRETURN_EMPTY;
}

#if GTK_CHECK_VERSION (2, 14, 0)
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Gtk2__Container_get_focus_child); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_get_focus_child)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "container");
    {
	GtkWidget_ornull *	RETVAL;
	GtkContainer *	container = SvGtkContainer (ST(0))
;

	RETVAL = gtk_container_get_focus_child(container);
	ST(0) = newSVGtkWidget_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}

#endif /* 2.14 */

XS_EUPXS(XS_Gtk2__Container_get_focus_hadjustment); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_get_focus_hadjustment)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "container");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	GtkAdjustment_ornull *	RETVAL;

	RETVAL = gtk_container_get_focus_hadjustment(container);
	ST(0) = newSVGtkAdjustment_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Container_get_focus_vadjustment); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_get_focus_vadjustment)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "container");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	GtkAdjustment_ornull *	RETVAL;

	RETVAL = gtk_container_get_focus_vadjustment(container);
	ST(0) = newSVGtkAdjustment_ornull (RETVAL);
	sv_2mortal(ST(0));
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Container_set_focus_vadjustment); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_set_focus_vadjustment)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "container, adjustment");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	GtkAdjustment_ornull *	adjustment = SvGtkAdjustment_ornull (ST(1))
;

	gtk_container_set_focus_vadjustment(container, adjustment);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_set_focus_hadjustment); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_set_focus_hadjustment)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "container, adjustment");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	GtkAdjustment_ornull *	adjustment = SvGtkAdjustment_ornull (ST(1))
;

	gtk_container_set_focus_hadjustment(container, adjustment);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_resize_children); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_resize_children)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "container");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;

	gtk_container_resize_children(container);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_child_type); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_child_type)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "container");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
#line 226 "xs\\\\GtkContainer.xs"
	GType gtype;
#line 625 "xs\\GtkContainer.c"
	const char *	RETVAL;
	dXSTARG;
#line 228 "xs\\\\GtkContainer.xs"
	gtype = gtk_container_child_type (container);
	if (!gtype)
		/* this means that the container is full. */
		XSRETURN_UNDEF;
	/* GtkWidgets are GObjects, so we should only be getting object
	 * types back from this function.  however, we might get a GType
	 * that isn't registered with the bindings, so we have to look 
	 * for one that we know about.  since Glib::Object is always
	 * registered, this loop cannot be infinite. */
	RETVAL = NULL;
	while (gtype &&
	       (NULL == (RETVAL = gperl_object_package_from_type (gtype))))
		gtype = g_type_parent (gtype);
#line 642 "xs\\GtkContainer.c"
	sv_setpv(TARG, RETVAL); XSprePUSH; PUSHTARG;
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Gtk2__Container_find_child_property); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_find_child_property)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items < 1)
       croak_xs_usage(cv,  "container_or_class_name, ...");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	SV *	container_or_class_name = ST(0)
;
#line 271 "xs\\\\GtkContainer.xs"
	GType type;
	gchar *name = NULL;
	GObjectClass *object_class;
#line 665 "xs\\GtkContainer.c"
#line 275 "xs\\\\GtkContainer.xs"
	/* ENHANCE-ME: share this SV to GType with
	   Glib::Object::find_property and probably other places.  Might
	   pass GTK_TYPE_CONTAINER to say it should be a container. */
	if (gperl_sv_is_defined (container_or_class_name) &&
	    SvROK (container_or_class_name)) {
		GObject * object = SvGObject (container_or_class_name);
		if (!object)
			croak ("wha?  NULL object in list_properties");
		type = G_OBJECT_TYPE (object);
	} else {
		type = gperl_object_type_from_package
			(SvPV_nolen (container_or_class_name));
		if (!type)
			croak ("package %s is not registered with GPerl",
			       SvPV_nolen (container_or_class_name));
	}

	switch (ix) {
	case 0:
		if (items != 2)
			croak ("Usage: Gtk2::Container::find_child_property (class, name)");
		name = SvGChar (ST (1));
		break;
	default: /* ix==1 */
		if (items != 1)
			croak ("Usage: Gtk2::Container::list_child_properties (class)");
		break;
	}
	if (! g_type_is_a (type, GTK_TYPE_CONTAINER))
		croak ("Not a Gtk2::Container");

	/* classes registered by perl are kept alive by the bindings.
	 * those coming straight from C are not.  if we had an actual
	 * object, the class will be alive, but if we just had a
	 * package, the class may not exist yet.  thus, we'll have to
	 * do an honest ref here, rather than a peek.
	 */
	object_class = g_type_class_ref (type);

	if (ix == 0) {
		GParamSpec *pspec
		  = gtk_container_class_find_child_property
		      (object_class, name);
		XPUSHs (pspec
			? sv_2mortal (newSVGParamSpec (pspec))
			: &PL_sv_undef);
	}
	else if (ix == 1) {
		GParamSpec **props;
		guint n_props, i;
		props = gtk_container_class_list_child_properties
			  (object_class, &n_props);
		if (n_props) {
			EXTEND (SP, n_props);
			for (i = 0; i < n_props; i++)
				PUSHs (sv_2mortal (newSVGParamSpec (props[i])));
		}
		g_free (props); /* must free even when n_props==0 */
	}

	g_type_class_unref (object_class);
#line 728 "xs\\GtkContainer.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__Container_add_with_properties); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_add_with_properties)
{
    dVAR; dXSARGS;
    if (items < 2)
       croak_xs_usage(cv,  "container, widget, ...");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	GtkWidget *	widget = SvGtkWidget (ST(1))
;
#line 348 "xs\\\\GtkContainer.xs"
	GValue value = {0,};
	int i;
#line 749 "xs\\GtkContainer.c"
#line 351 "xs\\\\GtkContainer.xs"
	g_object_ref (container);
	g_object_ref (widget);
	gtk_widget_freeze_child_notify (widget);

	gtk_container_add (container, widget);

	if (widget->parent) {
		if (0 != ((items - 2) % 2))
			croak ("add_with_properties expects name => value pairs "
			       "(odd number of arguments detected)");

		for (i = 2; i < items; i += 2) {
			char *name = SvPV_nolen (ST (i));
			SV *newval = ST (i + 1);

			init_child_property_value (G_OBJECT (container), name, &value);
			gperl_value_from_sv (&value, newval);

			gtk_container_child_set_property (container, widget, name, &value);

			g_value_unset (&value);
		}
	}

	gtk_widget_thaw_child_notify (widget);
	g_object_unref (widget);
	g_object_unref (container);
#line 778 "xs\\GtkContainer.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_child_get); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_child_get)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items < 2)
       croak_xs_usage(cv,  "container, child, ...");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
#line 396 "xs\\\\GtkContainer.xs"
	GValue value = {0,};
	int i;
#line 801 "xs\\GtkContainer.c"
#line 399 "xs\\\\GtkContainer.xs"
	PERL_UNUSED_VAR (ix);
	EXTEND (SP, items-1);

	for (i = 2; i < items; i++) {
		char *name = SvPV_nolen (ST (i));
		init_child_property_value (G_OBJECT (container), name, &value);

		gtk_container_child_get_property (container, child, name, &value);

		PUSHs (sv_2mortal (gperl_sv_from_value (&value)));
		g_value_unset (&value);
	}
#line 815 "xs\\GtkContainer.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Gtk2__Container_child_set); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_child_set)
{
    dVAR; dXSARGS;
    dXSI32;
    if (items < 2)
       croak_xs_usage(cv,  "container, child, ...");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	GtkWidget *	child = SvGtkWidget (ST(1))
;
#line 429 "xs\\\\GtkContainer.xs"
	GValue value = {0,};
	int i;
#line 837 "xs\\GtkContainer.c"
#line 432 "xs\\\\GtkContainer.xs"
	PERL_UNUSED_VAR (ix);

	if (0 != ((items - 2) % 2))
		croak ("set method expects name => value pairs "
		       "(odd number of arguments detected)");

	for (i = 2; i < items; i += 2) {
		char *name = SvPV_nolen (ST (i));
		SV *newval = ST (i + 1);

		init_child_property_value (G_OBJECT (container), name, &value);
		gperl_value_from_sv (&value, newval);

		gtk_container_child_set_property (container, child, name, &value);

		g_value_unset (&value);
	}
#line 856 "xs\\GtkContainer.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Gtk2__Container_set_reallocate_redraws); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Gtk2__Container_set_reallocate_redraws)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "container, needs_redraws");
    {
	GtkContainer *	container = SvGtkContainer (ST(0))
;
	gboolean	needs_redraws = (bool)SvTRUE(ST(1))
;

	gtk_container_set_reallocate_redraws(container, needs_redraws);
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Gtk2__Container); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Gtk2__Container)
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

        newXS("Gtk2::Container::set_border_width", XS_Gtk2__Container_set_border_width, file);
        newXS("Gtk2::Container::get_border_width", XS_Gtk2__Container_get_border_width, file);
        newXS("Gtk2::Container::add", XS_Gtk2__Container_add, file);
        newXS("Gtk2::Container::remove", XS_Gtk2__Container_remove, file);
        newXS("Gtk2::Container::set_resize_mode", XS_Gtk2__Container_set_resize_mode, file);
        newXS("Gtk2::Container::get_resize_mode", XS_Gtk2__Container_get_resize_mode, file);
        newXS("Gtk2::Container::check_resize", XS_Gtk2__Container_check_resize, file);
        cv = newXS("Gtk2::Container::foreach", XS_Gtk2__Container_foreach, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::Container::forall", XS_Gtk2__Container_foreach, file);
        XSANY.any_i32 = 1;
        newXS("Gtk2::Container::get_children", XS_Gtk2__Container_get_children, file);
        newXS("Gtk2::Container::propagate_expose", XS_Gtk2__Container_propagate_expose, file);
        newXS("Gtk2::Container::set_focus_chain", XS_Gtk2__Container_set_focus_chain, file);
        newXS("Gtk2::Container::get_focus_chain", XS_Gtk2__Container_get_focus_chain, file);
        newXS("Gtk2::Container::unset_focus_chain", XS_Gtk2__Container_unset_focus_chain, file);
        newXS("Gtk2::Container::set_focus_child", XS_Gtk2__Container_set_focus_child, file);
#if XSubPPtmpAAAA
        newXS("Gtk2::Container::get_focus_child", XS_Gtk2__Container_get_focus_child, file);
#endif
        newXS("Gtk2::Container::get_focus_hadjustment", XS_Gtk2__Container_get_focus_hadjustment, file);
        newXS("Gtk2::Container::get_focus_vadjustment", XS_Gtk2__Container_get_focus_vadjustment, file);
        newXS("Gtk2::Container::set_focus_vadjustment", XS_Gtk2__Container_set_focus_vadjustment, file);
        newXS("Gtk2::Container::set_focus_hadjustment", XS_Gtk2__Container_set_focus_hadjustment, file);
        newXS("Gtk2::Container::resize_children", XS_Gtk2__Container_resize_children, file);
        newXS("Gtk2::Container::child_type", XS_Gtk2__Container_child_type, file);
        cv = newXS("Gtk2::Container::list_child_properties", XS_Gtk2__Container_find_child_property, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::Container::find_child_property", XS_Gtk2__Container_find_child_property, file);
        XSANY.any_i32 = 0;
        newXS("Gtk2::Container::add_with_properties", XS_Gtk2__Container_add_with_properties, file);
        cv = newXS("Gtk2::Container::child_get", XS_Gtk2__Container_child_get, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::Container::child_get_property", XS_Gtk2__Container_child_get, file);
        XSANY.any_i32 = 1;
        cv = newXS("Gtk2::Container::child_set", XS_Gtk2__Container_child_set, file);
        XSANY.any_i32 = 0;
        cv = newXS("Gtk2::Container::child_set_property", XS_Gtk2__Container_child_set, file);
        XSANY.any_i32 = 1;
        newXS("Gtk2::Container::set_reallocate_redraws", XS_Gtk2__Container_set_reallocate_redraws, file);
    }

    /* Initialisation Section */

#if XSubPPtmpAAAA
#endif
#line 948 "xs\\GtkContainer.c"

    /* End of Initialisation Section */

#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

