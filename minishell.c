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
	int n = 1, len = 26;

	find = _getenv("PATH");
	if (isatty(STDIN_FILENO) != 1)
		len = 0;

	signal(SIGINT, handler);

	head = get_path(find);
	free(find);
	n = prompt(head, len);
	return (n);
}
