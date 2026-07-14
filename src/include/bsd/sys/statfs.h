/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <sys/types.h>
#include <sys/mount.h>

/* FreeBSD has struct statfs in <sys/mount.h>.
 * On 64-bit systems with _FILE_OFFSET_BITS=64, statfs == statfs64.
 * Guard with __linux__ so we don't conflict with stat-util.h on Linux build validation. */
#ifndef __linux__
typedef __uint32_t statfs_f_type_t;
#else
/* On Linux, struct statfs is defined by the system <sys/statfs.h>.
 * Include it via include_next so that stat-util.h can derive statfs_f_type_t from it. */
#include_next <sys/statfs.h>
#endif
