/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex5_01_input_to_lower_output.c */
/* gcc ex5_01_input_to_lower_output.o -o program -lm */
#include <stdio.h>

void input_to_lower_until_nl(void);
void input_to_lower_until_eof(void);

int main(void)
{
	puts("Enter text to lower output");
	printf("Input: \t");
	input_to_lower_until_nl();
	puts("");

	return 0;
}


void input_to_lower_until_nl(void)
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


void input_to_lower_until_eof(void)
{
	int counter=0;
	int ch;
	while ((ch=getchar()) != EOF)
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

