/*
* Readers-writers problem
* Multiple readers - multiple writers
* Service queue (semaphore) is used to prevent starving of writers or readers
* Shared data is an integer
* This solution does NOT use pthread_rwlock
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_READERS 5
#define NUM_WRITERS 5

int shared_var;
int read_count;

sem_t resource_access;
sem_t read_count_access;
sem_t service_queue;

void *reader()
{
	pthread_t tid;
	int i;
	tid = pthread_self() % 1000;
	printf("READER %lu: started\n", tid);

	while (i++ < 5) {

		/* Wait to be serviced */
		sem_wait(&service_queue);
		sem_wait(&read_count_access);

		/* If there are no active readers, request exclusive access */
		if (!read_count)
			sem_wait(&resource_access);
		read_count++;
		sem_post(&service_queue);
		sem_post(&read_count_access);
		
		printf("READER %lu: shared_var: %d\n", tid, shared_var);

		sem_wait(&read_count_access);
		read_count--;

		/* Release resource for waiting writers if there are no readers*/
		if (!read_count)
			sem_post(&resource_access);
		sem_post(&read_count_access);
	}
}

void *writer()
{
	pthread_t tid;
	int i = 0;
	tid = pthread_self() % 1000;
	printf("WRITER %lu: started\n", tid);

	while (i++ < 5) {

		/* Wait to be serviced */
		sem_wait(&service_queue);

		/* Access resource exclusively */
		sem_wait(&resource_access);
		sem_post(&service_queue);

		shared_var++;
		printf("WRITER %lu: shared_var: %d\n", tid, shared_var);
		sem_post(&resource_access);
	}
	while (1);
}

int main()
{
	pthread_t tid[10];
	int i;

	sem_init(&resource_access, 0, 1);
	sem_init(&read_count_access, 0, 1);
	sem_init(&service_queue, 0, 1);

	for (i = 0; i < NUM_WRITERS; i++) {
		pthread_create(&tid[i], NULL, &reader, NULL);
		pthread_create(&tid[i + 1], NULL, &writer, NULL);
	}

	for (i = 0; i < 10; i++) 
		pthread_join(tid[i], NULL);

	return 0;
}

