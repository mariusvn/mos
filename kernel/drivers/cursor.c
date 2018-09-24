#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <drivers/cursor.h>
#include <kernel/tty.h>

static uint8_t inb(uint16_t port)
{
        uint8_t ret;
        asm volatile ( "inb %1, %0"
                                     : "=a"(ret)
                                     : "Nd"(port) );
        return ret;
}

static inline void outb(uint16_t port, uint8_t val){
  		asm volatile ( "outb %0, %1" : : "a"(val), "Nd"(port) );
}

void enable_cursor_back(uint8_t cursor_start, uint8_t cursor_end)
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);

	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3E0) & 0xE0) | cursor_end);
}

void enable_cursor()
{
	enable_cursor_back(0, 1); //TODO not sure args
}

void disable_cursor()
{
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

void update_cursor(int x, int y)
{
	uint16_t pos = y * VGA_WIDTH + x;

	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}
