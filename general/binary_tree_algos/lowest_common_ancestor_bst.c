/* 
* Lowest common ancestor of two nodes of a binary tree
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

struct node *insert_node(struct node **root, int data)
{
	struct node *cur = *root;
	if (!cur) {
		*root = create_node(data);
		return *root;
	}

	if (data < cur->data)
		insert_node(&cur->left, data);
	else if (data > cur->data)
		insert_node(&cur->right, data);
	else
		return NULL;
}

void print_inorder(struct node *n)
{
	if (!n)
		return;

	print_inorder(n->left);
	printf(" %d", n->data);
	print_inorder(n->right);
}

struct node *lowest_common_ancestor(struct node *root, int key1, int key2)
{
	if (!root)
		return NULL;

	if (key1 < root->data && key2 < root->data)
		return lowest_common_ancestor(root->left, key1, key2);

	if (key1 > root->data && key2 > root->data)
		return lowest_common_ancestor(root->right, key1, key2);

	return root;
}

int main()
{
	struct node *ans;
	struct node *root = NULL;

	insert_node(&root, 4);
	insert_node(&root, 3);
	insert_node(&root, 16);
	insert_node(&root, 17);
	insert_node(&root, 15);
	insert_node(&root, 6);
	insert_node(&root, 2);
	insert_node(&root, 5);

	print_inorder(root);
	printf("\n\n");

	ans = lowest_common_ancestor(root, 2, 19);
	if (ans)
		printf("Lowest common ancestor %d\n", ans->data);
	return 0;
}


