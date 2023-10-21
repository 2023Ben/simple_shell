#include "shelly.h"

/**
* myhsh - main shell loop
* @info: the parameter & return info struct
* @av1: the argument vector from main()
*
* Return: 0 on success, 1 on error, or error code
*/
int myhsh(info_t *info1, char **av1)
{
ssize_t r1 = 0;
int _built_ret1 = 0;

while (r1 != -1 && _built_ret1 != -2)
{
clear_info(info1);
if (myinteract(info1))
_myplace("$ ");
theputstr(b_flush);
r1 = get_input(info1);
if (r1 != -1)
{
set_info(info1, av1);
_built_ret1 = myfinding__built(info1);
if (_built_ret1 == -1)
myfinding_cmd(info1);
}
else if (myinteract(info1))
_putchar('\n');
free_info(info1, 0);
}
write_history(info1);
free_info(info1, 1);
if (!myinteract(info1) && info1->status)
exit(info1->status);
if (_built_ret1 == -2)
{
if (info1->err_num == -1)
exit(info1->status);
exit(info1->err_num);
}
return (_built_ret1);
}

/**
* myfinding__built - myfindings a _built command
* @info1: the parameter & return info struct
*
* Return: -1 if _built not found,
*			0 if _built executed successfully,
*			1 if _built found but not successful,
*			-2 if _built signals exit()
*/
int myfinding__built(info_t *info1)
{
int i1, built_in_ret1 = -1;

_built_table _builttbl1[] = {
{"exit", ourexit},
{"env", _myenv},
{"help", h_elp},
{"history", _myhistory},
{"setenv", _mysetenv},
{"unsetenv", _myunsetenv},
{"cd", our_cd},
{"alias", A_lias},
{NULL, NULL}
};
for (i1 = 0; _builttbl1[i1].type; i1++)
if (_mycmp(info1->argv[0], _builttbl1[i1].type) == 0)
{
info1->line_count++;
built_in_ret1 = _builttbl1[i1].func(info1);
break;
}
return (built_in_ret1);
}

/**
* myfinding_cmd - myfindings a command in PATH
* @info1: the parameter & return info struct
*
* Return: void
*/
void myfinding_cmd(info_t *info1)
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
if (!check_del(info1->arg[i1], " \t\n"))
k1++;
if (!k1)
return;
path1 = myfinding_path(info1, _getenv(info1, "PATH="), info1->argv[0]);
if (path1)
{
info1->path = path1;
myfork_command(info1);
}
else
{
if ((myinteract(info1) || _getenv(info1, "PATH=")
|| info1->argv[0][0] == '/') && isit_command(info1, info1->argv[0]))
myfork_command(info1);
else if (*(info1->arg) != '\n')
{
info1->status = 127;
put_myerror(info1, "not found\n");
}
}
}

/**
* myfork_command - forks an exec thread to run cmd
* @info1: the parameter & return info struct
*
* Return: void
*/
void myfork_command(info_t *info1)
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
put_myerror(info1, "Permission denied\n");
}
}
}

