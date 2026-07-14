/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * POSIX message queues — Linux <mqueue.h>.
 *
 * On FreeBSD, mqd_t is 'struct __mq *' (a pointer), but systemd code
 * uses it as int (Linux uses an fd-based implementation). We provide
 * an int-based interface that matches the Linux ABI, wrapping the
 * native FreeBSD mq_open/mq_close implementations in misc.c.
 */

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

/* On Linux, mqd_t is an int (a file descriptor). We override it here to
 * match that expectation. The native FreeBSD mqd_t (struct __mq *) is
 * completely hidden from systemd code.
 *
 * We use a #define so that it takes effect before the function declarations
 * below, then undefine it to avoid polluting downstream code.
 */
#define mqd_t int

struct mq_attr {
        long    mq_flags;
        long    mq_maxmsg;
        long    mq_msgsize;
        long    mq_curmsgs;
        long    __reserved[4];
};

int mq_open(const char *name, int oflag, ...);
int mq_close(int mqdes);
int mq_unlink(const char *name);
int mq_getattr(int mqdes, struct mq_attr *attr);
int mq_setattr(int mqdes, const struct mq_attr *newattr, struct mq_attr *oldattr);
int mq_notify(int mqdes, const struct sigevent *notification);
ssize_t mq_send(int mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio);
ssize_t mq_timedsend(int mqdes, const char *msg_ptr, size_t msg_len,
                     unsigned int msg_prio, const struct timespec *abs_timeout);
ssize_t mq_receive(int mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio);
ssize_t mq_timedreceive(int mqdes, char *msg_ptr, size_t msg_len,
                        unsigned int *msg_prio, const struct timespec *abs_timeout);

#undef mqd_t
/* Restore the original system definition by re-including sys/types.h.
 * Actually, we can't undo a typedef. But systemd code shouldn't use mqd_t
 * directly — it uses int for message queue descriptors. */

#ifdef __cplusplus
}
#endif
