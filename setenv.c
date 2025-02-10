/**
 * This file implements environment variable management functionality
 * Handles setting, updating, and removing environment variables
 */

#include "main.h"

/**
 * _getenv_for_setenv - finds index of environment variable by name
 * Special version optimized for setenv operations
 * Searches environment array for matching variable name
 *
 * @name: environment variable name to find
 * Return: index of variable in environ array, -1 if not found
 */
int _getenv_for_setenv(const char *name)
{
	int i, j;

	if (!name)
		return (-1);
	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j] == name[j]; j++)
			;
		if (name[j] == '\0' && environ[i][j] == '=')
			return (i);
	}
	return (-1);
}

/**
 * check_equal - validates environment variable name format
 * Ensures name doesn't contain equals sign
 * Required for proper environment variable syntax
 *
 * @name: variable name to check
 * Return: 0 if equals found, -1 if valid (no equals)
 */
int check_equal(const char *name)
{
	for (; *name; name++)
		if (*name == '=')
			return (0);
	return (-1);
}

/**
 * _setenv - adds or modifies environment variable
 * Allocates new memory for variable if needed
 * Updates existing variable if overwrite allowed
 *
 * @name: variable name
 * @value: variable value
 * @overwrite: flag to allow overwriting existing variable
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i, j, k;
	char *s;

	if (!name || _strlen((char *)name) == 0 || check_equal(name) == 0)
		return (-1);
	i = _getenv_for_setenv(name);
	if (i < 0) /*name isn't exist in Environment*/
	{
		for (i = 0; environ[i];)
			i++;
		environ[i++] = _calloc(strlen(name) + strlen(value) + 5, 1);
		environ[i] = NULL;
		for (j = 0, --i; name[j]; j++)
			environ[i][j] = name[j];
		environ[i][j++] = '=';
		for (k = 0; value[k]; j++, k++)
			environ[i][j] = value[k];
		environ[i][j] = '\0';
		return (0);
	}
	else if (i >= 0 && overwrite != 0)
	{
		s = _calloc(strlen(name) + strlen(value) + 5, 1);
		for (j = 0; environ[i][j] != '='; j++)
			s[j] = environ[i][j];
		s[j++] = '=';
		for (k = 0; value[k]; j++, k++)
			s[j] = value[k];
		s[j] = '\0';
		environ[i] = realloc(environ[i], 0);
		environ[i] = s;
		return (0);
	}
	else
		return (0);
}

/**
 * _unsetenv - removes environment variable
 * Deallocates memory and adjusts environ array
 * Maintains environment array integrity
 *
 * @name: name of variable to remove
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	int i;

	if (!name || _strlen((char *)name) == 0 || check_equal(name) == 0)
		return (-1);
	i = _getenv_for_setenv(name);
	if (i >= 0)
	{
		environ[i] = realloc(environ[i], 0);
		for (; environ[i]; i++)
			environ[i] = environ[i + 1];
	}
	return (0);
}
