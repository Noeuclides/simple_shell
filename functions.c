#include "header.h"

/**
 * str_concat - function for concatenate
 * @s1: string 1
 * @s2: string2
 * Return: New pointer
 */
char *str_concat(char *s1, char *s2)
{
	int a = 0, b = 0, c = 0, d = 0;
	char *x;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	for ( ; s1[a]; a++)
	{}
	for ( ; s2[b]; b++)
	{}
	b++;
	x = malloc(sizeof(char) * a + b);
	if (x == NULL)
		return (NULL);
	for ( ; c < a; c++)
		x[c] = s1[c];
	for ( ; d < b; d++)
	{
		x[c] = s2[d];
		c++;
	}

	return (x);
}

/**
***_strdup_const - create an array of char
*
*@str: string parameter
*
*Return: array of char
*/

char *_strdup_const(const char *str)
{
	char *p;
	unsigned int i, j;

	if (str == '\0')
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
	}

	p = malloc(sizeof(char) * i + 1);

	if (!p)
		return (NULL);

	for (j = 0; j <= i; j++)
	{
		p[j] = str[j];
	}

	return (p);
}

/**
***_strdup - func returns pointer to newstring which is a dup of the string s.
*
*@str: string parameter
*
*Return: array of char
*/

char *_strdup(char *str)
{
	char *p;
	unsigned int i, j;

	if (str == '\0')
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
	}

	p = malloc(sizeof(char) * i + 1);

	if (!p)
		return (NULL);

	for (j = 0; j <= i; j++)
	{
		p[j] = str[j];
	}

	return (p);
}

/**
 * _strcmp - compare an array to another.
 * @s1: array 1
 * @s2: array 2.
 * Return: Always 0.
 */

int _strcmp(char *s1, char *s2)
{
	int len, dif = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (len = 0; (s1[len] || s2[len]) && dif == 0; len++)
	{
		dif = s1[len] - s2[len];
	}

	return (dif);
}
