/*
* Program to perform a basic string compression
* using the counts of repeated characters.
* For example, the string aabcccccaaa would become a2b1c5a3.
* The string has only uppercase and lowercase letters (a - z).
* Modified Run-Length Encoding (RLE)
* TODO fix limitation of max 9 occurences
*/

#include <stdio.h>
#include <stdlib.h>

int compress_string(char *str)
{
	char *src;
	if (!str)
		return 0;

	for (src = str; *src; src++) {
		int count = 1;
		*str = *src;
		str++;

		while (src[0] == src[1]) {
			count++;
			src++;
		}

		if (count > 1) {
			*str = count + '0';
			str++;
		}
	}
	*str = '\0';
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
	err = compress_string(str);
	if (!err)
		printf("Compressed string: %s\n", str);

	free(str);
	return 0;
}


