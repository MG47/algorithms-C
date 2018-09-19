/*
* Memory management programs
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void test_aligned_malloc()
{
/*
	1-byte aligned -  2^0 - last bit can be 0/1  e.g 0x80000000, 0x80000001
	2-byte aligned - 2^1 last bit must be reset e.g 0x80000000, 0x80000002
	4-byte aligned - 2^2 last 2 bits must be reset e.g 0x80000000, 0x80000004
	8-byte aligned - 2^3 - last 3 bits must be reset   e.g 0x80000000, 0x80000008
	16-byte aligned - 2^4 - last 4 bits must be reset e.g 0x80000000, 0x80000010
*/

	unsigned int bytes_to_alloc;
	unsigned int alignment;
	void *addr;
	void *aligned_ptr;	

	bytes_to_alloc = 109;
	alignment  = 8;

	/* Do normal malloc to get unaligned pointer 
	Allocate alignment - 1 extra bytes */
	addr = malloc(bytes_to_alloc + (alignment -1));
	if (!addr)
		return;

	/* TO force unaligned address as an example */
	addr = (uintptr_t)addr + (uintptr_t)3;

	printf("Address before %d byte alignment : %p\n", alignment, addr);

	aligned_ptr = ((uintptr_t)addr + (alignment - 1)) & ~(uintptr_t)((alignment - 1));

	printf("aligned address %p\n\n", aligned_ptr);
}

void test_round_no_to_n_bits()
{
        int num, n;

	num = 37; // 0b100101
	n = 8;

        printf("Number before rounding to %d bytes : %d\n", n, num);

	num &= (~(n - 1));

        printf("Number after rounding : %d\n\n", num);
}

void test_get_aligned_value()
{
	unsigned int page_size; 
	unsigned int address;
	unsigned int aligned_address;

	page_size = (4 * 1024);
	address = 12622;

	aligned_address = (address / page_size) * page_size;

	printf("Page size: %u\n", page_size);
	printf("Address to align: %u\n", address);
	printf("Nearest page-aligned value is %u\n\n", aligned_address);
}

int main()
{
	test_get_aligned_value();

	test_round_no_to_n_bits();

	test_aligned_malloc();


        return 0;
}

