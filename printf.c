#include "main.h"

/**
 * _printf - produces output according to a format
 * @s: char pointer
 * Return: int
 */

int _printf(char *s)
{
	int len = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		_putchar(*s);
		len++;
		s++;
	}


	return (len);
}