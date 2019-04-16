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
	signal(SIGINT, handler);
	find = _getenv();
	if (isatty(STDIN_FILENO) != 1)
		len = 0;
        head = get_path(find);
	free(find);
	n = prompt(head, len);
	return (n);
}
