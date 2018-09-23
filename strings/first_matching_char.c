/*
* Program to find first matching character between two strings
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ASCII_SIZE 256

char first_matching_char(char *str1, char *str2)
{
	int i, len, *val;
	if (!str1 || !str2)
		return 0;

	val = calloc(ASCII_SIZE, sizeof(char));
	if (!val)
		exit(EXIT_FAILURE);

	len = strlen(str1);

	for (i = 0; i < len - 1; i++)
		val[str1[i]]++;

	i = 0;
	len = strlen(str2);

	while (i < len - 1) {
		if (val[str2[i]])
			return str2[i];
		i++;
	}
	return 0;
}

int main()
{
	printf("Find first matching character\n");
	char *str1 = NULL, *str2 = NULL;
	size_t len;

	printf("Enter string 1\n");

	if (getline(&str1, &len, stdin) == -1) {
		printf("error: %s\n", strerror(errno));
	}

	printf("Enter string 2\n");

	if (getline(&str2, &len, stdin) == -1) {
		printf("error: %s\n", strerror(errno));
	}

	char match = 0;
	match = first_matching_char(str1, str2);
	if (match)
		printf("First matching character: %c\n", match);
	else 
		printf("No character matches\n");
	return 0;
}

