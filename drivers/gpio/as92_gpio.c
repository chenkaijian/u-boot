/*
 * Copyright (C) 2014 Du Huanpeng <u74147@gmail.com>
 *
 * Copyright (C) 2013 Bo Shen <voice.shen@atmel.com>
 *
 * Copyright (C) 2009 Jens Scharsig (js_at_ng@scharsoft.de)
 *
 *  Copyright (C) 2005 HP Labs
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <config.h>
#include <common.h>
#include <asm/io.h>
#include <linux/sizes.h>
#include <asm/arch/hardware.h>
#include <asm/arch/gpio.h>

static struct as92_port *as92_pio_get_port(unsigned port)
{
}

int as92_set_pio_pullup(unsigned port, unsigned pin, int use_pullup)
{

	return 0;
}

/*
 * mux the pin to the "GPIO" peripheral role.
 */
int as92_set_pio_periph(unsigned port, unsigned pin, int use_pullup)
{
	return 0;
}

/*
 * mux the pin to the "A" internal peripheral role.
 */
int as92_set_a_periph(unsigned port, unsigned pin, int use_pullup)
{
	return 0;
}


/*
 * mux the pin to the gpio controller (instead of "A" or "B" peripheral), and
 * configure it for an input.
 */
int as92_set_pio_input(unsigned port, u32 pin, int use_pullup)
{
	return 0;
}

/*
 * mux the pin to the gpio controller (instead of "A" or "B" peripheral),
 * and configure it for an output.
 */
int as92_set_pio_output(unsigned port, u32 pin, int value)
{
	return 0;
}

/*
 * enable/disable the glitch filter. mostly used with IRQ handling.
 */
int as92_set_pio_deglitch(unsigned port, unsigned pin, int is_on)
{
	return 0;
}


/*
 * enable/disable the multi-driver. This is only valid for output and
 * allows the output pin to run as an open collector output.
 */
int as92_set_pio_multi_drive(unsigned port, unsigned pin, int is_on)
{
	return 0;
}

/*
 * assuming the pin is muxed as a gpio output, set its value.
 */
int as92_set_pio_value(unsigned port, unsigned pin, int value)
{
	return 0;
}

/*
 * read the pin's value (works even if it's not muxed as a gpio).
 */
int as92_get_pio_value(unsigned port, unsigned pin)
{
	return 0;
}

/* Common GPIO API */

int gpio_request(unsigned gpio, const char *label)
{
	return 0;
}

int gpio_free(unsigned gpio)
{
	return 0;
}

int gpio_direction_input(unsigned gpio)
{
	as92_set_pio_input(as92_gpio_to_port(gpio),
			   as92_gpio_to_pin(gpio), 0);
	return 0;
}

int gpio_direction_output(unsigned gpio, int value)
{
	as92_set_pio_output(as92_gpio_to_port(gpio),
			    as92_gpio_to_pin(gpio), value);
	return 0;
}

int gpio_get_value(unsigned gpio)
{
	return as92_get_pio_value(as92_gpio_to_port(gpio),
				  as92_gpio_to_pin(gpio));
}

int gpio_set_value(unsigned gpio, int value)
{
	as92_set_pio_value(as92_gpio_to_port(gpio),
			   as92_gpio_to_pin(gpio), value);

	return 0;
}
