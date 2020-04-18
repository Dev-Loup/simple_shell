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

	if (s1 == NULL || s2 == NULL)
		return (1);

	if (_strlen(s1) != _strlen(s2))
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
	char *copy = NULL;
	int i;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
	{
	}
	copy = malloc((i + 1) * sizeof(char));
	if (copy == NULL)
	{
		free(copy);
		return (NULL);
	}
	for (i = 0; str[i]; i++)
	{
		copy[i] = str[i];
	}
	copy[i] = '\0';
	return (copy);
}

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{}
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
/**
 * _strlen - prints the length of a string
 * @s: the string to measure
 *
 * Return: No returning
 */
int _strlen(char *s)
{
	int counter;

	for (counter = 0; s[counter] != '\0'; counter++)
	{}
	return (counter);

}

int str_cmp_first_chars(char *envs, char *namenv)
{
        int i = 0, j = 0;

        for (i = 0; namenv[i]; i++)
        {
        }
        for (j = 0; namenv[j]; j++)
        {
                if(envs[j] != namenv[j])
                        break;
        }
        if (i == j)
                return(1);
        else
                return (0);
}
/**
 * _strcpy - print a copy string
 * @src: string to copy
 * @dest: string to be written
 *
 * Return: No returning
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

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 */
void print_number(int n)
{
	int i, j, big, small, h = 1, potencia = 1;

	if (n == 0)
	{
		_putchar(48);
	}
	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
	}
	for (i = 0; h != 0; i++)
	{
		h = n / potencia;
		potencia = potencia * 10;
	}
	potencia = potencia / 100;
	for (j = (i - 1); j != 0; j--)
	{
		big = n / potencia;
		small = big % 10;
		potencia = potencia / 10;
		_putchar(small + 48);
	}
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
