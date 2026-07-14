/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <sys/types.h>

/*
 * Linux <sys/sendfile.h> — sendfile(2) declaration.
 * FreeBSD has sendfile(2) in <sys/socket.h> with incompatible signature.
 * Provide the function under a different name and map via macro.
 */

#include <sys/socket.h>
#include <errno.h>

/* FreeBSD's sendfile conflicts with the Linux signature. Provide
 * an internal wrapper that is called from the compat C file. */
ssize_t _systemd_sendfile(int out_fd, int in_fd, off_t *offset, size_t count);

#define sendfile _systemd_sendfile
