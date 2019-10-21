/*
* Overflow/Underflow Detection
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>

int test_safe_add(int a, int b)
{
	if (a > 0 && b > INT_MAX - a)
		printf("%s : overflow detected for %d + %d\n", __func__, a, b);
	else if (a < 0 && b < INT_MIN - a)
		printf("%s : underflow detected for %d + %d\n", __func__, a, b);

	return a + b;
}

int test_safe_multiply(int a, int b)
{
	if (a && INT_MAX / abs(a) < abs(b))
		printf("%s : overflow detected for %d * %d\n", __func__, a, b);

	return a * b;
}


int main()
{

	int a, b, c;

	/* Addition */
	a = INT32_MAX - 4; b = 10;
	c = test_safe_add(a, b);
	printf("a (%d) + b (%d) = c(%d)\n", a, b, c);

	a = INT32_MIN + 4; b = -10;
	c = test_safe_add(a, b);
	printf("a (%d) + b (%d) = c(%d)\n", a, b, c);

	a = 4; b = 10;
	c = test_safe_add(a, b);
	printf("a (%d) + b (%d) = c(%d)\n", a, b, c);


	/* mulitiplication */
	a = INT32_MAX - 4; b = 10;
	c = test_safe_multiply(a, b);
	printf("a (%d) * b (%d) = c(%d)\n", a, b, c);

	a = INT32_MIN + 4; b = -2;
	c = test_safe_multiply(a, b);
	printf("a (%d) * b (%d) = c(%d)\n", a, b, c);

	a = 4; b = -2;
	c = test_safe_multiply(a, b);
	printf("a (%d) * b (%d) = c(%d)\n", a, b, c);

	return 0;
}


