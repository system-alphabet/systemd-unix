# SPDX-License-Identifier: LGPL-2.1-or-later

zshcompletiondir = get_option('zshcompletiondir')
if zshcompletiondir == 'no'
        subdir_done()
elif zshcompletiondir == ''
        zshcompletiondir = datadir / 'zsh/site-functions'
endif

custom_target(
        input : '_systemctl.in',
        output : '_systemctl',
        command : [jinja2_cmdline, '@INPUT@', '@OUTPUT@'],
        install : true,
        install_dir : zshcompletiondir)

foreach item : [
        ['_busctl',                   ''],
        ['_coredumpctl',              'ENABLE_COREDUMP'],
        ['_journalctl',               ''],
        ['_kernel-install',           'ENABLE_KERNEL_INSTALL'],
        ['_oomctl',                   'ENABLE_OOMD'],
        ['_run0',                     ''],
        ['_sd_bus_address',           ''],
        ['_sd_outputmodes',           ''],
        ['_sd_unit_files',            ''],
        ['_storagectl',               ''],
        ['_systemd',                  ''],
        ['_systemd-analyze',          ''],
        ['_systemd-cryptenroll',      'HAVE_LIBCRYPTSETUP'],
        ['_systemd-delta',            ''],
        ['_systemd-hwdb',             'ENABLE_HWDB'],
        ['_systemd-id128',            ''],

        ['_systemd-nspawn',           ''],
        ['_systemd-path',             ''],
        ['_systemd-run',              ''],
        ['_systemd-sysinstall',       'ENABLE_SYSINSTALL'],
        ['_systemd-tmpfiles',         'ENABLE_TMPFILES'],
        ['_userdbctl',                ''],
        ['_varlinkctl',               ''],
]

        if item[1] == '' or conf.get(item[1]) == 1
                install_data(item[0],
                             install_dir : zshcompletiondir)
        endif
endforeach
