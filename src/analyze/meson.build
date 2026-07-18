# SPDX-License-Identifier: LGPL-2.1-or-later

systemd_analyze_sources = files(
        'analyze-architectures.c',
        'analyze-blame.c',
        'analyze-calendar.c',
        'analyze-capability.c',
        'analyze-cat-config.c',
        'analyze-chid.c',
        'analyze-compare-versions.c',
        'analyze-critical-chain.c',
        'analyze-dlopen-metadata.c',
        'analyze-dot.c',
        'analyze-dump.c',
        'analyze-exit-status.c',
        'analyze-fdstore.c',
        'analyze-filesystems.c',
        'analyze-image-policy.c',
        'analyze-inspect-elf.c',
        'analyze-log-control.c',
        'analyze-malloc.c',
        'analyze-pcrs.c',
        'analyze-plot.c',
        'analyze-service-watchdogs.c',
        'analyze-smbios11.c',
        'analyze-syscall-filter.c',
        'analyze-time.c',
        'analyze-time-data.c',
        'analyze-timespan.c',
        'analyze-timestamp.c',
        'analyze-unit-files.c',
        'analyze-unit-gdb.c',
        'analyze-unit-paths.c',
        'analyze-unit-shell.c',
        'analyze.c',
)


executables += [
        executable_template + {
                'name' : 'systemd-analyze',
                'public' : conf.get('ENABLE_ANALYZE') == 1,
                'sources' : systemd_analyze_sources,
                'link_with' : [
                        libshared,
                ],
                'dependencies' : [
                        libseccomp_cflags,
                ],
                'install' : conf.get('ENABLE_ANALYZE') == 1 ? 'yes' : 'no',
        },
]
