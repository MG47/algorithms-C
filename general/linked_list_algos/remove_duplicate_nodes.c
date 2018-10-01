/* 
* Remove duplicates nodes of a singly linked list
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

/*
* O(N^2) time, in-place algorithm
*/
void remove_duplicate_nodes(struct node *head)
{
	struct node *cur, *runner, *temp;
	if (!head)
		return;

	cur = head;
	while (cur) {
		runner = cur;
		while (runner && runner->next) {
			if (runner->next->data == cur->data) {
				temp = runner->next;
				runner->next = temp->next;
				free(temp);
			}
			runner = runner->next;
		}
		cur = cur->next;
	}
}

int main()
{
	struct node* head = NULL;

	insert_at_head(&head, 20);
	insert_at_head(&head, 4);
	insert_at_head(&head, 15);
	insert_at_head(&head, 15);
	insert_at_head(&head, 4);
	insert_at_head(&head, 20);

	printf("List 1: \n");
	print_linked_list(head);

	remove_duplicate_nodes(head);

	print_linked_list(head);

	return 0;
}

