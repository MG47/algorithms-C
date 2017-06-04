/* 
* Program to perform binary search on array 
* Uses insertion sort to sort array before binary search
*/ 

#include <stdio.h>
#include <stdlib.h>

int insertionsort(int *arr, int len)
{
	int i, cur_val, j;
	for (i = 1; i < len; i++) {
		cur_val = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > cur_val) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = cur_val;
	}
	return 0;
}

int bin_search(int *array, int len, int search)
{
	int first = 0;
	int last = len - 1;
	int middle = (first + last)/2;
	int err;

	err = insertionsort(array, len);
	if (err)
		exit(EXIT_FAILURE);

	while (first <= last) {
		if (array[middle] < search) {
			first = middle + 1;
		} else if (array[middle] > search) {
			last = middle - 1;
		} else {
			return 1;
		}
		middle = (first + last)/2;
	}

	if (first > last)
		return 0;
	return 1;
}

int main()
{
	int key;
	int len = 10;
	int found = 0;
	int search_arr[10] = {3, 4, 32, 11, 9, 26, 122, 87, 29, 87};

	key = 87;
	found = bin_search(search_arr, len, key);
	if (found)
		printf("Found element %d in the array\n", key);
	else
		printf("Did not find element %d in the array\n", key);
	return 0;
}

