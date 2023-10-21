#include "main.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>

/**
 * pass - separate command from argumets
 * @BUF: command to be separate
 * @COmmand: array where commands will be store
 * Return: Nothing
 */

void pass(char *BUF, char **COmmand)
{
	char *str;
	int i = 0;

	str = TRok1(BUF, " \a\r\t\n");

	for (; str; )
	{
		if (str[0] == '#')
		{
			COmmand[i] = NULL;
			return;
		}
		COmmand[i] = str;
		str = TRok1(NULL, " \n");
		i++;
	}

	COmmand[i] = NULL;

}

