#include <asm/arch/pinctrl.h>
#include <asm/arch/hardware.h>
#include <asm/io.h>
#include <asm/types.h>

void set_gpio_input(u32 port, u32 pin)
{
	writel((1<<((port%4)*8+pin)), HW_GPIO_DATA_BASE+0x8000 + (port/4)*0x10000  + 8);
}

ulong read_gpio_port(u32 port)
{
	printf("222 = %x\n", (ulong)(HW_GPIO_DATA_BASE + (port/4)*0x10000));
	return readl(HW_GPIO_DATA_BASE + (port/4)*0x10000);
}

void set_pin_mux(u32 port, u32 pin, u32 mux_type)
{
	u32 val, addr;

	addr = HW_IOCON_PIO_BASE + (port*32) + (pin*4);
	val = readl(addr);   /*read org val*/

	val &= 0xFFFFFFF8; /* clear mux feild*/
	val |= mux_type;  /*set mux feild with new value*/

	writel(val, addr);   /* Set new value*/
}

void set_pin_dir(u32 port, u32 pin, int bout)
{
	int a = HW_GPIO_DATA_BASE+0x8000 + (port/4)*0x10000  + 8;

	if (bout)
		writel((1<<((port%4)*8+pin)), HW_GPIO_DATA_BASE+0x8000 + (port/4)*0x10000  + 4);
	else
		writel((1<<((port%4)*8+pin)), HW_GPIO_DATA_BASE+0x8000 + (port/4)*0x10000  + 8);
		printf("1<<((port%4)*8+pin) = %x\n", 1<<((port%4)*8+pin));
		printf("HW_GPIO_DATA_BASE = %x\n", a);
}

void set_gpio(u32 port, u32 pin)
{
	/*set GPIO*/
	writel(1<<((port%4)*8+pin), HW_GPIO_DATA_BASE + (port/4)*0x10000+4);
	set_pin_dir(port, pin, 1);    /*output en*/
}

void clear_gpio(u32 port, u32 pin)
{
	/*clear GPIO*/
	writel(1<<((port%4)*8+pin), HW_GPIO_DATA_BASE + (port/4)*0x10000+8);
	set_pin_dir(port, pin, 1); /*output en*/
}

void write_gpio(u32 port, u32 pin, u32 value)
{
	if (value == 0)
		clear_gpio(port, pin);
	else
		set_gpio(port, pin);
}

u32 read_gpio(u32 port, u32 pin)
{
	u32 read_val;

	set_pin_dir(port, pin, 0);
	read_val = read_port(port);
	read_val = ((read_val >> pin)&0x1);

	return read_val;
}

void write_port(u32 nport, u32 nmask, u32 nvalue)
{
	u32 addr = (u32)(HW_GPIO_DATA_BASE + (nport/4)*0x10000);

	writel(addr + 8, (u32)(nmask<<((nport%4)*8)));
	writel(addr + 4, (u32)(nvalue<<((nport%4)*8)));
}

u32 read_port(u32 port)
{
	 return((u32)readl(HW_GPIO_DATA_BASE + (port/4)*0x10000)>>((port%4)*8));
}

void set_pin_pullup(u32 port, u32 pin)
{
	do {
		writel((1<<3), HW_IOCON_PIO0_0+port*0x20+pin*4 + 8);
		writel((1<<4), HW_IOCON_PIO0_0+port*0x20+pin*4 + 4);
	} while (0);
}

/*===============IRQ Functions============================*/
void gpiorq_enable_edge(u32 port, u32 pin, u32 type)
{
	u32 val, addr;

	set_pin_dir(port, pin, 0); /*INPUT*/
	val = (u32)(1 << (pin+(port%4)*8));

	addr = (u32)(HW_GPIO_IS0 + (port/32 * 0x10000));
	writel(addr + 8, val);	/*选择边沿触发*/

	addr = (u32)(HW_GPIO_IEV0 + (port/32 * 0x10000));
	if (type == GPIO_IRQ_EDGE_FALLING)
		writel(addr + 8, val); /*下降沿*/
	else
		writel(addr + 4, val); /*上升沿*/
	addr = (u32)(HW_GPIO_IE0 + (port/32 * 0x10000));
	writel(addr + 4, val);	/*使能为中断源*/
}

void gpioirq_enable_level(u32 port, u32 pin, u32 type)
{
	u32 val, addr;

	set_pin_dir(port, pin, 0); /*INPUT*/
	val = (u32)(1 << (pin+(port%4)*8));

	addr = (u32)(HW_GPIO_IS0 + (port/32 * 0x10000));
	writel(addr + 4, val);	 /*选择电平触发*/

	addr = (u32)(HW_GPIO_IEV0 + (port/32 * 0x10000));
	if (type == GPIO_IRQ_LEVEL_LOW)
		writel(addr + 8, val); /*低电平*/
	else
		writel(addr + 4, val); /*高电平*/
	addr = (u32)(HW_GPIO_IE0 + (port/32 * 0x10000));
	writel(addr + 4, val);	/*使能为中断源*/
}

void gpioirq_disable(u32 port, u32 pin)
{
	u32 val, addr;

	val = (u32)(1 << (pin+(port%4)*8));
	addr = (u32)(HW_GPIO_IE0 + (port/32 * 0x10000));
	writel(addr + 8, val);	/*关闭中断源*/
}

void gpioirq_enable(u32 port, u32 pin)
{
	u32 val, addr;

	val = (u32)(1 << (pin+(port%4)*8));
	addr = (u32)(HW_GPIO_IE0 + (port/32*0x10000));
	writel(addr + 4, val);	/*打开中断源*/
}

void gpioirq_clear(u32 port, u32 pin)
{
	u32 val, addr;

	val = (u32)(1 << (pin+(port%4)*8));
	addr = (u32)(HW_GPIO_IC0 + (port/32*0x10000));
	writel(addr + 4, val);	/*清中断源*/
}

int is_gpioirq_pending(u32 port, u32 pin)
{
	u32 addr, val;

	addr = (u32)(HW_GPIO_IRS0 + (port/32*0x10000));
	val = readl(addr); /*Read status*/
	if ((val & (u32)(1 << (pin + (port%4)*8))) != 0)
		return 0;
	else
		return -1;
}
