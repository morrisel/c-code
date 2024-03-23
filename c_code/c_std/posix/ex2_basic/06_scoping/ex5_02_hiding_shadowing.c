/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex5_02_hiding_shadowing.c */
/* gcc ex5_02_hiding_shadowing.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

int x = 100;

void f(void)
{
	puts("F START");
	printf("global x: %d\n", x);

	int x = 5;
	printf("x: %d\n", x);

	puts("F END");
}

int main(void)
{
	puts("MAIN START");
	printf("global x: %d\n", x);

	f();
	printf("global x: %d\n", x);

	{
		puts("MAIN MIDDLE SCOPE START");

		int x = 9;
		printf("x: %d\n", x);

		{
			puts("MAIN INNER SCOPE START");

			int x = 8;
			printf("x: %d\n", x);
			puts("MAIN INNER SCOPE END");
		}

		puts("MAIN MIDDLE SCOPE END");
	}

	puts("MAIN END");
	printf("x: %d\n", x); // x is global too

	puts("");
	return 0;
}
