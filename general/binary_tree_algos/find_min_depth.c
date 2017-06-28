/* Find minimum depth in a tree */

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

int find_min_depth(struct node *root)
{
	if (!root)
		return 0;

	/* Check these conditions for the case where height = 1*/
	if (!root->left && !root->right)
		return 1;

	if (!root->left)
		return find_min_depth(root->right) + 1;

	if (!root->right)
		return find_min_depth(root->left) + 1;

	int left_dep, right_dep;
	left_dep = find_min_depth(root->left);
	right_dep = find_min_depth(root->right);

	return (left_dep < right_dep ? left_dep + 1 : right_dep + 1);
}

int main()
{
	int min_depth;
	struct node *root;

	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->right->left = create_node(5);
	root->right->right = create_node(6);
	root->right->left->left = create_node(7);
	root->right->right->right = create_node(8);

	min_depth = find_min_depth(root);
	printf("Minimum depth in the tree %d\n", min_depth);
	return 0;
}

