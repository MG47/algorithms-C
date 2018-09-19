/*
* Program to perform level-order traversal
* Uses queue to store node values
*/ 

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left; 
	struct node *right;
};

struct queue {
	int size;
	int maxsize;
	int front;
	int rear;
	struct node *data[];
};

struct node *create_node(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

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
	struct node * ret;

	if ((!q) || (is_empty(q)))
		return 0;

	ret = q->data[q->front];
	q->data[q->front++] = 0;
	q->front %= q->maxsize;
	q->size--;
	return ret;
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

void traverse_level_order(struct node *root)
{
	int height, queue_size;
	struct queue *q;
	struct node *cur;

	/* Get height to calculate max queue size */
	height = find_height(root);
	queue_size = power(2, height);

	q = init_queue(queue_size);

	cur = root;
	while (cur) {
		printf("%d\n", cur->data);
		if (cur->left)
			insert_at_rear(q, cur->left);
		if (cur->right)
			insert_at_rear(q, cur->right);
		cur = remove_from_front(q);
	}
	destroy_queue(q);
}

int main()
{
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

	traverse_level_order(root);

	return 0;
}

