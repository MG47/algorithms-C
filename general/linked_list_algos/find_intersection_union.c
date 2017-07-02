/* 
* Find intersection and union lists of two singly linked lists 
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

int is_present(struct node *head, int data)
{
	struct node *cur = head;
	while (cur) {
		if (cur->data == data)
			return 1;
		cur = cur->next;
		}
	return 0;
}

struct node *get_intersection(struct node *head1, struct node *head2)
{
	struct node *intersection_list;
	int i = 0;
	intersection_list = NULL;

	while (head2) {
		if (is_present(head1, head2->data))
			insert_at_head(&intersection_list, head2->data);
		head2 = head2->next;
	}
	return intersection_list;
}

struct node *get_union(struct node *head1, struct node *head2)
{
	struct node *union_list;
	int i = 0;
	union_list = NULL;
 
	while (head1) {
		insert_at_head(&union_list, head1->data);
		head1 = head1->next;
	}
 
	while (head2) {
		if (!is_present(union_list, head2->data))
			insert_at_head(&union_list, head2->data);
		head2 = head2->next;
	}
	return union_list;
}

int main()
{
	struct node* head1 = NULL;
	struct node* head2 = NULL;
	struct node* intersection_list = NULL;
	struct node* union_list = NULL;
 
	insert_at_head(&head1, 20);
	insert_at_head(&head1, 4);
	insert_at_head(&head1, 15);
	insert_at_head(&head1, 10);

	insert_at_head(&head2, 10);
	insert_at_head(&head2, 2);
	insert_at_head(&head2, 4);
	insert_at_head(&head2, 8);

	intersection_list = get_intersection(head1, head2);
	union_list = get_union(head1, head2);

	printf("List 1: \n");
	print_linked_list(head1);

	printf("List 2: \n");
	print_linked_list(head2);

	printf("Intersection list is \n");
	print_linked_list(intersection_list);

	printf("Union list is \n");
	print_linked_list(union_list);

	return 0;
}

