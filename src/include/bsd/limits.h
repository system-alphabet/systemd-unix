/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <limits.h>

#ifndef LINE_MAX
#  define LINE_MAX 2048
#endif

/* SSIZE_MAX is required by POSIX but may not be visible when our compat
 * header is the first to include <limits.h>.  Provide a safe fallback. */
#ifndef SSIZE_MAX
#  ifdef __linux__
/* On Linux LONG_MAX is always available via <bits/limits.h> */
#    include <bits/limits.h>
#  endif
#  ifndef SSIZE_MAX
#    define SSIZE_MAX ((ssize_t)(~(size_t)0 >> 1))
#  endif
#endif

/* IOV_MAX is in <sys/uio.h> on Linux.  Provide a fallback for code that
 * expects it from <limits.h>. */
#ifndef IOV_MAX
#  define IOV_MAX 1024
#endif

#ifndef HOST_NAME_MAX
#  ifdef _POSIX_HOST_NAME_MAX
#    define HOST_NAME_MAX _POSIX_HOST_NAME_MAX
#  else
#    define HOST_NAME_MAX 64
#  endif
#endif
