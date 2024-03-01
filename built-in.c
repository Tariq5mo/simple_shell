#include "main.h"

/**
 * ex - execute exit command
 *
 * @av: arguments of the program
 * @as: arguments of the command
 * @i: the pid of the process
 * @path: pointer to path
 * @j: the index of null pointer in environment
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
 * is_it_number - check if content of a string is a number
 *
 * @s: the string
 * Return: 0 is a number, -1 otherwise
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
 * error_exit - print error of not finding the command
 *
 * @av: arguments of the program
 * @as: arguments of the command
 * @i: the pid of the process
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
 * _env - execute env command
 *
 * @en: pointer to environment
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
