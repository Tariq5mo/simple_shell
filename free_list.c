/**
 * This file implements memory management for the PATH linked list
 * Contains functions for freeing allocated memory and environment handling
 */

#include "main.h"

/**
 * free_list - deallocates memory for PATH linked list
 * Iterates through list freeing both directory strings and nodes
 * Essential for preventing memory leaks when shell exits
 *
 * @head: The head of the linked list
 * Return: void
 */
void free_list(path_l *head)
{
	path_l *ptr1, *ptr2;

	for (ptr1 = head; ptr1; ptr1 = ptr2)
	{
		ptr2 = ptr1->next;
		if (ptr1->dic)
			free(ptr1->dic);
		free(ptr1);
		ptr1 = ptr2;
	}
}

/**
 * where_null - locates end of environment variable array
 * Used for environment variable management
 * Helps maintain proper array termination
 *
 * @env: pointer to array of environment strings
 * Return: index of null terminator
 */
int where_null(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		;
	return (i);
}
