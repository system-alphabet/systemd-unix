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

/* Linux-specific signal: SIGPWR (power failure) */
#ifndef SIGPWR
#define SIGPWR  30
#endif

/* Linux-specific si_code values for SIGILL */
#ifndef ILL_BADIADDR
#define ILL_BADIADDR    (__SI_FAULT - 1)
#endif

/* Linux-specific si_code values for SIGFPE */
#ifndef FPE_FLTUNK
#define FPE_FLTUNK      14
#endif

/* Linux-specific si_code values for SIGSEGV */
#ifndef SEGV_BNDERR
#define SEGV_BNDERR     3
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
