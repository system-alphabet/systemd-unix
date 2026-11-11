/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/io_uring.h> — reuse the vendored UAPI definitions so that the io_uring types and
 * constants are available on FreeBSD. The io_uring syscalls themselves do not exist there, hence
 * the __NR_* numbers in <sys/syscall.h> always fail with ENOSYS and the callers fall back.
 */
#include "../../uapi/linux/stddef.h"
#include "../../uapi/linux/io_uring.h"
