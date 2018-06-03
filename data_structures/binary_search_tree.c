/*
* Binary Search Tree
* INCOMPLETE
* Inserting duplicates is not allowed
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

struct node *find_max(struct node *n)
{
	struct node *cur = n;
	if (!cur)
		return NULL;

	while (cur->right != NULL)
		cur = cur->right;

	return cur;  
}

struct node *find_min(struct node *n)
{
	struct node *cur = n;
	if (!cur)
		return NULL;

	while (cur->left != NULL)
		cur = cur->left;

	return cur;  	
}

struct node *insert_data(struct node **root, int data)
{
	struct node *cur = *root;
	if (!cur) {
		*root = create_node(data);
		return *root;
	}

	if (data < cur->data)
		insert_data(&cur->left, data);
	else if (data > cur->data)
		insert_data(&cur->right, data);
	else
		return NULL;
}

struct node *remove_data(struct node **root, int data)
{
	struct node *cur = *root;
	if (!cur) {
		return NULL;
	}

	if (data < cur->data) {
		remove_data(&(cur->left), data);
	} else if (data > cur->data) {
		remove_data(&(cur->right), data);
	} else {
		if (cur->left == NULL && cur->right != NULL) {
			*root = (*root)->right;
			free(cur);
			return *root;
		} else if (cur->right == NULL && cur->left != NULL) {
			*root = (*root)->left;
			free(cur);
			return *root;
		}
		struct node *temp = find_min(cur->right);
		(*root)->data = temp->data;
		(*root)->right = remove_data(&((*root)->right), temp->data);
	}
}

struct node *search(struct node *n, int data)
{
	struct node *cur = n; 
	if (!cur)
		return NULL;

	if (data < cur->data)
		search(cur->left, data);
	else if (data > cur->data)
		search(cur->right, data);
	else if (data == cur->data)
		return cur;
}

void print_inorder(struct node *n)
{
	if (!n)
		return;

	print_inorder(n->left);
	printf(" %d", n->data);
	print_inorder(n->right);
}

void print_preorder(struct node *n)
{
	if (!n)
		return;

	printf(" %d", n->data);
	print_preorder(n->left);
 	print_preorder(n->right);
}

void print_postorder(struct node *n)
{
	if (!n)
		return;

	print_postorder(n->left);
	print_postorder(n->right);
	printf(" %d", n->data);
}

int main()
{
	printf("\nBinary Search Tree\n\n");

	int option;
	struct node *root = NULL;

	while (1) {
		printf("\nEnter the option number:\n");
		printf("1. Insert data \n");
		printf("2. Remove data \n");
		printf("3. Search \n");
		printf("4. Find min value\n");
		printf("5. Find max value\n");
		printf("6. Print inorder\n");
		printf("7. Print preorder\n");
		printf("8. Print postorder\n");
		printf("9. Exit\n");
		printf("\n\n");

		printf("Enter the option number: ");
		scanf("%d", &option);
		int data , position;

		switch (option) {
		case 1:
			printf("Enter data to be inserted: ");
			scanf("%d", &data);
			insert_data(&root, data);
			break;
		case 2:
			printf("Enter data to be removed: ");
			scanf("%d", &data);
			remove_data(&root, data);
			break;
		case 3:
		{
			struct node *find;
			printf("Enter data to search:");
			scanf(" %d", &data);
			find = search(root, data);
			if (find)
				printf("Data found: %d\n", find->data);
			break;
		}
		case 4:
		{
			struct node *max;
			max = find_max(root);
			if (max)
				printf("Max value in the tree : %d", max->data);
			break;
		}
		case 5:
		{
			struct node *min;
			min = find_min(root);
			if (min)
				printf("Max value in the tree : %d", min->data);
			break;
		}
		case 6:
			print_inorder(root);
			break;
		case 7:
			print_preorder(root);
			break;
		case 8:
			print_postorder(root);
			break;
		case 9:
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("Invalid Option\n");
		}
	}
	return 0;
}



