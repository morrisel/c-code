/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_04_array_v1.c */
/* gcc ex2_04_array_v1.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

#define MAX 5

void print_ints(int arr[], int len)
{
	int i;
	for (i=0; i<len; i++)
	{
		printf("%d ", arr[i]);
	}
	puts("");
}

int main(void)
{
	int numbers[] = {10,20,30,40};
	int len_numbers = sizeof(numbers)/sizeof(numbers[0]);

	for (int i = 0; i < (int)(sizeof(numbers)/sizeof(numbers[0])); i++)
	{
		printf("%d ", numbers[i]);

	}

	printf("\n");
	print_ints(numbers, len_numbers);

	puts("");
	return 0;
}
