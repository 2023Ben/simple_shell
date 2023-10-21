#include "main.h"
#include <stdio.h>

/**
 * _strdup - Duplicate A String
 * @str:String
 * Return: Duplicate String Failed Null
 */
char *RTSUP(char *str)
{
	size_t len, i;
	char *str2;

	len = strl(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
}

