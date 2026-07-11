/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <limits.h>

/* Linux defines HOST_NAME_MAX as 64.  POSIX mandates _POSIX_HOST_NAME_MAX
 * (255 on FreeBSD) but does not require HOST_NAME_MAX.  Provide it so that
 * systemd's hostname-util.c compiles. */
#ifndef HOST_NAME_MAX
#  ifdef _POSIX_HOST_NAME_MAX
#    define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
#  else
#    define HOST_NAME_MAX 64
#  endif
#endif
