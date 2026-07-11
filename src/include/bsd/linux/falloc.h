/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* Linux fallocate() flags, for compatibility on FreeBSD.
 * These are used by src/basic/fs-util.c. */

#ifndef FALLOC_FL_KEEP_SIZE
#define FALLOC_FL_KEEP_SIZE     0x01
#endif
#ifndef FALLOC_FL_PUNCH_HOLE
#define FALLOC_FL_PUNCH_HOLE    0x02
#endif
#ifndef FALLOC_FL_COLLAPSE_RANGE
#define FALLOC_FL_COLLAPSE_RANGE 0x08
#endif
#ifndef FALLOC_FL_ZERO_RANGE
#define FALLOC_FL_ZERO_RANGE    0x10
#endif
#ifndef FALLOC_FL_INSERT_RANGE
#define FALLOC_FL_INSERT_RANGE  0x20
#endif
#ifndef FALLOC_FL_UNSHARE_RANGE
#define FALLOC_FL_UNSHARE_RANGE 0x40
#endif
