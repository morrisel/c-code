/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_11_array.c */
/* gcc ex3_11_array.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>		  /* size_t (less lib) */

typedef unsigned long ul;

int main(void)
{
	int nums[] = {10, 20, 30, 40, 50};
	const int nums_len = sizeof(nums) / sizeof(nums[0]);

	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i)
	{
		printf("%d ", nums[i]);
	}
	puts("");

	for (size_t i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i)
	{
		printf("%d ", nums[i]);
	}
	puts("");

	for (int i = nums_len - 1; i >= 0; --i)
	{
		printf("%d ", nums[i]);
	}
	puts("");

	for (int i = 0; i < nums_len; i++)
	{
		printf("%d ", nums[nums_len - 1 -i]);
	}

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
 * ================================================================================================ */
