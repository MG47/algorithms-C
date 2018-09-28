/* 
* Program to reverse a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *strrev_custom(char *str)
{
	int i = 0, j, len = 0;

	if (!str)
		return NULL;

	while (str[i++])
		len++;

	i = 0;
	j = len - 1;
	while (i < j) {
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return str;
}

int main()
{
	char c, *str;
	size_t len;

	int i = 0;
	len = 50;
	str = malloc(sizeof(char) * len);
	if (!str)
		exit(EXIT_FAILURE);

	printf("Enter a string\n");
	while((c = fgetc(stdin)) != '\n')
		str[i++] = c;

	strrev_custom(str);
	if (str)
		printf("Reversed String: %s \n", str);

	return 0;
}


