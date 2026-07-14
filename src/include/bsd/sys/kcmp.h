/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <sys/kcmp.h> — kernel comparison syscall constants.
 * FreeBSD stub.
 */

#include <sys/types.h>

#ifndef KCMP_FILE
#define KCMP_FILE 0
#endif
#ifndef KCMP_VM
#define KCMP_VM 1
#endif
#ifndef KCMP_FILES
#define KCMP_FILES 2
#endif
#ifndef KCMP_FS
#define KCMP_FS 3
#endif
#ifndef KCMP_SIGHAND
#define KCMP_SIGHAND 4
#endif
#ifndef KCMP_IO
#define KCMP_IO 5
#endif
#ifndef KCMP_SYSVSEM
#define KCMP_SYSVSEM 6
#endif
#ifndef KCMP_EPOLL_TFD
#define KCMP_EPOLL_TFD 7
#endif

int kcmp(pid_t pid1, pid_t pid2, int type, unsigned long idx1, unsigned long idx2);
