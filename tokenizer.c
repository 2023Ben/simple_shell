#include "shelly.h"

/**
* **strtow - splits a string into words. Repeat delimiters are ignored
* @input_str: the input string
* @delimiters: the delimiter string
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow(char *input_str, char *delimiters)
{
int i1, j1, k1, m1, num_words = 0;
char **words;

if (input_str == NULL || input_str[0] == 0)
return (NULL);
if (!delimiters)
delimiters = " ";
for (i1 = 0; input_str[i1] != '\0'; i1++)
if (!is_delim(input_str[i1], delimiters) && (is_delim(input_str[i1 + 1], delimiters) || !input_str[i1 + 1]))
num_words++;
if (num_words == 0)
return (NULL);
words = malloc((1 + num_words) *sizeof(char *));
if (!words)
return (NULL);
for (i1 = 0, j1 = 0; j1 < num_words; j1++)
{
for (; is_delim(input_str[i1], delimiters);)
i1++;
k1 = 0;
while (!is_delim(input_str[i1 + k1], delimiters) && input_str[i1 + k1])
k1++;
words[j1] = malloc((k1 + 1) * sizeof(char));
if (!words[j1])
{
for (k1 = 0; k1 < j1; k1++)
free(words[k1]);
free(words);
return (NULL);
}
for (m1 = 0; m1 < k1; m1++)
words[j1][m1] = input_str[i1++];
words[j1][m1] = 0;
}
words[j1] = NULL;
return (words);
}

/**
* **strtow2 - splits a string into words
* @input_str: the input string
* @delimiter: the delimiter
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow2(char *input_str, char delimiter)
{
int i1, j1, k1, m1, num_words = 0;
char **words;

if (input_str == NULL || input_str[0] == 0)
return (NULL);
for (i1 = 0; input_str[i1] != '\0'; i1++)
if ((input_str[i1] != delimiter && input_str[i1 + 1] == delimiter) ||
(input_str[i1] != delimiter && !input_str[i1 + 1]) || input_str[i1 + 1] == delimiter)
num_words++;
if (num_words == 0)
return (NULL);
words = malloc((1 + num_words) *sizeof(char *));
if (!words)
return (NULL);
for (i1 = 0, j1 = 0; j1 < num_words; j1++)
{
while (input_str[i1] == delimiter && input_str[i1] != delimiter)
i1++;
k1 = 0;
while (input_str[i1 + k1] != delimiter && input_str[i1 + k1] && input_str[i1 + k1] != delimiter)
k1++;
words[j1] = malloc((k1 + 1) * sizeof(char));
if (!words[j1])
{
for (k1 = 0; k1 < j1; k1++)
free(words[k1]);
free(words);
return (NULL);
}
for (m1 = 0; m1 < k1; m1++)
words[j1][m1] = input_str[i1++];
words[j1][m1] = 0;
}
words[j1] = NULL;
return (words);
}

