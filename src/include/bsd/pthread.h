/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <pthread.h>
#include <sched.h>
#ifdef __FreeBSD__
#include <sys/cpuset.h>
typedef cpuset_t cpu_set_t;
#endif

#if defined(__NetBSD__)
/* NetBSD's <pthread.h> declares pthread_setaffinity_np() against its own opaque cpuset_t, which is a
 * completely different type from the Linux-style bitmap cpu_set_t that <sched.h> models for us. Point the
 * name at our implementation so the declaration below and the definition in src/libc/bsd/misc.c stay
 * compatible with what callers pass. */
#define pthread_setaffinity_np(thread, cpusetsize, cpuset) \
        bsd_pthread_setaffinity_np(thread, cpusetsize, cpuset)

/* NetBSD's pthread_setname_np() takes a third argument (an unused void *), while
 * Linux and FreeBSD use the two-argument form systemd calls. Point two-argument
 * calls at the three-argument libc function; the macro is self-referential, so
 * the inner name is not expanded again. */
#define pthread_setname_np(thread, name) \
        pthread_setname_np((thread), (name), NULL)
#endif

/* Linux pthread_setaffinity_np — not available on FreeBSD. */
int pthread_setaffinity_np(pthread_t thread, size_t cpusetsize,
                           const cpu_set_t *cpuset);
