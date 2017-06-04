/*
* Program to detect and remove loop in linked list
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
 
int remove_loop(struct node *head, struct node *loop_node)
{
	struct node *ptr1, *ptr2;
 
	ptr1 = head;
	while (1) {
		ptr2 = loop_node;
		while (ptr2->next != loop_node && ptr2->next != ptr1)
			ptr2 = ptr2->next;
 
 		/* Loop point found, break the loop */
		if (ptr2->next == ptr1)
			break;

		ptr1 = ptr1->next;
	}
	ptr2->next = NULL;
	return 0;
}

int detect_and_remove_loop(struct node *head)
{
	int ret;
	struct node *slow_ptr = head, *fast_ptr = head;

	while (slow_ptr && fast_ptr && fast_ptr->next) {
		slow_ptr = slow_ptr->next;
		fast_ptr  = fast_ptr->next->next;

		/* Floyd Cycle Detection Algorithm*/
		if (slow_ptr == fast_ptr) {
			ret = remove_loop(head, slow_ptr);
			return ret;
		}
	}
	return 0;
}

int create_loop(struct node *head, int position)
{
	struct node *cur, *loop_node;
	int counter;

	if (!head)
		return 0;

	counter = 0;
	cur = head;

	while (counter != position) {
		if (!cur)
			return 0;
		cur = cur->next;
		counter++;
	}
	loop_node = cur;

	while (cur->next)
		cur = cur->next;
	cur->next = loop_node;
	return 0;
}

int main()
{
	struct node* head = NULL;
	int ret;
 
	insert_at_head(&head, 20);
	insert_at_head(&head, 4);
	insert_at_head(&head, 15);
	insert_at_head(&head, 10);
	insert_at_head(&head, 9);
	print_linked_list(head);

	create_loop(head, 2);
	ret = detect_and_remove_loop(head);
	if (ret)
		printf("Detected and removed loop\n");

	print_linked_list(head);

	return 0;
}

