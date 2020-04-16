#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: destination
 * @s2: source
 * Return: 0 on success, lesser or greater if it fails.
 */
int _strcmp(char *s1, char *s2)
{
	int long_of_dest;

	if (!s1 || !s2)
		return(1);

	for (long_of_dest = 0; s1[long_of_dest] != '\0'; long_of_dest++)
	{
		if (s1[long_of_dest] != s2[long_of_dest])
		{
			return (s1[long_of_dest] - s2[long_of_dest]);
		}
	}
	return (0);
}
/**
 * _strdup - generates a string
 * @str: string to recive
 * Return: a pointer to a newly allocated space in memory
 */
char *_strdup(char *str)
{
	char *copy;
	int i;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
	}
	copy = malloc((i + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
		copy[i] = str[i];
	}
	copy[i] = '\0';
	return (copy);
}

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
