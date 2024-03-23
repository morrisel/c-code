/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex6_01_swap_by_value_bad.c */
/* gcc ex6_01_swap_by_value_bad.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

void swap(int num1, int num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}


int main(void)
{
	int x = 5;
	int y = 90;

	puts("before swap");
	printf("x: %d\n", x);
	printf("x: %d\n", y);

	swap(x, y);

	puts("after swap");
	printf("x: %d\n", x);
	printf("x: %d\n", y);

	puts("");
	return 0;
}
