/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Shim for <byteswap.h>.
 *
 * FreeBSD ships a glibc-compatible <byteswap.h> providing bswap_16/32/64().
 * OpenBSD has no such header at all, but its <endian.h> already covers the
 * htobe*() / *toh() family, so only the plain byte-reversal helpers are
 * missing there. Clang and GCC both provide those as builtins.
 */

#if defined(__has_include_next) && __has_include_next(<byteswap.h>)
#        include_next <byteswap.h>
#else
#        define bswap_16(x) __builtin_bswap16(x)
#        define bswap_32(x) __builtin_bswap32(x)
#        define bswap_64(x) __builtin_bswap64(x)
#endif
