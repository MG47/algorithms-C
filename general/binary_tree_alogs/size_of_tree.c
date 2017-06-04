/* Find size of binary tree */

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

int sizeof_tree(struct node *root)
{
	if (!root)
		return 0;

	int sizeof_left = 0, sizeof_right = 0;
	sizeof_left = sizeof_tree(root->left);
	sizeof_right = sizeof_tree(root->right);
	return (sizeof_left + 1 + sizeof_right);
}

int main()
{
	int size;
	struct node *root;
	
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->right->left = create_node(5);
	root->right->right = create_node(6);
	
	size = sizeof_tree(root);
	printf("Size of the tree: %d\n", size);
	return 0;
}

