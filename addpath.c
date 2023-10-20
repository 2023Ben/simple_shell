#include "main.h"

/**
 * Path - add the rightful path to the command enter by the user
 * @command: command enter by user
 * @env: array of env
 * Return: 0 on success and 1 on failure
 */

int Path(char **command, char **env)
{
	char *Atarr, *s, *path = give("PATH", env);
	struct stat st;

	Atarr = TRok1(path, ":");

	while (Atarr)
	{
		s = constr_ct(*command, Atarr);
		if (stat(s, &st) == 0)
		{
			*command = RTSUP(s);
			free(s);
			free(path);
			return (0);
		}
		Atarr = TRok1(NULL, ":");
		free(s);
	}


	free(path);
	return (-1);

}
