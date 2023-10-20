#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * run_COmmand - create child proccess and execute command
 * @COmmand: command to be executed
 * @argv: array of argument values
 * @env: array of environment variables
 * Return: Nothing
 */

void run_COmmand(char **COmmand, char **argv, char **env)
{
	int status, n = 1;

	if (COmmand[0][0] != '/' && COmmand[0][0] != '.')
	{
		n = Path(&(COmmand[0]), env);
		if (n == -1)
		{

			_printf(argv[0]);
			_printf(": No such file or directory\n");
			return;
		}
	}

	if (fork() == 0)
	{
		execve(COmmand[0], COmmand, env);
		_printf(argv[0]);
		_printf(": No such file or directory\n");
		free(COmmand[0]);
		exit(0);

	}

	else
	{
		wait(&status);
		if (n == 1 || n == -1)
			return;
		free(COmmand[0]);
	}

}