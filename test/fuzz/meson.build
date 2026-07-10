# SPDX-License-Identifier: LGPL-2.1-or-later

generate_directives_py = files('generate-directives.py')

fuzz_regression_tests = {}

directives = [['fuzz-network-parser', 'directives.network'],
              ['fuzz-netdev-parser', 'directives.netdev'],
              ['fuzz-link-parser', 'directives.link'],
             ]

foreach tuple : directives
        directive = custom_target(
                output: tuple[1],
                command: [generate_directives_py],
                capture: true)

        dict = { 'directives' : [directive] }
        fuzz_regression_tests += { tuple[0] : dict }
endforeach

############################################################

fuzz_testsdir = 'test/fuzz'

if git.found() and fs.is_dir(meson.project_source_root() / '.git')
        out = run_command(env, '-u', 'GIT_WORK_TREE',
                          git, '--git-dir=@0@/.git'.format(meson.project_source_root()),
                          'ls-files', ':/@0@/*/*'.format(fuzz_testsdir),
                          check: true)
else
        out = run_command(sh, '-c', 'cd "@0@"; printf "%s " @1@/*/*'.format(meson.project_source_root(), fuzz_testsdir), check: true)
endif

# Add crafted fuzz inputs we have in the repo
foreach p : out.stdout().split()
        # Remove the last entry which is ''.
        #
        # Also, backslashes get mangled, so skip test. See
        # https://github.com/mesonbuild/meson/issues/1564.
        if p.contains('\\') or not fs.exists(meson.project_source_root() / p)
                continue
        endif
        fuzzer = fs.name(fs.parent(p))
        fuzz_in = fs.name(p)

        dict = fuzz_regression_tests.get(fuzzer, {})
        dict += { 'files' : dict.get('files', []) + files(fuzzer / fuzz_in) }
        fuzz_regression_tests += { fuzzer : dict }
endforeach
