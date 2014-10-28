/*
 *
 * Copyright (C) 2014 Du Huanpeng <u74147@gmail.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <config.h>
#include <asm/arch/hardware.h>


.globl lowlevel_init
lowlevel_init:
	mov	pc, lr