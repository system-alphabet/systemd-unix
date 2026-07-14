/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <sys/signal.h>

/*
 * Linux-specific signal numbers and siginfo codes not present on FreeBSD.
 */

/* _NSIG — number of standard signal numbers. FreeBSD uses NSIG. */
#ifndef _NSIG
#ifdef NSIG
#define _NSIG NSIG
#else
#define _NSIG 128
#endif
#endif

/* Linux-specific signal: SIGPWR (power failure)
 * FreeBSD uses SIGUSR1=30, so pick an unused number (34). */
#ifndef SIGPWR
#define SIGPWR  34
#endif

/* Linux-specific si_code values for SIGILL */
#ifndef ILL_BADIADDR
#define ILL_BADIADDR    9
#endif

/* Linux-specific si_code values for SIGFPE */
#ifndef FPE_FLTUNK
#define FPE_FLTUNK      14
#endif
#ifndef FPE_CONDTRAP
#define FPE_CONDTRAP    15
#endif

/* Linux-specific si_code values for SIGSEGV */
#ifndef SEGV_BNDERR
#define SEGV_BNDERR     3
#endif
#ifndef SEGV_ACCADI
#define SEGV_ACCADI     5
#endif
#ifndef SEGV_ADIDERR
#define SEGV_ADIDERR    6
#endif
#ifndef SEGV_ADIPERR
#define SEGV_ADIPERR    7
#endif
#ifndef SEGV_MTEAERR
#define SEGV_MTEAERR    8
#endif
#ifndef SEGV_MTESERR
#define SEGV_MTESERR    9
#endif
#ifndef SEGV_CPERR
#define SEGV_CPERR      10
#endif

/* Linux-specific si_code values for SIGBUS */
#ifndef BUS_MCEERR_AR
#define BUS_MCEERR_AR   4
#endif
#ifndef BUS_MCEERR_AO
#define BUS_MCEERR_AO   5
#endif

/* Linux-specific si_code values for SIGTRAP */
#ifndef TRAP_BRANCH
#define TRAP_BRANCH     3
#endif
#ifndef TRAP_HWBKPT
#define TRAP_HWBKPT     4
#endif
#ifndef TRAP_UNK
#define TRAP_UNK        5
#endif
#ifndef TRAP_PERF
#define TRAP_PERF       6
#endif

/* Linux-specific si_code values for SIGSYS */
#ifndef SYS_SECCOMP
#define SYS_SECCOMP     1
#endif
#ifndef SYS_USER_DISPATCH
#define SYS_USER_DISPATCH 2
#endif

/* Linux SI_* codes */
#ifndef SI_ASYNCNL
#define SI_ASYNCNL      (-60)
#endif
#ifndef SI_DETHREAD
#define SI_DETHREAD     (-7)
#endif
#ifndef SI_TKILL
#define SI_TKILL        (-6)
#endif
#ifndef SI_SIGIO
#define SI_SIGIO        (-5)
#endif
#ifndef SI_ASYNCIO
#define SI_ASYNCIO      (-4)
#endif
#ifndef SI_MESGQ
#define SI_MESGQ        (-3)
#endif
#ifndef SI_TIMER
#define SI_TIMER        (-2)
#endif
#ifndef SI_QUEUE
#define SI_QUEUE        (-1)
#endif
#ifndef SI_USER
#define SI_USER         0
#endif
#ifndef SI_KERNEL
#define SI_KERNEL       0x80
#endif

/* __SI_FAULT is used internally for computing si_code offsets */
#ifndef __SI_FAULT
#define __SI_FAULT      0
#endif

/* SIGPOLL — Linux names SIGIO for poll events; FreeBSD only defines SIGIO. */
#ifndef SIGPOLL
#define SIGPOLL SIGIO
#endif

/* Linux-compatible siginfo_t convenience members.
 * FreeBSD's siginfo_t uses si_value.sival_int / si_value.sival_ptr. */
#ifndef si_int
#define si_int  si_value.sival_int
#endif
#ifndef si_ptr
#define si_ptr  si_value.sival_ptr
#endif

/* rt_tgsigqueueinfo — Linux-specific syscall wrapper. */
int rt_tgsigqueueinfo(__pid_t tgid, __pid_t tid, int sig, siginfo_t *info);
