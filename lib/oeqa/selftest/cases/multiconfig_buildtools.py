#
# Copyright OpenEmbedded Contributors
#
# SPDX-License-Identifier: MIT
#

import os
import textwrap
from oeqa.selftest.cases.multiconfig import MultiConfig
from oeqa.utils.commands import bitbake, runCmd, get_bb_vars
from oeqa.core.decorator.data import skipIfNotDataVar


class MultilibBuildtoolsExtendedTarball(MultiConfig):
    def _run_multilib_nativesdk_gcc(self, environment_script_path, c_example_src):
        def runCmdEnv(cmd):
            cmd = '/bin/sh -c ". %s > /dev/null && %s"' % (
                environment_script_path, cmd)
            self.logger.debug(cmd)
            result = runCmd(cmd)
            self.logger.debug(f"ret: {result.status}, output {result.output}")
            return result

        runCmdEnv('which gcc')
        self.logger.debug(f"c_example_src {c_example_src}")
        result = runCmdEnv("gcc -m32 %s -o main-32 && ./main-32" % (c_example_src))
        self.assertEqual("Hello world!", result.output, "Compile 32 bit program failed")
        result = runCmdEnv("gcc -m64 %s -o main-64 && ./main-64" % (c_example_src))
        self.assertEqual("Hello world!", result.output, "Compile 64 bit program failed")

    @skipIfNotDataVar('BUILD_ARCH', 'x86_64', 'SDK was built for ix86 hosts')
    def test_multiconfig_64bit_gcc_suport_32bit_multilib(self):
        """
        Build 64bit x86_64 buildtools-extended-tarball with package nativesdk-multiconfig-multlib-toolchain-packager-x86.
        The recipe nativesdk-multiconfig-multlib-toolchain-packager trigger a x86 multiconfig
        build to generate 32bit x86 buildtools-tarball which contains minimal 32bit toolchains
        libraries and include files. The package nativesdk-multiconfig-multlib-toolchain-packager-x86
        extract 32bit x86 buildtools-tarball and installed it to 64bit x86_64 nativesdk sysroot.
        Then use 64bit gcc to compile 32bit and 64bit hello world program
        """

        config = """
BBMULTICONFIG = "x86 x86_64"
# Unify the same SDKPATHNATIVE for two multiconfig, otherwise
# nativesdk relocation will fail
SDKPATHNATIVE = "${SDKPATH}/sysroots/x86_64${SDK_VENDOR}-${SDK_OS}"
DISTRO_FEATURES_NATIVESDK:append = " multiarch"
"""
        self.write_config(config)

        x86config = """
SDKMACHINE = "i686"
TMPDIR = "${TOPDIR}/tmp-mc-x86"
# Only install 32bit toolchains library and include files to buildtools-tarball
TOOLCHAIN_HOST_TASK:pn-buildtools-tarball = "nativesdk-libgcc nativesdk-libgcc-dev nativesdk-glibc nativesdk-glibc-dev nativesdk-sdk-provides-dummy nativesdk-buildtools-perl-dummy"
# Do not add relocate script to buildtools-tarball
SDK_RELOCATE_AFTER_INSTALL:pn-buildtools-tarball = "0"
"""
        self.write_config(x86config, 'x86')

        x86_64config = """
SDKMACHINE = "x86_64"
TMPDIR = "${TOPDIR}/tmp-mc-x86_64"
TOOLCHAIN_HOST_TASK:append:pn-buildtools-extended-tarball = " nativesdk-multiconfig-multlib-toolchain-packager-x86"
# lib64 in 64bit nativesdk sysroot, avoid conflict with 32bit lib
baselib:class-nativesdk= "lib64"
baselib:class-crosssdk= "lib64"
libdir_nativesdk = "${prefix_nativesdk}/lib64"
base_libdir_nativesdk = "/lib64"
"""
        self.write_config(x86_64config, 'x86_64')

        bitbake('mc:x86_64:buildtools-extended-tarball')

        needed_vars = ['TOPDIR', 'DISTRO_VERSION', 'COREBASE', 'SDK_VENDOR']
        bb_vars = get_bb_vars(needed_vars)

        c_example_src = os.path.join(
            bb_vars['COREBASE'],
            'meta-skeleton/recipes-skeleton/hello-single/files/helloworld.c'
        )
        sdk_name = 'x86_64-buildtools-extended-nativesdk-standalone-%s.sh' % bb_vars['DISTRO_VERSION']
        sdk_path = os.path.join(bb_vars['TOPDIR'], 'tmp-mc-x86_64/deploy/sdk', sdk_name)
        self.logger.debug(f"sdk_path {sdk_path}")
        runCmd('sh %s -y -d "%s"' % (sdk_path, './sdk-test'))

        environment_script = 'environment-setup-x86_64%s-linux' % (bb_vars['SDK_VENDOR'])
        environment_script_path = os.path.join('./sdk-test', environment_script)

        self._run_multilib_nativesdk_gcc(environment_script_path, c_example_src)

