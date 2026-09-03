/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _LINUX_SECUREBITS_H
#define _LINUX_SECUREBITS_H

/* Each securesetting is implemented using two bits. One bit specifies
   whether the setting is on or off. The other bit specify whether the
   setting is locked or not. A setting which is locked cannot be
   changed from user-level. */
#define issecure_mask(X) (1 << (X))

#define SECUREBITS_DEFAULT 0x00000000

/* When set UID 0 has no special privileges. When unset, we support
   inheritance of root-permissions and suid-root executable under
   compatibility mode. */
#define SECURE_NOROOT 0
#define SECURE_NOROOT_LOCKED 1 /* make bit-0 immutable */

#define SECBIT_NOROOT (issecure_mask(SECURE_NOROOT))
#define SECBIT_NOROOT_LOCKED (issecure_mask(SECURE_NOROOT_LOCKED))

#define SECURE_NO_SETUID_FIXUP 2
#define SECURE_NO_SETUID_FIXUP_LOCKED 3 /* make bit-2 immutable */

#define SECBIT_NO_SETUID_FIXUP (issecure_mask(SECURE_NO_SETUID_FIXUP))
#define SECBIT_NO_SETUID_FIXUP_LOCKED (issecure_mask(SECURE_NO_SETUID_FIXUP_LOCKED))

#define SECURE_KEEP_CAPS 4
#define SECURE_KEEP_CAPS_LOCKED 5 /* make bit-4 immutable */

#define SECBIT_KEEP_CAPS (issecure_mask(SECURE_KEEP_CAPS))
#define SECBIT_KEEP_CAPS_LOCKED (issecure_mask(SECURE_KEEP_CAPS_LOCKED))

/* When set, a process cannot add new capabilities to its ambient set. */
#define SECURE_NO_CAP_AMBIENT_RAISE 6
#define SECURE_NO_CAP_AMBIENT_RAISE_LOCKED 7 /* make bit-6 immutable */

#define SECBIT_NO_CAP_AMBIENT_RAISE (issecure_mask(SECURE_NO_CAP_AMBIENT_RAISE))
#define SECBIT_NO_CAP_AMBIENT_RAISE_LOCKED (issecure_mask(SECURE_NO_CAP_AMBIENT_RAISE_LOCKED))

#define SECURE_EXEC_RESTRICT_FILE 8
#define SECURE_EXEC_RESTRICT_FILE_LOCKED 9 /* make bit-8 immutable */

#define SECBIT_EXEC_RESTRICT_FILE (issecure_mask(SECURE_EXEC_RESTRICT_FILE))
#define SECBIT_EXEC_RESTRICT_FILE_LOCKED (issecure_mask(SECURE_EXEC_RESTRICT_FILE_LOCKED))

#define SECURE_EXEC_DENY_INTERACTIVE 10
#define SECURE_EXEC_DENY_INTERACTIVE_LOCKED 11 /* make bit-10 immutable */

#define SECBIT_EXEC_DENY_INTERACTIVE (issecure_mask(SECURE_EXEC_DENY_INTERACTIVE))
#define SECBIT_EXEC_DENY_INTERACTIVE_LOCKED (issecure_mask(SECURE_EXEC_DENY_INTERACTIVE_LOCKED))

#define SECURE_ALL_BITS                                                                 \
        (issecure_mask(SECURE_NOROOT) | issecure_mask(SECURE_NO_SETUID_FIXUP) |         \
         issecure_mask(SECURE_KEEP_CAPS) | issecure_mask(SECURE_NO_CAP_AMBIENT_RAISE) | \
         issecure_mask(SECURE_EXEC_RESTRICT_FILE) | issecure_mask(SECURE_EXEC_DENY_INTERACTIVE))
#define SECURE_ALL_LOCKS (SECURE_ALL_BITS << 1)

#define SECURE_ALL_UNPRIVILEGED \
        (issecure_mask(SECURE_EXEC_RESTRICT_FILE) | issecure_mask(SECURE_EXEC_DENY_INTERACTIVE))

#endif /* _LINUX_SECUREBITS_H */
