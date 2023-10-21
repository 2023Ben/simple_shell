#ifndef _SHELLY_H_
#define _SHELLY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#define READ_BUF_SIZE 1024
#define W_B_size 1024
#define b_flush -1
#define Command_Norm	0
#define command_or		1
#define command_and		2
#define command_chain	3
#define con_lower	1
#define convert_unsigned	2
#define use_getl 0
#define Strtok 0
#define old_file	".simple_shelly.history"
#define old_max	4096
extern char **environ;
/**
 * struct LISTSTR - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct LISTSTR
{
	int num;
	char *str;
	struct LISTSTR *next;
} mylist;
/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	mylist *env;
	mylist *history;
	mylist *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;
#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
/**
 *struct _built - contains a _built string and related function
 *@type: the _built command flag
 *@func: the function
 */
typedef struct _built
{
	char *type;
	int (*func)(info_t *);
} _built_table;
int myhsh(info_t *, char **);
int myfinding__built(info_t *);
void myfinding_cmd(info_t *);
void myfork_command(info_t *);
int isit_command(info_t *, char *);
char *mydupl_str(char *, int, int);
char *myfinding_path(info_t *, char *, char *);
int loopmyhsh(char **);
void _theputs(char *);
int theputstr(char);
int _myputfd(char c, int fd);
int _myplacefd(char *str, int fd);
int _mystrlength(char *);
int _mycmp(char *, char *);
char *first_with(const char *, const char *);
char *_my_cat(char *, char *);
char *my_cpy(char *, char *);
char *strd_up(const char *);
void _myplace(char *);
int _putchar(char);
char *_cpymystr(char *, char *, int);
char *_catmystr(char *, char *, int);
char *chr_str(char *, char);
char **st_tow(char *, char *);
char **st_tow2(char *, char);
char *my_memeset(char *, char, unsigned int);
void myf_free(char **);
void *re_alloc(void *, unsigned int, unsigned int);
int my_freed(void **);
int myinteract(info_t *);
int check_del(char, char *);
int hasalpha(int);
int A_toi(char *);
int Ra_atoi(char *);
void put_myerror(info_t *, char *);
int place_d(int, int);
char *vert_num(long int, int, int);
void move_del(char *);
int ourexit(info_t *);
int our_cd(info_t *);
int h_elp(info_t *);
int _myhistory(info_t *);
int A_lias(info_t *);
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int mybuild_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);
mylist *plac_node(mylist **, const char *, int);
mylist *plac_node_end(mylist **, const char *, int);
size_t print_list_str(const mylist *);
int delete_node_at_index(mylist **, unsigned int);
void free_list(mylist **);
size_t list_len(const mylist *);
char **mylisto_strings(mylist *);
size_t print_list(const mylist *);
mylist *node_first_with(mylist *, char *, char);
ssize_t get_node_index(mylist *, mylist *);
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);
#endif
