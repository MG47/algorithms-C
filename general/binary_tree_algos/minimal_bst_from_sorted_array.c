/* 
* Program to create a binary search tree with minimal height,
* given a sorted (increasing order) array with unique integer elements
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

struct node *minimal_bst_recurse(int *arr, int start, int end)
{
	struct node *root;
	int mid;
	if (start > end)
		return NULL;

	/* Start from mid to get equal number of nodes in left & right subtrees - create minimal height */
	mid = (start + end) / 2;

	root = create_node(arr[mid]);
	root->left = minimal_bst_recurse(arr, start, mid - 1);
	root->right = minimal_bst_recurse(arr, mid + 1, end);
	return root;
}

struct node *minimal_bst(int *arr, int len)
{
	int start, end;
	start = 0;
	end = len - 1;
	return minimal_bst_recurse(arr, start, end);	
}

int main()
{
	int i, ans, *arr, len;
	struct node *root = NULL;

	len = 10;
	arr = malloc(sizeof(int) * len);

	for (i = 0; i < len; i++)
		arr[i] = 5 * i + 5;

	root = minimal_bst(arr, len);
	if (root) {
		printf("Minimal Binary Search Tree inorder:\n");
		print_inorder(root);
		printf("\n\n");
	} 
	return 0;
}


