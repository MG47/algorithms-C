/* 
* Program to check if a binary tree is BST or not 
* Assumption: Duplicate values are not inserted
*/

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

int is_bst(struct node *root, int min, int max)
{
	int left_check, right_check;
	if  (!root)
		return 1;

	if (root->data < min || root->data > max)
		return 0; 

	left_check = is_bst(root->left, min, root->data - 1);
	right_check = is_bst(root->right, root->data + 1, max);

	if (!left_check || !right_check)
		return 0;
	return 1;
}

int is_tree_bst(struct node *root)
{
	return is_bst(root, INT_MIN, INT_MAX);
}

int main()
{
	struct node *root;
	int is_bst;
	
	root = create_node(4);
	root->left = create_node(2);
	root->left->right = create_node(3);
	root->left->left = create_node(1);
	root->right = create_node(6);
	root->right->right = create_node(5);

	is_bst = is_tree_bst(root);
	if (is_bst)
		printf("tree is a binary search tree\n");
	else
		printf("tree is NOT a binary search tree\n");

	return 0;
}


