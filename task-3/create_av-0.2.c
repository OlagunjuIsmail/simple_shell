#include "main.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
  * create_argv - creates an null terminated array of words from a string
  * @str: the command string
  * Description: uses space character as the delimiter and splits the
  * command string into words, saving the pointer to each into
  * a malloc'ed array
  * Return: pointer to the array/arg vector
  */
char **create_argv(char *str)
{
	char **arr, *str_cpy, *path;
	unsigned int n_words, i;

	if (str == NULL)
		return (NULL);

	str_cpy = strdup(str);
	n_words = 0;
	if (strtok(str_cpy, " "))
		n_words++;
	while (strtok(NULL, " "))
		n_words++;

	arr = malloc(sizeof(int) * 2 * (n_words + 1));

	path = strtok(str, " ");
	arr[0] = strdup(path);
	for (i = 1; i < n_words; i++)
	{
		path = strtok(NULL, " ");
		arr[i] = strdup(path);
	}

	arr[i] = NULL;
	free(str_cpy);

	return (arr);
}
