/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex09_basic_struct.c */
/* gcc ex09_basic_struct.o -o program -lm */
#include <stdio.h>
#include <math.h>

typedef struct Point
{
	double x;
	double y;
} Point;

int main(void)
{
	Point point1 = { 0 }, point2 = { 0 };

	printf("enter point1 x & y:");
	scanf("%lf %lf", &point1.x, &point1.y);

	printf("enter point2 x & y:");
	scanf("%lf %lf", &point2.x, &point2.y);

	printf("point1: (%g, %g)\n", point1.x, point1.y);
	printf("point2: (%g, %g)\n", point2.x, point2.y);

	double distance = sqrt(
			pow(point1.x - point2.x, 2)
			+ pow(point1.y - point2.y, 2)
			);

	printf("distance: %g\n", distance);

	// printf("distance: %g\n", sqrt(
	//     pow(point1.x - point2.x, 2)
	//     + pow(point1.y - point2.y, 2)
	// ));

	return 0;
}
