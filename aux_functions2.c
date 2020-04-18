#include "shell.h"
/**
 * return_integer - returns integer
 * @n: integer to pass to string
 * Return: string of integers
 */
char *return_integer(int n)
{
	int i, j, count = 0, big, small, h = 1, potencia = 1;
	char *integer;

	if (n == 0)
	{
		integer = malloc(2), integer[count] = 48;
		if (!integer)
		{
			return (integer);
		}
		integer[count + 1] = '\0';
		return (integer);
	}
	if (n < 0)
		count++;
	for (i = 0; h != 0; i++)
		h = n / potencia, potencia = potencia * 10;
	potencia = potencia / 100;
	for (j = (i - 1); j != 0; j--, count++)
		big = n / potencia, small = big % 10, potencia = potencia / 10;
	integer = malloc((count + 1) * sizeof(char));
	if (!integer)
	{
		return (integer);
	}
	count = 0, potencia = 1, h = 1;
	if (n < 0)
		integer[count] = '-', n = n * -1, count++;
	for (i = 0; h != 0; i++)
		h = n / potencia, potencia = potencia * 10;
	potencia = potencia / 100;
	for (j = (i - 1); j != 0; j--, count++)
	{
		big = n / potencia, small = big % 10, potencia = potencia / 10;
		integer[count] = small + 48;
	}
	integer[count] = '\0';
	return (integer);
}
/**
 * _strcpy - print a copy string
 * @src: string to copy
 * @dest: string to be written
 * Return: a string copied
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int n;

	for (n = 0; src[n] != '\0'; n++)
	{}
	for (i = 0; i <= n; i++)
		dest[i] = src[i];
	return (dest);
}
