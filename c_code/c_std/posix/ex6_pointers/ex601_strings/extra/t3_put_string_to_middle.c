/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow t3_put_string_to_middle.c */
/* gcc t3_put_string_to_middle.o -o program -lm */
#include <stdio.h>
#include <string.h>


char *put_str_to_middle(char *dest, const char *src)
{
	size_t dest_len = strlen(dest);
	size_t src_len = strlen(src);
	size_t middle = dest_len / 2; // finding middle of dest

	// move part of dest from middle to src+1 distance with '\0'
	memmove(dest + middle + src_len, dest + middle, dest_len - middle + 1);

	// copying src to the middle of dest
	memcpy(dest + middle, src, src_len);

	dest[dest_len+src_len]='\0';

	return dest;
}

int main(void)
{
	char target[128]= "Hello World!";
	char source[128]= "z2bA";

	puts("Before:");
	printf("target: %s\n", target);
	printf("source: %s\n", source);
	puts("");

	put_str_to_middle(target, source);

	puts("After:");
	printf("target: %s\n", target);
	printf("source: %s\n", source);
	puts("");

	return 0;
}


char *strncpy_reverse(char *dest, const char *src, size_t n)
{
	char *temp = dest;

	strncpy(dest, src, n);
	for (size_t i = 0; i<n; i++)
	{
		temp[i] = src[n -i -1];
	}
	return temp;
}

char *strncpy_reverse_v1(char *dest, const char *src, size_t n)
{
	char *temp = dest;

	strncpy(dest, src, n);
	for (size_t i = 0; i<n; i++)
	{
		temp[i] = src[n -i -1];
	}
	return temp;
}

char *my_strncpy_reverse_v1(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t src_len, dest_len;

	for (src_len=0; src_len!=n; src_len++);
	// length of dest
	for (dest_len=0; dest[dest_len]!='\0'; dest_len++);

	// copy from the end of src to dest
	for (i=0; src[i] != '\0'; i++)
	{
		dest[i]=src[src_len -i -1];
	}

	// continue to fill the dest with the dest's characters if there are
	while (n < dest_len)
	{
		dest[n] = dest[n+1];
		n++;
	}

	// copy from dest
	dest[dest_len] = '\0';

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
