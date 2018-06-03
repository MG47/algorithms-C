/*
* Min Heap
* INCOMPLETE
* 
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

void min_heapify(int *arr, int size, int i)
{
	int left, right, min;
	left = 2 * i + 1;
	right = 2 * i + 2;

	if (left >= size)
		return;

	if (arr[left] < arr[i] && left < size)
		min = left;
	else
		min = i;
	if (arr[right] < arr[i] && right < size)
		min = right;
	if (min != i) {
		int temp;
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
		min_heapify(arr, size, min);
	}
}

void arrange_heap(struct heap *h)
{
	int i;
	if (!h || !h->heap_arr)
		return;

	for (i = (h->size) / 2; i >= 0; i--)
		min_heapify(h->heap_arr, h->size, i);
}

int find_max(struct heap *h)
{

	int max, i;
	if (!h || !h->heap_arr)
		return;

	max = h->heap_arr[0];
	for (i = (h->size) / 2; i < h->size; i++)
		if (h->heap_arr[i] < max)
			max = h->heap_arr[i];
	return max;
}

int find_min(struct heap *h)
{
	if (!h || !h->heap_arr)
		return;

	return h->heap_arr[0];
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
	arrange_heap(heap);
	return 0;
}

int remove_data(struct heap **h, int data)
{
	struct heap *heap = *h;
	if (!heap || !heap->heap_arr)
		return;

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

	heap->heap_arr = new_heap_arr;
	arrange_heap(heap);
	return 0;
}

int search(struct heap *h, int data)
{
	int i = 0;
	if (!h || !h->heap_arr)
		return;

	while (i < h->size) {
		if (data == h->heap_arr[i]) {
			return i; 
		}
		i++;
	}
	return -1;
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
	printf("\nMin Heap\n\n");

	int option;
	struct heap *h = NULL;

	while (1) {
		printf("\nEnter the option number:\n");
		printf("1. Insert data \n");
		printf("2. Remove data \n");
		printf("3. Search \n");
		printf("4. Find min value\n");
		printf("5. Find max value\n");
		printf("6. Print heap\n");
		printf("7. Exit\n");
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
			int max;
			max = find_max(h);
			printf("Max value in the tree : %d", max);
			break;
		}
		case 5:
		{
			int min;
			min = find_min(h);
			printf("Min value in the tree : %d", min);
			break;
		}
		case 6:
			print_heap(h);
			break;
		case 7:
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("Invalid Option\n");
		}
	}
	return 0;
}

