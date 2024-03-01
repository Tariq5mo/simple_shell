#include "main.h"

/**
 * _strlen - lenght
 *
 * @s: a  string
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int j;

	j = 0;
	for (; *(s + j) != '\0'; j++)
		;
	return (j);
}

/**
 * str_concat - connect two strings
 *
 * @s1: 1st string
 * @s2: 2nd string
 * Return: the whole string
*/
char *str_concat(char *s1, char *s2)
{
	int i, j;
	char *s, ss[] = "\0";

	if (s1 == NULL)
		s1 = &ss[0];
	if (s2 == NULL)
		s2 = &ss[0];
	s = _calloc((_strlen(s1) + _strlen(s2) + 10), 1);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < _strlen(s1); i++)
		s[i] = s1[i];
	for (j = 0; s2[j] != '\0'; j++, i++)
		s[i] = s2[j];
	s[i] = '\0';
	return (s);
}
/**
 * find_in_path - search the command in path's directories
 *
 * @args: the arguments of shell
 * @p: the head of path's linked list
 * Return: 0 on success, -1 of failure
*/
int find_in_path(char **args, path_l *p)
{
	char *c, *dic, *com;
	struct stat s;

	if (!args || !*args)
		return (-1);
	c = _strdup(args[0]);
	if (!c)
		return (-1);
	for (; p; free(dic), free(com))
	{
		dic = str_concat(p->dic, "/");
		com = str_concat(dic, c);
		if (stat(com, &s) == 0)
		{
			free(args[0]);
			args[0] = com;
			free(dic);
			free(c);
			return (0);
		}
		p = p->next;
	}
	free(c);
	return (-1);
}
/**
 * not_found - print error of not finding the command
 *
 * @av: arguments of the program
 * @as: arguments of the command
 * @i: the pid of the process
*/
void not_found(char **av, char **as, size_t i)
{
	int j;
	char *e, *c, *pid;

	pid = _calloc(1000, 1);
	for (j = 0; i > 0; i /= 10, j++)
		pid[j] = (i % 10) + '0';
	rev_string(pid);
	e = str_concat(av[0], ": ");
	c = str_concat(e, pid);
	free(e);
	e = str_concat(c, ": ");
	free(c);
	c = str_concat(e, as[0]);
	free(e);
	e = str_concat(c, ": not found\n");
	write(2, e, _strlen(e) + 1);
	free(c);
	free(e);
	free(pid);
}
