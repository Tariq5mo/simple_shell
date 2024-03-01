#include "main.h"

/**
 * strtoargs - convert a string to array of strings(arguments)
 *
 * @ptr: pointer to the string
 * Return: the array of strings
*/
char **strtoargs(char *ptr)
{
	char **s, *p, *str;
	int i, w;

	str = _strdup(ptr);
	for (i = w = 0; str[i];)
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] != ' ' && str[i])
		{
			while (str[i] != ' ' && str[i])
				i++;
			w++;
		}
	}
	if (w == 0)
		return (NULL);
	s = _calloc(w + 1, sizeof(char *));
	if (!s)
		return (NULL);
	p = strtok(str, " ");
	for (i = 0; p; i++)
	{
		s[i] = _strdup(p);
		p = strtok(NULL, " ");
	}
	s[w] = NULL;
	free(str);
	return (s);
}
/**
 * free_strings - free array of strings
 *
 * @grid: The two dimensional array
*/
void free_strings(char **grid)
{
	int i;

	if (!grid)
		return;
	for (i = 0; grid[i]; i++)/*Free the rest of the the grid*/
		free(grid[i]);/*Then the array of pointers*/
	free(grid);
}
/**
 * _strdup - put a string to new memory location
 *
 * @str: The_old_string
 * Return: new_string
 */
char *_strdup(char *str)
{
	int i, j;
	char *s;

	if (str == NULL)
		return (NULL);
	i = _strlen(str);
	s = _calloc(i + 1, 1);
	if (s == NULL)
		return (NULL);
	for (j = 0; j != i; j++)
		s[j] = str[j];
	return (s);
}
/**
 * rev_string - reverse an array
 *
 * @s: is a pointer to first elemnt
 */
void rev_string(char *s)
{
	int i, j;
	char t;
	int len = _strlen(s);

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}
/**
 * _calloc -  allocates memory for an array
 *
 * @nmemb: The elements's number
 * @size: The size of each element
 * Return: void
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int j;
	unsigned char *s;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc((nmemb) * size);
	if (ptr == 0)
		return (NULL);
	s = ptr;
	for (j = 0; j < nmemb * size; j++)
		s[j] = 0;
	return (ptr);
}
