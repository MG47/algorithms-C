/*
* Breadth-First Traversal
*/

#include <stdio.h>
#include <stdlib.h>

struct queue {
	int *arr;
	int size;
	int maxsize;
	int head;
	int tail;
};

struct queue *create_queue(int maxsize)
{
	struct queue *q;

	if (maxsize <= 0)
		return NULL;

	q = malloc(sizeof(struct queue));
	if (!q)
		exit(EXIT_FAILURE);
	q->arr = calloc(maxsize, sizeof(int));
	if (!q->arr)
		exit(EXIT_FAILURE);

	q->maxsize = maxsize;
	q->size = 0;
	q->head = 0;
	q->tail = 0;
	return q;
}

void destroy_queue(struct queue *q)
{
	if (!q)
		return;
	free(q->arr);
	free(q);
}

int queue_empty(struct queue *q)
{
	return (q->size == 0);
}

int queue_full(struct queue *q)
{
	return (q->size == q->maxsize);
}

void insert_at_tail(struct queue *q, int data)
{
	if (!q || !q->arr)
		return;

	if (!queue_full(q))
		q->arr[q->tail] = data;
	else
		return;

	q->tail++;
	q->tail %= q->maxsize;
	q->size++;
}

int remove_from_head(struct queue *q)
{
	int data;
	if (!q || !q->arr)
		return 0;

	if (!queue_empty(q))
		data = q->arr[q->head];
	else
		return 0;
	q->head++;
	q->head %= q->maxsize;
	q->size--;
	return data;
}

struct graph {
	int size;
	int **adj_matrix;
};

void create_random_edges(struct graph *g)
{
	if (!g)
		return;

	if (!g->adj_matrix)
		return;

	g->adj_matrix[0][1] = 1;
	g->adj_matrix[0][4] = 1;
	g->adj_matrix[1][0] = 1;
	g->adj_matrix[1][2] = 1;
	g->adj_matrix[1][3] = 1;
	g->adj_matrix[2][1] = 1;
	g->adj_matrix[2][3] = 1;
	g->adj_matrix[3][1] = 1;
	g->adj_matrix[3][2] = 1;
	g->adj_matrix[3][4] = 1;
	g->adj_matrix[4][0] = 1;
	g->adj_matrix[4][3] = 1;

	return;
}

struct graph *create_random_graph(struct graph **g, int *input_arr, int size)
{
	struct graph *graph;
	int i = 0;

	if (*g) {
		printf("Graph already exits\n");
		return NULL;
	}

	if (!input_arr)
		return NULL;
	
	graph = malloc(sizeof(struct graph));
	if (!graph)
		exit(EXIT_FAILURE);

	graph->size = size;
	graph->adj_matrix = malloc(size * sizeof(int *));

	while (i < size) {
		graph->adj_matrix[i] = calloc(size, sizeof(int));
		i++;
	}

	if (!graph->adj_matrix)
		exit(EXIT_FAILURE);

	create_random_edges(graph);
	*g = graph;
	return (*g);
}

void print_graph(struct graph *g)
{
	if (!g) {
		printf("Graph does not exist\n");
		return;
	}

	if (!g->adj_matrix) {
		printf("Graph is empty\n");
		return;
	}
	printf("Graph size: %d\n", g->size);

	int i, j;
	for (i = 0; i < g->size; i++) {
		for (j = 0; j < g->size; j++) {
			if (g->adj_matrix[i][j])
				printf("%d -> %d\n", i , j);
		}
	}
}

void traverse_breadth_first(struct graph *g)
{
	int *visited, *traverse_arr;
	struct queue *q;
	int i, j, k;

	if (!g || !g->adj_matrix)
		return;

	visited = calloc(g->size, sizeof(int));
	if (!visited)
		exit(EXIT_FAILURE);

	traverse_arr = calloc(g->size, sizeof(int));
	if (!traverse_arr)
		exit(EXIT_FAILURE);

	q = create_queue(g->size);
	if (!q)
		exit(EXIT_FAILURE);

	k = 0;
	insert_at_tail(q, 0);
	visited[0] = 1;

	while (!queue_empty(q)) {
		i = remove_from_head(q);
		traverse_arr[k++] = i;
		for (j = 0; j < g->size; j++) {
			if (g->adj_matrix[i][j]) {
				if (queue_full(q))
					exit(EXIT_FAILURE);
				if (!visited[j]) {
					insert_at_tail(q, j);
					visited[j] = 1;
				}
			}
		}
	}

	i = 0;
	while (i < g->size) {
		printf("%d -> ", traverse_arr[i++]);
	}
	printf("done\n");
	destroy_queue(q);
	free(visited);
	free(traverse_arr);
}

int main()
{
	printf("\nBreadth-First Traversal\n\n");

	int option;
	struct graph *g = NULL;

	while (1) {
		printf("\nEnter the option number:\n");
		printf("1. Create Random Graph \n");
		printf("2. Perform Breadth-First Traversal\n");
		printf("3. Print Graph \n");
		printf("4. Exit\n");
		printf("\n\n");

		printf("Enter the option number: ");
		scanf("%d", &option);
		int *input_arr;

		input_arr = malloc(sizeof(int) * 100);
		if (!input_arr)
			exit(EXIT_FAILURE); 

		switch (option) {
		case 1:
			input_arr[0] = 0;
			input_arr[1] = 1;
			input_arr[2] = 2;
			input_arr[3] = 3;
			input_arr[4] = 4;
			create_random_graph(&g, input_arr, 5);
			break;
		case 2:
			traverse_breadth_first(g);
			break;
		case 3:
			print_graph(g);
			break;
		case 4:
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("Invalid Option\n");
		}
	}
	return 0;
}

