/* Find and return maxium path sum in a binary tree */

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

int max_path_sum(struct node *root)
{
	int left_sum, right_sum;
	if (!root)
		return 0;

	left_sum = max_path_sum(root->left);
	right_sum = max_path_sum(root->right);

	return ((left_sum > right_sum) ? (left_sum  + root->data) : (right_sum  + root->data));
}

int main()
{
	int max_sum;
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

	max_sum = max_path_sum(root);
	printf("The Maximum path sum in the tree: %d\n", max_sum);
	return 0;
}

