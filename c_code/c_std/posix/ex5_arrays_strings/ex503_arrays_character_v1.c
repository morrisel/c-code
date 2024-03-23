/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex503_arrays_character_v1.c */
/* gcc ex503_arrays_character_v1.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	/* bad 
	char arr1[] = {'A','B','C'};
	char arr2[] = {'X','Y','Z'};
	char arr3[] = {'E','F','G'};*/

	char arr1[] = {'A','B','C','\0'};
	char arr2[] = {'X','Y','Z','\0'};
	char arr3[] = {'E','F','G','\0'};

	puts(arr2);
	puts(arr1);

	arr2[2]=0;
	puts(arr2);

	puts(arr3);
	puts(arr3+1);
	puts(arr3+2);
	
	arr3[1]='\0';

	puts(arr3);
	puts(arr3+1);
	puts(arr3+2);


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
