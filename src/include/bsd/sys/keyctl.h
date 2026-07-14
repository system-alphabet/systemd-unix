/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include <sys/types.h>
#include <stddef.h>
#include <errno.h>

typedef int key_serial_t;

/* Linux KEYCTL_* constants (from <linux/keyctl.h>).
 * The override/uapi paths are skipped in bsd builds, so we provide
 * them directly. */
#ifndef KEYCTL_GET_KEYRING_ID
#define KEYCTL_GET_KEYRING_ID           0
#endif
#ifndef KEYCTL_JOIN_SESSION_KEYRING
#define KEYCTL_JOIN_SESSION_KEYRING     1
#endif
#ifndef KEYCTL_UPDATE
#define KEYCTL_UPDATE                   2
#endif
#ifndef KEYCTL_REVOKE
#define KEYCTL_REVOKE                   3
#endif
#ifndef KEYCTL_CHOWN
#define KEYCTL_CHOWN                    4
#endif
#ifndef KEYCTL_SETPERM
#define KEYCTL_SETPERM                  5
#endif
#ifndef KEYCTL_DESCRIBE
#define KEYCTL_DESCRIBE                 6
#endif
#ifndef KEYCTL_CLEAR
#define KEYCTL_CLEAR                    7
#endif
#ifndef KEYCTL_LINK
#define KEYCTL_LINK                     8
#endif
#ifndef KEYCTL_UNLINK
#define KEYCTL_UNLINK                   9
#endif
#ifndef KEYCTL_SEARCH
#define KEYCTL_SEARCH                   10
#endif
#ifndef KEYCTL_READ
#define KEYCTL_READ                     11
#endif
#ifndef KEYCTL_INSTANTIATE
#define KEYCTL_INSTANTIATE              12
#endif
#ifndef KEYCTL_NEGATE
#define KEYCTL_NEGATE                   13
#endif
#ifndef KEYCTL_SET_REQKEY_KEYRING
#define KEYCTL_SET_REQKEY_KEYRING       14
#endif
#ifndef KEYCTL_SET_TIMEOUT
#define KEYCTL_SET_TIMEOUT              15
#endif
#ifndef KEYCTL_ASSUME_AUTHORITY
#define KEYCTL_ASSUME_AUTHORITY         16
#endif
#ifndef KEYCTL_GET_SECURITY
#define KEYCTL_GET_SECURITY             17
#endif
#ifndef KEYCTL_SESSION_TO_PARENT
#define KEYCTL_SESSION_TO_PARENT        18
#endif
#ifndef KEYCTL_REJECT
#define KEYCTL_REJECT                   19
#endif
#ifndef KEYCTL_INSTANTIATE_IOV
#define KEYCTL_INSTANTIATE_IOV          20
#endif
#ifndef KEYCTL_INVALIDATE
#define KEYCTL_INVALIDATE               21
#endif
#ifndef KEYCTL_GET_PERSISTENT
#define KEYCTL_GET_PERSISTENT           22
#endif
#ifndef KEYCTL_DH_COMPUTE
#define KEYCTL_DH_COMPUTE               23
#endif
#ifndef KEYCTL_RESTRICT_KEYRING
#define KEYCTL_RESTRICT_KEYRING         29
#endif
#ifndef KEYCTL_MOVE
#define KEYCTL_MOVE                     31
#endif
#ifndef KEYCTL_CAPABILITIES
#define KEYCTL_CAPABILITIES             (-4)
#endif
#ifndef KEYCTL_WATCH_KEY
#define KEYCTL_WATCH_KEY                32
#endif

/* Key permission constants (from linux/keyctl.h / keyutils.h) */
#ifndef KEY_POS_VIEW
#define KEY_POS_VIEW     0x01000000
#endif
#ifndef KEY_POS_READ
#define KEY_POS_READ     0x02000000
#endif
#ifndef KEY_POS_SEARCH
#define KEY_POS_SEARCH   0x08000000
#endif
#ifndef KEY_USR_VIEW
#define KEY_USR_VIEW     0x00010000
#endif
#ifndef KEY_USR_READ
#define KEY_USR_READ     0x00020000
#endif
#ifndef KEY_USR_SEARCH
#define KEY_USR_SEARCH   0x00080000
#endif

/* Special keyring shortcut IDs */
#ifndef KEY_SPEC_THREAD_KEYRING
#define KEY_SPEC_THREAD_KEYRING         (-1)
#endif
#ifndef KEY_SPEC_PROCESS_KEYRING
#define KEY_SPEC_PROCESS_KEYRING        (-2)
#endif
#ifndef KEY_SPEC_SESSION_KEYRING
#define KEY_SPEC_SESSION_KEYRING        (-3)
#endif
#ifndef KEY_SPEC_USER_KEYRING
#define KEY_SPEC_USER_KEYRING           (-4)
#endif
#ifndef KEY_SPEC_USER_SESSION_KEYRING
#define KEY_SPEC_USER_SESSION_KEYRING   (-5)
#endif
#ifndef KEY_SPEC_GROUP_KEYRING
#define KEY_SPEC_GROUP_KEYRING          (-6)
#endif
#ifndef KEY_SPEC_REQKEY_AUTH_KEY
#define KEY_SPEC_REQKEY_AUTH_KEY        (-7)
#endif
#ifndef KEY_SPEC_REQUESTOR_KEYRING
#define KEY_SPEC_REQUESTOR_KEYRING      (-8)
#endif

long keyctl_shim(int cmd, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5);
#define keyctl keyctl_shim
key_serial_t add_key_shim(const char *type, const char *description, const void *payload, size_t plen, key_serial_t ringid);
#define add_key add_key_shim
key_serial_t request_key_shim(const char *type, const char *description, const char *callout_info, key_serial_t destringid);
#define request_key request_key_shim
