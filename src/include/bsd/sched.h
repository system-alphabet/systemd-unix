/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * BSD shim for <sched.h>.
 * FreeBSD provides the POSIX scheduling API; we add the Linux clone()
 * flags that systemd uses for namespace operations and thread spawning.
 */

#include_next <sched.h>

#ifndef CLONE_VM
#define CLONE_VM                        0x00000100
#endif
#ifndef CLONE_PARENT_SETTID
#define CLONE_PARENT_SETTID             0x00100000
#endif
#ifndef CLONE_CHILD_SETTID
#define CLONE_CHILD_SETTID              0x01000000
#endif
#ifndef CLONE_CHILD_CLEARTID
#define CLONE_CHILD_CLEARTID            0x00200000
#endif
#ifndef CLONE_NEWNS
#define CLONE_NEWNS                     0x00020000
#endif
#ifndef CLONE_NEWIPC
#define CLONE_NEWIPC                    0x08000000
#endif
#ifndef CLONE_NEWUSER
#define CLONE_NEWUSER                   0x10000000
#endif
#ifndef CLONE_NEWPID
#define CLONE_NEWPID                    0x20000000
#endif
#ifndef CLONE_NEWNET
#define CLONE_NEWNET                    0x40000000
#endif
#ifndef CLONE_NEWUTS
#define CLONE_NEWUTS                    0x04000000
#endif
#ifndef CLONE_NEWCGROUP
#define CLONE_NEWCGROUP                 0x02000000
#endif
#ifndef CLONE_NEWTIME
#define CLONE_NEWTIME                   0x00000080
#endif
#ifndef CLONE_SETTLS
#define CLONE_SETTLS                    0x00080000
#endif
#ifndef CLONE_PIDFD
#define CLONE_PIDFD                     0x00001000
#endif

#ifndef CLONE_VFORK
#define CLONE_VFORK                     0x00004000
#endif
#ifndef CLONE_VFORK
#define CLONE_VFORK                     0x00004000
#endif

/* Linux scheduling policies not usually present in POSIX <sched.h>. */
#ifndef SCHED_BATCH
#define SCHED_BATCH                     3
#endif
#ifndef SCHED_IDLE
#define SCHED_IDLE                      5
#endif
#ifndef SCHED_EXT
#define SCHED_EXT                       7
#endif
#ifndef SCHED_RESET_ON_FORK
#define SCHED_RESET_ON_FORK             0x40000000
#endif

/* PF_KTHREAD — Linux process flag indicating a kernel thread. */
#ifndef PF_KTHREAD
#define PF_KTHREAD                      0x00200000
#endif

/* setns — Linux namespace switching syscall.  Unavailable on FreeBSD. */
int setns(int fd, int nstype);
