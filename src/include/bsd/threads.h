/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Shim for C11 <threads.h>.
 *
 * FreeBSD provides the real header. OpenBSD has no <threads.h> whatsoever,
 * and the only thing systemd ever pulls from it is the thread_local macro.
 */

#if defined(__has_include_next) && __has_include_next(<threads.h>)
#        include_next <threads.h>
#elif !defined(thread_local)
#        define thread_local _Thread_local
#endif
