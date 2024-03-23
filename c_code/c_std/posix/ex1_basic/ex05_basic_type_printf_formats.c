/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex05_basic_type_printf_formats.c */
/* gcc ex05_basic_type_printf_formats.o -o program -lm */
#include <stdio.h>

int main(void)
{
	int x = 456;
	double d = 12.47;

	printf("x = [%d]\n", x);
	printf("x = [%12d]\n", x);
	printf("x = [%-12d]\n", x);
	printf("x = [%012d]\n", x);

	printf("d = [%f]\n", d);
	printf("d = [%g]\n", d);
	printf("d = [%12f]\n", d);
	printf("d = [%12.3f]\n", d);
	printf("d = [%12.2f]\n", d);
	printf("d = [%12.1f]\n", d);

	printf("0.1 + 0.2 = %f\n", 0.1 + 0.2);
	printf("0.1 + 0.2 = %.20f\n", 0.1 + 0.2);

	return 0;
}
