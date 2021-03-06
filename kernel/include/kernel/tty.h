#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>

void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);
void terminal_updatecursorpos();
int *get_cursor_position();

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

#endif
