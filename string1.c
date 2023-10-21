#include "shelly.h"

/**
* _strcpy - copies a string
* @dest1: the destination
* @src1: the source
*
* Return: pointer to destination
*/
char *_strcpy(char *dest1, char *src1)
{
int i1 = 0;

if (dest1 == src1 || src1 == 0)
return (dest1);
while (src1[i1])
{
dest1[i1] = src1[i1];
i1++;
}
dest1[i1] = 0;
return (dest1);
}

/**
* _strdup - duplicates a string
* @str1: the string to duplicate
*
* Return: pointer to the duplicated string
*/
char *_strdup(const char *str1)
{
int length1 = 0;
char *ret1;

if (str1 == NULL)
return (NULL);
while (*str1++)
length1++;
ret1 = malloc(sizeof(char) * (length1 + 1));
if (!ret1)
return (NULL);
for (length1++; length1--;)
ret1[length1] = *--str1;
return (ret1);
}

/**
* _puts - prints an input string
* @str1: the string to be printed
*
* Return: Nothing
*/
void _puts(char *str1)
{
int i1 = 0;

if (!str1)
return;
while (str1[i1] != '\0')
{
_putchar(str1[i1]);
i1++;
}
}

/**
* _putchar - writes the character c to stdout
* @c1: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _putchar(char c1)
{
static int i1;
static char buf1[WRITE_BUF_SIZE];

if (c1 == BUF_FLUSH || i1 >= WRITE_BUF_SIZE)
{
write(1, buf1, i1);
i1 = 0;
}
if (c1 != BUF_FLUSH)
buf1[i1++] = c1;
return (1);
}

