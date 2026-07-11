/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

/* Linux getrandom() flags and /dev/random ioctls.
 * Used by src/basic/random-util.c. */

#include <linux/types.h>

#ifndef GRND_NONBLOCK
#define GRND_NONBLOCK 0x0001
#endif
#ifndef GRND_RANDOM
#define GRND_RANDOM 0x0002
#endif
#ifndef GRND_INSECURE
#define GRND_INSECURE 0x0004
#endif

/* RNDADDENTROPY and struct rand_pool_info — Linux /dev/random ioctl. */
#ifndef RNDADDENTROPY
#define RNDADDENTROPY   _IOW('R', 0x03, struct rand_pool_info)
#endif

#define RND_MAX_ENTROPY_POOL_WORDS 128
struct rand_pool_info {
        int     entropy_count;
        int     buf_size;
        __u32   buf[RND_MAX_ENTROPY_POOL_WORDS];
};
