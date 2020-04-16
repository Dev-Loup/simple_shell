#include "shell.h"

/**
 * com_c - compares a char with many chars at the same tiime
 * @av: char to compare
 * @delimiter: array of chars ot compare
 * Return: 1 if the char is equal to one delimiter, 0 if av is never equal
 */
int com_c(char av)
{
	char *delimiter = DELIMITER;
	int i = 0;

	if (!av)
		return(1);
	for(i = 0; delimiter[i]; i++)
		if (av == delimiter[i])
			return(1);
	return(0);
}

/**
 * _strtok - from a string creates a matrix of strings, splitted by delimiters.
 * @a: string to split
 * Return: string of tokens
 */
char** _strtok(char *a)
{
	int j = 0, i = 0, palabras = 1, k = 0;
	char **arr_palabs;

	if (!a)
		return(NULL);
	for (i = 0; a[i]; i++)
	{
		if((com_c(a[i]) == 1) && (com_c(a[i - 1]) == 0) && a[i + 1])
		{
			palabras++;
		}
	}
	arr_palabs = malloc((palabras) * sizeof(char *));
	if (!arr_palabs)
	{}
	arr_palabs[palabras] = NULL;
	palabras = 0;
	for (i = 0; a[i]; i++)
	{
		if ((com_c(a[i])) == 0)
		{
			j++;
		}
		else if((com_c(a[i]) == 1) && (com_c(a[i - 1]) == 0))
		{
			arr_palabs[palabras] = malloc((j + 1) * sizeof(char));
			if (!arr_palabs[palabras])
				k = 0;
			for(i = i - j; k < j ; i++, k++)
			{
				arr_palabs[palabras][k] = a[i];
			}
			arr_palabs[palabras][j] = '\0';
			palabras++;
			j = 0;
		}
	}
	return(arr_palabs);
}
