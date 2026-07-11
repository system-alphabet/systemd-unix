/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * POSIX message queues — Linux <mqueue.h>.
 * Some FreeBSD versions may not have this; provide minimal stub.
 */

#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mq_attr {
        long    mq_flags;
        long    mq_maxmsg;
        long    mq_msgsize;
        long    mq_curmsgs;
        long    __reserved[4];
} mqd_t;

mqd_t mq_open(const char *name, int oflag, ...);
int mq_close(mqd_t mqdes);
int mq_unlink(const char *name);
int mq_getattr(mqd_t mqdes, struct mq_attr *attr);
int mq_setattr(mqd_t mqdes, const struct mq_attr *newattr, struct mq_attr *oldattr);
int mq_notify(mqd_t mqdes, const struct sigevent *notification);
ssize_t mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio);
ssize_t mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
                     unsigned int msg_prio, const struct timespec *abs_timeout);
ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio);
ssize_tmq_timedreceive(mqd_t mqdes, char *msg_ptr, size_t msg_len,
                       unsigned int *msg_prio, const struct timespec *abs_timeout);

#ifdef __cplusplus
}
#endif
