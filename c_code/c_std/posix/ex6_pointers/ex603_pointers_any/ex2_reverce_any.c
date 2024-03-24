/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_reverce_any.c */
/* gcc ex2_reverce_any.o -o program -lm */
/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex7_swap_any.c */
/* gcc ex7_swap_any.o -o program */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


void swap_any(void *mem1, void *mem2, size_t sz)
{
	char *c1 = mem1;
	char *c2 = mem2;
	char temp;

	for (size_t i=0; i<sz; ++i)
	{
		temp = c1[i];
		c1[i] = c2[i];
		c2[i] = temp;
	}
}

void print_ints(int *arr, size_t len)
{
	for (size_t i=0; i<len; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("");
}

void reverse_any(void *arr, size_t cell_size, size_t arr_len)
{
	char *carr = arr;
	for (size_t left = 0, right = arr_len-1; left < right; left++, right--)
	{
		swap_any(&carr[left*cell_size], &carr[right*cell_size], cell_size);
//		swap_any(carr+(left*cell_size), carr+(right*cell_size), cell_size);
	}
}

int main(void)
{
	int arr1[] = {10, 20, 30};
	int arr2[] = {44, 66, 55};

	print_ints(arr1, 3);
	print_ints(arr2, 3);
	puts("");

	swap_any(arr1, arr2, 3);
	
	print_ints(arr1, 3);
	print_ints(arr2, 3);
	puts("");

	int arr3[] = {11,22,33,44,55,66,77,88,99};
	//               ^  ^  ^     ^  ^  ^

	size_t arr3_len = sizeof(arr3)/sizeof(*arr3);

	print_ints(arr3, arr3_len);
	//swap_any(arr3+1, arr3+5, arr3_len);
	//swap_any(arr3+1, arr3+5, 3*sizeof(int));
	swap_any(arr3+1, arr3+5, 3*sizeof(*arr3));
	print_ints(arr3, arr3_len);

	reverse_any(arr3, sizeof(int), arr3_len);
	print_ints(arr3, arr3_len);

	reverse_any(arr3, sizeof(*arr3), arr3_len);
	print_ints(arr3, arr3_len);


	puts("");
	return 0;
}

/*
 * :%s/\(\s*\)\(.*\)/\1\/\* \2 \*\//
 * :%s/   \(\s*\)    \(.*\)   /   \1   \/\* \2 \*\//
 * :%17s#// \(.*\)#/ * \1 * /
 *
 * Compilation processes:
 * ----------------------
 *  gcc [-std=c89 -c -g -O0] [-pedantic -Wall -Wextra -Werror -Wshadow] [file_name].c
 *      ^                    ^                                          ^
 *      compilation          diagnostical                               filename
 *      flags                flags                                      for
 *
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 * ================================================================================================ */

