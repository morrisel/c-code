/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex1_malloc.c */
/* gcc ex1_malloc.o -o program */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main(void)
{
	size_t len;

	printf("How many grades to input? ");
	scanf("%zu", &len);

	int *arr = malloc(len * sizeof(int));

	for (size_t i=0; i<len; i++)
	{
		printf("enter value for #%zu: ", i);
		scanf("%d", arr+i);
	}

	for (size_t i=0; i<len; i++)
	{
		printf("%d ", arr[i]);
	}

	free(arr);
	arr = NULL;

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
 *
 * =================================================================================== */
