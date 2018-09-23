#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/consts.h>
#include <drivers/keyboard.h>
#include <drivers/cursor.h>

void kernel_main(void) {
	terminal_initialize();
	printf("MOS v%s\nCreated by %s\n", VERSION, AUTHOR);
	terminal_updatecursorpos();
	while (1) {
		char c = getchar();
		printf("%c", c);
		terminal_updatecursorpos();
	}
}
