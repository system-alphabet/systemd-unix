/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * FreeBSD provides getauxval() in <sys/auxv.h> (since FreeBSD 12).
 * This shim ensures the function is declared when code includes <sys/auxv.h>.
 *
 * NetBSD has no <sys/auxv.h> at all; its AT_* constants live in <sys/exec_elf.h>, so fall back to that
 * instead of blindly using include_next, which would fail with "file not found".
 */

#if defined(__has_include_next) && __has_include_next(<sys/auxv.h>)
#  include_next <sys/auxv.h>
#elif defined(__has_include) && __has_include(<sys/exec_elf.h>)
#  include <sys/exec_elf.h>
#endif

#ifndef AT_PHDR
#define AT_PHDR                3
#endif
#ifndef AT_PHENT
#define AT_PHENT               4
#endif
#ifndef AT_PHNUM
#define AT_PHNUM               5
#endif
#ifndef AT_PAGESZ
#define AT_PAGESZ              6
#endif
#ifndef AT_BASE
#define AT_BASE                7
#endif
#ifndef AT_FLAGS
#define AT_FLAGS               8
#endif
#ifndef AT_ENTRY
#define AT_ENTRY               9
#endif
#ifndef AT_UID
#define AT_UID                 11
#endif
#ifndef AT_EUID
#define AT_EUID                12
#endif
#ifndef AT_GID
#define AT_GID                 13
#endif
#ifndef AT_EGID
#define AT_EGID                14
#endif
#ifndef AT_SECURE
#define AT_SECURE              23
#endif
#ifndef AT_RANDOM
#define AT_RANDOM              25
#endif
#ifndef AT_EXECFN
#define AT_EXECFN              31
#endif
#ifndef AT_SYSINFO_EHDR
#define AT_SYSINFO_EHDR        33
#endif
#ifndef AT_MINSIGSTKSZ
#define AT_MINSIGSTKSZ         51
#endif

unsigned long getauxval(unsigned long type);
