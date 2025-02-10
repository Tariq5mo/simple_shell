/**
 * This file contains the core shell functionality including the main loop
 * and command execution logic for both interactive and non-interactive modes
 */

#include "main.h"

/**
 * main - entry point for the shell program
 * Initializes shell environment and chooses appropriate execution mode
 * Handles both interactive (terminal) and non-interactive (pipe/file) modes
 *
 * @argc: argument count
 * @argv: argument vector
 * @env: environment variables array
 * Return: 0 on Success, -1 on failure
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
 * none_interactive - handles shell execution in non-interactive mode
 * Used when input comes from a pipe or file rather than terminal
 * Processes commands until EOF without displaying prompts
 *
 * @argv: program arguments
 * @j: environment null pointer index
 * @st: file status struct
 * @path: linked list of PATH directories
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
			free_list(path);
			free(com);
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
 * interactive - handles shell execution in interactive mode
 * Displays prompt, reads user input, and executes commands
 * Provides command-line interface when shell runs in terminal
 *
 * @argv: program arguments
 * @j: environment null pointer index
 * @st: file status struct
 * @path: linked list of PATH directories
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
		write(1, "($) ", 5);
		c_s = getline(&com, &com_size, stdin);
		if (c_s == -1)
		{
			free_list(path);
			free(com);
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
 * execute - creates child process and executes command
 * Forks process and uses execve to run commands
 * Parent process waits for child completion
 *
 * @as: array of command and arguments
 * @w: pointer to store wait status
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
 * does_it_Builtin - checks if command is a builtin and executes if so
 * Handles built-in commands: exit, env, setenv, unsetenv, cd
 * Returns success/failure to indicate if command was handled
 *
 * @av: program arguments
 * @as: command arguments
 * @i: process ID
 * @path: PATH linked list
 * @j: environment null pointer index
 * Return: 0 if builtin executed, -1 if not a builtin
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
