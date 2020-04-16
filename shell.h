#ifndef _SHELL_H
#define _SHELL_H
#define IP_SIZE 200
#define SH_KILLER "exit\n"
#define DELIMITER "=: \n"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>

char *finds_path(char **env);
int str_cmp_first_chars(char *variable);
char *_strcat(char *dest, char *src);
char* match_path(char *command, char* directory);
char** _strtok(char *av);
int com_c(char av);
int _strcmp(char *s1, char *s2);
int works_as_address(char *argv0, char **argv, char *env[]);
void control_c(int sig);
void sig_handler(int signal);
char *_strdup(char *str);

#endif
