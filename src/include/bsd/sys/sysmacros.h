/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * FreeBSD's <sys/types.h> defines major()/minor()/makedev() returning int.
 * Linux defines them in <sys/sysmacros.h> returning unsigned int.
 * On Linux build validation, delegate to the system header.
 */

#ifndef __linux__

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

#else
#include_next <sys/sysmacros.h>
#endif
