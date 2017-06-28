/* Find height of a tree (Maximum Depth) */

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

int find_height(struct node *root)
{
	int left_ht, right_ht;
	if (!root)
		return 0;

	left_ht = find_height(root->left);
	right_ht = find_height(root->right);

	return (left_ht > right_ht ? (left_ht + 1) : (right_ht + 1));
}

int main()
{
	int height;
	struct node *root;

	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->right->left = create_node(5);
	root->right->right = create_node(6);
	root->right->left->left = create_node(7);
	root->right->right->right = create_node(8);
	root->right->right->right->right = create_node(9);


	height = find_height(root);
	printf("Height of the tree %d\n", height);
	return 0;
}

