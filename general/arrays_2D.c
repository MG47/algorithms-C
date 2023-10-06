/*
* 2D Array / Matrix Programs
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

	printf("\nMatrix before 90 right-rotation\n");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%d ", my_2d_arr[i][j]);
		}
		printf("\n");
	}

	// Transpose the matrix and reverse the rows
	for (i = 0; i < ROWS; i++) {
		for (j = i; j < COLUMNS; j++) {
			swap(&my_2d_arr[i][j], &my_2d_arr[j][i]);
		}
	}

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < (COLUMNS / 2); j++) {
			swap(&my_2d_arr[i][j], &my_2d_arr[i][COLUMNS - 1 - j]);
		}
	}

	printf("\nMatrix after 90 right-rotation\n");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%d ", my_2d_arr[i][j]);
		}
		printf("\n");
	}
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

	printf("\nMatrix before transposition\n");
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
	}

	printf("\nMatrix after transposition\n");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%d ", my_2d_transpose[i][j]);
		}
		printf("\n");
	}
}

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
* If an element in an M x N matrix is 0, set its entire row and column to 0
*/
void test_zero_matrix()
{
#undef ROWS
#define ROWS 3
#define COLUMNS 4

	int i, j;
	int matrix[ROWS][COLUMNS] = {{1, 5, 88, 21},
					{1, 0, 37, 16},
					{2, 4, 0, 9}};

	int zero_rows[ROWS] = {0};
	int zero_columns[COLUMNS] = {0};


	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	/* Track all the rows and columns which have zero elements */
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			if (!matrix[i][j]) {
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
				matrix[i][j] = 0;
			}
		}
	}

	for (j = 0; j < COLUMNS; j++) {
		if (zero_columns[j]) {
			for (i = 0; i < ROWS; i++) {
				matrix[i][j] = 0;
			}
		}
	}

	printf("\nArray after zeroing\n");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLUMNS; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void print_2DArr(int **arr, int R, int C)
{
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%d ", arr[i][j]);
        }
		printf("\n");

    }
}

void test_twoD_matrix()
{

	int matrix[3][3] = {{1, 2, 3,}, {4, 5, 6}, {7, 8, 9}};
	int matrix2[3][3] = {{1, 2, 3,}, {4, 5, 6}, {7, 8, 9}};

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix2[j][i] = matrix[i][j];
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", matrix2[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++)
			swap(&matrix2[i][j], &matrix2[i][2 - j]);
		}

		for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", matrix2[i][j]);
		}
		printf("\n");
	}


	//printArr(matrix, 3, 3);


	int *matrixSingle = (int *)malloc(sizeof(int) * 9);
	if (!matrixSingle)
		return 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			matrixSingle[i * 3 + j]  = matrix[i][j];
	}

	int **twodArr = (int **)malloc(sizeof(int *) * 3);
	for (int i = 0; i < 3; i++)
		twodArr[i] = (int *)malloc(sizeof(int) * 3);


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			twodArr[i][j] = matrix[i][j];
			printf("%d ", twodArr[i][j]);
		}
	}

	//print2DArr(twodArr, 3, 3);

	return 0;
}

void print_array(int *arr, int R, int C)
{
	printf("\n== %s == \n", __func__);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d ", arr[i * C + j]);
		}
		printf("\n");
	}
}

void test_2D_array_as_1D_array()
{
	int **arr2D = (int **)malloc(2 * sizeof(int *)); // 2 rows;
	for (int i = 0; i < 2; i++)
		arr2D[i] = malloc(3 * sizeof(int)); 	// 3 Columns

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			arr2D[i][j] = (i + 1) * j;
		}
	}

	// Convert to 1D array
	int *arr1D = (int *)malloc(sizeof(int) * 2 * 3);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			// [i * C + j] ==> [i][j]
			arr1D[i * 3 + j] = arr2D[i][j];
		}
	}
	print_array(arr1D, 2, 3);
}

void print_array_as_ptrs_to_ptrs(int **arr, int R, int C)
{
	printf("\n== %s == \n", __func__);
	for (int i = 0; i < R; i++) {
		printf("{");
		for (int j = 0; j < C; j++) {
			printf(" %d ", arr[i][j]);
		}
		printf("}\n");
	}
	printf("\n");
}

void print_array_of_pointers(int *arr[3], int R, int C)
{
	printf("\n== %s == \n", __func__);
	for (int i = 0; i < R; i++) {
		printf("{");
		for (int j = 0; j < C; j++) {
			printf(" %d ", arr[i][j]);
		}
		printf("}\n");
	}
	printf("\n");
}

void print_2D_static_array(int arr[][3], int R, int C)
{
	printf("\n== %s == \n", __func__);
	for (int i = 0; i < R; i++) {
		printf("{");
		for (int j = 0; j < C; j++) {
			printf(" %d ", arr[i][j]);
		}
		printf("}\n");
	}
	printf("\n");
}

void test_2D_array_as_parameters()
{
	int i, j;
	/* Static allocation */
	int arr1[2][3] = {{1, 2, 3}, {6, 7, 8}};
	print_2D_static_array(arr1, 2, 3);


	/* Dynamic allocation - array of pointers */
	int *arr2[2]; 		// 2 Rows
	for (i = 0; i < 2; i++)
		arr2[i] = malloc(3 * sizeof(int)); // 3 Columns

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			arr2[i][j] = (i + 6) * j;
		}
	}
	print_array_of_pointers(arr2, 2, 3);

	/* Dynamic allocation - double pointers */
	int **arr3;
	arr3 = malloc(2 * sizeof(int *)); // 2 rows;
	for (i = 0; i < 2; i++)
		arr3[i] = malloc(3 * sizeof(int));

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			arr3[i][j] = (i + 1) * j;
		}
	}
	print_array_as_ptrs_to_ptrs(arr3, 2, 3);

}

void test_2D_array_initialization()
{
	/* 2D */
	int i, j;

	printf("\n");
	int my_2d_arr[3][4] = {{0}};
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


void test_allocate_2D_array()
{
	int i, j;

	/* Static allocation */
	int arr1[2][3] = {{1, 2, 3}, {6, 7, 8}};

	for (i = 0; i < 2; i++) {
		printf("{");
		for (j = 0; j < 3; j++) {
			printf(" %d ", arr1[i][j]);
		}
		printf("} ");
	}
	printf("\n");

	/* Dynamic allocation - array of pointers */
	int *arr2[2]; 		// 2 Rows
	for (i = 0; i < 2; i++)
		arr2[i] = malloc(10 * sizeof(int)); // 10 Columns

	for (i = 0; i < 2; i++) {
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
	arr3 = malloc(2 * sizeof(int *)); // 2 rows;
	for (i = 0; i < 2; i++)
		arr3[i] = malloc(3 * sizeof(int));

	for (i = 0; i < 2; i++) {
		printf("{");
		for (j = 0; j < 3; j++) {
			arr3[i][j] = (i + 1) * j;
			printf(" %d ", arr3[i][j]);
		}
		printf("} ");
	}
	printf("\n");
}


int main()
{
	printf("\nTest program: 2D Arrays and Matrices\n\n");

	test_allocate_2D_array();

	test_2D_array_initialization();

	test_2D_array_as_parameters();

	test_2D_array_as_1D_array();

	test_zero_matrix();

	test_matrix_multiplication();

	test_matrix_transposition();

	test_rotate_matrix();

	printf("\n\nExiting...\n\n");

	return 0;
}

