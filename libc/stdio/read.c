#include <stdio.h>
#include <stdlib.h>
#include <drivers/keyboard.h>
#include <kernel/tty.h>

char *read_line(void)
{
	int strlen = 0;
	char *result = calloc(1024); //c'est pas opti ! et c'est pas sécu
	char c = getchar();

	while (c != '\n')
	{
		if ((c == '\b' && strlen > 0) || c != '\b') {
			printf("%c", c);
			result[strlen] = c;
			strlen += (c == '\b') ? -1 : 1;
		}
		terminal_updatecursorpos();
		c = getchar();
	}
	printf("\n");
	result[strlen] = '\0';
	return result;
}
