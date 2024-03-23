/* gcc -std=c89 -c -g -O0 -pedantic -Wall -Wextra -Werror -Wshadow longest_repeated_sequence.c */
/* gcc longest_repeated_sequence.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>	/* For rand() and srand() */
#include <time.h>	/* For time() */

int main(void)
{
	/* Declaration variables */
	int arr[] = {5,2,4,5,9,9,2,2,2,2,2,2,2,2,4,4,4,9,8,8,5,5,5,5,5,4,1,1,2};
	int lenArr = sizeof(arr)/sizeof(arr[0]);
	int i,j;
	int count = 0, maxCount=0;

	puts("way1:");
	for(i=0, j=1; i < lenArr; i++,j++)
	{
		if (arr[i] == arr[j])
		{
			count++;
		}
		else
		{
			count = 0;
		}

		if (count > maxCount)
		{
			maxCount = count;
		}
	}
	printf("max count is: %d\n", ++maxCount);

	puts("way2:");
	for (i = 0; i < lenArr; i++)
	{
		count = 1; /* Initialize counter for repetitions of the current element */
		j = i + 1; /* Set the index to the next element */
		while (j < lenArr && arr[i] == arr[j])
		{
			count++;
			j++;
		}
		if (count > maxCount)
		{
			maxCount = count;
		}
	}
	printf("max count is: %d\n", maxCount);

	puts("\n");
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

