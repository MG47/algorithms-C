/* 
* Program to delete any middle node (any node except first and last) in a singly linked list,
* given only access to that node (HEAD pointer is not given)
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

void delete_node(struct node *del_node)
{
	struct node *next_node;
	if (!del_node || !del_node->next)
		return;

	/* Copy next node to current node and free next node */
	next_node = del_node->next;
	del_node->data = next_node->data;
	del_node->next = next_node->next;
	free(next_node);
}

int main()
{
	struct node* head = NULL;

	insert_at_head(&head, 20);
	insert_at_head(&head, 4);
	insert_at_head(&head, 12);
	insert_at_head(&head, 15);
	insert_at_head(&head, 7);
	insert_at_head(&head, 10);

	printf("List 1: \n");
	print_linked_list(head);

	struct node *del_node = head->next->next;
	delete_node(del_node);

	print_linked_list(head);

	return 0;
}

