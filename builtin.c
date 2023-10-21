#include "shelly.h"

/**
 * ourexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int ourexit(info_t *info)
{
	int exitcheck1;

	if (info->argv[1])  /* If there is an exit argument */
	{
		exitcheck1 = Ra_atoi(info->argv[1]);
		if (exitcheck1 == -1)
		{
			info->status = 2;
			put_myerror(info, "Illegal number: ");
			_theputs(info->argv[1]);
			theputstr('\n');
			return (1);
		}
		info->err_num = Ra_atoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 * our_cd - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int our_cd(info_t *info)
{
	char *s1, *dir1, buffer1[1024];
	int chdir_ret1;

	s1 = getcwd(buffer1, 1024);
	if (!s1)
		_myplace("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir1 = _getenv(info, "HOME=");
		if (!dir1)
			chdir_ret1 = /* TODO: what should this be? */
				chdir((dir1 = _getenv(info, "PWD=")) ? dir1 : "/");
		else
			chdir_ret1 = chdir(dir1);
	}
	else if (_mycmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_myplace(s1);
			_putchar('\n');
			return (1);
		}
		_myplace(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret1 = /* TODO: what should this be? */
			chdir((dir1 = _getenv(info, "OLDPWD=")) ? dir1 : "/");
	}
	else
		chdir_ret1 = chdir(info->argv[1]);
	if (chdir_ret1 == -1)
	{
		put_myerror(info, "can't cd to ");
		_theputs(info->argv[1]), theputstr('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer1, 1024));
	}
	return (0);
}
/**
 * h_elp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int h_elp(info_t *info)
{
	char **arg_array1;

	arg_array1 = info->argv;
	_myplace("help call works. Function not yet implemented \n");
	if (0)
		_myplace(*arg_array1); /* temp att_unused workaround */
	return (0);
}
