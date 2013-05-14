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

MODULE = Gtk2::HScale	PACKAGE = Gtk2::HScale	PREFIX = gtk_hscale_

## GtkWidget* gtk_hscale_new (GtkAdjustment *adjustment)
GtkWidget *
gtk_hscale_new (class, adjustment=NULL)
	GtkAdjustment_ornull * adjustment
    C_ARGS:
	adjustment

## GtkWidget* gtk_hscale_new_with_range (gdouble min, gdouble max, gdouble step)
GtkWidget *
gtk_hscale_new_with_range (class, min, max, step)
	gdouble min
	gdouble max
	gdouble step
    C_ARGS:
	min, max, step

