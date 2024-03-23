/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex5_03_input_is_even.c */
/* gcc ex5_03_input_is_even.o -o program -lm */

/* Prompts for Input:
 * 	The code asks the user to enter a number for checking.
 *
 * Reads Input:
 * 	It reads the input from the user, handling spaces and invalid characters.
 *
 * Checks for Even or Odd:
 * 	It determines whether the entered number is even or odd.
 *
 * Outputs Result:
 * 	It prints a message indicating whether an even or non-even number was entered. */

#include <stdio.h>
#include <stdbool.h>

bool input_is_even(void);

int main(void)
{
	bool result = false;

	printf("Input: \t");
	result = input_is_even();
	if (result)
	{
		printf("Output: even number putted\n");
	}
	else
	{
		printf("Output: ins't even number\n");
	}

	return 0;
}

bool input_is_even(void)
{
	int ch;
	int num = 0;
	int digit;

	/* Skip leading spaces */
	while ((ch = getchar()) == ' ');

	/* Read digits until a new line */
	while (ch != '\n')
	{
		/* Check if the character is a digit */
		if (ch >= '0' && ch <= '9')
		{
			digit = ch - '0';
			num = num * 10 + digit;
		}
		else
		{
			/* If an invalid character is encountered, handle the error (can alse coose to ingnore */
			printf("Error: Invalid input\n");
			return false;
		}
		ch = getchar();
	}

	/* Chek if the number is even */
	return (num % 2 == 0);
}
