/* 
* Lowest common ancestor of two nodes of a binary tree
* Duplicates are not allowed
* Both nodes must be present
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

struct node *lowest_common_ancestor(struct node *root, int key1, int key2)
{
	struct node *left_check, *right_check;
	if (!root)
		return NULL;

	if (root->data == key1 || root->data == key2)
		return root;

	left_check = lowest_common_ancestor(root->left, key1, key2);
	right_check = lowest_common_ancestor(root->right, key1, key2);

	/* If both keys are present in current subtree, current node is the common ancestor */
	if (left_check && right_check)
		return root;

	if (left_check)
		return left_check;
	if (right_check)
		return right_check;
}

int main()
{
	struct node *ans;
	struct node *root;

	root = create_node(12);
	root->left = create_node(2);
	root->right = create_node(7);
	root->left->left = create_node(4);
	root->right->left = create_node(9);
	root->right->right = create_node(6);
	root->right->left->left = create_node(3);
	root->right->right->right = create_node(8);
	root->right->right->right->right = create_node(11);

	ans = lowest_common_ancestor(root, 2, 11);
	if (ans)
		printf("Lowest common ancestor %d\n", ans->data);
	return 0;
}

