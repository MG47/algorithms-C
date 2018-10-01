/*
* Program to study unions and structs in C
* TODO : tagged unions, pointers to unions, union within struct
* typdef struct and unions
*/

#include <stdio.h>

struct cal {
	int date;
	int month;
	int year;
} str1, str2;

union car {
	double ultra_precise_price;
	float precise_price;
	int price;
};

int main()
{
	str1.date = 4;

	union car my_car;
	my_car.precise_price = 23000.12;

	printf("Price of my car %f\n", my_car.precise_price);

	my_car.price = 23000;

	printf("Price of my car %d\n", my_car.price);


	printf("Price of my car %f\n", my_car.precise_price);

	printf("Size of union car %lu\n", sizeof(my_car));

	return 0;
}

