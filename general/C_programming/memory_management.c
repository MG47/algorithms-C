/*
* Memory management programs
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/* Custom malloc - Useful for memory tracking */
unsigned long long get_timestamp()
{
	return 0x12345678;
}

struct metadata {
	char func_name[32];
	unsigned long long timestamp;
};

void *custom_malloc(int size, char *func_name)
{
	void *ptr = malloc(size + sizeof(struct metadata));

	struct metadata *mt = ptr;
	strncpy(mt->func_name, func_name, 32);
	mt->timestamp = get_timestamp();

	printf("allocating size %d, for %s : meta %p, data: %p\n", size, func_name, ptr, mt + 1);

	return ((struct metadata *)ptr + 1);
}

void custom_free(void *ptr)
{
	struct metadata *mt = (struct metadata *)ptr - 1;
	printf("De-allocate called by %s (%llu) : meta: %p, data: %p\n", mt->func_name, mt->timestamp, mt, ptr);
	free(mt);
}

void test_custom_malloc()
{

	void *ptr = custom_malloc(1000, "test_custom_malloc");
	printf("Allocated memory %p\n", ptr);
	custom_free(ptr);
}

/* Aligned Malloc */
void test_aligned_malloc()
{
/*
	1-byte aligned -  2^0 - last bit can be 0/1  e.g 0x80000000, 0x80000001
	2-byte aligned - 2^1 last bit must be reset e.g 0x80000000, 0x80000002
	4-byte aligned - 2^2 last 2 bits must be reset e.g 0x80000000, 0x80000004
	8-byte aligned - 2^3 - last 3 bits must be reset   e.g 0x80000000, 0x80000008
	16-byte aligned - 2^4 - last 4 bits must be reset e.g 0x80000000, 0x80000010

	Steps:
	1) Call malloc with (size + (alignment - 1)) bytes e.g 100 bytes to allocate, 8byte
	    alignment: allocate 107 bytes
	2) Make sure to cast malloc'd pointer to uintptr_t : to perform bitwise and other
	    operations.
	3) To get the next aligned address:
	    (addr + (alignment - 1))) & ~(alignment - 1);
	    --> alignment - 1 for 8 bytes = 7 ==> 0111
	    (~alignment - 1) ===> 1000 // reset last 3 bits
*/

	unsigned int bytes_to_alloc;
	unsigned int alignment;
	void *addr;
	void *aligned_ptr;	

	bytes_to_alloc = 109;
	alignment  = 8;

	/* Do normal malloc to get unaligned pointer 
	Allocate alignment - 1 extra bytes */
	addr = malloc(bytes_to_alloc + (alignment - 1));
	if (!addr)
		return;

	/* To force unaligned address as an example */
	addr = (uintptr_t)addr + (uintptr_t)3;

	printf("Address before %d byte alignment : %p\n", alignment, addr);

	aligned_ptr = ((uintptr_t)addr + (alignment - 1)) & ~(uintptr_t)((alignment - 1));

	printf("aligned address %p\n\n", aligned_ptr);
}

void test_round_no_next_power_of_2()
{
	int count = 0;
	int round = 0;

	int num = 9; // round to 16
	while (num) {
		num >>= 1;
		count++;
	}
	round = 1 << count;
	printf("round %d to next power of 2  = %d\n", 9, round);

	count = 0;
	round = 0;
	num = 16; // round to 32;
	while (num) {
		num >>= 1;
		count++;
	}

	round = 1 << count;
	printf("round %d to next power of 2  = %d\n", 16, round);
}

void test_round_no_to_n_bytes()
{
	int num, n;

	num = 37; // 0b100101
	n = 8;

	printf("Number before rounding to %d bytes : %d\n", n, num);

	// for 8, (n - 1) = 7 ==> 1000
	// ~(n - 1) ==> 0111
	// Use & to reset last three bits
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

	test_round_no_to_n_bytes();

	test_round_no_next_power_of_2();

	test_aligned_malloc();

	test_custom_malloc();

	return 0;
}

