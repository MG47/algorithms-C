/*
Given a binary tree and a number, find if the tree has a root-to-leaf path such that adding 
up all the values along the path equals the given number.
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

int traverse(struct node *n, int current_sum, int sum)
{
	int ans = 0;
	if (!n) {
		if (current_sum == sum)
			return 1;
		else
			return 0;    
	}

	current_sum += n->data;

	if (current_sum == sum && n->left == NULL && n->right == NULL)
		return 1;

	ans |= traverse(n->left, current_sum, sum);
	ans |= traverse(n->right, current_sum, sum);

	return ans;
}

int check_path_sum(struct node *root, int sum)
{
	int result = 0;
	int current_sum = 0;
	result = traverse(root, current_sum, sum); 
	return result;
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

	ans = check_path_sum(root, 31);
	if (ans)
		printf("The tree has the given root-to-leaf path sum\n");
	else
		printf("The tree does not have the given root-to-leaf path sum\n");
	return 0;
}

