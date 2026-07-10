/* SPDX-License-Identifier: LGPL-2.1-or-later */

/* Stub implementations for Linux key management syscalls.
 * These are not available on BSD. The shim names match the declarations
 * in src/include/override/sys/keyctl.h. */

#include <sys/types.h>
#include <stddef.h>
#include <errno.h>
#include <sys/keyctl.h>

long keyctl_shim(int cmd, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5) {
        (void)cmd; (void)arg2; (void)arg3; (void)arg4; (void)arg5;
        return errno = ENOSYS, -1;
}

key_serial_t add_key_shim(const char *type, const char *description, const void *payload, size_t plen, key_serial_t ringid) {
        (void)type; (void)description; (void)payload; (void)plen; (void)ringid;
        return errno = ENOSYS, -1;
}

key_serial_t request_key_shim(const char *type, const char *description, const char *callout_info, key_serial_t destringid) {
        (void)type; (void)description; (void)callout_info; (void)destringid;
        return errno = ENOSYS, -1;
}
