# SPDX-License-Identifier: LGPL-2.1-or-later

subdir('override/sys')

need_linux_uapi = get_option('libc') != 'bsd'

# Source files that provides AF_XYZ
af_sources = files(
        'override/sys/socket.h',
)

# Source files that provides ARPHRD_XYZ
arphrd_sources = files(
        'uapi/linux/if_arp.h',
)

# Source files that provides CAP_XYZ
if need_linux_uapi
        capability_sources = files(
                'uapi/linux/capability.h',
        )
else
        capability_sources = []
endif

# Source files that provides BPF delegate options
if need_linux_uapi
        bpf_delegate_sources = files(
                'uapi/linux/bpf.h',
        )
else
        bpf_delegate_sources = []
endif

# Source files that provides ETHTOOL_LINK_MODE_XYZ
if need_linux_uapi
        ethtool_link_mode_sources = files(
                'uapi/linux/ethtool.h',
        )
else
        ethtool_link_mode_sources = []
endif

# Source files that provides IPPROTO_XYZ
if need_linux_uapi
        ipproto_sources = files(
                'override/netinet/in.h',
                'uapi/linux/in.h',
        )
else
        ipproto_sources = []
endif

# Source files that provides KEY_XYZ
if need_linux_uapi
        keyboard_sources = files(
                'uapi/linux/input.h',
                'uapi/linux/input-event-codes.h',
        )
else
        keyboard_sources = []
endif

# Source files that provides STATX_*
if need_linux_uapi
        statx_sources = files(
                'uapi/linux/stat.h',
        )
else
        statx_sources = []
endif
