
#ifndef COMMAND_H_
#define COMMAND_H_ 1


typedef struct {
	int id;
	int (*fnc)(int, char**);
	char *call;
	char *name;
} command_t;

int command(char *str, char **av);

void bush_add_command(command_t *cmd);

#endif
