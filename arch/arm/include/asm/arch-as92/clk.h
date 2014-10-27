/*
 * (C) Copyright 2007
 * Stelian Pop <stelian@popies.net>
 * Lead Tech Design <www.leadtechdesign.com>
 * Copyright (C) 2009 Jean-Christophe PLAGNIOL-VILLARD <plagnioj@jcrosoft.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef __ASM_ARM_ARCH_CLK_H__
#define __ASM_ARM_ARCH_CLK_H__

#include <asm/arch/hardware.h>
#include <asm/global_data.h>

static inline unsigned long get_cpu_clk_rate(void)
{
	return 0;
}

static inline unsigned long get_main_clk_rate(void)
{
	return 0;
}

static inline unsigned long get_mck_clk_rate(void)
{
	return 0;
}

static inline unsigned long get_plla_clk_rate(void)
{
	return 0;
}

static inline unsigned long get_pllb_clk_rate(void)
{
	return 0;
}

static inline u32 get_pllb_init(void)
{
	return 0;
}

static inline unsigned long get_macb_pclk_rate(unsigned int dev_id)
{
	return 0;
}

static inline unsigned long get_usart_clk_rate(unsigned int dev_id)
{
	return 0;
}

static inline unsigned long get_lcdc_clk_rate(unsigned int dev_id)
{
	return 0;
}

static inline unsigned long get_spi_clk_rate(unsigned int dev_id)
{
	return 0;
}

static inline unsigned long get_twi_clk_rate(unsigned int dev_id)
{
	return 0;
}

static inline unsigned long get_mci_clk_rate(void)
{
	return 0;
}

int at91_clock_init(unsigned long main_clock);
void at91_periph_clk_enable(int id);
void at91_periph_clk_disable(int id);
#endif /* __ASM_ARM_ARCH_CLK_H__ */
