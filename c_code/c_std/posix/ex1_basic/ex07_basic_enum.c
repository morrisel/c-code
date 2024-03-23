/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex07_basic_enum.c */
/* gcc ex07_basic_enum.o -o program -lm */
#include <stdio.h>

enum Color
{
	COLOR_RED, COLOR_GREEN, 
	COLOR_YELLOW, COLOR_BLUE
};
typedef enum Color Color;


typedef enum
{
	MOOD_HAPPY, MOOD_NEUTRAL, MOOD_BLUE
} Mood;

typedef enum Error
{
	ERROR_BAD_INPUT, ERROR_FAILURE
} Error;


enum { MODE_OFF, MODE_ON };
typedef int Mode;


int main(void)
{
	enum Color color1;
	printf("enter color (0-red, 1-green, 2-yellow, 3-blue):");
	scanf("%u", &color1);

	//enum Color color2 = 0;
	enum Color color2 = COLOR_RED;
	enum Color color3 = 1234;

	return 0;
}
