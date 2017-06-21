/*
* Program to insert/remove characters in a string
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* Insert a character at given index */
void insert_char_at(char *str, int index, char ch)
{
	int len, i;
	if (!str)
		return;
	
	len = strlen(str);

	i = 0;
	for (i = len; i > index; i--)
		str[i] = str[i - 1];

	str[i] = ch;
	str[len] = '\0';
}

/* Removes all occurences of a character */
void remove_char(char *str, char ch)
{
	int len, i, j;
	if (!str)
		return;

	len = strlen(str);
	i = 0;

	while (i < len) {
		if (str[i] == ch) {
			for (j = i; j < len; j++)
				str[j] = str[j + 1];
			len--;
			i--;			
		}
		i++;
	}
}

/* Remove character at given index */
void remove_char_at(char *str, int index)
{
	int i, len;
	if (!str)
		return;

	len = strlen(str);
	
	for (i = index; i <= len; i++)
		str[i] = str[i + 1];
}

int main()
{
	char *str = NULL;
	size_t len;
	printf("Enter string \n");

	if (getline(&str, &len, stdin) == -1) {
		printf("error: %s\n", strerror(errno));
	}

	insert_char_at(str, 2, 'i');
	remove_char_at(str, 1);
	remove_char(str, 'l');

	printf("new string: %s\n", str);

	return 0;
}

