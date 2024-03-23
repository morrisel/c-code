/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_14_print_array_using_ptr.c */
/* gcc ex3_14_print_array_using_ptr.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>


int main(void)
{
	int arr[] = {11,22,33,44,55};
	const size_t arr_len=sizeof(arr)/sizeof(*arr);
	int *p;
	int *end;

	for (p=arr, end=arr+arr_len; p!=end; ++p)
	{
		printf("%d ", *p);
	}

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
