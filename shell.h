#ifndef _SHELL_H
#define _SHELL_H
#define IP_SIZE 0
#define SH_KILLER "exit\n"
#define DELIMITER "=: \n\t"
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
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;
/**
 * struct garbage - recieves address to free
 * @trash: pointer to malloc
 * @next: points to the next node
 */
typedef struct garbage
{
	void *trash;
	struct garbage *next;
} garbage;
garbage *add_nodeint_end(garbage **head, void *trash);
void print_listint(garbage *h);
void free_list(garbage *head);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int check_malloc(void *alloc);
void free_garbage(char *path, char **cmd, int n);
char **tokenizer(char *line, garbage **head);
int _strlen(char *s);
char *path_finder(char *env[], garbage **head);
int str_cmp_first_chars(char *envs, char *namenv);
char *cat_cmd(char *cmd0, char **dirs, garbage **head);
char *_strcpy(char *dest, char *src);
int is_address(char *cmd0);
int _putchar(char c);
void not_found(char *argv0, char *cmd0, int cmd_counter, garbage **head);
void print_number(int n);
char *return_integer(int n);

#endif
