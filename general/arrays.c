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

void test_matrix_transposition()
{
#define ROWS 4
#define COLUMNS 4

	int i, j;
	int my_2d_arr[ROWS][COLUMNS] = {{1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16}};

	int my_2d_transpose[ROWS][COLUMNS];

	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%d ", my_2d_arr[i][j]);
		}
		printf("\n");
	}

	/* Matrix transposition */
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			my_2d_transpose[i][j] = my_2d_arr[j][i];
		}
		printf("\n");
	}

	printf("\nMatrix after transposition\n");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%d ", my_2d_transpose[i][j]);
		}
		printf("\n");
	}
}

/* TODO */
void test_matrix_multiplication()
{
#define ROWS_A 2
#define COLUMNS_A 4

#define ROWS_B 4
#define COLUMNS_B 2

	int i, j;
	int arr_A[ROWS_A][COLUMNS_A] = {{1, 0, 1, 0},
					{0, 1, 1, 0}};

	int arr_B[ROWS_B][COLUMNS_B] = {{1, 0},
					{0, 1},
					{1, 0},
					{0, 1}};

	int multi_arr[ROWS_A][COLUMNS_B] = {{0}};

	/* Matrix multiplication */
	for (i = 0; i < ROWS_A; i++) {
		for (j = 0; j < COLUMNS_B; j++) {
			int cur_dot_prod = 0;
			int k;
			for (k = 0; k < COLUMNS_A; k++)
				cur_dot_prod += arr_A[i][k] * arr_B[k][j];
			multi_arr[i][j] = cur_dot_prod;
		}
	}

	printf("\nMultiplication matrix\n");
	for (i = 0; i < ROWS_A; i++) {
		for (j = 0; j < COLUMNS_B; j++) {
			printf("%d ", multi_arr[i][j]);
		}
		printf("\n");
	}
}

/*
* if an element in an MxN matrix is 0, its entire row and
* column are set to O
*/
void test_zero_matrix()
{
#undef ROWS
#define ROWS 3
#define COLUMNS 4

	int i, j;
	int my_2d_arr[ROWS][COLUMNS] = {{1, 5, 88, 21},
					{1, 0, 37, 16},
					{2, 4, 0, 9}};

	int zero_rows[ROWS] = {0};
	int zero_columns[COLUMNS] = {0};


	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%d ", my_2d_arr[i][j]);
		}
		printf("\n");
	}

	/* Track all the rows and columns which have zero elements */
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			if (!my_2d_arr[i][j]) {
				zero_rows[i] = 1;
				zero_columns[j] = 1;
			}
		}
		printf("\n");
	}
	/* Zero out tracked rows and columns */
	for (i = 0; i < ROWS; i++) {
		if (zero_rows[i]) {
			for (j = 0; j < COLUMNS; j++) {
				my_2d_arr[i][j] = 0;
			}
		}
	}

	for (j = 0; j < COLUMNS; j++) {
		if (zero_columns[j]) {
			for (i = 0; i < ROWS; i++) {
				my_2d_arr[i][j] = 0;
			}
		}
	}

	printf("\nArray after zeroing\n");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%d ", my_2d_arr[i][j]);
		}
		printf("\n");
	}
}

/*
* Given an image represented by an NxN matrix, where each pixel in the image is 4
* bytes,rotate the image by 90 degrees, in place.
*/
void test_rotate_matrix()
{
// to suppress warnings
#undef ROWS
#undef COLUMNS

#define ROWS 3
#define COLUMNS 3

	int i, j;
	int my_2d_arr[ROWS][COLUMNS] = {{1, 5, 88},
					{1, 0, 37},
					{2, 4, 0}};

	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%d ", my_2d_arr[i][j]);
		}
		printf("\n");
	}

	int top_l, top_r, bottom_l, bottom_r;
	int layer, layer_max, temp;

	layer = 0;
	layer_max = (ROWS - 1) - layer;

	top_l = 0;
	top_r = 0;
	bottom_l = ROWS - 1;
	bottom_r = ROWS - 1;

	// TODO : complete
	for (i = layer; i <= layer_max; i++) {
		temp = my_2d_arr[layer][top_l + i];

		my_2d_arr[layer][top_l + i] = my_2d_arr[bottom_l - i][layer];
		my_2d_arr[bottom_l - i][layer] = my_2d_arr[layer_max][bottom_r - i];
		my_2d_arr[layer_max][bottom_r - i] = my_2d_arr[top_r + i][layer_max];
		my_2d_arr[top_r + i][layer_max] = temp;
	}

	printf("\nArray after 90 right-rotation\n");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%d ", my_2d_arr[i][j]);
		}
		printf("\n");
	}
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

void test_array_initialization()
{
	/* 1D */
	int my_arr[4] = {0};
	print_array(my_arr, 4);

	int my_arr_two[] = {6, 1, 3};
	print_array(my_arr_two, 3);

	printf("\n");

	/* 2D */
	int i, j;

	int my_2d_arr[3][4] = {};
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++)
			printf("%d ", my_2d_arr[i][j]);
		printf("\n");
	}

	printf("\n");

	int my_2d_arr_two[][2] = {{5, 6}, {1, 3}};
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++)
			printf("%d ", my_2d_arr_two[i][j]);
		printf("\n");
	}
}


int main()
{
	printf("\nTest program: Arrays\n\n");
#if 0
	test_array_initialization();

	test_find_largest_element_in_array();

	test_delete_an_element();

	test_remove_duplicate_elements();

	test_shift_members_of_array();

	test_find_count_of_repeating_elements_in_1_to_n_array();

	test_allocate_2D_array();
#endif
	//TODO
//	test_rotate_matrix();

//	test_zero_matrix();

//	test_matrix_multiplication();

//	test_matrix_transposition();

	printf("\n\nExiting...\n\n");

	return 0;
}

