/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_33_string_ptr.c */
/* gcc ex3_33_string_ptr.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 256

int main(void)
{
	char s1[MAX] = "";

	printf("s1 = [%s]\n", s1);

	strcpy(s1, "ABCD");
	printf("s1 = [%s]\n", s1);

	strcpy(s1, "XYZ");
	printf("s1 = [%s]\n", s1);


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
