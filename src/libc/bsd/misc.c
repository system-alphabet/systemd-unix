/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <signal.h>
#ifdef __FreeBSD__
#include <pthread_np.h>
#endif
#ifdef __FreeBSD__
#include <sys/event.h>
#include <sys/pidfd.h>
#endif
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/mount.h>
#include <malloc.h>
#include <sys/personality.h>
#include <sys/prctl.h>
#include <sys/pidfd.h>
#include <sys/kcmp.h>
#include <shadow.h>
#include <gshadow.h>
#include <linux/openat2.h>
#include <linux/fs.h>
#include <sched.h>
#include <spawn.h>
#include <dirent.h>
#include <pwd.h>
#include <shadow.h>
#include <stdbool.h>
#include <mqueue.h>
#include <sys/resource.h>
#include <sys/vfs.h>
#include <sys/auxv.h>
#include <grp.h>
#include <gshadow.h>
#include <pthread.h>

/* Forward declarations for stub functions whose system headers don't exist on FreeBSD */
unsigned int parse_printf_format(const char *fmt, size_t n, int *types);
const char *capability_to_name(int cap);
struct sd_netlink;
typedef int ResolveInterfaceNameFlag;
int rtnl_resolve_ifname_full(struct sd_netlink **rtnl, ResolveInterfaceNameFlag flags, const char *name, char **ret_name, char ***ret_altnames);
struct hw_addr_data;
int rtnl_get_link_info_full(struct sd_netlink **rtnl, int ifindex, char **ret_name, char ***ret_altnames, unsigned short *ret_iftype, unsigned *ret_flags, char **ret_kind, struct hw_addr_data *ret_hw_addr, struct hw_addr_data *ret_permanent_hw_addr);
int copy_tree_at_full(int fdf, const char *from, int fdt, const char *to, uid_t override_uid, gid_t override_gid, unsigned int copy_flags, void *denylist, void *subvolumes, void *progress_path, void *progress_bytes, void *userdata);
int image_path_lock(int scope, const char *path, int operation, void *global, void *local);
int sd_netlink_open(void **ret);
int sd_netlink_call(void *rtnl, void *m, uint64_t timeout, void **ret_reply);
int sd_netlink_message_get_errno(void *m);
int sd_netlink_message_get_type(void *m, uint16_t *type);
void *sd_netlink_message_next(void *m);
int sd_netlink_message_read_u32(void *m, unsigned short attr, uint32_t *ret);
int sd_netlink_message_read_data(void *m, unsigned short attr, size_t *ret_size, void **ret_data);
int sd_netlink_message_append_s32(void *m, unsigned short attr, int32_t val);
void *sd_netlink_message_unref(void *m);
void *sd_netlink_unref(void *rtnl);
int sd_rtnl_message_new_nsid(void *rtnl, void **ret, uint16_t type, int ifindex);
int sd_sock_diag_socket_open(void);
int sd_sock_diag_message_new_unix(void *sock_diag, void **ret, int family);

/* Capability utility stubs */
unsigned long capability_from_name(const char *name);
int capability_set_to_string(const void *c, char **ret);
int capability_set_to_string_negative(const void *c, char **ret);

/* Additional stub forward declarations */
int sd_netlink_message_open_container(void *m, uint16_t attr_type);
int sd_netlink_message_close_container(void *m);
int sd_netlink_message_append_data(void *m, uint16_t attr_type, const void *data, size_t len);
const char *arphrd_to_name(int id);
int arphrd_to_hw_addr_len(int id);
int copy_bytes_full(int fdf, int fdt, uint64_t max_bytes, unsigned int copy_flags,
                    void **ret_remains, size_t *ret_remains_size,
                    void *progress, void *userdata);
void *dissected_image_unref(void *m);
int dissect_loop_device_and_warn(void *loop, const void *verity, const void *mount_options,
                                 const void *image_policy, const void *image_filter,
                                 unsigned int flags, void **ret);
int dissected_image_decrypt(void *m, const char *root, const char *passphrase,
                            const void *verity, const void *image_policy,
                            unsigned int flags);
int dissected_image_mount(void *m, const char *where, uid_t uid_shift, uid_t uid_range,
                          int userns_fd, unsigned int flags);
int dissected_image_guess_verity_roothash(void *m, void *verity);
int dissected_image_load_verity_sig_partition(void *m, int fd, void *verity);
int dissected_image_relinquish(void *m);
int mount_image_privately_interactively(const char *image, const void *image_policy,
                                        unsigned int flags, char **ret_directory,
                                        int *ret_dir_fd, void **ret_loop_device);
void verity_settings_done(void *verity);
int mountfsd_connect(void **ret);
int mountfsd_mount_image_fd(void *vl, int image_fd, int userns_fd,
                            const void *options, const void *image_policy,
                            const void *verity, unsigned int flags, void **ret);
int mountfsd_mount_directory_fd(void *vl, int directory_fd, int userns_fd,
                                unsigned int flags, int *ret_mount_fd);
const char *nl80211_iftype_to_string(int i);
int quotactl_fd(int fd, int cmd, int id, void *addr);
int get_mempolicy(int *mode, unsigned long *nodemask, unsigned long maxnode,
                  void *addr, unsigned long flags);
int set_mempolicy(int mode, const unsigned long *nodemask, unsigned long maxnode);
int sd_netlink_message_append_u32(void *m, unsigned short attr, uint32_t val);
int sd_netlink_message_append_in_addr(void *m, unsigned short attr, const void *in);
int sd_netlink_message_append_in6_addr(void *m, unsigned short attr, const void *in6);
int sd_netlink_message_read_in_addr(void *m, unsigned short attr, void *ret);
int sd_netlink_message_set_request_dump(void *m, int dump);
int local_addresses(void *context, int ifindex, int af, void **ret);
int local_gateways(void *context, int ifindex, int af, void **ret);
int local_outbounds(void *context, int ifindex, int af, void **ret);
int copy_rights_with_fallback(int fdf, int fdt, const char *patht);
int probe_filesystem_full(int fd, const char *path, uint64_t offset, uint64_t size,
                          int restrict_fstypes, char **ret_fstype);
int get_common_dissect_directory(char **ret);
int dissect_loop_device(void *loop, const void *verity, const void *mount_options,
                        const void *image_policy, const void *image_filter,
                        unsigned int flags, void **ret);
void *mount_options_free_all(void *options);
void *image_filter_free(void *f);
int image_filter_parse(const char *s, void **ret);
const char *image_type_to_string(int t);
int sd_netlink_call_async(void *rtnl, void *m, void *callback, void *userdata, uint64_t timeout, const char *type);
int sd_netlink_wait(void *rtnl, uint64_t timeout);
int sd_netlink_process(void *rtnl, void **ret);
void *sd_netlink_ref(void *rtnl);
int sd_rtnl_message_new_addr(void *rtnl, void **ret, int type, int ifindex, int family);
int sd_rtnl_message_addr_set_prefixlen(void *m, unsigned char prefixlen);
int sd_rtnl_message_addr_set_scope(void *m, unsigned char scope);
int sd_rtnl_message_addr_get_scope(void *m, unsigned char *ret);
int sd_rtnl_message_addr_get_ifindex(void *m);
int sd_rtnl_message_addr_get_family(void *m);
int sd_rtnl_message_new_link(void *rtnl, void **ret, int type, int ifindex);
int sd_rtnl_message_link_set_flags(void *m, unsigned int flags, unsigned int change);
int sd_rtnl_message_link_get_flags(void *m, unsigned int *ret);
int probe_partition_table(int fd, bool *ret_is_gpt);
int probe_sector_size(int fd, uint32_t *ret);
int copy_file_atomic_at_full(int dir_fdf, const char *from, int dir_fdt, const char *to,
                             mode_t mode, unsigned chattr_flags, unsigned chattr_mask,
                             unsigned int copy_flags, void *progress, void *userdata);
