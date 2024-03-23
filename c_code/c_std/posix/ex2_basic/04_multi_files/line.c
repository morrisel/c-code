#include "line.h"

#include <stdio.h>

void line_print(Line line, bool has_newline) {
	point_print(line.p1, false);
	printf(" --> ");
	point_print(line.p2, has_newline);
}

double line_length(Line line) {
	return point_distance(line.p1, line.p2);
}
