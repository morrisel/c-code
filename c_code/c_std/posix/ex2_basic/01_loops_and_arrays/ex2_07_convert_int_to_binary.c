/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_07_convert_int_to_binary.c */
/* gcc ex2_07_convert_int_to_binary.o -o program -lm */
#include <stdio.h>

void print_binary_simple(unsigned int num)
{
	int i;
	for (i=sizeof(num)*8-1; i>=0; i--)
	{
		if ((i+1)%4 == 0)
			printf(" ");

		printf("%d", (num>>i)&1);
	}
	printf("\n");
}

int main(void)
{
	unsigned int number;
	printf("Enter number: ");
	scanf("%u", &number);

	printf("binary number (simple method): ");
	print_binary_simple(number);

	return 0;
}
