#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
extern char **environ;
/**
 * struct path_build - structure content a PATH's directory
 * @dic: pointer to the directory
 * @next: points to the next node
 *
 * Description: To make a singly linked list of PATH's directories
 *
 */
typedef struct path_build
{
	char *dic;
	struct path_build *next;
} path_l;
void none_interactive(char **argv, size_t j, struct stat st, path_l *path);
void interactive(char **argv, size_t j, struct stat st, path_l *path);
path_l *add_node_end(path_l **head, const char *n);
char *_getenv_for_build_path(const char *name);
path_l *build_path(void);
int _strlen(char *s);
char *str_concat(char *s1, char *s2);
int find_in_path(char **args, path_l *p);
void str_concat_pro(char **s1, char *s2);
void not_found(char **av, char **as, size_t i);
char **strtoargs(char *ptr);
int does_it_Builtin(char **av, char **as, size_t i, path_l *path, int j);
void execute(char **as, int *w);
char *_strdup(char *str);
void free_strings(char **grid);
void *_calloc(unsigned int nmemb, unsigned int size);
int _atoi(char *s);
void rev_string(char *s);
int _strcmp(char *s1, char *s2);
void ex(char **av, char **as, size_t i, path_l *path, int j);
void error_exit(char **av, char **as, size_t i);
int is_it_number(char *s);
void _env(char **en);
void set_null(char *s);
int _setenv(const char *name, const char *value, int overwrite);
int check_equal(const char *name);
int _getenv_for_setenv(const char *name);
int _unsetenv(const char *name);
void _cd(char **av, char **as, size_t j);
void free_list(path_l *head);
int *f(int n);
int where_null(char **env);
void change_dir(char **as, char *pwd, char *oldpwd, size_t i);
#endif/*endif*/
