#include "main.h"
/**
 * add_nod_end - adding a new node at end
 *
 * @head: The head of a linked list
 * @n: The value in a node
 * Return: The address of new node
 */
path_l *add_node_end(path_l **head, const char *n)
{
	path_l *ptr2, *ptr1;

	if (!head)
		return (NULL);
	for (ptr1 = *head; *head && ptr1->next; ptr1 = ptr1->next)
		;
	ptr2 = malloc(sizeof(path_l));/*create the tail*/
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
 * _getenv_for_build_path - special edition of _getenv for build_path function
 *
 * @name: pointer to string (usually path)
 * Return: the path's value
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
 * build_path - build a singly linked list of path's directories
 *
 * Return: pointer to the list
*/
path_l *build_path(void)
{
	char *s, *p, *pp;
	path_l *head;

	s = _getenv_for_build_path("PATH");/*point to path's value*/
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
