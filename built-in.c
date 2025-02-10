/**
 * This file implements built-in shell commands
 * Handles exit, environment variables, and related error handling
 */

#include "main.h"

/**
 * ex - implements exit built-in command
 * Handles clean exit with optional status code
 * Frees all allocated memory before exiting
 *
 * @av: program arguments for error reporting
 * @as: command arguments including exit code
 * @i: process ID for error messages
 * @path: PATH linked list to free
 * @j: environment array terminator index
 */
void ex(char **av, char **as, size_t i, path_l *path, int j)
{
	int n;

	if (!as[1])
	{

		for (; environ[j]; j++)
			free(environ[j]);
		free_list(path);
		free_strings(as);
		exit(0);
	}
	else
	{
		if (is_it_number(as[1]) == -1 || atoi(as[1]) < 0)
		{
			error_exit(av, as, i);
			return;
		}
		for (; environ[j]; j++)
			free(environ[j]);
		n = atoi(as[1]);
		free_list(path);
		free_strings(as);
		exit(n);
	}
}

/**
 * is_it_number - validates string as numeric value
 * Used for exit status validation
 * Ensures proper numeric format for exit codes
 *
 * @s: string to validate
 * Return: 0 if valid number, -1 if invalid
 */
int is_it_number(char *s)
{
	if (!s)
		return (-1);
	for (; *s; s++)
		if (*s < '0' || *s > '9')
			return (-1);
	return (0);
}

/**
 * error_exit - generates exit command error message
 * Formats error for invalid exit arguments
 * Writes formatted message to standard error
 *
 * @av: program arguments
 * @as: exit command arguments
 * @i: process ID for message
 */
void error_exit(char **av, char **as, size_t i)
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
	e = str_concat(c, ": Illegal number: ");
	free(c);
	c = str_concat(e, as[1]);
	free(e);
	e = str_concat(c, "\n");
	write(2, e, _strlen(e));
	free(e);
	free(c);
	free(pid);
}

/**
 * _env - implements env built-in command
 * Displays all environment variables
 * Writes each variable on a new line
 *
 * @en: pointer to environment array
 */
void _env(char **en)
{
	int i;

	for (i = 0; en[i]; i++)
	{
		write(1, en[i], _strlen(en[i]));
		write(1, "\n", 1);
	}
}
