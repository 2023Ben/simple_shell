#include "main.h"



/**
 * Alloc - reallocates a memory block using malloc and free
 *
 * @a: void pointer
 * @b: unsigned int
 * @c: unsigned int
 *
 * Return: void pointer
 */

void *Alloc(void *a, unsigned int b, unsigned int c)
{
	unsigned int i;
	char *na = NULL;

	if (b == c)
		return (a);
	if (c == 0 && a != NULL)
	{
		free(a);
		a = NULL;
		return (NULL);
	}
	if (a == NULL)
	{
		na = malloc(c);

		if (na == NULL)
			return (NULL);
		return (na);
	}

	na = malloc(c);
	if (na == NULL)
		return (NULL);

	i = 0;

	while (i < b && i < c)
	{
		na[i] = ((char *)a)[i];
		i++;
	}

	free(a);
	a = NULL;
	return (na);
}

