/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex5_04_digit_parity_analyzer.c */
/* gcc ex5_04_digit_parity_analyzer.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

/* DESCRIPTION:
 * 	This function is intended for inputting a number from the keyboard.
 *
 * PARAMS:
 * 	None, as the function simply reads input from the keyboard.
 *
 * RETURN:
 * 	The entered number of type unsigned long.
 *
 * BEHAVIOR:
 * 	The function expects the user to input a number, reads the entered digits,
 * 	and forms an unsigned long integer from them.
 * 	The resulting number is returned to the calling program. */
unsigned long input_number(void);

/* DESCRIPTION:
 * 	Check if the number of even digits is greater than the number of odd digits 
 * 	in the given number.
 *
 * PARAMS:
 * 	n The input number to be analyzed.
 *
 * RETURN:
 * 	true if the number of even digits is greater, false otherwise
 *
 * BEHAVIOR:
 * 	The function counts the number of even and odd digits in the given number.
 * 	It iterates through each digit of the number, checks if it's even or odd,
 * 	and increments the respective counters.
 * 	After analyzing all digits, the function compares the counts and returns
 * 	true if the number of even digits is greater than the number of odd digits,
 * 	otherwise, it returns false. */
bool has_more_even_digits(unsigned long n);


int main(void)
{
	puts("Input:");

	unsigned long read_num = input_number();
	bool            answer = has_more_even_digits(read_num);

	printf("%s\n", answer ? "true" : "false");


	return 0;
}


/** Examples:
 * ----------
 *
 * Argument: 4876332341
 * 	Return:
 * 	false (explanation: 5 even 5 odd, nubmer of even digits is not greater)
 *
 * Argument: 122122
 * 	Return:
 * 	true (number of even digits (4) is greater than number of odd digits (2) */
/* This function determines if the number n has a greater number of even digits than odd digits. */
bool has_more_even_digits(unsigned long n)
{
	int even_count=0;
	int odd_count=0;
	unsigned long digit;

	while (n > 0) 
	{
		digit = n % 10;
		if (digit % 2 == 0) 
			even_count++;
		else 
			odd_count++;

		n /= 10;
	}

	printf("even number: %d\n", even_count);
	printf("odd number: %d\n", odd_count);
	if (even_count == odd_count)
		return false;
	else
		return true;
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
