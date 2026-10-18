/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <sys/mman.h>

#ifndef MFD_CLOEXEC
#define MFD_CLOEXEC 0x0001U
#endif
#ifndef MFD_ALLOW_SEALING
#define MFD_ALLOW_SEALING 0x0002U
#endif

/*
 * memfd_create(): Linux/glibc <sys/mman.h> and FreeBSD declare it there; NetBSD ≥ 11 too. On OpenBSD and
 * NetBSD < 11 <sys/mman.h> has no such declaration (test-fdstore.c includes only this header, not
 * <fcntl.h>), so repeat it here — a repeat declaration with identical types is legal in C and C++.
 */
int memfd_create(const char *name, unsigned int flags);

/* Linux-specific MAP_* values not present on FreeBSD. */
#ifndef MAP_NORESERVE
#define MAP_NORESERVE   0
#endif

/* mincore() takes a char * vector on FreeBSD and NetBSD, unsigned char * on Linux. */
#if defined(__FreeBSD__) || defined(__NetBSD__)
#define mincore(addr, len, vec) mincore((addr), (len), (char*)(vec))
#endif

/* Linux-specific MADV_* values not present on FreeBSD. */
#ifndef MADV_DONTDUMP
#define MADV_DONTDUMP   16
#endif
#ifndef MADV_DODUMP
#define MADV_DODUMP     17
#endif
#ifndef MADV_WIPEONFORK
#define MADV_WIPEONFORK 18
#endif
#ifndef MADV_KEEPONFORK
#define MADV_KEEPONFORK 19
#endif
#ifndef MADV_COLD
#define MADV_COLD       20
#endif
#ifndef MADV_PAGEOUT
#define MADV_PAGEOUT    21
#endif
#ifndef MADV_GUARD_INSTALL
#define MADV_GUARD_INSTALL 102
#endif
#ifndef MADV_GUARD_REMOVE
#define MADV_GUARD_REMOVE 103
#endif
