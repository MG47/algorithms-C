/* Check if a binary tree is BST or not */
/* Support algorithms: find min and max in binary tree */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
	struct node *left;
	struct node *right;
	int data;
};

struct node *create_node(int data)
{
	struct node *new;
	new = malloc(sizeof(struct node));
	if (!new)
		exit(EXIT_FAILURE);
	new->left = NULL;
	new->right = NULL;
	new->data = data;
	return new;
}

int min_value(struct node *root)
{
	int left_min;
	int right_min;
	int min;

	if (!root)
		return INT_MAX;

	min = root->data;
	left_min = min_value(root->left);
	right_min = min_value(root->right);

	if (left_min < min)
		min = left_min;
	if (right_min < min)
		min = right_min;

	return min;
}

int max_value(struct node *root)
{
	int left_max;
	int right_max;
	int max;

	if (!root)
		return INT_MIN;

	max = root->data;
	left_max = max_value(root->left);
	right_max = max_value(root->right);

	if (left_max > max)
		max = left_max;
	if (right_max > max)
		max = right_max;

	return max;
}

/* Check if max value in left subtree is not greater than current node's value
AND check if min value in right subtree is not less than current node's value */
int is_tree_bst(struct node *root)
{
	if (!root)
		return 1;

	if (root->left && max_value(root->left) > root->data)
		return 0;

	if (root->right && min_value(root->right) < root->data)
		return 0;

	if (!is_tree_bst(root->left) || !is_tree_bst(root->right))
		return 0;
}

int main()
{
	struct node *root;
	int is_bst;
	
	root = create_node(4);
	root->left = create_node(2);
	root->left->right = create_node(3);
	root->left->left = create_node(1);
	root->right = create_node(5);

	is_bst = is_tree_bst(root);
	if (is_bst)
		printf("tree is a binary search tree\n");
	else
		printf("tree is NOT a binary search tree\n");

	return 0;
}


