/* gcc -ansi -c -g -O0 -pedantic -Wall -Wextra -Wshadow input_to_lower_output.c */
/* gcc input_to_lower_output.o -o program -lm */
#include <stdio.h>

void input_to_lower_output(void);

int main(void)
{
	puts("Enter text to lower output");
	printf("Input: \t");
	input_to_lower_output();
	puts("");

	return 0;
}


void input_to_lower_output(void)
{
	int counter=0;
	int ch;
	while ((ch=getchar()) != '\n')
	{
		if (ch >= 'A' && ch <= 'Z')
		{
			counter++;
			ch += 32;
		}
		putchar(ch);
	}
	puts("");
	printf("%d", counter);
}
