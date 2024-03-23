/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex01_basic_types_out.c */
/* gcc ex01_basic_types_out.o -o program -lm */
#include <stdio.h>

int main(void)
{
	int i = 100;
	char c = 65;
	float f = 12.5;
	double d = 345.67;
	short h = 2;	// same as "short int h = 2;
	size_t st=89862314;

	printf("i = %d\n", i);
	printf("c = %c\n", c);
	printf("f = %f\n", f);
	printf("d = %lf\n", d);
	printf("f = %d\n", h);
	printf("st= %zu\n", st);

	long l = 30000;

	printf("l = %ld\n", l);

	long unsigned lu1 = 234567;
	unsigned u = 5; //same as "unsigned int u = 5;"
	printf("l = %lu\n", l);
	printf("u = %u\n", u);

	return 0;
}



/**
 * Compilation processes:
 * ----------------------
 *  gcc [-std=c89 -c -g -O0] [-pedantic -Wall -Wextra -Werror -Wshadow] [file_name].c
 *      ^                    ^                                          ^
 *      compilation          diagnostical                               filename
 *      flags                flags                                      for
 *                                                                      compilation
 *
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 *
 *
 * ======================================================================================
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
