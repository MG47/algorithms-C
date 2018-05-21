/*
* Program to split strings into tokens
* INCOMPLETE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

char *strtok_r_custom(char *str, const char *delim, char **saveptr)
{
	int pos, i;
	char *s;
	if (saveptr && ((*saveptr)!= str))
		s = *saveptr;
	else 
		s = str;

	pos = 0;
	while (s[pos]) {
		i = 0;
		while (delim[i]) {
			if (delim[i] == s[pos]) {
				s[pos] = '\0';
				*saveptr = &s[pos + 1];
				return s;
			}
			i++;
		}
		pos++;
	}
	return NULL;
}

char *strtok_custom(char *str, const char *delim)
{
	static char *s;
	static int pos;
	int i, start;

	if (str)
		s = str;

	start = pos;

	while (s[pos]) {

		i = 0;
		while (delim[i]) {
				if (s[pos] == delim[i]) {
					s[pos] = '\0';
					pos++;

					if (s[start] != '\0') {
						return (&s[start]);
					} else {
						start = pos;
						pos--;
						break;
					}
			}
			i++;
		}
		pos++;
	}

	if (s[start] == '\0')
		return NULL;
	else
		return &s[start];
}

int main()
{
	printf("Split string into tokens\n");
	char *str = NULL, *token, *saveptr;
	size_t len;

	char delim[6] = " ,!.-\n";

	if (getline(&str, &len, stdin) == -1) {
		printf("error \n");
	}

	token = strtok_custom(str, delim);
	while (token) {
		printf("%s\n", token);
		token = strtok_custom(NULL, delim);
	}

	saveptr = str;
	while (token = strtok_r_custom(str, delim, &saveptr)) {
		printf("%s\n", token);		
	}

	return 0;
}

