/* 
* Program to convert integer (base 10) to string (Null-terminated)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strrev(char *str)
{
	int i, j;
	char ch;

	i = strlen(str) - 1;
	j = 0;

	while (i > j) {
		ch = str[i];
		str[i]= str[j];
		str[j] = ch;
		i--;
		j++;
	}
	return str;
}

char *itoa_custom(int64_t num)
{	
	int8_t sign = 1, dec, i;
	char *str = malloc(sizeof(char) * 20);
	if (!str)
		exit(EXIT_FAILURE);

	if (!num) {
		str[0] = '0';
		return str;
	}

	if (num < 0) {
		str[0] = '-';
		sign = -1;
		num *= sign;
	}

	i = 0;
	while (num) {
		dec = num % 10;
		str[i++] = dec + '0';
		num /= 10;
	}

	if (sign < 0) 
		str[i] = '-';

	strrev(str);
	return str;
}

int main()
{
	int64_t num;
	char *str;
	printf("Enter number\n");
	scanf("%ld", &num);

	str = itoa_custom(num);
	if (*str)
		printf("Input number %ld\nString: %s\n", num, str);

	return 0;
}


