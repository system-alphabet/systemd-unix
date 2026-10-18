/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * BSD shim for <sched.h>.
 * FreeBSD provides the POSIX scheduling API; we add the Linux clone()
 * flags that systemd uses for namespace operations and thread spawning.
 */

#include_next <sched.h>

#ifndef CLONE_VM
#define CLONE_VM                        0x00000100
#endif
#ifndef CLONE_PARENT_SETTID
#define CLONE_PARENT_SETTID             0x00100000
#endif
#ifndef CLONE_CHILD_SETTID
#define CLONE_CHILD_SETTID              0x01000000
#endif
#ifndef CLONE_CHILD_CLEARTID
#define CLONE_CHILD_CLEARTID            0x00200000
#endif
#ifndef CLONE_NEWNS
#define CLONE_NEWNS                     0x00020000
#endif
#ifndef CLONE_NEWIPC
#define CLONE_NEWIPC                    0x08000000
#endif
#ifndef CLONE_NEWUSER
#define CLONE_NEWUSER                   0x10000000
#endif
#ifndef CLONE_NEWPID
#define CLONE_NEWPID                    0x20000000
#endif
#ifndef CLONE_NEWNET
#define CLONE_NEWNET                    0x40000000
#endif
#ifndef CLONE_NEWUTS
#define CLONE_NEWUTS                    0x04000000
#endif
#ifndef CLONE_NEWCGROUP
#define CLONE_NEWCGROUP                 0x02000000
#endif
#ifndef CLONE_NEWTIME
#define CLONE_NEWTIME                   0x00000080
#endif
#ifndef CLONE_SETTLS
#define CLONE_SETTLS                    0x00080000
#endif
#ifndef CLONE_PIDFD
#define CLONE_PIDFD                     0x00001000
#endif

#ifndef CLONE_VFORK
#define CLONE_VFORK                     0x00004000
#endif

#ifndef CLONE_FILES
#define CLONE_FILES                     0x00000400
#endif

#ifndef CLONE_FS
#define CLONE_FS                        0x00000200
#endif

/* Linux scheduling policies — FreeBSD uses different values so we override them all.
 * Must come AFTER #include_next <sched.h> so we can undefine the FreeBSD versions. */
#ifdef SCHED_OTHER
#undef SCHED_OTHER
#endif
#define SCHED_OTHER                     0

/* SCHED_FIFO = 1 is the same on both FreeBSD and Linux, keep as-is. */

#ifdef SCHED_RR
#undef SCHED_RR
#endif
#define SCHED_RR                        2

#ifndef SCHED_BATCH
#define SCHED_BATCH                     3
#endif
#ifndef SCHED_IDLE
#define SCHED_IDLE                      5
#endif
#ifndef SCHED_EXT
#define SCHED_EXT                       7
#endif
#ifndef SCHED_RESET_ON_FORK
#define SCHED_RESET_ON_FORK             0x40000000
#endif

/* schedule.h — Linux process flag indicating a kernel thread. */
#ifndef PF_KTHREAD
#define PF_KTHREAD                      0x00200000
#endif

/* TASK_COMM_LEN — length of the comm field in /proc/self/comm.
 * Defined in include/linux/sched.h on Linux. */
#ifndef TASK_COMM_LEN
#define TASK_COMM_LEN 16
#endif

/* setns — Linux namespace switching syscall.  Unavailable on FreeBSD. */
int setns(int fd, int nstype);

/* unshare — Linux namespace disassociate syscall.  Unavailable on FreeBSD. */
int unshare(int flags);

/* clone/__clone2 — Linux thread/process creation syscalls.  Unavailable on FreeBSD. */
int __clone2(int (*fn)(void *), void *stack_base, size_t stack_size, int flags, void *arg);

/* Non-ia64 builds use clone(); on FreeBSD we have neither so we pick __clone2. */
#define HAVE_CLONE 0

#if defined(__NetBSD__)

/*
 * NetBSD has none of the Linux CPU-set interface: no cpu_set_t, no CPU_ALLOC()/CPU_SET_S()/CPU_COUNT_S(),
 * and no plain sched_getaffinity(). What it does have in <sys/sched.h> is an opaque cpuset_t plus a
 * cpuset_create()/cpuset_isset()/cpuset_size() API. Because struct _cpuset is never defined in any
 * installed header, sizeof(cpuset_t) is unknown at compile time, so the malloc()-based interface that
 * src/shared/cpu-set-util.c is built around cannot be layered on top of it. Model Linux's bitmap
 * semantics ourselves and translate in sched_getaffinity().
 */

