/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * FreeBSD's <sys/types.h> defines major()/minor()/makedev() returning int.
 * Linux defines them in <sys/sysmacros.h> returning unsigned int.
 * On Linux build validation, delegate to the system header.
 */

#ifndef __linux__

#include <sys/types.h>

/* FreeBSD uses __major, __minor, __makedev internally. NetBSD instead defines major()/minor()/makedev()
 * directly in <sys/types.h>, so there is nothing to redirect to there. */

#if !defined(__NetBSD__)
#ifdef major
#undef major
#endif
#ifdef minor
#undef minor
#endif
#ifdef makedev
#undef makedev
#endif

#define major(d)  ((unsigned int)__major(d))
#define minor(d)  ((unsigned int)__minor(d))
#define makedev(maj, min) __makedev((int)(maj), (int)(min))
#else
/* NetBSD's major()/minor() return the signed devmajor_t/devminor_t (= int32_t), while systemd's format
 * strings are written against Linux's unsigned int return type and -Werror=format-signedness rejects the
 * mix. Keep NetBSD's bit decoding, change only the result type. */
#ifdef major
#undef major
#endif
#ifdef minor
#undef minor
#endif

#define major(d)  ((unsigned int)(((uint32_t)(d) & 0x000fff00U) >> 8))
#define minor(d)  ((unsigned int)((((uint32_t)(d) & 0xfff00000U) >> 12) | \
                                  (((uint32_t)(d) & 0x000000ffU) >> 0)))
#endif

#else
#include_next <sys/sysmacros.h>
#endif
