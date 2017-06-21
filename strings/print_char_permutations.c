/* 
* Program to print all permutations of string characters 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void print_permute(char *str, int left_index, int right_index)
{
	int i;

	/* one permutation is ready to be printed */
	if (left_index == right_index) {
		printf("%s\n", str);

	} else {
		/* run the loop from left index -> so that permutation is done on 
		all the remaining characters of the loop in each step */
		for (i = left_index; i <= right_index; i++) {

			/* Swap characters for a new permutation */
			swap(&str[left_index], &str[i]);

			/* keep left index fixed and do permutations on all left+1 to end characters */
			print_permute(str, left_index + 1, right_index);

			/* This is to undo the swap done in previous step */
			/* This ensures that next permutation can be printed */
			swap(&str[left_index], &str[i]); 
		}
	}
}

int main()
{
	char str[] = "nxp";
	int len = strlen(str);
	print_permute(str, 0, len - 1);
	return 0;
}

