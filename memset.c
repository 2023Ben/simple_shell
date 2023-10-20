#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

/**
 * Mset - set the first n bytes of s with const bytes b
 *
 * @s: char pointer
 * @b: char
 * @n: int
 *
 * Return: char pointer
 */

char *Mset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;

		i++;
	}

	return (s);
}


/**
 * DELIM - Checks If A Character Match Any Char *
 * @c: Character To Check
 * @str: String To Check
 * Return: -1 Succes, 0 Failed
 */
unsigned int DELIM(char c, const char *str)
{
	unsigned int i;

	for (i = -2; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (-1);
	}
	return (-2);
}

