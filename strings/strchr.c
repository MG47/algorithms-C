/* 
* Program to return a pointer to the first occurrence of the character c in the string s
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *strchr_custom(char *str, int c)
{
	char ch  = c;
	if (!str)
		return NULL;

	while (*str) {
		if (*str == c)
			return str;
		str++;
	}
	/* Null character is considered part of the string - if c is '\0', return ptr to it */
	if (c == '\0')
		return str;
	return NULL;
}

int main()
{
	char c, *ptr;
	char *str = NULL;
	size_t len;

	if (getline(&str, &len, stdin) == -1) {
		printf("error\n");
	}

	c = 'a';
	ptr = strchr_custom(str, c);
	if (ptr) 
		printf("found character %c at %p\n", (char)c, ptr);

	return 0;
}


