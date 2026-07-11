/* SPDX-License-Identifier: LGPL-2.1-or-later */

/* Stub implementations for Linux-specific syscall shims that are not available on BSD.
 * These exist only so that the code compiles on Linux when -Dlibc=bsd is used for
 * build validation. On a real BSD system, the system libraries would provide these
 * symbols through the BSD compatibility layer in src/libc/bsd/. */

#include <sys/types.h>
#include <stddef.h>
#include <errno.h>
#include <fcntl.h>
#include <spawn.h>
#include <signal.h>
#include <sys/stat.h>

#ifdef __linux__
/* Linux-specific structs needed for shim declarations */
struct open_how;
struct mount_attr;
union bpf_attr;

/* bpf */
int bpf_shim(int cmd, union bpf_attr *attr, size_t size) {
        (void)cmd; (void)attr; (void)size;
        return errno = ENOSYS, -1;
}

/* openat2 */
int openat2_shim(int dfd, const char *filename, const struct open_how *how, size_t usize) {
        (void)dfd; (void)filename; (void)how; (void)usize;
        return errno = ENOSYS, -1;
}

/* kcmp */
int kcmp_shim(pid_t pid1, pid_t pid2, int type, unsigned long idx1, unsigned long idx2) {
        (void)pid1; (void)pid2; (void)type; (void)idx1; (void)idx2;
        return errno = ENOSYS, -1;
}

/* fchmodat2 */
int fchmodat2_shim(int dirfd, const char *path, mode_t mode, int flags) {
        (void)dirfd; (void)path; (void)mode; (void)flags;
        return errno = ENOSYS, -1;
}

/* fsopen */
int fsopen_shim(const char *fsname, unsigned int flags) {
        (void)fsname; (void)flags;
        return errno = ENOSYS, -1;
}

/* fsconfig */
int fsconfig_shim(int fd, unsigned int cmd, const char *key, const void *value, int aux) {
        (void)fd; (void)cmd; (void)key; (void)value; (void)aux;
        return errno = ENOSYS, -1;
}

/* fsmount */
int fsmount_shim(int fd, unsigned int flags, unsigned int ms_flags) {
        (void)fd; (void)flags; (void)ms_flags;
        return errno = ENOSYS, -1;
}

/* move_mount */
int move_mount_shim(int from_dfd, const char *from_pathname, int to_dfd, const char *to_pathname, unsigned int flags) {
        (void)from_dfd; (void)from_pathname; (void)to_dfd; (void)to_pathname; (void)flags;
        return errno = ENOSYS, -1;
}

/* open_tree */
int open_tree_shim(int dfd, const char *filename, unsigned int flags) {
        (void)dfd; (void)filename; (void)flags;
        return errno = ENOSYS, -1;
}

/* open_tree_attr */
int open_tree_attr_shim(int dfd, const char *filename, unsigned int flags, struct mount_attr *attr, size_t size) {
        (void)dfd; (void)filename; (void)flags; (void)attr; (void)size;
        return errno = ENOSYS, -1;
}

/* pivot_root */
int pivot_root_shim(const char *new_root, const char *put_old) {
        (void)new_root; (void)put_old;
        return errno = ENOSYS, -1;
}

/* mount_setattr */
int mount_setattr_shim(int dfd, const char *path, unsigned int flags, struct mount_attr *attr, size_t size) {
        (void)dfd; (void)path; (void)flags; (void)attr; (void)size;
        return errno = ENOSYS, -1;
}

/* get_mempolicy */
int get_mempolicy_shim(int *mode, unsigned long *nodemask, unsigned long maxnode, void *addr, unsigned long flags) {
        (void)mode; (void)nodemask; (void)maxnode; (void)addr; (void)flags;
        return errno = ENOSYS, -1;
}

/* set_mempolicy */
int set_mempolicy_shim(int mode, const unsigned long *nodemask, unsigned long maxnode) {
        (void)mode; (void)nodemask; (void)maxnode;
        return errno = ENOSYS, -1;
}

/* quotactl_fd */
int quotactl_fd_shim(int fd, int cmd, int id, void *addr) {
        (void)fd; (void)cmd; (void)id; (void)addr;
        return errno = ENOSYS, -1;
}

/* pidfd_spawn */
int pidfd_spawn_shim(pid_t *restrict pidfd, const char *restrict path,
                     const posix_spawn_file_actions_t *restrict file_actions,
                     const posix_spawnattr_t *restrict attrp,
                     char *const *restrict argv, char *const *restrict envp) {
        (void)pidfd; (void)path; (void)file_actions; (void)attrp; (void)argv; (void)envp;
        return errno = ENOSYS, -1;
}

/* posix_spawnattr_setcgroup_np */
int posix_spawnattr_setcgroup_np_shim(posix_spawnattr_t *attr, int cgroup) {
        (void)attr; (void)cgroup;
        return errno = ENOSYS, -1;
}

/* rt_tgsigqueueinfo */
int rt_tgsigqueueinfo_shim(pid_t tgid, pid_t tid, int sig, siginfo_t *info) {
        (void)tgid; (void)tid; (void)sig; (void)info;
        return errno = ENOSYS, -1;
}

/* kexec_file_load */
int kexec_file_load_shim(int kernel_fd, int initrd_fd, unsigned long cmdline_len, const char *cmdline_p, unsigned long flags) {
        (void)kernel_fd; (void)initrd_fd; (void)cmdline_len; (void)cmdline_p; (void)flags;
        return errno = ENOSYS, -1;
}
#endif /* __linux__ */
