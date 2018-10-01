/*
* Program to check if two strings are one edit away
* 'hello' -> 'helo' ; 'what' -> 'wgat'
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*
*  return 0 -> strings are the same
*  return 1 -> strings are one edit away
*  return other -> strings are different
*/
int check_one_edit_away(char *str1, char *str2)
{
	int len1, len2;
	int different_count;
	if (!str1 || !str2)
		return 1;

	different_count = 0;
	len1 = strlen(str1);
	len2 = strlen(str2);

	/* If lengths are the same, just compare
	count of different characters, 	if len diff is one,
	check if shorter string is one char away
	*/
	if ((len2 == len1)) {
		while (*str1 && *str2) {
			if (!(*str1 == *str2)) {
				if (different_count)
					return -1;
				different_count++;
			}
			str1++;
			str2++;
		}
	} else if ((len1 - len2) == 1 || (len1 - len2) == -1) {
		while (*str1 && *str2) {
			if (*str1 != *str2) {
				if (different_count)
					return -1;
				different_count++;
			}
			str1++;
			str2++;
		}
	} else {
		different_count = -1;
	}
	return different_count;
}

int main()
{
	printf("Check if two strings are one edit away\n");
	char *str1 = NULL, *str2 = NULL;
	size_t len;

	printf("Enter string 1\n");

	if (getline(&str1, &len, stdin) == -1) {
		printf("error: %s\n", strerror(errno));
	}

	printf("Enter string 1\n");

	if (getline(&str2, &len, stdin) == -1) {
		printf("error: %s\n", strerror(errno));
	}

	int ans = 0;
	ans = check_one_edit_away(str1, str2);
	if (!ans)
		printf("Strings are identical\n");
	else if (ans == 1)
		printf("Strings are just one edit apart\n");
	else
		printf("Strings are different\n");

	return 0;
}

