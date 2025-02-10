/**
 * This file contains functions for string manipulation and memory management
 * used by the shell to handle command parsing and argument management.
 */

#include "main.h"

/**
 * strtoargs - convert a string to array of strings(arguments)
 * Takes a command string and splits it into an array of argument strings
 * First counts words, then allocates memory and copies each word
 *
 * @ptr: pointer to the input command string
 * Return: array of strings (arguments) or NULL if no words found
 */
char **strtoargs(char *ptr)
{
	char **s, *p, *str;
	int i, w;

	str = _strdup(ptr);
	for (i = w = 0; str[i];) /*how many words in ptr*/
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
	{
		free(str);
		return (NULL);
	}
	s = _calloc(w + 1, sizeof(char *));
	if (!s)
		return (NULL);
	p = strtok(str, " \0");
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
 * free_strings - deallocates memory for an array of strings
 * Properly frees both the individual strings and the array itself
 * Important for preventing memory leaks in the shell
 *
 * @grid: The array of strings to free
 */
void free_strings(char **grid)
{
	int i;

	if (!grid)
		return;
	for (i = 0; grid[i]; i++) /*Free the rest of the the grid*/
		free(grid[i]);		  /*Then the array of pointers*/
	free(grid);
}
/**
 * _strdup - creates a duplicate of a string in new memory
 * Allocates new memory and copies string contents
 * Used for safe string duplication throughout the shell
 *
 * @str: The source string to duplicate
 * Return: Pointer to the new string or NULL if allocation fails
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
 * rev_string - reverses characters in a string in-place
 * Used for string manipulation operations
 * Particularly useful for number-to-string conversions
 *
 * @s: The string to reverse
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
 * _calloc - custom implementation of calloc
 * Allocates memory for an array and initializes to zero
 * Provides memory allocation with error checking
 *
 * @nmemb: Number of elements to allocate
 * @size: Size of each element
 * Return: Pointer to allocated memory or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int j;
	unsigned char *s;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc((nmemb)*size);
	if (ptr == 0)
		return (NULL);
	s = ptr;
	for (j = 0; j < nmemb * size; j++)
		s[j] = 0;
	return (ptr);
}
