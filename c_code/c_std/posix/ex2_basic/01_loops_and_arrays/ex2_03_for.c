/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_03_for.c */
/* gcc ex2_03_for.o -o program -lm */
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

		int row;
		for (row = 0; row < height; ++row)
		{
			int col;
			for (col = 0; col < width; ++col)
			{
				putchar('*');
			}
			putchar('\n');
		}
	}

	puts("");
	return 0;
}
