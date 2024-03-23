/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_12_print_fact_prime_time_of_digits.c */
/* gcc ex2_12_print_fact_prime_time_of_digits.o -o program -lm */
#include <stdio.h>

void print_factorial(unsigned int n);
void print_prime_numbers(unsigned int n);
void print_time_of_digits(unsigned int n);

void print_prime_numbers_v2(unsigned int n)
{
	unsigned int j;
	printf("%u = ", n); 
	for (j=2; j*j <= n; j++)
	{
		while (n%j == 0)
		{
			printf("%u", j);
			n /= j;
			if (n > 1)
				printf(" * ");
		}
		j++;
	}

	if (n > 1)
	{
		printf("%u", n);
	}
	puts("");
}

void printPrimeFactors(unsigned int num)
{
	printf("real multipliers numbers %u: ", num);
	unsigned int i; 
	for (i = 2; i <= num; i++)
	{
		while (num % i == 0)
		{
			printf("%u ", i);
			num /= i;
		}
	}

	printf("\n");
}

int main(void)
{
	unsigned int num;

	printf("enter a number: ");
	scanf("%u", &num);

	/* print_prime_numbers(num); */
	/* print_time_of_digits(num); */
	print_prime_numbers_v2(num);

	printPrimeFactors(num);

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

void print_prime_numbers(unsigned int n)
{
	unsigned int j;
	unsigned int i;
	printf("%u = ", n);
	for (i=n, j=2; i>=2; i--)		/* 10 */
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

void print_time_of_digits(unsigned int n)
{
	unsigned int temp=1;

	do
	{
		temp = n%10 * temp;
		n = n/10;
	} while (n != 0);

	printf("time of digits: %u\n", temp);
}
