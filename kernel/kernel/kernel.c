#include <stdio.h>

#include <kernel/tty.h>
#include <kernel/consts.h>
#include <drivers/keyboard.h>
#include <drivers/cursor.h>
#include <string.h>
#include <kernel/command.h>
#include <modules/modules.h>

void kernel_init(void)
{
	terminal_initialize();
	int init_modules = module_caller(NULL);
	if (init_modules != 0)
		printf("modules initialization has not finished successfully.\n");
}

void kernel_main(void)
{
	kernel_init();
	printf("MOS v%s\nCreated by %s\n", VERSION, AUTHOR);
	while(1) {
		printf(">");
		terminal_updatecursorpos();
		char *a = read_line();
		int ret = command(a, split(a, ' '));
		if (ret == 30)
			printf("Command not found\n");
	}
}
