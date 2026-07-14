/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <sys/stat.h>

/*
 * Linux statx() — extended stat system call.
 * FreeBSD does not have statx(); these definitions allow code that
 * references struct statx / STATX_* to compile.
 * The actual statx() call is a stub that returns ENOSYS.
 */

#include <stdint.h>

#ifndef STATX_TYPE
#define STATX_TYPE              0x00000001U
#endif
#ifndef STATX_MODE
#define STATX_MODE              0x00000002U
#endif
#ifndef STATX_NLINK
#define STATX_NLINK             0x00000004U
#endif
#ifndef STATX_UID
#define STATX_UID               0x00000008U
#endif
#ifndef STATX_GID
#define STATX_GID               0x00000010U
#endif
#ifndef STATX_ATIME
#define STATX_ATIME             0x00000020U
#endif
#ifndef STATX_MTIME
#define STATX_MTIME             0x00000040U
#endif
#ifndef STATX_CTIME
#define STATX_CTIME             0x00000080U
#endif
#ifndef STATX_INO
#define STATX_INO               0x00000100U
#endif
#ifndef STATX_SIZE
#define STATX_SIZE              0x00000200U
#endif
#ifndef STATX_BLOCKS
#define STATX_BLOCKS            0x00000400U
#endif
#ifndef STATX_BASIC_STATS
#define STATX_BASIC_STATS       0x000007FFU
#endif
#ifndef STATX_BTIME
#define STATX_BTIME             0x00000800U
#endif
#ifndef STATX_MNT_ID
#define STATX_MNT_ID            0x00001000U
#endif
#ifndef STATX_DIOALIGN
#define STATX_DIOALIGN          0x00002000U
#endif
#ifndef STATX_MNT_ID_UNIQUE
#define STATX_MNT_ID_UNIQUE     0x00004000U
#endif
#ifndef STATX_SUBVOL
#define STATX_SUBVOL            0x00008000U
#endif
#ifndef STATX_INO_VERSION
#define STATX_INO_VERSION       0x00010000U
#endif
#ifndef STATX_WRITE_ATOMIC
#define STATX_WRITE_ATOMIC      0x00010000U
#endif
#ifndef STATX_DIO_READ_ALIGN
#define STATX_DIO_READ_ALIGN    0x00020000U
#endif
#ifndef STATX_ALL
#define STATX_ALL               0x00000FFF
#endif

/* Attributes */
#ifndef STATX_ATTR_COMPRESSED
#define STATX_ATTR_COMPRESSED   0x00000004
#endif
#ifndef STATX_ATTR_IMMUTABLE
#define STATX_ATTR_IMMUTABLE    0x00000010
#endif
#ifndef STATX_ATTR_APPEND
#define STATX_ATTR_APPEND       0x00000020
#endif
#ifndef STATX_ATTR_NODUMP
#define STATX_ATTR_NODUMP       0x00000040
#endif
#ifndef STATX_ATTR_ENCRYPTED
#define STATX_ATTR_ENCRYPTED    0x00000800
#endif
#ifndef STATX_ATTR_AUTOMOUNT
#define STATX_ATTR_AUTOMOUNT    0x00001000
#endif
#ifndef STATX_ATTR_MOUNT_ROOT
#define STATX_ATTR_MOUNT_ROOT   0x00002000
#endif
#ifndef STATX_ATTR_VERITY
#define STATX_ATTR_VERITY       0x00100000
#endif
#ifndef STATX_ATTR_DAX
#define STATX_ATTR_DAX          0x00200000
#endif
#ifndef STATX_ATTR_WRITE_ATOMIC
#define STATX_ATTR_WRITE_ATOMIC 0x00400000
#endif

/* Guard statx definitions to avoid redefinition on Linux where <linux/stat.h> already provides them. */
#ifndef __linux__

struct statx_timestamp {
        int64_t  tv_sec;
        uint32_t tv_nsec;
        int32_t  tv_pad;
};

struct statx {
        uint32_t                stx_mask;
        uint32_t                stx_blksize;
        uint64_t                stx_attributes;
        uint32_t                stx_nlink;
        uint32_t                stx_uid;
        uint32_t                stx_gid;
        uint16_t                stx_mode;
        uint16_t                stx_pad1;
        uint64_t                stx_ino;
        uint64_t                stx_size;
        uint64_t                stx_blocks;
        uint64_t                stx_attributes_mask;
        struct statx_timestamp  stx_atime;
        struct statx_timestamp  stx_btime;
        struct statx_timestamp  stx_ctime;
        struct statx_timestamp  stx_mtime;
        uint32_t                stx_rdev_major;
        uint32_t                stx_rdev_minor;
        uint32_t                stx_dev_major;
        uint32_t                stx_dev_minor;
        uint64_t                stx_mnt_id;
        uint32_t                stx_dio_mem_align;
        uint32_t                stx_dio_offset_align;
        uint64_t                stx_subvol;
        uint64_t                stx_ino_version;
        uint64_t                stx_write_atomic_size_unit;
        uint64_t                stx_pad[8];
};

int statx(int dirfd, const char *pathname, int flags,
          unsigned int mask, struct statx *statxbuf);

#endif /* __linux__ */

/* fchmodat2 — Linux syscall wrapper.  Stub on FreeBSD. */
int fchmodat2(int dirfd, const char *pathname, mode_t mode, int flags);
