/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow *.c */
/* gcc *.o -o program -lm */

/**
 * After compiling the files `main.c`, `add.c` and `mul.c` with the `-c` flag,
 * you can check the symbol table of each object file using the `nm` command.
 *
 * Example:
 * --------
 *
 * nm main.o
 * nm add.o
 * nm mul.o
 */

#include <stdio.h>
#include <stdbool.h>

int add(int a, int b);
int mul(int a, int b);

int main(void)
{
	printf("%d\n", add(2,3));
	printf("%d\n", mul(2,3));

	puts("");
	return 0;
}
