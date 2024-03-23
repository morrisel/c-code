/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_07_matrix.c */
/* gcc ex4_07_matrix.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

int main(void) {
	int mat[][4] = {
		{10, 20, 30, 35},
		{40, 50, 60, 65},
		{70, 80, 90, 95}
	};

	//loop the lines
	for (size_t row = 0; 
			row < sizeof mat / sizeof mat[0];
			row++
	    ) {
		//loop each cell(column) in the line
		for (size_t col = 0;
				col < sizeof mat[0]/ sizeof mat[0][0];
				col++
		    ) {
			printf("%2d ", mat[row][col]);
		}

		//end of line print newline
		puts("");
	}

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
