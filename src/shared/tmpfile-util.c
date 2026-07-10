/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include <sys/stat.h>

#include "tmpfile-util.h"

int fopen_temporary_at_label(
                int dir_fd,
                const char *target,
                const char *path,
                FILE **f,
                char **temp_path) {

        assert(dir_fd >= 0 || dir_fd == AT_FDCWD);
        assert(path);

        return fopen_temporary_at(dir_fd, path, f, temp_path);
}
