/*
* Given a Binary Tree with children Nodes, 
* return a random node with equal probability of selecting any Node in tree
* TODO optimize
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int data;
	struct node *left; 
	struct node *right;
};

struct node *create_node(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void print_inorder(struct node *n)
{
	if (!n)
		return;

	print_inorder(n->left);
	printf("%d ", n->data);
	print_inorder(n->right);
}

void get_node_from_data(struct node *root, int data, struct node **current)
{
	if (!root)
		return;
	get_node_from_data(root->left, data, current);
	if (root->data == data)
		*current = root;

	get_node_from_data(root->right, data, current);
}

int sizeof_tree(struct node *root)
{
	int size_left, size_right;
	if (!root)
		return 0;
	
	size_left = sizeof_tree(root->left);
	size_right = sizeof_tree(root->right);

	return (size_left + 1 + size_right);	
}

void store_inorder(struct node *root, int *inorder_arr, int size, int *index)
{
	if (!root || !inorder_arr || !index || (*index >= size) )
		return;

	store_inorder(root->left, inorder_arr, size, index);
	inorder_arr[*index] = root->data;
	(*index)++;
	store_inorder(root->right, inorder_arr, size, index);
}

/* 
* Walk tree in-order and store elements in an array
* Choose a random array element
*/
struct node *get_random_node(struct node *root)
{
	int *inorder_array, size, index;
	struct node *random_node;
	if (!root)
		return NULL;

	size = sizeof_tree(root);
	if (size <= 0)
		return NULL;

	inorder_array = malloc(sizeof(int) * size);
	if (!inorder_array)
		exit(EXIT_FAILURE);

	index = 0;
	store_inorder(root, inorder_array, size, &index);

	srand(time(NULL));
	index = rand() % size;

	random_node = NULL;
	get_node_from_data(root, inorder_array[index], &random_node);
	free(inorder_array);
	return random_node;
}

int main()
{
	struct node *root;

	root = create_node(12);
	root->left = create_node(2);
	root->right = create_node(7);
	root->left->left = create_node(4);
	root->left->right = create_node(1);

	print_inorder(root);
	printf("\n\n");

	root = get_random_node(root);
	if (root) {
		printf("Got node %d \n", root->data);
	}

	return 0;
}

