#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>


size_t mystrl(const char *str);
int mycmp(const char *str1, const char *str2);
char *my_fgets(char *str, int size, FILE *stream);
void run_COmmand(char **COmmand, char **argv, char **env);
int _printf(char *s);
int _strncmp(char *s1, char *s2, unsigned int n);
char *_getenv(char *target, char **env);
int REPL(char *BUF, size_t BUFlen, char **COmmand, char **argv, char **env);
int read_COmmand(char **BUF, size_t *BUFlen);
int exit_arg(char **COmmand, char **argv, char *BUF);
int A_toi(char *s);
char *_strcpy(char *dest, char *src);
int cmp(char *s1, char *s2);
void run_COmmand(char **COmmand, char **argv, char **env);
int arr_len(char **s);
void _print(char **env);
int Path(char **COmmand, char **env);
void pass(char *BUF, char **COmmand);
char *TRok1(char *str, const char *delim);
unsigned int DELIM(char c, const char *str);
char *constr_ct(char *token, char *value);
char *Mset(char *s, char b, unsigned int n);
char *RTSUP(char *str);
int _putchar(int h);
int strl(char *s);
void i_wan_print(void);
char *cat(char *dest, char *src);

#endif
