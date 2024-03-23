/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_02_pow_recursive_naive.c */
/* gcc ex4_02_pow_recursive_naive.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

typedef unsigned long ul;

ul my_pow(ul base, ul power)
{
	if (power == 0)
	{
		return 1;
	}
	return base * my_pow(base, power-1);
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
