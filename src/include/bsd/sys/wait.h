/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <sys/wait.h>

/* P_PIDFD — Linux-specific idtype for waitid().
 * Used by src/basic/pidref.c. */
#ifndef P_PIDFD
#define P_PIDFD 3
#endif

/* __WCLONE — Linux wait flag for waiting on clone children (non-SIGCHLD). */
#ifndef __WCLONE
#define __WCLONE 0x80000000
#endif
