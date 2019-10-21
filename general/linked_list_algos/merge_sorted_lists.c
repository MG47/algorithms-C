/*
* Merge two sorted linked lists such that resulting list is sorted too
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

struct node *merge_list(struct node *head1, struct node *head2)
{
	struct node *merged_list = NULL, *cur = NULL;

	if (head1 && !head2)
		return head1;
	if (head2 && !head1)
		return head2;
	if (!head1 && !head2)
		return NULL;

	while (head1 && head2) {
		if (head1->data <= head2->data) {
			insert_at_tail(&merged_list, head1->data);
			head1 = head1->next;
		} else {
			insert_at_tail(&merged_list, head2->data);
			head2 = head2->next;
		}
	}

	if (!head1 && head2)
		cur = head2;
	if (!head2 && head1)
		cur = head1;

	while (cur) {
		insert_at_tail(&merged_list, cur->data);
		cur = cur->next;
	}

	return merged_list;
}

int main()
{
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	struct node* merged_list = NULL;

	insert_at_tail(&head1, 2);
	insert_at_tail(&head1, 5);
	insert_at_tail(&head1, 7);
	insert_at_tail(&head1, 10);

	insert_at_tail(&head2, 1);
	insert_at_tail(&head2, 2);
	insert_at_tail(&head2, 4);
	insert_at_tail(&head2, 9);

	merged_list = merge_list(head1, head2);

	printf("List 1: \n");
	print_linked_list(head1);

	printf("List 2: \n");
	print_linked_list(head2);

	printf("Merged list: \n");
	print_linked_list(merged_list);


	return 0;
}

