#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>

void dbg_putc (const char c)
{
	u32 waittime;
	waittime = 0; 	
	while ( ((readl(HW_UART4_STAT)) & 0x02000000) != 0 )
	{			
		waittime++;
		if(waittime > 0x1000000)
			break;
	}
	writeb(c,HW_UART4_DATA);
	
	if(c == '\n')
		dbg_putc('\r');
}

void dbg_puts (const char *s)
{
	while (*s) {
		dbg_putc (*s++);
	}
}

