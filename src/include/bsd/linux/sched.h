/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/sched.h> — CLONE_* constants.
 * Used by src/basic/process-util.c, src/basic/raw-clone.c,
 * src/basic/namespace-util.c.
 */

#ifndef CLONE_VM
#define CLONE_VM                0x00000100
#endif
#ifndef CLONE_VFORK
#define CLONE_VFORK             0x00004000
#endif
#ifndef CLONE_PARENT_SETTID
#define CLONE_PARENT_SETTID     0x00100000
#endif
#ifndef CLONE_CHILD_SETTID
#define CLONE_CHILD_SETTID      0x01000000
#endif
#ifndef CLONE_CHILD_CLEARTID
#define CLONE_CHILD_CLEARTID    0x00200000
#endif
#ifndef CLONE_SETTLS
#define CLONE_SETTLS            0x00080000
#endif
#ifndef CLONE_SIGHAND
#define CLONE_SIGHAND           0x00000800
#endif
#ifndef CLONE_THREAD
#define CLONE_THREAD            0x00010000
#endif
#ifndef CLONE_NEWNS
#define CLONE_NEWNS             0x00020000
#endif
#ifndef CLONE_NEWIPC
#define CLONE_NEWIPC            0x08000000
#endif
#ifndef CLONE_NEWUSER
#define CLONE_NEWUSER           0x10000000
#endif
#ifndef CLONE_NEWPID
#define CLONE_NEWPID            0x20000000
#endif
#ifndef CLONE_NEWNET
#define CLONE_NEWNET            0x40000000
#endif
#ifndef CLONE_NEWUTS
#define CLONE_NEWUTS            0x04000000
#endif
#ifndef CLONE_NEWCGROUP
#define CLONE_NEWCGROUP         0x02000000
#endif
#ifndef CLONE_NEWTIME
#define CLONE_NEWTIME           0x00000080
#endif
#ifndef CLONE_PIDFD
#define CLONE_PIDFD             0x00001000
#endif
#ifndef CLONE_INTO_CGROUP
#define CLONE_INTO_CGROUP       0x200000000ULL
#endif
