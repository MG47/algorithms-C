/*
* Doubly Linked List - Circular 
* // INCOMPLETE
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

static struct node *create_node(int data)
{
	struct node *n;
	n = malloc(sizeof(struct node));
	if (!n)
		exit(EXIT_FAILURE);

	n->next = NULL;
	n->prev = NULL;
	n->data = data;
	return n;
}

static struct node *insert_at_head(struct node **head_ptr, int data)
{
	struct node *n;
	struct node *cur = *head_ptr;
	if (!cur) {
		*head_ptr = create_node(data);
		(*head_ptr)->next = *head_ptr;
		(*head_ptr)->prev = *head_ptr;
		n = *head_ptr;
	} else {
		n = create_node(data);
		n->next = cur;
		n->prev = cur->prev;
		cur->prev->next = n;
		cur->prev = n;
		*head_ptr = n;
	}
	return n;
}

static struct node *insert_at_tail(struct node **head_ptr, int data)
{
	struct node *n;
	struct node *cur = *head_ptr;

	if (!cur) {
		*head_ptr = create_node(data);
		(*head_ptr)->next = *head_ptr;
		(*head_ptr)->prev = *head_ptr;
		n = *head_ptr;
		return n;
	}

	while (cur->next != (*head_ptr)) {
		cur = cur->next;
	}

	n = create_node(data);
	n->next = cur->next;
	n->prev = cur;
	cur->next = n;
	cur->next->prev = n;
	return n;
}

static struct node *insert_at_position(struct node **head_ptr, int data, int position)
{
	int count = 1;
	struct node *cur = *head_ptr;
	struct node *n;

	if (position == 1) {
		if (!cur) {
			*head_ptr = create_node(data);
			(*head_ptr)->next = *head_ptr;
			(*head_ptr)->prev = *head_ptr;
			n = *head_ptr;
		} else {
			n = create_node(data);
			n->next = cur;
			n->prev = cur->prev;
			cur->prev->next = n;
			cur->prev = n;
			*head_ptr = n;
		}
		return n;
	}

	while (cur->next != (*head_ptr)) {
		if (count == position)	{
			n = create_node(data);
			n->next = cur;
			n->prev = cur->prev;
			cur->prev->next = n;
			cur->prev = n;
			return n;
		}
		cur = cur->next;
		count++;
	}

	if (count != position)
		return NULL;

	n = create_node(data);
	n->next = cur;
	n->prev = cur->prev;
	cur->prev->next = n;
	cur->prev = n;
	return n;
}

static int remove_data(struct node **head_ptr, int data) 
{
	struct node *cur = *head_ptr;
	struct node *prev;
	if (!cur)
		return -1;

	if (cur->data == data) {
		if (cur->next == (*head_ptr)) {
			free(*head_ptr);
			*head_ptr = NULL;
			return 0;
		}
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		*head_ptr = cur->next;
		free(cur);
		return 0;
	}

	while (cur->next != *head_ptr) {
		if (cur->data == data) {
			prev = cur->prev;
			prev->next = cur->next;
			cur->next->prev = prev;
			free(cur);
			return 0;
		}
		cur = cur->next;
	}

	if (cur->data == data) {
		prev = cur->prev;
		prev->next = cur->next;
		cur->next->prev = prev;
		free(cur);
		return 0;
	}
	return -1;
}

static int search(struct node *head, int data)
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

static int remove_node(struct node **head_ptr, int position) 
{
	struct node *cur = *head_ptr;
	struct node *prev;
	int count = 1;

	if (!(*head_ptr))
		return -1;

	if (count == position) {
		if (cur->next == (*head_ptr)) {
			free(*head_ptr);
			*head_ptr = NULL;
			return 0;
		}
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		*head_ptr = cur->next;
		free(cur);
		return 0;
	}

	while (cur->next != (*head_ptr)) {
		if (count == position ) {
			prev = cur->prev;
			prev->next = cur->next;
			cur->next->prev = prev;
			free(cur);
			return 0;
		}
		count++;
		cur = cur->next;
	}

	if (count == position) {
		prev = cur->prev;
		prev->next = cur->next;
		cur->next->prev = prev;
		free(cur);
		return 0;
	}
	return -1;
}

static void print_linked_list(struct node *head)
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
	printf("\nCircular doubly Linked List\n\n");

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

