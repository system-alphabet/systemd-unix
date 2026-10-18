/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Shim for <sys/random.h>.
 *
 * FreeBSD provides the real header. OpenBSD has neither it nor getrandom().
 * The fork implements getrandom() in src/libc/bsd/misc.c and declares it in
 * <unistd.h>, so only the GRND_* flags are missing here.
 */

#if defined(__has_include_next) && __has_include_next(<sys/random.h>)
#        include_next <sys/random.h>
#else
#        include <sys/types.h>
#        include <stddef.h>
#        include <unistd.h>

#        ifndef GRND_NONBLOCK
#                define GRND_NONBLOCK 0x0001
#        endif
#        ifndef GRND_RANDOM
#                define GRND_RANDOM 0x0002
#        endif
#        ifndef GRND_INSECURE
#                define GRND_INSECURE 0x0004
#        endif
#endif
