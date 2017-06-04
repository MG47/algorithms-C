/* Binary Tree to Binary Search Tree Conversion */
/* INCOMPLETE */

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
};

int main()
{
	printf("\nBinary Tree to Binary Search Tree Conversion\n\n");

	int option;
	struct interval_table *int_table = NULL;
	int_table = create_interval_table(10);

	while (1) {
		printf("\nEnter the option number:\n");
		printf("1. Create Interval \n");
		printf("2. Merge Intervals \n");
		printf("3. Print Intervals \n");
		printf("4. Exit\n");
		printf("\n\n");

		printf("Enter the option number: ");
		scanf("%d", &option);
		int data1, data2, position;

		switch (option) {
		case 1:
			printf("Enter Start of Interval: ");
			scanf("%d", &data1);
			printf("Enter End of Interval: ");
			scanf("%d", &data2);
			create_interval(int_table, data1, data2);
			break;
		case 2:
			merge_intervals(int_table);
		case 3:
			print_intervals(int_table);
			break;
		case 4:
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("Invalid Option\n");
		}
	}
	return 0;
}


