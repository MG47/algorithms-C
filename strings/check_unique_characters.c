/*
* Check if a string has all unique characters 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int unique_characters(char *str)
{
	int *val;

	if (!str || (*str) == '\n')
		return 0;

	val = calloc(256, sizeof(int));
	if (!val)
		exit(EXIT_FAILURE);

	while (*str) {
		if (val[*str])
			return 0;
		val[*str] = 1;
		str++;
	}
	return 1;
}

int main()
{
	printf("Check if a string has unique characters\n");
	char *str = NULL;
	size_t len;
	int i = 0;

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

