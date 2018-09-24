#include <stdio.h>
#include <stdlib.h>
#include <kernel/command.h>

/* header in modules/modules_fnc.h */

int echo(int ac, char **av)
{
	int len = 0;

	for (; av[len]; len++);
	if (len == 1)
		return 0;
	for (int i = 1; av[i]; i++)
	{
		printf(av[i]);
		if (av[i + 1])
			printf(" ");
	}
	printf("\n");
	return 0;
}

int add_echo_cmd(char **env)
{
	command_t *new_cmd = malloc(sizeof(command_t));

	new_cmd->fnc = echo;
	new_cmd->id = 0;
	new_cmd->call = "echo";
	new_cmd->name = "echo v1.0";
	bush_add_command(new_cmd);
	return 0;
}
