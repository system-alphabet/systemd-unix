/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <sys/types.h>
#include <sys/mount.h>

/* FreeBSD has struct statfs in <sys/mount.h>.
 * On 64-bit systems with _FILE_OFFSET_BITS=64, statfs == statfs64.
 * Guard with __linux__ so we don't conflict with stat-util.h on Linux build validation. */
#ifndef __linux__

#if defined(__NetBSD__)
/*
 * NetBSD has statfs(2) in libc but exposes no struct statfs to userspace — the kernel's layout is a
 * private <sys/syscallargs.h> detail — and its <sys/mount.h> only knows struct statvfs. Build a struct
 * statfs with the fields systemd actually reads on top of statvfs, and route the two calls through it.
 *
 * f_type has no counterpart: NetBSD does not publish a superblock magic, and src/libc/bsd/misc.c already
 * stubs out fs_in_group()/filesystem_sets() on BSD, so leaving it zero keeps every is_fs_type() comparison
 * false, which is exactly what Linux-specific constants such as CGROUP_SUPER_MAGIC should mean here.
 */
#include <sys/statvfs.h>
#include <stdint.h>
#include <string.h>

typedef __uint32_t statfs_f_type_t;

struct statfs {
        statfs_f_type_t f_type;
        uint64_t        f_flags;
        uint64_t        f_bsize;
        uint64_t        f_frsize;
        uint64_t        f_iosize;
        uint64_t        f_blocks;
        uint64_t        f_bfree;
        uint64_t        f_bavail;
        uint64_t        f_files;
        uint64_t        f_ffree;
        uint64_t        f_fsid;
        uint64_t        f_namemax;
        char            f_fstypename[32];
};

static inline void statfs_from_statvfs(struct statfs *ret, const struct statvfs *v) {
        *ret = (struct statfs) {
                .f_bsize    = v->f_bsize,
                .f_frsize   = v->f_frsize,
                .f_iosize   = v->f_iosize,
                .f_blocks   = v->f_blocks,
                .f_bfree    = v->f_bfree,
                .f_bavail   = v->f_bavail,
                .f_files    = v->f_files,
                .f_ffree    = v->f_ffree,
                .f_flags    = v->f_flag,
                .f_fsid     = v->f_fsid,
                .f_namemax  = v->f_namemax,
        };

        memcpy(ret->f_fstypename, v->f_fstypename, sizeof(ret->f_fstypename));
}

static inline int statfs(const char *path, struct statfs *ret) {
        struct statvfs v;

        if (statvfs(path, &v) < 0)
                return -1;

        statfs_from_statvfs(ret, &v);
        return 0;
}

static inline int fstatfs(int fd, struct statfs *ret) {
        struct statvfs v;

        if (fstatvfs(fd, &v) < 0)
                return -1;

        statfs_from_statvfs(ret, &v);
        return 0;
}

#else

typedef __uint32_t statfs_f_type_t;

#endif

#else
/* On Linux, struct statfs is defined by the system <sys/statfs.h>.
 * Include it via include_next so that stat-util.h can derive statfs_f_type_t from it. */
#include_next <sys/statfs.h>
#endif
