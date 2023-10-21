#include "shelly.h"

/**
* _theputs - prints an input string
* @str: the string to be printed
*
* Return: Nothing
*/
void _theputs(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
theputstr(str[i]);
i++;
}
}

/**
* theputstr - writes the character c to stderr
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int theputstr(char c)
{
static int i;
static char buf[W_B_size];

if (c == b_flush || i >= W_B_size)
{
write(2, buf, i);
i = 0;
}
if (c != b_flush)
buf[i++] = c;
return (1);
}

/**
* _myputfd - writes the character c to given fd
* @c: The character to print
* @fd: The filedescriptor to write to
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/
int _myputfd(char c, int fd)
{
static int i;
static char buf[W_B_size];

if (c == b_flush || i >= W_B_size)
{
write(fd, buf, i);
i = 0;
}
if (c != b_flush)
buf[i++] = c;
return (1);
}

/**
* _myplacefd - prints an input string
* @str: the string to be printed
* @fd: the filedescriptor to write to
*
* Return: the number of chars put
*/
int _myplacefd(char *str, int fd)
{
int i = 0;

if (!str)
return (0);
while (*str)
{
i += _myputfd(*str++, fd);
}
return (i);
}

