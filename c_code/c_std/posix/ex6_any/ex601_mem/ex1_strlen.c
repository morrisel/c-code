/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex1_strlen.c */
/* gcc ex1_strlen.o -o program */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

size_t my_strlen(const char *s)
{
	size_t count=0;

	for (size_t i=0; s[i] != '\0'; ++i)
	{
		count++;
	}
	
	return count;
}

size_t my_strlen_v2(const char *s)
{
	size_t i=0;
	for (i=0; s[i] != '\0'; ++i);
	
	return i;
}

size_t my_strlen_v3(const char *s)
{
	size_t i=0;
	//while (s[i] != '\0')
	//while (s[i] != 0)
	while(s[i])
	{
		++i;
	}
	
	return i;
}

size_t my_strlen_v4(const char *s)
{
	size_t count=0;
	while(*s)
	{
		++count;
		++s;
	}
	
	return count;
}

int main(void)
{
	printf("%zu\n", strlen("abcd"));
	printf("%zu\n", strlen(""));
	printf("%zu\n", strlen("0123456789"));

	printf("%zu\n", my_strlen_v2("abcd"));
	printf("%zu\n", my_strlen_v2(""));
	printf("%zu\n", my_strlen_v2("0123456789"));

	printf("%zu\n", my_strlen_v4("Hi there"));

	puts("");
	return 0;
}


/*
 * :%s/\(\s*\)\(.*\)/\1\/\* \2 \*\//
 * :%s/   \(\s*\)    \(.*\)   /   \1   \/\* \2 \*\//
 * :%17s#// \(.*\)#/ * \1 * /
 *
 * Compilation processes:
 * ----------------------
 *  gcc [-std=c89 -c -g -O0] [-pedantic -Wall -Wextra -Werror -Wshadow] [file_name].c
 *      ^                    ^                                          ^
 *      compilation          diagnostical                               filename
 *      flags                flags                                      for
 *                                                                      compilation
 *
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 *
 * =================================================================================== */

