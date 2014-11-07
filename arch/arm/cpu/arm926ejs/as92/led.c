/*
 * (C) Copyright 2007-2008
 * Stelian Pop <stelian@popies.net>
 * Lead Tech Design <www.leadtechdesign.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/gpio.h>
#include <asm/arch/gpio.h>
#include <asm/arch/pinctrl.h>

/*
inline int gpio_set_mux(unsigned gpio)
{

}

inline int gpio_get_value(unsigned gpio)
{
	
	
        return 0;
}

inline int gpio_set_value(unsigned gpio, int val)
{
        return 0;
}
*/

#ifdef CONFIG_RED_LED
void red_led_on(void)
{
	printf("1111111111111111111111111111111111\n");
	printf("1111111111111111111111111111111111\n");
	printf("1111111111111111111111111111111111\n");
	printf("==============red_led_on==========\n");
	printf("1111111111111111111111111111111111\n");
	printf("1111111111111111111111111111111111\n");
	printf("1111111111111111111111111111111111\n");
	set_pin_mux(0, 0, 0);
	set_gpio_input(0, 0);
	write_gpio(0, 0, 0);
	printf("IOCON_PIO0_099 = %d\n", read_gpio(0, 0));
	printf("read_gpio_port(0) = %x\n", read_gpio_port(0));
	printf("read_gpio_port(1) = %x\n", read_gpio_port(1));
	printf("read_gpio_port(2) = %x\n", read_gpio_port(2));
	printf("read_gpio_port(3) = %x\n", read_gpio_port(3));
	printf("2222222222222222222222222222222222\n");
	printf("2222222222222222222222222222222222\n");
	printf("2222222222222222222222222222222222\n");
	printf("2222222222222222222222222222222222\n");
//	gpio_set_value(CONFIG_RED_LED, 1);
}

void red_led_off(void)
{
//	gpio_set_value(CONFIG_RED_LED, 0);
}
#endif

#ifdef CONFIG_GREEN_LED
void green_led_on(void)
{
//	gpio_set_value(CONFIG_GREEN_LED, 0);
}

void green_led_off(void)
{
//	gpio_set_value(CONFIG_GREEN_LED, 1);
}
#endif

#ifdef CONFIG_YELLOW_LED
void yellow_led_on(void)
{
//	gpio_set_value(CONFIG_YELLOW_LED, 0);
}

void yellow_led_off(void)
{
//	gpio_set_value(CONFIG_YELLOW_LED, 1);
}
#endif
