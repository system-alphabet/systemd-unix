# SPDX-License-Identifier: LGPL-2.1-or-later

runlevels = conf.get('ENABLE_COMPAT_SYSV_INTERFACES') == 1

units = [
        { 'file' : 'basic.target' },
        { 'file' : 'blockdev@.target' },
        { 'file' : 'bluetooth.target' },
        { 'file' : 'boot-complete.target' },
        { 'file' : 'breakpoint-pre-basic.service.in' },
        { 'file' : 'breakpoint-pre-mount.service.in' },
        { 'file' : 'breakpoint-pre-switch-root.service.in' },
        { 'file' : 'breakpoint-pre-udev.service.in' },
        { 'file' : 'capsule@.service.in' },
        { 'file' : 'capsule.slice' },
        {
          'file' : 'clonesetup.target',
          'symlinks' : ['sysinit.target.wants/'],
        },
        { 'file' : 'console-getty.service.in' },
        { 'file' : 'container-getty@.service.in' },
        {
          'file' : 'cryptsetup-pre.target',
          'conditions' : ['HAVE_LIBCRYPTSETUP'],
        },
        {
          'file' : 'cryptsetup.target',
          'conditions' : ['HAVE_LIBCRYPTSETUP'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        { 'file' : 'debug-shell.service.in' },
        {
          'file' : 'dev-hugepages.mount',
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'dev-mqueue.mount',
          'symlinks' : ['sysinit.target.wants/'],
        },
        { 'file' : 'emergency.service.in' },
        { 'file' : 'emergency.target' },
        { 'file' : 'exit.target' },
        { 'file' : 'factory-reset.target' },
        { 'file' : 'factory-reset-now.target' },
        { 'file' : 'final.target' },
        { 'file' : 'first-boot-complete.target' },
        { 'file' : 'getty-pre.target' },
        {
          'file' : 'getty.target',
          'symlinks' : ['multi-user.target.wants/'],
        },
        { 'file' : 'getty@.service.in' },
        {
          'file' : 'graphical.target',
          'symlinks' : ['default.target'] + (runlevels ? ['runlevel5.target'] : []),
        },
        { 'file' : 'halt.target' },
        {
          'file' : 'hibernate.target',
          'conditions' : ['ENABLE_HIBERNATE'],
        },
        {
          'file' : 'hybrid-sleep.target',
          'conditions' : ['ENABLE_HIBERNATE'],
        },
        {
          'file' : 'systemd-battery-check.service.in',
          'conditions' : ['ENABLE_INITRD'],
          'symlinks' : ['initrd.target.wants/'],
        },
        {
          'file' : 'systemd-bsod.service.in',
          'conditions' : ['HAVE_QRENCODE', 'ENABLE_INITRD'],
          'symlinks' : ['initrd.target.wants/'],
        },
        {
          'file' : 'initrd-cleanup.service',
          'conditions' : ['ENABLE_INITRD'],
        },
        {
          'file' : 'initrd-fs.target',
          'conditions' : ['ENABLE_INITRD'],
        },
        {
          'file' : 'initrd-parse-etc.service.in',
          'conditions' : ['ENABLE_INITRD'],
        },
        {
          'file' : 'initrd-root-device.target',
          'conditions' : ['ENABLE_INITRD'],
        },
        {
          'file' : 'initrd-root-fs.target',
          'conditions' : ['ENABLE_INITRD'],
        },
        {
          'file' : 'initrd-switch-root.service',
          'conditions' : ['ENABLE_INITRD'],
        },
        {
          'file' : 'initrd-switch-root.target',
          'conditions' : ['ENABLE_INITRD'],
        },
        {
          'file' : 'initrd-udevadm-cleanup-db.service',
          'conditions' : ['ENABLE_INITRD'],
          'install_tag' : 'udev',
        },
        {
          'file' : 'initrd-usr-fs.target',
          'conditions' : ['ENABLE_INITRD'],
        },
        {
          'file' : 'initrd.target',
          'conditions' : ['ENABLE_INITRD'],
        },
        {
          'file' : 'integritysetup-pre.target',
          'conditions' : ['HAVE_LIBCRYPTSETUP'],
        },
        {
          'file' : 'integritysetup.target',
          'conditions' : ['HAVE_LIBCRYPTSETUP'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        { 'file' : 'kexec.target' },
        {
          'file' : 'kmod-static-nodes.service.in',
          'conditions' : ['HAVE_KMOD', 'ENABLE_TMPFILES'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'ldconfig.service',
          'conditions' : ['ENABLE_LDCONFIG'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        { 'file' : 'local-fs-pre.target' },
        { 'file' : 'local-fs.target' },

        { 'file' : 'modprobe@.service' },
        {
          'file' : 'multi-user.target',
          'symlinks' : runlevels ? ['runlevel2.target', 'runlevel3.target', 'runlevel4.target'] : [],
        },
        {
          'file' : 'systemd-mute-console.socket',
          'symlinks' : ['sockets.target.wants/']
        },
        { 'file' : 'systemd-mute-console@.service' },
        {
          'file' : 'system-systemd-mute-console.slice',
          'name' : 'system-systemd\\x2dmute\\x2dconsole.slice',
        },
        { 'file' : 'network-online.target' },
        { 'file' : 'network-pre.target' },
        { 'file' : 'network.target' },
        { 'file' : 'nss-lookup.target' },
        { 'file' : 'nss-user-lookup.target' },
        { 'file' : 'paths.target' },
        {
          'file' : 'poweroff.target',
          'symlinks' : runlevels ? ['runlevel0.target'] : [],
        },
        { 'file' : 'printer.target' },
        {
          'file' : 'proc-sys-fs-binfmt_misc.automount',
          'conditions' : ['ENABLE_BINFMT'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'proc-sys-fs-binfmt_misc.mount',
          'conditions' : ['ENABLE_BINFMT'],
        },
        {
          'file' : 'quotaon@.service.in',
          'conditions' : ['ENABLE_QUOTACHECK'],
        },
        {
          'file' : 'quotaon-root.service.in',
          'conditions' : ['ENABLE_QUOTACHECK'],
        },
        {
          'file' : 'reboot.target',
          'symlinks' : ['ctrl-alt-del.target'] + (runlevels ? ['runlevel6.target'] : []),
        },
        {
          'file' : 'remote-cryptsetup.target',
          'conditions' : ['HAVE_LIBCRYPTSETUP'],
          'symlinks' : ['initrd-root-device.target.wants/'],
        },
        { 'file' : 'remote-fs-pre.target' },
        { 'file' : 'remote-fs.target' },
        {
          'file' : 'remote-integritysetup.target',
          'conditions' : ['HAVE_LIBCRYPTSETUP'],
          'symlinks' : ['initrd-root-device.target.wants/'],
        },
        {
          'file' : 'remote-veritysetup.target',
          'conditions' : ['HAVE_LIBCRYPTSETUP'],
          'symlinks' : ['initrd-root-device.target.wants/'],
        },
        { 'file' : 'rescue.service.in' },
        {
          'file' : 'rescue.target',
          'symlinks' : runlevels ? ['runlevel1.target'] : [],
        },
        { 'file' : 'rpcbind.target' },
        { 'file' : 'serial-getty@.service.in' },
        { 'file' : 'shutdown.target' },
        { 'file' : 'sigpwr.target' },
        { 'file' : 'sleep.target' },
        { 'file' : 'slices.target' },
        { 'file' : 'smartcard.target' },
        { 'file' : 'sockets.target' },
        { 'file' : 'soft-reboot.target' },
        { 'file' : 'sound.target' },
        { 'file' : 'ssh-access.target' },
        {
          'file' : 'suspend-then-hibernate.target',
          'conditions' : ['ENABLE_HIBERNATE'],
        },
        { 'file' : 'suspend.target' },
        { 'file' : 'swap.target' },
        {
          'file' : 'sys-fs-fuse-connections.mount',
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'sys-kernel-config.mount',
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'sys-kernel-debug.mount',
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'sys-kernel-tracing.mount',
          'symlinks' : ['sysinit.target.wants/'],
        },
        { 'file' : 'sysinit.target' },
        { 'file' : 'syslog.socket' },
        { 'file' : 'system-install.target' },
        {
          'file' : 'system-systemd-cryptsetup.slice',
          'name' : 'system-systemd\\x2dcryptsetup.slice',
          'conditions' : ['HAVE_LIBCRYPTSETUP'],
        },
        {
          'file' : 'system-systemd-veritysetup.slice',
          'name' : 'system-systemd\\x2dveritysetup.slice',
          'conditions' : ['HAVE_LIBCRYPTSETUP'],
        },
        { 'file' : 'system-update-cleanup.service' },
        { 'file' : 'system-update-pre.target' },
        { 'file' : 'system-update.target' },
        {
          'file' : 'systemd-ask-password.socket',
          'symlinks' : ['sockets.target.wants/']
        },
        { 'file' : 'systemd-ask-password@.service' },
        {
          'file' : 'systemd-ask-password-console.path',
          'symlinks' : ['sysinit.target.wants/'],
        },
        { 'file' : 'systemd-ask-password-console.service' },
        {
          'file' : 'systemd-ask-password-wall.path',
          'symlinks' : ['multi-user.target.wants/'],
        },
        { 'file' : 'systemd-ask-password-wall.service' },
        {
          'file' : 'systemd-backlight@.service.in',
          'conditions' : ['ENABLE_BACKLIGHT'],
        },
        {
          'file' : 'systemd-binfmt.service.in',
          'conditions' : ['ENABLE_BINFMT'],
          'symlinks' : ['sysinit.target.wants/'],
        },

        {
          'file' : 'systemd-confext.service',
          'conditions' : ['ENABLE_SYSEXT'],
        },
        {
          'file' : 'systemd-confext-initrd.service',
          'conditions' : ['ENABLE_INITRD', 'ENABLE_SYSEXT'],
          'symlinks' : ['initrd.target.wants/'],
        },
        {
          'file' : 'systemd-confext-sysroot.service',
          'conditions' : ['ENABLE_INITRD', 'ENABLE_SYSEXT'],
        },
        {
          'file' : 'systemd-coredump.socket',
          'conditions' : ['ENABLE_COREDUMP'],
          'symlinks' : ['sockets.target.wants/', 'system-update-pre.target.wants/'],
        },
        {
          'file' : 'systemd-coredump@.service.in',
          'conditions' : ['ENABLE_COREDUMP'],
        },
        {
          'file' : 'systemd-coredump-register.service.in',
          'conditions' : ['ENABLE_COREDUMP'],
        },
        {
          'file' : 'systemd-coredumpd.service.in',
          'conditions' : ['ENABLE_COREDUMP'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'systemd-creds.socket',
          'symlinks' : ['sockets.target.wants/'],
        },
        { 'file' : 'systemd-creds@.service' },
        {
          'file' : 'systemd-cryptenroll.socket',
          'conditions' : ['HAVE_LIBCRYPTSETUP'],
          'symlinks' : ['sockets.target.wants/'],
        },
        {
          'file' : 'systemd-cryptenroll@.service',
          'conditions' : ['HAVE_LIBCRYPTSETUP'],
        },
        {
          'file' : 'systemd-cryptenroll-firstboot.service',
          'conditions' : ['HAVE_LIBCRYPTSETUP', 'ENABLE_INITRD'],
          'symlinks' : ['initrd.target.wants/'],
        },
        { 'file' : 'systemd-exit.service' },
        { 'file' : 'systemd-factory-reset@.service.in' },
        {
          'file' : 'systemd-factory-reset.socket',
          'symlinks' : ['sockets.target.wants/'],
        },
        { 'file' : 'systemd-factory-reset-complete.service.in' },
        { 'file' : 'systemd-factory-reset-reboot.service' },
        {
          'file' : 'systemd-factory-reset-request.service.in',
          'symlinks' : ['factory-reset.target.wants/'],
        },
        {
          'file' : 'systemd-firstboot.service',
          'conditions' : ['ENABLE_FIRSTBOOT'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        { 'file' : 'systemd-fsck-root.service.in' },
        { 'file' : 'systemd-fsck@.service.in' },
        { 'file' : 'systemd-growfs-root.service.in' },
        { 'file' : 'systemd-growfs@.service.in' },
        { 'file' : 'systemd-halt.service' },
        {
          'file' : 'systemd-hibernate-clear.service.in',
          'conditions' : ['ENABLE_HIBERNATE', 'ENABLE_EFI'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'systemd-hibernate-resume.service.in',
          'conditions' : ['ENABLE_HIBERNATE'],
        },
        {
          'file' : 'systemd-hibernate.service.in',
          'conditions' : ['ENABLE_HIBERNATE'],
        },


        {
          'file' : 'systemd-hwdb-update.service.in',
          'conditions' : ['ENABLE_HWDB'],
          'symlinks' : ['sysinit.target.wants/'],
          'install_tag' : 'hwdb',
        },
        {
          'file' : 'systemd-hybrid-sleep.service.in',
          'conditions' : ['ENABLE_HIBERNATE'],
        },
        {
          'file' : 'systemd-imdsd@.service.in',
          'conditions' : ['ENABLE_IMDS'],
        },
        {
          'file' : 'systemd-imdsd.socket',
          'conditions' : ['ENABLE_IMDS'],
        },
        {
          'file' : 'systemd-imds-early-network.service.in',
          'conditions' : ['ENABLE_IMDS'],
        },
        {
          'file' : 'systemd-imds-import.service.in',
          'conditions' : ['ENABLE_IMDS'],
        },
        {
          'file' : 'systemd-imds-metrics.socket',
          'conditions' : ['ENABLE_IMDS'],
        },
        {
          'file' : 'systemd-imds-metrics@.service.in',
          'conditions' : ['ENABLE_IMDS'],
        },
        {
          'file' : 'systemd-importd.service.in',
          'conditions' : ['ENABLE_IMPORTD'],
          'symlinks' : ['dbus-org.freedesktop.import1.service'],
        },
        {
          'file' : 'systemd-importd.socket',
          'conditions' : ['ENABLE_IMPORTD'],
          'symlinks' : ['sockets.target.wants/'],
        },
        {
          'file' : 'imports-pre.target',
          'conditions' : ['ENABLE_IMPORTD'],
        },
        {
          'file' : 'imports.target',
          'conditions' : ['ENABLE_IMPORTD'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'systemd-journal-catalog-update.service',
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'systemd-journal-flush.service',
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'systemd-journal-gatewayd.service.in',
          'conditions' : ['HAVE_MICROHTTPD'],
        },
        {
          'file' : 'systemd-journal-gatewayd.socket',
          'conditions' : ['HAVE_MICROHTTPD'],
        },
        {
          'file' : 'systemd-journal-remote.service.in',
          'conditions' : ['HAVE_MICROHTTPD'],
        },
        {
          'file' : 'systemd-journal-remote.socket',
          'conditions' : ['HAVE_MICROHTTPD'],
        },
        {
          'file' : 'systemd-journal-upload.service.in',
          'conditions' : ['HAVE_LIBCURL'],
        },
        { 'file' : 'systemd-journalctl@.service' },
        {
          'file' : 'systemd-journalctl.socket',
          'symlinks' : ['sockets.target.wants/'],
        },
        { 'file' : 'systemd-journalctl-metrics@.service' },
        { 'file' : 'systemd-journalctl-metrics.socket' },

        { 'file' : 'systemd-kexec.service' },


        { 'file' : 'systemd-loop@.service' },
        {
          'file' : 'systemd-machine-id-commit.service',
          'symlinks' : ['sysinit.target.wants/'],
        },


        {
          'file' : 'systemd-modules-load.service.in',
          'conditions' : ['HAVE_KMOD'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        { 'file' : 'systemd-network-generator.service.in' },

        {
          'file' : 'systemd-nspawn@.service.in',
          'conditions' : ['ENABLE_NSPAWN'],
        },
        {
          'file' : 'systemd-vmspawn@.service.in',
          'conditions' : ['ENABLE_VMSPAWN'],
        },
        {
          'file' : 'systemd-oomd.service.in',
          'conditions' : ['ENABLE_OOMD'],
        },
        {
          'file' : 'systemd-oomd.socket',
          'conditions' : ['ENABLE_OOMD'],
        },

        { 'file' : 'systemd-report.socket' },
        { 'file' : 'systemd-report@.service.in' },
        { 'file' : 'systemd-report-basic.socket' },
        { 'file' : 'systemd-report-basic@.service.in' },

        {
          'file' : 'systemd-portabled.service.in',
          'conditions' : ['ENABLE_PORTABLED'],
          'symlinks' : ['dbus-org.freedesktop.portable1.service'],
        },
        { 'file' : 'systemd-poweroff.service' },
        {
          'file' : 'systemd-pstore.service.in',
          'conditions' : ['ENABLE_PSTORE'],
        },
        {
          'file' : 'systemd-quotacheck@.service.in',
          'conditions' : ['ENABLE_QUOTACHECK'],
        },
        {
          'file' : 'systemd-quotacheck-root.service.in',
          'conditions' : ['ENABLE_QUOTACHECK'],
        },
        {
          'file' : 'systemd-random-seed.service.in',
          'conditions' : ['ENABLE_RANDOMSEED'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        { 'file' : 'systemd-reboot.service' },
        { 'file' : 'systemd-remount-fs.service.in' },
        {
          'file' : 'systemd-repart.service',
          'conditions' : ['ENABLE_REPART'],
          'symlinks' : ['sysinit.target.wants/', 'initrd-root-fs.target.wants/'],
        },
        {
          'file' : 'systemd-repart.socket',
          'conditions' : ['ENABLE_REPART'],
          'symlinks' : ['sockets.target.wants/'],
        },
        {
          'file' : 'systemd-repart@.service',
          'conditions' : ['ENABLE_REPART'],
        },
        { 'file' : 'systemd-report-cgroup.socket' },
        { 'file' : 'systemd-report-cgroup@.service.in' },
        { 'file' : 'systemd-report-files.socket' },
        { 'file' : 'systemd-report-files@.service.in' },
        {
          'file' : 'systemd-report-sign-plain.socket',
          'conditions' : ['HAVE_OPENSSL'],
        },
        {
          'file' : 'systemd-report-sign-plain@.service.in',
          'conditions' : ['HAVE_OPENSSL'],
        },
        {
          'file' : 'systemd-report-sign-tpm2.socket',
          'conditions' : ['HAVE_OPENSSL','HAVE_TPM2'],
        },
        {
          'file' : 'systemd-report-sign-tpm2@.service.in',
          'conditions' : ['HAVE_OPENSSL', 'HAVE_TPM2'],
        },
        { 'file' : 'systemd-report-sign-tsm.socket' },
        { 'file' : 'systemd-report-sign-tsm@.service.in' },

        {
          'file' : 'systemd-rfkill.service.in',
          'conditions' : ['ENABLE_RFKILL'],
        },
        {
          'file' : 'systemd-rfkill.socket',
          'conditions' : ['ENABLE_RFKILL'],
        },
        { 'file' : 'systemd-soft-reboot.service' },
        {
          'file' : 'systemd-suspend-then-hibernate.service.in',
          'conditions' : ['ENABLE_HIBERNATE'],
        },
        { 'file' : 'systemd-suspend.service.in' },
        {
          'file' : 'systemd-sysctl.service.in',
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'systemd-sysext.service',
          'conditions' : ['ENABLE_SYSEXT'],
        },
        {
          'file' : 'systemd-sysext-initrd.service',
          'conditions' : ['ENABLE_INITRD', 'ENABLE_SYSEXT'],
          'symlinks' : ['initrd.target.wants/'],
        },
        {
          'file' : 'systemd-sysext-sysroot.service',
          'conditions' : ['ENABLE_INITRD', 'ENABLE_SYSEXT'],
        },
        {
          'file' : 'systemd-sysext.socket',
          'conditions' : ['ENABLE_SYSEXT'],
          'symlinks' : ['sockets.target.wants/'],
        },
        {
          'file' : 'systemd-sysupdate-notify-sysext@.service',
          'conditions' : ['ENABLE_SYSEXT'],
        },
        {
          'file' : 'systemd-sysupdate-notify-sysext.socket',
          'conditions' : ['ENABLE_SYSEXT'],
        },
        {
          'file' : 'systemd-sysext@.service',
          'conditions' : ['ENABLE_SYSEXT'],
        },
        {
          'file' : 'systemd-sysinstall.service',
          'conditions' : ['ENABLE_SYSINSTALL'],
          'symlinks' : ['system-install.target.wants/'],
        },
        {
          'file' : 'systemd-sysinstall.socket',
          'conditions' : ['ENABLE_SYSINSTALL'],
          'symlinks' : ['sockets.target.wants/'],
        },
        {
          'file' : 'systemd-sysinstall@.service',
          'conditions' : ['ENABLE_SYSINSTALL'],
        },
        {
          'file' : 'systemd-sysupdate-auto-enable.service.in',
          'conditions' : ['ENABLE_SYSUPDATE'],
        },
        {
          'file' : 'systemd-sysupdate-reboot.service.in',
          'conditions' : ['ENABLE_SYSUPDATE'],
        },
        {
          'file' : 'systemd-sysupdate-reboot.timer',
          'conditions' : ['ENABLE_SYSUPDATE'],
        },
        {
          'file' : 'systemd-sysupdate-update.service.in',
          'conditions' : ['ENABLE_SYSUPDATE'],
          'symlinks' : ['systemd-sysupdate.service'],  # compatibility after rename
        },
        {
          'file' : 'systemd-sysupdate@.service.in',
          'conditions' : ['ENABLE_SYSUPDATE'],
        },
        {
          'file' : 'systemd-sysupdate.socket',
          'conditions' : ['ENABLE_SYSUPDATE'],
          'symlinks' : ['sockets.target.wants/'],
        },
        {
          'file' : 'systemd-sysupdate-update.timer',
          'conditions' : ['ENABLE_SYSUPDATE'],
          'symlinks' : ['systemd-sysupdate.timer'],  # compatibility after rename
        },
        {
          'file' : 'systemd-sysupdated.service.in',
          'conditions' : ['ENABLE_SYSUPDATED'],
          'symlinks' : ['dbus-org.freedesktop.sysupdate1.service'],
        },
        {
          'file' : 'systemd-sysusers.service',
          'conditions' : ['ENABLE_SYSUSERS'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'systemd-storage-block.socket',
          'symlinks' : ['sockets.target.wants/']
        },
        {
          'file' : 'systemd-storage-block@.service.in',
        },
        {
          'file' : 'systemd-storage-fs.socket',
          'symlinks' : ['sockets.target.wants/']
        },
        {
          'file' : 'systemd-storage-fs@.service.in',
        },
        {
          'file' : 'systemd-storagetm.service.in',
          'conditions' : ['ENABLE_STORAGETM'],
        },
        {
          'file' : 'storage-target-mode.target',
          'conditions' : ['ENABLE_STORAGETM'],
        },



        {
          'file' : 'systemd-tmpfiles-clean.service',
          'conditions' : ['ENABLE_TMPFILES'],
        },
        {
          'file' : 'systemd-tmpfiles-clean.timer',
          'conditions' : ['ENABLE_TMPFILES'],
          'symlinks' : ['timers.target.wants/'],
        },
        {
          'file' : 'systemd-tmpfiles-setup-dev-early.service',
          'conditions' : ['ENABLE_TMPFILES'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'systemd-tmpfiles-setup-dev.service',
          'conditions' : ['ENABLE_TMPFILES'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'systemd-tmpfiles-setup.service',
          'conditions' : ['ENABLE_TMPFILES'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'systemd-udev-load-credentials.service',
          'install_tag' : 'udev',
        },
        {
          'file' : 'systemd-udev-settle.service',
          'install_tag' : 'udev',
        },
        {
          'file' : 'systemd-udev-trigger.service',
          'symlinks' : ['sysinit.target.wants/'],
          'install_tag' : 'udev',
        },
        {
          'file' : 'systemd-update-done.service.in',
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'systemd-update-utmp.service.in',
          'conditions' : ['ENABLE_UTMP'],
          'symlinks' : ['sysinit.target.wants/'],
        },
        {
          'file' : 'systemd-user-sessions.service.in',
          'conditions' : ['HAVE_PAM'],
          'symlinks' : ['multi-user.target.wants/'],
        },
        {
          'file' : 'systemd-userdb-load-credentials.service',
          'conditions' : ['ENABLE_USERDB'],
        },
        {
          'file' : 'systemd-userdbd.service.in',
          'conditions' : ['ENABLE_USERDB'],
        },
        {
          'file' : 'systemd-userdbd.socket',
          'conditions' : ['ENABLE_USERDB'],
        },
        {
          'file' : 'systemd-mountfsd.service.in',
          'conditions' : ['ENABLE_MOUNTFSD'],
        },
        {
          'file' : 'systemd-mountfsd.socket',
          'conditions' : ['ENABLE_MOUNTFSD'],
        },
        {
          'file' : 'systemd-nsresourced.service.in',
          'conditions' : ['ENABLE_NSRESOURCED'],
        },
        {
          'file' : 'systemd-nsresourced.socket.in',
          'conditions' : ['ENABLE_NSRESOURCED'],
        },
        {
          'file' : 'systemd-validatefs@.service.in',
          'conditions' : ['HAVE_BLKID'],
        },
        {
          'file' : 'systemd-vconsole-setup.service.in',
          'conditions' : ['ENABLE_VCONSOLE'],
        },
        {
          'file' : 'systemd-volatile-root.service.in',
          'conditions' : ['ENABLE_INITRD'],
        },
        { 'file' : 'time-set.target' },
        { 'file' : 'time-sync.target' },
        { 'file' : 'timers.target' },
        {
          'file' : 'tmp.mount',
          'symlinks' : ['local-fs.target.wants/'],
        },

        { 'file' : 'umount.target' },
        { 'file' : 'usb-gadget.target' },
        { 'file' : 'user-runtime-dir@.service.in' },
        { 'file' : 'user.slice' },
        { 'file' : 'user@.service.in' },

        {
          'file' : 'veritysetup-pre.target',
          'conditions' : ['HAVE_LIBCRYPTSETUP'],
        },
        {
          'file' : 'veritysetup.target',
          'conditions' : ['HAVE_LIBCRYPTSETUP'],
          'symlinks' : ['sysinit.target.wants/'],
        },
]

# For the udev/hwdb aliases
udev_units = []
hwdb_units = []

# Unit files whose contents are embedded into the manager binary, so that it can
# fall back to a built-in copy when the file is not present on disk. Referenced
# from src/core/meson.build.
embedded_unit_names = [
        'basic.target',
        'exit.target',
        'final.target',
        'graphical.target',
        'halt.target',
        'kexec.target',
        'multi-user.target',
        'poweroff.target',
        'reboot.target',
        'shutdown.target',
        'sigpwr.target',
        'soft-reboot.target',
        'sysinit.target',
        'systemd-exit.service',
        'systemd-halt.service',
        'systemd-kexec.service',
        'systemd-poweroff.service',
        'systemd-reboot.service',
        'systemd-soft-reboot.service',
        'umount.target',
]
embedded_units = []

foreach unit : units
        source = unit.get('file')

        if source.endswith('.in')
                needs_jinja = true
                name = source.substring(0, -3)
                assert(name + '.in' == source)
        else
                needs_jinja = false
                name = source
        endif
        # Unit names that contain characters which are awkward in source file names (e.g. the
        # backslash in \x2d escapes) are stored under a sanitized file name and renamed on install.
        name = unit.get('name', name)
        source = files(source)

        install = true
        foreach cond : unit.get('conditions', [])
                if conf.get(cond) != 1
                        install = false
                        break
                endif
        endforeach

        if needs_jinja
                processed = custom_target(
                        input : source,
                        output : name,
                        command : [jinja2_cmdline, '@INPUT@', '@OUTPUT@'],
                        install : install,
                        install_dir : systemunitdir,
                        install_tag : unit.get('install_tag', ''))
                if unit.get('install_tag', '') == 'udev'
                        udev_units += processed
                elif unit.get('install_tag', '') == 'hwdb'
                        hwdb_units += processed
                endif
        elif install
                install_data(source,
                             rename : name,
                             install_dir : systemunitdir,
                             install_tag : unit.get('install_tag', ''))
        endif

        if name in embedded_unit_names
                # Embed either the processed output or the original file.
                embedded_units += needs_jinja ? processed : source
        endif

        if install
                foreach target : unit.get('symlinks', [])
                        if target.endswith('/')
                                # '/' is only allowed at the end of the target
                                assert(target.replace('/', '') + '/' == target)
                                install_symlink(name,
                                                pointing_to : '..' / name,
                                                install_dir : systemunitdir / target,
                                                install_tag : unit.get('install_tag', ''))
                        else
                                install_symlink(target,
                                                pointing_to : name,
                                                install_dir : systemunitdir,
                                                install_tag : unit.get('install_tag', ''))
                        endif
                endforeach
        endif
endforeach

install_data('user-.slice.d/10-defaults.conf',
             install_dir : systemunitdir + '/user-.slice.d')

install_data('user@.service.d/10-login-barrier.conf',
             install_dir : systemunitdir + '/user@.service.d')
install_data('user@0.service.d/10-login-barrier.conf',
             install_dir : systemunitdir + '/user@0.service.d')

############################################################

if meson.version().version_compare('>=1.3.0')
        install_symlink(
                'org.freedesktop.systemd1.service',
                pointing_to : fs.relative_to(dbussystemservicedir / 'org.freedesktop.systemd1.service',
                                             dbussessionservicedir),
                install_dir : dbussessionservicedir)
else
        install_emptydir(dbussessionservicedir)
        meson.add_install_script(sh, '-c',
                ln_s.format(dbussystemservicedir / 'org.freedesktop.systemd1.service',
                            dbussessionservicedir / 'org.freedesktop.systemd1.service'))
endif

subdir('user')
