/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex04_basic_type_castings.c */
/* gcc ex04_basic_type_castings.o -o program -lm */

#include <stdio.h>

int main(void)
{
	signed char c1 = 1, c2 = 2;

	//signed char c3 = c1 + c2;
	signed char c3 = (signed char)(c1 + c2);

	printf("c3 = %d\n", c3);

	printf("%d\n", (int)12.5);
	printf("%u\n", (unsigned)-1);
	printf("%u\n", (unsigned)-2);

	return 0;
}
