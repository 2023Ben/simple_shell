#include "main.h"

/**
 * main - run shell
 * @argc : argument length
 * @argv: array of argument value
 * @env: array of environment variable
 * Return: 0 on success
 */

int main(int argc, char **argv, char **env)
{
	char *BUF = NULL;
	size_t BUFlen = 0;
	char *COmmand[20];

	(void)argc;
	ICATE(BUF, BUFlen, COmmand, argv, env);
	return (0);
}
