/*
* Program to Check If a Binary Tree is Balanced
* Support Algorithms: Get height of a tree
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

int get_height(struct node *root)
{
	int l_height, r_height, max;
	if (!root)
		return 0;

	l_height = get_height(root->left);
	r_height = get_height(root->right);
	max = l_height >= r_height ? l_height : r_height;

	return 1 + max;
}

/* Tree is balanced if difference of height between left & right subtrees is 1 */
int is_tree_balanced(struct node *root)
{
	int l_height, r_height, diff;
	if (!root)
		return 1;

	l_height = get_height(root->left);
	r_height = get_height(root->right);
	diff = l_height - r_height;

	if (diff >= -1 && diff <= 1) {
		if (is_tree_balanced(root->left) && is_tree_balanced(root->right))
			return 1;
	}
	return 0;
}

int main()
{
	int is_balanced;
	struct node *root;
	
	root = create_node(4);
	root->left = create_node(2);
	root->left->right = create_node(3);
	root->left->left = create_node(1);
	root->right = create_node(5);
	root->right->right = create_node(12);
	root->right->right->left = create_node(11);
	root->right->right->right = create_node(19);

	is_balanced = is_tree_balanced(root);
	if (is_balanced)
		printf("tree is balanced\n");
	else
		printf("tree is not balanced\n");

	return 0;
}

