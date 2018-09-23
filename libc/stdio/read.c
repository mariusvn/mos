#include <stdio.h>
#include <stdlib.h>
#include <drivers/keyboard.h>
#include <kernel/tty.h>

char *read_line(void) {
	char a = getchar();
	char *res = calloc(79);
	unsigned char i = 0;
	while (a != '\n' && i <= 78) {
		printf("%c", a);
		terminal_updatecursorpos();
		if (a != '\b') {
			res[i] = a;
			i++;
		} else {
			i--;
			res[i] = '\0';
		}
		a = getchar();
	};
	terminal_putchar('\n');
	terminal_updatecursorpos();
	res[i] = '\0';
	return res;
}
