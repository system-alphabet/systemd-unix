/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include <sys/stat.h>

#include "env-file.h"
#include "env-file-label.h"
#include "locale-setup.h"

int write_env_file_label(int dir_fd, const char *fname, char **headers, char **l) {
        return write_env_file(dir_fd, fname, headers, l);
}

int write_vconsole_conf_label(char **l) {
        return write_vconsole_conf(AT_FDCWD, etc_vconsole_conf(), l);
}
