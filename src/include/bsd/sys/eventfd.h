/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Flags */
#define EFD_SEMAPHORE (1 << 0)
#define EFD_CLOEXEC 02000000
#define EFD_NONBLOCK 00004000

typedef uint64_t eventfd_t;

int eventfd(unsigned int initval, int flags);
int eventfd_read(int fd, eventfd_t *value);
int eventfd_write(int fd, eventfd_t value);

#ifdef __cplusplus
}
#endif
