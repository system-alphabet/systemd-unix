#pragma once

#include <errno.h>
#include <stddef.h>

#define LINUX_REBOOT_CMD_RESTART2 0xA1B2C3D4
#define LINUX_REBOOT_CMD_KEXEC   0x45584543

#define HAVE_KEXEC_FILE_LOAD_SYSCALL 0

static inline int kexec_load(unsigned long entry, unsigned long nr_segments, const void *segments, unsigned long flags) {
        (void)entry; (void)nr_segments; (void)segments; (void)flags;
        errno = ENOSYS;
        return -1;
}

static inline int kexec_file_load_shim(int kernel_fd, int initrd_fd, unsigned long cmdline_len, const char *cmdline, unsigned long flags) {
        (void)kernel_fd; (void)initrd_fd; (void)cmdline_len; (void)cmdline; (void)flags;
        errno = ENOSYS;
        return -1;
}
