/*
* Find Depth of a node
* Duplicates are not allowed
*/ 

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left; 
	struct node *right;
};

int find_depth(struct node *root, int data)
{
	if (!root)
		return -1;
	int left_check, right_check;
	left_check = find_depth(root->left, data);
	right_check = find_depth(root->right, data);

	if (left_check >= 0) 
		return (1 + left_check);

	if (right_check >= 0) 
		return (1 + right_check);

	if (data == root->data)
		return 1;
	return -1;
}

struct node *create_node(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

int main()
{
	int ans;
	struct node *root = NULL;

	root = create_node(12);
	root->left = create_node(2);
	root->right = create_node(7);
	root->left->left = create_node(4);
	root->right->left = create_node(9);
	root->right->right = create_node(6);
	root->right->left->left = create_node(3);
	root->right->right->right = create_node(8);
	root->right->right->right->right = create_node(11);

	ans = find_depth(root, 3);
	if (ans >= 0)
		printf("Depth of node: %d\n", ans);
	return 0;
}

