/*
* Depth-First Traversal
* INCOMPLETE
*/

#include <stdio.h>
#include <stdlib.h>

struct stack {
	void *arr;
	int top;
	int size;
};

struct stack *create_stack(int size)
{
	struct stack *s;
	if (size <= 0)
		return NULL;

	s = malloc(sizeof(struct stack *));
	if (!s)
		return NULL;

	s->size = size;
	s->top = -1;
	s->arr = calloc(s->size, sizeof(void *));
	if (!s->arr)
		return NULL;
	return s;
}

int push(struct stack *s, int data)
{
	int *arr;
	if (!s)
		return -1;
	if (!s->arr)
		return -1;

	if (s->top < s->size)
		s->top++;
	else
		return -1;

	arr = s->arr;
	arr[s->top] = data;
	return 0;
}

int pop(struct stack *s)
{
	int data;
	int *arr;
	if (!s)
		return 0; //fix errno
	if (!s->arr)
		return 0;

	if (s->top < 0)
		return 0;
	arr = s->arr;
	data = arr[s->top];
	s->top--;
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

void traverse_depth_first(struct graph *g)
{
	int *visited, *traverse_arr;
	struct stack *s;
	int i, j, k;

	if (!g)
		return;

	if (!g->adj_matrix)
		return;

	visited = calloc(g->size, sizeof(int));
	if (!visited)
		return;

	traverse_arr = calloc(g->size, sizeof(int));
	if (!traverse_arr)
		return;

	s = create_stack(g->size);
	if (!s)
		return;

	k = 0;
	push(s, 0);
	visited[0] = 1;
	
	while (s->top > -1) {
		i = pop(s);
		traverse_arr[k++] = i;
		for (j = 0; j < g->size; j++) {
			if (g->adj_matrix[i][j]) {
				if (s->top == s->size)
					exit(EXIT_FAILURE);
				if (!visited[j]) {
					visited[j] = 1;
					push(s, j);
				}
			}
		}
	}
	i = 0;
	while (i < g->size) {
		printf("%d -> ", traverse_arr[i++]);
	}
	printf("done\n");
}

int main()
{
	printf("\nDepth-First Traversal\n\n");

	int option;
	struct graph *g = NULL;

	while (1) {
		printf("\nEnter the option number:\n");
		printf("1. Create Random Graph \n");
		printf("2. Perform Depth-First Traversal\n");
		printf("3. Print Graph \n");
		printf("4. Exit\n");
		printf("\n\n");

		printf("Enter the option number: ");
		scanf("%d", &option);
		int i = 0;
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
			traverse_depth_first(g);
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

