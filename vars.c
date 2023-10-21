#include "shelly.h"

/**
* is_chain - test if the current char in the buffer is a chain delimiter
* @info1: the parameter struct
* @buf1: the char buffer
* @p1: address of the current position in buf
*
* Return: 1 if a chain delimiter, 0 otherwise
*/
int is_chain(info_t *info1, char *buf1, size_t *p1)
{
size_t j1 = *p1;

if (buf1[j1] == '|' && buf1[j1 + 1] == '|')
{
buf1[j1] = 0;
j1++;
info1->cmd_buf_type = command_or;
}
else if (buf1[j1] == '&' && buf1[j1 + 1] == '&')
{
buf1[j1] = 0;
j1++;
info1->cmd_buf_type = command_and;
}
else if (buf1[j1] == ';') /* found the end of this command */
{
buf1[j1] = 0; /* replace semicolon with null */
info1->cmd_buf_type = command_chain;
}
else
return (0);
*p1 = j1;
return (1);
}

/**
* check_chain - checks if we should continue chaining based on the last status
* @info1: the parameter struct
* @buf1: the char buffer
* @p1: address of the current position in buf
* @i1: starting position in buf
* @len1: length of buf
*
* Return: Void
*/
void check_chain(info_t *info1, char *buf1, size_t *p1, size_t i1, size_t len1)
{
size_t j1 = *p1;

if (info1->cmd_buf_type == command_and)
{
if (info1->status)
{
buf1[i1] = 0;
j1 = len1;
}
}
if (info1->cmd_buf_type == command_or)
{
if (!info1->status)
{
buf1[i1] = 0;
j1 = len1;
}
}
*p1 = j1;
}

/**
* replace_alias - replaces aliases in the tokenized string
* @info1: the parameter struct
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_alias(info_t *info1)
{
int i1;
mylist *node1;
char *p1;

for (i1 = 0; i1 < 10; i1++)
{
node1 = node_first_with(info1->alias, info1->argv[0], '=');
if (!node1)
return (0);
free(info1->argv[0]);
p1 = chr_str(node1->str, '=');
if (!p1)
return (0);
p1 = strd_up(p1 + 1);
if (!p1)
return (0);
info1->argv[0] = p1;
}
return (1);
}

/**
* replace_vars - replaces variables in the tokenized string
* @info1: the parameter struct
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_vars(info_t *info1)
{
int i1 = 0;

mylist *node1;

for (i1 = 0; info1->argv[i1]; i1++)
{
if (info1->argv[i1][0] != '$' || !info1->argv[i1][1])
continue;
if (!_mycmp(info1->argv[i1], "$?"))
{
replace_string(&(info1->argv[i1]),
strd_up(vert_num(info1->status, 10, 0)));
continue;
}
if (!_mycmp(info1->argv[i1], "$$"))
{
replace_string(&(info1->argv[i1]),
strd_up(vert_num(getpid(), 10, 0)));
continue;
}
node1 = node_first_with(info1->env, &info1->argv[i1][1], '=');
if (node1)
{
replace_string(&(info1->argv[i1]),
strd_up(chr_str(node1->str, '=') + 1));
continue;
}
replace_string(&info1->argv[i1], strd_up(""));
}
return (0);
}

/**
* replace_string - replaces a string
* @old1: address of the old string
* @new1: new string
*
* Return: 1 if replaced, 0 otherwise
*/
int replace_string(char **old1, char *new1)
{
free(*old1);

*old1 = new1;

return (1);
}

