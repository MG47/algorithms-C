/*
* Program to check if a string2 is anagram of string1
* TODO : another approach: sort two strings and do strcmp
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int is_anagram(char *str1, char *str2)
{
	int *val1, *val2, len, i, ret;
	if (!str1 || !str2)
		return 0;
	
	/* Anagram strings: lengths of and frequencies of chars in two strings should match*/
	len = strlen(str1);
	if (strlen(str2) != len)
		return 0;

	val1 = calloc(256, sizeof(int));
	val2 = calloc(256, sizeof(int));
	if (!val1 || !val2)
		exit(EXIT_FAILURE);

	i = 0;
	while (i < len) {
		val1[str1[i]]++;
		val2[str2[i]]++;
		i++;
	}

	i = 0;
	ret = 0;
	while (i < len) {
		if (val1[str1[i]] != val2[str1[i]])
			goto free_exit;
		i++;
	}
	return 1;
free_exit:
	free(val1);
	free(val2);
	return ret;
}

int main()
{
	printf("Check if two strings are anagrams\n");
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
	ans = is_anagram(str1, str2);
	if (ans)
		printf("String are anagrams\n");
	else
		printf("String are not anagrams\n");	

	return 0;
}

