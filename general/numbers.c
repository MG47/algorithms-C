
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <string.h>

char *strrev_custom(char *str)
{
	int i = 0, j, len = 0;

	if (!str)
		return NULL;

	while (str[i++])
		len++;

	i = 0;
	j = len - 1;
	while (i < j) {
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return str;
}

void bin_to_hex()
{
	//NOTE: Simplification: leading 0s are added for 4-digit grouping
	char *bin = "000110100111";		// 0x1A7, dec 423
//	char *bin = "100110110111";		// 0x9B7, dec 2487
	char *hex;
	int i, j, num, base;

	printf("\nNumber in binary: %s\n", bin);
	hex = malloc(sizeof(char) * 10);
	if (!hex)
		return;

	i = 0;
	j = 0;
	num = 0;
	base = 8;
	while (bin[i]) {
		if (bin[i] - '0')
			num += (bin[i] - '0') * base;
		base /= 2;

		if (((i + 1) % 4) == 0) {
			hex[j] = num <= 9 ? (num + '0') : (num + 'A' - 10);
			j++;
			num = 0;
			base = 8;
		}
		i++;
	}
	printf("Number in hex: 0x%s\n", hex);
}

void hex_to_bin()
{
	char *hex = "A1FF";			// A1FF 1010 0001 1111 1111
//	char *hex = "D2C1";			// D2C1 1101 0010 1100 0001

	char *bin;
	int i, j, num;

	bin = malloc(sizeof(char) * 20);
	if (!bin)
		return;

	printf("\nNumber in hex: 0x%s\n", hex);

	i = 0;
	j = 0;
	while (hex[i]) {
		num = (hex[i] <= '9') ? (hex[i] - '0') : (hex[i] - ('A' - 10));
		while (j < 4) {
			bin[(i * 4) + (3 - j)] = (num % 2) + '0';
			num /= 2;
			j++;
		}
		j = 0;
		i++;
	}
	bin[i * 4 + 3] = '\0';
	printf("Number in binary: %s\n", bin);
}

void dec_to_hex()
{
	int num = 494;		// hex 1EE
	char *hex;
	int i;

	printf("\nNumber in decimal: %d\n", num);

	hex = malloc(sizeof(char) * 10);
	if (!hex)
		return;

	i = 0;
	while (num) {
		if ((num % 16) < 9)
			hex[i] = (num % 16) + '0';
		else
			hex[i] = (num % 16) + ('A' - 10);
		num /= 16;
		i++;
	}
	hex[i] = '\0';
	strrev_custom(hex);

	printf("Number in hex: 0x%s\n", hex);
}

void hex_to_dec()
{
	char *hex = "F12D";		// 0xF12D, dec 61741
	int num;
	int len, i, base;

	printf("\nNumber in hex: %s\n", hex);

	num = 0;
	len = 0;
	i = 0;
	while (hex[i++])
		len++;

	i = len - 1;
	base = 1;
	while (i >= 0) {
		if ((hex[i]) >= '0' && (hex[i]) <= '9')
			num += base * (hex[i] - '0');
		else if((hex[i] >= 'A') && (hex[i] <= 'F'))
			num += base * (hex[i] - 'A' + 10);
		else if((hex[i] >= 'a') && (hex[i] <= 'f'))
			num += base * (hex[i] - 'a' + 10);
		base *= 16;
		i--;
	}
	printf("Number in decimal: %d\n", num);
}

void dec_to_bin()
{
	int num = 103;		// bin 1100111
	char *bin;
	int i;

	printf("\nNumber in decimal: %d\n", num);

	bin = malloc(sizeof(char) * 20);
	if (!bin)
		return;

	i = 0;
	while (num) {
		bin[i] = (num % 2) + '0';
		num /= 2;
		i++;
	}
	bin[i] = '\0';
	strrev_custom(bin);

	printf("Number in binary: %s\n", bin);
}

void bin_to_dec()
{
	char *bin = "0100101";		// 0x25, dec 37
	int num;
	int len, i, base;

	printf("\nNumber in binary: %s\n", bin);

	num = 0;
	len = 0;
	i = 0;
	while (bin[i++])
		len++;

	i = len - 1;
	base = 1;
	while (i >= 0) {
		num += base * (bin[i] - '0');
		base *= 2;
		i--;
	}
	printf("Number in decimal: %d\n", num);
}

void test_do_conversions()
{
	bin_to_dec();
	dec_to_bin();

	hex_to_dec();
	dec_to_hex();

	bin_to_hex();
	hex_to_bin();
}

void test_swap_two_no_without_temp()
{
	int num1, num2;
	num1 = 10, num2 = 20;
	printf("\nBefore swap: num 1->%d and num 2->%d\n", num1, num2);

	num1 = num1 + num2;
	num2 = num1 - num2;
	num1 = num1 - num2;

	printf("After swap: num 1->%d and num 2->%d\n", num1, num2);

	num1 = num1 ^ num2;
	num2 = num1 ^ num2;
	num1 = num1 ^ num2;

	printf("After second swap: num 1->%d and num 2->%d\n", num1, num2);
}

/* TODO - Move the MACROS to more appropriate location */
#define SIZEOF_CUSTOM(var) (((size_t)(&(var) + 1) - (size_t)&(var)))

/* Why this works : https://en.wikipedia.org/wiki/Offsetof#Implementation */
#define OFFSETOF_CUSTOM(str_type, member) ((size_t)&(((str_type *)0)-> member))

#define SIZEOF_STRUCT(str) (((size_t)(&str + 1) - (size_t)(&str)))

#define SIZEOF_ARRAY(arr) (size_t)(sizeof(arr) / sizeof(int))

struct my_struct { 	// for 64bit Linux: 24bytes
	int a; 		// 4
	char b; 	// 1 + 3 padding
	long c; 	// 8
	double d; 	// 8
};

struct my_packed_struct { 	// for 64bit Linux: 21bytes
	int a; 			// 4
	char b; 		// 1
	long c; 		// 8
	double d; 		// 8
} __attribute__((packed));

void test_of_macros()
{
	struct my_struct mstr;
	struct my_packed_struct mpstr;

	int arr[12] = {0};

	/* ======================================================== */
	/* sizeof tests */
	printf("sizeof int a is %lu\n", SIZEOF_CUSTOM(mstr.a));
	printf("sizeof char b is %lu\n", SIZEOF_CUSTOM(mstr.b));
	printf("sizeof long c is %lu\n", SIZEOF_CUSTOM(mstr.c));
	printf("sizeof double d is %lu\n", SIZEOF_CUSTOM(mstr.d));

	/* ======================================================== */
	/* struct tests */

	/* offsetof tests */
	printf("\n\nUnpacked struct tests\n\n");

	printf("offsetof int a is %lu\n", OFFSETOF_CUSTOM(struct my_struct, a));
	printf("offsetof char b is %lu\n", OFFSETOF_CUSTOM(struct my_struct, b));
	printf("offsetof long c is %lu\n", OFFSETOF_CUSTOM(struct my_struct, c));
	printf("offsetof double d is %lu\n", OFFSETOF_CUSTOM(struct my_struct, d));

	/* sizeof struct test */
	printf("sizeof struct my_struct is %lu\n", SIZEOF_STRUCT(mstr));

	/* ======================================================== */
	/* Packed struct tests */
	/* offsetof tests */

	printf("\n\nPacked struct tests\n\n");
	printf("offsetof int a is %lu\n", OFFSETOF_CUSTOM(struct my_packed_struct, a));
	printf("offsetof char b is %lu\n", OFFSETOF_CUSTOM(struct my_packed_struct, b));
	printf("offsetof long c is %lu\n", OFFSETOF_CUSTOM(struct my_packed_struct, c));
	printf("offsetof double d is %lu\n", OFFSETOF_CUSTOM(struct my_packed_struct, d));

	/* sizeof struct test */
	printf("sizeof struct my_struct is %lu\n", SIZEOF_STRUCT(mpstr));

	/* ======================================================== */
	/* sizeof array (int) test */
	printf("\n\nsizeof array arr is %lu\n", SIZEOF_ARRAY(arr));
}

void test_round_floating_pt_no()
{
	float num;
	int no;

	/* -3.6 -> -4, 3.6 -> 4 */
	/* -3.2 -> -3, 3.2 -> 3 */
	num = 3.2;

	no = (num > 0) ? (int)(num + 0.5) : (int)(num - 0.5);
	printf("rounded num is %d", no);
}

void test_find_lcm()
{
	/* 6 & 7 -> lcm is 42 */
	/* 6 & 4 -> lcm is 12 */
	/* 18 & 9 -> lcm is 18 */

	int num1 = 6, num2 = 4;
	int lcm, n1, n2;

	n1 = num1;
	n2 = num2;

	while (n1 != n2)
		(n1 > n2) ? (n1 = n1 - n2) : (n2 = n2 - n1);

	lcm = num1 * num2 / n1;

	printf("LCM of %d and %d is %d\n", num1, num2, lcm); 
}

void test_find_gcd()
{
	/* 12 & 18 -> gcd is 6 */
	/* 20 & 23 -> gcd is 1 */
	/* 20 & 24 -> gcd is 4 */

	int num1 = 20, num2 = 24;
	int gcd, n1, n2;
	
	n1 = num1;
	n2 = num2;

	while (n1 != n2) 
		(n1 > n2) ? (n1 = n1 - n2) : (n2 = n2 - n1);
	gcd = n1;
	printf("GCD of %d and %d is %d\n", num1, num2, gcd); 
}

int fibonacci_recurse(int no)
{
	if (no <=1)
		return no;

	return fibonacci_recurse(no - 1) + fibonacci_recurse(no - 2);
}

void test_fibonacci_no()
{
	/* no = 3-> fib: 2*/
	/* no = 6-> fib: 8*/
	
	int no = 3, ans;
	
	ans = fibonacci_recurse(no);
	printf("fib of %d is %d\n", no, ans);
}

int factorial(int num)
{
	int fact = 1;
	while (num) {
		fact *= num;
		num--;
	}
	return fact;
}

void test_ncr_npr()
{
	int n, r, ncr, npr;

	n = 3, r = 2;

	ncr = factorial(n) / (factorial(n - r) * factorial(r));
	npr = factorial(n) / (factorial(n - r));

	printf("nCr of n=%d and r=%d is %d\n", n, r, ncr); // should be 3
	printf("nPr of n=%d and r=%d is %d\n", n, r, npr); // should be 6
}

void test_find_prime_factors_of_no()
{
	/* 12 = 2 * 2 * 3, two unique prime factors */
	/* 20 = 2 * 2 * 5, two unique prime factors */
	int num = 5; 
	int i = 0, count = 0; 

	/* Check every no from the beginning */
	for (i = 1; i <= num; i++) {
		/* Check that current no is factor of given no */
		if (!(num % i)) {
			/* Check if the factor is prime */
			int j, k = 0;
			for (j = 1; j <= i; j++) {
				if (!(i % j)) {
					k++;
				}
			}
			if (k == 2) { 	// just two factors -> prime no
				count++;
				printf("%d is a prime factor of %d\n", i, num);
			} 
		}
	}
	printf("Total no of unique prime factors of %d is %d\n", num, count);
}

void test_square_root_floor_of_no()
{
	int num = 440, start, end, mid, sqrt;

	if (num == 0 || num == 1)
		return;

	start = 0, end = num;
	mid = (start + end) / 2;

	while (start <= end) {
		mid = (start + end) / 2;
		if (mid * mid == num) {
			sqrt = mid;
			break;
		} else if (mid * mid < num) {
			start = mid + 1;
			sqrt = mid;
		} else {
			end = mid - 1;
		}
	}


	printf("Square Root (floor) is %d\n", sqrt);
}

void test_subtract_two_no_without_subtraction_operator()
{
	int num1, num2, diff;
	num1 = 10, num2 = 20;

	/* TODO */
	diff = num1 + ~num2 + 1;
	printf("Difference is %d\n", diff);
}

void test_add_two_no_without_addition_operator()
{
	int num1, num2, sum, carry;
	num1 = 10, num2 = 20;

	/* HINT: Sum of two bits can be obtained by performing XOR (^) of the two bits. 
	Carry bit can be obtained by performing AND (&) of two bits.*/

	while (num2) {
		// carry now contains common set bits of num1 and num2
		carry = num1 & num2;  

		// Sum of bits of num1 and num2 where at least one of the bits is not set
		num1 = num1 ^ num2; 

		// Carry is shifted by one so that adding it to num1 gives the required sum
		num2 = carry << 1;
	}
	sum = num1;
	printf("Addition is %d\n", sum);
}

void test_largest_of_three_nums()
{
	int a, b, c, largest;
	a = 23, b = 43, c = 29;

	largest = ((a > b && a > c)) ? a : ((b > c) ? b : c);
	printf("largest of %d, %d, %d is %d\n", a, b, c, largest);
}

int power_recursion(int num, int pow)
{
	if (pow < 0) {
		return num;
	} else if (pow == 0) {
		return 1;
	} else {
		return num * power_recursion(num, pow - 1) ;
	}
}

void test_power_of_no_recursion()
{
	int pow, num, ans;
	pow = 4;
	num = 3;

	ans = power_recursion(num, pow);
	printf("%d power %d is : %d\n", num, pow, ans);
}

void test_power_of_no()
{
	int pow, num, ans, i;
	pow = 3;
	num = 3;
	ans = 1;

	i = pow;
	while (i--) {
		ans *= num;
	}
	printf("%d power %d is :%d\n", num, pow, ans);
}

void test_no_of_bits_to_change_a_to_b()
{
	int a, b, count;
	a = 0x4DBF; // 0100 1101 1011 1111 
	b = 0x2CA9; // 0010 1100 1010 1001, need 6 bits to change a to b
	count = 0;

	a = a ^ b;

	while (a) {
		a &= a - 1;
		count++;
	}
	printf("No of bits required to convert a to b = %d\n", count);

}

void test_count_no_of_ones()
{
	int num, count;
	num = 0x4FB; // 0100 1111 1011 -> 8 ones
	count = 0;

	while (num) {
		num &= num - 1;
		count++;
	}
	printf("No of ones is %d\n", count);
}

int test_sum_of_digits_recur(int num)
{
	static int sum;

	if (num) {
		sum += num % 10;
		test_sum_of_digits_recur(num / 10);
	}
	return sum;
}

void test_sum_of_digits_recursion()
{
	int num = 1233, sum = 0;


	printf("num = %d\n", num);

	sum = test_sum_of_digits_recur(num);

	printf("Sum of digits = %d\n", sum);
}


void test_sum_of_digits()
{
	int num = 234;
	int sum = 0;

	printf("num = %d\n", num);

	while (num) {
		sum += num % 10;
		num /= 10;
	}

	printf("Sum of digits = %d\n", sum);

}

void test_modulo_remainder()
{
	int a = 10;
	int b = 4;

	int c = -10;
	int d = 4;

	int e = 10;
	int f = -4;

	int g = -10;
	int h = -4;

	printf("a = %d, b = %d,  a (%) b= %d\n\n", a, b, a % b);
	printf("c = %d, d = %d,  c (%) d= %d\n\n", c, d, c % d);
	printf("e = %d, f = %d,  e (%) f= %d\n\n", e, f, e % f);
	printf("g = %d, h = %d,  g (%) h= %d\n\n", g, h, g % h);
}

int rev_num_recur(int num)
{
	static int ones, rev;

	if (num) {
		ones = num % 10;
		rev = rev * 10 + ones;
		num /= 10;
		rev_num_recur(num);
	}
	return rev;
}

void test_rev_num_recursion()
{
	int num = -1023;
	int rev = 0;

	printf("num = %d\n", num);

	rev = rev_num_recur(num);

	printf("Reversed number = %d\n", rev);
}

void test_rev_num()
{
	int num = 102;
	int ones, rev = 0;

	printf("num = %d\n", num);

	while (num) {
		ones = num % 10;
		num /= 10;
		rev = rev * 10 + ones;
	}

	printf("Reversed number = %d\n", rev);
}

void test_is_power_of_2()
{
	int num;
	/* power of 2 no.s have only 1 set bit : num & (num-1) should return 0) */

	num = 0x4000; //16384, power of 2

	if (!(num & (num - 1)))
		printf("Original no = %x is a power of 2\n", num);
	else
		printf("Original no = %x is not a power of 2\n", num);

	num = 0x4001; //16385, not power of 2

	if ((num > 1) && !(num & (num - 1)))
		printf("Original no = %x is a power of 2\n", num);
	else
		printf("Original no = %x is not a power of 2\n", num);

}

int main()
{
	printf("\nTest program: numbers\n\n");

//	test_is_power_of_2();

//	test_modulo_remainder();

//	test_rev_num();

//	test_rev_num_recursion();

//	test_sum_of_digits();

//	test_sum_of_digits_recursion();

//	test_count_no_of_ones();

//	test_no_of_bits_to_change_a_to_b();

//	test_power_of_no();

	test_power_of_no_recursion();

//	test_largest_of_three_nums();

//	test_add_two_no_without_addition_operator();

//	test_subtract_two_no_without_subtraction_operator();

//	test_square_root_floor_of_no();

//	test_find_prime_factors_of_no();

//	test_ncr_npr();

//	test_fibonacci_no();

//	test_find_gcd();

//	test_find_lcm();

//	test_round_floating_pt_no();

//	test_of_macros();

//	test_swap_two_no_without_temp();

	test_do_conversions();

// 	TODO
//	test_get_power();

	printf("\n\nExiting...\n\n");

	return 0;
}


