#include "shelly.h"

/**
 * Ra_atoi - converts a string to an integer
 * @s1: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int Ra_atoi(char *s1)
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
 * put_myerror - prints an error message
 * @info: the parameter & return info struct
 * @est: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void put_myerror(info_t *info, char *est)
{
	_theputs(info->fname);
	_theputs(": ");
	place_d(info->line_count, STDERR_FILENO);
	_theputs(": ");
	_theputs(info->argv[0]);
	_theputs(": ");
	_theputs(est);
}
/**
 * place_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int place_d(int input1, int fd1)
{
	int (*__putchar)(char) = _putchar;
	int i1, count1 = 0;
	unsigned int _abs1, current1;

	if (fd1 == STDERR_FILENO)
		__putchar = theputstr;
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
 * vert_num - converter function, a clone of itoa
 * @nu: number
 * @bas: base
 * @flag: argument flags
 *
 * Return: string
 */
char *vert_num(long int nu, int bas, int flag)
{
	static char *array1;
	static char buffer1[50];
	char sign1 = 0;
	char *ptr1;
	unsigned long n1 = nu;

	if (!(flag & convert_unsigned) && nu < 0)
	{
		n1 = -nu;
		sign1 = '-';
	}
	array1 = flag & con_lower ? "0123456789abcdef" : "0123456789ABCDEF";
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
 * move_del - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void move_del(char *buf)
{
	int ij;

	for (ij = 0; buf[ij] != '\0'; ij++)
		if (buf[ij] == '#' && (!ij || buf[ij - 1] == ' '))
		{
			buf[ij] = '\0';
			break;
		}
}