int copy_file_fd_at_full(int dir_fdf, const char *from, int fdt, unsigned int copy_flags,
                         void *progress, void *userdata);
int copy_file_at_full(int dir_fdf, const char *from, int dir_fdt, const char *to,
                      int open_flags, mode_t mode, unsigned chattr_flags, unsigned chattr_mask,
                      unsigned int copy_flags, void *progress, void *userdata);
int pidref_get_capability(const void *pidref, void *ret);
int nfproto_from_string(const char *s);
int nft_set_source_from_string(const char *s);
const char *nft_set_source_to_string(int i);
int verity_dissect_and_mount(int src_fd, const char *src, const char *dest,
                             const void *options, const void *image_policy,
                             const void *image_filter, const void *extension_release_data,
                             int required_class, void *verity, int runtime_scope, void **ret_image);
struct mount_attr;
int sd_netlink_message_read_in6_addr(void *m, uint16_t attr_type, void *ret);
int sd_netlink_message_read(void *m, uint16_t attr_type, size_t size, void *ret);
int netlink_message_read_in_addr_union(void *m, unsigned short type, int family, void *ret);
int make_socket_fd(int log_level, const char *address, int type, int flags);
int socket_address_parse(void *a, const char *s);
int sd_rtnl_message_new_route(void *nl, void **ret, uint16_t nlmsg_type, int family, uint8_t protocol);
int sd_rtnl_message_route_set_type(void *m, uint8_t type);
int sd_rtnl_message_route_set_table(void *m, uint8_t table);
int sd_rtnl_message_route_get_dst_prefixlen(void *m, uint8_t *ret);
int sd_rtnl_message_route_get_src_prefixlen(void *m, uint8_t *ret);
int sd_rtnl_message_route_get_table(void *m, uint8_t *ret);
int sd_rtnl_message_route_get_family(void *m, int *ret);
int mq_unlink(const char *name);
void *in_addr_full_free(void *a);
int in_addr_full_new(int family, const void *a, uint16_t port, int ifindex, const char *server_name, void **ret);
int sd_netlink_get_event(void *nl, void **ret);
int sd_netlink_attach_event(void *nl, void *e, uint64_t priority);
int sd_netlink_add_match(void *nl, uint16_t type, void *callback, void *userdata);
int image_discover(int scope, int cls, const char *root, void **ret);
int image_read_metadata(void *image, int root_fd, const char *root);
int verity_settings_load(void *verity, const char *image, const char *image_path, const char *root_hash, const char *root_hash_sig);
int dissected_image_mount_and_warn(void *image, const char *where, uid_t uid_shift, uid_t uid_range, int userns_fd, unsigned int flags);
int image_to_json(void *image, unsigned int flags, void **ret);
int sd_sock_diag_message_new_unix_dump(void *sock_diag, void **ret, int family);
int sd_sock_diag_message_get_unix(void *m, void **ret);
int dlopen_bpf(int log_level);
int dlopen_libpam(int log_level);
int loopback_setup(void);
int nfproto_is_valid(int nfproto);
int sd_nfnl_socket_open(void **ret);
int nft_set_element_modify_any(void *nl, int protocol, int family, int table, unsigned int operation, const void *element, int element_len, uint8_t *ret);
int nft_set_element_modify_ip(void *nl, int protocol, int family, int table, unsigned int operation, const void *element, uint8_t prefixlen, uint8_t *ret);
int nft_set_element_modify_iprange(void *nl, int protocol, int family, int table, unsigned int operation, const void *prefix, const void *suffix, uint8_t *ret);
int arphrd_from_name(const char *name);
int capability_list_length(void);
const char *capability_to_string(int id);
int capability_set_to_strv(const void *c, char ***ret);
int capability_get_ambient(uint64_t *mask);
int capability_ambient_set_apply(uint64_t mask, int also_inherit);
int capability_bounding_set_drop(uint64_t drop, int keep_first);
int copy_directory_at_full(int fdf, const char *from, int fdt, const char *to,
                           int ignore, unsigned int copy_flags, void *denylist,
                           void *subvolumes, void *p, void *pb, void *u);
int fw_nftables_add_masquerade(void *context, int af, const void *source, const void *destination, unsigned int source_port, unsigned int destination_port, const char *table);
int fw_nftables_add_local_dnat(void *context, int af, int protocol, const void *source, const void *destination, unsigned int source_port, unsigned int destination_port, const void *remote, const void *previous);
int drop_capability(unsigned cap);
int socket_address_parse_netlink(void *a, const char *s);
int socket_address_is(const void *a, const char *s, int type);
int socket_address_is_netlink(const void *a, const char *s);
int netns_get_nsid(int netnsfd, uint32_t *ret);
int af_unix_get_qlen(int fd, uint32_t *ret);
int in_addr_port_ifindex_name_from_string_auto(const char *s, int family, void *ret, uint16_t *ret_port, int *ret_ifindex, char **ret_server_name);
int image_type_from_string(const char *s);
int drop_privileges(uint64_t keep, uint64_t keep_inheritable, uint64_t keep_ambient);
int capability_get(uint64_t *ret);
int have_inheritable_cap(void);



/* close_range - close all fds from first to last */
int close_range(unsigned int first, unsigned int last, int flags) {
        (void)flags;
        if (last == UINT_MAX) {
                /* close from first to max, get max fd from sysconf */
                long max = sysconf(_SC_OPEN_MAX);
                if (max < 0) max = 1024;
                for (long i = first; i <= max && i <= last; i++)
                        close(i);
        } else {
                for (unsigned int i = first; i <= last; i++)
                        close(i);
        }
        return 0;
}

/* getrandom - read random bytes */
ssize_t getrandom(void *buf, size_t buflen, unsigned int flags) {
        (void)flags;
        FILE *f;
        size_t n;
        int saved_errno;

        f = fopen("/dev/urandom", "re");
        if (!f)
                f = fopen("/dev/random", "re");
        if (!f)
                return errno = ENOSYS, -1;
        n = fread(buf, 1, buflen, f);
        saved_errno = errno;
        fclose(f);
        errno = saved_errno;
        if (n != buflen)
                return -1;
        return (ssize_t)n;
}

/* renameat2 - Linux extension */
int renameat2(int olddirfd, const char *oldpath, int newdirfd, const char *newpath, unsigned int flags) {
        if (flags == 0)
                return renameat(olddirfd, oldpath, newdirfd, newpath);

        if (flags == RENAME_NOREPLACE) {
                int fd = openat(newdirfd, newpath, O_RDONLY | O_CREAT | O_EXCL, 0);
                if (fd < 0)
                        return -1;
                close(fd);
                /* Now do the rename (newpath was just created empty) */
                return renameat(olddirfd, oldpath, newdirfd, newpath);
        }

        return errno = EOPNOTSUPP, -1;
}

