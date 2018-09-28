/* 
* Program to convert string (Null-terminated) to integer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

int64_t atoi_custom(char *str)
{
	int64_t num = 0;
	int8_t sign = 1;

	if (*str == '-') {
		sign = -1;
		str++;
	}

	while (*str) {	
		if (*str >= '0' && *str <= '9') {
			/* Check for overflow */
			int64_t temp = num * 10 + (*str - '0');
			if (temp < num)
				return 0;
			else
				num = temp;
		} else {
			return -1;
		}
		str++;
	}
	return sign * num;
}

int main()
{
	char *str;
	str = calloc(100, sizeof(char));
	scanf("%s", str);
	int64_t num = atoi_custom(str);

	printf("Number: %ld\n", num);
	free(str);
	return 0;
}

