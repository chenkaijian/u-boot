/*
 * (C) Copyright 2014
 * Du Huanpeng <u74147@gmail.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>

void dbg_putc(const char ch)
{
	unsigned tmo = 0x1000000;
	unsigned val;

	while (tmo--) {
		val = readl(HW_UART4_STAT);
		if (val & 0x02000000)
			break;
	}

	writeb(ch, HW_UART4_DATA);
}

void dbg_puts(const char *str)
{
	while (*str) {
		dbg_putc(*str);
		str++;
	}
}
