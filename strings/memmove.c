/* 
* Program to copy memory area
* Memory areas may overlap
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void *memmove_custom(void *dest, void *src, size_t n)
{
	/* Typecast void ptr to char */
	unsigned char *source, *dst, *temp;
	int i = 0;

	source = src;
	dst = dest;

	if (!source || !dst)
		return NULL;

	if (source == dst)
		return dst;

	temp = malloc(sizeof(char) * n);
	if (!temp)
		exit(EXIT_FAILURE);

	for (i = 0; i < n; i++)
		temp[i] = source[i];

	for (i = 0; i < n; i++)
		dst[i] = temp[i];

	free(temp);
	return dest;
}

int main()
{
	int *num1, *num2;
	int i, size = 20;

	num1 = malloc(2 * size * sizeof(int));
	if (!num1)
		exit(EXIT_FAILURE);

	for (i = 0; i < size; i++) 
		num1[i] = i;

	num2 = &num1[4];

	num2 = memmove_custom(num2, num1, size * sizeof(int));
	for (i = 0; i < size; i++) 
		printf("num2[%d] : %d\n", i, num1[i]);

	return 0;
}


