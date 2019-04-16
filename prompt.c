#include "header.h"

/**
 *prompt - function that start the prompt wait for user command and execute it
 *
 *@head: pointer to a linked list with the paths
 *
 *@len: len of the prompt, 0 if isatty is not terminal
 *
 *Return: 0 when succeed.
 **/

int prompt(l_dir *head, int len)
{
	char *ptobuf = NULL, **execline = NULL, *env = "env";
	size_t size = 0;
	int hijo, sw = 1, line = 0, n = 1;

	while (line != -1 && sw == 1)
	{
		if (write(1, "\x1B[1;35m( ⚆ _ ⚆ ) \x1B[0m", len) == -1)
			perror("0. write");
		line = getline(&ptobuf, &size, stdin);
		if (line == -1)
		{
			free(ptobuf);
			free_listint(head);
			return (-1);
		}
		execline = tok(ptobuf, head);
		execline = quotes(execline, "\'\"");
		if (_strcmp(*execline, env) == 0)
		{
			if (print_env() != 0)
				perror("No env");
		}
		hijo = fork();
		if (hijo == -1)
			perror("2. fork");
		else if (hijo == 0)
		{
			n = hijo_path(execline, head, ptobuf);
			sw = 0;
		}
		else
			wait(NULL);
		free(execline);
	}
	return (n);
}


/**
 *concat_path - function that concatenate path and verify if it exist
 *
 *@str: first token of the user
 *
 *@head: pointer to a linked list with the Paths
 *
 *Return: string that the user write or the executable path
 **/
char *concat_path(char *str, l_dir *head)
{
	struct stat buf;
	l_dir *aux;
	char *first, *paths;

	aux = head;
	while (aux != NULL)
	{
		first = str_concat("/", str);
		paths = str_concat(aux->str, first);
		free(first);
		if (stat(paths, &buf) == 0)
			return (paths);
		free(paths);
		aux = aux->next;
	}

	return (str);
}

/**
 *tok - function to eliminate delimiters of the string that the user write
 *
 *@ptobuf: array of pointer with the commands and option the user put in
 *
 *@head: a pointer to the first node of the linked list
 *
 *Return: array of pointer without those chars.
 **/
char **tok(char *ptobuf, l_dir *head)
{
	char *delimiters = " \t\r\n\v\f";/*delimitadores a remover del ptobuf*/
	char *cleanline;/*puntero al path con el comando a ejecutar*/
	char **aline;
	int i = 1, comp;

	aline = malloc(sizeof(char *) * 64);
	if (!aline)
	{
		free(aline);
		return (aline);
	}
	cleanline = strtok(ptobuf, delimiters);
	if (!cleanline)
	{
		/* free(aline); */
		return (aline);
	}
	aline[0] = cleanline;
	while (cleanline != NULL)
	{
		cleanline = strtok(NULL, delimiters);
		aline[i] = cleanline;
		i++;
	}
	comp = _strcmp(aline[0], "exit");
	if (comp == 0)
	{
		free(aline);
		free(ptobuf);
		free_listint(head);
		exit(EXIT_SUCCESS);
	}
	return (aline);
}

/**
 *quotes - function to eliminate quotes of the string that the user write
 *
 *@execline: array of pointer with the commands and option the user put in
 *
 *@quotesdel: characters to eliminate
 *
 *Return: array of pointer without those chars.
 **/
char **quotes(char **execline, char *quotesdel)
{
	int j;

	*execline = strtok(*execline, quotesdel);
	j = 1;
	while (*(execline + j))
	{
		*(execline + j) = strtok(*(execline + j), quotesdel);
		execline[j] = *(execline + j);
		j++;
	}
	return (execline);
}

/**
 *hijo_path - function that executes the command if it exist
 *
 *@execline: address of a pointer to the commands of the user
 *
 *@head: pointer to a linked list with the paths
 *
 *@ptobuf: string to the command's user.
 *
 *Return: 0 when succeed
 **/
int hijo_path(char **execline, l_dir *head, char *ptobuf)
{
	l_dir *aux_list = NULL;
	struct stat buf;
	int rexe = 1;

	aux_list = head; /* do a auxiliar of node head*/
	while (aux_list->next != NULL)
	{
		if (*execline != NULL)
			*execline = concat_path(*execline, aux_list);
		else
		{
			free_listint(head);
			exit(100);
		}
		if (stat(*execline, &buf) == 0)
			break;
		aux_list = aux_list->next;
	}
	rexe = execve(*execline, execline, NULL);
	if (*execline != NULL && rexe == -1)
	{
		perror("2. Executable NOT FOUND");
		exit(100);
	}
	return (0);
}
