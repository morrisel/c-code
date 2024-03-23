/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex02_basic_types_in.c */
/* gcc ex02_basic_types_in.o -o program -lm */

#include <stdio.h>

int main(void)
{
	int i = 100;
	char c = 65;
	float f = 12.5;
	double d = 345.67;
	short h = 2; //same as "short int h = 2;"
	long l = 30000; //same as "long int l = 30000;"
	long unsigned lu1 = 234567;
	unsigned u = 5; // same as "unsigned int u = 5;"

	scanf("%d" , &i); //%d -> int

	//without space prefix: read any charcter (including newline)
	scanf("%c" , &c);  
	//with space prefix: skip whitespace, read the next char
	scanf(" %c" , &c);

	scanf("%f", &f);
	scanf("%lf", &d);
	scanf("%hd", &h);
	scanf("%ld", &l);
	scanf("%lu", &lu1);
	scanf("%u", &u);

	puts("");
	return 0;
}
