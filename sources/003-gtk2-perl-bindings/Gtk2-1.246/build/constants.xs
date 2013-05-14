/**
 * This is a generated file.  Do not edit.
 */

#include "gtk2perl.h"

MODULE = Gtk2::Constants	PACKAGE = Gtk2

BOOT:
{
	HV *stash = gv_stashpv ("Gtk2", TRUE); /* create if needed */
	HV *tags_hv = get_hv ("Gtk2::EXPORT_TAGS", 1);
	AV *constants_av = NULL;
	SV *constants_ref_sv = NULL;
	SV **constants_svp = hv_fetch (tags_hv, "constants", strlen ("constants"), 0);
	if (constants_svp && gperl_sv_is_array_ref (*constants_svp)) {
		constants_av = (AV *) SvRV (*constants_svp);
		constants_ref_sv = *constants_svp;
	} else {
		constants_av = newAV ();
		constants_ref_sv = newRV_noinc ((SV *) constants_av);
	}
	newCONSTSUB (stash, "GDK_CURRENT_TIME", newSViv (GDK_CURRENT_TIME));
	av_push (constants_av, newSVpv ("GDK_CURRENT_TIME", PL_na));
	newCONSTSUB (stash, "GDK_PRIORITY_EVENTS", newSViv (GDK_PRIORITY_EVENTS));
	av_push (constants_av, newSVpv ("GDK_PRIORITY_EVENTS", PL_na));
	newCONSTSUB (stash, "GDK_PRIORITY_REDRAW", newSViv (GDK_PRIORITY_REDRAW));
	av_push (constants_av, newSVpv ("GDK_PRIORITY_REDRAW", PL_na));
	newCONSTSUB (stash, "GTK_PRIORITY_RESIZE", newSViv (GTK_PRIORITY_RESIZE));
	av_push (constants_av, newSVpv ("GTK_PRIORITY_RESIZE", PL_na));
	newCONSTSUB (stash, "GTK_PATH_PRIO_LOWEST", newSViv (GTK_PATH_PRIO_LOWEST));
	av_push (constants_av, newSVpv ("GTK_PATH_PRIO_LOWEST", PL_na));
	newCONSTSUB (stash, "GTK_PATH_PRIO_GTK", newSViv (GTK_PATH_PRIO_GTK));
	av_push (constants_av, newSVpv ("GTK_PATH_PRIO_GTK", PL_na));
	newCONSTSUB (stash, "GTK_PATH_PRIO_APPLICATION", newSViv (GTK_PATH_PRIO_APPLICATION));
	av_push (constants_av, newSVpv ("GTK_PATH_PRIO_APPLICATION", PL_na));
	newCONSTSUB (stash, "GTK_PATH_PRIO_THEME", newSViv (GTK_PATH_PRIO_THEME));
	av_push (constants_av, newSVpv ("GTK_PATH_PRIO_THEME", PL_na));
	newCONSTSUB (stash, "GTK_PATH_PRIO_RC", newSViv (GTK_PATH_PRIO_RC));
	av_push (constants_av, newSVpv ("GTK_PATH_PRIO_RC", PL_na));
	newCONSTSUB (stash, "GTK_PATH_PRIO_HIGHEST", newSViv (GTK_PATH_PRIO_HIGHEST));
	av_push (constants_av, newSVpv ("GTK_PATH_PRIO_HIGHEST", PL_na));
	newCONSTSUB (stash, "GTK_ENTRY_BUFFER_MAX_SIZE", newSVuv (GTK_ENTRY_BUFFER_MAX_SIZE));
	av_push (constants_av, newSVpv ("GTK_ENTRY_BUFFER_MAX_SIZE", PL_na));
	gperl_hv_take_sv_s (tags_hv, "constants", constants_ref_sv);
}


