/*
* Program to demo variadic args in C
* Function 'sum' can take any number of arguments and returns sum of arguments
* 'sum' requires format string and number of arguments to calculate sum
*/

#include <stdarg.h>
#include <stdio.h>

double sum(char *format, int count, ...)
{
	double total;

	if (!format || format[0] != '%')
		return 0;

	total = 0;
	va_list args;
	va_start(args, count);
	while (count--) {
		if (format[1] == 'd')
			total += va_arg(args, int);
		else if (format[1] == 'f')
			total += va_arg(args, double);
		else if (format[1] == 'p')
			total += *va_arg(args, int *);
		else
			break;
	}
	va_end(args);
	return total;
}

int main()
{
	double ans = 0;
	printf("Variadic arguments demo \n");

	ans = sum("%d", 3, 1, 2, 3);
	printf("sum = %f\n", ans);

	/* NOTE: cannot use char, short, float for variadic args */
	ans = sum("%f", 4, 1.0, 2.5, -3.1, 8.43234);
	printf("sum = %f\n", ans);

	int num1 = 50, num2 = 100;
	/* Pointer to integer*/
	ans = sum("%p", 2, &num1, &num2);
	printf("sum = %f\n", ans);

	ans = sum(0, 0);
	printf("sum = %f\n", ans);

	return 0;
}

