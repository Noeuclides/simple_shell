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
	int len = 26;

	signal(SIGINT, handler);

	find = _getenv();
	if (isatty(STDIN_FILENO) != 1)
		len = 0;

	head = get_path(find);
	free(find);
	prompt(head, len);
	return (0);
}
