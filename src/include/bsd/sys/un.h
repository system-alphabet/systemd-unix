/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * BSD <sys/un.h> pass-through.
 *
 * We do NOT override struct sockaddr_un here.  FreeBSD's native layout
 * (sun_len + sun_family + sun_path[104]) is compatible with the
 * sockaddr_union overlay in src/basic/socket-util.h, while Linux's
 * layout (sun_family + sun_path[108]) is not.  Keeping our own
 * Linux-compatible definition would put sun_family at a different
 * offset than struct sockaddr.sa_family inside the union, causing
 * socket(2) to receive junk instead of AF_UNIX → EAFNOSUPPORT.
 */

#include_next <sys/un.h>
