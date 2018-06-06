/* 
* Partition a linked list based on value x
* (all nodes less than value x are on one side and the rest on the other)
* Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 (PARTITION 5)
* Output: 3 -> 1 -> 2 -> -> 5 -> 5 -> 8 -> 10
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

struct node *insert_at_tail(struct node **head_ptr, int data)
{
	struct node *n;
	struct node *cur = *head_ptr;

	if (!cur) {
		*head_ptr = create_node(data);
		(*head_ptr)->next = NULL;
		n = *head_ptr;
		return n;
	}

	while (cur->next != NULL)
		cur = cur->next;

	n = create_node(data);
	n->next = cur->next;
	cur->next = n;
	return n;
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

void partition_list(struct node *head, int partition_point)
{
	struct node *less_than_list = NULL, *greater_than_list = NULL;
	struct node *cur, *next;
	if (!head)
		return;

	cur = head;
	while (cur) {
		if (cur->data < partition_point)
			insert_at_tail(&less_than_list, cur->data);
		else
			insert_at_tail(&greater_than_list, cur->data);
		cur = cur->next;

	}

	cur = less_than_list;
	while (cur) {
		head->data = cur->data;
		cur = cur->next;
		head = head->next;
	}

	cur = greater_than_list;

	while (cur) {
		head->data = cur->data;
		cur = cur->next;
		head = head->next;
	}

	/* Free temporary lists */
	cur = less_than_list;
	while (cur) {
		next = cur->next;
		free(cur);
		cur = next;
	}

	cur = greater_than_list;
	while (cur) {
		next = cur->next;
		free(cur);
		cur = next;
	}
}

int main()
{
	struct node* head1 = NULL;

	insert_at_head(&head1, 20);
	insert_at_head(&head1, 4);
	insert_at_head(&head1, 15);
	insert_at_head(&head1, 9);
	insert_at_head(&head1, 2);
	insert_at_head(&head1, 16);
	insert_at_head(&head1, 10);

	printf("List 1: \n");
	print_linked_list(head1);

	partition_list(head1, 10);

	print_linked_list(head1);

	return 0;
}

