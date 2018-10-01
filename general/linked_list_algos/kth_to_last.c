/*
* Find 'k' th from last element of a singly linked list 
* Iterative and recursive solutions
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

struct node *kth_to_last_element_recurse(struct node *head, int k, int *reverse_pos)
{
	struct node *cur;
	if (!head)
		return NULL;
	cur = kth_to_last_element_recurse(head->next, k, reverse_pos);

	(*reverse_pos)++;	
	if (*reverse_pos == k)
		return head;
	return cur;
}

/* Recursive solution */
struct node *kth_to_last_element_recursion(struct node *head, int k)
{
	int reverse_pos = 0;
	if (!head)
		return NULL;
	return kth_to_last_element_recurse(head, k, &reverse_pos);
}

/* Iterative solution */
struct node *kth_to_last_element_iteration(struct node *head, int k)
{
	struct node *cur;
	int len, num;
	if (!head)
		return NULL;

	len = 0;
	cur = head;
	while (cur) {
		cur = cur->next;
		len++;
	}

	cur = head;
	num = len - k;
	while (num--) {
		cur = cur->next;
	}
	return cur;
}

int main()
{
	struct node* head = NULL;
	struct node *ans;

	insert_at_head(&head, 20);
	insert_at_head(&head, 4);
	insert_at_head(&head, 15);
	insert_at_head(&head, 16);
	insert_at_head(&head, 14);
	insert_at_head(&head, 2);

	printf("List 1: \n");
	print_linked_list(head);

	int k;
	k = 5;

	/* Recursive approach */
//	ans = kth_to_last_element_recursion(head, k);

	/* Iterative approach */
	ans = kth_to_last_element_iteration(head, k);

	if (ans)
		printf("element no. %d from last node is %d\n", k, ans->data);
	else
		printf("element not found\n");
	return 0;
}

