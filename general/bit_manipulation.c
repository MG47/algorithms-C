/*
* Bit Manipulation
*/


#include <stdio.h>

#define NO_OF_BITS(type) (sizeof(type) * 8)

void test_alternating_bits()
{

#define EVEN_ALTERNATE_MASK 0xAAAAAAAA
#define ODD_ALTERNATE_MASK 0x55555555

	int ans = 0;
	unsigned int num = 0xAAAAAAAA; // 0101 0101 ...

	ans |= !(num ^ EVEN_ALTERNATE_MASK);
	ans |= !(num ^ ODD_ALTERNATE_MASK);

	if (ans)
		printf("num 0x%x has alternating bits\n", num);
	else
		printf("num 0x%x does not have alternating bits\n", num);
}

void test_highest_power_2_less_equal_to_n()
{
	// highest power less than/equal to num e.g num = 25 => 16
	// num = 16 -> 16

	// Approach: find the leftmost set bit position
	// and just keep that set bit (reset other bits)
	unsigned int num = 25;

	int pos = 0;
	unsigned int n = num;
	while (n) {
		n >>= 1;
		pos++;
	}

	unsigned int pow = (pos == 0) ? num : (1 << (pos - 1));

	printf("highest power of 2 less than equal to %u is %u\n", num, pow);

	return;
}

void test_shifts()
{
	printf("Testing shifts...\n\n");
	unsigned int un;

	un = 0x403; // 0100 0000 0011, l.s ans 1000 0000 0110 (0x806), r.s 0010 0000 0001 (0x201)

	/* Test logical left and right shift */
	printf("unsigned num (%u) left shift by 1 = %x\n", un, un << 1);
	printf("unsigned num (%u) right shift by 1 = %u\n\n", un, un >> 1);

	un = (1 << 31);
	/* Test logical left and right shift */
	printf("unsigned num (%u) left shift by 1 = %x\n", un, un << 1);
	printf("unsigned num (%u) right shift by 1 = %u\n\n", un, un >> 1);

	/* Test arithmetic left & right shift */
	int sn = -1; // 0xFFFFFFFF

	printf("signed num (%d) left shift by 1 = %d\n", sn, sn << 1);
	printf("signed num (%d) right shift by 1 = %d\n\n", sn, sn >> 2);

	sn = ~(1 << 30);

	printf("signed num (%d) left shift by 1 = %d\n", sn, sn << 1);
	printf("signed num (%d) right shift by 1 = %d\n", sn, sn >> 1);

	return;
}

/*
* Given an integer, prints the next smallest and next
* largest number that have the same
* number of 1 bits in their binary representation.
* e.g 3 (011) higher -> 5 (101); 13 (1101) -> lower 11 (1011)
* explanation: https://www.slideshare.net/gkumar007/bits-next-higher-presentation
*/
void test_next_high_low_no_with_same_no_of_ones()
{

	//TODO
	unsigned int num = 0x4533; // 0100 0101 0011 0011
			  // next highest with ones:
			  // next lowest with ones:

/* Steps:
	1) Starting from left.. find successive zeros
		0100 0101 0011 0011  --> ... 0011 "00"11

	2) find successive 1's follwed by zeros found in 1)
		0100 0101 0011 0011  --> ... 00"11" 0011

	3) find immidiate 0 follwed by by ones found in 2)
		0100 0101 0011 0011  --> ... 0"0"11 0011
	4) Swap 0 <-> immidiate (leftmost) one from 2)
		0100 0101 0011 0011  --> ... 0"1""0"1 0011
	5) Move the remaining ones from 2) to extreme right
		0100 0101 0011 0011  --> ... 0100 0111
*/
	num & (-num);




}

/* TODO */
/*
* Give an integer n, where we can flip exactly one bit,
* write code to find the length of the longest sequence of ones you could create.
*/
void test_find_longest_sequence_of_ones_flip_one()
{
#if 0
	int currentLength = a;
	int previous Length = a;
	int maxLength = 1;
	while (a != a) {
		if «a & 1) == 1) {
			currentLength++;
		} else if a & 1) == B) {
			previous Length = (a & 2) == a ? a : currentLength;
			current Length = a;
		}
		maxLength = Math.max(previousLength + current Length + I, maxLength);
		a >>> = 1;
	}
