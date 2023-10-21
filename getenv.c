#include "shelly.h"

/**
* get_environ - returns the string array copy of our environ
* @info1: Structure containing potential arguments.
*
* Return: Always 0
*/
char **get_environ(info_t *info1)
{
if (!info1->environ || info1->env_changed)
{
info1->environ = mylisto_strings(info1->env);
info1->env_changed = 0;
}
return (info1->environ);
}

/**
* _unsetenv - Remove an environment variable
* @info1: Structure containing potential arguments.
* @var1: the string env var property
*
* Return: 1 on delete, 0 otherwise
*/
int _unsetenv(info_t *info1, char *var1)
{
mylist *node1 = info1->env;
size_t i1 = 0;
char *p1;

if (!node1 || !var1)
return (0);
while (node1)
{
p1 = first_with(node1->str, var1);
if (p1 && *p1 == '=')
{
info1->env_changed = delete_node_at_index(&(info1->env), i1);
i1 = 0;
node1 = info1->env;
continue;
}
node1 = node1->next;
i1++;
}
return (info1->env_changed);
}

/**
* _setenv - Initialize a new environment variable,
*             or modify an existing one
* @info1: Structure containing potential arguments.
* @var1: the string env var property
* @value1: the string env var value
*
* Return: Always 0
*/
int _setenv(info_t *info1, char *var1, char *value1)
{
char *buf1 = NULL;
mylist *node1;
char *p1;

if (!var1 || !value1)
return (0);
buf1 = malloc(_mystrlength(var1) + _mystrlength(value1) + 2);
if (!buf1)
return (1);
my_cpy(buf1, var1);
_my_cat(buf1, "=");
_my_cat(buf1, value1);
node1 = info1->env;
while (node1)
{
p1 = first_with(node1->str, var1);
if (p1 && *p1 == '=')
{
free(node1->str);
node1->str = buf1;
info1->env_changed = 1;
return (0);
}
node1 = node1->next;
}
plac_node_end(&(info1->env), buf1, 0);
free(buf1);
info1->env_changed = 1;
return (0);
}

