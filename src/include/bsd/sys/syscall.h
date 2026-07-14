/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <sys/syscall.h>

/* Linux-specific syscall numbers for code that must compile on FreeBSD. */

#ifndef __NR_clone
#define __NR_clone 999999  /* Always fails with ENOSYS on FreeBSD */
#endif
