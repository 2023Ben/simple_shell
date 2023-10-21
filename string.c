#include "shelly.h"

/**
 * _mystrlength - returns the length of a string
 * @str1: the string whose length to check
 *
 * Return: integer length of string
 */
int _mystrlength(char *str1)
{
	int i1 = 0;

	if (!str1)
		return (0);
	while (*str1++)
		i1++;
	return (i1);
}

/**
 * _mycmp - performs lexicographic comparison of two strings.
 * @str1: the first string
 * @str2: the second string
 *
 * Return: negative if str1 < str2, positive if str1 > str2, zero if str1 == str2
 */
int _mycmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * first_with - checks if needle starts with haystack
 * @haystack1: string to search
 * @needle1: the substring to myfinding
 *
 * Return: address of the next character of haystack or NULL
 */
char *first_with(const char *haystack1, const char *needle1)
{
	while (*needle1)
		if (*needle1++ != *haystack1++)
			return (NULL);
	return ((char *)haystack1);
}

/**
 * _my_cat - concatenates two strings
 * @dest1: the destination buffer
 * @src1: the source buffer
 *
 * Return: pointer to the destination buffer
 */
char *_my_cat(char *dest1, char *src1)
{
	char *ret1 = dest1;

	while (*dest1)
		dest1++;
	while (*src1)
		*dest1++ = *src1++;
	*dest1 = *src1;
	return (ret1);
}

