/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_08_palindrome.c */
/* gcc ex2_08_palindrome.o -o program -lm */
#include <stdio.h>

int isPalidrome(unsigned int num)
{
	unsigned int org_num=num;
	unsigned int reverse_num=0;

	while (num > 0)
	{
		reverse_num = (num % 10) + reverse_num * 10;
		num = num/10;
	}

	return org_num == reverse_num;
}

int main(void)
{
	unsigned int number;

	printf("Enter positive number: ");
	scanf("%u", &number);

	if (isPalidrome(number))
	{
		puts("this is a palindrome");
	}
	else
	{
		puts("this is not a palindrome");
	}

	return 0;
}
