/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>

/*
 * Linux <linux/types.h> — kernel type definitions.
 * FreeBSD does not have a linux/types.h, so provide minimal shim.
 */

#ifndef __loff_t_defined
#define __loff_t_defined
typedef int64_t loff_t;
#endif

#ifndef __kernel_ulong_t_defined
#define __kernel_ulong_t_defined
typedef unsigned long __kernel_ulong_t;
#endif

/* Linux kernel integer types (from <asm/types.h> via <linux/types.h>). */
typedef uint8_t  __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;
typedef uint64_t __u64;
typedef int8_t   __s8;
typedef int16_t  __s16;
typedef int32_t  __s32;
typedef int64_t  __s64;

/* Little-endian types used by kernel headers */
typedef uint32_t le32_t;

/* Endian conversion helpers (Linux kernel style).
 * On x86 (little-endian), these are no-ops. */
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define htole32(x) ((uint32_t)(x))
#define le32toh(x) ((uint32_t)(x))
#define htole64(x) ((uint64_t)(x))
#define le64toh(x) ((uint64_t)(x))
#else
#error "Big-endian not yet supported in BSD compat headers"
#endif
