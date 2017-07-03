/* 
* Program to find min & max in a binary tree(separate functions)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int find_min(struct node *root)
{
	int left_min, right_min, min;
	if (!root)
		return INT_MAX;

	min = root->data;
	left_min = find_min(root->left);
	right_min = find_min(root->right);

	if (left_min < min)
		min = left_min;
	if (right_min < min)
		min = right_min;
	return min;
}

int find_max(struct node *root)
{
	int right_max, left_max, max;
	if (!root)
		return INT_MIN;

	max = root->data;
	left_max = find_max(root->left);
	right_max = find_max(root->right);

	if (left_max > max)
		max = left_max;
	if (right_max > max)
		max = right_max;
	return max;
}

int main()
{
	int min, max;
	struct node *root = NULL;

	root = create_node(22);
	root->left = create_node(1);
	root->right = create_node(7);
	root->left->left = create_node(4);
	root->right->left = create_node(9);
	root->right->right = create_node(6);
	root->right->left->left = create_node(3);
	root->right->right->right = create_node(8);
	root->right->right->right->right = create_node(11);

	min = find_min(root);
	max = find_max(root);

	printf("Min value: %d\n", min);
	printf("Max value: %d\n", max);

	return 0;
}

