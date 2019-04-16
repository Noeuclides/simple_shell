include "header.h"

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
        char *buffer[] = {NULL};
        char **ptobuf = NULL, **execline = NULL, *env = "env";
        size_t size = 0;
        int hijo, sw = 1, line = 0, n = 1;

        ptobuf = buffer;
        while (line != -1 && sw == 1)
        {
                if (write(1, "\x1B[1;35m( ⚆ _ ⚆ ) \x1B[0m", len) == -1)
                        perror("0. write");
                line = getline(ptobuf, &size, stdin);
                if (line == -1)
                {
                        free(*ptobuf);
                        free_listint(head);
                        return (-1);
                }
                execline = tok(*ptobuf);
                execline = quotes(execline, "\'\"");
                if (_strcmp(*execline, env) == 0)
                {

