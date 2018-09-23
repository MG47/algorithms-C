/*
* Program to check if string2 is rotation of string1
* Example: 'aterw' is rotation of 'water'
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_rotation(char *str1, char *str2)
{
	int len1, len2;
	char *temp, *ret;
	if (!str1 || !str2)
		return 0;

	len1 = strlen(str1);
	len2 = strlen(str2);

	if (len1 != len2 || !len1)
		return 0;

	temp = malloc(sizeof(char) * ((len1 * 2) + 1));
	if (!temp)
		exit(EXIT_FAILURE);
	temp[0] = '\0';

	strcat(temp, str1);
	strcat(temp, str1);

	ret = strstr(temp, str2);
	free(temp);

	if (!ret)
		return 0;
	return 1;
}

int main()
{
	char *str1, *str2;
	size_t len;
	int i, ans;
	char c;

	i = 0;
	len = 20;
	str1 = malloc(sizeof(char) * len);
	str2 = malloc(sizeof(char) * len);
	if (!str1 || !str2)
		exit(EXIT_FAILURE);

	printf("Enter string 1\n");
	while((c = fgetc(stdin)) != '\n' && i < 20)
		str1[i++] = c;

	i = 0;
	printf("Enter string 2\n");
	while((c = fgetc(stdin)) != '\n'  && i < 20)
		str2[i++] = c;

	ans = check_rotation(str1, str2);
	if (ans)
		printf("String 2 is rotation of string 1\n");
	else
		printf("String 2 is not rotation of string 1\n");	

	return 0;
}

