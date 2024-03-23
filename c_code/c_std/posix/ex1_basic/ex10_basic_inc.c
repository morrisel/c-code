/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex10_basic_inc.c */
/* gcc ex10_basic_inc.o -o program -lm */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int x = 5; int y = 7;

	printf("x = %d; y = %d\n", x, y);
	x++;
	y++;
	printf("x = %d; y = %d\n", x, y);
	++x;
	++y;
	printf("x = %d; y = %d\n", x, y);
	x--;
	y--;
	printf("x = %d; y = %d\n", x, y);
	--x;
	--y;
	printf("x = %d; y = %d\n", x, y);

	//---
	//x = 5;
	int num1 = x++;
	//
	//int temp = x;
	//num1 = temp;
	//x = x + 1;

	//x = 6;
	int num2 = ++x;
	//
	//x = x + 1;
	//num2 = x;

	//x = 7;
	// we can't be sure about the order
	// of evaluation
	int num3 = (x++) - x++;

	printf("num1: %d\n", num1);
	printf("num2: %d\n", num2);
	printf("num3: %d\n", num3);

	//---
	x = 2;

	// we can't be sure about the order
	// of evaluation
	printf("%f\n", pow(x++, x++));

	printf("x = %d\n", x);
	// warning x may be undefined
	x = x++;
	printf("x = %d\n", x);

	x++;
	x+=1;
	++x;

	num1 = num2 = num3 = 5;

	// error: result of (++x) is lvalue
	//++ (++x);

	return 0;
}
