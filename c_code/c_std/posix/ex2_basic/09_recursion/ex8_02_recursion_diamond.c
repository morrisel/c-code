/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex8_02_recursion_diamond.c */
/* gcc ex8_02_recursion_diamond.o -o program -lm */
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

ul my_pow_v2(ul base, ul power)
{
	if (power == 0)
		return 1;

	return base * my_pow_v2(base, power);
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

	puts("");
	return 0;
}
