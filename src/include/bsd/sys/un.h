/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * BSD <sys/un.h> override — provides a Linux-compatible struct sockaddr_un
 * with a 108-byte sun_path (FreeBSD uses 104).
 *
 * We fully redefine the struct instead of relying on SUNPATHLEN, because
 * the system header may be pulled in via #include_next before our override
 * takes effect.
 */

#include <sys/types.h>
#include <sys/socket.h>

#ifdef __cplusplus
extern "C" {
#endif

#define UNIX_PATH_MAX    108

struct sockaddr_un {
        sa_family_t sun_family;
        char sun_path[108];
};

#ifdef __cplusplus
}
#endif
