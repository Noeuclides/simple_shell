#include "header.h"

/**
 * free_listint - function that free a list
 *
 *@head: node to free
 *
 * Return: void
 */

void free_listint(l_dir *head)
{
	l_dir *freenode;

	while (head != NULL)
	{
		freenode = head;
		free(head->str);
		head = head->next;
		free(freenode);
	}
}
