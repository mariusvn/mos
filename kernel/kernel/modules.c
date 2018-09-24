#include <modules/modules.h>
#include <modules/modules_fnc.h>
#include <stdio.h>

#define MODULE_LIST_LENGTH 2

int (*MODULES_LIST[MODULE_LIST_LENGTH])(char **) = {
	/* MODULES HERE */
	add_echo_cmd,
	add_shutdown_cmd
};

int module_caller(char **env)
{
	int ret = 0;
	for (int i = 0; i < MODULE_LIST_LENGTH; i++)
	{
		if (MODULES_LIST[i](env) != 0)
			ret = 1;
	}
	return (ret);
}
