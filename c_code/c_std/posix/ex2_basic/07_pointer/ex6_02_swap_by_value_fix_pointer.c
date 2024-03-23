/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex6_02_swap_by_value_fix_pointer.c */
/* gcc ex6_02_swap_by_value_fix_pointer.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

void swap(int *p_num1, int *p_num2)
{
	int temp = *p_num1;
	*p_num1 = *p_num2;
	*p_num2 = temp;
}


int main(void)
{
	int x = 5;
	int y = 90;

	puts("before swap");
	printf("x: %d\n", x);
	printf("x: %d\n", y);

	swap(&x, &y);

	puts("after swap");
	printf("x: %d\n", x);
	printf("x: %d\n", y);

	puts("");
	return 0;
}
