/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex5_05_closet_to_prime_number.c */
/* gcc ex5_05_closet_to_prime_number.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

unsigned long 	input_number		(void);
bool 		is_prime		(unsigned n);
unsigned 	closest_prime		(unsigned n);


int main(void)
{
	unsigned long read_num = input_number();
	unsigned get_num=(unsigned)read_num;
	printf("number was putted %u ", get_num);
	printf("closest prime to %u is %u\n", get_num, closest_prime(get_num));

	puts("");
	return 0;
}

/* Function for input numbers from keyboard */
unsigned long input_number(void)
{
	printf("enter a number: ");
	unsigned long result = 0;
	int digit;

	/* while ((digit = getchar()) != '\0' && digit != EOF) */
	while ((digit = getchar()) != '\0' && digit != '\n')
	{
		if (digit >= '0' && digit <='9')
		{
			result = result * 10u + (unsigned long)(digit - '0');
		}
	}

	printf("%lu", result);
	puts("");

	return result;
}

bool is_prime(unsigned n)
{
	if (n <= 1)
		return false;

	unsigned i;
	for (i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;

	return true;
}

unsigned closest_prime(unsigned n)
{
	/* Check if the number itself is prime */
	if (is_prime(n))
		return n;

	/* Find closest smaller prime */
	unsigned smaller = n - 1;
	while (!is_prime(smaller))
	{
		smaller--;
	}

	/* Find closest larger prime */
	unsigned larger = n + 1;
	while (!is_prime(larger))
	{
		larger++;
	}

	/* Determine which prime is closer */
	if (n - smaller <= larger - n)
	{
		return smaller;
	}
	else
	{
		return larger;
	}
}
