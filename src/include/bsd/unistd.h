/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <unistd.h>

/* Linux close_range syscall */
int close_range(unsigned int first, unsigned int last, int flags);

/* Linux getrandom */
ssize_t getrandom(void *buf, size_t buflen, unsigned int flags);

/* Linux gettid — returns thread ID as pid_t.
 * FreeBSD through at least 15 does not declare gettid() in any public header. */
pid_t gettid(void);

/* Linux syncfs — sync filesystem referenced by fd.
 * Provided as a stub on FreeBSD. */
int syncfs(int fd);

/* Linux getdents64 — read directory entries.
 * Provided via getdirentries() on FreeBSD. */
ssize_t getdents64(int fd, void *dirp, size_t count);

/* GNU extension: get_current_dir_name — like getcwd but malloc'd. */
char *get_current_dir_name(void);
