/* gcc -std=c89 -c -g -O0 -pedantic -Wall -Wextra -Werror -Wshadow generate_unique_sorted_numbers.c */
/* gcc generate_unique_sorted_numbers.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>	/* For rand() and srand() */
#include <time.h>	/* For time() */


int main(void)
{
	/* Declaration variables */
	int 	arr[20];
	int 	n;
	int 	new_arr[20];
	int 	k,i;
	
	/* Initialization variables */
	n = sizeof(arr) / sizeof(arr[0]);
	k = 0;

	/* create array with random numbers */
	srand(time(NULL));
	for (i=0; i<n; i++)
	{
		arr[i] = rand()%15+1;
	}

	puts("");
	puts("auto-generated array:");
	puts("---------------------");
	for (i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}

	/* Initialize new_arr with zero values */
	for (i = 0; i < n; i++)
	{
		new_arr[i] = 0;
	}


	for (i = 0; i < n; i++)
	{
		if (k == 0 || arr[i] > new_arr[k - 1])
		{
			/* The element is either the last one or is in ascending order, so we store it in new_arr */
			new_arr[k++] = arr[i];
		}
	}

	/* Display the new array */
	puts("\n");
	puts("unique sorted array:");
	puts("--------------------");
	printf("new_arr[]={");
	for (i = 0; i < k; i++)
	{
		
		printf("%d", new_arr[i]);
		if (i < k - 1)
		{
			printf(", ");
		}
	}

	printf("}\n");
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

