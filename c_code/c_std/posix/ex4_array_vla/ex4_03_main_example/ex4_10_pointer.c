/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_10_pointer.c */
/* gcc ex4_10_pointer.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int num1 = 100;
	int num2 __attribute__((unused)) = 200;
	int num3 = 300;
	int num4 = 400;

	int *p1 = NULL;
	int *p2 = NULL;

	//make p1 point to num3
	p1 = &num3;

	//make p2 point to num1
	p2 = &num1;

	//change value pointed by p1 to 111
	*p1 = 111;

	//make p1 point to the same address as p2
	p1 = p2;

	//make p2 point to num4
	p2 = &num4;

	//set value pointed by p2 
	//to be the same as the value pointed by p1
	*p2 = *p1;

	return 0;
}

/* Compilation processes:
 * ----------------------
 *  gcc [-std=c89 -c -g -O0] [-pedantic -Wall -Wextra -Werror -Wshadow] [file_name].c
 *      ^                    ^                                          ^
 *      compilation          diagnostical                               filename
 *      flags                flags                                      for
 *
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 * =================================================================================== */
