#include "shelly.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - checks if character is a delimeter
 * @ci: the char to check
 * @delim1: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char ci, char *delim1)
{
	while (*delim1)
		if (*delim1++ == ci)
			return (1);
	return (0);
}
/**
 *_isalpha - checks for alphabetic character
 *@cl: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int cl)
{
	if ((cl >= 'a' && cl <= 'z') || (cl >= 'A' && cl <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 *_atoi - converts a string to an integer
 *@s1: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(char *s1)
{
	int x, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (x = 0;  s1[x] != '\0' && flag != 2; x++)
	{
		if (s1[x] == '-')
			sign *= -1;
		if (s1[x] >= '0' && s1[x] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s1[x] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
