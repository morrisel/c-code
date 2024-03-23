/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex06_basic_enum.c */
/* gcc ex06_basic_enum.o -o program -lm */
#include <stdio.h>

// enum Color { RED, GREEN, YELLOW, BLUE};
// enum Mood { HAPPY, NEUTRAL, BLUE};

enum Color { COLOR_RED, COLOR_GREEN, COLOR_YELLOW, COLOR_BLUE };
enum Mood {MOOD_HAPPY, MOOD_NEUTRAL, MOOD_BLUE};

enum {MODE_OFF, MODE_ON};
typedef int Mode;

int main(void)
{
	enum Color color1;
	printf("enter color (0-red, 1-green, 2-yellow, 3-blue):");
	scanf("%u", &color1);

	enum Color color2 = COLOR_RED;
	enum Color color3 = 1234;

	return 0;
}
