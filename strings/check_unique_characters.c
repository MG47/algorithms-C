/*
* Check if a string has all unique characters 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ASCII_SIZE 256

int unique_characters(char *str)
{
	int *val;
	int ret;

	if (!str || (*str) == '\n')
		return 0;

	val = calloc(ASCII_SIZE, sizeof(int));
	if (!val)
		exit(EXIT_FAILURE);

	while (*str) {
		if (val[*str]) {
			ret = 0;
			goto free_exit;
		}
		val[*str] = 1;
		str++;
	}
	ret = 1;
free_exit:
	free(val);
	return ret;
}

int main()
{
	printf("Check if a string has unique characters\n");
	char *str = NULL;
	size_t len;

	printf("Enter string\n");

	if (getline(&str, &len, stdin) == -1) {
		printf("error: %s\n", strerror(errno));
	}

	int ans = 0;
	ans = unique_characters(str);
	if (ans)
		printf("String has unique characters\n");
	else
		printf("String does not have unique characters\n");	

	return 0;
}

