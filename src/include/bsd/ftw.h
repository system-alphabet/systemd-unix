/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <ftw.h>

/*
 * Glibc nftw() callback return values (GNU extensions).
 * FreeBSD's <ftw.h> only defines the basic FTW_* flags.
 */
#ifndef FTW_CONTINUE
#define FTW_CONTINUE    0
#endif
#ifndef FTW_STOP
#define FTW_STOP        1
#endif
#ifndef FTW_SKIP_SUBTREE
#define FTW_SKIP_SUBTREE 2
#endif
#ifndef FTW_SKIP_SIBLINGS
#define FTW_SKIP_SIBLINGS 3
#endif
#ifndef FTW_ACTIONRETVAL
#define FTW_ACTIONRETVAL 0x10
#endif
