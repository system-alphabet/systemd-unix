/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include "sys/xattr.h"
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#if defined(__FreeBSD__)
#include <sys/extattr.h>
/* FreeBSD: use extattr_* system calls */
static int attr_ns(const char *name) {
        if (!name) return -1;
        if (strncmp(name, "security.", 9) == 0) return EXTATTR_NAMESPACE_SYSTEM;
        if (strncmp(name, "trusted.", 8) == 0) return EXTATTR_NAMESPACE_USER;
        if (strncmp(name, "user.", 5) == 0) return EXTATTR_NAMESPACE_USER;
        if (strncmp(name, "system.", 7) == 0) return EXTATTR_NAMESPACE_SYSTEM;
        return EXTATTR_NAMESPACE_USER;
}

static const char* attr_name_only(const char *name) {
        const char *dot = strchr(name, '.');
        return dot ? dot + 1 : name;
}

ssize_t getxattr(const char *path, const char *name, void *value, size_t size) {
        return extattr_get_file(path, attr_ns(name), attr_name_only(name), value, size);
}
ssize_t lgetxattr(const char *path, const char *name, void *value, size_t size) {
        return extattr_get_link(path, attr_ns(name), attr_name_only(name), value, size);
}
ssize_t fgetxattr(int fd, const char *name, void *value, size_t size) {
        return extattr_get_fd(fd, attr_ns(name), attr_name_only(name), value, size);
}
int setxattr(const char *path, const char *name, const void *value, size_t size, int flags) {
        (void)flags;
        return extattr_set_file(path, attr_ns(name), attr_name_only(name), value, size);
}
int lsetxattr(const char *path, const char *name, const void *value, size_t size, int flags) {
        (void)flags;
        return extattr_set_link(path, attr_ns(name), attr_name_only(name), value, size);
}
int fsetxattr(int fd, const char *name, const void *value, size_t size, int flags) {
        (void)flags;
        return extattr_set_fd(fd, attr_ns(name), attr_name_only(name), value, size);
}
ssize_t listxattr(const char *path, char *list, size_t size) {
        return extattr_list_file(path, EXTATTR_NAMESPACE_USER, list, size);
}
ssize_t llistxattr(const char *path, char *list, size_t size) {
        return extattr_list_link(path, EXTATTR_NAMESPACE_USER, list, size);
}
ssize_t flistxattr(int fd, char *list, size_t size) {
        return extattr_list_fd(fd, EXTATTR_NAMESPACE_USER, list, size);
}
int removexattr(const char *path, const char *name) {
        return extattr_delete_file(path, attr_ns(name), attr_name_only(name));
}
int lremovexattr(const char *path, const char *name) {
        return extattr_delete_link(path, attr_ns(name), attr_name_only(name));
}
int fremovexattr(int fd, const char *name) {
        return extattr_delete_fd(fd, attr_ns(name), attr_name_only(name));
}
#else
/* Other BSD / non-Linux: stub xattr */
ssize_t getxattr(const char *path, const char *name, void *value, size_t size) {
        (void)path; (void)name; (void)value; (void)size;
        return errno = ENOTSUP, -1;
}
ssize_t lgetxattr(const char *path, const char *name, void *value, size_t size) {
        (void)path; (void)name; (void)value; (void)size;
        return errno = ENOTSUP, -1;
}
ssize_t fgetxattr(int fd, const char *name, void *value, size_t size) {
        (void)fd; (void)name; (void)value; (void)size;
        return errno = ENOTSUP, -1;
}
int setxattr(const char *path, const char *name, const void *value, size_t size, int flags) {
        (void)path; (void)name; (void)value; (void)size; (void)flags;
        return errno = ENOTSUP, -1;
}
int lsetxattr(const char *path, const char *name, const void *value, size_t size, int flags) {
        (void)path; (void)name; (void)value; (void)size; (void)flags;
        return errno = ENOTSUP, -1;
}
int fsetxattr(int fd, const char *name, const void *value, size_t size, int flags) {
        (void)fd; (void)name; (void)value; (void)size; (void)flags;
        return errno = ENOTSUP, -1;
}
ssize_t listxattr(const char *path, char *list, size_t size) {
        (void)path; (void)list; (void)size;
        return errno = ENOTSUP, -1;
}
ssize_t llistxattr(const char *path, char *list, size_t size) {
        (void)path; (void)list; (void)size;
        return errno = ENOTSUP, -1;
}
ssize_t flistxattr(int fd, char *list, size_t size) {
        (void)fd; (void)list; (void)size;
        return errno = ENOTSUP, -1;
}
int removexattr(const char *path, const char *name) {
        (void)path; (void)name;
        return errno = ENOTSUP, -1;
}
int lremovexattr(const char *path, const char *name) {
        (void)path; (void)name;
        return errno = ENOTSUP, -1;
}
int fremovexattr(int fd, const char *name) {
        (void)fd; (void)name;
        return errno = ENOTSUP, -1;
}
#endif

/* Linux-specific setxattrat / removexattrat (always stub) */
int setxattrat(int fd, const char *path, int at_flags, const char *name, const struct xattr_args *args, size_t size) {
        (void)fd; (void)path; (void)at_flags; (void)name; (void)args; (void)size;
        return errno = ENOSYS, -1;
}
int removexattrat(int fd, const char *path, int at_flags, const char *name) {
        (void)fd; (void)path; (void)at_flags; (void)name;
        return errno = ENOSYS, -1;
}
