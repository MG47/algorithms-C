/*
* Mergesort
* INCOMPLETE
*/

#include <stdio.h>
#include <stdlib.h>

struct data {
	int *arr;
	int len;
};

struct data *create_data(int val)
{
	struct data *d;
	d = malloc(sizeof(struct data));
	if (!d)
		exit(EXIT_FAILURE);

	d->arr = malloc(sizeof(int));
	if (!d->arr)
		exit(EXIT_FAILURE);

	d->arr[0] = val;
	d->len = 1;
	return d;
}


void print_array(struct data *d)
{
	if (!d) {
		printf("Data does not exist\n");
		return;
	}

	if (!d->arr) {
		printf("Array is empty\n");
		return;
	}
	printf("Array size: %d\n", d->len);

	int i = 0;
	while (i < d->len) {
		printf("%d - %d\n", i, d->arr[i]);
		i++;
	}
}


int insert_data(struct data **d, int val)
{
	struct data *data = *d;
	if (!(*d)) {
		*d = create_data(val);
		return 0;
	}

	data->len++;
	int *new_arr;
	new_arr = realloc(data->arr, sizeof(int) * (data->len));
	if (!new_arr)
		exit(EXIT_FAILURE);

	data->arr = new_arr;

	data->arr[(data->len) - 1] = val;
	return 0;
}

int remove_data(struct data **d, int val)
{
	struct data *data = *d;
	if (!data)
		return -1;

	if (!data->arr)
		return -1;

	int i = 0;
	while (i < data->len) {
		if (val == data->arr[i]) {
			int j = i;
			while (j != (data->len - 1)) {
				data->arr[j] = data->arr[j + 1];
				j++; 	
			}
			break;
		}
		i++;
	}

	if (i == data->len)
		return -1;

	data->len--;
	if (!data->len) {
		free(data->arr);
		free(*d);
		*d = NULL;
		return 0;
	}

	int *new_arr;
	new_arr = realloc(data->arr, sizeof(int) * (data->len));
	if (!new_arr)
		exit(EXIT_FAILURE);

	return 0;
}

void merge(int *arr, int left, int right, int mid)
{
	int left_count = mid - left + 1;
	int right_count = right - mid;
	int i, j, k;

	int *left_arr, *right_arr;
	left_arr = malloc(sizeof(int) * left_count);
	right_arr = malloc(sizeof(int) * right_count);

	if ((!left_arr) || (!right_arr))
		exit(EXIT_FAILURE);

	for (i = 0; i < left_count; i++)
		left_arr[i] = arr[left + i];

	for (j = 0; j < right_count; j++)
		right_arr[j] = arr[mid + 1+ j];

	i = 0; j = 0; k = left;

	while (i < left_count && j < right_count) {
		if (left_arr[i] < right_arr[j])
			arr[k] = left_arr[i++];
		else
			arr[k] = right_arr[j++];
		k++;
	}

	while (i < left_count) {
		arr[k] = left_arr[i];
		i++;
		k++;
	}

	while (j < right_count) {
		arr[k] = right_arr[j];
		j++;
		k++;
	}

	free(left_arr);
	free(right_arr);
}

void do_sort(int *arr, int left, int right)
{
	if (left < right) {
		int mid = (left + right ) / 2;
		do_sort(arr, left, mid);
		do_sort(arr, mid + 1, right);
		merge(arr, left, right, mid);
	}
}

int mergesort(struct data *d)
{

	if (!d)
		return -1;

	if (!d->arr)
		return -1;

	do_sort(d->arr, 0, (d->len - 1));

	return 0;
}


int main()
{
	printf("\nMergesort\n\n");

	int option;
	struct data *d = NULL;

	while (1) {
		printf("\nEnter the option number:\n");
		printf("1. Insert data \n");
		printf("2. Remove data \n");
		printf("3. Sort Array \n");
		printf("4. Print Array \n");
		printf("5. Exit\n");
		printf("\n\n");

		printf("Enter the option number: ");
		scanf("%d", &option);
		int data , position;

		switch (option) {
		case 1:
			printf("Enter data to be inserted: ");
			scanf("%d", &data);
			insert_data(&d, data);
			break;
		case 2:
			printf("Enter data to be removed: ");
			scanf("%d", &data);
			remove_data(&d, data);
			break;
		case 3:
			mergesort(d);
			printf("Sorted Array:\n");
			print_array(d);
			break;
		case 4:
			print_array(d);
			break;
		case 5:
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("Invalid Option\n");
		}
	}
	return 0;
}

