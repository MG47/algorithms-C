/*
* Queue
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct queue {
	int size;
	int maxsize;
	int front;
	int rear;
	int data[];
};

struct queue *init_queue(int maxsize)
{
	struct queue *q;
	if (maxsize <= 0)
		return NULL;

	q = calloc(1, sizeof(struct queue) + maxsize *  sizeof(int));
	if (!q)
		return NULL;
	
	q->front = q->rear = q->size = 0;
	q->maxsize = maxsize;
	return q;
}

void destroy_queue(struct queue **q)
{
	free(*q);
	*q = NULL;
}

int is_full(struct queue *q)
{
	return (q->size == q->maxsize);
}

int is_empty(struct queue *q)
{
	return (q->size == 0);
}

int insert_at_rear(struct queue *q, int *data, int count)
{
	int offset;
	if (!q || is_full(q) || !data)
		return -1;

	if (count > (q->maxsize - q->size))
		count = q->maxsize - q->size;

	if ((q->rear + count) > q->maxsize) {
		offset = q->maxsize - q->rear;
		memcpy(&q->data[q->rear], data, offset * sizeof(int));
		memcpy(&q->data[0], (data + offset) , (count - offset) * sizeof(int));
		q->rear = count - offset;
	} else {
		memcpy(&q->data[q->rear], data, count * sizeof(int));
		q->rear += count;
	}

	q->rear %= q->maxsize;
	q->size += count;
	return count;
}

int remove_from_front(struct queue *q, int *data, int count)
{
	int offset;
	if ((!q) || (is_empty(q)) || !data)
		return -1;

	if (count > q->size)
		count = q->size;

	if ((q->front + count) > q->maxsize) {
		offset = q->maxsize - q->front;
		memcpy(data, &q->data[q->front], offset * sizeof(int));
		memcpy((data + offset), &q->data[0], (count - offset) * sizeof(int));
		memset(&q->data[0], '\0', (count - offset) * sizeof(int));
		q->front  = count - offset;
	} else {
		memcpy(data, &q->data[q->front], count * sizeof(int));
		memset(&q->data[q->front], '\0', count * sizeof(int));
		q->front += count;
	}

	q->front %= q->maxsize;
	q->size -= count;
	return count;
}

void print_queue(struct queue *q)
{
	int i = 0;

	if (!q)
		return;

	printf("Queue rear: %d\n", q->rear);
	printf("Queue front: %d\n", q->front);
	printf("No of items: %d\n", q->size);
	printf("Current queue size: %d\n", q->maxsize);
	while (i < q->maxsize) {
		printf("%d - %d \n", i, q->data[i]);
		i++; 	// separated statment to suppress sequence point warning
	}
}

int main()
{
	printf("\nQueue\n\n");

	int option;
	struct queue *q = NULL;

	while (1) {
		printf("\nOptions:\n");
		printf("1. Initialize queue \n");
		printf("2. Push data \n");
		printf("3. Pop data \n");
		printf("4. Destroy queue\n");
		printf("5. Print queue contents\n");
		printf("6. Exit\n");
		printf("\n\n");

		printf("Enter the option number: ");
		scanf("%d", &option);
		int data[300], ret, size, i;

		switch (option) {
		case 1:
			if (q) {
				printf("Queue already exists\n");
				continue;
			}
			printf("Enter the size of the queue: ");
			scanf(" %d", &size);
			q = init_queue(size);
			if (!q) {
				printf("Not enough memory");
				exit(EXIT_FAILURE);
			}
			printf("Created a queue\n");
			break;
		case 2:
			printf("Enter count of items to be pushed: \n");
			scanf(" %d", &size);
			printf("Enter data to be pushed: \n");
			i = 0;
			while (i != size) {
				printf("%d: ", i);
				scanf(" %d", &data[i]);	
				printf("read %d\n", data[i]);
				i++;
			}
			ret = insert_at_rear(q, data, size);
			if (ret == -1)
				printf("queue is full\n");
			break;
		case 3:
			printf("Enter count of items to be pulled: ");
			scanf(" %d", &size);
			ret = remove_from_front(q, data, size);
			if (ret == -1) {
				printf("Queue is empty \n");
				continue;
			}
			i = 0;
			while (ret--)
				printf("item at the front: %d", data[i++]);
			break;
		case 4:
			destroy_queue(&q);
			printf("Destroyed the queue\n");
			break;
		case 5:
			print_queue(q);
			break;
		case 6:
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("Invalid Option\n");
		}
	}
	return 0;
}