#endif
}

/*
* Algorithm: If we AND a bit with shifted version of itself,
* we remove one 1 from a sequence of 1s - after some shifts, num = 0
* the number of times the loop runs to remove all ones from longest
* sequence is the count of longest consecutive ones
* Do left shift to avoid arithmetic one-MSBs
*/
void test_find_longest_sequence_of_ones()
{
	int max_count;
	unsigned int num = 0xBF13; // 1011 1111 0001 0011

	max_count = 0;
	while (num) {
		num &= (num << 1);
		max_count++;
	}
	printf("Longest sequence of ones is %d\n", max_count);
}

void test_is_power_of_two()
{
	/* Power of 2 has only one '1' bit so (num & num - 1) should be zero */
	int num_A = 512; 	// power of 2
	int num_B = 513;	// not power of 2

	if (!(num_A & (num_A - 1)))
		printf("num_A is a power of two");

	if (!(num_B & (num_A - 1)))
		printf("num_B is a power of two\n");

}

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

	config = FEATURE_4_FLAG | (FEATURE_2_FLAG & ~FEATURE_3_FLAG & ~FEATURE_1_FLAG);

	printf("Config  = %d\n", config); //  00..0010 1000, dec 40

}

struct date_regular {
	unsigned int day; 	//4 bytes
	unsigned int month; 	//4 bytes
	unsigned int year; 	//4 bytes
} __attribute__((packed));

struct date_bit_field {
	unsigned int day: 5; 	// max 31 days, 1byte
	unsigned int month: 4; 	// max 12 months, 1 byte
	unsigned int year; 	// 4 bytes
} __attribute__((packed));

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
	int hbit, lbit, num, val;

	num = 0x345;	// dec 837, bin 0011 0100 0101
	// bits 3 - 6 : 1000, val = 8
	// bits 6 - 9 : 1101, val = 13
	hbit = 6;
	lbit = 3;

	printf("num = 0x%x\n", num);
	val = ((num >>lbit) & (~(~0<<(hbit-lbit+1))));

	/* Alternative approach */
//	val = ((num & ((1 << hbit) - 1)) | (num & (~((1 << lbit) - 1))) ) >> lbit;

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

void test_no_of_bits_to_convert_a_to_b()
{
	int temp, count;
	int num_A = 0x5DC1; // 0101 1101 1100 0001
	int num_B = 0xA412; // 0100 0100 0001 0010, 8 bits to convert it to num_A

	count = 0;
	temp = num_A ^ num_B;
	while (temp) {
		temp &= (temp - 1);
		count++;
	}

	printf("No of bis to convert %d to %d is %d\n", num_A, num_B, count);
}

