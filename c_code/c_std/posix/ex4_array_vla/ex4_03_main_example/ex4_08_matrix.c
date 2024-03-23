/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_08_matrix.c */
/* gcc ex4_08_matrix.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

//solution if we don't know during compile time the dimensions
// (Warning: could be problematic with certain rules of the standard)
//
void print_matrix(int mat[], size_t rows, size_t cols) {
	//loop the lines
	for (size_t row = 0; row < rows; row++) {
		//loop each cell(column) in the line
		for (size_t col = 0; col < cols; col++) {
			//calculate the 1d array index from 
			//the 2d array indexes
			//
			printf("%2d ", mat[row * cols + col]);
		}

		//end of line print newline
		puts("");
	}
	puts("");
}

//solution if we know the size of lower dimentions (columns)
// during compile time
void print_matrix_v2(int mat[][4], size_t rows) {
	const size_t cols = sizeof mat[0] / sizeof mat[0][0];

	//loop the lines
	for (size_t row = 0; row < rows; row++) {
		//loop each cell(column) in the line
		for (size_t col = 0; col < cols; col++) {
			//calculate the 1d array index from 
			//the 2d array indexes
			//
			printf("%2d ", mat[row][col]);
		}

		//end of line print newline
		puts("");
	}
	puts("");
}

// C99 only using VMT (vatiably modifed type)
void print_matrix_v3(size_t rows, size_t cols, int mat[][cols]) {

	for (size_t row = 0; row < rows; row++) {        
		for (size_t col = 0; col < cols; col++) {
			printf("%2d ", mat[row][col]);
		}

		puts("");
	}

	puts("");
}

int main(void) {
	int mat[][4] = {
		{10, 20, 30, 35},
		{40, 50, 60, 65},
		{70, 80, 90, 95}
	};

	const size_t rows = sizeof mat / sizeof mat[0];
	const size_t cols = sizeof mat[0] / sizeof mat[0][0];
	print_matrix(&mat[0][0], rows, cols);
	print_matrix_v2(mat, rows);
	print_matrix_v3(rows, cols, mat);

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
