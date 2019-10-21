/*
* Program to study 'const' in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ABC_STRING "ABC"

/*
* Returns a pointer to read-only string, not a copy of string
*/
const char *test_const_string_return()
{
	return "hello_const";
}

void test_const_string(const char *temp)
{
	// error : read-only variable is not assignable
	// temp[0] = 'a';

	printf("%s: input string: %s\n", __func__, temp);
}

void test_const_to_non_const_func(char *temp)
{
	/* Below will cause a segfault when input string is const */
	// temp[0] = 's';
	printf("%s: input string: %s\n", __func__, temp);
}

void test_const_ptr_modify(const char **temp)
{
	if (!temp)
		return;

	printf("%s: input string: %s\n", __func__, *temp);

	// This is valid, the pointer to const string is modified
	*temp = ABC_STRING;
	printf("%s: modified string: %s\n", __func__, *temp);
}

int main()
{
	/* ======================================================== */
	/* Passing string to function with const parameters */

	test_const_string("hello world");

	char *hello_string = "hello_world";
	test_const_string(hello_string);

	char hello_string_arr[] = {'h', 'e'};
	test_const_string(hello_string_arr);

	char *hello_ptr;
	hello_ptr = calloc(10, sizeof(char));

	strcpy(hello_ptr, hello_string);
	test_const_string(hello_ptr);


	/* ======================================================== */
	/* Returning const string */

	hello_ptr[0] = 's';

	// warning : assigning char * from const char * discards qualifiers
	hello_ptr = test_const_string_return();
	// This will cause segfault
	// hello_ptr[0] = 's';

	printf("%s: return string: %s\n", __func__, hello_ptr);

	const char *hello_return_string;
	hello_return_string = test_const_string_return();
	printf("%s: return string: %s\n", __func__, hello_return_string);

	// error: read-only variable is not assignable
	// hello_return_string[0] = 't';

	/* const char ** test */
	const char **hello_ptr_array = &hello_return_string;
	test_const_ptr_modify(hello_ptr_array);

	/* ======================================================== */
	/* Passing const to non-const function */

	char non_const_string[] = {'h', 'b', '\0'};
	// This is okay
	test_const_to_non_const_func(non_const_string);

	// These can cause segfault if the callee modifies string
	const char const_string[] = {'a', 'b', '\0'};
	test_const_to_non_const_func("world");
	test_const_to_non_const_func(const_string);

	/* ======================================================== */
	/* const pointers to (const char *) */

	const char *const abc_const_ptr = ABC_STRING;

	test_const_string(abc_const_ptr);

	// below will cause segfault
	// test_const_ptr_modify(abc_const_ptr);

	return 0;

}


