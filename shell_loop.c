#include "shelly.h"

/**
* hsh - main shell loop
* @info: the parameter & return info struct
* @av1: the argument vector from main()
*
* Return: 0 on success, 1 on error, or error code
*/
int hsh(info_t *info1, char **av1)
{
ssize_t r1 = 0;
int builtin_ret1 = 0;

while (r1 != -1 && builtin_ret1 != -2)
{
clear_info(info1);
if (interactive(info1))
_puts("$ ");
_eputchar(BUF_FLUSH);
r1 = get_input(info1);
if (r1 != -1)
{
set_info(info1, av1);
builtin_ret1 = find_builtin(info1);
if (builtin_ret1 == -1)
find_cmd(info1);
}
else if (interactive(info1))
_putchar('\n');
free_info(info1, 0);
}
write_history(info1);
free_info(info1, 1);
if (!interactive(info1) && info1->status)
exit(info1->status);
if (builtin_ret1 == -2)
{
if (info1->err_num == -1)
exit(info1->status);
exit(info1->err_num);
}
return (builtin_ret1);
}

/**
* find_builtin - finds a builtin command
* @info1: the parameter & return info struct
*
* Return: -1 if builtin not found,
*			0 if builtin executed successfully,
*			1 if builtin found but not successful,
*			-2 if builtin signals exit()
*/
int find_builtin(info_t *info1)
{
int i1, built_in_ret1 = -1;

builtin_table builtintbl1[] = {
{"exit", _myexit},
{"env", _myenv},
{"help", _myhelp},
{"history", _myhistory},
{"setenv", _mysetenv},
{"unsetenv", _myunsetenv},
{"cd", _mycd},
{"alias", _myalias},
{NULL, NULL}
};
for (i1 = 0; builtintbl1[i1].type; i1++)
if (_strcmp(info1->argv[0], builtintbl1[i1].type) == 0)
{
info1->line_count++;
built_in_ret1 = builtintbl1[i1].func(info1);
break;
}
return (built_in_ret1);
}

/**
* find_cmd - finds a command in PATH
* @info1: the parameter & return info struct
*
* Return: void
*/
void find_cmd(info_t *info1)
{
char *path1 = NULL;
int i1, k1;

info1->path = info1->argv[0];
if (info1->linecount_flag == 1)
{
info1->line_count++;
info1->linecount_flag = 0;
}
for (i1 = 0, k1 = 0; info1->arg[i1]; i1++)
if (!is_delim(info1->arg[i1], " \t\n"))
k1++;
if (!k1)
return;
path1 = find_path(info1, _getenv(info1, "PATH="), info1->argv[0]);
if (path1)
{
info1->path = path1;
fork_cmd(info1);
}
else
{
if ((interactive(info1) || _getenv(info1, "PATH=")
|| info1->argv[0][0] == '/') && is_cmd(info1, info1->argv[0]))
fork_cmd(info1);
else if (*(info1->arg) != '\n')
{
info1->status = 127;
print_error(info1, "not found\n");
}
}
}

/**
* fork_cmd - forks an exec thread to run cmd
* @info1: the parameter & return info struct
*
* Return: void
*/
void fork_cmd(info_t *info1)
{
pid_t child_pid1;

child_pid1 = fork();

if (child_pid1 == -1)
{
/* TODO: PUT ERROR FUNCTION */
perror("Error:");
return;
}
if (child_pid1 == 0)
{
if (execve(info1->path, info1->argv, get_environ(info1)) == -1)
{
free_info(info1, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
/* TODO: PUT ERROR FUNCTION */
}
else
{
wait(&(info1->status));
if (WIFEXITED(info1->status))
{
info1->status = WEXITSTATUS(info1->status);
if (info1->status == 126)
print_error(info1, "Permission denied\n");
}
}
}

