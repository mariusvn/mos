#include <drivers/state.h>
#include <kernel/command.h>

int shutdown_cmd(int ac, char **av)
{
	shutdown();
}

int add_shutdown_cmd(char **env)
{
	command_t *new_cmd = malloc(sizeof(command_t));

	new_cmd->fnc = shutdown_cmd;
	new_cmd->id = 0;
	new_cmd->call = "shutdown";
	new_cmd->name = "shutdown";
	bush_add_command(new_cmd);
	return 0;
}
