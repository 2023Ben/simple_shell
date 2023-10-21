#include "shelly.h"

/**
* get_history_file - gets the history file
* @info: parameter struct
*
* Return: allocated string containing history file
*/
char *get_history_file(info_t *info)
{
char *dir1, *buf1;

dir1 = _getenv(info, "HOME=");

if (!dir1)
return (NULL);
buf1 = malloc(sizeof(char) * (_mystrlength(dir1) + _mystrlength(old_file) + 2));
if (!buf1)
return (NULL);
buf1[0] = 0;
my_cpy(buf1, dir1);
_my_cat(buf1, "/");
_my_cat(buf1, old_file);
return (buf1);
}

/**
* write_history - creates a file, or appends to an existing file
* @info: the parameter struct
*
* Return: 1 on success, else -1
*/
int write_history(info_t *info)
{
ssize_t fd;
char *filename1 = get_history_file(info);

mylist *node1 = NULL;

if (!filename1)
return (-1);
fd = open(filename1, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename1);
if (fd == -1)
return (-1);
for (node1 = info->history; node1; node1 = node1->next)
{
_myplacefd(node1->str, fd);
_myputfd('\n', fd);
}
_myputfd(b_flush, fd);
close(fd);
return (1);
}

/**
* read_history - reads history from file
* @info: the parameter struct
*
* Return: histcount on success, 0 otherwise
*/
int read_history(info_t *info)
{
int i1, last1 = 0, linecount1 = 0;
ssize_t fd1, rdlen1, fsize1 = 0;
struct stat st1;
char *buf1 = NULL, *filename1 = get_history_file(info);

if (!filename1)
return (0);
fd1 = open(filename1, O_RDONLY);
free(filename1);
if (fd1 == -1)
return (0);
if (!fstat(fd1, &st1))
fsize1 = st1.st_size;
if (fsize1 < 2)
return (0);
buf1 = malloc(sizeof(char) * (fsize1 + 1));
if (!buf1)
return (0);
rdlen1 = read(fd1, buf1, fsize1);
buf1[fsize1] = 0;
if (rdlen1 <= 0)
return (free(buf1), 0);
close(fd1);
for (i1 = 0; i1 < fsize1; i1++)
if (buf1[i1] == '\n')
{
buf1[i1] = 0;
mybuild_history_list(info, buf1 + last1, linecount1++);
last1 = i1 + 1;
}
if (last1 != i1)
mybuild_history_list(info, buf1 + last1, linecount1++);
free(buf1);
info->histcount = linecount1;
while (info->histcount-- >= old_max)
delete_node_at_index(&(info->history), 0);
renumber_history(info);
return (info->histcount);
}

/**
* mybuild_history_list - adds entry to a history linked list
* @info: Structure containing potential arguments. Used to maintain
* @buf1: buffer
* @linecount1: the history linecount, histcount
*
* Return: Always 0
*/
int mybuild_history_list(info_t *info, char *buf1, int linecount1)
{
mylist *node1 = NULL;

if (info->history)
node1 = info->history;
plac_node_end(&node1, buf1, linecount1);
if (!info->history)
info->history = node1;
return (0);
}

/**
* renumber_history - renumbers the history linked list after changes
* @info: Structure containing potential arguments. Used to maintain
*
* Return: the new histcount
*/
int renumber_history(info_t *info)
{
mylist *node1 = info->history;
int i1 = 0;

while (node1)
{
node1->num = i1++;
node1 = node1->next;
}
return (info->histcount = i1);
}

