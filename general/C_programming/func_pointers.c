/*
* Program to study function pointers
*/

#include <stdio.h>

/*
* Example 1 - Car structure
*/

/* Car operations */
enum car_type {
        LUXURY_SPORTS,
        SEDAN,
        SUV,
};

enum gear {
	FIRST = 1,
	SECOND = 2,
	THIRD = 3,
	FOURTH = 4,
	FIFTH = 5,
	SIXTH = 6,
	SEVENTH = 7,
	EIGHTH = 8,
	NEUTRAL,
	REVERSE,
	PARK,
	DRIVE,
	LOW,
};

struct car {
        int type;
        unsigned int current_gear;
        void (*accelerate)(int factor);
        void (*brake)(void);
        void (*change_gear)(struct car *c, int gear);
};

void fast_accelerate(int factor)
{
	printf("broooomm!!!\n");
}

void slow_accelerate(int factor)
{
	printf("brrrrr!!!\n");
}

void disc_brake()
{
	printf("screeeech!!!\n");
}

void drum_brake()
{
	printf("grrrrrrrr!!!\n");
}

void smooth_gear_change(struct car *cr, int gear)
{
	if (!cr)
		return;
	cr->current_gear = gear;
	printf("cluck\n");
}

int get_current_gear(struct car *cr)
{
        return cr->current_gear;
}
/* End of Car*/

/* Test passing array of function pointers */
void initialize_car(struct car *c, enum car_type type)
{
	switch (type) {
	case LUXURY_SPORTS:
		c->type = LUXURY_SPORTS;
		c->accelerate = fast_accelerate;
		c->brake = disc_brake;
		c->change_gear = smooth_gear_change;
		break;
	case SEDAN:
		c->type = SEDAN;
		c->accelerate = slow_accelerate;
		c->brake = disc_brake;
		c->change_gear = smooth_gear_change;
		break;
	case SUV:
		c->type = SUV;
		c->accelerate = slow_accelerate;
		c->brake = disc_brake;
		c->change_gear = smooth_gear_change;
		break;
	default:
		return;
	}
	c->current_gear = NEUTRAL;
	return;
}

void print_car_info(struct car *c)
{
	if (!c)
		return;
	printf("Car type is %d\n", c->type);
	printf("Car acceleartion: ");
	c->accelerate(10);
	printf("Car break: ");
	c->brake();
	printf("Car - change gear: ");
	c->change_gear(c, 3);
	printf("Car - current gear: %d\n", c->current_gear);
}

/*
* Example 2 - choose operation based on the choice
* array of function pointers
*/
void add(int a, int b)
{
	printf("Addition is %d\n", a + b);
}
void subtract(int a, int b)
{
	printf("Subtraction is %d\n", a - b);
}
void multiply(int a, int b)
{
	printf("Multiplication is %d\n", a * b);
}

/* Pointer to func_ptr_array */
void operation_initializer(int *(*func_ptr_array))
{
	func_ptr_array[0] = &add;
	func_ptr_array[1] = &subtract;
	func_ptr_array[2] = &multiply;
}

/* This simply calls the passed function */
void wrapper_caller(int (*func)(int, int), int a, int b)
{
	printf("Wrapper: calling the passed function : \n");
	func(a, b);
}

int main()
{
	/******************************************************************************************/
	/* Example 1: Car strucutre - basic function pointers */
	/******************************************************************************************/
        struct car jaguar;

	initialize_car(&jaguar, LUXURY_SPORTS);

	print_car_info(&jaguar);


	/******************************************************************************************/
	/* Example 2 - do ops based on input - pass array of function pointers */
	/******************************************************************************************/

	/* Case 1 - pass arugments */
	int (*func_ptr_array[3])();
	int option = 3;

	operation_initializer(func_ptr_array);

	switch(option) {
	case 1:
		func_ptr_array[0](3, 6);
		break;
	case 2:
		func_ptr_array[1](3, 6);
		break;
	case 3:
		func_ptr_array[2](3, 6);
		break;
	default:
		break;
	}

	/* Case 2 - call function pointer directly */
	void (*function_pointer)();

	function_pointer = &subtract;

	/* one method of calling */
	(*function_pointer)(3, 6);

	/* another method of calling */
	function_pointer(3, 6);

	/* Case 3 - pass function pointer to another wrapper function */
	wrapper_caller(function_pointer, 3, 6);


	/******************************************************************************************
	* Example 3 - Typedef array of function pointers
	* Array of 10 function pointers returning array of function pointers returning pointers to char
	******************************************************************************************/

	/* typedef return value */
	typedef char * charptr_t;

	/* Function pointer returning char pointers */
	typedef charptr_t (*innerfunc_t)();

	/* Function pointers returning array of function pointers returning char pointer) */
	typedef innerfunc_t (*outerfunc_t)();

	/* Array of 10 such pointers */
	outerfunc_t final_array[10];

        return 0;
}