/* pidfd_open - return pidfd (Linux-specific) */
int pidfd_open(pid_t pid, unsigned int flags) {
#if defined(__FreeBSD__)
        (void)flags;
        /* FreeBSD: use kqueue to monitor process exit */
        int kq = kqueue();
        if (kq < 0)
                return -1;
        struct kevent kev;
        EV_SET(&kev, pid, EVFILT_PROC, EV_ADD, NOTE_EXIT, 0, NULL);
        int r = kevent(kq, &kev, 1, NULL, 0, NULL);
        if (r < 0) {
                close(kq);
                return -1;
        }
        if (flags & O_CLOEXEC)
                fcntl(kq, F_SETFD, FD_CLOEXEC);
        return kq;
#else
        (void)pid;
        (void)flags;
        return errno = ENOSYS, -1;
#endif
}

/* pidfd_send_signal - send signal via pidfd */
int pidfd_send_signal(int pidfd, int sig, siginfo_t *info, unsigned int flags) {
        (void)pidfd;
        (void)sig;
        (void)info;
        (void)flags;
        return errno = ENOSYS, -1;
}

/* gettid — return thread ID (Linux style).
 * FreeBSD does not provide a public gettid() wrapper before 15;
 * we provide a stub that calls the thr_self syscall directly. */
#ifdef __FreeBSD__
#include <sys/thr.h>
#endif
pid_t gettid(void) {
#if defined(__FreeBSD__)
        long tid;
        thr_self(&tid);
        return (pid_t)tid;
#else
        /* Non-FreeBSD BSD (e.g. DragonFly, OpenBSD): return PID as TID */
        return getpid();
#endif
}

/* syncfs — Linux-specific: sync a filesystem referenced by fd.
 * FreeBSD doesn't have this syscall; emulate via fsync on the fd if it's
 * a directory or file, or simply call sync(). */
int syncfs(int fd) {
        (void)fd;
        /* FreeBSD can't sync a single filesystem by fd; do a full sync. */
        sync();
        return 0;
}

/* getdents64 — Linux getdents64 syscall wrapper.
 * FreeBSD provides getdirentries() which has a similar interface. */
ssize_t getdents64(int fd, void *dirp, size_t count) {
#if defined(__FreeBSD__)
        long base = 0;
        return getdirentries(fd, dirp, count, &base);
#else
        (void)fd;
        (void)dirp;
        (void)count;
        return errno = ENOSYS, -1;
#endif
}

/* statx — Linux statx() syscall (always fails on FreeBSD) */
int statx(int dirfd, const char *pathname, int flags,
          unsigned int mask, struct statx *statxbuf) {
        (void)dirfd;
        (void)pathname;
        (void)flags;
        (void)mask;
        (void)statxbuf;
        return errno = ENOSYS, -1;
}

/* personality — Linux process execution domain (always fails) */
int personality(unsigned long persona) {
        (void)persona;
        return errno = ENOSYS, -1;
}

/* prctl — Linux process control (always fails) */
int prctl(int option, ...) {
        (void)option;
        return errno = ENOSYS, -1;
}

/* glibc provides program_invocation_name / program_invocation_short_name
 * in <errno.h>.  FreeBSD has nothing equivalent.
 * These must be mutable pointers (systemd writes to them via strncpy). */
char *program_invocation_name = NULL;
char *program_invocation_short_name = NULL;

/* Linux-style mount / umount / umount2 wrappers.
 * FreeBSD's mount() has a different signature; these always fail. */
int mount_linux_shim(const char *source, const char *target,
                     const char *fstype, unsigned long flags, const void *data) {
        (void)source; (void)target; (void)fstype; (void)flags; (void)data;
        return errno = ENOSYS, -1;
}

int umount_linux_shim(const char *target) {
        (void)target;
        return errno = ENOSYS, -1;
}

int umount2_linux_shim(const char *target, int flags) {
        (void)target; (void)flags;
        return errno = ENOSYS, -1;
}

/* unshare — Linux-specific namespace syscall. */
int unshare(int flags) {
        (void)flags;
        return errno = ENOSYS, -1;
}

/* kcmp — Linux-specific process comparison syscall. */
int kcmp(pid_t pid1, pid_t pid2, int type, unsigned long idx1, unsigned long idx2) {
        (void)pid1; (void)pid2; (void)type; (void)idx1; (void)idx2;
        return errno = ENOSYS, -1;
}

/* open_by_handle_at — Linux-specific. CGrpFS doesn't support handle-based ops. */
int open_by_handle_at(int mount_fd, struct file_handle *handle, int flags) {
        (void)mount_fd; (void)handle; (void)flags;
        return errno = ENOSYS, -1;
}

/* __clone2 — Linux ia64 (and our BSD fallback) thread/process creation. */
int __clone2(int (*fn)(void *), void *stack_base, size_t stack_size, int flags, void *arg) {
        (void)fn; (void)stack_base; (void)stack_size; (void)flags; (void)arg;
        return errno = ENOSYS, -1;
}

/* pidfd_spawn — glibc 2.39+ extension. Unavailable on FreeBSD. */
int pidfd_spawn(pid_t *pidfd, const char *path,
                const posix_spawn_file_actions_t *file_actions,
                const posix_spawnattr_t *attrp,
                char *const argv[], char *const envp[]) {
        (void)pidfd; (void)path; (void)file_actions; (void)attrp; (void)argv; (void)envp;
        return errno = ENOSYS, -1;
}

/* posix_spawnattr_setcgroup_np — glibc 2.39+ extension. Unavailable on FreeBSD. */
int posix_spawnattr_setcgroup_np(posix_spawnattr_t *attr, int cgroup) {
        (void)attr; (void)cgroup;
        return errno = ENOSYS, -1;
}

/* putpwent — write a passwd entry to stream (Linux-specific). */
int putpwent(const struct passwd *p, FILE *stream) {
        (void)p; (void)stream;
        return errno = ENOSYS, -1;
}

/* fgetpwent — read a passwd entry from stream (Linux-specific). */
struct passwd *fgetpwent(FILE *stream) {
        (void)stream;
        errno = ENOSYS;
        return NULL;
}

/* fgetgrent — read a group entry from stream (Linux-specific). */
struct group *fgetgrent(FILE *stream) {
        (void)stream;
        errno = ENOSYS;
        return NULL;
}

/* putgrent — write a group entry to stream (Linux-specific). */
int putgrent(const struct group *g, FILE *stream) {
        (void)g; (void)stream;
        return errno = ENOSYS, -1;
}

/* putsgent — write a shadow group entry to stream (Linux-specific). */
int putsgent(const struct sgrp *sg, FILE *stream) {
        (void)sg; (void)stream;
        return errno = ENOSYS, -1;
}

/* fgetsgent — read a shadow group entry from stream (Linux-specific). */
struct sgrp *fgetsgent(FILE *stream) {
        (void)stream;
        errno = ENOSYS;
        return NULL;
}

/* rt_tgsigqueueinfo — Linux-specific syscall wrapper. Unavailable on FreeBSD. */
int rt_tgsigqueueinfo(__pid_t tgid, __pid_t tid, int sig, siginfo_t *info) {
        (void)tgid; (void)tid; (void)sig; (void)info;
        return errno = ENOSYS, -1;
}

/* malloc_info — glibc-specific function. Return minimal valid XML as a stub. */
int malloc_info(int options, FILE *stream) {
        (void)options;
        fprintf(stream, "<malloc version=\"1\"/>\n");
        return 0;
}

