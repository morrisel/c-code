/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow *.c */
/* gcc *.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
//#include <math.h>       // -lm

#include "point.h"
#include "line.h"

int main(void)
{
	Point p1 = { 10, 20 };
	Point p2 = { 3, 5 };

	point_print(p1, true);
	point_print(p2, true);

	printf("distance %g", point_distance(p1, p2));

	Line lin1 = {{11,22}, {44,55}};
	line_print(lin1, true);
	printf("line length %g", line_length(lin1));


	puts("");
	return 0;
}

