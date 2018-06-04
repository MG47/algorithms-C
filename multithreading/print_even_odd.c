/*
* Thread 1 prints even numbers and thread 2 prints odd numbers in a given array
* INCOMPLETE: TODO: add signals/cond vars
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//INCOMPLETE
pthread_t tid[2];
unsigned int array_index = 0;

int arr[10] = {1, 99, 3, 4, 1, 6, 7, 2, 9, 10};

void *print_even()
{

	while (array_index < 10) {
		if (!((arr[array_index]) % 2)) {
			printf("EVEN thread: print index: %d - %d\n", array_index, arr[array_index]);
			array_index++;
		}

	}
}

void *print_odd()
{
	while (array_index < 10) {
		if (((arr[array_index]) % 2)) {
			printf("ODD thread: print index: %d - %d\n", array_index, arr[array_index]);
			array_index++;		
		}
	}
}

int main()
{
	int i = 0;
	printf("ARRAY: ");
	while (i < 10) {
		printf("%d, ", arr[i++]);
	}
	printf("\n\n");

	pthread_create(&tid[0], 0, &print_even, 0);
	pthread_create(&tid[1], 0, &print_odd, 0);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	return 0;
}

