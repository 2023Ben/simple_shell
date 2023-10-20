#include "main.h"

/**
 * _putchar - print a char
 * @ch: char
 * Return: int
 */


int _putchar(int h)
{
	return (write(1, &h, 1));
}
