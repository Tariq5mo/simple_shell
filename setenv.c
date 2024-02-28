#include "main.h"

/**
 * _getenv_for_setenv - special version of getenv
 *
 * @name: a string which PATH usually
 * Return: the index of PATH in environment, -1 on failure
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
 * check_equal - check if the name content an equal
 *
 * @name: the name of the variable
 * Return: 0 there is an equal, -1 there isn't an equal
 */
int check_equal(const char *name)
{
	for (; *name; name++)
		if (*name == '=')
			return (0);
	return (-1);
}
/**
 * _setenv - changes or adds an environment variable
 *
 * @name: the variable's name
 * @value: the variable's value
 * @overwrite: determine if overwrite valid or not
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i, j, k;
	char *s;

	if (!name || _strlen((char *)name) == 0 || check_equal(name) == 0)
		return (-1);
	i = _getenv_for_setenv(name);
	if (i < 0)/*name isn't exist in Environment*/
	{
		i = 0;
		while (environ[i])
			i++;
		environ[i++] = malloc(strlen(name) + strlen(value) + 1);
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
		s = malloc(strlen(name) + strlen(value) + 1);
		for (j = 0; environ[i][j] != '='; j++)
			s[j] = environ[i][j];
		s[j++] = '=';
		for (k = 0; value[k]; j++, k++)
			s[j] = value[k];
		s[j] = '\0';
		environ[i] = s;
		return (0);
	}
	else
		return (0);
}
/**
 * _unsetenv - unset an environment variable
 *
 * @name: the name of the variable
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
		free(environ[i]);
		for (; environ[i]; i++)
			environ[i] = environ[i + 1];
	}
	return (0);
}
