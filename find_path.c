/**
 * This file handles PATH resolution and command location functionality
 * Contains utilities for string manipulation and command path searching
 */

#include "main.h"

/**
 * _strlen - calculates string length
 * Helper function used throughout shell for string operations
 * Counts characters until null terminator
 *
 * @s: string to measure
 * Return: length of string
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
 * str_concat - concatenates two strings safely
 * Allocates new memory for combined string
 * Handles null inputs by treating them as empty strings
 *
 * @s1: first string
 * @s2: second string
 * Return: newly allocated concatenated string or NULL on failure
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
 * find_in_path - searches PATH directories for command
 * Tries to locate executable in each PATH directory
 * Essential for command resolution without full paths
 *
 * @args: shell command arguments
 * @p: linked list of PATH directories
 * Return: 0 if command found, -1 if not found
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
 * not_found - generates command not found error message
 * Formats error message with program name and process ID
 * Writes formatted error to standard error
 *
 * @av: program arguments
 * @as: shell command arguments
 * @i: process ID
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
