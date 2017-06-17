/* 
* Program to concatenate two strings
* NOTE: The strings may not overlap
* NOTE: Destination string must be allocated and large enough (buffer overruns are not checked)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *strcat_custom(char *dest, char *src)
{
	char *dst = dest;
	if (!dst || !src)
		return NULL;

	while (*dst) 
		dst++;

	while (*src) {
		*dst = *src;
		dst++;
		src++;
	}

	*dst = '\0';

	return dest;
}

int main()
{
	char *str = NULL, *dest = NULL;
	size_t len;
	len = 50;
	dest = malloc(sizeof(char) * len);

	char c;
	int i = 0;
	/* To avoid reading newline char */
	while((c = fgetc(stdin)) != '\n')
		dest[i++] = c;

	if (getline(&str, &len, stdin) == -1) {
		printf("error \n");
	}

	dest = strcat_custom(dest, str);
	if (dest)
		printf("Destination String: %s\n", dest);

	return 0;
}