/* sendfile — Linux-compatible wrapper around FreeBSD's sendfile(2). */
ssize_t _systemd_sendfile(int out_fd, int in_fd, off_t *offset, size_t count);
ssize_t _systemd_sendfile(int out_fd, int in_fd, off_t *offset, size_t count) {
        off_t sbytes;
        int ret = sendfile(in_fd, out_fd, offset ? *offset : 0, count, NULL, &sbytes, 0);
        if (ret == 0) {
                if (offset)
                        *offset += sbytes;
                return (ssize_t)sbytes;
        }
        return -1;
}

/* ── Linux stub implementations ── */

/* shadow password database */
int putspent(const struct spwd *p, FILE *fp) {
        (void)p; (void)fp;
        return errno = ENOSYS, -1;
}
struct spwd *fgetspent(FILE *fp) {
        (void)fp;
        return errno = ENOSYS, NULL;
}
struct spwd *getspnam(const char *name) {
        (void)name;
        return errno = ENOSYS, NULL;
}

/* resource limits */
int prlimit(pid_t pid, int resource,
            const struct rlimit *new_limit, struct rlimit *old_limit) {
        (void)pid; (void)resource; (void)new_limit; (void)old_limit;
        return errno = ENOSYS, -1;
}

/* POSIX message queues */
int mq_getattr(int mqdes, struct mq_attr *attr) {
        (void)mqdes; (void)attr;
        return errno = ENOSYS, -1;
}
ssize_t mq_receive(int mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio) {
        (void)mqdes; (void)msg_ptr; (void)msg_len; (void)msg_prio;
        return (errno = ENOSYS), -1;
}

/* current directory */
char *get_current_dir_name(void) {
        return getcwd(NULL, 0);
}

/* file handle operations */
int name_to_handle_at(int dirfd, const char *pathname,
                      struct file_handle *handle, int *mnt_id, int flags) {
        (void)dirfd; (void)pathname; (void)handle; (void)mnt_id; (void)flags;
        return errno = ENOSYS, -1;
}

/* namespace operations */
int setns(int fd, int nstype) {
        (void)fd; (void)nstype;
        return errno = ENOSYS, -1;
}

/* mount API shims */
int fsopen_shim(const char *fsname, unsigned flags) {
        (void)fsname; (void)flags;
        return errno = ENOSYS, -1;
}
int fsconfig_shim(int fd, unsigned cmd, const char *key,
                  const void *value, int aux) {
        (void)fd; (void)cmd; (void)key; (void)value; (void)aux;
        return errno = ENOSYS, -1;
}
int open_tree_shim(int dfd, const char *filename, unsigned flags) {
        (void)dfd; (void)filename; (void)flags;
        return errno = ENOSYS, -1;
}
int fsmount_shim(int fd, unsigned flags, unsigned ms_flags) {
        (void)fd; (void)flags; (void)ms_flags;
        return errno = ENOSYS, -1;
}
int move_mount_shim(int from_dfd, const char *from_pathname,
                    int to_dfd, const char *to_pathname, unsigned flags) {
        (void)from_dfd; (void)from_pathname; (void)to_dfd; (void)to_pathname; (void)flags;
        return errno = ENOSYS, -1;
}
int mount_setattr_shim(int dfd, const char *path, unsigned flags,
                        struct mount_attr *attr, size_t size) {
        (void)dfd; (void)path; (void)flags; (void)attr; (void)size;
        return errno = ENOSYS, -1;
}

int pivot_root_shim(const char *new_root, const char *put_old) {
        (void)new_root; (void)put_old;
        return errno = ENOSYS, -1;
}

ssize_t splice(int fd_in, off_t *off_in, int fd_out, off_t *off_out,
               size_t len, unsigned int flags) {
        (void)fd_in; (void)off_in; (void)fd_out; (void)off_out; (void)len; (void)flags;
        errno = ENOSYS;
        return -1;
}

/* capability (Linux-specific, always return 0 / empty on BSD) */
unsigned cap_last_cap(void);
bool have_effective_cap(unsigned cap);
int capability_set_from_string(const char *s, uint64_t *ret);
const char *statx_mask_one_to_name(unsigned mask);
const char *statx_attribute_to_name(unsigned attr);
bool fs_in_group(const struct statfs *s, const char *const *groups);
const struct statfs *filesystem_sets(size_t *ret_n);

unsigned cap_last_cap(void) {
        return 0;
}
bool have_effective_cap(unsigned cap) {
        (void)cap;
        return false;
}
int capability_set_from_string(const char *s, uint64_t *ret) {
        (void)s;
        if (ret)
                *ret = 0;
        return 0;
}

/* getauxval — FreeBSD does not provide this; stub returning 0. */
unsigned long getauxval(unsigned long type);

unsigned long getauxval(unsigned long type) {
        (void)type;
        return 0;
}

/* statx strings (Linux-specific, return NULL on BSD) */
const char *statx_mask_one_to_name(unsigned mask) {
        (void)mask;
        return NULL;
}
const char *statx_attribute_to_name(unsigned attr) {
        (void)attr;
        return NULL;
}

/* filesystem type helpers (Linux-specific, always return false / empty on BSD) */
bool fs_in_group(const struct statfs *s, const char *const *groups) {
        (void)s; (void)groups;
        return false;
}
const struct statfs *filesystem_sets(size_t *ret_n) {
        (void)ret_n;
        return NULL;
}

/* Linux syscall stubs */
int fchmodat2(int dirfd, const char *path, mode_t mode, int flags) {
        (void)dirfd; (void)path; (void)mode; (void)flags;
        errno = ENOSYS;
        return -1;
}

int openat2(int dfd, const char *filename, const struct open_how *how, size_t usize) {
        (void)dfd; (void)filename; (void)how; (void)usize;
        errno = ENOSYS;
        return -1;
}

int fallocate(int fd, int mode, off_t offset, off_t len) {
        (void)fd; (void)mode; (void)offset; (void)len;
        errno = ENOSYS;
        return -1;
}

/* pthread_create stub — FreeBSD needs explicit -lpthread linking */
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine)(void *), void *arg) {
        (void)thread; (void)attr; (void)start_routine; (void)arg;
        errno = ENOSYS;
        return -1;
}

/* GNU extension: parse_printf_format — parse printf format string */
unsigned int parse_printf_format(const char *fmt, size_t n, int *types) {
        (void)fmt; (void)n; (void)types;
        return 0;
}

/* capability_to_name — Linux capability name lookup */
const char *capability_to_name(int cap) {
        (void)cap;
        return NULL;
}

/* Netlink utility stubs (sd-netlink excluded on BSD) */
int rtnl_resolve_ifname_full(
                struct sd_netlink **rtnl,
                ResolveInterfaceNameFlag flags,
                const char *name,
                char **ret_name,
                char ***ret_altnames) {
        (void)rtnl; (void)flags; (void)name; (void)ret_name; (void)ret_altnames;
        return -ENOSYS;
}

