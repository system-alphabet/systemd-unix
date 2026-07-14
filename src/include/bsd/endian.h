/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * BSD <endian.h> — provides __BYTE_ORDER and related macros.
 * FreeBSD defines these in <sys/endian.h> with single underscores.
 * We add the double-underscore aliases that glibc uses.
 */

#include <sys/endian.h>

#ifndef __LITTLE_ENDIAN
#define __LITTLE_ENDIAN _LITTLE_ENDIAN
#endif
#ifndef __BIG_ENDIAN
#define __BIG_ENDIAN    _BIG_ENDIAN
#endif
#ifndef __BYTE_ORDER
#define __BYTE_ORDER    _BYTE_ORDER
#endif
