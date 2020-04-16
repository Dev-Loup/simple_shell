#include "shell.h"

/**
 * str_cmp_first_chars - look for path variable
 * @variable: environment variable
 * Return: 0 on Success, 1 if it fails
 **/
int str_cmp_first_chars(char *variable)
{
	char path[] = "PATH";
	int i = 4, j = 0;

	for(j = 0; path[j]; j++)
	{
		if(variable[j] != path[j])
			return(1);
	}
	return (0);
}

/**
 * finds_path - finds path env among env variables
 * @env: environment variables
 * Return: path variable
 **/

char *finds_path(char *env[])
{
	int i = 0;

	for(i = 0; env[i]; ++i)
	{
		if ((str_cmp_first_chars(env[i])) == 0)
			break;
	}
	return (env[i]);
}
