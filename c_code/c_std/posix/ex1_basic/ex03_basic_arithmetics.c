/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex03_basic_arithmetics.c */
/* gcc ex03_basic_arithmetics.o -o program -lm */
#include <stdio.h>

int main(void)
{
	int num1, num2;

	printf("enter two ints:");
	scanf("%d%d", &num1, &num2);

	printf("num1 = %d; num2 = %d\n", num1, num2);

	printf("sum = %d\n", num1 + num2);

	int sum = num1 + num2;
	printf("sum = %d\n", sum);

	printf("div: %f\n", (double)num1 / num2);
	//printf("div: %d\n", 1.0 * num1 / num2);

	printf("avg: %f\n", ((double)num1 + num2) / 2);


	return 0;
}
