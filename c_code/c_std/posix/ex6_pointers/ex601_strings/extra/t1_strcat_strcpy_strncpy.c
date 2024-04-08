/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow t1_strcat_strcpy_strncpy.c */
/* gcc t1_strcat_strcpy_strncpy.o -o program -lm */
#include <stdio.h>


// concatenate string to the end
char *my_strcat(char *dest, const char *src)
{
	// src is longer, just concatenate
	size_t i, j;

	// set the i variable to the end of the destination
	for (i=0; dest[i] != '\0'; i++);

	// add second arr to the tail of the first array
	for (j=0; src[j]!='\0'; j++)
		dest[i++] = src[j];

	// add the null terminator at the end
	dest[i] = '\0';

	return dest;
}

// copy a string from src to dest
char *my_strcpy(char *dest, const char *src)
{
	size_t i;
	for (i=0; src[i]!='\0'; i++)
	{
		dest[i]=src[i];
	}

	dest[i] = '\0';
	return dest;
}

// copy a string with an n characters
char *my_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for ( ; i < n; i++)
		dest[i] = '\0';

	return dest;
}

int main(void)
{
	char dest[128]="Hello";
	char src[128]= "z2bA";
	size_t n=2;

	puts("Before:");
	printf("dest: %s\n", dest);
	printf("src:  %s\n", src);
	puts("");

	//my_strcat(dest, src);
	//my_strcpy(dest, src);
	my_strncpy(dest, src, n);

	puts("After:");
	printf("dest: %s\n", dest);
	printf("src:  %s\n", src);

	return 0;
}


/*
 * :%s/\(\s*\)\(.*\)/\1\/\* \2 \*\//
 * :%s/   \(\s*\)    \(.*\)   /   \1   \/\* \2 \*\//
 * :%17s#// \(.*\)#/ * \1 * /
 * :%s/\/\/\(.*\)/\/ * \1 *\//gc
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
 * ================================================================================================ */
