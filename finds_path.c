#include "shell.h"
/**
 * path_finder -  finds where is the path environment variable
 * @env: environment variables
 * @head: the head of the garbage list
 * Return: a simple pointer with the whole path enviroment variable
 */
char *path_finder(char *env[], garbage **head)
{
	int i = 0;
	char *copy;
	char path[] = "PATH";

	for (i = 0; env[i]; ++i)
	{
		if ((str_cmp_first_chars(env[i], path)) == 1)
		break;
	}
	copy = _strdup(env[i]);
	add_nodeint_end(head, copy);
	return (copy);
}
/**
 * is_address - finds if the first command can be simply open as address
 * @cmd0: the first comd token
 * Return: 0 if it works a s address, -1 if it doesn't
 */
int is_address(char *cmd0)
{
	struct stat fileStat;

	if (cmd0 == NULL)
		return (-1);
	if (stat(cmd0, &fileStat) == 0)
	{
		return (0);
	}
	else
		return (-1);
}
