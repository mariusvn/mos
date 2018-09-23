#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <kernel/tty.h>
#include <drivers/keyboard.h>

unsigned char kbdus[128] =
{
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8',			/* 9 */
  	'9', '0', '-', '=', '\b',								/* Backspace - 14 */
  	'\t',													/* Tab - 15 */
	'a', 'z', 'e', 'r',										/* 19 */
	't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',			/* Enter key */
	0,														/* 29   - Control */
	'q', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',		/* 39 */
	'\'', '`',  'A',										/* Left shift */
	'\\', 'w', 'x', 'c', 'v', 'b', 'n',						/* 49 */
	'm', ',', '.', '/',  'A',								/* Right shift */
	'*',
	0,														/* Alt */
	' ',													/* Space bar */
	'C',													/* Caps lock */
	0,														/* 59 - F1 key ... > */
	0,   0,   0,   0,   0,   0,   0,   0,
	0,														/* < ... F10 */
	0,														/* 69 - Num lock*/
	0,														/* Scroll Lock */
	0,														/* Home key */
	0,														/* Up Arrow */
	0,														/* Page Up */
	'-',
	0,														/* Left Arrow */
	0,
	0,														/* Right Arrow */
	'+',
	0,														/* 79 - End key*/
	0,														/* Down Arrow */
	0,														/* Page Down */
	0,														/* Insert Key */
	0,														/* Delete Key */
	0,   0,   0,
	0,														/* F11 Key */
	0,														/* F12 Key */
	0,														/* All other keys are undefined */
};

static bool is_shift = false;

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

char keyboard_handler()
{
    unsigned char scancode = 0;
	outb(0x60, 0x0);
	while (scancode == 0 || scancode == 250)
    	scancode = inb(0x60);
    if (scancode & 0x80)
    {
        switch (scancode) {
			case KB_LEFT_SHIFT_RELEASED:
			case KB_RIGHT_SHIFT_RELEASED:
				return 'B';
			default: return 0;
		}
    }
    else
    {
        return kbdus[scancode];
    }
}

bool is_coded_char(char c) {
	char *coded_chars = "ABC";
	for (int i = 0; coded_chars[i]; i++) {
		if (coded_chars[i] == c)
			return true;
	}
	return false;
}

char getchar() {
	while (true) {
		char c = keyboard_handler();
		if (c == 0)
			continue;
		if (is_coded_char(c)) {
			if (c == 'A' && !is_shift)
				is_shift = true;
			if (c == 'B' && is_shift)
				is_shift = false;
			if (c == 'C') {
				is_shift = !is_shift;
			}
		} else {
			if (is_shift && c >= 'a' && c <= 'z') {
				c -= 32;
			}
			return c;
		}
	}
}
