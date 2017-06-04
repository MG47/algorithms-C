/* Find the deepest node */

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

void find_node(struct node *root, int level, int *deep_value, int *max_depth)
{
	if (!root)
		return;

	level++;

	if (level > (*max_depth)) {
		*max_depth = level;
		*deep_value = root->data;
	}
	find_node(root->left, level, deep_value, max_depth);
	find_node(root->right, level, deep_value, max_depth);
}

int deepest_node(struct node *root)
{
	int deep_value = -1;
	int max_depth = -1;
	if (!root)
		return -1;

	find_node(root, 0, &deep_value, &max_depth);
	return deep_value;
}

int main()
{
	int deep;
	struct node *root;
	
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->right->left = create_node(5);
	root->right->right = create_node(6);
	root->right->right = create_node(33);   
	root->right->right->right = create_node(34);
	root->right->right->right->right = create_node(35);
	root->right->right->right->right->right = create_node(36);
	root->right->left->right = create_node(8);
	root->right->left->right->left = create_node(13);
	
	deep = deepest_node(root);
	printf("deepest node value: %d\n", deep);
	return 0;
}

