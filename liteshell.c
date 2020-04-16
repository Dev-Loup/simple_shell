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
char *line = NULL, *path = NULL, *location = NULL;
  char **pathoken = NULL, **line_tk = NULL;
  int ipath = 0, ret_wa = -1, cmdcounter = 0;
  ssize_t line_chk = 0;
  size_t size = IP_sIZE;
  pid_t pid1;

  path = finds_path(env);
  pathoken = _strtok(path);
  while (_strcmp(line, SH_KILLER) != 0)
    {
      location = malloc(256 * sizeof(char));
      write(STDOUT_FILENO, "$ ", 2);
      line_chk = getline(&line, &size, stdin); 
      if (line_chk == -1)
	{
	  free(line);
	  free(location);
	  exit(-1);
	}
      else
	{
	  cmdcounter++;
	  if (line == "." || line == "\n" || line == "\t" || line == " ")
	    continue;
	  line_tk = _strtok(line);
	  ret_wa = is_address(line_tk[0]);
	  if (ret_wa != 0)
	    {
	      location = NULL;
	      for (ipath = 1; pathoken[ipath]; ipath++)
		{
		  location = match_path(line_tk[0], pathoken[ipath]);
		  if (location != NULL)
		    break;
		}
	    }
	  else
	    {
	      location = line_tk[0];
	    }
	  if (location != NULL)
	    {
	      pid1 = fork();
	      if (pid1 == 0)
		{
		  execve(location, line_tk, env);
		}
	      else
		wait(NULL);
	    }
	  else
	    {
	      cmdcounter++;
	      printf("%i", cmdcounter);
	    } 
    }
}
