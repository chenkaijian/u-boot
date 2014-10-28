/*
 * Freescale i.MX23/i.MX28 AUART driver
 *
 * Copyright (C) 2013 Andreas Wass <andreas.wass@dalelven.com>
 *
 * Based on the MXC serial driver:
 *
 * (c) 2007 Sascha Hauer <s.hauer@pengutronix.de>
 *
 * Further based on the Linux mxs-auart.c driver:
 *
 * Freescale STMP37XX/STMP38X Application UART drkiver
 * Copyright 2008-2010 Freescale Semiconductor, Inc.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#include <common.h>
#include <asm/io.h>
#include <serial.h>
#include <linux/compiler.h>

DECLARE_GLOBAL_DATA_PTR;

#ifndef CONFIG_AS92_USART_BASE
/* #error "CONFIG_MXS_AUART_BASE must be set to the base UART to use" */
#endif

/**
 * Sets the baud rate and settings.
 * The settings are: 8 data bits, no parit and 1 stop bit.
 */
static void as92_serial_setbrg(void)
{

}

static int as92_serial_init(void)
{
	serial_setbrg ();
	return 0;
}

static void as92_serial_putc(const char ch)
{
	u32 waittime;
	waittime = 0;
	while ( ((readl(HW_UART4_STAT)) & 0x02000000) != 0 )
	{
		waittime++;
		if(waittime > 0x1000000)
			break;
	}
	writeb(ch,HW_UART4_DATA);

	if(ch == '\n')
		as92_serial_putc('\r');
	return;

}

static int as92_serial_tstc(void)
{
	return ((readl(HW_UART4_STAT) & 0x01000000) != 0x01000000);
}

static int as92_serial_getc(void)
{
	while ( ((readl(HW_UART4_STAT)) & 0x01000000) !=0 );
	return readb(HW_UART4_DATA);
}

static struct serial_device as92_serial_drv = {
	.name = "as92_serial",
	.start = as92_serial_init,
	.stop = NULL,
	.setbrg = as92_serial_setbrg,
	.putc = as92_serial_putc,
	.puts = default_serial_puts,
	.getc = as92_serial_getc,
	.tstc = as92_serial_tstc,
};

void as92_serial_initialize(void)
{
	serial_register(&as92_serial_drv);
}

__weak struct serial_device *default_serial_console(void)
{
	return &as92_serial_drv;
}
