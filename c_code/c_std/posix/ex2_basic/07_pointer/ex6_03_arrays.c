/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex6_03_arrays.c */
/* gcc ex6_03_arrays.o -o program -lm */

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
	int numbers[MAX] = { 11, 22, 33, 44, 50 };

	print_ints(numbers, MAX);

	puts("");
	return 0;
}

/*
 *
 * Compilation processes:
 * ----------------------
 *  gcc [-std=c89 -c -g -O0] [-pedantic -Wall -Wextra -Werror -Wshadow] [file_name].c
 *      ^                    ^                                          ^
 *      compilation          diagnostical                               filename
 *      flags                flags                                      for
 *                                                                      compilation
 *
 *
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 *
 *
 * ================================================================================================
 *
 *
 * Compilation processes:
 * ----------------------
 *  gcc [-std=c89 -c -g -O0] [-pedantic -Wall -Wextra -Werror -Wshadow] [file_name].c
 *      ^                    ^                                          ^
 *      compilation          diagnostical                               filename
 *      flags                flags                                      for
 *                                                                      compilation
 *
 * Basic compilation:
 *     gcc -std=c89 -c -g -O0 hw1_array.c
 *
 *     This command compiles the hw1_array.c file with basic options:
 *         -std=c89: specifies the C89 standard.
 *         -c: generates an object file (*.o) instead of an executable file.
 *         -g: generates debugging information.
 *         -O0: no optimization
 *
 * Compilation with additional flags:
 *     gcc [-std=c89 -c -g -O[0-4]] [additional flags:[-pedantic -Wall -Wextra -Werror -Wshadow]] [file_name].c
 *
 *     This command allows you to specify additional flags to the compiler:
 *         -O[0-4]: specifies the optimization level (0 - no optimization, 4 - highest optimization)
 *         -pedantic: enables "pedantic" mode for stricter compliance with the C89 standard.
 *         -Wall: displays all compiler warnings.
 *         -Wextra: displays additional warnings.
 *         -Werror: treats all warnings as errors.
 *         -Wshadow: warns about shadowed variables.
 *
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 *
 * Basic linking:
 *     gcc hw1_array.o -o program
 *
 *     This command links the hw1_array.o object file into an executable file named program.
 *
 * Linking with additional flags:
 *     gcc hw1_array.o -o program [additional flags:[-lm -glut -gl -xlib]]
 *
 *     This command allows you to specify additional flags to the linker:
 *        -lm: links the standard math library.
 *        -glut: links the GLUT library for graphics.
 *        -gl: links the OpenGL library for graphics.
 *        -xlib: links the X11 library for windowing.
 *
*
* Additional resources:
* ---------------------
* GNU Compiler Collection (GCC) documentation: https://gcc.gnu.org/onlinedocs/: https://gcc.gnu.org/onlinedocs/
*/




