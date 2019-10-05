/*
* Program to study enums
*/

#include <stdio.h>

/*
*
*/

enum car_type {
        LUXURY_SPORTS,
        SEDAN,
        SUV,
};

enum gear {
	/* Manual */
	FIRST 	= 1,
	SECOND 	= 2,
	THIRD 	= 3,
	FOURTH 	= 4,
	FIFTH 	= 5,
	SIXTH 	= 6,
	SEVENTH = 7,
	EIGHTH 	= 8,

	/* Auto */
	NEUTRAL = 0x100,
	REVERSE = 0x101,
	PARK 	= 0x102,
	DRIVE 	= 0x103,
	LOW 	= 0x104,
};

struct car {
        enum car_type type;
        enum gear current_gear;
};

static inline enum gear current_gear(struct car c)
{
	return c.current_gear;
}

void initialize_car_data(struct car *c)
{
	if (!c)
		return;
	c->type = SEDAN;
	c->current_gear = NEUTRAL;
}

void change_gear(struct car *c, enum gear new_gear)
{
	if (!c)
		return;

	c->current_gear = new_gear;
}

int main()
{

	struct car c;
	initialize_car_data(&c);

	printf("sizeof strcut car = %u\n", sizeof(c));
	printf("car : current gear = %u\n", current_gear(c));
	printf("car : type = %u\n", c.type);

	change_gear(&c, REVERSE);
	printf("car : current gear = %u\n", current_gear(c));

        return 0;
}

