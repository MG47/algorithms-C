/* 
* Binary Tree to Binary Search Tree Conversion 
* Original Structure of the tree is preserved 
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
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void print_inorder(struct node *n)
{
	if (!n)
		return;

	print_inorder(n->left);
	printf(" %d", n->data);
	print_inorder(n->right);
}

int count_nodes(struct node *root)
{
	int left_count, right_count;
	if (!root)
		return 0;
	right_count = count_nodes(root->left);
	left_count = count_nodes(root->right);
	return (left_count + 1 + right_count);
}

void store_inorder(int *arr, int *index, struct node *root)
{	
	if (!root)
		return;

	store_inorder(arr, index, root->left);
	arr[*index] = root->data;
	(*index)++;
	store_inorder(arr, index, root->right);
}

int bubblesort(int *arr, int len)
{
	int i, j, temp;

	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return 0;
}

void array_to_bst(int *arr, int *index, struct node *root)
{
	if (!root)
		return;

	array_to_bst(arr, index, root->left);
	root->data = arr[*index];
	(*index)++;
	array_to_bst(arr, index, root->right);
}

struct node *binary_tree_to_bst(struct node *root)
{
	int len, *arr, index;
	if (!root)
		return NULL;

	len = count_nodes(root);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		exit(EXIT_FAILURE);

	index = 0;
	store_inorder(arr, &index, root);

	bubblesort(arr, len);

	index = 0;
	array_to_bst(arr, &index, root);
	return root;
}

int main()
{
	int ans;
	struct node *root = NULL;

	root = create_node(12);
	root->left = create_node(2);
	root->right = create_node(7);
	root->left->left = create_node(4);
	root->left->right = create_node(1);

		print_inorder(root);
		printf("\n\n");

	root = binary_tree_to_bst(root);
	if (root) {
		printf("Binary Search Tree inorder:\n");
		print_inorder(root);
		printf("\n\n");
	} 
	return 0;
}


