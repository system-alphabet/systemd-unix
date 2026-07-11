/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <linux/nsfs.h> — namespace file descriptor definitions.
 * Minimal FreeBSD shim for compilation purposes.
 */

#include <stdint.h>

#ifndef NSIO
#define NSIO    0xb7
#endif

#ifndef NS_GET_USERNS
#define NS_GET_USERNS   _IO(NSIO, 0x1)
#endif
#ifndef NS_GET_PARENT
#define NS_GET_PARENT   _IO(NSIO, 0x2)
#endif
#ifndef NS_GET_NSTYPE
#define NS_GET_NSTYPE   _IO(NSIO, 0x3)
#endif
#ifndef NS_GET_OWNER_UID
#define NS_GET_OWNER_UID _IO(NSIO, 0x4)
#endif

/* NSFS_MAGIC moved to linux/magic.h */
#ifndef NSFS_MAGIC
#define NSFS_MAGIC      0x6E736364
#endif

/* struct nsfs_file_handle (kernel uapi since v6.18) */
struct nsfs_file_handle {
        uint8_t         pad[8];
};

/* PROC_*_INIT_INO — procfs inode numbers for the initial namespace objects. */
#ifndef PROC_CGROUP_INIT_INO
#define PROC_CGROUP_INIT_INO    0xEFFFFFFBU
#endif
#ifndef PROC_IPC_INIT_INO
#define PROC_IPC_INIT_INO       0xEFFFFFFEU
#endif
#ifndef PROC_PID_INIT_INO
#define PROC_PID_INIT_INO       0xEFFFFFFCU
#endif
#ifndef PROC_USER_INIT_INO
#define PROC_USER_INIT_INO      0xEFFFFFFDU
#endif
#ifndef PROC_UTS_INIT_INO
#define PROC_UTS_INIT_INO       0xEFFFFFFAU
#endif
#ifndef PROC_TIME_INIT_INO
#define PROC_TIME_INIT_INO      0xEFFFFFF9U
#endif
