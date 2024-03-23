/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_04_recursion_pow_v2.c */
/* gcc ex4_04_recursion_pow_v2.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

typedef unsigned long ul;

ul my_pow(ul base, ul power)
{
	ul result = 1;
	while (power--)
	{
		result = result * base;
	}

	return result;
}

ul my_pow_recursion(ul base, ul power)
{
	if (power == 0)
		return 1;

	return base * my_pow_recursion(base, power - 1);
}

int main(void)
{
	ul base;
	ul power;

	printf("enter base: ");
	scanf("%lu", &base);

	printf("enter power: ");
	scanf("%lu", &power);

	printf("%lu ** %lu = %lu\n", base, power, my_pow_recursion(base, power));

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
 * =================================================================================== */
