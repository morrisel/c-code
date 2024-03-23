/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_02_while.c */
/* gcc ex2_02_while.o -o program -lm */
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

		while (height--)
		{
			int i = width;
			while (i--)
			{
				putchar('*');
			}
			putchar('\n');
		}
	}

	puts("");
	return 0;
}
