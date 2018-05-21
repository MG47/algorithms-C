/*
* Program to convert string characters to uppercase/lowercase
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define CASE_OFFSET 32

void to_lowercase(char *str)
{
	if (!str)
		return;
	while (*str) {
		if (*str >= 'A' && *str <= 'Z')
			*str += CASE_OFFSET; 
		str++;
	}
}

void to_uppercase(char *str)
{
	if (!str)
		return;
	while (*str) {
		if (*str >= 'a' && *str <= 'z')
			*str -= CASE_OFFSET; 
		str++;
	}
}

int main()
{
	char *str = NULL;
	size_t len;
	printf("Enter string \n");

	if (getline(&str, &len, stdin) == -1) {
		printf("error: %s\n", strerror(errno));
	}

	to_uppercase(str);
	printf("Uppercase string: %s\n", str);

	to_lowercase(str);
	printf("lowercase string: %s\n", str);

	return 0;
}

