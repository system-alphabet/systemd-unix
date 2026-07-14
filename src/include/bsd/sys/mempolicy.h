/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* Minimal stub for Linux NUMA memory policy API. */

#define MPOL_DEFAULT            0
#define MPOL_PREFERRED          1
#define MPOL_BIND               2
#define MPOL_INTERLEAVE         3
#define MPOL_LOCAL              4
#define MPOL_PREFERRED_MANY     5
#define MPOL_WEIGHTED_INTERLEAVE 6

#define MPOL_F_STATIC_NODES     (1 << 0)
#define MPOL_F_RELATIVE_NODES   (1 << 1)
#define MPOL_F_NUMA_BALANCING   (1 << 2)

/* Stubs for Linux NUMA memory policy syscalls */
int get_mempolicy(int *mode, unsigned long *nodemask, unsigned long maxnode,
                  void *addr, unsigned long flags);
int set_mempolicy(int mode, const unsigned long *nodemask, unsigned long maxnode);
