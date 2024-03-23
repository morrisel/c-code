/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex501_scan_string_v1.c */
/* gcc ex501_scan_string_v1.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>	/* str*, mem* ... functions  */

#define MAX 256

int main(void)
{
	char name[1024];
	char id_num[1024];

	/* BAD: unsafe depricated in C99, removed in C11 */
	/* gets(name); */

	/* still bad, but we can change it to make is safer */
	/* scanf("%s", name); */

	printf("enter your name: ");
	scanf("%1023s", name);

	printf("enter your number: ");
	scanf(" %1023[0123456789]", id_num);
	/*     ^ single space in format to read all whitespaces */

	printf("your name is: %s\n", name);
	printf("your ID number is %s\n", id_num);

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
