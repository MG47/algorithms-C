/*
* Find intersecting node between two linked lists
* (Node in one linked list points to node in another linked list)
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

struct node *find_intersecting_node(struct node *head1, struct node *head2)
{
	int len1, len2, diff;
	struct node *cur, *shorter, *longer;
	if (!head1 || !head2)
		return NULL;
	
	cur = head1;
	len1 = 0;
	while (cur) {
		len1++;
		cur = cur->next;
	}

	cur = head2;
	len2 = 0;
	while (cur) {
		len2++;
		cur = cur->next;
	}

	diff = 0;
	shorter = head2;
	longer = head1;
	if (len1 > len2) {
		diff = len1 - len2;
	} else if (len2 > len1) {
		shorter = head1;
		longer = head2;
		diff = len2 - len1;
	}

	while (diff--)
		longer = longer->next;

	while (shorter != longer) {
		shorter = shorter->next;
		longer = longer->next;
	}
	return longer;
}

int main()
{
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	struct node* intersecting_node;

	insert_at_head(&head1, 20);
	insert_at_head(&head1, 4);
	insert_at_head(&head1, 15);
	insert_at_head(&head1, 10);

	insert_at_head(&head2, 12);
	insert_at_head(&head2, 2);
	insert_at_head(&head2, 14);
	insert_at_head(&head2, 8);
	insert_at_head(&head2, 19);

	printf("List 1: \n");
	print_linked_list(head1);

	printf("List 2: \n");
	print_linked_list(head2);

	/* Intersecting node */
	head1->next->next = head2->next->next->next;

	intersecting_node = find_intersecting_node(head1, head2);
	if (intersecting_node) {
		printf("Intersecting node: %d\n", intersecting_node->data);
	}

	return 0;
}

