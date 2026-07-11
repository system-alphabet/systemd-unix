/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <sys/types.h>
#include <sys/mount.h>

/* FreeBSD has struct statfs in <sys/mount.h>.
 * On 64-bit systems with _FILE_OFFSET_BITS=64, statfs == statfs64. */
typedef __uint32_t statfs_f_type_t;
