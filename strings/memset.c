/* 
* Program to fill memory with a constant byte
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void *memset_custom(void *src, int byte, size_t n)
{
	unsigned char *str = src;
	if (!src)
		return NULL;
	while (n--) {
		*str = byte;
		str++;
	}
	return src;
}

int main()
{
	char *num_ptr;
	int *num, i, size = 20;
	char byte = 12;

	num = malloc(size * sizeof(int));
	if (!num)
		exit(EXIT_FAILURE);

	num_ptr = memset_custom(num, byte, size);
	for (i = 0; i < size; i++) 
		printf("num[%d] : %d\n", i, num_ptr[i]);

	return 0;
}