int rtnl_get_link_info_full(
                struct sd_netlink **rtnl,
                int ifindex,
                char **ret_name,
                char ***ret_altnames,
                unsigned short *ret_iftype,
                unsigned *ret_flags,
                char **ret_kind,
                struct hw_addr_data *ret_hw_addr,
                struct hw_addr_data *ret_permanent_hw_addr) {
        (void)rtnl; (void)ifindex; (void)ret_name; (void)ret_altnames;
        (void)ret_iftype; (void)ret_flags; (void)ret_kind;
        (void)ret_hw_addr; (void)ret_permanent_hw_addr;
        return -ENOSYS;
}

/* Global environ — POSIX.1 requires this from <unistd.h> but FreeBSD may not
 * export it when _GNU_SOURCE is defined. */
char **environ __attribute__((weak));

/* pthread_setaffinity_np — set thread CPU affinity (Linux-specific). */
int pthread_setaffinity_np(pthread_t thread, size_t cpusetsize,
                           const cpu_set_t *cpuset) {
        (void)thread; (void)cpusetsize; (void)cpuset;
        return errno = ENOSYS, -1;
}

/* pthread_setname_np — set thread name. FreeBSD has the same API. */
int pthread_setname_np(pthread_t thread, const char *name) {
        (void)thread; (void)name;
        /* The system function exists but we let it call through the normal process.
         * This stub should not need to exist — the function is available on FreeBSD.
         * We provide it in case of linking issues. */
        errno = ENOSYS;
        return -1;
}

/* copy_tree_at_full — from copy.c (excluded on BSD). */
int copy_tree_at_full(int fdf, const char *from, int fdt, const char *to,
                      uid_t override_uid, gid_t override_gid,
                      unsigned int copy_flags, void *denylist,
                      void *subvolumes,
                      void *progress_path, void *progress_bytes,
                      void *userdata) {
        (void)fdf; (void)from; (void)fdt; (void)to;
        (void)override_uid; (void)override_gid; (void)copy_flags;
        (void)denylist; (void)subvolumes; (void)progress_path;
        (void)progress_bytes; (void)userdata;
        errno = ENOSYS;
        return -1;
}

/* image_path_lock — from discover-image.c (excluded on BSD). */
int image_path_lock(int scope, const char *path, int operation,
                    void *global, void *local) {
        (void)scope; (void)path; (void)operation; (void)global; (void)local;
        return -ENOSYS;
}

/* Capability utility stubs (Linux-specific) */
unsigned long capability_from_name(const char *name) {
        (void)name;
        return 0;
}
int capability_set_to_string(const void *c, char **ret) {
        (void)c;
        *ret = NULL;
        return -ENOSYS;
}
int capability_set_to_string_negative(const void *c, char **ret) {
        (void)c;
        *ret = NULL;
        return -ENOSYS;
}

/* sd-netlink stubs (libsystemd sd-netlink excluded on BSD) */
int sd_netlink_open(void **ret) {
        (void)ret;
        return -ENOSYS;
}
int sd_netlink_call(void *rtnl, void *m, uint64_t timeout, void **ret_reply) {
        (void)rtnl; (void)m; (void)timeout; (void)ret_reply;
        return -ENOSYS;
}
int sd_netlink_message_get_errno(void *m) {
        (void)m;
        return -ENOSYS;
}
int sd_netlink_message_get_type(void *m, uint16_t *type) {
        (void)m; (void)type;
        return -ENOSYS;
}
void *sd_netlink_message_next(void *m) {
        (void)m;
        return NULL;
}
int sd_netlink_message_read_u32(void *m, unsigned short attr, uint32_t *ret) {
        (void)m; (void)attr; (void)ret;
        return -ENOSYS;
}
int sd_netlink_message_read_data(void *m, unsigned short attr, size_t *ret_size, void **ret_data) {
        (void)m; (void)attr; (void)ret_size; (void)ret_data;
        return -ENOSYS;
}
int sd_netlink_message_append_s32(void *m, unsigned short attr, int32_t val) {
        (void)m; (void)attr; (void)val;
        return -ENOSYS;
}
void *sd_netlink_message_unref(void *m) {
        (void)m;
        return NULL;
}
void *sd_netlink_unref(void *rtnl) {
        (void)rtnl;
        return NULL;
}
int sd_rtnl_message_new_nsid(void *rtnl, void **ret, uint16_t type, int ifindex) {
        (void)rtnl; (void)ret; (void)type; (void)ifindex;
        return -ENOSYS;
}
int sd_sock_diag_socket_open(void) {
        return -ENOSYS;
}
int sd_sock_diag_message_new_unix(void *sock_diag, void **ret, int family) {
        (void)sock_diag; (void)ret; (void)family;
        return -ENOSYS;
}
int sd_netlink_message_open_container(void *m, uint16_t attr_type) {
        (void)m; (void)attr_type;
        return -ENOSYS;
}
int sd_netlink_message_close_container(void *m) {
        (void)m;
        return -ENOSYS;
}
int sd_netlink_message_append_data(void *m, uint16_t attr_type, const void *data, size_t len) {
        (void)m; (void)attr_type; (void)data; (void)len;
        return -ENOSYS;
}

/* arphrd_to_name — ARP hardware type to string. */
const char *arphrd_to_name(int id) {
        (void)id;
        return NULL;
}

/* copy_bytes_full — from copy.c (excluded on BSD). */
int copy_bytes_full(int fdf, int fdt, uint64_t max_bytes, unsigned int copy_flags,
                    void **ret_remains, size_t *ret_remains_size,
                    void *progress, void *userdata) {
        (void)fdf; (void)fdt; (void)max_bytes; (void)copy_flags;
        (void)ret_remains; (void)ret_remains_size; (void)progress; (void)userdata;
        return -ENOSYS;
}

/* dissect-image stubs (dissect-image.c excluded on BSD) */
void *dissected_image_unref(void *m) {
        (void)m;
        return NULL;
}
int dissect_loop_device_and_warn(void *loop, const void *verity, const void *mount_options,
                                 const void *image_policy, const void *image_filter,
                                 unsigned int flags, void **ret) {
        (void)loop; (void)verity; (void)mount_options; (void)image_policy;
        (void)image_filter; (void)flags; (void)ret;
        return -ENOSYS;
}
int dissected_image_decrypt(void *m, const char *root, const char *passphrase,
                            const void *verity, const void *image_policy,
                            unsigned int flags) {
        (void)m; (void)root; (void)passphrase; (void)verity; (void)image_policy; (void)flags;
        return -ENOSYS;
}
int dissected_image_mount(void *m, const char *where, uid_t uid_shift, uid_t uid_range,
                          int userns_fd, unsigned int flags) {
        (void)m; (void)where; (void)uid_shift; (void)uid_range; (void)userns_fd; (void)flags;
        return -ENOSYS;
}
int dissected_image_guess_verity_roothash(void *m, void *verity) {
        (void)m; (void)verity;
        return -ENOSYS;
}
int dissected_image_load_verity_sig_partition(void *m, int fd, void *verity) {
        (void)m; (void)fd; (void)verity;
        return -ENOSYS;
}
int dissected_image_relinquish(void *m) {
        (void)m;
        return -ENOSYS;
}

/* mount_image_privately_interactively — from dissect-image.c (excluded on BSD) */
int mount_image_privately_interactively(const char *image, const void *image_policy,
                                        unsigned int flags, char **ret_directory,
                                        int *ret_dir_fd, void **ret_loop_device) {
        (void)image; (void)image_policy; (void)flags;
        (void)ret_directory; (void)ret_dir_fd; (void)ret_loop_device;
        return -ENOSYS;
}

