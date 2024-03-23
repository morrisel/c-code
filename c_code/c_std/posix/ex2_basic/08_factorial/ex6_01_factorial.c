/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex6_01_factorial.c */
/* gcc ex6_01_factorial.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

typedef unsigned long long ull;

// iterative solution:
ull factorial(ull num)
{
	ull result = 1;
	for (ull i = 1; i <= num; i++)
	{
		result = result * i;
	}

	return result;
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
