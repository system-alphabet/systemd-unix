/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <sys/types.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

ssize_t getxattr(const char *path, const char *name, void *value, size_t size);
ssize_t lgetxattr(const char *path, const char *name, void *value, size_t size);
ssize_t fgetxattr(int fd, const char *name, void *value, size_t size);
int setxattr(const char *path, const char *name, const void *value, size_t size, int flags);
int lsetxattr(const char *path, const char *name, const void *value, size_t size, int flags);
int fsetxattr(int fd, const char *name, const void *value, size_t size, int flags);
ssize_t listxattr(const char *path, char *list, size_t size);
ssize_t llistxattr(const char *path, char *list, size_t size);
ssize_t flistxattr(int fd, char *list, size_t size);
int removexattr(const char *path, const char *name);
int lremovexattr(const char *path, const char *name);
int fremovexattr(int fd, const char *name);

/* struct xattr_args and setxattrat/removexattrat (Linux 6.13+, stubbed for compilation).
 * Must match the kernel's struct xattr_args from <linux/xattr.h>. */
struct xattr_args {
        uint64_t value;
        uint32_t size;
        uint32_t flags;
} __attribute__((aligned(8)));

#define XATTR_CREATE  0x1
#define XATTR_REPLACE 0x2

int setxattrat(int fd, const char *path, int at_flags, const char *name, const struct xattr_args *args, size_t size);
int removexattrat(int fd, const char *path, int at_flags, const char *name);

#ifdef __cplusplus
}
#endif
