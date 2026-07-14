/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * BSD shim for <sys/mount.h>.
 *
 * FreeBSD provides mount() with a BSD signature (4 arguments) and
 * unmount().  Linux uses mount() with 5 arguments and umount() /
 * umount2().  This shim wraps the BSD calls behind macros so that
 * systemd's Linux-style calls compile (the stubs in linux-stubs.c
 * always return ENOSYS).
 */

#include_next <sys/mount.h>

struct mount_attr;

/* Override FreeBSD's BSD-style mount() with the Linux 5-arg version. */
int mount_linux_shim(const char *source, const char *target,
                     const char *fstype, unsigned long flags, const void *data);
#define mount mount_linux_shim

/* Override FreeBSD's unmount() with Linux umount() / umount2(). */
int umount_linux_shim(const char *target);
#define umount umount_linux_shim

int umount2_linux_shim(const char *target, int flags);
#define umount2 umount2_linux_shim

/* Linux mount flags (from <sys/mount.h>). */
#ifndef MS_RDONLY
#define MS_RDONLY                       1
#endif
#ifndef MS_NOSUID
#define MS_NOSUID                       2
#endif
#ifndef MS_NOEXEC
#define MS_NOEXEC                       8
#endif
#ifndef MS_NODEV
#define MS_NODEV                        4
#endif

/* Linux mount propagation flags (from <linux/mount.h>). */
#ifndef MS_SHARED
#define MS_SHARED                 (1 << 20)
#endif
#ifndef MS_PRIVATE
#define MS_PRIVATE                (1 << 18)
#endif
#ifndef MS_SLAVE
#define MS_SLAVE                  (1 << 19)
#endif
#ifndef MS_UNBINDABLE
#define MS_UNBINDABLE             (1 << 17)
#endif
#ifndef MS_REC
#define MS_REC                    16384
#endif
#ifndef MS_SILENT
#define MS_SILENT                 32768
#endif
#ifndef MS_LAZYTIME
#define MS_LAZYTIME               (1 << 25)
#endif
#ifndef MS_NOSYMFOLLOW
#define MS_NOSYMFOLLOW            256
#endif
#ifndef MS_BIND
#define MS_BIND                   4096
#endif
#ifndef MS_MOVE
#define MS_MOVE                   8192
#endif
#ifndef MS_REMOUNT
#define MS_REMOUNT                32
#endif
#ifndef MS_NOATIME
#define MS_NOATIME                1024
#endif
#ifndef MS_NODIRATIME
#define MS_NODIRATIME             2048
#endif
#ifndef MS_RELATIME
#define MS_RELATIME               0x02000000
#endif
#ifndef MS_STRICTATIME
#define MS_STRICTATIME            0x04000000
#endif
#ifndef MS_SYNCHRONOUS
#define MS_SYNCHRONOUS            16
#endif
#ifndef MS_MANDLOCK
#define MS_MANDLOCK               64
#endif
#ifndef MS_DIRSYNC
#define MS_DIRSYNC                128
#endif
#ifndef MS_POSIXACL
#define MS_POSIXACL               (1 << 16)
#endif
#ifndef MS_KERNMOUNT
#define MS_KERNMOUNT              (1 << 22)
#endif
#ifndef MS_I_VERSION
#define MS_I_VERSION              (1 << 23)
#endif
#ifndef UMOUNT_NOFOLLOW
#define UMOUNT_NOFOLLOW           8
#endif

/* mount_setattr() attributes (struct mount_attr) */
#ifndef MOUNT_ATTR_RDONLY
#define MOUNT_ATTR_RDONLY         0x00000001
#endif
#ifndef MOUNT_ATTR_NOSUID
#define MOUNT_ATTR_NOSUID         0x00000002
#endif
#ifndef MOUNT_ATTR_NODEV
#define MOUNT_ATTR_NODEV          0x00000004
#endif
#ifndef MOUNT_ATTR_NOEXEC
#define MOUNT_ATTR_NOEXEC         0x00000008
#endif
#ifndef MOUNT_ATTR__ATIME
#define MOUNT_ATTR__ATIME         0x00000070
#endif
#ifndef MOUNT_ATTR_RELATIME
#define MOUNT_ATTR_RELATIME       0x00000000
#endif
#ifndef MOUNT_ATTR_NOATIME
#define MOUNT_ATTR_NOATIME        0x00000010
#endif
#ifndef MOUNT_ATTR_STRICTATIME
#define MOUNT_ATTR_STRICTATIME    0x00000020
#endif
#ifndef MOUNT_ATTR_NODIRATIME
#define MOUNT_ATTR_NODIRATIME     0x00000080
#endif
#ifndef MOUNT_ATTR_NOSYMFOLLOW
#define MOUNT_ATTR_NOSYMFOLLOW    0x00200000
#endif
#ifndef MOUNT_ATTR_SIZE_VER0
#define MOUNT_ATTR_SIZE_VER0      32
#endif

/* umount2() flags */
#ifndef MNT_FORCE
#define MNT_FORCE                 1
#endif
#ifndef MNT_DETACH
#define MNT_DETACH                2
#endif
#ifndef MNT_EXPIRE
#define MNT_EXPIRE                4
#endif

