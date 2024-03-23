/* gcc -std=c89 -c -g -O0 -pedantic -Wall -Wextra -Wshadow array_cyclic_shift_left.c */
/* gcc array_cyclic_shift_left.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>


int main(void)
{
	int arr[10] = {43, 23, 4, 9, 78, 5, 9, 3, 8, 5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int i;
	int j;
	int k=1;

	puts("cyclic shift left");
	printf("array before shifting:\t\t");
	for (i=0; i<10; i++)
	{
		printf("%d ", arr[i]);
	}
	
	puts("");
	printf("array after shifting:\t\t");
	for (i=0; i<k; i++)
	{
		int temp = arr[0];
		for (j=0; j<n; j++)
		{
			arr[j-1] = arr[j];
		}
		arr[n-1] = temp;
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
