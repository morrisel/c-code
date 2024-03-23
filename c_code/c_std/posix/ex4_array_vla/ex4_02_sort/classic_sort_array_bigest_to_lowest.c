/* gcc -std=c89 -c -g -O0 -pedantic -Wall -Wextra -Werror -Wshadow classic_sort_array_bigest_to_lowest.c */
/* gcc classic_sort_array_bigest_to_lowest.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>


int main(void)
{
	int arr[] = {4, 9, 62, 2, 3, 25};
	int n = sizeof(arr) / sizeof(arr[0]);
	int i;
	int j;
	int temp;

	puts("original array:");
	puts("---------------");
	for (i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("\n");

	puts("sort array from bigest to lowest");
	puts("--------------------------------");
	for (i=0; i<n; i++)
	{
		for (j=i; j<n; ++j)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	puts("");
	return 0;
}


/*
 * :28s/\(\s*\)\(.*\)/\1\/\* \2 \*\//
 * :28s/   \(\s*\)    \(.*\)   /   \1   \/\* \2 \*\//
 *
 * Compilation processes:
 * ----------------------
 *  gcc [-std=c89 -c -g -O0] [-pedantic -Wall -Wextra -Werror -Wshadow] [file_name].c
 *      ^                    ^                                          ^
 *      compilation          diagnostical                               filename
 *      flags                flags                                      for
 *                                                                      compilation
 *
 *
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 *
 *
 * ================================================================================================ */
