/*
* Program to convert a string to a long integer
* TODO : add support for octal
* INCOMPLETE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "ctype_custom.h"

long int strtol_custom(char *str, char **endptr, int base)
{
	int i, sign, num;

	i = 0;
	sign = 1;

	/* Skip leading whitespace characters */
	while (ISSPACE(str[i]))
		i++;

	/* Check sign */
	if (str[i] == '-') {
		sign = -1;
		i++;
	} else if (str[i] == '+') {
		i++;
	} 

	/* Check base */
	if (base == 16) {
		if (str[i] == '0' && (str[i+1] == 'x' || str[i+1] == 'X'))
			i += 2;
	} 

	num = 0;
	switch (base) {
	case 10:
		while (str[i]) {
			if (ISDIGIT(str[i])) {
				num = num * 10 + str[i++] - '0';
			} else {
				*endptr = &str[i];
				return num * sign;
			}
		}
		break;
	case 16:
		/* TODO */
		while (str[i]) {
			if (ISDIGIT(str[i])) {
				num = num * 16 + str[i] - '0';
			} else if (ISALPHA(str[i])) {
				if (str[i] >= 'A' && 'F')
					num = num * 16 + 'A' - 10;
				else 					
					num = num * 16 + 'a' - 10;
			}
			else {
				*endptr = &str[i];
				return num * sign;
			}
			i++;
		}
		break;		break;
	default:
		break;
	}
	*endptr = NULL;
	return num * sign;
}

int main()
{
	long int ret;
	size_t len;
	char *str = NULL, *endptr;
	char str2[] = "123hellomotto233";
	char str3[] = "0x123FF"; 

	printf("Convert a string to a long integer\n");

	if (getline(&str, &len, stdin) == -1) {
		printf("error \n");
	}

	printf("String 1 : %s\n", str);
	ret = strtol_custom(str, &endptr, 16);
	printf("String 1 int: %ld\n", ret);
	printf("String 1 first inv char: %s\n", endptr);
#if 0
	printf("String 2 : %s\n", str2);
	ret = strtol_custom(str2, &endptr, 10);
	printf("String 2 int: %ld\n", ret);
	printf("String 2 first str: %s\n", endptr);

	printf("String 3 : %s\n", str3);
	ret = strtol_custom(str3, &endptr, 10);
	printf("String 3 int: %ld\n", ret);
	printf("String 3 first str: %s\n", endptr);
#endif
	return 0;
}

