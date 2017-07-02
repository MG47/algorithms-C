/* 
* Program that adds the two numbers represented by linked lists and returns the sum as a linked list
* Two numbers are represented by a linked list, where each node contains a single
* digit. The digits are stored in reverse order, such that the 1 's digit is at the head of the list.
* EXAMPLE
* Input: (7-) 1 -) 6) + (5 -) 9 -) 2) .That is, 617 + 295.
* Output: 2 -) 1 -) 9. That is, 912
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

	while (cur->next != NULL) {
		cur = cur->next;
	}

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

void pad_list(struct node *head, int data, int diff)
{
	struct node *new, *cur;
	cur = head;
	while (cur->next)
		cur = cur->next;
	while (diff--) {
		new = create_node(data);
		cur->next = new;
		cur = new;
	}

}

struct node *sum_list(struct node *head1, struct node *head2)
{
	struct node *head3 = NULL, *cur;
	int len1, len2;

	if (!head1 || !head2)
		return NULL;

	len1 = 0;
	cur = head1;
	while (cur) {
		cur = cur->next;
		len1++;
	}

	len2 = 0;
	cur = head2;
	while (cur) {
		cur = cur->next;
		len2++;
	}

	/* Pad the shorter list with zeros to make lengths of lists euqal */
	if (len1 > len2) 
		pad_list(head2, 0, len1 - len2);
	else if (len2 > len1)
		pad_list(head1, 0, len2 - len1);

	int value, carry;
	carry = 0;
	while (head1 && head2) {
		value = carry;
		if (head1)
			value += head1->data;
		if (head2)
			value += head2->data;

		carry = value / 10;
		value %= 10;

		insert_at_tail(&head3, value);
		
		head1 = head1->next;
		head2 = head2->next;
	}
	return head3;
}

int main()
{
	struct node *head1 = NULL, *head2 = NULL, *head3 = NULL;
	insert_at_head(&head1, 4);
	insert_at_head(&head1, 5);
	insert_at_head(&head1, 9);

	insert_at_head(&head2, 1);
	insert_at_head(&head2, 2);
	insert_at_head(&head2, 3);
	insert_at_head(&head2, 6);

	head3 = sum_list(head1, head2);

	print_linked_list(head1);
	print_linked_list(head2);
	printf("===========================\n");
	print_linked_list(head3);

	return 0;
}

