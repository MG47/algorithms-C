/*
* Array programs
*/

#include <stdio.h>
#include <stdlib.h>

/* Utitlies */
#define SIZEOF_ARR(arr) (sizeof(arr) / sizeof(arr[0]))

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *arr, int size)
{
	int i = 0;
	printf("\nArray: {");
	while (i < size) {
		printf(" %d ", arr[i++]);
	}
	printf("}\n");

}

/*
* Move all zeros in an array to end without changing order of non-zero elements
*/
void test_shift_zeros_to_end()
{
	int arr[] = {0, 1, 19, 200, 0, 5, 1, 44, 6, 0, 1, 0};
	int count, len, i;
	len = SIZEOF_ARR(arr);

	print_array(arr, len);

	count = 0;
	i = 0;
	while (i < len) {
		if (arr[i])
			arr[count++] = arr[i];
		i++;
	}

	while (count < len) {
		arr[count] = 0;
		count++;
	}

	print_array(arr, len);

}

void test_find_count_of_repeating_elements_in_1_to_n_array()
{
	int n = 7; 	// (range 0 - 6)
	int size = 10;
	int arr[10] = {1, 2, 4, 6, 3, 2, 1, 5, 6, 4};

	int *count_arr, i;

	count_arr = calloc(n, sizeof(int));
	if (!count_arr)
		return;

	print_array(arr, size);
	for (i = 0; i < size; i++)
		count_arr[arr[i]]++;

	for (i = 0; i < n; i++)
		printf("i %d -> count: %d\n", i, count_arr[i]);
}

void test_shift_members_of_array()
{
	enum {
		LEFT,
		RIGHT,
	};
	int size = 6;
	int arr[6] = {1, 17, -3, -9, 10, 2};
	int shift_by = 2;
	int direction = LEFT;
	int temp, i;

	printf("\nArray before shifting %s by %d", (direction == LEFT) ? "left" : "right", shift_by);
	print_array(arr, size);

	if (direction == LEFT) {
		while (shift_by--) {
			temp = arr[0];
			for (i = 0; i < size - 1; i++)
				arr[i] = arr[i + 1];
			arr[size - 1] = temp;
		}
	} else {
		while (shift_by--) {
			temp = arr[size - 1];
			for (i = size - 1; i > 0; i--)
				arr[i] = arr[i - 1];
			arr[0] = temp;
		}
	}
	printf("Array after shifting:\n");
	print_array(arr, size);
}

void test_remove_duplicate_elements()
{
	int size = 8;
	int arr[8] = {1, 17, -3, -3, 10, 2, 9, 2};
	int i, j, k;

	print_array(arr, size);
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (arr[i] == arr[j]) {
				// remove second element and reduce lenght of array by 1
				for (k = j; k < (size - 1); k++) {
					arr[k] = arr[k + 1];
				}
				size--;
			}
		}
	}
	printf("Array after removing elements: ");
	print_array(arr, size);
}

void test_array_initialization()
{
	/* 1D */
	int my_arr[4] = {0};
	print_array(my_arr, SIZEOF_ARR(my_arr));

	int my_arr_two[] = {6, 1, 3};
	print_array(my_arr_two, SIZEOF_ARR(my_arr_two));

}

int main()
{
	printf("\nTest program: Arrays\n\n");

	test_array_initialization();

	test_remove_duplicate_elements();

	test_shift_members_of_array();

	test_find_count_of_repeating_elements_in_1_to_n_array();

	test_shift_zeros_to_end();

	printf("\n\nExiting...\n\n");

	return 0;
}

