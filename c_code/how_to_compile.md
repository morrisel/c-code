Compiling C Files
=================

This document explains the basic steps involved in compiling C files to create executable programs.

Compilation Process
-------------------

Compiling translates human-readable C code into machine code that the computer can understand. This process involves two main steps:

Preprocessing:
--------------
	The preprocessor expands macros, removes comments, and includes header files.

Compilation:
------------
	The compiler translates the preprocessed code into assembly language.
	Typically, the gcc compiler is used for this purpose. Here's a basic compilation command with explanations (While gcc is commonly used, other compilers like cc might also be available on some systems.):

	gcc -std=c89 -c -g -O0 my_array.c -lm

	gcc: The compiler command
		-std=c89:	Specifies the C89 standard (you can use other standards like C99 or C11)
		-c:		Generates an object file (.o) instead of an executable
		-g:		Includes debugging information in the object file
		-O0:		No optimization (you can use other optimization levels)
				my_array.c: The C source file to compile
		-lm:		Links the standard math library, for linking processing

Linking Process:
----------------
	Linking combines multiple object files and libraries to create a final executable program. Here's a basic linking command:
		gcc my_array.o -o program

	gcc: The linker command
		my_array.o: The object file to link
		-o program: Specifies the name of the output executable file


Additional Notes
The specific flags used in compilation and linking will vary depending on your project's requirements.
For more information on C compilation and linking, refer to the GNU Compiler Collection (GCC) documentation: https://gcc.gnu.org/onlinedocs/.
I hope this revised version provides a clearer and more informative explanation.



Additional explanation and examples:
====================================

/* compilation: gcc *.c -c -g -O0 -std=c99 -pedantic -Wall -Wextra */
/* checking: nm *.o */
/* linking: gcc -std=c99 -pedantic -Wall -Wextra *.o -o program -lm */
/* running: ./program */

/* compilation: gcc -std=c89 -c -g -O0 my_array.c -pedantic -Wall -Wextra -Werror -Wshadow */
/* checking: nm [file_name].o */
/* linking: gcc [file_name].o -o program -lm */
/* running: ./program */


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
 *     gcc -std=c89 -c -g -O0 my_array.c
 *
 *     This command compiles the my_array.c file with basic options:
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
 *     gcc my_array.o -o program
 *
 *     This command links the my_array.o object file into an executable file named program.
 *
 * Linking with additional flags:
 *     gcc my_array.o -o program [additional flags:[-lm -glut -gl -xlib]]
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
 * GNU Compiler Collection (GCC) documentation: https://gcc.gnu.org/onlinedocs/
 */
