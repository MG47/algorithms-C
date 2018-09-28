/*
* Thread 1 prints even numbers and thread 2 prints odd numbers in a given array
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid[2] = {0};
int array_index = 0;

int arr[10] = {1, 99, 3, 4, 1, 6, 7, 2, 9, 10};

void *print_even()
{
	while (array_index < 10) {
		if (!((arr[array_index]) % 2)) {
			printf("EVEN thread: print index: %d : %d\n", array_index, arr[array_index]);
			array_index++;
		}

	}
	pthread_exit(NULL);
}

void *print_odd()
{
	while (array_index < 10) {
		if (((arr[array_index]) % 2)) {
			printf("ODD thread: print index: %d : %d\n", array_index, arr[array_index]);
			array_index++;		
		}
	}
	pthread_exit(NULL);
}

int main()
{
	int i = 0, err;
	printf("ARRAY: ");
	while (i < 10) {
		printf("%d, ", arr[i++]);
	}
	printf("\n\n");

	err = pthread_create(&tid[0], 0, &print_even, 0);
	if (err)
		exit(EXIT_FAILURE);

	err = pthread_create(&tid[1], 0, &print_odd, 0);
	if (err)
		exit(EXIT_FAILURE);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	return 0;
}

