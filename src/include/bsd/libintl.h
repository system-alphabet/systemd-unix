/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Minimal shim for <libintl.h>.
 *
 * Neither FreeBSD's base sysroot nor OpenBSD's ships <libintl.h>: gettext is
 * an optional package on both. Hand over to the system header only when it is
 * actually installed, otherwise fall back to no-op macros.
 */

#if defined(__has_include_next) && __has_include_next(<libintl.h>)
#        include_next <libintl.h>
#else
#        define _(String) (String)
#        define N_(String) (String)
#        define gettext(String) (String)
#        define dgettext(Domain, String) (String)
#        define dcgettext(Domain, String, Type) (String)
#        define bindtextdomain(Domain, Directory) ((char *)(Directory))
#        define textdomain(Domain) ((char *)(Domain))
#endif
