#ifndef LINE_H
#define LINE_H

#include <stdbool.h>

#include "point.h"

typedef struct Line Line;
struct Line {
	Point p1;
	Point p2;
};

//prints a line
//line: the line to print
//has_newline: stay in line if false, newline otherwise.
void line_print(Line line, bool has_newline);

//return the length of the line
// (the distance between its two points)
double line_length(Line line);

#endif /* LINE_H */
