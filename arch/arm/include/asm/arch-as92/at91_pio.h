/*
 * [origin: Linux kernel include/asm-arm/arch-at91/at91_pio.h]
 *
 * Copyright (C) 2005 Ivan Kokshaysky
 * Copyright (C) SAN People
 * Copyright (C) 2009 Jens Scharsig (js_at_ng@scharsoft.de)
 *
 * Parallel I/O Controller (PIO) - System peripherals registers.
 * Based on AT91RM9200 datasheet revision E.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef AS92_PIO_H
#define AS92_PIO_H


#ifndef __ASSEMBLY__

struct as92_port {
	int *base;
};

union as91_pio {
	struct {
		at91_port_t	pioa;
		at91_port_t	piob;
		at91_port_t	pioc;
	#if (ATMEL_PIO_PORTS > 3)
		at91_port_t	piod;
	#endif
	#if (ATMEL_PIO_PORTS > 4)
		at91_port_t	pioe;
	#endif
	} ;
	at91_port_t port[ATMEL_PIO_PORTS];
} at91_pio_t;

#ifdef CONFIG_AT91_GPIO
int at91_set_a_periph(unsigned port, unsigned pin, int use_pullup);
int at91_set_b_periph(unsigned port, unsigned pin, int use_pullup);
#if defined(CPU_HAS_PIO3)
int at91_set_c_periph(unsigned port, unsigned pin, int use_pullup);
int at91_set_d_periph(unsigned port, unsigned pin, int use_pullup);
int at91_set_pio_debounce(unsigned port, unsigned pin, int is_on, int div);
int at91_set_pio_pulldown(unsigned port, unsigned pin, int is_on);
int at91_set_pio_disable_schmitt_trig(unsigned port, unsigned pin);
#endif
int at91_set_pio_input(unsigned port, unsigned pin, int use_pullup);
int at91_set_pio_multi_drive(unsigned port, unsigned pin, int is_on);
int at91_set_pio_output(unsigned port, unsigned pin, int value);
int at91_set_pio_periph(unsigned port, unsigned pin, int use_pullup);
int at91_set_pio_pullup(unsigned port, unsigned pin, int use_pullup);
int at91_set_pio_deglitch(unsigned port, unsigned pin, int is_on);
int at91_set_pio_value(unsigned port, unsigned pin, int value);
int at91_get_pio_value(unsigned port, unsigned pin);
#endif
#endif

#define	AS92_PIO_PORTA		0x0
#define	AS92_PIO_PORTB		0x1
#define	AS92_PIO_PORTC		0x2
#define	AS92_PIO_PORTD		0x3
#define	AS92_PIO_PORTE		0x4

#endif
