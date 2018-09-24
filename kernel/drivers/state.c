#include <stddef.h>
#include <stdint.h>

static inline void outb(uint16_t port, uint8_t val){
  		asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

void shutdown()
{
	for (const char *s = "Shutdown"; *s; ++s)
	{
		outb(0x8900, *s);
	}
	outb(0xf4, 0x00);
}
