/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_34_uintptr_t_string.c */
/* gcc ex3_34_uintptr_t_string.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>	/* uintptr_t c99 */
#include <inttypes.h>	/* uintptr_t c99 */
#include <string.h>

#define X "XYZ"

int main(void)
{
	char s1[256] ="Hello";
	char s2[256]=" World";
	char s3[256]="";

	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", s3);

	puts("-----------");

	strcat(s3,s1);
	printf("s3: %s\n", s3);

	strcat(s3,s2);
	printf("s3: %s\n", s3);

	/*
	int arr[]={10,20,30,40,5};

	printf("arr takes %zu bytes in memory\n", sizeof(arr));
	printf("arr:\t\t%" PRIuPTR "\n",          (uintptr_t)arr);
	printf("arr+1:\t\t%" PRIuPTR "\n",        (uintptr_t)(arr+1));
	printf("arr+1:\t\t%" PRIuPTR "\n",        (uintptr_t)(arr+1));
	printf("&arr:\t\t%" PRIuPTR "\n",         (uintptr_t)(&arr));
	printf("&arr+1:\t\t%" PRIuPTR "\n",       (uintptr_t)(&arr+1));
	*/

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