void test_count_no_of_ones()
{
	int count;
	int num = 0xDF10; // 1101 1111 0001 0000 -> 7 ones

	count = 0;
	while (num) {
		num = num & (num - 1);
		count++;
	}

	printf("No of ones in %d is %d\n", num, count);
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

	/* check if two bits are different in the first place
	* flip the bits if they are different - equivalent to swapping */
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


#define EVEN_MASK 0xAAAA
#define ODD_MASK 0x5555
void test_swap_odd_even_bits()
{
	int num, swap_no;
	num = 0xAA; // 101010101, swap no  = 01010101(0x55)

	swap_no = (num & EVEN_MASK) >> 1 | (num & ODD_MASK) << 1;

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

	rev = 0;
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

void test_basic_bit_manipulation()
{
	unsigned int num, no;
	int pos;

	num = 0x5123; // 0b 0101 0001 0010 0011

	/* Set bit */
	pos = 4;
	no = num;
	printf("\nTest : Set bit %d of num 0x%x\n", pos, no);
	no |= (1 << pos); 	// should be 0x5133
	printf("New num : 0x%x\n", no);

	/* Reset bit */
	pos = 8;
	no = num;
	printf("\nTest : Reset bit %d of num 0x%x\n", pos, no);
	no &= ~(1 << pos); 	// should be 0x5023
	printf("New num : 0x%x\n", no);

	/* Toggle bit */
	pos = 3;
	no = num;
	printf("\nTest : Toggle bit %d of num 0x%x\n", pos, no);
	no ^= (1 << pos); 	// should be 0x502b
	printf("New num : 0x%x\n", no);

	/* Test bit */
	pos = 12;
	no = num;
	printf("\nTest : Test bit %d of num 0x%x\n", pos, no);
	no = no & (1 << pos); 	 // should be true for bit 12
	printf("num : bit %d is %s\n", pos, (no ? "SET": "RESET"));

	/* Check even or odd */
	no = num;
	printf("\nTest : Check if num 0x%x is even or odd\n", no);
	no = no & 1; 		 // should be ODD
	printf("num is %s\n", (no ? "ODD": "EVEN"));

	/* Update bit */
	pos = 10;
	int new_bit = 1;
	no = num;
	printf("\nTest : Update bit %d with new bit %d of 0x%x\n", pos, new_bit, no);
	no = (no & ~(1 << pos)) | (new_bit << pos); // should be 0x5123
	printf("New num 0x%x\n", no);

	/* Turn off rightmost 1 bit */
	no = num;
	printf("\nTest : Turn off righmost bit of 0x%x\n", no);
	no = no & (no - 1); // should be 0x5122
	printf("New num 0x%x\n", no);

	/* Turn on rightmost 0 bit */
	no = num;
	printf("\nTest : Turn on righmost bit of 0x%x\n", no);
	no = no | (no + 1); // should be 0x5127
	printf("New num 0x%x\n", no);

	/* Test Muliply / Div by power of 2 */
	no = num;
	printf("\nNo 0x%x multipled by 4 (2*2) is 0x%x\n", no, no << 2);
	printf("\nNo 0x%x divided by 4 (2*2) is 0x%x\n", no, no >> 2);

	/* Isolate rightmost 1-bit */
	no = num;
	printf("\nTest : Isolate righmost 1 bit of 0x%x\n", no);
	no = no & (-no); // should be 0x5127
	printf("New num 0x%x\n", no);

	/* Isolate rightmost 1-bit */
	no = 0x1240; // 0001 0010 0100 0000
	printf("\nTest : Isolate righmost 1 bit of 0x%x\n", no);
	no = no & (-no); // should be 0x40
	printf("New num 0x%x\n", no);

	/* Isolate rightmost 0-bit */
	no = 0x1241; // 0001 0010 0100 0001 // bit 1 should be isolated: 0x1
	printf("\nTest : Isolate righmost 0 bit of 0x%x\n", no);
	no = ~no & (no + 1); // should be 0x1
	printf("New num 0x%x\n", no);

	/* Right-propagate rightmost 1-bit */
	no = 0x1240; // 0001 0010 0100 0000
	printf("\nTest : Right-propagate rightmost 1 bit of 0x%x\n", no);
	no = no | (no - 1); // should be 0x127F: 0001 0010 0111 1111
	printf("New num 0x%x\n", no);
}

int main()
{
	printf("\nBit manipulation\n\n");

//	test_basic_bit_manipulation();

//	test_NO_OF_BITS();

//	test_bit_reversal();

//	test_endianness_conversion();

//	test_endianeness();

//	test_swap_odd_even_bits();

//	test_swap_two_bits();

//	test_swap_two_bits_xor_swap();

//	test_find_bit_pattern_count();

//	test_count_no_of_ones();

//	test_no_of_bits_to_convert_a_to_b();

//	test_get_k_bits();

//	test_get_value();

//	test_set_substring_bits();

//	test_bit_fields();

//	test_bitmasks();

//	test_is_power_of_two();

//	test_find_longest_sequence_of_ones();

	//TODO
//	test_next_high_low_no_with_same_no_of_ones();

//	test_shifts();

	test_alternating_bits();

	printf("\n\nExiting...\n\n");

	return 0;
}


