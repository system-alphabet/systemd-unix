/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <fcntl.h>

#include <linux/openat2.h>
#include <sys/uio.h>

/* Root of the nsfs filesystem */
#ifndef FD_NSFS_ROOT
#define FD_NSFS_ROOT (-10003)
#endif

/* Linux-specific fcntl commands */
#ifndef F_DUPFD_QUERY
#define F_DUPFD_QUERY 14
#endif
#ifndef F_ADD_SEALS
#define F_ADD_SEALS 1033
#endif
#ifndef F_GET_SEALS
#define F_GET_SEALS 1034
#endif
#ifndef F_SEAL_SEAL
#define F_SEAL_SEAL 0x0001
#endif
#ifndef F_SEAL_SHRINK
#define F_SEAL_SHRINK 0x0002
#endif
#ifndef F_SEAL_GROW
#define F_SEAL_GROW 0x0004
#endif
#ifndef F_SEAL_WRITE
#define F_SEAL_WRITE 0x0008
#endif
#ifndef F_SEAL_EXEC
#define F_SEAL_EXEC 0x0010
#endif
#ifndef F_SEAL_FUTURE_EXEC
#define F_SEAL_FUTURE_EXEC 0x0020
#endif

/* Linux renameat2 flags */
#ifndef RENAME_NOREPLACE
#define RENAME_NOREPLACE (1 << 0)
#endif

/* Open file description (OFD) locks — Linux-specific fcntl commands */
#ifndef F_OFD_GETLK
#define F_OFD_GETLK 36
#endif
#ifndef F_OFD_SETLK
#define F_OFD_SETLK 37
#endif
#ifndef F_OFD_SETLKW
#define F_OFD_SETLKW 38
#endif

/* fallocate() — Linux file space manipulation.  Stub on FreeBSD. */
int fallocate(int fd, int mode, off_t offset, off_t len);

/* fallocate() mode flags */
#ifndef FALLOC_FL_KEEP_SIZE
#define FALLOC_FL_KEEP_SIZE     0x01
#endif
#ifndef FALLOC_FL_PUNCH_HOLE
#define FALLOC_FL_PUNCH_HOLE    0x02
#endif
#ifndef FALLOC_FL_COLLAPSE_RANGE
#define FALLOC_FL_COLLAPSE_RANGE 0x08
#endif
#ifndef FALLOC_FL_ZERO_RANGE
#define FALLOC_FL_ZERO_RANGE    0x10
#endif
#ifndef FALLOC_FL_INSERT_RANGE
#define FALLOC_FL_INSERT_RANGE  0x20
#endif
#ifndef FALLOC_FL_UNSHARE_RANGE
#define FALLOC_FL_UNSHARE_RANGE 0x40
#endif
#ifndef RENAME_EXCHANGE
#define RENAME_EXCHANGE (1 << 1)
#endif
#ifndef RENAME_WHITEOUT
#define RENAME_WHITEOUT (1 << 2)
#endif

/* Linux memfd_create */
#ifndef MFD_CLOEXEC
#define MFD_CLOEXEC 0x0001U
#endif
#ifndef MFD_ALLOW_SEALING
#define MFD_ALLOW_SEALING 0x0002U
#endif
#ifndef MFD_NOEXEC_SEAL
#define MFD_NOEXEC_SEAL 0x0008U
#endif
#ifndef MFD_EXEC
#define MFD_EXEC 0x0010U
#endif

/* Linux AT_* flags - FreeBSD defines different values */
#ifndef AT_NO_AUTOMOUNT
#define AT_NO_AUTOMOUNT  0x800
#endif
#ifndef RESOLVE_NO_SYMLINKS
#define RESOLVE_NO_SYMLINKS     0x01
#endif
#ifndef RESOLVE_IN_ROOT
#define RESOLVE_IN_ROOT         0x10
#endif
#ifndef AT_STATX_SYNC_AS_STAT
#define AT_STATX_SYNC_AS_STAT  0x0000
#endif
#ifndef AT_STATX_FORCE_SYNC
#define AT_STATX_FORCE_SYNC    0x2000
#endif
#ifndef AT_STATX_DONT_SYNC
#define AT_STATX_DONT_SYNC     0x4000
#endif
#ifndef AT_HANDLE_FID
#define AT_HANDLE_FID 0x200
#endif

/* Linux-specific O_* flags */
#ifndef O_DIRECT
#define O_DIRECT 040000
#endif
#ifndef O_NOATIME
#define O_NOATIME 01000000
#endif
#ifndef O_TMPFILE
#define O_TMPFILE (020000000 | O_DIRECTORY)
#endif
#ifndef O_LARGEFILE
#define O_LARGEFILE 0
#endif

/* Linux-specific */
int memfd_create(const char *name, unsigned int flags);
int renameat2(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, unsigned int flags);

/* Linux name_to_handle_at() — filesystem handle operations.
 * Guarded to avoid redefinition on Linux where <bits/fcntl-linux.h> already provides these. */
#ifndef __linux__
struct file_handle {
        unsigned int handle_bytes;
        int handle_type;
        unsigned char f_handle[];
};

int name_to_handle_at(int dirfd, const char *pathname,
                      struct file_handle *handle, int *mnt_id, int flags);
#endif

#ifndef __linux__
int open_by_handle_at(int mount_fd, struct file_handle *handle, int flags);
#endif

#ifndef AT_HANDLE_MNT_ID_UNIQUE
#define AT_HANDLE_MNT_ID_UNIQUE 0x400
#endif

/* Linux pipe buffer size fcntl operations */
#ifndef F_GETPIPE_SZ
#define F_GETPIPE_SZ 1032
#endif
#ifndef F_SETPIPE_SZ
#define F_SETPIPE_SZ 1031
#endif
