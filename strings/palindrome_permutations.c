/*
* Check if a string is permutation of a palindrome
* "tact coa" -> "taco cat"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ASCII_SIZE 256
int check_palindrome_permutation(char *str)
{
	char *freq_table;
	int i, len, oddchars, ret;

	freq_table = calloc(ASCII_SIZE, sizeof(char));
	if (!freq_table)
		return -1;

	len = strlen(str);
	for (i = 0; i < len; i++)
		freq_table[str[i]]++;

	ret = -1;
	oddchars = 0;

	/* For even len - All characters must have even freq.
	For odd len - all except one char must have even frequency.
	*/
	if (len % 2) { 	//odd length
		for (i = 0; i < ASCII_SIZE; i++) {
			if (freq_table[i] % 2)
				oddchars++;
		}
		if (oddchars != 1) {
			ret = -1;
			goto exit_free;
		}
	} else {
		for (i = 0; i < len; i++) {
			if (freq_table[str[i]] % 2) {
				ret = -1;
				goto exit_free;
			}
		}
	}
	ret = 0;
exit_free:
	free(freq_table);
	return ret;
}

int main()
{
	printf("Check if a string is palindrome permuation\n");
	char str[200], c;
	int ret, i;

	printf("Enter a string\n");

	i = 0;
	while((c = fgetc(stdin)) != '\n')
		str[i++] = c;
	str[i] = '\0';

	ret = check_palindrome_permutation(str);
	if (!ret)
		printf("String is a perumation of a palindrome\n");
	else
		printf("String is NOT a perumation of a palindrome\n");


	return 0;
}

