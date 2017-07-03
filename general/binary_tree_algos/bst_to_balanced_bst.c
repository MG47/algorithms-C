/* 
* Program to convert BST to balanced BST 
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
	struct node *n;
	n = malloc(sizeof(struct node));
	if (!n)
		exit(EXIT_FAILURE);
	n->left = NULL;
	n->right = NULL;
	n->data = data;
	return n;
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

void print_preorder(struct node *n)
{
	if (!n)
		return;
	printf(" %d", n->data);
	print_preorder(n->left);
	print_preorder(n->right);
}

int get_size(struct node *root)
{
	int l_size, r_size;
	if (!root)
		return 0;

	l_size = get_size(root->left);
	r_size = get_size(root->right);

	return (l_size + r_size + 1);
}

void store_inorder(struct node *root, struct node **arr, int *index)
{
	if (!root)
		return;

	store_inorder(root->left, arr, index);
	arr[(*index)] = root;
	(*index)++;
	store_inorder(root->right, arr, index);
}

struct node *get_balanced_bst(struct node **arr, int start, int end)
{
	int mid;
	struct node *root;
	if (start > end)
		return NULL;

	mid = (start + end) / 2;

	root = arr[mid];

	root->left = get_balanced_bst(arr, start, mid - 1);
	root->right = get_balanced_bst(arr, mid + 1, end);

	return root;
}

struct node *bst_to_balanced_bst(struct node *root)
{
	int size, index;
	struct node **arr, *ans;
	if (!root)
		return NULL;
	size = get_size(root);

	arr = malloc(sizeof(struct node *) * size);
	if (!arr)
		exit(EXIT_FAILURE);

	/* Store bst inorder to get sorted array */
	index = 0;
	store_inorder(root, arr, &index);
	int i  = 0;
	
	ans = get_balanced_bst(arr, 0, size - 1);
	free(arr);
	return ans;
}

int main()
{
	int ans;
	struct node *root = NULL, *new = NULL;

	insert_node(&root, 4);
	insert_node(&root, 3);
	insert_node(&root, 16);
	insert_node(&root, 17);
	insert_node(&root, 15);
	insert_node(&root, 6);
	insert_node(&root, 2);
	insert_node(&root, 5);

	print_preorder(root);
	printf("\n\n");

	new = bst_to_balanced_bst(root);
	if (root) {
		printf("Balanced Binary Search Tree - Preorder:\n");
		print_preorder(new);
		printf("\n\n");
	} 
	return 0;
}


