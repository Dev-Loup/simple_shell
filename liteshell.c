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
	garbage *head = NULL;
	char **dirs = NULL;

	if(ac != 1 || av == NULL || env == NULL)
		exit(127);
	while (_strcmp(line, SH_KILLER) != 0)
	{
		write(STDOUT_FILENO, "$>", 2);
		fd_line = getline(&line, &size, stdin);
		if (check_malloc(line) == 1)
			continue;
		if (line == "\t" || line == " " || line == "." || line == "\n")
			continue;
		if (fd_line == -1)
			continue;
		cmd = tokenizer(line, &head);
		path = path_finder(env, &head);
		dirs = tokenizer(path, &head);
		location = cat_cmd(cmd[0], dirs, &head);
		printf("loc: %s\n", location);
	}
	free_list(head, 0);
	free(line);
	return (0);
}