/* move_mount() flags */
#ifndef MOVE_MOUNT_F_SYMLINKS
#define MOVE_MOUNT_F_SYMLINKS      0x00000001
#endif
#ifndef MOVE_MOUNT_F_AUTOMOUNTS
#define MOVE_MOUNT_F_AUTOMOUNTS    0x00000002
#endif
#ifndef MOVE_MOUNT_F_EMPTY_PATH
#define MOVE_MOUNT_F_EMPTY_PATH    0x00000004
#endif
#ifndef MOVE_MOUNT_T_SYMLINKS
#define MOVE_MOUNT_T_SYMLINKS      0x00000010
#endif
#ifndef MOVE_MOUNT_T_AUTOMOUNTS
#define MOVE_MOUNT_T_AUTOMOUNTS    0x00000020
#endif
#ifndef MOVE_MOUNT_T_EMPTY_PATH
#define MOVE_MOUNT_T_EMPTY_PATH    0x00000040
#endif
#ifndef MOVE_MOUNT_SET_GROUP
#define MOVE_MOUNT_SET_GROUP       0x00000100
#endif
#ifndef MOVE_MOUNT_BENEATH
#define MOVE_MOUNT_BENEATH         0x00000200
#endif

/* open_tree() flags */
#ifndef AT_RECURSIVE
#define AT_RECURSIVE               0x8000
#endif

/* open_tree() flags */
#ifndef OPEN_TREE_CLOEXEC
#define OPEN_TREE_CLOEXEC         O_CLOEXEC
#endif
#ifndef OPEN_TREE_CLONE
#define OPEN_TREE_CLONE           (1 << 0)
#endif
#ifndef OPEN_TREE_NAMESPACE
#define OPEN_TREE_NAMESPACE       (1 << 1)
#endif

/* fsconfig_command enum values */
#ifndef FSCONFIG_SET_FLAG
#define FSCONFIG_SET_FLAG               0
#endif
#ifndef FSCONFIG_SET_STRING
#define FSCONFIG_SET_STRING             1
#endif
#ifndef FSCONFIG_SET_BINARY
#define FSCONFIG_SET_BINARY             2
#endif
#ifndef FSCONFIG_SET_PATH
#define FSCONFIG_SET_PATH               3
#endif
#ifndef FSCONFIG_SET_PATH_EMPTY
#define FSCONFIG_SET_PATH_EMPTY         4
#endif
#ifndef FSCONFIG_SET_FD
#define FSCONFIG_SET_FD                 5
#endif
#ifndef FSCONFIG_CMD_CREATE
#define FSCONFIG_CMD_CREATE             6
#endif
#ifndef FSCONFIG_CMD_RECONFIGURE
#define FSCONFIG_CMD_RECONFIGURE        7
#endif
#ifndef FSCONFIG_CMD_CREATE_EXCL
#define FSCONFIG_CMD_CREATE_EXCL        8
#endif

/* fsopen() / fsmount() / move_mount() / fsconfig() shims */
#ifndef FSOPEN_CLOEXEC
#define FSOPEN_CLOEXEC            0x00000001
#endif
#ifndef FSMOUNT_CLOEXEC
#define FSMOUNT_CLOEXEC           0x00000001
#endif
#ifndef FSMOUNT_NAMESPACE
#define FSMOUNT_NAMESPACE         0x00000002
#endif
#ifndef MOVE_MOUNT_F_SYMLINKS
#define MOVE_MOUNT_F_SYMLINKS     0x00000001
#endif
#ifndef MOVE_MOUNT_F_AUTOMOUNTS
#define MOVE_MOUNT_F_AUTOMOUNTS   0x00000002
#endif

int fsopen_shim(const char *fsname, unsigned flags);
#define fsopen fsopen_shim

int fsmount_shim(int fd, unsigned flags, unsigned ms_flags);
#define fsmount fsmount_shim

int move_mount_shim(int from_dfd, const char *from_pathname,
                    int to_dfd, const char *to_pathname, unsigned flags);
#define move_mount move_mount_shim

int fsconfig_shim(int fd, unsigned cmd, const char *key,
                  const void *value, int aux);
#define fsconfig fsconfig_shim

int open_tree_shim(int dfd, const char *filename, unsigned flags);
#define open_tree open_tree_shim

/* MOUNT_ATTR_* constants */
#ifndef MOUNT_ATTR_RDONLY
#define MOUNT_ATTR_RDONLY               0x00000001
#endif
#ifndef MOUNT_ATTR_NOSUID
#define MOUNT_ATTR_NOSUID               0x00000002
#endif
#ifndef MOUNT_ATTR_NODEV
#define MOUNT_ATTR_NODEV                0x00000004
#endif
#ifndef MOUNT_ATTR_NOEXEC
#define MOUNT_ATTR_NOEXEC               0x00000008
#endif
#ifndef MOUNT_ATTR_IDMAP
#define MOUNT_ATTR_IDMAP                0x00100000
#endif

#ifndef __linux__
struct mount_attr {
        uint64_t attr_set;
        uint64_t attr_clr;
        uint64_t propagation;
        uint64_t userns_fd;
};
#endif

int mount_setattr_shim(int dfd, const char *path, unsigned flags,
                       struct mount_attr *attr, size_t size);
#define mount_setattr mount_setattr_shim

int open_tree_attr_shim(int dfd, const char *filename, unsigned int flags,
                        struct mount_attr *attr, size_t size);
#define open_tree_attr open_tree_attr_shim
