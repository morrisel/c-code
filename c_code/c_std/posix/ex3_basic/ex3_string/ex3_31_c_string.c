/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_31_c_string.c */
/* gcc ex3_31_c_string.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

#define X "XYZ"

int main(void)
{
	char arr1[] = {'A', 'B', 'C', '\0'};
	char arr2[] = {'E', '\0', 'F', 'G'};
	char arr3[] = {'X', 'Y', 'Z'};

	puts("-----------");

	puts(arr1);
	puts(arr2);

	char s1[] = "hello";
	puts(s1);
	/*
	puts(s1[0]);
	puts(s1[1]);
	puts(s1[2]);
	puts(s1[3]);
	puts(s1[4]);
	puts(s1[5]);
	puts(s1[6]);
	*/

	printf("%c ", s1[0]);
	printf("%c ", s1[1]);
	printf("%c ", s1[2]);
	printf("%c ", s1[3]);
	printf("%c ", s1[4]);
	printf("%c ", s1[5]);
	printf("%c ", s1[6]);

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
