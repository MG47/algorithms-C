/*
* Insertionsort
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

int insertionsort(struct data *d)
{
	int i, cur_val, j;
	if (!d)
		return -1;

	if (!d->arr)
		return -1;

	for (i = 1; i < d->len; i++) {
		cur_val = d->arr[i];
		j = i - 1;
		while (j >= 0 && d->arr[j] > cur_val) {
			d->arr[j + 1] = d->arr[j];
			j--;
		}
		d->arr[j + 1] = cur_val;
	}
	return 0;
}

int main()
{
	printf("Insertionsort\n\n");

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
			insertionsort(d);
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

