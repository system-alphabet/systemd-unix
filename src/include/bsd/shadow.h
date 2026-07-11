/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * FreeBSD does not have a system <shadow.h>.
 * This minimal shim provides the Linux shadow password structures
 * used by systemd for /etc/shadow access.
 *
 * On FreeBSD, shadow passwords are managed via the getpwnam(3) family
 * (libutil) or directly via /etc/master.passwd. This shim allows
 * compilation of code that references struct spwd.
 */

#include <sys/types.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Shadow password structure matching Linux */
struct spwd {
        char    *sp_namp;       /* login name */
        char    *sp_pwdp;       /* encrypted password */
        long     sp_lstchg;     /* date of last change */
        long     sp_min;        /* min days between changes */
        long     sp_max;        /* max days between changes */
        long     sp_warn;       /* days before password expires to warn user */
        long     sp_inact;      /* days after password expires until account is disabled */
        long     sp_expire;     /* absolute date to expire the account */
        unsigned long sp_flag;  /* reserved */
};

struct spwd *getspnam(const char *name);
struct spwd *getspent(void);
struct spwd *fgetspent(FILE *fp);
void setspent(void);
void endspent(void);
int putspent(const struct spwd *p, FILE *fp);

#ifdef __cplusplus
}
#endif
