/* 
* Program to create a linked list of all the nodes at each depth 
* (i.e., if you have a tree with height H, you will have H linked lists).
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left; 
	struct node *right;
};

struct node *create_node(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	if (!temp)
		exit(EXIT_FAILURE);
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

struct queue {
	int size;
	int maxsize;
	int front;
	int rear;
	struct node *data[];
};

struct queue *init_queue(int maxsize)
{
	struct queue *q;
	q = calloc(1, sizeof(struct queue) + (sizeof(struct node *) * maxsize));
	if (!q)
		return NULL;

	q->maxsize = maxsize;
	return q;
}

struct queue *destroy_queue(struct queue *q)
{
	if (!q)
		return NULL;
	free(q);
	return NULL;
}

int is_full(struct queue *q)
{
	return (q->size == q->maxsize);
}

int is_empty(struct queue *q)
{
	return (q->size == 0);
}

int insert_at_rear(struct queue *q, struct node *data)
{
	if (!q || (is_full(q)))
		return -1;

	q->data[q->rear++] = data;
	q->rear %= q->maxsize;
	q->size++; 
	return 0;
}

struct node *remove_from_front(struct queue *q)
{
	struct node *ret;
	if ((!q) || (is_empty(q)))
		return 0;

	ret = q->data[q->front];
	q->data[q->front++] = 0;
	q->front %= q->maxsize;
	q->size--;
	return ret;
}

struct list_node {
	struct node *data;
	struct list_node *next;
};

struct list_node *create_list_node(struct node *data)
{
	struct list_node *temp = malloc(sizeof(struct list_node));
	if (!temp)
		exit(EXIT_FAILURE);
	temp->data = data;
	temp->next = NULL;
	return temp;
}

/* Insert at tail of linked list */
void insert_list_node(struct list_node **head, struct node *data)
{
	struct list_node *new;
	struct list_node *cur;
	cur = *head;
	new = create_list_node(data);

	if (cur) {
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	} else {
		*head = new;
	}
}

void print_linked_list(struct list_node *head)
{
	int count = 1;
	struct list_node *cur = head;

	printf("\nLinked List: \n");

	if (!cur) {
		printf("Linked list is empty!\n");
		return;
	}

	if (cur->next == NULL) {
		printf("(%d): %d ", count, cur->data->data);
		printf("(Last Node)\n");
		return;
	}
	while (cur->next != NULL) {
		printf("(%d): %d \n", count, cur->data->data);
		printf("|\n");
		cur = cur->next;
		count++;
	}

	printf("(%d): %d ", count, cur->data->data);
	printf("(Last Node)\n");
}

int power(int number, int pow)
{
	unsigned int i = 0, res = 1;	
	while (i++ < pow)
		res *= number;
	return res;
}

int find_height(struct node *root)
{
	int left_ht, right_ht;
	if (!root)
		return 0;

	left_ht = find_height(root->left);
	right_ht = find_height(root->right);

	return (left_ht > right_ht ? (left_ht + 1) : (right_ht + 1));
}

/* Array of linked lists */
struct list_node **list;

/* 
* Use a queue to traverse in BFS fashion 
* Allocate a linked list at each level
* Return length of array of linked lists
*/

int get_level_order_linked_list(struct node *root)
{
	int height, queue_size;
	struct queue *q;
	struct node *cur;
	int i;
	int level_nodes;

	/* Get height to calculate max queue size */
	height = find_height(root);
	queue_size = power(2, height);

	q = init_queue(queue_size);
	list = malloc(sizeof(struct list_node) * height);

	i = 0;
	insert_at_rear(q, root);

	while (!is_empty(q)) {
		level_nodes = q->size;
		while (level_nodes > 0) {
			cur = remove_from_front(q);
			insert_list_node(&list[i], cur);
			if (cur->left)
				insert_at_rear(q, cur->left);
			if (cur->right)
				insert_at_rear(q, cur->right);
			level_nodes--;
		}
		i++;
	}		

	destroy_queue(q);
	return height;
}

int main()
{
	int len, i;
	struct node *root;

	root = create_node(12);
	root->left = create_node(2);
	root->right = create_node(7);
	root->left->left = create_node(4);
	root->right->left = create_node(9);
	root->right->right = create_node(6);
	root->right->left->left = create_node(3);
	root->right->right->right = create_node(8);
	root->right->right->right->right = create_node(11);

	len = get_level_order_linked_list(root);

	for (i = 0; i < len; i++) {
		printf("\n\nList %d: ", i);
		print_linked_list(list[i]);
	}
	return 0;
}

