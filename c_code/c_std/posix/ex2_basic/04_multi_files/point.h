#ifndef POINT_H_0bd70b1bde604b34953f0a4fe37552c2
#define POINT_H_0bd70b1bde604b34953f0a4fe37552c2

#include <stdbool.h>

typedef struct Point Point;
struct Point {
    double x;
    double y;
};

//takes a point and prints it on the screen
// p: the point to print
// has_newline: if true print a newline
//              in the end, else stay on 
//              the same line
//
void point_print(Point p, bool has_newline);

//takes two points and prints their distance
double point_distance(Point p1, Point p2);

#endif /* POINT_H_0bd70b1bde604b34953f0a4fe37552c2 */
