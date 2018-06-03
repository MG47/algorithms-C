/*
* Stack
* INCOMPLETE
* TODO Make dynamically growing stack
* 
*/

#include <stdio.h>
#include <stdlib.h>

struct stack {
	int top;
	int maxsize;
	int stack_arr[];
};

struct stack *init_stack(int maxsize)
{
	struct stack *s;
	if (maxsize < 0) {
		printf("Invalid stack size \n");
		exit(EXIT_FAILURE);
	}
	s = calloc(1, sizeof(struct stack) + maxsize * sizeof(int));
	if (!s)
		return NULL;

	s->maxsize = maxsize;
	s->top = -1;
	return s;
}

void destroy_stack(struct stack *s)
{
	free(s);
	s = NULL;
}

int push(struct stack *s, int data)
{
	if (!s || (s->top == (s->maxsize - 1)))
		return -1;
	
	s->top++;
	s->stack_arr[s->top] = data;
	return 0;
}

int peek(struct stack *s, int *data)
{
	if (!s || s->top == -1)
		return -1;

	*data = s->stack_arr[s->top];
	return 0;
}

int pop(struct stack *s, int *data)
{
	if (!s || s->top == -1)
		return -1;
	
	*data = s->stack_arr[s->top--];
	return 0;
}

void print_stack(struct stack *s)
{
	int pos = 0;
	if (!s) {
		printf("Stack does not exist\n");
		return;
	}

	if (s->top == -1) {
		printf("Stack is empty \n");
		return;
	}

	while (pos != s->top) {
		printf("%d -> %d\n",pos, s->stack_arr[pos]);
		pos++;
	}

	printf("%d -> %d (top of stack)\n", pos, s->stack_arr[s->top]);
}
	
int main()
{
	printf("\nStack\n\n");

	int option;
	struct stack *s = NULL;

	while (1) {
		printf("\nOptions:\n");
		printf("1. Initialize stack \n");
		printf("2. Push data \n");
		printf("3. Pop data \n");
		printf("4. Peek\n");
		printf("5. Destroy stack\n");
		printf("6. Print Stack contents\n");
		printf("7. Exit\n");
		printf("\n\n");

		printf("Enter the option number: ");
		scanf("%d", &option);
		int data , ret;
		data = 0;

		switch (option) {
		case 1:
			if (s) {
				printf("Stack already exists\n");
				continue;
			}
			printf("Enter the size of the stack: ");
			scanf(" %d", &data);
			s = init_stack(data);
			if (!s) {
				printf("Not enough memory");
				exit(EXIT_FAILURE);
			}
			printf("Created a stack\n");
			break;
		case 2:
			printf("Enter data to be pushed: ");
			scanf("%d", &data);
			ret = push(s, data);
			if (ret == -1)
				printf("Stack if full\n");
			break;
		case 3:
			ret = pop(s, &data);
			if (ret == -1) {
				printf("Stack is empty \n");
				continue;
			}
			printf("Value at the top of stack: %d", data);
			break;
		case 4:
			ret = peek(s, &data);
			if (ret == -1) {
				printf("Stack is empty \n");
				continue;
			}
			printf("Value at the top of stack: %d", data);
			break;
		case 5:
			destroy_stack(s);
			printf("Destroyed the stack\n");
			break;
		case 6:
			print_stack(s);
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
