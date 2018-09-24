#include <stdbool.h>
#include <string.h>

bool strcmp(char *str_a, char *str_b)
{
	if (strlen(str_a) != strlen(str_b))
		return false;
	for (unsigned int i = 0; i < strlen(str_a); i++) {
		if (str_a[i] != str_b[i])
			return false;
	}
	return true;
}
