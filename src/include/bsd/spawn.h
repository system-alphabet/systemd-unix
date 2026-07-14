/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <spawn.h>

/* pidfd_spawn() and posix_spawnattr_setcgroup_np() — glibc 2.39+ extensions.
 * Not available on FreeBSD. */
#ifndef POSIX_SPAWN_SETCGROUP
#  define POSIX_SPAWN_SETCGROUP 0x100
#endif

int pidfd_spawn(pid_t *pidfd, const char *path,
                const posix_spawn_file_actions_t *file_actions,
                const posix_spawnattr_t *attrp,
                char *const argv[], char *const envp[]);

int posix_spawnattr_setcgroup_np(posix_spawnattr_t *attr, int cgroup);
