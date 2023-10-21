#include "shelly.h"

/**
 * _erratoi - converts a string to an integer
 * @s1: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *s1)
{
	int ij = 0;
	unsigned long int result1 = 0;

	if (*s1 == '+')
		s1++;  /* TODO: why does this make main return 255? */
	for (ij = 0;  s1[ij] != '\0'; ij++)
	{
		if (s1[ij] >= '0' && s1[ij] <= '9')
		{
			result1 *= 10;
			result1 += (s1[ij] - '0');
			if (result1 > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result1);
}
/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @est: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *est)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(est);
}
/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input1, int fd1)
{
	int (*__putchar)(char) = _putchar;
	int i1, count1 = 0;
	unsigned int _abs1, current1;

	if (fd1 == STDERR_FILENO)
		__putchar = _eputchar;
	if (input1 < 0)
	{
		_abs1 = input1;
		__putchar('-');
		count1++;
	}
	else
		_abs1 = input1;
	current1 = _abs1;
	for (i1 = 1000000000; i1 > 1; i1 /= 10)
	{
		if (_abs1 / i1)
		{
			__putchar('0' + current1 / i1);
			count1++;
		}
		current1 %= i1;
	}
	__putchar('0' + current1);
	count1++;
	return (count1);
}
/**
 * convert_number - converter function, a clone of itoa
 * @nu: number
 * @bas: base
 * @flag: argument flags
 *
 * Return: string
 */
char *convert_number(long int nu, int bas, int flag)
{
	static char *array1;
	static char buffer1[50];
	char sign1 = 0;
	char *ptr1;
	unsigned long n1 = nu;

	if (!(flag & CONVERT_UNSIGNED) && nu < 0)
	{
		n1 = -nu;
		sign1 = '-';
	}
	array1 = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr1 = &buffer1[49];
	*ptr1 = '\0';
	do	{
		*--ptr1 = array1[n1 % bas];
		n1 /= bas;
	} while (n1 != 0);
	if (sign1)
		*--ptr1 = sign1;
	return (ptr1);
}
/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int ij;

	for (ij = 0; buf[ij] != '\0'; ij++)
		if (buf[ij] == '#' && (!ij || buf[ij - 1] == ' '))
		{
			buf[ij] = '\0';
			break;
		}
}
