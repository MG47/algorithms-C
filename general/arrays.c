#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size)
{
	int i = 0;
	printf("\nArray: {");
	while (i < size) {
		printf("%d ", arr[i++]);
	}
	printf("}\n");

}

void test_allocate_2D_array()
{
	int i, j;

	/* Static allocation */
	int arr1[2][3] = {{1, 2, 3}, {6, 7, 8}};

	for(i = 0; i < 2; i++) {
		printf("{");
		for (j = 0; j < 3; j++) {
			printf(" %d ", arr1[i][j]);
		}
		printf("} ");
	}
	printf("\n");

	/* Dynamic allocation - pointers */
	int *arr2[2];
	for (i = 0; i < 2; i++)
		arr2[i] = malloc(10 * sizeof(int));

	for(i = 0; i < 2; i++) {
		printf("{");
		for (j = 0; j < 3; j++) {
			arr2[i][j] = (i + 6) * j;
			printf(" %d ", arr2[i][j]);
		}
		printf("} ");
	}
	printf("\n");


	/* Dynamic allocation - double pointers */
	int **arr3;
	arr3 = malloc(2 * sizeof(int)); // 2 rows;
	for (i = 0; i < 2; i++)
		arr3[i] = malloc(3 * sizeof(int));

	for(i = 0; i < 2; i++) {
		printf("{");
		for (j = 0; j < 3; j++) {
			arr3[i][j] = (i + 1) * j;
			printf(" %d ", arr3[i][j]);
		}
		printf("} ");
	}
	printf("\n");
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
		left,
		right,
	};
	int size = 6;
	int arr[6] = {1, 17, -3, -9, 10, 2};
	int shift_by = 2;
	int direction = left;
	int temp, i;

	printf("\nArray before shifting %s by %d", direction ? "right" : "left", shift_by);
	print_array(arr, size);

	if (!direction) { 	//left
		while (shift_by--) {
			temp = arr[0];
			for (i = 0; i < size - 1; i++)
				arr[i] = arr[i + 1];
			arr[size - 1] = temp;
		}
	} else { 		//right
		while (shift_by--) {
			temp = arr[size - 1];
			for (i = size - 1; i > 0; i--)
				arr[i] = arr[i - 1];
			arr[0] = temp;
		}
	}
	printf("Array after shifting");
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
				for (k = j; k < size; k++) {
					arr[k] = arr[k + 1];
				}
				size--;
			}
		}
	}
	printf("Array after removing elements: ");
	print_array(arr, size);
}

void test_delete_an_element()
{
	int size = 6;
	int arr[6] = {1, 17, -3, -9, 10, 2};
	int i, pos = 3;

	print_array(arr, size);

	for (i = pos; i < size - 1; i++) {
		arr[i] = arr[i + 1];
	}
	size--;

	printf("Array removing element at index %d:", pos);
	print_array(arr, size);
}

void test_find_largest_element_in_array()
{

	int size = 5;
	int arr[5] = {1, 17, -3, 200, 10};
	int i = 0, max;
	max = arr[0];

	for (i = 1; i < size; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	print_array(arr, size);
	printf("Largest element in the array is %d\n", max);
}

int main()
{
	printf("\nTest program: Arrays\n\n");

	test_find_largest_element_in_array();

	test_delete_an_element();

	test_remove_duplicate_elements();

	test_shift_members_of_array();

	test_find_count_of_repeating_elements_in_1_to_n_array();

	test_allocate_2D_array();

	printf("\n\nExiting...\n\n");

	return 0;
}

