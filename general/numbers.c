
#include <stdio.h>


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
		test_rev_num_recur(num);
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

	num = 0x4000; //16384, power of 2

	if (!(num & (num - 1)))
		printf("Original no = %x is a power of 2\n", num);
	else
		printf("Original no = %x is not a power of 2\n", num);	

	num = 0x4001; //16385, not power of 2

	if (!(num & (num - 1)))
		printf("Original no = %x is a power of 2\n", num);
	else
		printf("Original no = %x is not a power of 2\n", num);	

}

int main()
{
	printf("\nTest program\n\n");


//	test_is_power_of_2();

//	test_modulo_remainder();

//	test_rev_num();

//	test_rev_num_recursion();

//	test_sum_of_digits();

//	test_sum_of_digits_recursion();
    

	printf("\n\nExiting...\n\n");

	return 0;
}


