/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <unistd.h>
#include <assert.h>
#include <endian.h>
#include <sys/uio.h>

/* Linux close_range syscall */
int close_range(unsigned int first, unsigned int last, int flags);

/* Linux getrandom */
ssize_t getrandom(void *buf, size_t buflen, unsigned int flags);

/* Linux gettid — returns thread ID as pid_t.
 * FreeBSD through at least 15 does not declare gettid() in any public header. */
pid_t gettid(void);

/* Linux syncfs — sync filesystem referenced by fd.
 * Provided as a stub on FreeBSD. */
int syncfs(int fd);

/* Linux getdents64 — read directory entries.
 * Provided via getdirentries() on FreeBSD. */
ssize_t getdents64(int fd, void *dirp, size_t count);

/* GNU extension: get_current_dir_name — like getcwd but malloc'd. */
char *get_current_dir_name(void);

/* environ — declared for strict POSIX compliance; FreeBSD's <unistd.h> may not
 * expose it under _GNU_SOURCE. */
extern char **environ;

/* Linux pivot_root — redirect to shim (via override header pattern) */
int pivot_root_shim(const char *new_root, const char *put_old);
#define pivot_root pivot_root_shim

/* Linux splice syscall — not available on FreeBSD */
ssize_t splice(int fd_in, off_t *off_in, int fd_out, off_t *off_out,
               size_t len, unsigned int flags);

#if defined(__NetBSD__)
/* NetBSD has neither the setresuid(2)/setresgid(2) syscalls nor
 * getresuid(2)/getresgid(2), and its headers declare none of them. ENOSYS stubs
 * live in src/libc/bsd/misc.c; callers already treat failure as "cannot change
 * credentials", which is the safe outcome. */
int setresuid(uid_t ruid, uid_t euid, uid_t suid);
int setresgid(gid_t rgid, gid_t egid, gid_t sgid);
int getresuid(uid_t *ruid, uid_t *euid, uid_t *suid);
int getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid);

/* NetBSD's reboot(2) takes a second argument — the path of the boot program to
 * exec, or NULL for the default — where Linux takes only the command. The
 * declaration from <unistd.h> above is processed before this macro, so it stays
 * intact; call sites like reboot(RB_HALT_SYSTEM) pick up the extra argument. */
#define reboot(howto) reboot((howto), NULL)
#endif

/* SPLICE_F_* flags */
#ifndef SPLICE_F_MOVE
#define SPLICE_F_MOVE            1
#endif
#ifndef SPLICE_F_NONBLOCK
#define SPLICE_F_NONBLOCK        2
#endif
#ifndef SPLICE_F_MORE
#define SPLICE_F_MORE            4
#endif
#ifndef SPLICE_F_GIFT
#define SPLICE_F_GIFT            8
#endif

/* SEEK_DATA/SEEK_HOLE — Linux lseek(2) commands for sparse-file navigation.
 * FreeBSD and OpenBSD define these natively in <fcntl.h>; NetBSD has neither
 * the constants nor lseek support for them, so give it the Linux values — the
 * kernel rejects them with EINVAL, which callers treat as "no hole data
 * available". */
#ifndef SEEK_DATA
#define SEEK_DATA               3
#endif
#ifndef SEEK_HOLE
#define SEEK_HOLE               4
#endif
