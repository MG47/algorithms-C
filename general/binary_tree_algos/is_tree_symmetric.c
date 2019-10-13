/*
* Program to check if a tree is symmetric (Mirror image)
*/

#include <stdio.h>
#include <stdlib.h>

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

int check_symmetry(struct node *root1, struct node* root2)
{
	int left_check, right_check;
	if (!root1 && !root2)
		return 1;

	if (!root1 || !root2)
		return 0;

	if (root1->data != root2->data)
		return 0;

	left_check = check_symmetry(root1->left, root2->right);
	right_check = check_symmetry(root1->right, root2->left);

	return left_check && right_check;
}

int is_tree_symmetrical(struct node *root)
{
	int ret;
	if (!root)
		return 0;

	ret = check_symmetry(root, root);
	return ret;
}

int main()
{
	int is_symmetrical;
	struct node *root;

	root = create_node(4);
	root->left = create_node(2);
	root->left->right = create_node(3);
	root->left->left = create_node(1);
	root->right = create_node(2);
	root->right->right = create_node(1);
	root->right->left = create_node(3);
//	root->right->right->right = create_node(12);

	is_symmetrical = is_tree_symmetrical(root);
	if (is_symmetrical)
		printf("tree is symmetrical\n");
	else
		printf("tree is not symmetrical\n");

	return 0;
}

