#include "shell.h"
/**
 * is_address - check if argument is a valid address
 * @cmd: possible address
 * Return: 0 on success, -1 if it fails
 **/
int is_address(char *cmd)
{
	int fd;

	fd = open(cmd ,O_RDONLY);
	if (fd == 3)
	{
		close(fd);
		return(0);
	}
	close(fd);
	return (-1);
}
