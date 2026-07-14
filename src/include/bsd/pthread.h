/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <pthread.h>
#include <sched.h>
#ifdef __FreeBSD__
#include <sys/cpuset.h>
typedef cpuset_t cpu_set_t;
#endif

/* Linux pthread_setaffinity_np — not available on FreeBSD. */
int pthread_setaffinity_np(pthread_t thread, size_t cpusetsize,
                           const cpu_set_t *cpuset);
