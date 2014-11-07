#
# (C) Copyright 2000-2008
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# SPDX-License-Identifier:	GPL-2.0+
#

obj-$(CONFIG_ASM9260T_EVK)	+= asm9260_devices.o
obj-$(CONFIG_AS92_EFLASH)	+= eflash.o
obj-$(CONFIG_AS92_LED)	+= led.o
obj-y += clock.o
obj-y += cpu.o
obj-y	+= reset.o
obj-y	+= timer.o
obj-y	+= pinctrl.o

ifndef CONFIG_SKIP_LOWLEVEL_INIT
obj-y	+= lowlevel_init.o
endif
