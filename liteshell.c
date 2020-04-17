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
	pid_t pid = 0;
	int chk_adr = 0;

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
		cmd = tokenizer(line, &head);
		printf("cmd tokenized\n");
		chk_adr = is_address(cmd[0]);
		if (chk_adr != 0)
		{
			path = path_finder(env, &head);
			printf("path found\n");
			dirs = tokenizer(path, &head);
			printf("path tokenized\n");
			location = cat_cmd(cmd[0], dirs, &head);
			printf("loc: %s\n", location);
			if (location == "sh")
				continue;
			if (location == NULL && (_strcmp(DELIMITER, line) == 0))
				continue;
		}
		else
			location = cmd[0];
		if (location != NULL)
		{
			pid = fork();
			if (pid == 0)
			{
				execve(location, cmd, env);
			}
			wait(NULL);
		}
	}
	free_list(head, 0);
	free(line);
	return (0);
}
