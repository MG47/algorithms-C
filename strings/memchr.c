/* 
* Program to search for the first occurrence of the character c 
* (an unsigned char) in the first n bytes of the string pointed to, by the argument str.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void *memchr_custom(void *mem, int c, size_t n)
{
	unsigned char *src = mem;
	if (!mem)
		return NULL;
	
	while (n--) {
		if (*src == c)
			return src;
		src++;
	}
	return NULL;
}

int main()
{
	unsigned char c, *ptr = NULL;
	int64_t *num;
	int i;
	num = calloc(10, sizeof(int64_t));
	if (!num)
		exit(EXIT_FAILURE);

	for (i = 0; i < 10; i++)
		num[i] = i;

	c = 2;

	ptr = memchr_custom(0, c, 10 * sizeof(int));
	if (ptr) {
		printf("start address %p\n", num);
		printf("Found byte %d at address %p\n", *ptr, ptr);
		printf("Offset %ld\n", ((int64_t)ptr - (int64_t)num));
	}

	return 0;
}


