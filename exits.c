#include "shelly.h"

/**
* _strncpy - copies a string
* @dest1: the destination string to be copied to
* @src2: the source string
* @n1: the amount of characters to be copied
*
* Return: the concatenated string
*/
char *_strncpy(char *dest1, char *src2, int n1)
{
int i, j;
char *s = dest1;

i = 0;
while (src2[i] != '\0' && i < n1 - 1)
{
dest1[i] = src2[i];
i++;
}
if (i < n1)
{
j = i;
while (j < n1)
{
dest1[j] = '\0';
j++;
}
}
return (s);
}

/**
* _strncat - concatenates two strings
* @dest1: the first string
* @src2: the second string
* @n1: the amount of bytes to be maximally used
*
* Return: the concatenated string
*/
char *_strncat(char *dest1, char *src2, int n1)
{
int i, j;
char *s = dest1;

i = 0;
j = 0;
while (dest1[i] != '\0')
i++;
while (src2[j] != '\0' && j < n1)
{
dest1[i] = src2[j];
i++;
j++;
}
if (j < n1)
dest1[i] = '\0';
return (s);
}

/**
* _strchr - locates a character in a string
* @s: the string to be parsed
* @c: the character to look for
*
* Return: (s) a pointer to the memory area s
*/
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');
return (NULL);
}

