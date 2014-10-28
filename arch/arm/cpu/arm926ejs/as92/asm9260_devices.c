/*
 * (C) Copyright 2007-2008
 * Stelian Pop <stelian@popies.net>
 * Lead Tech Design <www.leadtechdesign.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/io.h>
#include <asm/arch/gpio.h>

/*
 * if CONFIG_AT91_GPIO_PULLUP ist set, keep pullups on on all
 * peripheral pins. Good to have if hardware is soldered optionally
 * or in case of SPI no slave is selected. Avoid lines to float
 * needlessly. Use a short local PUP define.
 *
 * Due to errata "TXD floats when CTS is inactive" pullups are always
 * on for TXD pins.
 */
#ifdef CONFIG_AS92_GPIO_PULLUP
# define PUP CONFIG_AS92_GPIO_PULLUP
#else
# define PUP 0
#endif

void as92_serial0_hw_init(void)
{
}

void as92_serial1_hw_init(void)
{
}

void as92_serial2_hw_init(void)
{
}

void as92_seriald_hw_init(void)
{
}

#if defined(CONFIG_HAS_DATAFLASH) || defined(CONFIG_ATMEL_SPI)
void as92_spi0_hw_init(unsigned long cs_mask)
{
}

void as92_spi1_hw_init(unsigned long cs_mask)
{
}
#endif

#ifdef CONFIG_MACB
void as92_macb_hw_init(void)
{
}
#endif

#if defined(CONFIG_GENERIC_ATMEL_MCI)
void as92_mci_hw_init(void)
{
	/* Enable mci clock */
}
#endif
