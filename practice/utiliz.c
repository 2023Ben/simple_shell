#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

/**
 * _print - prints each evironment variable on newline
 * @env: array of evironment varaible to be printed
 * Return: Nothing
 */

void _print(char **env)
{
	int i = 0;

	while (env[i])
	{
		_printf(env[i]);
		_printf("\n");
		i++;
	}
}


/**
 * arr_len - return the length of string array
 * @s: array whose length is to be calculated
 * Return: Length of a array
 */

int arr_len(char **s)
{
	int len = 0, i = 0;

	while (s[i])
	{
		len++;
		i++;
	}

	return (len);
}

