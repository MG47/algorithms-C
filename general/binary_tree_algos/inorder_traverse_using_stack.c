/* 
* In-order traversal of a binary tree using stack 
*/


#include <stdio.h>
#include <stdlib.h>

struct stack {
	int top;
	int maxsize;
	struct node *stack_arr[];
};

struct node {
	int data;
	struct node *left; 
	struct node *right;
};

/* TODO: Make dynamically growing stack */
struct stack *init_stack(int maxsize)
{
	struct stack *s;
	s = calloc(1, ((sizeof(struct stack) + maxsize * sizeof(struct node *))));
	if (!s)
		return NULL;

	s->maxsize = maxsize;
	s->top = -1;

	return s;
}

struct stack *destroy_stack(struct stack *s)
{
	free(s);
	return NULL;
}

int push(struct stack *s, struct node *root)
{
	if (!s)
		return -1;

	if (s->top == (s->maxsize - 1))
		return -1;

	s->top++;
	s->stack_arr[s->top] = root;
	return 0;
}

int is_empty(struct stack *s)
{
	return (s->top == -1);
}

struct node *pop(struct stack *s)
{
	struct node *root;
	if (!s)
		return 0;
	
	if (s->top == -1)
		return 0;

	root = s->stack_arr[s->top];
	
	if ((s->top) > -1)
		s->top--;

	return root;
}
 
struct node *create_node(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
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

	while(pos != (s->top)) {
		printf("%d -> %d\n",pos, s->stack_arr[pos]->data);
		pos++;
	}

	printf("%d -> %d (top of stack)\n", pos, s->stack_arr[s->top]->data);
}

void traverse_inorder(struct node *root)
{
	int flag = 0;
	struct stack *s;
	s = init_stack(100);

	if (!root)
		return;

	while (!flag) {
		if (root) {
			push(s, root);
			root = root->left;
		} else {
			if (!is_empty(s)) {
				root = pop(s);
				printf("%d ", root->data);
				root = root->right;
			} else {
				flag = 1;
			}
		}
	}
	printf("\n\n");
	destroy_stack(s);
}

int main()
{
	struct node *root;
	
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->right->left = create_node(5);
	root->right->right = create_node(6);

	traverse_inorder(root);
	
	return 0;
}

