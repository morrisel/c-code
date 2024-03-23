#include "point.h"

#include <stdio.h>
#include <math.h> //pow sqrt

void point_print(Point p, bool has_newline) {
	printf("(%g, %g)", p.x, p.y);
	if (has_newline) {
		printf("\n");
	}
}

double point_distance(Point p1, Point p2) {
	return sqrt(
			pow(p1.x - p2.x, 2)
			+
			pow(p1.y - p2.y, 2)
		   );
}
