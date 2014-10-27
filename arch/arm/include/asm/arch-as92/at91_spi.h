/*
 * [origin: Linux kernel include/asm-arm/arch-at91/at91_spi.h]
 *
 * Copyright (C) 2005 Ivan Kokshaysky
 * Copyright (C) SAN People
 *
 * Serial Peripheral Interface (SPI) registers.
 * Based on AT91RM9200 datasheet revision E.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef AT91_SPI_H
#define AT91_SPI_H


struct at91_spi {
	u32		cr;		/* 0x00 Control Register */
	u32		mr;		/* 0x04 Mode Register */
	u32		rdr;		/* 0x08 Receive Data Register */
	u32		tdr;		/* 0x0C Transmit Data Register */
	u32		sr;		/* 0x10 Status Register */
	u32		ier;		/* 0x14 Interrupt Enable Register */
	u32		idr;		/* 0x18 Interrupt Disable Register */
	u32		imr;		/* 0x1C Interrupt Mask Register */
	u32		reserve1[4];
	u32		csr[4];		/* 0x30 Chip Select Register 0-3 */
	u32		reserve2[48];
	at91_pdc_t	pdc;
};


#endif
