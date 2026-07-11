/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Minimal shim replacing glibc's <stdio_ext.h> for FreeBSD.
 * glibc provides __fsetlocking() to control stdio locking.
 * FreeBSD's stdio is thread-safe by default, so this is a no-op.
 */

#ifndef __fsetlocking
#define __fsetlocking(stream, type) (-1)
#endif

/* These constants match glibc's values. */
#ifndef FSETLOCKING_INTERNAL
#define FSETLOCKING_INTERNAL    0
#endif
#ifndef FSETLOCKING_BYCALLER
#define FSETLOCKING_BYCALLER    1
#endif
#ifndef FSETLOCKING_STREAMER
#define FSETLOCKING_STREAMER    2
#endif
