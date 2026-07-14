/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <utmpx.h>

#include <sys/socket.h>  /* for struct sockaddr_storage */

/* Linux path for utmpx database */
#ifndef UTMPX_FILE
#define UTMPX_FILE "/var/run/utmp"
#endif

/* Linux extension: IPv6 address storage in struct utmpx.
 * FreeBSD's struct utmpx may not have this field. */
#ifndef ut_addr_v6
#define ut_addr_v6 ut_ss
#endif

/* Linux path for utmpx database — not used on FreeBSD but needed for compilation */
#ifndef UTMPX_FILE
#define UTMPX_FILE "/var/run/utmp"
#endif
