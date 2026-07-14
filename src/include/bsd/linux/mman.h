/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* Common MADV_* values (missing on FreeBSD). */
#ifndef MADV_DONTDUMP
#define MADV_DONTDUMP   16
#endif
#ifndef MADV_DODUMP
#define MADV_DODUMP     17
#endif
#ifndef MADV_WIPEONFORK
#define MADV_WIPEONFORK 18
#endif
#ifndef MADV_KEEPONFORK
#define MADV_KEEPONFORK 19
#endif
#ifndef MADV_COLD
#define MADV_COLD       20
#endif
#ifndef MADV_PAGEOUT
#define MADV_PAGEOUT    21
#endif
#ifndef MADV_GUARD_INSTALL
#define MADV_GUARD_INSTALL 102
#endif
#ifndef MADV_GUARD_REMOVE
#define MADV_GUARD_REMOVE 103
#endif
