/*
* Program to count words in a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char **word_counter(char *str1)
{
	char **word_table;
	word_table = malloc(sizeof(char *) * 100);
	if (!word_table)
		exit(EXIT_FAILURE);

	int i = 0, j = 0, k = 0;

	while (str1[i] != '\0' || str1[i] != '\n') {
		word_table[k] = malloc(sizeof(char) * 100);
		j = 0;

		while (str1[i + j] != ' ') {
			if (str1[i + j] == '\n' || str1[i + j] == '\0')
				return word_table;
			word_table[k][j] = str1[i + j];
			j++;
		}
		str1[i + j] = '\0';
		i += j;
		i++;
		k++;
	}
	return word_table;
}

int main()
{
	printf("Count words in a string\n");
	char *str = NULL;
	size_t len;
	int i = 0;
	char **word_table;

	printf("Enter string\n");

	if (getline(&str, &len, stdin) == -1) {
		printf("error: %s\n", strerror(errno));
	}

	i = 0;
	word_table = word_counter(str);
	while (word_table[i]) {
		printf("word %d: %s\n",i, word_table[i]);
		i++;
	}

	printf("Total number of words = %d\n", i);
	return 0;
}

