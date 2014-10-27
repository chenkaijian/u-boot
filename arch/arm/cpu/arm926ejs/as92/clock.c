/*
 * [origin: Linux kernel linux/arch/arm/mach-at91/clock.c]
 *
 * Copyright (C) 2005 David Brownell
 * Copyright (C) 2005 Ivan Kokshaysky
 * Copyright (C) 2009 Jean-Christophe PLAGNIOL-VILLARD <plagnioj@jcrosoft.com>
 * Copyright (C) 2014 Du Huanpeng <u74147@gmail.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/clk.h>

#if !defined(CONFIG_AT91FAMILY)
//# warning You need to define CONFIG_AT91FAMILY in your board config!
#endif

DECLARE_GLOBAL_DATA_PTR;

static unsigned long as92_css_to_rate(unsigned long css)
{
	return 0;
}

#ifdef CONFIG_USB_ATMEL
static unsigned at91_pll_calc(unsigned main_freq, unsigned out_freq)
{
	return 0;
}
#endif

static u32 at91_pll_rate(u32 freq, u32 reg)
{
	return freq;
}

int at91_clock_init(unsigned long main_clock)
{
#ifndef CONFIG_SYS_AT91_MAIN_CLOCK
#endif

#ifdef CONFIG_USB_ATMEL
#endif

	return 0;
}
