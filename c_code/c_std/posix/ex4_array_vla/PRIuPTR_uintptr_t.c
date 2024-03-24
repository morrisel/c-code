/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow PRIuPTR_uintptr_t.c */
/* gcc PRIuPTR_uintptr_t.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>	/* uintptr_t - since C99 */
#include <inttypes.h>	/* PRIuPTR   - since C99 */

# define PRIuPTR __PRIPTR_PREFIX "u"

int main(void)
{
	int arr[] = {10,20,30};

	printf("arr takes %zu bytes in memory\n",           sizeof(arr));
	printf("address of cell #0 of arr: %" PRIuPTR "\n", (uintptr_t)(arr));
	printf("address of cell #1 of arr: %" PRIuPTR "\n", (uintptr_t)(arr+1));
	printf("address of cell #1 of arr: %" PRIuPTR "\n", (uintptr_t)(arr+1));
	printf("address of cell #1 of arr: %" PRIuPTR "\n", (uintptr_t)(&arr[1]));
	printf("address of cell #2 of arr: %" PRIuPTR "\n", (uintptr_t)(&arr+1));

	puts("---------------------------------------");
	//printf("address of cell #%d of arr: %" PRIuPTR "\n", (int)(arr), (uintptr_t)(arr));
	printf("address of cell #%zu of arr: %" PRIuPTR "\n", (size_t)(arr), (uintptr_t)(arr));

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
 *
 * =================================================================================== */
