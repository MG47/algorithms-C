/*
* Program to check if a string is palindrome
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int is_palindrome(char *str1)
{
	int i, n;

	i = 0;
	while (str1[i])
		i++;

	n = i - 1;
	i = 0;
	while (i <= n / 2) {		
		if (str1[i] != str1[n - i - 1])
			return 0;
		i++;
	}
	return 1;
}

int main()
{
	printf("Check palindrome\n");
	char *str = NULL;
	size_t len;
	printf("Enter string \n");

	if (getline(&str, &len, stdin) == -1) {
		printf("error: %s\n", strerror(errno));
	}

	int ans = is_palindrome(str);
	if (ans)
		printf("string is a palindrome\n");
	else 
		printf("string is not a palindrome\n");
	return 0;
}

