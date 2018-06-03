/*
* Max Heap
* INCOMPLETE
*/

#include <stdio.h>
#include <stdlib.h>

struct heap {
	int *heap_arr;
	int size;
};

struct heap *create_heap(int data)
{
	struct heap *h;
	h = malloc(sizeof(struct heap));
	if (!h)
		exit(EXIT_FAILURE);

	h->heap_arr = malloc(sizeof(int));
	if (!h->heap_arr)
		exit(EXIT_FAILURE);

	h->heap_arr[0] = data;
	h->size = 1;
	return h;
}

void max_heapify(int *arr, int size, int i)
{
	int left, right, max;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left >= size)
		return;

	if (arr[left] > arr[i] && left < size)
		max = left;
	else
		max = i;
		
	if (arr[right] > arr[i] && right < size)
		max = right;

	if (max != i) {
		int temp;
		temp = arr[max];
		arr[max] = arr[i];
		arr[i] = temp;
		max_heapify(arr, size, max);
	}
}

void arrange_heap(struct heap *h)
{
	int i;
	if (!h || !h->heap_arr)
		return;

	for (i = (h->size) / 2; i >= 0; i--)
		max_heapify(h->heap_arr, h->size, i);
}

int find_max(struct heap *h, int *val)
{
	if (!h || !h->heap_arr)
		return -1;

	*val = h->heap_arr[0];
	return 0;
}

int find_min(struct heap *h, int *val)
{
	int min, i;
	if (!h || !h->heap_arr)
		return -1;

	min = h->heap_arr[0];
	for (i = (h->size) / 2; i < h->size; i++)
		if (h->heap_arr[i] < min)
			min = h->heap_arr[i];
	*val = min;
	return 0;
}

void insert_data(struct heap **h, int data)
{
	struct heap *hp = *h;
	if (!(*h)) {
		*h = create_heap(data);
		return;
	}

	hp->size++;
	int *new_heap_arr;
	new_heap_arr = realloc(hp->heap_arr, sizeof(int) * (hp->size));
	if (!new_heap_arr)
		exit(EXIT_FAILURE);

	hp->heap_arr = new_heap_arr;
	hp->heap_arr[(hp->size) - 1] = data;
	arrange_heap(hp);
	return;
}

int remove_data(struct heap **h, int data)
{
	struct heap *hp = *h;
	if (!hp || !hp->heap_arr)
		return -1;

	int i = 0;
	while (i < hp->size) {
		if (data == hp->heap_arr[i]) {
			int j = i;
			while (j != (hp->size - 1)) {
				hp->heap_arr[j] = hp->heap_arr[j + 1];
				j++; 	
			}
			break;
		}
		i++;
	}

	if (i == hp->size)
		return -1;

	hp->size--;
	if (!hp->size) {
		free(hp->heap_arr);
		free(*h);
		*h = NULL;
		return 0;
	}

	int *new_heap_arr;
	new_heap_arr = realloc(hp->heap_arr, sizeof(int) * (hp->size));
	if (!new_heap_arr)
		exit(EXIT_FAILURE);

	hp->heap_arr = new_heap_arr;
	arrange_heap(hp);
	return 0;
}

int search(struct heap *h, int data)
{
	int i = 0;
	if (!h || !h->heap_arr)
		return -1;

	while (i < h->size) {
		if (data == h->heap_arr[i]) {
			return i; 
		}
		i++;
	}
	return -1;
}

int extract_max(struct heap **h, int *max)
{
	struct heap *hp = *h;
	if (!hp || !hp->heap_arr)
		return -1;	
	
	if (hp->size == 1) {
		*max = h->heap_arr[0];
		free(hp->heap_arr);
		free(*h);
		*h = NULL;
		return 0;
	}

	*max = hp->heap_arr[0];
	hp->heap_arr[0] = hp->heap_arr[hp->size - 1];
	hp->size--;

	max_heapify(0);
	return 0;
}

void print_heap(struct heap *h)
{
	if (!h) {
		printf("Heap does not exist\n");
		return;
	}

	if (!h->heap_arr) {
		printf("Heap is empty\n");
		return;
	}
	printf("Heap size: %d\n", h->size);

	int i = 0;
	while (i < h->size) {
		printf("%d - %d\n", i, h->heap_arr[i]);
		i++;
	}
}

int main()
{
	printf("\nMax Heap\n\n");

	int option;
	struct heap *h = NULL;

	while (1) {
		printf("\nEnter the option number:\n");
		printf("1. Insert data \n");
		printf("2. Remove data \n");
		printf("3. Search \n");
		printf("4. Find max value\n");
		printf("5. Find min value\n");
		printf("6. Extract Max\n");
		printf("7. Print heap\n");
		printf("8. Exit\n");
		printf("\n\n");

		printf("Enter the option number: ");
		scanf("%d", &option);
		int data;

		switch (option) {
		case 1:
			printf("Enter data to be inserted: ");
			scanf("%d", &data);
			insert_data(&h, data);
			break;
		case 2:
			printf("Enter data to be removed: ");
			scanf("%d", &data);
			remove_data(&h, data);
			break;
		case 3:
		{
			int i;
			printf("Enter data to search:");
			scanf(" %d", &data);
			i = search(h, data);
			if (i >= 0)
				printf("Data found at index %d: %d\n", i, h->heap_arr[i]);
			break;
		}
		case 4:
		{
			int ret, int *val;
			ret = find_max(h, val);
			if (ret)
				printf("Max value in the tree : %d", *val);
			else
				printf("Error: Heap does not exist \n");
			break;
		}
		case 5:
		{
			int ret, int *val;
			ret = find_min(h, val);
			if (ret)
				printf("Min value in the tree : %d", *val);
			else
				printf("Error: Heap does not exist \n");
			break;
		}
		case 6:
		{
			int ret, int *val;
			ret = extract_max(h, val);
			if (ret)
				printf("Max value in the tree : %d", *val);
			else
				printf("Error: Heap does not exist \n");
			break;
		}
		case 7:
			print_heap(h);
			break;
		case 8:
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("Invalid Option\n");
		}
	}
	return 0;
}

