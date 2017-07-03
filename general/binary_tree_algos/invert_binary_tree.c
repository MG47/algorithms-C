/* 
* Program to invert(mirror) a binary tree
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

void print_preorder(struct node *n)
{
	if (!n)
		return;
	printf(" %d", n->data);
	print_preorder(n->left);
	print_preorder(n->right);
}

void invert_tree(struct node *root)
{
	struct node *temp;
	if (!root)
		return;
	invert_tree(root->left);
	invert_tree(root->right);

	temp = root->left;
	root->left = root->right;
	root->right = temp;
}

int main()
{
	int height;
	struct node *root;

	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->right->right = create_node(6);
	root->right->right->left = create_node(7);
	root->right->right->right = create_node(8);
	root->right->right->right->right = create_node(9);

	print_preorder(root);
	printf("\n\n");

	invert_tree(root);

	print_preorder(root);
	printf("\n\n");
	return 0;
}

