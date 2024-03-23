/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex504_arrays_like_strings_v2.c */
/* gcc ex504_arrays_like_strings_v2.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>	/* str*, mem* ... functions  */

#define MAX 256

int main(void)
{
	const char *arr1="ABC";
	const char *arr2="XYZ";
	const char *arr3="EFG";

	puts(arr1);
	puts(arr2);
	puts(arr3);

	char s1[MAX] __attribute__((unused))= "";


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
