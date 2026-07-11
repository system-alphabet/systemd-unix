/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Minimal shim for <libintl.h>.
 * FreeBSD provides <libintl.h> from gettext-libintl or the base system.
 * This shim ensures the header is always findable even when gettext is
 * not installed.
 */

#ifdef __FreeBSD__
/* FreeBSD may not have libintl.h in the base sysroot; provide stubs. */
#define _(String) (String)
#define N_(String) (String)
#define gettext(String) (String)
#define dgettext(Domain, String) (String)
#define dcgettext(Domain, String, Type) (String)
#define bindtextdomain(Domain, Directory) ((char *)(Directory))
#define textdomain(Domain) ((char *)(Domain))
#else
#include_next <libintl.h>
#endif