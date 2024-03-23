/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_11_declarations.c */
/* gcc ex4_11_declarations.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int*    a __attribute__((unused)) ,
	       	b __attribute__((unused)) ,
	       	c __attribute__((unused)) ;
	//what is the type of a? int*
	//what is the type of b? int
	//what is the type of c? int

	//int* a, b, c;
	//should be treated as:
	//int *a, b, c;
	//"the asterisk (*) attaches to the right side"


	int x[3]    __attribute__((unused)) ,
	    y       __attribute__((unused)) ,
	    *z      __attribute__((unused)) ;
	//what is the type of x? int[3]
	//what is the type of y? int
	//what is the type of z? int*

	int *arr[5];
	//what is the type of arr?  int* [5]
	//an array (of size 5) of pointers to int 

	//make the first cell of arr point to b:
	//
	//*(arr[0]) = &b;
	*arr[0] = &b;

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
