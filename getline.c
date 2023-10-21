#include "shelly.h"

/**
* input_buf - buffers chained commands
* @info: parameter struct
* @buf: address of buffer
* @len: address of len var
*
* Return: bytes read
*/
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t r1 = 0;
size_t len_p1 = 0;

if (!*len) /* if nothing left in the buffer, fill it */
{
/*bfree((void **)info->cmd_buf);*/
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
r1 = getline(buf, &len_p1, stdin);
#else
r1 = _getline(info, buf, &len_p1);
#endif
if (r1 > 0)
{
if ((*buf)[r1 - 1] == '\n')
{
(*buf)[r1 - 1] = '\0'; /* remove trailing newline */
r1--;
}
info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
/* if (_strchr(*buf, ';')) is this a command chain? */
{
*len = r1;
info->cmd_buf = buf;
}
}
}
return (r1);
}

/**
* get_input - gets a line minus the newline
* @info: parameter struct
*
* Return: bytes read
*/
ssize_t get_input(info_t *info)
{
static char *buf1; /* the ';' command chain buffer */
static size_t i1, j1, len1;
ssize_t r1 = 0;
char **buf_p1 = &(info->arg), *p1;

_putchar(BUF_FLUSH);
r1 = input_buf(info, &buf1, &len1);
if (r1 == -1) /* EOF */
return (-1);
if (len1)    /* we have commands left in the chain buffer */
{
j1 = i1; /* init new iterator to current buf position */
p1 = buf1 + i1; /* get pointer for return */
check_chain(info, buf1, &j1, i1, len1);
while (j1 < len1) /* iterate to semicolon or end */
{
if (is_chain(info, buf1, &j1))
break;
j1++;
}
i1 = j1 + 1; /* increment past nulled ';'' */
if (i1 >= len1) /* reached end of buffer? */
{
i1 = len1 = 0; /* reset position and length */
info->cmd_buf_type = CMD_NORM;
}
*buf_p1 = p1; /* pass back pointer to current command position */
return (_strlen(p1)); /* return length of current command */
}
*buf_p1 = buf1; /* else not a chain, pass back buffer from _getline() */
return (r1); /* return length of buffer from _getline() */
}

/**
* read_buf - reads a buffer
* @info: parameter struct
* @buf1: buffer
* @i1: size
*
* Return: r1
*/
ssize_t read_buf(info_t *info, char *buf1, size_t *i1)
{
ssize_t r1 = 0;

if (*i1)
return (0);
r1 = read(info->readfd, buf1, READ_BUF_SIZE);
if (r1 >= 0)
*i1 = r1;
return (r1);
}

/**
* _getline - gets the next line of input from STDIN
* @info: parameter struct
* @ptr: address of pointer to buffer, preallocated or NULL
* @length: size of preallocated ptr buffer if not NULL
*
* Return: s1
*/
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buf1[READ_BUF_SIZE];
static size_t i1, len1;
size_t k1;
ssize_t r1 = 0, s1 = 0;
char *p1 = NULL, *new_p1 = NULL, *c1;

p1 = *ptr;

if (p1 && length)
s1 = *length;
if (i1 == len1)
i1 = len1 = 0;
r1 = read_buf(info, buf1, &len1);
if (r1 == -1 || (r1 == 0 && len1 == 0))
return (-1);
c1 = _strchr(buf1 + i1, '\n');
k1 = c1 ? 1 + (unsigned int)(c1 - buf1) : len1;
new_p1 = _realloc(p1, s1, s1 ? s1 + k1 : k1 + 1);
if (!new_p1) /* MALLOC FAILURE! */
return (p1 ? free(p1), -1 : -1);
if (s1)
_strncat(new_p1, buf1 + i1, k1 - i1);
else
_strncpy(new_p1, buf1 + i1, k1 - i1 + 1);
s1 += k1 - i1;
i1 = k1;
p1 = new_p1;
if (length)
*length = s1;
*ptr = p1;
return (s1);
}

/**
* sigintHandler - blocks ctrl-C
* @sig_num: the signal number
*
* Return: void
*/
void sigintHandler(__attribute__((unused)) int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}

