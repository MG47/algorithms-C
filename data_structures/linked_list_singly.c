/*
* Singly Linked List
* // INCOMPLETE
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *create_node(int data)
{
	struct node *n;
	n = malloc(sizeof(struct node));
	if (!n)
		exit(EXIT_FAILURE);

	n->next = NULL;
	n->data = data;
	return n;
}

void insert_at_head(struct node **head, int data)
{
	struct node *cur, *new;

	cur = *head;

	new = create_node(data);
	new->next = cur;
	*head = new;
}

void insert_at_tail(struct node **head, int data)
{
	struct node *cur, *new;
	new = create_node(data);

	cur = *head;

	if (cur) {
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	} else {
		*head = new;
	}
}

void insert_at_position(struct node **head, int data, int position)
{
	int count;
	struct node *cur, *prev, *new;
	cur = *head;
	prev = NULL;
	count = 0;

	new = create_node(data);
	while (cur) {
		if (count++ == position) {
			if (prev) {
				prev->next = new;
				new->next = cur;
			} else {
				*head = new;
				new->next = cur;
			}
		}
		prev = cur;
		cur = cur->next;
	}
}

void remove_data(struct node **head, int data) 
{
	struct node *cur, *prev;
	cur = *head;
	prev = NULL;

	while (cur) {
		if (cur->data == data) {
			if (prev)
				prev->next = cur->next;
			else 
				*head = cur->next;
		}
		prev = cur;
		cur = cur->next;
	}
}

void remove_node(struct node **head, int position) 
{
	struct node *prev, *tmp;
	int count;

	if (position < 0)
		return;

	count = 1;
	tmp = *head;
	prev = NULL;

	while (tmp) {
		if (count++ == position) {
			if (prev) 
				prev->next = tmp->next;
			else
				*head = tmp->next;
			return;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void search(struct node *head, int data)
{
	int pos;
	pos = 1;
	while (head) {
		if (head->data == data) {
			printf("Data found at position %d\n", pos);
			return;
		}
		head = head->next;
		pos++;
	}

	printf("Data not found");
	return;
}

void print_linked_list(struct node *head)
{
	int count = 1;
	struct node *cur = head;

	printf("\nLinked List: \n");

	if (!cur) {
		printf("Linked list is empty!\n");
		return;
	}

	if (cur->next == NULL) {
		printf("(%d): %d ", count, cur->data);
		printf("(Last Node)\n");
		return;
	}

	while (cur->next != NULL) {
		printf("(%d): %d \n", count, cur->data);
		printf("|\n");
		cur = cur->next;
		count++;
	}

	printf("(%d): %d ", count, cur->data);
	printf("(Last Node)\n");
}

	
int main()
{
	printf("\nSingly Linked List\n\n");

	int option;
	struct node *head = NULL;

	while (1) {
		printf("\nOptions:\n");
		printf("1. Insert at head \n");
		printf("2. Insert at tail \n");
		printf("3. Insert at position \n");
		printf("4. Search\n");
		printf("5. Remove data\n");
		printf("6. Remove node\n");
		printf("7. Print Linked List\n");
		printf("8. Exit\n");
		printf("\n\n");

		printf("Enter the option number: ");
		scanf("%d", &option);
		int data , position;

		switch (option) {
		case 1:
			printf("Enter data to be inserted: ");
			scanf("%d", &data);
			insert_at_head(&head, data);
			break;
		case 2:
			printf("Enter data to be inserted: ");
			scanf("%d", &data);
			insert_at_tail(&head, data);
			break;
		case 3:
			printf("Enter data to be inserted:");
			scanf(" %d", &data);
			printf("Enter position");
			scanf("%d", &position);
			insert_at_position(&head, data, position);
			break;
		case 4:
			printf("Enter data to be searched: ");
			scanf("%d", &data);
			search(head, data);
			break;
		case 5:
			printf("Enter data to be removed: ");
			scanf("%d", &data);
			remove_data(&head, data);
			break;
		case 6:
			printf("Enter node number to be removed:");
			scanf("%d", &position);
			remove_node(&head, position);
			break;
		case 7:
			print_linked_list(head);
			break;
		case 8:
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("Invalid Option\n");
		}
	}
	return 0;
}

