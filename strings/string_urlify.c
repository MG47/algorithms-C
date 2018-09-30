/*
* Program to format string into URL format
* e.g "Mr John Smith" -> "Mr%20John%20Smith"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_urlify(char *str)
{
	int len, space_count;
	char *temp_str, *temp, *src;
	if (!str)
		return -1;

	len = 0;
	space_count = 0;
	while (str[len]) {
		if (str[len] == ' ')
			space_count++;
		len++;
	}
	len--;

	temp_str = malloc(sizeof(char) * (len + space_count * 2));
	if (!temp_str)
		exit(EXIT_FAILURE);

	temp = temp_str;
	src = str;

	while (*str) {
		if (*str == ' ') {
			*temp_str++ = '%';
			*temp_str++ = '2';
			*temp_str++ = '0';
			str++;
		}
		*temp_str++ = *str++;
	}

	*(temp_str + 1) = '\0';
	strcpy(src, temp);
	free(temp);
	return 0;
}

int main()
{
	int err, i, len;
	char *str, c;

	len = 200;
	i = 0;
	str = malloc(sizeof(char) * len);
	printf("Enter a string\n");
	while((c = fgetc(stdin)) != '\n')
		str[i++] = c;
	str[i] = '\0';
	err = string_urlify(str);
	if (!err)
		printf("URLified string: %s\n", str);

	free(str);
	return 0;
}


