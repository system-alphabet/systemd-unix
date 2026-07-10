# SPDX-License-Identifier: LGPL-2.1-or-later

if get_option('libc') != 'bsd'
        subdir_done()
endif

libc_wrapper_sources += files(
        'epoll.c',
        'eventfd.c',
        'inotify.c',
        'keyctl.c',
        'kqueue-stubs.c',
        'linux-stubs.c',
        'memfd.c',
        'misc.c',
        'signalfd.c',
        'timerfd.c',
        'xattr.c',
)
