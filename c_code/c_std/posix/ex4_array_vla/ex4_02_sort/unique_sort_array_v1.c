/* gcc -std=c89 -c -g -O0 -pedantic -Wall -Wextra -Werror -Wshadow unique_sort_array_v1.c */
/* gcc unique_sort_array_v1.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>	  /* For rand() and srand() */
#include <time.h>	  /* For time() */

int main(void)
{
	int arr[] = {0,8,5,4,9,0,1,1,1,4,2,5,1,5,1,5,9,1,1,0,1,5,4,3,2,5};

	int n = sizeof(arr) / sizeof(arr[0]);
	int i;
	int j;
	int temp;

	puts("");
	puts("array:");
	puts("------");
	for (i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("\n");
	for (i=0; i<n; i++)
		printf("%d ", i);
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

	puts("");
	return 0;
}


/*
 * :%s/{\([^}]*\)}/\=substitute(submatch(1), ' ', ',', 'g')/g
 * :28s/\(\s*\)\(.*\)/\1\/\* \2 \*\//
 * :11s#[a-z]\(.*\)#/ * & * /
 * :11s#[a-z]\(.*\)#/ * \1 * /
 * :28s/   \(\s*\)    \(.*\)   /   \1   \/\* \2 \*\//
 * :17s#// \(.*\)#/ * \1 * /
 * :%s/\(\d\)\(\s\)\?/\1,/g
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
