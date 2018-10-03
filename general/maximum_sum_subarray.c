/*
* Maximum sum subarray
* program to find the sum of contiguous subarray within
* a one-dimensional array of numbers which has the largest sum.
* In addition to maximum sum, this program returns
* start and end indices of the maximum subarray
* Modified Kadane’s algorithms - checks when there are no positive numbers
* TODO
*/

#include <stdio.h>
#include <stdlib.h>

struct max_sub_arr {
	int start;
	int end;
	int sum;
};

int find_max_sum_sub(struct max_sub_arr *ms, int *arr, int size)
{
	int max_so_far = 0, max_ending_here = 0;
	int positive_flag = 0;
	int start = 0, end = 0, len = 0;
	int i;

	if (!ms || !arr)
		return -1;

	for (i = 0; i < size; i++) {
		if (arr[i] > 0)
			positive_flag = 1;

		max_ending_here = max_ending_here + arr[i];
		if (max_ending_here < 0) {
			max_ending_here = 0;
		}

		/* TODO - fix start and end indices */
		if (max_ending_here > max_so_far) {
			max_so_far = max_ending_here;
			end = i;
			len++;
		} else {
			start = end - len + 1;
			len = 0;
		}
	}

	if (!positive_flag)
		return -1;

	ms->start = start;
	ms->end = end;
	ms->sum = max_so_far;
	return 0;
}

int main()
{
	int ret;
	struct max_sub_arr *ms;
	int arr[10] = {1, 2, -3, 7, 2, -5, -11, 9, 12, 11};
	ms = calloc(1, sizeof(struct max_sub_arr));
	if (!ms)
		exit(EXIT_FAILURE);

	ret = find_max_sum_sub(ms, arr, 10);
	if (!ret) {
		printf("Maximum sum subarray start: %d, end: %d, max sum: %d\n",
			ms->start,
			ms->end,
			ms->sum);
	}

	return 0;
}

