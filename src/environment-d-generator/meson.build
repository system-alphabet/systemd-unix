# SPDX-License-Identifier: LGPL-2.1-or-later

if conf.get('ENABLE_ENVIRONMENT_D') != 1
        subdir_done()
endif

executables += [
        executable_template + {
                'name' : '30-systemd-environment-d-generator',
                'sources' : files('environment-d-generator.c'),
                'install_dir' : userenvgeneratordir,
        },
]

install_emptydir(environmentdir)
# /etc/environment is not managed by us and may not exist, so this symlink is
# deliberately dangling. install_symlink() only supports dangling symlinks since
# meson 1.3 (https://github.com/mesonbuild/meson/pull/12266); before that fall
# back to a plain POSIX "ln -sf", which does not require the target to exist.
if meson.version().version_compare('>=1.3.0')
        install_symlink('99-environment.conf',
                        pointing_to : sysconfdir / 'environment',
                        install_dir : environmentdir)
else
        meson.add_install_script(sh, '-c',
                                 '{0} -sf -- "{1}" "{2}"'.format(ln.full_path(),
                                                                sysconfdir / 'environment',
                                                                environmentdir / '99-environment.conf'))
endif
