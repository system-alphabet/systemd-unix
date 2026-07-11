/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/*
 * Linux <sys/personality.h> — process execution domain.
 * FreeBSD stub used by src/basic/process-util.c.
 */

#ifndef ADDR_NO_RANDOMIZE
#define ADDR_NO_RANDOMIZE       0x0040000
#endif
#ifndef ADDR_LIMIT_3GB
#define ADDR_LIMIT_3GB          0x8000000
#endif
#ifndef MMAP_PAGE_ZERO
#define MMAP_PAGE_ZERO          0x0100000
#endif
#ifndef ADDR_COMPAT_LAYOUT
#define ADDR_COMPAT_LAYOUT      0x0200000
#endif
#ifndef READ_IMPLIES_EXEC
#define READ_IMPLIES_EXEC       0x0400000
#endif
#ifndef ADDR_LIMIT_32BIT
#define ADDR_LIMIT_32BIT        0x0800000
#endif
#ifndef SHORT_INODE
#define SHORT_INODE             0x1000000
#endif
#ifndef WHOLE_SECONDS
#define WHOLE_SECONDS           0x2000000
#endif
#ifndef STICKY_TIMEOUTS
#define STICKY_TIMEOUTS         0x4000000
#endif
#ifndef ADDR_RANDOMIZE
#define ADDR_RANDOMIZE          0x0040000
#endif

#ifndef PER_LINUX
#define PER_LINUX               0x0000
#endif
#ifndef PER_LINUX_32BIT
#define PER_LINUX_32BIT         0x0008
#endif
#ifndef PER_LINUX_FDPIC
#define PER_LINUX_FDPIC         0x0016
#endif
#ifndef PER_SVR4
#define PER_SVR4                0x0001
#endif
#ifndef PER_SVR3
#define PER_SVR3                0x0002
#endif
#ifndef PER_SCOSVR3
#define PER_SCOSVR3             0x0003
#endif
#ifndef PER_OSR5
#define PER_OSR5                0x0005
#endif
#ifndef PER_WYSEV386
#define PER_WYSEV386            0x0006
#endif
#ifndef PER_ISCR4
#define PER_ISCR4               0x0007
#endif
#ifndef PER_BSD
#define PER_BSD                 0x0009
#endif
#ifndef PER_SUNOS
#define PER_SUNOS               0x000A
#endif
#ifndef PER_XENIX
#define PER_XENIX               0x000B
#endif
#ifndef PER_LINUX32
#define PER_LINUX32             0x000C
#endif
#ifndef PER_IRIX32
#define PER_IRIX32              0x000D
#endif
#ifndef PER_IRIXN32
#define PER_IRIXN32             0x000E
#endif
#ifndef PER_IRIX64
#define PER_IRIX64              0x000F
#endif
#ifndef PER_RISCOS
#define PER_RISCOS              0x0010
#endif
#ifndef PER_SOLARIS
#define PER_SOLARIS             0x0011
#endif
#ifndef PER_UW7
#define PER_UW7                 0x0012
#endif
#ifndef PER_OSF4
#define PER_OSF4                0x0013
#endif
#ifndef PER_HPUX
#define PER_HPUX                0x0014
#endif

int personality(unsigned long persona);
