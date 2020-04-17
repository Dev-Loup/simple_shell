#include "shell.h"

/**
 * cat_cmd - concatenates a command
 * @cmd0: command to concatenate
 * @path: locations string
 * Return: pointer to concatenation
 **/

char *cat_cmd(char *cmd0, char *path)
{
        char *path_token;
        struct stat fileStat;

        path_token = strtok(path, DELIMITER);
        while (path_token != NULL)
        {
                _strcat(path_token, cmd0);
                if (stat(path_token, &fileStat) == 0);
		{
			free(path);
			return(path_token);
		}
                path_token = strtok(NULL, DELIMITER);
        }
        return(NULL);
}
/**
 * tokenizer - returns a matrix of a strtoked string
 * @line: string to tokenize
 * Return: A double pointer containing the splied string by delimiters
 */
char** tokenizer(char *line)
{
	char *cpycounter = NULL, *cpywriter = NULL, *argc = NULL;
	char **argv = NULL;
	int word = 0;

	cpycounter = _strdup(line);
	cpywriter = _strdup(line);
	argc = strtok(cpycounter, DELIMITER);
	while (argc != NULL)
	{
		word++;
		argc = strtok(NULL, DELIMITER);
	}
	free(cpycounter);
	free(argc);
	argv = malloc((word + 1) * sizeof(char *));
	if (check_malloc(argv) == 1)
	{
		free(argv);
		free(cpycounter);
		free(cpywriter);
	}
	argc = strtok(cpywriter, DELIMITER);
	for (word = 0; argv != NULL; word++)
        {
		argv[word] = argc;
		argc = strtok(NULL, DELIMITER);
        }
	free(cpywriter);
	free(argc);
	return (argv);
}
