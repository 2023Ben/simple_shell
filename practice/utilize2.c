#include "main.h"


/**
 * constr_ct - Build Command
 * @token: Excutable Command
 * @value: Dirctory Conatining Command
 *
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *constr_ct(char *token, char *value)
{
	char *COmmand;
	size_t len;

	len = strl(value) + strl(token) + 2;
	COmmand = malloc(sizeof(char) * len);
	if (COmmand == NULL)
	{
		return (NULL);
	}

	Mset(COmmand, 0, len);

	COmmand = cat(COmmand, value);
	COmmand = cat(COmmand, "/");
	COmmand = cat(COmmand, token);

	return (COmmand);
}

