/* SPDX-License-Identifier: @SPDX@ */
/* Copyright(c) 2007 - 2023 Intel Corporation. */

#ifndef _KCOMPAT_DEFS_H_
#define _KCOMPAT_DEFS_H_

#ifndef LINUX_VERSION_CODE
#include <linux/version.h>
#else
#ifndef KERNEL_VERSION
#define KERNEL_VERSION(a,b,c) (((a) << 16) + ((b) << 8) + (c))
#endif
#endif /* LINUX_VERSION_CODE */

#ifndef UTS_RELEASE
#include <generated/utsrelease.h>
#endif

/*
 * Include the definitions file for HAVE/NEED flags for the standard upstream
 * kernels.
 *
 * Then, based on the distribution we detect, load the distribution specific
 * definitions file that customizes the definitions for the target
 * distribution.
 */
#include "kcompat_std_defs-5.10-ethercat.h"

#ifdef CONFIG_SUSE_KERNEL
#include "kcompat_sles_defs-5.10-ethercat.h"
#elif UBUNTU_VERSION_CODE
#include "kcompat_ubuntu_defs-5.10-ethercat.h"
#elif RHEL_RELEASE_CODE
#include "kcompat_rhel_defs-5.10-ethercat.h"
#endif

#include "kcompat_generated_defs-5.10-ethercat.h"

#endif /* _KCOMPAT_DEFS_H_ */
