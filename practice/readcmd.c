#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

/**
 * exit_arg - handle exit with argument
 * @COmmand: array of command enter
 * @argv: array of argument
 * @BUF: command enter
 * Return: int
 */

int exit_arg(char **COmmand, char **argv, char *BUF)
{
	int status = A_toi(COmmand[1]);

	if (status < 0 || (status == 0 && COmmand[1][0] != '0'))
	{
		write(2, argv[0], strl(argv[0]));
		write(2, ": 1: exit: Illegal number: ", 27);
		write(2, COmmand[1], strl(COmmand[1]));
		write(2, "\n", 1);
		free(BUF);
		exit(2);
	}

	free(BUF);
	exit(status);
}


/**
 * read_COmmand - reads the commands from the terminal till newline char
 * @BUF: BUFfer to read the commands into
 * @BUFlen: length of the BUFfer
 * Return: Nothing
 */

int read_COmmand(char **BUF, size_t *BUFlen)
{
	int n;

	n = getline(BUF, BUFlen, stdin);

	if (n == -1)
	{
		free(*BUF);
		exit(0);
	}

	return (n);
}
