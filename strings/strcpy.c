/* 
* Program to copy a string
* NOTE: The strings may not overlap
* NOTE: Destination string must be allocated and large enough (buffer overruns are not checked)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *strcpy_custom(char *dest, char *src)
{
	char *dst = dest;
	if (!src || !dst)
		return NULL;

	while (*src) {
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
	return dest;
}

int main()
{
	char *str = NULL, *dest = NULL;
	size_t len;

	if (getline(&str, &len, stdin) == -1) {
		printf("error \n");
	}

	dest = malloc(sizeof(char) * len);
	if (!dest)
		exit(EXIT_FAILURE);

	strcpy_custom(dest, str);
	if (dest)
		printf("Destination String: %s \n", dest);

	return 0;
}


