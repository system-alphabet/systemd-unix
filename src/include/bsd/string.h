/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#ifndef __linux__
/*
 * On FreeBSD, strerror_r() follows the POSIX standard and returns int.
 * systemd code expects the GNU variant which returns char *.
 * Redirect calls to our wrapper to maintain compatibility.
 *
 * On Linux/glibc the GNU variant (returning char *) is already in effect,
 * so we skip the wrapper entirely to avoid type mismatches.
 */

#include_next <string.h>

#include <errno.h>

static inline char *_bsd_strerror_r(int errnum, char *buf, size_t buflen) {
        int r = strerror_r(errnum, buf, buflen);
        if (r != 0)
                return NULL;
        return buf;
}

#ifdef strerror_r
#undef strerror_r
#endif
#define strerror_r(errnum, buf, buflen) _bsd_strerror_r(errnum, buf, buflen)

#else
#include_next <string.h>
#endif
