/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_11_print_prime_numbers.c */
/* gcc ex2_11_print_prime_numbers.o -o program -lm */
#include <stdio.h>

void print_factorial(unsigned int n);

void print_prime_numbers(unsigned int n)
{
	unsigned int j;
	unsigned int i;
	printf("%u = ", n);
	for (i=n, j=2; i>=2; i--)
	{
		while (n%j == 0)
		{
			if (n == j)
				printf("%u", j);
			else
				printf("%u * ", j);
			n = n/j;
		}
		j++;
	}
	puts("");
}

int main(void)
{
	unsigned int num;

	printf("enter a number: ");
	scanf("%u", &num);

	print_prime_numbers(num);

	return 0;
}

void print_factorial(unsigned int n)
{
	unsigned int i = n;
	n = 1;

	for (; i>0; i--)
		n=n*i;

	printf("%u", n);
	puts("");
}
