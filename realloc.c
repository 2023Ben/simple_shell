#include "shelly.h"

/**
**_memset - fills memory with a constant byte
*@s1: the pointer to the memory area
*@b1: the byte to fill *s with
*@n1: the amount of bytes to be filled
*Return: (s) a pointer to the memory area s
*/
char *_memset(char *s1, char b1, unsigned int n1)
{
unsigned int i1;

for (i1 = 0; i1 < n1; i1++)
s1[i1] = b1;
return (s1);
}
/**
* ffree - frees a string of strings
* @pp1: string of strings
*/
void ffree(char **pp1)
{
char **a1 = pp1;

if (!pp1)
return;
while (*pp1)
free(*pp1++);
free(a1);
}
/**
* _realloc - reallocates a block of memory
* @ptr1: pointer to the previous malloc'ated block
* @old_size1: byte size of the previous block
* @new_size1: byte size of the new block
*
* Return: pointer to the old block nameen.
*/
void *_realloc(void *ptr1, unsigned int old_size1, unsigned int new_size1)
{
char *p1;

if (!ptr1)
return (malloc(new_size1));
if (!new_size1)
return (free(ptr1), NULL);
if (new_size1 == old_size1)
return (ptr1);
p1 = malloc(new_size1);
if (!p1)
return (NULL);
old_size1 = old_size1 < new_size1 ? old_size1 : new_size1;
while (old_size1--)
p1[old_size1] = ((char *)ptr1)[old_size1];
free(ptr1);
return (p1);
}

