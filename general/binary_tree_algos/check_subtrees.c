/* 
* Program to check if tree 1 is subtree of tree 2
* INCOMPLETE
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

void print_inorder(struct node *n)
{
	if (!n)
		return;

	print_inorder(n->left);
	printf(" %d", n->data);
	print_inorder(n->right);
}

int match_nodes(struct node *root1, struct node *root2)
{
	int left_check, right_check;
	if (!root1 && !root2)
		return 1;

	if (!root1 || !root2)
		return 0;

	if (root1->data == root2->data) {
		left_check = match_nodes(root1->left, root2->left);
		right_check = match_nodes(root1->right, root2->right);
		return (left_check && right_check);
	} else {
		return 0;
	}
}

int check_subtrees(struct node *root1, struct node *root2)
{
	if (!root1 || !root2)
		return 0;

	if (match_nodes(root1, root2))
		return 1;

	return (check_subtrees(root1->left, root2) ||
		check_subtrees(root1->right, root2));
}

int main()
{
	int ans;
	struct node *root1 = NULL, *root2 = NULL;

	root1 = create_node(12);
	root1->left = create_node(2);
	root1->right = create_node(7);
	root1->left->left = create_node(4);
	root1->left->right = create_node(1);

	root2 = create_node(2);
	root2->left = create_node(4);
	root2->right = create_node(1);

	ans = check_subtrees(root1, root2);
	if (ans) 
		printf("Tree 2 is a subtree of tree 1\n");
	else
		printf("Tree 2 is NOT a subtree of tree 1\n");	
	return 0;
}


