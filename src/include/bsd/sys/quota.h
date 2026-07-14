/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* Linux quota syscalls are not available on FreeBSD. Provide stubs. */

#define USRQUOTA  0
#define GRPQUOTA  1
#define PRJQUOTA  2

#define Q_QUOTAON  0x0100
#define Q_QUOTAOFF 0x0200
#define Q_GETQUOTA 0x0300
#define Q_SETQUOTA 0x0400

/* QCMD macro: build quota command from sub-command and quota type */
#define QCMD(cmd, type) ((cmd) | ((type) << 8))

int quotactl(int cmd, const char *special, int id, void *addr);
int quotactl_fd(int fd, int cmd, int id, void *addr);
