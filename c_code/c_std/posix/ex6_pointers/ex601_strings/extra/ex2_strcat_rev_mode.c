/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_strcat_rev_mode.c */
/* gcc ex2_strcat_rev_mode.o -o program */
#include <stdio.h>

/* concatenate string to the end  */
char *my_strcat(char *dest, const char *src);

/* concatenate two strings by n characters  */
char *my_strncat(char *dest, const char *src, size_t n);

/* copy a string */
char *my_strcpy(char *dest, const char *src);

/* copy a string n characters */
char *my_strncpy(char *dest, const char *src, size_t n);

/* concatenate two strings  */
char *my_strncat_v1(char *dest, const char *src, size_t n);
char *my_strncat_v2(char *dest, const char *src, size_t n);

void print_str(char *str)
{
	printf("%s\n", str);
}


int main(void)
{
	/*
	// ERROR: *** stack smashing detected ***: terminated
	//	  Aborted (core dumped)
	//	  We need to define size explicitly for the strings
	//char source[]="Hello, World!";
	//char target[]="one two three";*/

	char source[50]="Hello, World!";
	char target[50]="one two three";
	size_t n = 4;

	puts("Before:");
	print_str(source);
	print_str(target);

	/* my_strcpy(target, source); */
	/* my_strcat(target, source); */
	my_strncat_v2(target, source, n);
	puts("");

	puts("After:");
	print_str(source);
	print_str(target);

	return 0;
}

/* concatenate string to the end  */
char *my_strcat(char *dest, const char *src)
{
	int i, j;

	/* set and initialize the i variable to the end of the destination */
	for (i=0; dest[i] != '\0'; i++);

	/* add second arr to the tail of the first array */
	for (j=0; src[j]!='\0'; j++)
		dest[i++] = src[j];

	/* add the null terminator at the end */
	dest[i] = '\0';

	return dest;
}

/* concatenate two strings  */
char *my_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = 0;
	size_t i;

	while (dest[dest_len] != '\0') dest_len++;
	printf("%zu\n", dest_len);

	for (i = 0 ; i < n && src[i] != '\0' ; i++)
		dest[dest_len + i] = src[i];

	dest[dest_len + i] = '\0';

	return dest;
}

/* copy a string */
char *my_strcpy(char *dest, const char *src) {
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return dest;
}

/* copy a string n-characters */
char *my_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';

	dest[i] = '\0';
	return dest;
}

char *my_strcpy_v2(char *dest, const char *src)
{
	char *d = dest;
	while (*src) {
		*d = *src;
		d++;
		src++;
	}

	return dest;
}

/* concatenate two strings v1 */
char *my_strncat_v1(char *dest, const char *src, size_t n)
{
	size_t dest_len;
	size_t i;

	for (dest_len=0; dest[dest_len]!='\0'; dest_len++);

	for (i = 0 ; i < n && src[i] != '\0' ; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return dest;
}

/* concatenate two strings v2  */
char *my_strncat_v2(char *dest, const char *src, size_t n)
{
	size_t dest_len = 0;

	while (dest[dest_len] != '\0') {
		dest_len++;
	}

	/* Copy no more than n characters from src to the end of dest */
	size_t i;
	for (i = 0; i < n && src[i] != '\0'; i++) {
		dest[dest_len + i] = src[i];
	}

	dest[dest_len + i] = '\0';

	return dest;
}

/*
 * :%s/\(\s*\)\(.*\)/\1\/\* \2 \*\//
 * :%s/   \(\s*\)    \(.*\)   /   \1   \/\* \2 \*\//
 * :%17s#// \(.*\)#/ * \1 * /
 * %s/\/\/\(.*\)/\/ *\1 *\//gc
 *
 * Compilation processes:
 * ----------------------
 *  gcc [-std=c89 -c -g -O0] [-pedantic -Wall -Wextra -Werror -Wshadow] [file_name].c
 *      ^                    ^                                          ^
 *      compilation          diagnostical                               filename
 *      flags                flags                                      for
 *
 *
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 *
 * ================================================================================================ */
