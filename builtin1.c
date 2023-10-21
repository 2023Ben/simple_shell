#include "shelly.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p1, c1;
	int ret1;

	p1 = _strchr(str, '=');
	if (!p1)
		return (1);
	c1 = *p1;
	*p1 = 0;
	ret1 = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p1 = c1;
	return (ret1);
}
/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p1;

	p1 = _strchr(str, '=');
	if (!p1)
		return (1);
	if (!*++p1)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p1 = NULL, *a1 = NULL;

	if (node)
	{
		p1 = _strchr(node->str, '=');
		for (a1 = node->str; a1 <= p1; a1++)
			_putchar(*a1);
		_putchar('\'');
		_puts(p1 + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int ij = 0;
	char *p1 = NULL;

	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (ij = 1; info->argv[ij]; ij++)
	{
		p1 = _strchr(info->argv[ij], '=');
		if (p1)
			set_alias(info, info->argv[ij]);
		else
			print_alias(node_starts_with(info->alias, info->argv[ij], '='));
	}
	return (0);
}
