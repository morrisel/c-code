/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow *.c */
/* gcc *.o -o program -lm */

/**
 * compilations:
 * -------------
 * min version: gcc *.c -c -std=c99 -pedantic -Wall -Wextra
 *                                             
 * check if all correct:
 * ---------------------
 * nm *.o
 *                                             
 * linking:
 * --------
 * min version: gcc main.o mul.o add.o -o program
 *
 * Note! If nesessary to use with an external library, we can add the -lm flag to the end
 *       of linking and connect to #include <math.h> library.
 * */

#include <stdio.h>
#include <stdbool.h>

// compilations:
// gcc *.c -c -std=c99 -pedantic -Wall -Wextra

// check if all correct:
// nm *.o

// linking:
// gcc main.o mul.o add.o -o prog

#include "add.h"
//int add(int a, int b);

#include "mul.h"
//int mul(int a, int b);


int main(void)
{
	printf("%d\n", add(2,3));
	printf("%d\n", mul(2,3));

	puts("");
	return 0;
}

