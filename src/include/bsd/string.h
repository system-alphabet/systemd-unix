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

/*
 * explicit_bzero() — securely zero memory. FreeBSD, OpenBSD and DragonFly declare it in their headers, but
 * NetBSD has never provided it (its libc exports only plain bzero(), which a compiler is free to optimize
 * away), so supply it ourselves.
 */
#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__DragonFly__) && !defined(__APPLE__)
static inline void explicit_bzero(void *p, size_t n) {
        volatile unsigned char *v = (volatile unsigned char *) p;
        while (n-- > 0)
                *v++ = 0;
}
#endif

/*
 * mempcpy() — copy n bytes and return the destination pointer past the last byte written. FreeBSD and
 * NetBSD ≥ 11 declare it in <string.h>; OpenBSD and NetBSD < 11 do not, so supply it ourselves.
 */
#if defined(__NetBSD__)
#include <sys/param.h> /* for __NetBSD_Prereq__() */
#endif

/* __NetBSD_Prereq__() only exists on NetBSD, so it must not be referenced from a
 * preprocessor expression that is evaluated on other platforms. */
#if defined(__OpenBSD__)
#define NEED_MEMPCPY 1
#elif defined(__NetBSD__)
#if !__NetBSD_Prereq__(11, 0, 0)
#define NEED_MEMPCPY 1
#endif
#endif

#ifdef NEED_MEMPCPY
static inline void *mempcpy(void *dest, const void *src, size_t n) {
        return (char *) memcpy(dest, src, n) + n;
}
#endif

#else
#include_next <string.h>
#endif
