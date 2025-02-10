/**
 * This file implements directory navigation functionality
 * Handles cd command and directory path management
 */

#include "main.h"

/**
 * _cd - implements cd (change directory) command
 * Supports absolute paths, relative paths, and special arguments
 * Handles cd with no args (home), cd -, and cd ..
 *
 * @av: program arguments for error reporting
 * @as: command arguments (cd command and target)
 * @j: process ID for error messages
 */
void _cd(char **av, char **as, size_t j)
{
	char *s, *c, *old, *oldpwd;
	int i;

	old = _getenv_for_build_path("PWD");
	oldpwd = getcwd(old, _strlen(old) + 1);
	if (!as[1]) /*no argument*/
	{
		change_dir(av, _getenv_for_build_path("HOME"), oldpwd, j);
		return;
	}
	else if (_strcmp(as[1], "..") == 0) /*change to previous dir*/
	{
		s = _strdup(oldpwd);
		for (i = _strlen(s) - 2; s[i] != '/'; i--)
			s[i] = '\0';
		change_dir(av, s, oldpwd, j);
		free(s);
		return;
	}
	else if (_strcmp(as[1], "-") == 0) /*print PWD*/
	{
		write(1, oldpwd, _strlen(oldpwd));
		write(1, "\n", 2);
		return;
	}
	else if (as[1][0] == '/')
	{
		change_dir(av, as[1], oldpwd, j);
		return;
	}
	c = str_concat(oldpwd, "/");
	s = str_concat(c, as[1]);
	change_dir(av, s, oldpwd, j);
	free(s);
	free(c);
}

/**
 * change_dir - performs actual directory change
 * Updates PWD and OLDPWD environment variables
 * Handles error reporting for invalid directories
 *
 * @as: shell command arguments
 * @pwd: new directory path
 * @oldpwd: current directory before change
 * @i: process ID for error messages
 */
void change_dir(char **as, char *pwd, char *oldpwd, size_t i)
{
	char *pid, *arg;
	int j;

	if (chdir(pwd) < 0)
	{
		pid = _calloc(1000, 1);
		for (j = 0; i > 0; i /= 10, j++)
			pid[j] = (i % 10) + '0';
		write(2, as[0], _strlen(as[0]));
		write(2, ": ", 2);
		write(2, pid, _strlen(pid));
		write(2, ": cd: can't cd to ", _strlen(": cd: can't cd to "));
		for (j = _strlen(pwd); pwd[j] != '/'; j--)
			;
		arg = &pwd[j + 1];
		write(2, arg, _strlen(arg));
		write(2, "\n", 2);
		return;
	}
	_setenv("PWD", pwd, 1);
	_setenv("OLDPWD", oldpwd, 1);
}
