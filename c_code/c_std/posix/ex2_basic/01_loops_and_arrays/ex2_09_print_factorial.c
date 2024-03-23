/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_09_print_factorial.c */
/* gcc ex2_09_print_factorial.o -o program -lm */
#include <stdio.h>

/** Factorial n!
 *  ------------
 *  n*(n-1) = n!
 */
void print_factorial(unsigned int n)
{
	unsigned int i = n;
	n = 1;

	for (; i>0; i--)
		n=n*i;

	printf("%u", n);
	puts("");
}

int main(void)
{
	unsigned int num;

	printf("enter a number: ");
	scanf("%u", &num);
	
	print_factorial(num);

	return 0;
}
