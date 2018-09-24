
#include <kernel/command.h>
#include <string.h>
#include <stdlib.h>

command_t **cmdlist = NULL;
int lastReturn = 0;

int get_list_length()
{
	int i;

	for (i = 0; cmdlist[i]; i++);
	return i;
}

command_t *get_command(char *str)
{
	int length = get_list_length();

	for (int i = 0; i < length; i++)
		if (strcmp(str, cmdlist[i]->call))
			return cmdlist[i];
	return NULL;
}

int command(char *str, char **av)
{
	int length = 0;
	command_t *cmd;
	int ret;

	for (; av[length]; length++);
	if (length == 0)
		return lastReturn;
	cmd = get_command(av[0]);
	if (!cmd)
	{
		lastReturn = 30;			/* CODE 30: No command found */
		return 30;
	}
	ret = cmd->fnc(length, av);
	lastReturn = ret;
	return ret;
}

void bush_add_command(command_t *cmd)
{
	int length = get_list_length();
	command_t **new_list = malloc(sizeof(command_t) * (length + 1));

	for (int i = 0; i < length; i++)
		new_list[i] = cmdlist[i];
	new_list[length] = cmd;
	cmdlist = new_list;
}
