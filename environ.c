#include "shelly.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @nam: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *nam)
{
	list_t *node = info->env;
	char *p1;

	while (node)
	{
		p1 = starts_with(node->str, nam);
		if (p1 && *p1)
			return (p1);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}
/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int ij;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (ij = 1; ij <= info->argc; ij++)
		_unsetenv(info, info->argv[ij]);
	return (0);
}
/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t ij;

	for (ij = 0; environ[ij]; ij++)
		add_node_end(&node, environ[ij], 0);
	info->env = node;
	return (0);
}
