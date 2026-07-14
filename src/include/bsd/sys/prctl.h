/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <sys/prctl.h> — process control operations.
 * Minimal FreeBSD shim providing only what systemd uses.
 */

#include <sys/types.h>

/* PR_* options used by systemd */
#ifndef PR_SET_PDEATHSIG
#define PR_SET_PDEATHSIG        1
#endif
#ifndef PR_GET_PDEATHSIG
#define PR_GET_PDEATHSIG        2
#endif
#ifndef PR_GET_DUMPABLE
#define PR_GET_DUMPABLE         3
#endif
#ifndef PR_SET_DUMPABLE
#define PR_SET_DUMPABLE         4
#endif
#ifndef PR_SET_NAME
#define PR_SET_NAME             15
#endif
#ifndef PR_GET_NAME
#define PR_GET_NAME             16
#endif
#ifndef PR_SET_SECCOMP
#define PR_SET_SECCOMP          22
#endif
#ifndef PR_CAPBSET_READ
#define PR_CAPBSET_READ         23
#endif
#ifndef PR_CAPBSET_DROP
#define PR_CAPBSET_DROP         24
#endif
#ifndef PR_GET_SECCOMP
#define PR_GET_SECCOMP          21
#endif
#ifndef PR_SET_NO_NEW_PRIVS
#define PR_SET_NO_NEW_PRIVS     38
#endif
#ifndef PR_GET_NO_NEW_PRIVS
#define PR_GET_NO_NEW_PRIVS     39
#endif
#ifndef PR_SET_FP_MODE
#define PR_SET_FP_MODE          45
#endif
#ifndef PR_GET_FP_MODE
#define PR_GET_FP_MODE          46
#endif
#ifndef PR_SET_TIMING
#define PR_SET_TIMING            50
#endif
#ifndef PR_SET_TIMERSLACK
#define PR_SET_TIMERSLACK       29
#endif
#ifndef PR_GET_TIMERSLACK
#define PR_GET_TIMERSLACK       30
#endif
#ifndef PR_SET_CHILD_SUBREAPER
#define PR_SET_CHILD_SUBREAPER  36
#endif
#ifndef PR_GET_CHILD_SUBREAPER
#define PR_GET_CHILD_SUBREAPER  37
#endif
#ifndef PR_SET_MM
#define PR_SET_MM               35
#endif
#ifndef PR_SET_VMA
#define PR_SET_VMA              0x53564d41
#endif

/* PR_SET_MM options */
#ifndef PR_SET_MM_START_CODE
#define PR_SET_MM_START_CODE    1
#endif
#ifndef PR_SET_MM_END_CODE
#define PR_SET_MM_END_CODE      2
#endif
#ifndef PR_SET_MM_START_DATA
#define PR_SET_MM_START_DATA    3
#endif
#ifndef PR_SET_MM_END_DATA
#define PR_SET_MM_END_DATA      4
#endif
#ifndef PR_SET_MM_START_STACK
#define PR_SET_MM_START_STACK   5
#endif
#ifndef PR_SET_MM_START_BRK
#define PR_SET_MM_START_BRK     6
#endif
#ifndef PR_SET_MM_BRK
#define PR_SET_MM_BRK           7
#endif
#ifndef PR_SET_MM_ARG_START
#define PR_SET_MM_ARG_START     8
#endif
#ifndef PR_SET_MM_ARG_END
#define PR_SET_MM_ARG_END       9
#endif
#ifndef PR_SET_MM_ENV_START
#define PR_SET_MM_ENV_START     10
#endif
#ifndef PR_SET_MM_ENV_END
#define PR_SET_MM_ENV_END       11
#endif
#ifndef PR_SET_MM_AUXV
#define PR_SET_MM_AUXV          12
#endif
#ifndef PR_SET_MM_EXE_FILE
#define PR_SET_MM_EXE_FILE      13
#endif
#ifndef PR_SET_MM_MAP
#define PR_SET_MM_MAP           14
#endif
#ifndef PR_SET_MM_MAP_SIZE
#define PR_SET_MM_MAP_SIZE      15
#endif

/* PR_SET_FP_MODE options */
#ifndef PR_FP_MODE_FR
#define PR_FP_MODE_FR           (1 << 0)
#endif
#ifndef PR_FP_MODE_FRE
#define PR_FP_MODE_FRE          (1 << 1)
#endif

/* PR_CAP_AMBIENT — Linux 4.3+ capability bitset control */
#ifndef PR_CAP_AMBIENT
#define PR_CAP_AMBIENT                  47
#  define PR_CAP_AMBIENT_IS_SET         1
#  define PR_CAP_AMBIENT_RAISE          2
#  define PR_CAP_AMBIENT_LOWER          3
#  define PR_CAP_AMBIENT_CLEAR_ALL      4
#endif

/* SECCOMP mode */
#ifndef SECCOMP_MODE_DISABLED
#define SECCOMP_MODE_DISABLED    0
#endif
#ifndef SECCOMP_MODE_STRICT
#define SECCOMP_MODE_STRICT      1
#endif
#ifndef SECCOMP_MODE_FILTER
#define SECCOMP_MODE_FILTER      2
#endif

/* PR_SET_VMA option */
#ifndef PR_SET_VMA_ANON_NAME
#define PR_SET_VMA_ANON_NAME    0
#endif

int prctl(int option, ...);

#ifndef TASK_COMM_LEN
#define TASK_COMM_LEN 16
#endif
