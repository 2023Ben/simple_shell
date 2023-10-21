#include "shelly.h"

/**
 * plac_node - adds a node to the start of the list
 * @head1: address of pointer to head node
 * @str1: str field of node
 * @num1: node index used by history
 *
 * Return: size of list
 */
mylist *plac_node(mylist **head1, const char *str1, int num1)
{
	mylist *new_head1;

	if (!head1)
		return (NULL);
	new_head1 = malloc(sizeof(mylist));
	if (!new_head1)
		return (NULL);
	my_memeset((void *)new_head1, 0, sizeof(mylist));
	new_head1->num = num1;
	if (str1)
	{
		new_head1->str = strd_up(str1);
		if (!new_head1->str)
		{
			free(new_head1);
			return (NULL);
		}
	}
	new_head1->next = *head1;
	*head1 = new_head1;
	return (new_head1);
}

/**
 * plac_node_end - adds a node to the end of the list
 * @head1: address of pointer to head node
 * @str1: str field of node
 * @num1: node index used by history
 *
 * Return: size of list
 */
mylist *plac_node_end(mylist **head1, const char *str1, int num1)
{
	mylist *new_node1, *node1;

	if (!head1)
		return (NULL);
	node1 = *head1;
	new_node1 = malloc(sizeof(mylist));
	if (!new_node1)
		return (NULL);
	my_memeset((void *)new_node1, 0, sizeof(mylist));
	new_node1->num = num1;
	if (str1)
	{
		new_node1->str = strd_up(str1);
		if (!new_node1->str)
		{
			free(new_node1);
			return (NULL);
		}
	}
	if (node1)
	{
		while (node1->next)
			node1 = node1->next;
		node1->next = new_node1;
	}
	else
		*head1 = new_node1;
	return (new_node1);
}

/**
 * print_list_str - prints only the str element of a mylist linked list
 * @h1: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const mylist *h1)
{
	size_t i1 = 0;

	while (h1)
	{
		_myplace(h1->str ? h1->str : "(nil)");
		_myplace("\n");
		h1 = h1->next;
		i1++;
	}
	return (i1);
}

/**
 * delete_node_at_index - deletes node at the given index
 * @head1: address of pointer to first node
 * @index1: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(mylist **head1, unsigned int index1)
{
	mylist *node1, *prev_node1;
	unsigned int i1 = 0;

	if (!head1 || !*head1)
		return (0);
	if (!index1)
	{
		node1 = *head1;
		*head1 = (*head1)->next;
		free(node1->str);
		free(node1);
		return (1);
	}
	node1 = *head1;
	while (node1)
	{
		if (i1 == index1)
		{
			prev_node1->next = node1->next;
			free(node1->str);
			free(node1);
			return (1);
		}
		i1++;
		prev_node1 = node1;
		node1 = node1->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr1: address of pointer to head node
 *
 * Return: void
 */
void free_list(mylist **head_ptr1)
{
	mylist *node1, *next_node1, *head1;

	if (!head_ptr1 || !*head_ptr1)
		return;
	head1 = *head_ptr1;
	node1 = head1;
	while (node1)
	{
		next_node1 = node1->next;
		free(node1->str);
		free(node1);
		node1 = next_node1;
	}
	*head_ptr1 = NULL;
}

