/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_32_char_ptr.c */
/* gcc ex3_32_char_ptr.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

#define X "XYZ"

int main(void)
{
	char c = 'a';
	char arr[5] = "abcd";
	char *p = arr;

	puts("-----------");
	printf("%c\n", c);
	printf("%c\n", arr[3]);
	printf("%c\n", arr[4]);
	printf("%c\n", arr[5]);
	printf("%s\n", arr);

	puts("-----------");
	printf("%c\n", *p);
	printf("%c\n", *p+1);
	printf("%c\n", *p+2);
	printf("%c\n", ++*p++);

	puts("-----------");
	printf("%s %s %s\n", arr, arr+2, &arr[2]);

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
