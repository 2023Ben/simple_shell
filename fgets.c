#include <stdio.h>
#include "main.h"

/**
 * my_fgets - A progam that does get request
 * @str: String argument
 * @size: size
 * @stream: file arguments
 *
 * Return: Always a string
 */

char *my_fgets(char *str, int size, FILE *stream)
{
int n, i = 0;
char c;

if (size <= 0 || str == NULL || stream == NULL)
{
return (NULL);
}

while (i < size - 1)
{
n = read(fileno(stream), &c, 1);

if (n < 0)
{
perror("Read error");
exit(1);
}
else if (n == 0)
{
break;
}

str[i++] = c;

if (c == '\n')
{
break;
}
}

str[i] = '\0';

if (i == 0)
{
return (NULL);
}

return (str);
}
