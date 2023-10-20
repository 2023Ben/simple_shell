#include "main.h"
#include <string.h>

/**
 * give - return a env and its values
 * @target: env to be return
 * @environ: array of env
 * Return: env and values on Success, NULL on Failure
 */

char *give(char *target, char **environ)
{
	char *path;
	int i = 0;

	for (; (environ[i]); )
	{
		if (_strncmp(environ[i], target, strl(target)) == 0)
		{
			path = RTSUP(environ[i]);
			return (path);
		}
		i++;
	}

	return (NULL);
}

