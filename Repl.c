#include "main.h"
#include <stdio.h>

/**
 * ICATE - read eval print loop
 * @BUF: command to be executed
 * @BUFlen: length of the command
 * @COmmand : array to store command and argument
 * @argv: argument values
 * @env: array of environment variable
 * Return: 0 on success
 */


int ICATE(char *BUF, size_t BUFlen, char **COmmand, char **argv, char **env)
{

	while (1)
	{
		if (isatty(STDIN_FILENO))
			i_wan_print();
		read_COmmand(&BUF, &BUFlen);
		if (BUF[0] == '\0' || cmp(BUF, "\n") == 0)
		{
			continue;
		}
		if (cmp(BUF, "exit\n") == 0)
		{
			free(BUF);
			return (0);
		}
		if (cmp(BUF, "env\n") == 0)
		{
			_print(env);
			continue;
		}
		pass(BUF, COmmand);
		if (COmmand[0] == NULL)
			continue;
		if (cmp(COmmand[0], "exit") == 0 && arr_len(COmmand) == 2)
		{
			exit_arg(COmmand, argv, BUF);
		}
		run_COmmand(COmmand, argv, env);
	}
	return (0);
}