void verity_settings_done(void *verity) {
        (void)verity;
}

/* mountfsd stubs */
int mountfsd_connect(void **ret) {
        (void)ret;
        return -ENOSYS;
}
int mountfsd_mount_image_fd(void *vl, int image_fd, int userns_fd,
                            const void *options, const void *image_policy,
                            const void *verity, unsigned int flags, void **ret) {
        (void)vl; (void)image_fd; (void)userns_fd; (void)options;
        (void)image_policy; (void)verity; (void)flags; (void)ret;
        return -ENOSYS;
}
int mountfsd_mount_directory_fd(void *vl, int directory_fd, int userns_fd,
                                unsigned int flags, int *ret_mount_fd) {
        (void)vl; (void)directory_fd; (void)userns_fd; (void)flags; (void)ret_mount_fd;
        return -ENOSYS;
}

/* nl80211_iftype_to_string — from wifi-util.c (excluded on BSD) */
const char *nl80211_iftype_to_string(int i) {
        (void)i;
        return NULL;
}
/* arphrd_to_hw_addr_len — from basic/arphrd-util.c */
int arphrd_to_hw_addr_len(int id) {
        (void)id;
        return -ENOSYS;
}
/* quotactl_fd — from sys/quota.h */
int quotactl_fd(int fd, int cmd, int id, void *addr) {
        (void)fd; (void)cmd; (void)id; (void)addr;
        errno = ENOSYS;
        return -1;
}
/* get_mempolicy / set_mempolicy — from sys/mempolicy.h */
int get_mempolicy(int *mode, unsigned long *nodemask, unsigned long maxnode,
                  void *addr, unsigned long flags) {
        (void)mode; (void)nodemask; (void)maxnode; (void)addr; (void)flags;
        errno = ENOSYS;
        return -1;
}
int set_mempolicy(int mode, const unsigned long *nodemask, unsigned long maxnode) {
        (void)mode; (void)nodemask; (void)maxnode;
        errno = ENOSYS;
        return -1;
}

/* sd_netlink/sd_rtnl stub additions */
int sd_netlink_message_append_u32(void *m, unsigned short attr, uint32_t val) {
        (void)m; (void)attr; (void)val;
        return -ENOSYS;
}
int sd_netlink_message_append_in_addr(void *m, unsigned short attr, const void *in) {
        (void)m; (void)attr; (void)in;
        return -ENOSYS;
}
int sd_netlink_message_append_in6_addr(void *m, unsigned short attr, const void *in6) {
        (void)m; (void)attr; (void)in6;
        return -ENOSYS;
}
int sd_netlink_message_read_in_addr(void *m, unsigned short attr, void *ret) {
        (void)m; (void)attr; (void)ret;
        return -ENOSYS;
}
int sd_netlink_message_set_request_dump(void *m, int dump) {
        (void)m; (void)dump;
        return -ENOSYS;
}
int sd_netlink_call_async(void *rtnl, void *m, void *callback, void *userdata, uint64_t timeout, const char *type) {
        (void)rtnl; (void)m; (void)callback; (void)userdata; (void)timeout; (void)type;
        return -ENOSYS;
}
int sd_netlink_wait(void *rtnl, uint64_t timeout) {
        (void)rtnl; (void)timeout;
        return -ENOSYS;
}
int sd_netlink_process(void *rtnl, void **ret) {
        (void)rtnl; (void)ret;
        return -ENOSYS;
}
void *sd_netlink_ref(void *rtnl) {
        (void)rtnl;
        return NULL;
}
int sd_rtnl_message_new_addr(void *rtnl, void **ret, int type, int ifindex, int family) {
        (void)rtnl; (void)ret; (void)type; (void)ifindex; (void)family;
        return -ENOSYS;
}
int sd_rtnl_message_addr_set_prefixlen(void *m, unsigned char prefixlen) {
        (void)m; (void)prefixlen;
        return -ENOSYS;
}
int sd_rtnl_message_addr_set_scope(void *m, unsigned char scope) {
        (void)m; (void)scope;
        return -ENOSYS;
}
int sd_rtnl_message_addr_get_scope(void *m, unsigned char *ret) {
        (void)m; (void)ret;
        return -ENOSYS;
}
int sd_rtnl_message_addr_get_ifindex(void *m) {
        (void)m;
        return -ENOSYS;
}
int sd_rtnl_message_addr_get_family(void *m) {
        (void)m;
        return -ENOSYS;
}
int sd_rtnl_message_new_link(void *rtnl, void **ret, int type, int ifindex) {
        (void)rtnl; (void)ret; (void)type; (void)ifindex;
        return -ENOSYS;
}
int sd_rtnl_message_link_set_flags(void *m, unsigned int flags, unsigned int change) {
        (void)m; (void)flags; (void)change;
        return -ENOSYS;
}
int sd_rtnl_message_link_get_flags(void *m, unsigned int *ret) {
        (void)m; (void)ret;
        return -ENOSYS;
}
int probe_partition_table(int fd, bool *ret_is_gpt) {
        (void)fd; (void)ret_is_gpt;
        return -ENOSYS;
}
int probe_sector_size(int fd, uint32_t *ret) {
        (void)fd; (void)ret;
        *ret = 512;
        return 0;
}

/* copy_file_* stubs — from copy.c (excluded on BSD) */
int copy_file_atomic_at_full(int dir_fdf, const char *from, int dir_fdt, const char *to,
                             mode_t mode, unsigned chattr_flags, unsigned chattr_mask,
                             unsigned int copy_flags, void *progress, void *userdata) {
        (void)dir_fdf; (void)from; (void)dir_fdt; (void)to; (void)mode;
        (void)chattr_flags; (void)chattr_mask; (void)copy_flags; (void)progress; (void)userdata;
        return -ENOSYS;
}
int copy_file_fd_at_full(int dir_fdf, const char *from, int fdt, unsigned int copy_flags,
                         void *progress, void *userdata) {
        (void)dir_fdf; (void)from; (void)fdt; (void)copy_flags; (void)progress; (void)userdata;
        return -ENOSYS;
}
int copy_file_at_full(int dir_fdf, const char *from, int dir_fdt, const char *to,
                      int open_flags, mode_t mode, unsigned chattr_flags, unsigned chattr_mask,
                      unsigned int copy_flags, void *progress, void *userdata) {
        (void)dir_fdf; (void)from; (void)dir_fdt; (void)to; (void)open_flags; (void)mode;
        (void)chattr_flags; (void)chattr_mask; (void)copy_flags; (void)progress; (void)userdata;
        return -ENOSYS;
}

/* pidref_get_capability — from capability-util.c */
int pidref_get_capability(const void *pidref, void *ret) {
        (void)pidref; (void)ret;
        return -ENOSYS;
}

/* nftables/nfproto stubs — from firewall-util.c (excluded on BSD) */
int nfproto_from_string(const char *s) {
        (void)s;
        return -ENOSYS;
}
int nft_set_source_from_string(const char *s) {
        (void)s;
        return -ENOSYS;
}
const char *nft_set_source_to_string(int i) {
        (void)i;
        return NULL;
}

/* verity_dissect_and_mount — from dissect-image.c (excluded on BSD) */
int verity_dissect_and_mount(int src_fd, const char *src, const char *dest,
                             const void *options, const void *image_policy,
                             const void *image_filter, const void *extension_release_data,
                             int required_class, void *verity, int runtime_scope, void **ret_image) {
        (void)src_fd; (void)src; (void)dest; (void)options; (void)image_policy;
        (void)image_filter; (void)extension_release_data; (void)required_class;
        (void)verity; (void)runtime_scope; (void)ret_image;
        return -ENOSYS;
}

