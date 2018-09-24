/*
* Program to find out most frequently occuring character in a string 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ASCII_SIZE 256

char most_frequent_char(char *str)
{
	char *val, maxchar;
	int max;

	if (!str || (*str) == '\n')
		return 0;

	val = calloc(ASCII_SIZE, sizeof(char));
	if (!val)
		exit(EXIT_FAILURE);

	max = 0;
	while (*str) {
		val[*str]++;
		if (val[*str] > max) {
			maxchar = *str;
			max = val[*str];
		}
		str++;
	}
	free(val);
	return maxchar;
}

int main()
{
	char *str = NULL;
	size_t len;

	printf("Enter string\n");

	if (getline(&str, &len, stdin) == -1) {
		printf("error: %s\n", strerror(errno));
	}

	char ans = 0;
	ans = most_frequent_char(str);
	if (ans)
		printf("Most frequent character: %c\n", ans);
	else
		printf("String is empty\n");	

	return 0;
}

