#include "shelly.h"

/**
* main - entry point
* @ac1: arg count
* @av1: arg vector
*
* Return: 0 on success, 1 on error
*/
int main(int ac1, char **av1)
{
info_t info1[] = { INFO_INIT };
int fd1 = 2;

asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (fd1)
: "r" (fd1));

if (ac1 == 2)
{
fd1 = open(av1[1], O_RDONLY);
if (fd1 == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_theputs(av1[0]);
_theputs(": 0: Can't open ");
_theputs(av1[1]);
theputstr('\n');
theputstr(b_flush);
exit(127);
}
return (EXIT_FAILURE);
}
info1->readfd = fd1;
}
populate_env_list(info1);
read_history(info1);
myhsh(info1, av1);
return (EXIT_SUCCESS);
}

