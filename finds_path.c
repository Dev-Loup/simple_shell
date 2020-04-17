#include "shell.h"


char *path_finder(char *env[], garbage **head)
{
	int prim_chars = 0;
	int i = 0;
	char *copy;
	char path[] = "PATH";
	for(i = 0; env[i]; ++i)
	{
		if ((prim_chars = str_cmp_first_chars(env[i], path)) == 1)
		break;
	}
	copy = _strdup(env[i]);
	add_nodeint_end(head, copy);
	return (copy);
}
