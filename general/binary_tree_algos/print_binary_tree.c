/* 
* Program to print a binary tree
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

void print_inorder(struct node *root)
{
	if (!root)
		return;

	print_inorder(root->left);
	printf(" %d ", root->data);
	print_inorder(root->right);
}

void print_preorder(struct node *root)
{
	if (!root)
		return;

	printf(" %d ", root->data);
	print_preorder(root->left);
	print_preorder(root->right);
}

void print_postorder(struct node *root)
{
	if (!root)
		return;

	print_postorder(root->left);
	print_postorder(root->right);
	printf(" %d ", root->data);
}

int main()
{
	struct node *root = NULL;

	/* Level 0 */
	root = create_node(12);
	
	/* Level 1 */
	root->left = create_node(24);
	root->right = create_node(19);

	/* Level 2 */
	root->left->left = create_node(32);
	root->left->right = create_node(6);
	root->right->left = create_node(23);
	root->right->right = create_node(27);

	/* Level 3 */
	root->left->left->left = create_node(18);
	root->left->left->right = create_node(11);
	root->left->right->left = create_node(1);
	root->left->right->right = create_node(5);
	root->right->left->left = create_node(96);
	root->right->left->right = create_node(102);

	/* Level 4 */
	root->left->right->left->left = create_node(8);

	print_inorder(root);
	printf("\n");
	print_preorder(root);
	printf("\n");
	print_postorder(root);
	printf("\n");

	return 0;
}