#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* Same layout contract as glibc: cpu_set_t is a word-aligned bitmap, CPU_ALLOC_SIZE() turns a CPU count
 * into a size in bytes, and the _S variants take that size rather than deriving it from the type. */
typedef union {
        unsigned long __bits[1024 / (sizeof(unsigned long) * 8)];
} cpu_set_t;

#define CPU_ALLOC_SIZE(n) \
        (((((n) + sizeof(unsigned long) * 8 - 1) / (sizeof(unsigned long) * 8))) * sizeof(unsigned long))

#define CPU_ALLOC(n) malloc(CPU_ALLOC_SIZE(n))
#define CPU_FREE(p)  free(p)

#define CPU_ZERO(set)       memset((set), 0, sizeof(cpu_set_t))
#define CPU_ZERO_S(size, set) memset((set), 0, (size))

#define CPU_SET(cpu, set)   CPU_SET_S((cpu), sizeof(cpu_set_t), (set))
#define CPU_CLR(cpu, set)   CPU_CLR_S((cpu), sizeof(cpu_set_t), (set))
#define CPU_ISSET(cpu, set) CPU_ISSET_S((cpu), sizeof(cpu_set_t), (set))

#define CPU_SET_S(cpu, size, set)                                           \
        do {                                                                \
                size_t _cpu_ = (cpu), _size_ = (size);                      \
                unsigned char *_p_ = (unsigned char*) (set);                \
                if (_cpu_ / 8 < _size_)                                     \
                        _p_[_cpu_ / 8] |= (unsigned char) (1u << (_cpu_ % 8)); \
        } while (false)

#define CPU_CLR_S(cpu, size, set)                                           \
        do {                                                                \
                size_t _cpu_ = (cpu), _size_ = (size);                      \
                unsigned char *_p_ = (unsigned char*) (set);                \
                if (_cpu_ / 8 < _size_)                                     \
                        _p_[_cpu_ / 8] &= (unsigned char) ~(1u << (_cpu_ % 8)); \
        } while (false)

#define CPU_ISSET_S(cpu, size, set)                                         \
        ((size_t) (cpu) / 8 < (size_t) (size) &&                            \
         ((((const unsigned char*) (set))[(size_t) (cpu) / 8]) &            \
          (unsigned char) (1u << ((size_t) (cpu) % 8))) != 0)

#define CPU_COUNT_S(size, set)                                             \
        __extension__ ({                                                    \
                size_t _size_ = (size);                                     \
                const unsigned char *_p_ = (const unsigned char*) (set);    \
                int _n_ = 0;                                                \
                for (size_t _i_ = 0; _i_ < _size_; _i_++)                   \
                        for (unsigned _b_ = 0; _b_ < 8; _b_++)              \
                                if (_p_[_i_] & (unsigned char) (1u << _b_))  \
                                        _n_++;                              \
                _n_;                                                        \
        })

/* Linux's sched_getaffinity() takes a bitmap, NetBSD's _np variant takes an opaque cpuset_t. Translate,
 * and fail with EINVAL when the caller's buffer is too small — that is what makes cpus_in_affinity_mask()
 * in src/shared/cpu-set-util.c grow its buffer and retry. */
static inline int sched_getaffinity(pid_t pid, size_t setsize, cpu_set_t *set) {
        cpuset_t *c;
        size_t nbits;
        int r;

        if (!set || setsize == 0)
                return errno = EINVAL, -1;

        c = cpuset_create();
        if (!c)
                return -1;

        r = sched_getaffinity_np(pid, cpuset_size(c), c);
        if (r < 0) {
                cpuset_destroy(c);
                return -1;
        }

        /* The opaque cpuset is a bitmap indexed by cpuid_t, so its size tells us the valid CPU range. */
        nbits = cpuset_size(c) * 8;
        memset(set, 0, setsize);

        for (size_t i = 0; i < nbits; i++) {
                if (!cpuset_isset((cpuid_t) i, c))
                        continue;

                if (i / 8 >= setsize) {
                        cpuset_destroy(c);
                        return errno = EINVAL, -1;
                }

                ((unsigned char*) set)[i / 8] |= (unsigned char) (1u << (i % 8));
        }

        cpuset_destroy(c);
        return 0;
}

#endif /* __NetBSD__ */
