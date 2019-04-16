#ifndef _SHELL_H
#define _SHELL_H
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
extern char **environ;
void sighandler(int);
/**
 * struct list_dir - structure
 *
 *@str: string that has the path
 *
 *@next: pointer to the next structure
 *
 */
typedef struct list_dir
{
        char *str;
        struct list_dir *next;
} l_dir;
int prompt(l_dir *head, int len);
char *concat_path(char *str, l_dir *head);
char **tok(char *ptobuf, l_dir *head);
char **quotes(char **execline, char *quotesdel);
int hijo_path(char **execline, l_dir *head, char *ptobuf);
char *_getenv(void);
l_dir *get_path(char *find);
l_dir *linking_path(l_dir *head, char *newstr);
int print_env(void);
void handler(int num);
char *str_concat(char *s1, char *s2);
char *_strdup_const(const char *str);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int print_env(void);
void free_listint(l_dir *head);
#endif