/* open_tree_attr_shim — from mount-util.c shim */
int open_tree_attr_shim(int dfd, const char *filename, unsigned int flags, struct mount_attr *attr, size_t size) {
        (void)dfd; (void)filename; (void)flags; (void)attr; (void)size;
        return -ENOSYS;
}

/* sd_netlink_message_read_in6_addr — from sd-netlink */
int sd_netlink_message_read_in6_addr(void *m, uint16_t attr_type, void *ret) {
        (void)m; (void)attr_type; (void)ret;
        return -ENOSYS;
}
int sd_netlink_message_read(void *m, uint16_t attr_type, size_t size, void *ret) {
        (void)m; (void)attr_type; (void)size; (void)ret;
        return -ENOSYS;
}
int netlink_message_read_in_addr_union(void *m, unsigned short type, int family, void *ret) {
        (void)m; (void)type; (void)family; (void)ret;
        return -ENOSYS;
}
int sd_rtnl_message_new_route(void *nl, void **ret, uint16_t nlmsg_type, int family, uint8_t protocol) {
        (void)nl; (void)ret; (void)nlmsg_type; (void)family; (void)protocol;
        return -ENOSYS;
}
int sd_rtnl_message_route_set_type(void *m, uint8_t type) {
        (void)m; (void)type;
        return -ENOSYS;
}
int sd_rtnl_message_route_set_table(void *m, uint8_t table) {
        (void)m; (void)table;
        return -ENOSYS;
}
int sd_rtnl_message_route_get_dst_prefixlen(void *m, uint8_t *ret) {
        (void)m; (void)ret;
        return -ENOSYS;
}
int sd_rtnl_message_route_get_src_prefixlen(void *m, uint8_t *ret) {
        (void)m; (void)ret;
        return -ENOSYS;
}
int sd_rtnl_message_route_get_table(void *m, uint8_t *ret) {
        (void)m; (void)ret;
        return -ENOSYS;
}
int sd_rtnl_message_route_get_family(void *m, int *ret) {
        (void)m; (void)ret;
        return -ENOSYS;
}
int mq_unlink(const char *name) {
        (void)name;
        errno = ENOSYS;
        return -1;
}

/* in_addr_full_new / in_addr_full_free — from socket-netlink.c */
void *in_addr_full_free(void *a) {
        (void)a;
        return NULL;
}
int in_addr_full_new(int family, const void *a, uint16_t port, int ifindex, const char *server_name, void **ret) {
        (void)family; (void)a; (void)port; (void)ifindex; (void)server_name; (void)ret;
        return -ENOSYS;
}

/* local_addresses / local_gateways / local_outbounds — from local-addresses.c */
int local_addresses(void *context, int ifindex, int af, void **ret) {
        (void)context; (void)ifindex; (void)af; (void)ret;
        return -ENOSYS;
}
int local_gateways(void *context, int ifindex, int af, void **ret) {
        (void)context; (void)ifindex; (void)af; (void)ret;
        return -ENOSYS;
}
int local_outbounds(void *context, int ifindex, int af, void **ret) {
        (void)context; (void)ifindex; (void)af; (void)ret;
        return -ENOSYS;
}

/* copy_rights_with_fallback — from copy.c (excluded on BSD) */
int copy_rights_with_fallback(int fdf, int fdt, const char *patht) {
        (void)fdf; (void)fdt; (void)patht;
        return -ENOSYS;
}

/* probe_filesystem_full — from dissect-image.c (excluded on BSD) */
int probe_filesystem_full(int fd, const char *path, uint64_t offset, uint64_t size,
                          int restrict_fstypes, char **ret_fstype) {
        (void)fd; (void)path; (void)offset; (void)size;
        (void)restrict_fstypes; (void)ret_fstype;
        return -ENOSYS;
}

/* get_common_dissect_directory — from dissect-image.c */
int get_common_dissect_directory(char **ret) {
        (void)ret;
        return -ENOSYS;
}

/* dissect_loop_device — from dissect-image.c */
int dissect_loop_device(void *loop, const void *verity, const void *mount_options,
                        const void *image_policy, const void *image_filter,
                        unsigned int flags, void **ret) {
        (void)loop; (void)verity; (void)mount_options; (void)image_policy;
        (void)image_filter; (void)flags; (void)ret;
        return -ENOSYS;
}

/* mount_options_free_all — from dissect-image.c */
void *mount_options_free_all(void *options) {
        (void)options;
        return NULL;
}

/* image_search_path — from discover-image.c (excluded on BSD).
 * _IMAGE_CLASS_MAX = 4 from src/basic/os-util.h. */
const char *const image_search_path[4] = {};

/* image_filter_free — from dissect-image.c */
void *image_filter_free(void *f) {
        (void)f;
        return NULL;
}

/* image_filter_parse — from dissect-image.c */
int image_filter_parse(const char *s, void **ret) {
        (void)s; (void)ret;
        return -ENOSYS;
}

/* image_type_to_string — from discover-image.c (excluded on BSD) */
const char *image_type_to_string(int t) {
        (void)t;
        return NULL;
}

/* make_socket_fd — from socket-netlink.c (excluded on BSD) */
int make_socket_fd(int log_level, const char *address, int type, int flags) {
        (void)log_level; (void)address; (void)type; (void)flags;
        return -ENOSYS;
}

/* socket_address_parse — from socket-netlink.c (excluded on BSD) */
int socket_address_parse(void *a, const char *s) {
        (void)a; (void)s;
        return -ENOSYS;
}

/* sd-netlink stubs */
int sd_netlink_attach_event(void *nl, void *e, uint64_t priority) {
        (void)nl; (void)e; (void)priority;
        return -ENOSYS;
}
int sd_netlink_add_match(void *nl, uint16_t type, void *callback, void *userdata) {
        (void)nl; (void)type; (void)callback; (void)userdata;
        return -ENOSYS;
}
int sd_netlink_get_event(void *nl, void **ret) {
        (void)nl; (void)ret;
        return -ENOSYS;
}

/* image_discover — from discover-image.c (excluded on BSD) */
int image_discover(int scope, int cls, const char *root, void **ret) {
        (void)scope; (void)cls; (void)root; (void)ret;
        return -ENOSYS;
}

/* image_read_metadata — from discover-image.c */
int image_read_metadata(void *image, int root_fd, const char *root) {
        (void)image; (void)root_fd; (void)root;
        return -ENOSYS;
}

/* verity_settings_load — from dissect-image.c */
int verity_settings_load(void *verity, const char *image, const char *image_path, const char *root_hash, const char *root_hash_sig) {
        (void)verity; (void)image; (void)image_path; (void)root_hash; (void)root_hash_sig;
        return -ENOSYS;
}

/* dissected_image_mount_and_warn — from dissect-image.c */
int dissected_image_mount_and_warn(void *image, const char *where, uid_t uid_shift, uid_t uid_range, int userns_fd, unsigned int flags) {
        (void)image; (void)where; (void)uid_shift; (void)uid_range; (void)userns_fd; (void)flags;
        return -ENOSYS;
}

