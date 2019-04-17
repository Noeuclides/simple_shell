#include "header.h"

/**
 *main - main function of the shell
 *
 *Return: 0 when succeed
 **/

int main(void)
{
	char *find = NULL;
	l_dir *head = NULL;

	signal(SIGINT, handler);

	find = _getenv();
	isatty(STDIN_FILENO);


	head = get_path(find);
	free(find);
	prompt(head);
	return (0);
}
