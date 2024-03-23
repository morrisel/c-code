/* gcc -std=c89 -c -g -O0 -pedantic -Wall -Wextra -Werror -Wshadow ex4_01_pow_non_recursive.c */
/* gcc ex4_01_pow_non_recursive.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

typedef unsigned long ul;

ul my_pow(ul base, ul power)
{
	ul result = 1;
	while (power--)
	{
		result *= base;
	}
	return result;
}

int main(void)
{
	ul base;
	ul power;

	while (true)
	{
		printf("enter base: ");
		scanf("%lu", &base);
		printf("enter power: ");
		scanf("%lu", &power);

		printf("%lu ** %lu = %lu\n", base, power, my_pow(base, power));
	}
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
