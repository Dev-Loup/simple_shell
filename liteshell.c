#include "shell.h"

/**
 * main - liteshell command interpreter
 * @ac: argument counter
 * @av: argument vector
 * @env: environment variables
 * Return: 0 on success, 1 if it fails
 **/

int main(int ac, char **av, char **env)
{
	char *line = NULL, *path = NULL, **cmd = NULL, *location = NULL;
	size_t size = IP_SIZE;
	ssize_t fd_line = 0;
	garbage *headcmd = NULL, *headpath = NULL, *headloc = NULL, *headirs = NULL;
	char **dirs = NULL;

	if(ac != 1 || av == NULL || env == NULL)
		exit(127);
	while (_strcmp(line, SH_KILLER) != 0)
	{
		write(STDOUT_FILENO, "$>", 2);
		fd_line = getline(&line, &size, stdin);
		if (check_malloc(line) == 1)
			continue;
		printf("line:%s", line);
		if (fd_line == -1)
			continue;
		cmd = tokenizer(line, &headcmd);
		printf("cmd tokenized\n");
		path = path_finder(env, &headpath);
		printf("path found\n");
		dirs = tokenizer(path, &headirs);
		printf("path tokenized\n");
		location = cat_cmd(cmd[0], dirs, &headloc);
		printf("loc: %s\n", location);
		if (location == "sh")
			continue;
	}
	free_list(headcmd, 0);
	free_list(headpath, 0);
	free_list(headirs, 0);
	free_list(headloc, 0);
	free(line);
	return (0);
}
