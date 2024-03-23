/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_35_string_scanf.c */
/* gcc ex3_35_string_scanf.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int main(void)
{
	char name[1024];
	char id_number[1024];

	printf("enter your name: ");
	scanf("%1023s", name);

	printf("enter id number: ");
	/* scanf("%1023[0123456789]", id_number); */
	scanf(" %1023[0123456789]", id_number);

	printf("your name is: %s\n", name);
	printf("your ID number is: %s\n", id_number);


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
