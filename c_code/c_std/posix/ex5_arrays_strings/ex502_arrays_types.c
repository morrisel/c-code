/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex502_arrays_types.c */
/* gcc ex502_arrays_types.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>	/* memcpy */


void print_ints(int arr[], size_t len)
{
	size_t i;
	for (i=0; i<len; ++i)
	{
		printf("%d ", arr[i]);
	}
	puts("");
}

void print_floats(float arr[], size_t len)
{
	size_t i;
	for (i=0; i<len; ++i)
	{
		printf("%.2f ", arr[i]);
	}
	puts("");
}



int main(void)
{
	int arr1[] = {10,20,30,40,50};
	int arr2[sizeof(arr1)/sizeof(arr1[0])];

	size_t len = sizeof(arr1)/sizeof(arr1[0]);
	print_ints(arr2, len);

	/* mistake */
	memcpy(arr2, arr1, len);	/* memcpy needs size not array length */
	print_ints(arr2, len);

	memcpy(arr2, arr1, sizeof(arr1));
	print_ints(arr2, len);

	memset(arr2, 0, sizeof(arr2));
	print_ints(arr2, len);

	float arr3[5];
	memset(arr3, 0, sizeof(arr3));
	print_floats(arr3, 5);
	

	puts("");
	return 0;
}

/* Compilation processes:
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
 * =================================================================================== */
