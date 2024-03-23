/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_10_print_num_time_digit_v5.c */
/* gcc ex2_10_print_num_time_digit_v5.o -o program -lm */
#include <stdio.h>

void print_time_of_digits_v5(unsigned int n)
{
	printf("start for number: %u\n", n);

	while (n != 0)
	{
		unsigned int tmp_dig = n % 10;
		unsigned int count = 0;
		unsigned int tmp_n = n;

		while (tmp_n != 0)
		{
			if (tmp_n % 10 == tmp_dig)
			{
				count++;
			}
			tmp_n = tmp_n / 10;
		}

		if (count == 1)
		{
			printf("num %u was %u times\n", tmp_dig, count);
		}
		else
		{
			printf("num %u was %u times\n", tmp_dig, count);
			/* Arithmetic calculation to remove repeating digits */

			unsigned int mytemp = 0;
			unsigned int multiplier = 1;
			tmp_n = n;

			while (tmp_n != 0)
			{
				if (tmp_n % 10 != tmp_dig)
				{
					mytemp = mytemp + (tmp_n % 10) * multiplier;
					multiplier *= 10;
				}
				tmp_n = tmp_n / 10;
			}
			n = mytemp;
			continue; /* Skip printing for the current iteration */
		}

		n = n / 10; 	/* Move to the next digit */
	}

	printf("End of function\n");
}

int main()
{
	unsigned int test_number = 37771175;
	//test_number = 1222433333;
	test_number=2111156;
	print_time_of_digits_v5(test_number);

	return 0;
}

