/*
* Heapsort
* INCOMPLETE
*/

#include <stdio.h>
#include <stdlib.h>

struct heap {
	int *heap_arr;
	size_t size;
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


void print_array(struct heap *h)
{
	if (!h) {
		printf("Heap does not exist\n");
		return;
	}

	if (!h->heap_arr) {
		printf("Heap is empty\n");
		return;
	}
	printf("Heap size: %lu\n", h->size);

	int i = 0;
	while (i < h->size) {
		printf("%d - %d\n", i, h->heap_arr[i]);
		i++;
	}
}

void max_heapify(int *arr, int size, int i)
{
	int left, right, max;
	left = 2 * i + 1;
	right = 2 * i + 2;

	max = i;
	if (arr[left] > arr[i] && left < size)
		max = left;

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

int insert_data(struct heap **h, int data)
{
	struct heap *heap = *h;
	if (!(*h)) {
		*h = create_heap(data);
		return 0;
	}

	heap->size++;
	int *new_heap_arr;
	new_heap_arr = realloc(heap->heap_arr, sizeof(int) * (heap->size));
	if (!new_heap_arr)
		exit(EXIT_FAILURE);

	heap->heap_arr = new_heap_arr;

	heap->heap_arr[(heap->size) - 1] = data;
	return 0;
}

int remove_data(struct heap **h, int data)
{
	struct heap *heap = *h;
	if (!heap)
		return -1;

	if (!heap->heap_arr)
		return -1;

	int i = 0;
	while (i < heap->size) {
		if (data == heap->heap_arr[i]) {
			int j = i;
			while (j != (heap->size - 1)) {
				heap->heap_arr[j] = heap->heap_arr[j + 1];
				j++; 	
			}
			break;
		}
		i++;
	}

	if (i == heap->size)
		return -1;

	heap->size--;
	if (!heap->size) {
		free(heap->heap_arr);
		free(*h);
		*h = NULL;
		return 0;
	}

	int *new_heap_arr;
	new_heap_arr = realloc(heap->heap_arr, sizeof(int) * (heap->size));
	if (!new_heap_arr)
		exit(EXIT_FAILURE);

	return 0;
}

int heapsort(struct heap *h)
{
	int i, temp;

	if (!h)
		return -1;

	if (!h->heap_arr)
		return -1;

	int size = h->size;
	for (int i = size / 2 - 1; i >= 0; i--)
        	max_heapify(h->heap_arr, size, i);

	for (i = (((h->size) / 2) - 1); i > 0; i--)
		max_heapify(h->heap_arr, h->size, i);

	for (i = (h->size) - 1; i > 0; i--) {
		temp = h->heap_arr[0];
		h->heap_arr[0] = h->heap_arr[i];
		h->heap_arr[i] = temp;

		max_heapify(h->heap_arr, i, 0);
	}
	return 0;
}


int main()
{
	printf("\nHeapsort\n\n");

	int option;
	struct heap *h = NULL;

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
			insert_data(&h, data);
			break;
		case 2:
			printf("Enter data to be removed: ");
			scanf("%d", &data);
			remove_data(&h, data);
			break;
		case 3:
			heapsort(h);
			printf("Sorted Array:\n");
			print_array(h);
			break;
		case 4:
			print_array(h);
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

