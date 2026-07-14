/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* Stub for Linux seccomp headers. seccomp is disabled on FreeBSD builds
 * (-Dseccomp=false), but seccomp-util.c still includes this header. */

#include <stdint.h>
#include <linux/types.h>

/* seccomp() syscall operations */
#define SECCOMP_SET_MODE_STRICT       0
#define SECCOMP_SET_MODE_FILTER       1
#define SECCOMP_GET_ACTION_AVAIL      2
#define SECCOMP_GET_NOTIF_SIZES       3

/* seccomp filter return values */
#define SECCOMP_RET_KILL_PROCESS      0x80000000U
#define SECCOMP_RET_KILL_THREAD       0x00000000U
#define SECCOMP_RET_TRAP              0x00030000U
#define SECCOMP_RET_ERRNO             0x00050000U
#define SECCOMP_RET_TRACE             0x7ff00000U
#define SECCOMP_RET_LOG               0x7ffc0000U
#define SECCOMP_RET_ALLOW             0x7fff0000U
#define SECCOMP_RET_ACTION_FULL       0xffff0000U
#define SECCOMP_RET_DATA              (~SECCOMP_RET_ACTION_FULL)

/* seccomp filter flags */
#define SECCOMP_FILTER_FLAG_TSYNC             1
#define SECCOMP_FILTER_FLAG_LOG               2
#define SECCOMP_FILTER_FLAG_SPEC_ALLOW        4
#define SECCOMP_FILTER_FLAG_NEW_LISTENER      8
#define SECCOMP_FILTER_FLAG_TSYNC_ESRCH       16

/* seccomp data structures */
struct seccomp_data {
        int   nr;
        __u32 arch;
        __u64 instruction_pointer;
        __u64 args[6];
};

struct seccomp_notif_sizes {
        __u16 seccomp_notif;
        __u16 seccomp_notif_resp;
        __u16 seccomp_data;
};

/* SECCOMP_IOCTL_NOTIF_* */
#define SECCOMP_IOCTL_NOTIF_RECV     _IOWR(0x21, 0, struct seccomp_notif)
#define SECCOMP_IOCTL_NOTIF_SEND     _IOWR(0x21, 1, struct seccomp_notif_resp)
#define SECCOMP_IOCTL_NOTIF_ID_VALID _IOW(0x21, 2, __u64)
#define SECCOMP_IOCTL_NOTIF_ADDFD    _IOW(0x21, 3, struct seccomp_notif_addfd)

/* seccomp user notify structures */
struct seccomp_notif {
        __u64 id;
        __u32 pid;
        __u32 flags;
        struct seccomp_data data;
};

struct seccomp_notif_resp {
        __u64 id;
        __s64 val;
        __s32 error;
        __u32 flags;
};

#define SECCOMP_USER_NOTIF_FLAG_CONTINUE 1

struct seccomp_notif_addfd {
        __u64 id;
        __u32 flags;
        __u32 srcfd;
        __u32 newfd;
        __u32 newfd_flags;
};
