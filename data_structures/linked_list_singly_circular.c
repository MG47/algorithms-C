/*
* Singly Linked List - Circular 
* // INCOMPLETE  - not tested
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
	
	if (cur) {
		new->next = cur;
		while (cur->next != *head)
			cur = cur->next;
		cur->next = new;
		*head = new;
	} else {
		new->next = new;
		*head = new;
	}
}

void insert_at_tail(struct node **head, int data)
{
	struct node *cur, *new;
	cur = *head;
	new = create_node(data);

	if (cur) {
		while (cur->next != *head)
			cur = cur->next;
		cur->next = new;
		new->next = *head;
	} else {
		new->next = new;
		*head = new;
	}
}

void insert_at_position(struct node **head, int data, int position)
{
	//INCOMPLETE
	int count;
	struct node *cur, *new, *prev;

	if (position < 1)
		return;

	count = 1;
	new = create_node(data);
	cur = *head;
	prev = cur;

	if (!cur) {
		if (position == 1) {
			new->next = new;
			*head = new;
		}
		return;
	}

	while (cur->next != *head) {
		if (count == position) {
			new->next = cur;
			prev->next = new;
			return;
		}
		prev = cur;
		cur = cur->next;
		count++;
	}

	if (count != position)
		return;
	cur->next = new;
	new->next = *head;
}

void remove_data(struct node **head, int data)
{
	//INCOMPLETE
	struct node *cur, *prev;

	cur = *head;
	prev = NULL;

	if (cur->next == cur) {
		free(*head);
		*head = NULL;
	}

	while (cur && cur->next != *head) {
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
	// INCOMPLETE
	int count;
	struct node *cur, *prev;
	
	cur = *head;
	prev = NULL;
	count = 1;

	if (cur->next == cur) {
		free(*head);
		*head = NULL;
	}

	while (cur && cur->next != *head) {
		if (count++ == position) {
			if (prev)
				prev->next = cur->next;
			else
				*head = cur->next;
		}
		prev = cur;
		cur = cur->next;
	}
}

int search(struct node *head, int data)
{
	struct node *cur = head;
	int count = 1;

	if (!cur)
		return 0;

	if (cur->next == head) {
		if (cur->data == data)
			return count;
		else
			return 0;
	}

	while (cur->next != head) {
		if (cur->data == data)
			return count;
		cur = cur->next;
		count++;
	}

	if (cur->data == data)
		return count;
	
	return 0;
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

	if (cur->next == head) {
		printf("(%d): %d \n", count, cur->data);
		printf("|\n");
		printf("\nLast Node - Circles back to head\n");
		return;
	}

	while (cur->next != head) {
		printf("(%d): %d \n", count, cur->data);
		printf("|\n");
		cur = cur->next;
		count++;
	}

	printf("(%d): %d \n", count, cur->data);
	printf("\nLast Node - Circles back to head\n");
}

int main()
{
	printf("\nCircular Singly Linked List\n\n");

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
			int position;
			position = search(head, data);
			printf("position in list : %d", position);
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

