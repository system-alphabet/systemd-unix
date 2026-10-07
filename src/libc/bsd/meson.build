# SPDX-License-Identifier: LGPL-2.1-or-later

if get_option('libc') != 'bsd'
        subdir_done()
endif

libc_sources = files(
        'epoll.c',
        'eventfd.c',
        'inotify.c',
        'keyctl.c',
        'linux-stubs.c',
        'memfd.c',
        'misc.c',
        'signalfd.c',
        'timerfd.c',
        'xattr.c',
)

# kqueue(), kevent() and EV_SET() are provided by libc on real BSD systems. The stubs in
# kqueue-stubs.c would shadow those definitions and turn every kqueue-based implementation into an
# ENOSYS failure, hence they are only built when -Dlibc=bsd is compiled on a non-BSD host for build
# validation. This condition must match the one in src/include/bsd/sys/event.h, which decides
# whether the real <sys/event.h> or our stand-in for it is used.
if host_machine.system() not in ['freebsd', 'netbsd', 'openbsd', 'dragonfly', 'darwin']
        libc_sources += files('kqueue-stubs.c')
endif

libc_wrapper_sources += libc_sources
