#include "main.h"

/**
 * main - the core of simple shell
 *
 * @argc: the number of arguments
 * @argv: the arguments of shell
 * @env: pointer to The Environment
 * Return: 0 Success, -1 on failure
 */
int main(int argc, char **argv, char **env)
{
	path_l *path;
	size_t j;
	struct stat st;

	(void)(argc);
	j = where_null(env);
	path = build_path();
	if (isatty(0))
		interactive(argv, j, st, path);
	else
		none_interactive(argv, j, st, path);
	return (0);
}
/**
 * none_interactive - execute the none_interactive mode
 *
 * @argv: the arguments of the program
 * @j: the index of null pointer in environment
 * @st: the stat
 * @path: pointer to the PATH
 */
void none_interactive(char **argv, size_t j, struct stat st, path_l *path)
{
	char **args, *com;
	size_t com_size, i;
	ssize_t c_s;
	int w;

	for (com = NULL, i = 1;; free_strings(args), i++)
	{
		com_size = 0;
		c_s = getline(&com, &com_size, stdin);
		if (c_s == -1)
		{
			exit(0);
		}
		com[c_s - 1] = '\0';
		set_null(com);
		args = strtoargs(com);
		free(com);
		if (!args)
			continue;
		if (stat(args[0], &st) == 0)
			execute(args, &w);
		else if (_strcmp(args[0], "env") != 0 &&
			 find_in_path(args, path) == 0)
			execute(args, &w);
		else if (does_it_Builtin(argv, args, i, path, j) == -1)
			not_found(argv, args, i);
	}
}
/**
 * interactive - execute the interactive mode
 *
 * @argv: the arguments of the program
 * @j: the index of null pointer in environment
 * @st: the stat
 * @path: pointer to the PATH
 */
void interactive(char **argv, size_t j, struct stat st, path_l *path)
{
	char **args, *com;
	size_t com_size, i;
	ssize_t c_s;
	int w;

	for (com = NULL, i = 1;; free_strings(args), i++)
	{
		com_size = 0;
		if (!argv[1])
			write(1, "($) ", 5);
		c_s = getline(&com, &com_size, stdin);
		if (c_s == -1)
		{
			write(1, "\n", 2);
			exit(0);
		}
		com[c_s - 1] = '\0';
		set_null(com);
		args = strtoargs(com);
		free(com);
		if (!args)
			continue;
		if (stat(args[0], &st) == 0)
			execute(args, &w);
		else if (_strcmp(args[0], "env") != 0 &&
			 find_in_path(args, path) == 0)
			execute(args, &w);
		else if (does_it_Builtin(argv, args, i, path, j) == -1)
			not_found(argv, args, i);
	}
}
/**
 * execute - execute the commands
 *
 * @as: the command and it's arguments
 * @w: the argument of wait function
*/
void execute(char **as, int *w)
{
	if (fork() == 0)
	{
		if (execve(as[0], as, environ) == -1)
			perror("execve\n");
	}
	else
		wait(w);
}
/**
 * does_it_Builtin - check & execute if the command is Built-in
 *
 * @av: arguments of the program
 * @as: arguments of the command
 * @i: the pid of the process
 * @path: pointer to path
 * @j: the index of null pointer in environment
 * Return: 0 is Built-in and executed, -1 otherwise
 */
int does_it_Builtin(char **av, char **as, size_t i, path_l *path, int j)
{
	if (_strcmp(as[0], "exit") == 0)
	{
		ex(av, as, i, path, j);
		return (0);
	}
	else if (_strcmp(as[0], "env") == 0)
	{
		_env(environ);
		return (0);
	}
	else if (_strcmp(as[0], "setenv") == 0)
	{
		_setenv(as[1], as[2], 1);
		return (0);
	}
	else if (_strcmp(as[0], "unsetenv") == 0)
	{
		_unsetenv(as[1]);
		return (0);
	}
	else if (_strcmp(as[0], "cd") == 0)
	{
		_cd(av, as, i);
		return (0);
	}
	return (-1);
}
