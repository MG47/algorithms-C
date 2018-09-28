/* 
* Program to calculate the length of a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

size_t strlen_custom(char *str)
{
	size_t len = 0;
	if (!str)
		return 0;

	while (*str++) 
		len++;
	return len;
}

int main()
{
	char *str, c;
	size_t len = 40, length, i = 0;

	str = malloc(sizeof(char) * len);
	printf("Enter a string\n");
	while((c = fgetc(stdin)) != '\n')
		str[i++] = c;
	str[i] = '\0';

	length = strlen_custom(str);
	if (length) 
		printf("length of the string: %lu\n", length);

	free(str);
	return 0;
}


