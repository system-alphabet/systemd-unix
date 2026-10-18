/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * coredump-util.c parses the process's own ELF auxiliary vector through
 * <elf.h>'s AT_* constants. NetBSD's <elf.h> pulls in <sys/exec_elf.h>, whose
 * numbering is the Solaris-flavoured one: it has no AT_UID/AT_GID at all
 * (11/13 are AT_ICACHEBSIZE/AT_STACKBASE there) and uses AT_EUID 2000 etc. Our
 * <sys/auxv.h> shim already carries the Linux fallback values, so pull it in.
 */

#include_next <elf.h>

#include <sys/auxv.h>
