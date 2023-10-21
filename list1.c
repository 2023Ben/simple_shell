#include "shelly.h"

/**
* list_len - determines the length of a linked list
* @h1: pointer to the first node
*
* Return: size of the list
*/
size_t list_len(const mylist *h1)
{
size_t i1 = 0;

while (h1)
{
h1 = h1->next;
i1++;
}
return (i1);
}

/**
* mylisto_strings - returns an array of strings of the list->str
* @head1: pointer to the first node
*
* Return: array of strings
*/
char **mylisto_strings(mylist *head1)
{
mylist *node1 = head1;
size_t i1 = list_len(head1), j1;
char **strs1;
char *str1;

if (!head1 || !i1)
return (NULL);
strs1 = malloc(sizeof(char *) * (i1 + 1));
if (!strs1)
return (NULL);
for (i1 = 0; node1; node1 = node1->next, i1++)
{
str1 = malloc(_mystrlength(node1->str) + 1);
if (!str1)
{
for (j1 = 0; j1 < i1; j1++)
free(strs1[j1]);
free(strs1);
return (NULL);
}
str1 = my_cpy(str1, node1->str);
strs1[i1] = str1;
}
strs1[i1] = NULL;
return (strs1);
}

/**
* print_list - prints all elements of a mylist linked list
* @h1: pointer to the first node
*
* Return: size of the list
*/
size_t print_list(const mylist *h1)
{
size_t i1 = 0;

while (h1)
{
_myplace(vert_num(h1->num, 10, 0));
_putchar(':');
_putchar(' ');
_myplace(h1->str ? h1->str : "(nil)");
_myplace("\n");
h1 = h1->next;
i1++;
}
return (i1);
}

/**
* node_first_with - returns a node whose string starts with a prefix
* @node1: pointer to the list head
* @prefix1: string to match
* @c1: the next character after the prefix to match
*
* Return: matching node or null
*/
mylist *node_first_with(mylist *node1, char *prefix1, char c1)
{
char *p1 = NULL;

while (node1)
{
p1 = first_with(node1->str, prefix1);
if (p1 && ((c1 == -1) || (*p1 == c1)))
return (node1);
node1 = node1->next;
}
return (NULL);
}

/**
* get_node_index - gets the index of a node
* @head1: pointer to the list head
* @node1: pointer to the node
*
* Return: index of the node or -1
*/
ssize_t get_node_index(mylist *head1, mylist *node1)
{
size_t i1 = 0;

while (head1)
{
if (head1 == node1)
return (i1);
head1 = head1->next;
i1++;
}
return (-1);
}

