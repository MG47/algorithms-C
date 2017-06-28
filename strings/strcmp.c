/* 
* Program to compare two strings
* Return value < 0 => str1 is less than str2.
* Return value > 0 => str2 is less than str1.
* Return value = 0 => str1 is equal to str2.
*/

#include <stdio.h>
#include <stdlib.h>

int strcmp_custom(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2)) 
		++str1, ++str2;

	return ((*str1 > *str2) - (*str2  > *str1));
}

int main()
{
	char *str1 = NULL, *str2 = NULL;
	size_t len;
	len = 50;
	str1 = malloc(sizeof(char) * len);
	str2 = malloc(sizeof(char) * len);
	if (!str1 || !str2)
		exit(EXIT_FAILURE);

	char c;
	int i = 0, ans;
	/* To avoid reading newline char */
	while((c = fgetc(stdin)) != '\n')
		str1[i++] = c;

	i = 0;
	while((c = fgetc(stdin)) != '\n')
		str2[i++] = c;

	ans = strcmp_custom(str1, str2);
	if (!ans)
		printf("Strings are equal\n");
	else if (ans == 1) 
		printf("String 1 is greater than string 2\n");
	else
		printf("String 2 is greater than string 1\n");

	return 0;
}


