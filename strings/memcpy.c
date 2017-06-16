/* 
* Program to copy memory area
* Memory areas may not overlap
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void *memcpy_custom(void *dest, void *src, size_t n)
{
	unsigned char *source = src;
	unsigned char *dst = dest;
	while (n--)
		*dst++ = *source++;
	return dest;
}

int main()
{
	int *num1, *num2;
	int i, size = 10;

	num1 = calloc(size, sizeof(int));
	num2 = calloc(size, sizeof(int));

	if (!num1 || !num2)
		exit(EXIT_FAILURE);

	for (i = 0; i < size; i++) 
		num1[i] = i;

	num2 = memcpy_custom(num2, num1, size * sizeof(int));
	for (i = 0; i < size; i++) 
		printf("num2[%d] : %d\n", i, num1[i]);

	return 0;
}


