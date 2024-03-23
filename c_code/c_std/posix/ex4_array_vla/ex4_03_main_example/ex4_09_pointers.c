/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_09_pointers.c */
/* gcc ex4_09_pointers.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int num1 = 100;
	int num2 = 200;

	int *p = NULL;

	printf("num1: %4d; address: %p\n", num1, (void *)&num1);
	printf("num2: %4d; address: %p\n", num2, (void *)&num2);
	printf("*p:   %4d;       p: %p\n", p!=NULL?*p:-999 ,(void *) p);
	puts("");

	p = &num1;

	printf("num1: %4d; address: %p\n", num1, (void *)&num1);
	printf("num2: %4d; address: %p\n", num2, (void *)&num2);
	printf("*p:   %4d;       p: %p\n", p!=NULL ? *p : -999, (void *)p);
	puts("");

	*p = 333;

	printf("num1: %4d; address: %p\n", num1, (void *)&num1);
	printf("num2: %4d; address: %p\n", num2, (void *)&num2);
	printf("*p:   %4d;       p: %p\n", p!=NULL?*p:-999 , (void *)p);
	puts("");

	p = &num2;

	printf("num1: %4d; address: %p\n", num1, (void *)&num1);
	printf("num2: %4d; address: %p\n", num2, (void *)&num2);
	printf("*p:   %4d;       p: %p\n", p!=NULL?*p:-999 , (void *)p);
	puts("");

	//*p = *p + 1;
	//*p += 1;
	//(*p)++;
	//++(*p);
	++*p;

	printf("num1: %4d; address: %p\n", num1, (void *)&num1);
	printf("num2: %4d; address: %p\n", num2, (void *)&num2);
	printf("*p:   %4d;       p: %p\n", p!=NULL?*p:-999 , (void *)p);
	puts("");

	num2 /= 2;

	printf("num1: %4d; address: %p\n", num1,(void *) &num1);
	printf("num2: %4d; address: %p\n", num2,(void *) &num2);
	printf("*p:   %4d;       p: %p\n", p!=NULL?*p:-999 , (void *)p);
	puts("");

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
