/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex6_02_factorial_recursive_v1.c */
/* gcc ex6_02_factorial_recursive_v1.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

typedef unsigned long long ull;

// iterative solution:
ull factorial(ull num)
{
	if (num == 0)
		return 1;

	return num * factorial(num - 1);
}

int main(void)
{
	ull n;

	printf("enter a number (n!): ");
	scanf("%llu", &n);

	printf("n! = %llu", factorial(n));

	puts("");
	return 0;
}
