/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_01_while.c */
/* gcc ex2_01_while.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int width;
	int height;

	while (true)
	{
		printf("enter width: ");
		scanf("%d", &width);

		printf("enter height: ");
		scanf("%d", &height);

		int row = 0;
		//int column = 0;

		while (row < height)
		{
			int column = 0;
			while (column < width)
			{
				putchar('*');
				++column;
			}
			putchar('\n');
			++row;
		}

	}

	puts("");
	return 0;
}
