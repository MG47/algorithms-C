/*
* Merge Overlapping Intervals
* INCOMPLETE
*/

#include <stdio.h>
#include <stdlib.h>

struct stack {
	struct interval **stack_arr;
	int top;
	int maxsize;
};

struct interval {
	int start;
	int end;
};

struct interval_table {
	struct interval **intv;
	int maxsize;
	int size;
};

struct stack *init_stack(int maxsize)
{
	struct stack *s;
	s = malloc(sizeof(struct stack));
	if (!s)
		return NULL;

	s->maxsize = maxsize;
	s->stack_arr = calloc((s->maxsize), sizeof(struct interval *));
	if (!(s->stack_arr)) {
		free(s);
		return NULL;
	}

	s->top = -1;
	return s;
}

struct stack *destroy_stack(struct stack *s)
{
	if (!s)
		return 0;

	free(s->stack_arr);
	free(s);
	return NULL;
}

int partition(struct interval **intv, int left, int right)
{
	int i, j, pivot;

	i = left - 1;
	pivot = intv[right]->start;
	for (j = left; j <= right - 1; j++) {
		if (intv[j]->start <= pivot) {
			struct interval *temp = intv[j];
			intv[j] = intv[right];
			intv[right] = temp;
		}
	}

	struct interval *temp = intv[i + 1];
	intv[i + 1] = intv[right];
	intv[right] = temp;	

	return (i + 1);
}

void do_sort(struct interval **intv, int left, int right)
{
	if (left < right) {
		int p_index;
		p_index = partition(intv, left, right);
		do_sort(intv, 0, p_index - 1);
		do_sort(intv, p_index + 1, right);
	}
}

void sort_intervals(struct interval_table *int_table)
{
	if (!int_table)
		return;

	do_sort(int_table->intv, 0, (int_table->size - 1));
}

int push(struct stack *s, struct interval *intv)
{
	if (!s)
		return -1;

	if (s->top == (s->maxsize - 1))
		return -1;

	s->top++;
	s->stack_arr[s->top] = intv;
	return 0;
}

struct interval *pop(struct stack *s)
{
	struct interval *intv;
	if (!s)
		return NULL;
	
	if (s->top == -1)
		return NULL;

	intv = s->stack_arr[s->top];
	
	if ((s->top) > -1)
		s->top--;

	return intv;
}

void create_interval(struct interval_table *int_table, int start, int end)
{
	struct interval *in;
	if (int_table->size == int_table->maxsize)
		return;

	in = malloc(sizeof(struct interval));
	if (!in)
		exit(EXIT_FAILURE);

	int_table->intv[int_table->size] = in;
	int_table->intv[int_table->size]->start = start;
	int_table->intv[int_table->size]->end = end;
	int_table->size++;
}

struct interval_table *create_interval_table(int size)
{
	struct interval_table *int_table = malloc(sizeof(struct interval_table));
	if (!int_table)
		exit(EXIT_FAILURE);

	int_table->maxsize = size;
	int_table->intv = malloc(size * sizeof(struct interval));
	if (!int_table->intv)
		exit(EXIT_FAILURE);
	int_table->size = 0;
	return int_table;
}

void merge_intervals(struct interval_table *int_table)
{
	struct stack *s;
	int i;
	if (!int_table)
		return;

	s = init_stack(int_table->size);
	sort_intervals(int_table);

	push(s, int_table->intv[0]);
	for (i = 1; i < int_table->size; i++) {
		struct interval *top = pop(s);
		if (top->end < (int_table->intv[i]->start)) {
			push(s, int_table->intv[i]);
		} else if (top->end < int_table->intv[i]->end) {
			top->end = int_table->intv[i]->end;
			pop(s);
			push(s, top);
		}
	}

	for (i = 0; i < int_table->size; i++) {
		struct interval *intv_new = pop(s);
		if (!intv_new) {
			int_table->size = i;
			break;
		}
		int_table->intv[i] = intv_new;
	}
	s = destroy_stack(s);
}

void print_intervals(struct interval_table *int_table)
{
	int i = 0;
	if (!int_table)
		return;

	while (i < int_table->size) {
		printf("{%d,", int_table->intv[i]->start);
		printf(" %d}", int_table->intv[i]->end);
		printf(",\n");
		i++;
	}
}

int main()
{
	printf("\nMerge Overlapping Intervals\n\n");

	int option;
	struct interval_table *int_table = NULL;
	int_table = create_interval_table(10);

	while (1) {
		printf("\nEnter the option number:\n");
		printf("1. Create Interval \n");
		printf("2. Merge Intervals \n");
		printf("3. Print Intervals \n");
		printf("4. Exit\n");
		printf("\n\n");

		printf("Enter the option number: ");
		scanf("%d", &option);
		int data1, data2, position;

		switch (option) {
		case 1:
			printf("Enter Start of Interval: ");
			scanf("%d", &data1);
			printf("Enter End of Interval: ");
			scanf("%d", &data2);
			create_interval(int_table, data1, data2);
			break;
		case 2:
			merge_intervals(int_table);
		case 3:
			print_intervals(int_table);
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

