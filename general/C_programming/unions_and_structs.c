/*
* Program to study unions and structs in C
* TODO : tagged unions, pointers to unions
* typdef struct and unions
*/

#include <stdio.h>
#include <stdint.h>

union word32 {
	struct {
		uint8_t byte4;
		uint8_t byte3;
		uint8_t byte2;
		uint8_t byte1;
	};
	uint32_t num;
};

void test_union()
{
    union word32 wd;
    wd.num = 0x12345678;

    printf("byte 1 = %#x,  byte 2 = %#x, byte3 = %#x, byte4 = %#x\n", wd.byte1, wd.byte2, wd.byte3, wd.byte4);
}

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

void test_struct_union()
{
		str1.date = 4;

	union car my_car;
	my_car.precise_price = 23000.12;

	printf("Price of my car %f\n", my_car.precise_price);

	my_car.price = 23000;

	printf("Price of my car %d\n", my_car.price);
	printf("Price of my car %f\n", my_car.precise_price);
	printf("Size of union car %lu\n", sizeof(my_car));


	// struct initialization
	struct name {
		unsigned int len;
		char *str;
	} names[2] = {
		{
			.len = 3,
			.str = "abc",
		},
		{
			.len = 6,
			.str = "hello",
		}
	};

	printf("names %d: len: %u\n", 0, names[0].len);
	printf("names %d: str: %s\n", 0, names[0].str);
	printf("names %d: len: %u\n", 1, names[1].len);
	printf("names %d: str: %s\n", 1, names[1].str);

	/* sizeof */
	struct packet {
		unsigned int len;
		void *hdr;
		void *payload;
	};

	struct packet pkt, *pkt_ptr;
	pkt_ptr = &pkt;

	printf("Size of struct packet %lu\n", sizeof(struct packet));
	printf("Size of pkt %lu\n", sizeof(pkt));
	printf("Size of pkt_ptr %lu\n", sizeof(pkt_ptr));
	printf("Size of *pkt_ptr %lu\n", sizeof(*pkt_ptr));

}

int main()
{

	test_struct_union();

	test_union();

	return 0;
}

