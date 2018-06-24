
#include <stdio.h>

#define NO_OF_BITS(type) (sizeof(type) * 8)

struct date_regular {
	unsigned int day; 	//4 bytes
	unsigned int month; 	//4 bytes
	unsigned int year; 	//4 bytes
};

struct date_bit_field {
	unsigned int day: 5; 	// max 31 days, 1byte
	unsigned int month: 4; 	// max 12 months, 1 byte
	unsigned int year; 	// 4 bytes
};

void test_bitmasks()
{
	// Test enabling bits (flags) 3 & 5 and disabling bits 4 & 0
	// To enable
	#define FEATURE_1_FLAG (1 << 0)
	#define FEATURE_3_FLAG (1 << 4)
	// To disable
	#define FEATURE_2_FLAG (1 << 3)
	#define FEATURE_4_FLAG (1 << 5)

	int config = 0;
	printf("Config  = %d\n", config); 

	config = FEATURE_4_FLAG | FEATURE_2_FLAG & ~FEATURE_3_FLAG & ~FEATURE_1_FLAG;

	printf("Config  = %d\n", config); //  00..0010 1000, dec 40

}

void test_bit_fields()
{
	struct date_regular dr;
	struct date_bit_field db;

	dr.day = 1; 	
	dr.month = 2;
	dr.year = 2018;

	db.day = 1;
	db.month = 2;
	db.year = 2018;

	printf("Sizeof date_regular: %lu\n", sizeof(dr));
	printf("Sizeof date_bit_field: %lu\n", sizeof(db));
}

void test_set_substring_bits()
{
	int num, sub, ans, pos_l, pos_r, clear_mask;

	num = 0x2451; 	//10010001010001
	sub = 0x5; 	//101
	pos_l = 6; 	// ans = 10010011110001 (0x24f1)
	pos_r = 8;

	ans = num;

	clear_mask = (~0 << (pos_l + 1)) | ((1 << pos_r) - 1);

	ans &= clear_mask;
	ans |= (sub << (pos_l - 1));

	printf("Original no = 0x%x\n", num);
	printf("substring = 0x%x\n", sub);
	printf("lpos = %d\n", pos_l);
	printf("no with substring bits = 0x%x\n", ans);
}


void test_get_value()
{
	// INCOMPLETE
	int lpos, rpos, num, val;

	num = 0x345;	// dec 837, bin 0011 0100 0101
	lpos = 6;
	rpos = 3; 		// bits 3 - 6 : 1000, val = 8
					// bits 6 - 9 : 1101, val = 13

	printf("num = 0x%x\n", num);

	val = (1 << lpos - 1) & (~(~0 << rpos));
	val >>= rpos;

	printf("value = %d\n", val);

}

void test_get_k_bits()
{
	int num, k, lpos, extr;

	num = 0xE5B;  // 111001011011, ans = 1011 (0xB)
	k = 4;
	lpos = 3;

	extr = ((1 << k) - 1) & (num >> lpos);

	printf("Original no = %x\n", num);
	printf("extracted no = %x\n", extr);
}

void test_no_of_flip_bits_to_convert_a_to_b()
{

}

void test_find_bit_pattern_count()
{
	int num, count, pattern, i;

	num = 0x52B4; //101001010110100
	pattern = 0x5; // 101, count = 4

	printf("Original no = %x\n", num);
	printf("Pattern = %x\n", pattern);

	i = 0;
	count = 0;

	while (i++ < NO_OF_BITS(num)) {
		if ((num & pattern) == pattern)
			count++;
		num >>= 1;
	}

	printf("count of pattrn no = %d\n", count);

}

void test_swap_two_bits_xor_swap()
{
	int b1_pos, b2_pos, num;

	num = 0x4234; //100001000110100 , after swap: 100001001100100 (0x4264)
	b1_pos = 4; // bit 4 -> 1
	b2_pos = 6; // bit 6 -> 0

	printf("Original no = %x\n", num);

	if (((num >> b1_pos & 1) ^ (num >> b2_pos & 1))) {
		num ^= (1 << b1_pos);
		num ^= (1 << b2_pos);
	}

	printf("Swapped no = %x\n", num);
}

void test_swap_two_bits()
{
	int b1_pos, b2_pos, num, b1, b2;

	num = 0x4234; //100001000110100 , after swap: 100001001100100 (0x4264)
	b1_pos = 4; // bit 4 -> 1
	b2_pos = 6; // bit 6 -> 0


	printf("Original no = %x\n", num);

	b1 = num >> b1_pos & 1;
	b2 = num >> b2_pos & 1;

	num &= ~(1 << b1_pos);
	num &= ~(1 << b2_pos);

	num |= b1 << b2_pos;
	num |= b2 << b1_pos;

	printf("Swapped no = %x\n", num);
}

void test_swap_odd_even_bits()
{
	int num, swap_no;
	num = 0xAA; // 101010101, swap no  = 01010101(0x55)

	swap_no = (num & 0xAAAA) >> 1 | (num & 0x5555) << 1;

	printf("Original no = %x\n", num);
	printf("Swapped no = %x\n", swap_no);

}

void test_endianeness()
{
	int num;
	char *c;

	num = 1;

	c = (char *)&num;

	if (*c) {
		printf("System is little endian \n");
	} else {
		printf("System is big endian\n");
	}
}

void test_endianness_conversion()
{
	unsigned int num;
	unsigned int new_num;

	num = 0xAABBCCDD;

	// same for big to little and vice versa 
	new_num = ((num & 0xFF)  << 24) | ((num & 0xFF00) << 8) | ((num & 0xFF0000) >> 8) | ((num & 0xFF000000) >> 24 );
	printf("Original no = 0x%x\n", num);
	printf("new no = 0x%x\n", new_num);
}

void test_bit_reversal()
{
	unsigned int num = 11; 	// Hex = 0xA -> 0b1011, (reverse = 0b1101 -> hex 0xD00000...) 
	unsigned int rev, i = 0;

	rev = ~(~0);
	printf("Num dec = %d\n", num);
	printf("Num hex = %x\n", num);

	for (i = 0; i < NO_OF_BITS(num); i++) {
		if ((num & (1 << i)))
			rev |= 1 << ((NO_OF_BITS(num) - 1) - i);
	}

	printf("reverse hex = %x\n", rev);
	printf("reverse dec = %d\n", rev);
}

void test_NO_OF_BITS()
{
	int a[2];
	printf("No of bits in an int is %d, float is %d, double is %d,   int array is %d\n",  \
		(int)NO_OF_BITS(int), (int)NO_OF_BITS(float), (int)NO_OF_BITS(double), (int)NO_OF_BITS(a));
}

int main()
{
	printf("\nBit manipulation\n\n");


//	test_NO_OF_BITS();

//	test_bit_reversal();

//	test_endianness_conversion();

//	test_endianeness();

//	test_swap_odd_even_bits();

//	test_swap_two_bits();

//	test_swap_two_bits_xor_swap();

//	test_find_bit_pattern_count();

//	test_get_k_bits();

//	test_get_value();

//	test_set_substring_bits();

//	test_bit_fields();

	test_bitmasks();

	printf("\n\nExiting...\n\n");

	return 0;
}


