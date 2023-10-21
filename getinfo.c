#include "shelly.h"

/**
* clear_info - initializes info_t struct
* @info1: struct address
*/
void clear_info(info_t *info1)
{
info1->arg = NULL;
info1->argv = NULL;
info1->path = NULL;
info1->argc = 0;
}

/**
* set_info - initializes info_t struct
* @info1: struct address
* @av1: argument vector
*/
void set_info(info_t *info1, char **av1)
{
int i1 = 0;

info1->fname = av1[0];
if (info1->arg)
{
info1->argv = st_tow(info1->arg, " \t");
if (!info1->argv)
{
info1->argv = malloc(sizeof(char *) * 2);
if (info1->argv)
{
info1->argv[0] = strd_up(info1->arg);
info1->argv[1] = NULL;
}
}
for (i1 = 0; info1->argv && info1->argv[i1]; i1++)
;
info1->argc = i1;
replace_alias(info1);
replace_vars(info1);
}
}

/**
* free_info - frees info_t struct fields
* @info1: struct address
* @all1: true if freeing all fields
*/
void free_info(info_t *info1, int all1)
{
myf_free(info1->argv);
info1->argv = NULL;
info1->path = NULL;

if (all1)
{
if (!info1->cmd_buf)
free(info1->arg);
if (info1->env)
free_list(&(info1->env));
if (info1->history)
free_list(&(info1->history));
if (info1->alias)
free_list(&(info1->alias));
myf_free(info1->environ);
info1->environ = NULL;
my_freed((void **)info1->cmd_buf);
if (info1->readfd > 2)
close(info1->readfd);
_putchar(b_flush);
}
}

