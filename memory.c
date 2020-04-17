#include "shell.h"

/**
 * check_malloc - checks if malloc was successful
 * @alloc: pointer to check
 * Return: 0 on success, 1 if it fails
 **/

int check_malloc(void *alloc)
{
	if (alloc == NULL)
		return (1);
	else
		return (0);
}
