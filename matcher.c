#include "shell.h"

char *match_path(char *command, char *pathokeni)
{
	struct dirent *pDirent;
	DIR *pDir;
	char *path;
	char *slash = "/";
	char *directory;

	directory = _strdup(pathokeni);
	pDir = opendir(directory);
	if (pDir == NULL)
	{
		printf ("Cannot open directory %s\n", directory);
		return (NULL);
	}
	while ((pDirent = readdir(pDir)) != NULL)
	{
		if (_strcmp(command, pDirent->d_name) == 0)
		{
			path = pDirent->d_name;
			printf("path: %s\n", path);
			_strcat(directory, slash);
			_strcat(directory, path);
			printf("directory: %s\n", directory);
			closedir (pDir);
			return (directory);
		}
	}
	closedir (pDir);
	free(directory);
	return (NULL);
}