/* image_to_json — from discover-image.c */
int image_to_json(void *image, unsigned int flags, void **ret) {
        (void)image; (void)flags; (void)ret;
        return -ENOSYS;
}

/* sd_sock_diag_message_new_unix_dump — from sd-netlink */
int sd_sock_diag_message_new_unix_dump(void *sock_diag, void **ret, int family) {
        (void)sock_diag; (void)ret; (void)family;
        return -ENOSYS;
}

/* sd_sock_diag_message_get_unix — from sd-netlink */
int sd_sock_diag_message_get_unix(void *m, void **ret) {
        (void)m; (void)ret;
        return -ENOSYS;
}

/* dlopen_bpf — from bpf-util.c (excluded on BSD) */
int dlopen_bpf(int log_level) {
        (void)log_level;
        return -ENOSYS;
}

/* dlopen_libpam — from pam-util.c (excluded on BSD) */
int dlopen_libpam(int log_level) {
        (void)log_level;
        return -ENOSYS;
}

/* loopback_setup — from loopback-setup.c (excluded on BSD) */
int loopback_setup(void) {
        return -ENOSYS;
}

/* nfproto_is_valid — from sd-netlink (excluded on BSD) */
int nfproto_is_valid(int nfproto) {
        (void)nfproto;
        return -ENOSYS;
}

/* sd_nfnl_socket_open — from sd-netlink (excluded on BSD) */
int sd_nfnl_socket_open(void **ret) {
        (void)ret;
        return -ENOSYS;
}

/* nft_set_element_modify_any — from firewall-util.c (excluded on BSD) */
int nft_set_element_modify_any(void *nl, int protocol, int family, int table, unsigned int operation, const void *element, int element_len, uint8_t *ret) {
        (void)nl; (void)protocol; (void)family; (void)table; (void)operation;
        (void)element; (void)element_len; (void)ret;
        return -ENOSYS;
}

/* nft_set_element_modify_ip — from firewall-util.c (excluded on BSD) */
int nft_set_element_modify_ip(void *nl, int protocol, int family, int table, unsigned int operation, const void *element, uint8_t prefixlen, uint8_t *ret) {
        (void)nl; (void)protocol; (void)family; (void)table; (void)operation;
        (void)element; (void)prefixlen; (void)ret;
        return -ENOSYS;
}

/* nft_set_element_modify_iprange — from firewall-util.c (excluded on BSD) */
int nft_set_element_modify_iprange(void *nl, int protocol, int family, int table, unsigned int operation, const void *prefix, const void *suffix, uint8_t *ret) {
        (void)nl; (void)protocol; (void)family; (void)table; (void)operation;
        (void)prefix; (void)suffix; (void)ret;
        return -ENOSYS;
}

/* arphrd_from_name — from generated arphrd-from-name.inc (skipped on BSD) */
int arphrd_from_name(const char *name) {
        (void)name;
        return -ENOSYS;
}

/* capability_list_length — from capability-list.c (excluded on BSD) */
int capability_list_length(void) {
        return 0;
}

/* capability_set_to_strv — from capability-list.c */
int capability_set_to_strv(const void *c, char ***ret) {
        (void)c; (void)ret;
        return -ENOSYS;
}

/* capability_get_ambient — from capability-util.c (excluded on BSD) */
int capability_get_ambient(uint64_t *mask) {
        (void)mask;
        return -ENOSYS;
}

/* drop_privileges — from capability-util.c */
int drop_privileges(uint64_t keep, uint64_t keep_inheritable, uint64_t keep_ambient) {
        (void)keep; (void)keep_inheritable; (void)keep_ambient;
        return -ENOSYS;
}

/* capability_get — from capability-util.c */
int capability_get(uint64_t *ret) {
        (void)ret;
        return -ENOSYS;
}

/* have_inheritable_cap — from capability-util.c */
int have_inheritable_cap(void) {
        return 0;
}

/* capability_to_string — from capability-list.c (excluded on BSD) */
const char *capability_to_string(int id) {
        (void)id;
        return NULL;
}

/* capability_ambient_set_apply — from capability-util.c */
int capability_ambient_set_apply(uint64_t mask, int also_inherit) {
        (void)mask; (void)also_inherit;
        return -ENOSYS;
}

/* capability_bounding_set_drop — from capability-util.c */
int capability_bounding_set_drop(uint64_t drop, int keep_first) {
        (void)drop; (void)keep_first;
        return -ENOSYS;
}

/* copy_directory_at_full — from copy.c (excluded on BSD) */
int copy_directory_at_full(int fdf, const char *from, int fdt, const char *to,
                           int ignore, unsigned int copy_flags, void *denylist,
                           void *subvolumes, void *p, void *pb, void *u) {
        (void)fdf; (void)from; (void)fdt; (void)to; (void)ignore;
        (void)copy_flags; (void)denylist; (void)subvolumes;
        (void)p; (void)pb; (void)u;
        return -ENOSYS;
}

/* fw_nftables_add_masquerade — from firewall-util.c (excluded on BSD) */
int fw_nftables_add_masquerade(void *context, int af, const void *source, const void *destination, unsigned int source_port, unsigned int destination_port, const char *table) {
        (void)context; (void)af; (void)source; (void)destination;
        (void)source_port; (void)destination_port; (void)table;
        return -ENOSYS;
}

/* fw_nftables_add_local_dnat — from firewall-util.c (excluded on BSD) */
int fw_nftables_add_local_dnat(void *context, int af, int protocol, const void *source, const void *destination, unsigned int source_port, unsigned int destination_port, const void *remote, const void *previous) {
        (void)context; (void)af; (void)protocol; (void)source; (void)destination;
        (void)source_port; (void)destination_port; (void)remote; (void)previous;
        return -ENOSYS;
}

/* drop_capability — from capability-util.c (excluded on BSD) */
int drop_capability(unsigned cap) {
        (void)cap;
        return -ENOSYS;
}

/* socket_address_parse_netlink — from socket-netlink.c (excluded on BSD) */
int socket_address_parse_netlink(void *a, const char *s) {
        (void)a; (void)s;
        return -ENOSYS;
}

/* socket_address_is — from socket-netlink.c */
int socket_address_is(const void *a, const char *s, int type) {
        (void)a; (void)s; (void)type;
        return 0;
}

/* socket_address_is_netlink — from socket-netlink.c */
int socket_address_is_netlink(const void *a, const char *s) {
        (void)a; (void)s;
        return 0;
}

/* netns_get_nsid — from socket-netlink.c */
int netns_get_nsid(int netnsfd, uint32_t *ret) {
        (void)netnsfd; (void)ret;
        return -ENOSYS;
}

/* af_unix_get_qlen — from socket-netlink.c */
int af_unix_get_qlen(int fd, uint32_t *ret) {
        (void)fd; (void)ret;
        return -ENOSYS;
}

/* in_addr_port_ifindex_name_from_string_auto — from socket-netlink.c */
int in_addr_port_ifindex_name_from_string_auto(const char *s, int family, void *ret, uint16_t *ret_port, int *ret_ifindex, char **ret_server_name) {
        (void)s; (void)family; (void)ret; (void)ret_port; (void)ret_ifindex; (void)ret_server_name;
        return -ENOSYS;
}

/* image_type_from_string — from discover-image.c (excluded on BSD) */
int image_type_from_string(const char *s) {
        (void)s;
        return -ENOSYS;
}
