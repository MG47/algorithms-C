/*
* Program to remove duplicate characters in a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ASCII_SIZE 256

int remove_duplicates(char *str)
{
	int i, len, *val;
	if (!str || (*str == '\n'))
		return 0;

	val = calloc(ASCII_SIZE, sizeof(char));
	if (!val)
		exit(EXIT_FAILURE);

	i = 0;
	len = strlen(str);
	while (i < len) {
		if (val[str[i]]) {
			int j = i;
			while (j <= len) {
				str[j] = str[j + 1];
				j++;
			}
			len--;
			i--;
		} else {
			val[str[i]]++;
		}
		i++;
	}
	free(val);
	return 1;
}

int main()
{
	printf("Remove duplicate characters\n");
	char *str = NULL;
	size_t len;

	printf("Enter string 1\n");

	if (getline(&str, &len, stdin) == -1) {
		printf("error: %s\n", strerror(errno));
	}

	int ret = 0;
	ret = remove_duplicates(str);
	if (ret)
		printf("String after removing duplicate characters: %s\n", str);
	return 0;
}

