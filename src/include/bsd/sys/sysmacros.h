/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * FreeBSD's <sys/types.h> defines major()/minor()/makedev() returning int.
 * Linux defines them returning unsigned int. Override to match Linux types
 * for format-string compatibility.
 *
 * We need to include <sys/types.h> first to get the internal functions,
 * then undefine the macros and wrap the internal functions.
 */

#include <sys/types.h>

/* FreeBSD uses __major, __minor, __makedev internally */

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
