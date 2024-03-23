/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_03_pow_recursive_better.c */
/* gcc ex4_03_pow_recursive_better.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

typedef unsigned long ul;

ul my_pow(ul base, ul power)
{
	if (power == 0)
	{
		return 1;
	}

	if (power == 1)
	{
		return base;
	}

	//note: even if power is odd this works
	//      due to how integers divide.
	ul half = my_pow(base, power/2);

	if (base % 2 == 0)
	{
		return half * half;
	}
	else
	{
		return half * half;
	}

	return half * half * ((base % 2 == 0) ? 1 : base);
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
