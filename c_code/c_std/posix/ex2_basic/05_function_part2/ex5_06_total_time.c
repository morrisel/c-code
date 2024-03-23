/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex5_06_total_time.c */
/* gcc ex5_06_total_time.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

/* Function for input numbers from keyboard */
unsigned long input_number(void);

struct MyTime
{
	unsigned hours;
	unsigned minutes;
};
typedef struct MyTime MyTime;

MyTime time_from_total(unsigned total_minutes)
{
	MyTime results;
	results.hours = total_minutes/60;
	results.minutes = total_minutes%60;

	return results;
}

int main(void)
{
	unsigned total_minutes = (unsigned)input_number();
	MyTime time = time_from_total(total_minutes);
	printf("Total minutes: %u\n", total_minutes);
	printf("Converted time: %u hours, and %u minutes\n", time.hours, time.minutes);

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
