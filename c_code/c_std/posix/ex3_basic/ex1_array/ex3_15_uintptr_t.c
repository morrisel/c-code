/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_15_uintptr_t.c */
/* gcc ex3_15_uintptr_t.o -o program -lm */
/* nm [file_name].o */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>	/* uintptr_t c99 */
#include <inttypes.h>	/* uintptr_t c99 */

#define X "XYZ"

int main(void)
{
	int arr[]={10,20,30,40,5};

	printf("arr takes %zu bytes in memory\n", sizeof(arr));
	printf("arr:\t\t%" PRIuPTR "\n",          (uintptr_t)arr);
	printf("arr+1:\t\t%" PRIuPTR "\n",        (uintptr_t)(arr+1));
	printf("arr+1:\t\t%" PRIuPTR "\n",        (uintptr_t)(arr+1));
	printf("&arr:\t\t%" PRIuPTR "\n",         (uintptr_t)(&arr));
	printf("&arr+1:\t\t%" PRIuPTR "\n",       (uintptr_t)(&arr+1));
	


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
