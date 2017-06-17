/* 
* Program to locate a substring withing a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *strstr(char *haystack, char *needle)
{
	char *substr, *str;

	if (!haystack || !needle)
		return NULL;
	str = haystack;
	
	while (*str) {
		substr = needle;
		while (*substr && *str && *substr == *str) {
			substr++;
			str++;
		}
		if (!(*substr))
			return needle;
		str++;
	}
	return NULL;
}

int main()
{
	char *str = NULL, *substr = NULL;
	size_t len;
	len = 50;
	substr = malloc(sizeof(char) * len);

	char c;
	int i = 0;

	if (getline(&str, &len, stdin) == -1) {
		printf("error \n");
	}

	/* To avoid reading newline char */
	while((c = fgetc(stdin)) != '\n')
		substr[i++] = c;

	substr = strstr(str, substr);
	if (substr)
		printf("Substring: %s\n", substr);
	else 
		printf("Substring not found\n");

	return 0;
}


