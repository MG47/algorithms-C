/*
* Program to find first differing character between two strings
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ASCII_SIZE 256

char first_differing_char(char *str1, char *str2)
{
	int i, len, *val;
	if (!str1 || !str2)
		return 0;

	val = calloc(ASCII_SIZE, sizeof(char));
	if (!val)
		exit(EXIT_FAILURE);

	len = strlen(str1);

	for (i = 0; i <= len; i++)
		val[str1[i]]++;

	i = 0;
	len = strlen(str2);
	while (i < len - 1) {
		if (!val[str2[i]])
			return str2[i];
		i++;
	}
	return 0;
}

int main()
{
	printf("Find first differing character\n");
	char *str1 = NULL, *str2 = NULL;
	size_t len;
	int i = 0;

	printf("Enter string 1\n");

	if (getline(&str1, &len, stdin) == -1) {
		printf("error: %s\n", strerror(errno));
	}

	printf("Enter string 2\n");

	if (getline(&str2, &len, stdin) == -1) {
		printf("error: %s\n", strerror(errno));
	}

	char differ = 0;
	differ = first_differing_char(str1, str2);
	if (differ)
		printf("First differing character in string 2: %c\n", differ);
	else 
		printf("Strings have same characters\n");
	return 0;
}

