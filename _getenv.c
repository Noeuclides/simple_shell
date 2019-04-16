#include "header.h"
/**
 *_getenv - function that finds the PATH variable in the env
 *
 *Return: PATH
 **/
char *_getenv(void)
{
	char *aux = NULL;
	int i, j, l = 0;
	char *name = "PATH";
	aux = malloc(sizeof(char) * 128);

	for (i = 0; *(environ + i); i++)
	{
		for (j = 0; *(*(environ + i) + j) != '='; j++)
		{
			if (name[j] != *(*(environ + i) + j))
				break;
			l++;
		}
		if (l == 4)
		{
			free(aux);
			return (_strdup(*(environ + i)));
		}
		l = 0;
	}
	free(aux);
	if (aux == NULL)
		perror("no hay PATH");
	return (aux);
}
/**
 *get_path - function to get the path of directories
 *
 *@find: enviroment variable PATH to search dirs.
 *
 *Return: a pointer to a linked list of the dir's PATH
 **/
l_dir *get_path(char *find)
{
	char *newstr = NULL;
	l_dir *head = NULL; /*temporal node to print the list*/
	char *str = NULL;

	if (!find)
	{
		perror("PATH is empty");
		exit(100);
	}
	str = strtok(find, "=");
	while (str)
	{
		str = strtok(NULL, "=");
		if (str)
		{
			newstr = strtok(str, ":");
			while (newstr)
			{
				head = linking_path(head, newstr); /*send str and add node one by one*/
				newstr = strtok(NULL, ":");
			}
		}
	}
	free(str);
	free(newstr);
	return (head);
}
/**
 *linking_path - function that generates the linked list with the dir's PATH.
 *
 *@head: pointer to the linked list.
 *
 *@newstr: address of diretories.
 *
 *Return: linked list.
 **/
l_dir *linking_path(l_dir *head, char *newstr)
{
	l_dir *l_path = NULL;
	l_dir *aux = NULL;

	l_path = malloc(sizeof(l_dir));
	if (l_path == NULL)
	{
		return (NULL);
	}
	l_path->str = _strdup(newstr);
	if (head == NULL)
	{
		l_path->next = head;
		head = l_path;
	}
	aux = head;
	while (aux->next)
	{
		aux = aux->next;
	}
	aux->next = l_path;
	l_path->next = NULL;
	return (head); /*return de header node*/
}
/**
 *print_env - function that prints a copy of the enviroment variables
 *
 *Return: 0 when succeed.
 **/
int print_env(void)
{
	int x = 0, y, _write;

	while (*(environ + x))
	{
		for (y = 0; *(*(environ + x) + y) != '\0'; y++)
		{}
		_write = write(STDOUT_FILENO, *(environ + x), y);
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}

	if (_write == -1)
		return (0);
	return (0);
}

/**
 *handler - function that handles a signal(crtl + c)
 *
 *@num: signal id.
 **/
void handler(int num)
{
	(void)num;
	write(STDOUT_FILENO, ".|.(-_-).|.", 11);
}
