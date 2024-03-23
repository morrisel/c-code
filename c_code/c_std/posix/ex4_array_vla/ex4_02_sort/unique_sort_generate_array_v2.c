/* gcc -std=c89 -c -g -O0 -pedantic -Wall -Wextra -Werror -Wshadow unique_sort_generate_array_v2.c */
/* gcc unique_sort_generate_array_v2.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>	/* For rand() and srand() */
#include <time.h>	/* For time() */

int main(void)
{
	int arr[100];
	int n = sizeof(arr) / sizeof(arr[0]);
	int i;
	int j;
	int temp;

	/* generate random time */
	srand(time(NULL));

	/* fill the array with random numbers */
	for (i=0; i<n; i++)
	{
		arr[i] = rand() % 10 + 1;
	}

	puts("");
	puts("array:");
	puts("------");
	for (i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("\n");

	puts("sorted array:");
	puts("-------------");
	for (i=0; i<n; i++)
	{
		for (j=i; j<n; ++j)
		{
			if (arr[i] > arr[j])
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

	puts("\n");
	puts("after removing duplicates element:");
	puts("----------------------------------");
	/* remove duplicates elements */
	temp=1;
	for (i=1; i<n; i++)
	{
		if (arr[i] != arr[i-1])
		{
			arr[temp] = arr[i];
			temp++;
		}

	}
	for (i=0; i<temp; i++)
	{
		printf("%d ", arr[i]);
	}

	puts("\n");
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
