/* SPDX-License-Identifier: LGPL-2.1-or-later */

#include <sys/stat.h>
#include <unistd.h>

#include "btrfs-util.h"
#include "errno-util.h"
#include "label-util.h"
#include "smack-util.h"

int label_fix_full(
                int atfd,
                const char *inode_path, /* path of inode to apply label to */
                const char *label_path, /* path to use as database lookup key in label database (typically same as inode_path, but not always) */
                LabelFixFlags flags) {

        int r;

        if (atfd < 0 && atfd != AT_FDCWD)
                return -EBADF;

        if (!inode_path && atfd < 0) /* We need at least one of atfd and an inode path */
                return -EINVAL;

        r = mac_smack_fix_full(atfd, inode_path, label_path, flags);
        if (r < 0)
                return r;

        return 0;
}

int symlink_label(const char *old_path, const char *new_path) {
        int r;

        assert(old_path);
        assert(new_path);

        r = RET_NERRNO(symlink(old_path, new_path));
        if (r < 0)
                return r;

        return mac_smack_fix(new_path, 0);
}

int mknodat_label(int dirfd, const char *pathname, mode_t mode, dev_t dev) {
        int r;

        assert(dirfd >= 0 || dirfd == AT_FDCWD);
        assert(pathname);

        r = RET_NERRNO(mknodat(dirfd, pathname, mode, dev));
        if (r < 0)
                return r;

        return mac_smack_fix_full(dirfd, pathname, NULL, 0);
}

int btrfs_subvol_make_label(const char *path) {
        int r;

        assert(path);

        r = btrfs_subvol_make(AT_FDCWD, path);
        if (r < 0)
                return r;

        return mac_smack_fix(path, 0);
}

static int init_internal(bool lazy) {
        int r;

        assert(!mac_smack_use());

        r = mac_smack_init();
        if (r < 0)
                return r;

        return 0;
}

int mac_init_lazy(void) {
        return init_internal(/* lazy= */ true);
}

int mac_init(void) {
        return init_internal(/* lazy= */ false);
}
