/* 
* Check if linked list is palindrome
* Uses stack to store and check palindrome
*/ 

#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *next;
	int data;
};

struct node *create_node(int data)
{
	struct node *new;
	new = malloc(sizeof(struct node));
	if (!new)
		exit(EXIT_FAILURE);
	new->next = NULL;
	new->data = data;
	return new;
}

struct stack {
	int top;
	int size;
	int arr[];
};

struct stack *init_stack(size_t stack_size)
{
	struct stack *s;

	if (stack_size < 1)
		return NULL;
	s = calloc(1, (sizeof(struct stack) + stack_size * sizeof(int)));
	if (!s)
		exit(EXIT_FAILURE);
	s->size = stack_size;
	s->top = -1;
	return s;
}

void destroy_stack(struct stack **s)
{
	if (!s)
		return;
	free(*s);
	*s = NULL;
}

int push(struct stack *s, int data)
{
	if (!s || s->top == (s->size - 1))
		return 0;

	s->top++;
	s->arr[s->top] = data;
	return 0;
}

int pop(struct stack *s)
{
	int data;
	if (!s || (s->top == -1))
		return 0;

	data = s->arr[s->top--];
	return data;
}

int insert_at_head(struct node **head, int data)
{
	struct node *new;
	if (!(*head)) {
		*head = create_node(data);
		return 0;
	}
	new = create_node(data);
	new->next = *head;
	*head = new;
	return 0;
}

void print_linked_list(struct node *head)
{
	struct node *cur;
	cur = head;
	if (!cur)
		return;
	printf("(head)");

	while (cur) {
		printf(" %d ->", cur->data);
		cur = cur->next;
	}
	printf("(tail)\n");
}

int check_palindrome(struct node *head)
{
	struct node *fast, *slow, *cur;
	int len;
	struct stack *s;

	if (!head)
		return 0;

	len = 0;
	cur = head;
	while (cur) {
		cur = cur->next;
		len++;
	}

	s = init_stack(len);

	fast = head;
	slow = head;

	while (fast && fast->next) {
		push(s, slow->data);
		slow = slow->next;
		fast = fast->next->next;
	}

	/* Skip middle element if list has odd number of elements */
	if (fast)
		slow = slow->next;

	while (slow) {
		int data = pop(s);
		if (data != slow->data) {
			destroy_stack(&s);
			return 0;
		}
		slow = slow->next;
	}

	destroy_stack(&s);
	return 1;
}

int main()
{
	struct node* head = NULL;
	int ans;

	insert_at_head(&head, 20);
	insert_at_head(&head, 4);
	insert_at_head(&head, 15);
	insert_at_head(&head, 15);
	insert_at_head(&head, 4);
	insert_at_head(&head, 20);

	printf("List 1: \n");
	print_linked_list(head);

	ans = check_palindrome(head);
	if (ans)
		printf("List is palindrome\n");
	else
		printf("List is not palindrome\n");

	return 0;
}

