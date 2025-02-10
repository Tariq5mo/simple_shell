/**
 * This file implements PATH environment variable processing
 * Handles creation and management of PATH directory linked list
 */

#include "main.h"

/**
 * add_node_end - adds new directory node to PATH list
 * Creates and links new node at the end of list
 * Handles memory allocation and string duplication
 *
 * @head: pointer to head of PATH list
 * @n: directory string to add
 * Return: pointer to new node or NULL on failure
 */
path_l *add_node_end(path_l **head, const char *n)
{
	path_l *ptr2, *ptr1;

	if (!head)
		return (NULL);
	for (ptr1 = *head; *head && ptr1->next; ptr1 = ptr1->next)
		;
	ptr2 = malloc(sizeof(path_l)); /*create the tail*/
	if (!ptr2)
		return (NULL);
	ptr2->dic = _strdup((char *)n);
	ptr2->next = NULL;
	if (!*head)
		*head = ptr2;
	else
		ptr1->next = ptr2;
	return (ptr2);
}

/**
 * _getenv_for_build_path - retrieves PATH environment value
 * Specialized version for PATH processing
 * Searches environment for PATH and returns value portion
 *
 * @name: environment variable name to find
 * Return: pointer to variable value or NULL if not found
 */
char *_getenv_for_build_path(const char *name)
{
	int i, j;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j] == name[j]; j++)
			;
		if (name[j] == '\0' && environ[i][j] == '=')
			return (&(environ[i][j + 1]));
	}
	return (NULL);
}

/**
 * build_path - constructs linked list of PATH directories
 * Tokenizes PATH string and creates nodes for each directory
 * Core functionality for command path resolution
 *
 * Return: pointer to head of PATH list
 */
path_l *build_path(void)
{
	char *s, *p, *pp;
	path_l *head;

	s = _getenv_for_build_path("PATH"); /*point to path's value*/
	p = _strdup(s);
	pp = strtok(p, ":");
	head = NULL;
	while (pp)
	{
		add_node_end(&head, pp);
		pp = strtok(NULL, ":");
	}
	free(p);
	return (head);
}
