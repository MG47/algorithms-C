/*
* Producer-consumer problem (Bounded-buffer problem)
* Multiple Producers - Multiple Consumers
* Shared data structure is a circular queue
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_PRODUCERS 10
#define NUM_CONSUMERS 10

sem_t fill_count;
sem_t empty_count;
pthread_mutex_t buffer_lock;

struct queue {
	int head;
	int tail;
	int size;
	int maxsize;
	int data[];
};

struct queue *init_queue(int maxsize)
{
	struct queue *q = calloc(1, (sizeof(struct queue) + sizeof(int) * maxsize));
	if (!q)
		exit(EXIT_FAILURE);
	q->maxsize = maxsize;
	return q;
}

int destroy_queue(struct queue *q)
{
	free(q);
	return 0;
}

int is_full(struct queue *q)
{
	return (q->size == q->maxsize);
}

int is_empty(struct queue *q)
{
	return (q->size == 0);
}

int insert_at_head(struct queue *q, int data)
{
	if (!q)
		return -1;

	if (is_full(q))
		return -1;

	q->data[q->head++] = data;
	q->head %= q->maxsize;
	q->size++; 
	return 0;
}

int remove_from_tail(struct queue *q)
{
	int ret;

	if ((!q) || (is_empty(q)))
		return 0;

	ret = q->data[q->tail];
	q->data[q->tail++] = 0;
	q->tail %= q->maxsize;
	q->size--;
	return ret;
}

void print_queue(struct queue *q)
{
	int i = 0;

	if ((!q) || (is_empty(q)))
		return;

	printf("Current queue size: %d\n", q->size);
	while (i < q->maxsize) {
		printf("%d - %d \n", i, q->data[i]);
		i++;
	}
}

void *producer(void *queue)
{
	pthread_t tid;
	struct queue *q = queue;
	int new_data, i = 1;
	tid = pthread_self();
	printf("PRODUCER %lu: started\n", tid);

	while (i < 5) {
		new_data = i++; // i is local to thread

		/* Go to sleep (block) if buffer is full */
		sem_wait(&empty_count);
		/* Lock buffer to check that queue is not full and put data atomically */
		pthread_mutex_lock(&buffer_lock);
		insert_at_head(q, new_data);
		pthread_mutex_unlock(&buffer_lock);
		printf("PRODUCER %lu: produced data\n", tid);
		print_queue(q);
		/* Signal that one slot in the buffer is full */
		sem_post(&fill_count);
	}
	pthread_exit(NULL);
}

void *consumer(void *queue)
{
	pthread_t tid;
	struct queue *q = queue;
	int consumed_data;
	tid = pthread_self();
	printf("CONSUMER %lu: started\n", tid);

	while (1) {
		/* Wait (block) if buffer is empty */
		sem_wait(&fill_count);
		/* Lock buffer to check that queue is not empty and get data atomically */
		pthread_mutex_lock(&buffer_lock);
		consumed_data = remove_from_tail(q);
		pthread_mutex_unlock(&buffer_lock);
		printf("CONSUMER %lu: consumed data: %d\n", tid, consumed_data);
		print_queue(q);
		/* Signal that one buffer slot is available */
		sem_post(&empty_count);
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t tid[20] = {0};
	int i, err;

	/* Initialize Queue */
	struct queue *q = init_queue(5);

	if (!q)
		exit(EXIT_FAILURE);
	print_queue(q);

	/* For basic producer-consumer solution */
	sem_init(&fill_count, 0, 0);
	sem_init(&empty_count, 0, q->maxsize);

	/* To protect buffer from multiple producers or multipler consumers*/
	pthread_mutex_init(&buffer_lock, NULL);

	for (i = 0; i < NUM_CONSUMERS; i++) {
		err = pthread_create(&tid[i], NULL, &producer, q);
		if (err)
			exit(EXIT_FAILURE);

		err = pthread_create(&tid[i + 1], NULL, &consumer, q);
		if (err)
			exit(EXIT_FAILURE);

	}

	for (i = 0; i < (NUM_CONSUMERS + NUM_PRODUCERS); i++) 
		pthread_join(tid[i], NULL);

	return 0;
}

