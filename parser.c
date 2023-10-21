#include "shelly.h"

/**
* is_cmd - determines if a file is an executable command
* @info1: the info struct
* @path1: path to the file
*
* Return: 1 if true, 0 otherwise
*/
int is_cmd(info_t *info1, char *path1)
{
struct stat st;
(void)info1;

if (!path1 || stat(path1, &st))
return (0);
if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
* dup_chars - duplicates characters
* @pathstr1: the PATH string
* @start1: starting index
* @stop1: stopping index
*
* Return: pointer to new buffer
*/
char *dup_chars(char *pathstr1, int start1, int stop1)
{
static char buf1[1024];
int i1 = 0, k1 = 0;

for (k1 = 0, i1 = start1; i1 < stop1; i1++)
if (pathstr1[i1] != ':')
buf1[k1++] = pathstr1[i1];
buf1[k1] = 0;
return (buf1);
}

/**
* find_path - finds this cmd in the PATH string
* @info1: the info struct
* @pathstr1: the PATH string
* @cmd1: the cmd to find
*
* Return: full path of cmd if found or NULL
*/
char *find_path(info_t *info1, char *pathstr1, char *cmd1)
{
int i1 = 0, curr_pos1 = 0;
char *path1;

if (!pathstr1)
return (NULL);
if ((_strlen(cmd1) > 2) && starts_with(cmd1, "./"))
{
if (is_cmd(info1, cmd1))
return (cmd1);
}
while (1)
{
if (!pathstr1[i1] || pathstr1[i1] == ':')
{
path1 = dup_chars(pathstr1, curr_pos1, i1);
if (!*path1)
_strcat(path1, cmd1);
else
{
_strcat(path1, "/");
_strcat(path1, cmd1);
}
if (is_cmd(info1, path1))
return (path1);
if (!pathstr1[i1])
break;
curr_pos1 = i1;
}
i1++;
}
return (NULL);
}

