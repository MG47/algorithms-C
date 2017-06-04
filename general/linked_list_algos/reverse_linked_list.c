/* 
* Reverse a singly linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *next;
	struct node *prev;
	int data;
};

struct node *create_node(int data)
{
	struct node *new;
	new = malloc(sizeof(struct node));
	if (!new)
		exit(EXIT_FAILURE);
	new->next = NULL;
	new->prev = NULL;
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

int reverse_list(struct node **head)
{
	struct node *cur, *prev, *next;
	cur = *head;
	prev = NULL;
	while (cur) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*head = prev;
}

int main()
{
	struct node *head = NULL;
	insert_at_head(&head, 4);
	insert_at_head(&head, 5);
	insert_at_head(&head, 2);
	insert_at_head(&head, 9);
	insert_at_head(&head, 1);
	print_linked_list(head);
	reverse_list(&head);
	print_linked_list(head);
	return 0;
}

