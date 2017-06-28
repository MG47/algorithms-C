/* 
* Find count of subtrees with same values 
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

int find_subtrees(struct node *root, int *count)
{
	if (!root)
		return 1;

	int left, right;

	left = find_subtrees(root->left, count);
	right = find_subtrees(root->right, count);

	if (!left || !right)
		return 0;

	if (root->left && root->data != root->left->data)
		return 0;

	if (root->right && root->data != root->right->data)
		return 0;

	(*count)++;
}

int find_same_value_subtrees(struct node *root)
{
	int count;
	find_subtrees(root, &count);
	return count;
}

int main()
{
	struct node *root;
	int count;

	root = create_node(2);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(2);
	root->right->left = create_node(5);
	root->right->right = create_node(6);
	root->right->right->left = create_node(6);
	root->right->right->right = create_node(6);	
	root->left->right = create_node(2);  

	count = find_same_value_subtrees(root);
	printf("Found %d same-valued subtrees\n", count);

	return 0;
}

