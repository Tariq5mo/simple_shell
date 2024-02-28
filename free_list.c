#include "main.h"

/**
 * free_list - Frees a list_t list
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
 * where_null - find the index of null pointer
 *
 * @env: pointer to array of strings
 * Return: the index
 */
int where_null(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		;
	return (i);
}
