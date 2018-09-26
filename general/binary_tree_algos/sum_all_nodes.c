/*
* Find sum of all nodes in a binary tree
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

int sum_of_nodes(struct node *root)
{
	if (!root)
		return 0;
	return (sum_of_nodes(root->left) + root->data + sum_of_nodes(root->right));
}

int main()
{
	int sum;
	struct node *root;

	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->right->left = create_node(5);
	root->right->right = create_node(6);

	sum = sum_of_nodes(root);
	printf("Sum of all nodes of the tree: %d\n", sum);
	return 0;
}

