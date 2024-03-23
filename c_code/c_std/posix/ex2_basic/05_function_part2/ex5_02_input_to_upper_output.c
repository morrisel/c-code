/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex5_02_input_to_upper_output.c */
/* gcc ex5_02_input_to_upper_output.o -o program -lm */
#include <stdio.h>

void input_to_upper_until_nl(void);
void input_to_upper_until_eof(void);

int main(void)
{
	puts("Enter text to upper output");
	printf("Input: \t");
	input_to_upper_until_nl();

	puts("");
	return 0;
}


void input_to_upper_until_nl(void)
{
	int counter=0;
	int ch;

	while ((ch=getchar()) != '\n')
	{
		if (ch >= 'a' && ch <= 'z')
		{
			counter++;
			ch -= 32;
		}
		putchar(ch);
	}
	puts("");
	printf("%d", counter);
}


void input_to_upper_until_eof(void)
{
	int counter=0;
	int ch;

	while ((ch=getchar()) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			counter++;
			ch -= 32;
		}
		putchar(ch);
	}
	puts("");
	printf("%d", counter);
}

