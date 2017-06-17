/* 
* Program to compare the first n bytes (each interpreted as
* unsigned char) of the memory areas s1 and s2
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int memcmp_custom(void *s1, void *s2, size_t n)
{
	unsigned char *src1, *src2;
	while (n--) {
		src1 = s1;
		src2 = s2;
		if (*src1 != *src2)
			return (*src1 - *src2);
		s1++;
		s2++;
	}
	return 0;
}

int main()
{
	int *num1, *num2;
	int i, size = 10, diff;

	num1 = calloc(size, sizeof(int));
	num2 = calloc(size, sizeof(int));

	if (!num1 || !num2)
		exit(EXIT_FAILURE);

	for (i = 0; i < size; i++) {
		num1[i] = i;
		num2[i] = i;
 	}
	num2[5] = 121;

	diff = memcmp_custom(num1, num2, size * sizeof(int));
	if (diff) {
		printf("Memory areas are different\n");
	}

	return 0;
}


