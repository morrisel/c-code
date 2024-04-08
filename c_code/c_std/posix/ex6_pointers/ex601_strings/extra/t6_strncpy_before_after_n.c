/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow t6_strncpy_before_after_n.c */
/* gcc t6_strncpy_before_after_n.o -o program -lm */
#include <stdio.h>
#include <string.h>


char *strcpy_replace_before_n(char *dest, const char *src, size_t n);
char *strcpy_replace_after_n(char *dest, const char *src, size_t n);

char *strcpy_add_before_n(char *dest, const char *src, size_t n);
char *strcpy_add_after_n(char *dest, const char *src, size_t n);


int main(void)
{
	char target[128]= "Hello,World!";
	char source[128]= "xyz";
	size_t n=6;

	puts("Before:");
	printf("target: %s\n", target);
	printf("source: %s\n", source);
	puts("");

	strcpy_replace_before_n(target, source, n);
	//strcpy_replace_after_n(target, source, n);
	
	//strcpy_add_before_n(target, source, n);
	//strcpy_add_after_n(target, source, n);

	puts("After:");
	printf("target: %s\n", target);
	printf("source: %s\n", source);
	puts("");

	return 0;
}

char *strcpy_replace_before_n(char *dest, const char *src, size_t n)
{
	size_t i, dest_len, src_len;

	// Determine the length of the original and target strings
	dest_len = strlen(dest);
	src_len  = strlen(src);

	// If not, simply copy src to the end of dest
	if (dest_len < n) {
		// If not, simply copy src to the end of dest
		strcat(dest, src);
		return dest;
	}

	// If dest_len >= n, copy src before n
	// Start from the end to avoid overlap
	/*for (i = n - src_len; i > n; i--)
	{
		dest[i + src_len - 1] = dest[i - 1];
	}*/

	// Insert src into dest before n
	for (i = 0; i < src_len; i++)
	{
		dest[n - i -1] = src[src_len -i -1];
	}

	return dest;
}

char *strcpy_replace_after_n(char *dest, const char *src, size_t n)
{
	size_t i, dest_len, src_len;

	// Determine the length of the original and target strings
	dest_len = strlen(dest);
	src_len  = strlen(src);

	// If not, simply copy src to the end of dest
	if (dest_len < n) {
		// If not, simply copy src to the end of dest
		strcat(dest, src);
		return dest;
	}

	// If dest_len >= n, copy src after n
	for (i = n + 1; (i-n-1) < src_len; i++)
	{
		dest[i] = src[i - n -1];
	}

	return dest;
}

char *strcpy_add_before_n(char *dest, const char *src, size_t n)
{
	size_t i, dest_len, src_len;

	// Determine the length of the source and destination strings
	dest_len = strlen(dest);
	src_len  = strlen(src);

	// Check if there is enough space in dest before n
	if (dest_len < n) {
		// If not, just copy src to the end of dest
		strcat(dest, src);
		return dest;
	}

	// If dest_len >= n, copy src before n
	// Start from the end to avoid intersection
	for (i = dest_len; i > n; i--)
		dest[i + src_len - 1] = dest[i - 1];

	// Insert src into dest before n
	for (i = 0; i < src_len; i++)
		dest[n + i] = src[i];

	return dest;
}

char *strcpy_add_after_n(char *dest, const char *src, size_t n)
{
	size_t i, dest_len, src_len;

	// Determine the length of the source and destination strings
	dest_len = strlen(dest);
	src_len  = strlen(src);

	// Check if there is enough space in dest before n
	if (dest_len < n) {
		// If not, just copy src to the end of dest
		strcat(dest, src);
		return dest;
	}

	// If dest_len >= n, copy src before n
	// Start from the end to avoid intersection
	for (i = dest_len; i > n; i--)
		dest[i + src_len - 1] = dest[i - 1];

	// Insert src into dest before n
	for (i =  n +1; (i -n-1) < src_len; i++)
	{
		dest[i] = src[i-n-1];
	}

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
 *                                                                      compilation
 *
 *
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 *
 *
 * ================================================================================================ */
