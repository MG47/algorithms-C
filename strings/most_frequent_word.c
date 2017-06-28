/*
* Program to find out most frequently occuring word (string) in an array of strings
* INCOMPLETE - need to find efficient solution (map/hash)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *most_frequent_word(char **str_table, int len)
{
	int i, j, max_index, max;
	int *ft;
	if (!str_table)
		return NULL;

	ft = malloc(sizeof(int) * len);
	if (!ft)
		exit(EXIT_FAILURE);

	max_index = 0, max = 0;
	for (i = 0; i < len; i++) {
		for (j = i; j < len; j++) {
			if (!strcmp(str_table[i], str_table[j]))
				ft[i]++;
		}
		if (ft[i] > max) {
			max = ft[i];
			max_index = i;
		}
	}
	free(ft);
	if (max > 1)
		return str_table[max_index];
	else
		return NULL;
}

int main()
{
	char **str_table = NULL;
	size_t len, length;
	int i = 0;

	len = 4;
	str_table = malloc(sizeof(char *) * len);

	for (i = 0; i < len; i++) {
		if (getline(&str_table[i], &length, stdin) == -1) {
			printf("error: %s\n", strerror(errno));
		}
	}

	char *ans = 0;
	ans = most_frequent_word(str_table, len);
	if (ans)
		printf("Most frequent word: %s\n", ans);

	return 0;
}

