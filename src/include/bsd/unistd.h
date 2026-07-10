/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <unistd.h>

/* Linux close_range syscall */
int close_range(unsigned int first, unsigned int last, int flags);

/* Linux getrandom */
ssize_t getrandom(void *buf, size_t buflen, unsigned int flags);
