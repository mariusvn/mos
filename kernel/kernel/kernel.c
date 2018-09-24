#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/consts.h>
#include <drivers/keyboard.h>
#include <drivers/cursor.h>
#include <string.h>

void kernel_main(void) {
	terminal_initialize();
	printf("MOS v%s\nCreated by %s\n", VERSION, AUTHOR);
	while(1) {
		printf(">");
		terminal_updatecursorpos();
		char *a = read_line();
		if (strlen(a) != 0) {
			char **res = split(a, ' ');
			printf(".%s.\n", res[1]);
		}
	}
}
