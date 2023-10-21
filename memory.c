#include "shelly.h"

/**
* bfree1 - frees a pointer and NULLs the address
* @ptr1: address of the pointer to free
*
* Return: 1 if freed, otherwise 0.
*/
int bfree(void **ptr1)
{
return ((ptr1 && *ptr1) ? (free(*ptr1), *ptr1 = NULL, 1) : 0)
;
}

