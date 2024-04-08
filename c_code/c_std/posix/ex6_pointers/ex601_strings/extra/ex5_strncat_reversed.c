/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex5_strncat_reversed.c */
/* gcc ex5_strncat_reversed.o -o program -lm */
#include <stdio.h>
#include <string.h>

/* concatenate two strings */
/* concatenate first n characters from src in reverse order to the end of dest */
char *my_strncat_reverse_to_end(char *dest, const char *src, size_t n)
{
	size_t dest_len = 0;
	size_t src_len = 0;
	size_t i;

	/* Find the length of dest and src */
	while (dest[dest_len] != '\0') dest_len++;
	while (src[src_len] != '\0') src_len++;

	/* Iterate over the first n characters of src in reverse order */
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[dest_len + i] = src[n - 1 - i];
	}

	dest[dest_len + i] = '\0';

	return dest;
}

/* Reverse the first n characters in a string */
void reverseFirstN(char *str, size_t n)
{
	size_t i, j;
	char temp;

	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

/* Reverse the last n characters in a string */
void reverseLastN(char *str, size_t n)
{
	size_t len = strlen(str);
	size_t i, j;
	char temp;

	for (i = len - n, j = len - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}


int main(void)
{
	char dest[20]="Hello";
	char src[20]= "Zy1234Ab";
	size_t n = 5;

	puts("Before:");
	printf("dest: %s\n", dest);
	printf("src:  %s\n", src);
	puts("");

	/* my_strncat_reverse_to_end(dest, src, n); */

	/* Use strncat to concatenate first n characters from src */
	strncat(dest, src, n);

	/* Reverse the first n characters in the newly concatenated string */
	/* reverseFirstN(dest + strlen(dest) - n, n); */

	/* Reverse the last n characters in the newly concatenated string */
	reverseLastN(dest, n);

	puts("After:");
	printf("dest: %s\n", dest);
	printf("src:  %s\n", src);

	return 0;
}



/** Classic Version **/
/* copy a string --------------------------------------- OK */
char *my_strcpy(char *dest, const char *src) {
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return dest;
}

/* concatenate string to the end ----------------------- OK */
char *my_strcat(char *dest, const char *src)
{
	int i, j;

	/* set the i variable to the end of the destination */
	for (i=0; dest[i] != '\0'; i++);

	/* add second arr to the tail of the first array */
	for (j=0; src[j]!='\0'; j++)
		dest[i++] = src[j];

	/* add the null terminator at the end */
	dest[i] = '\0';

	return dest;
}

/* copy a string n characters -------------------------- OK */
char *my_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';

	return dest;
}

/* concatenate two strings ----------------------------- OK */
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




/** Pointer version **/
/** Copying string src into dest. */
char *my_strncpy_v2(char *dest, const char *src, size_t n)
{
	char *d=dest;
	size_t i;

	for (i=0; i<n && *src; i++)
	{
		*d = *src;
		d++;
		src++;
	}

	/* add '\0' if n less than strlen(src) */
	if (i < n)
	{
		*d = '\0';
	}

	return dest;
}

/** Copying string src into dest. */
char *my_strcpy_v3(char *dest, const char *src)
{
	char *d = dest;
	while (*src) {
		*d = *src;
		d++;
		src++;
	}
	*d='\0';

	return dest;
}

/** Concatenates the source string to the end of the destination string. */
char *my_strcat_v2(char *dest, const char *src)
{
	/* Set the pointer to the end of the destination string. */
	char *dpos = dest;

	/* Move the pointer to the end of the destination string. */
	while (*dpos)
	{
		++dpos;
	}

	/* Copy characters from the source string to the destination string. */
	while (*src)
	{
		*dpos = *src;

		++dpos;
		++src;
	}

	/* Add the null terminator at the end of the string. */
	*dpos = '\0';

	/* Return the pointer to the head of the concatenated string. */
	return dest;
}

/** Concatenates the source string to the end of the destination string. */
char *my_strcat_v3(char *dest, const char *src)
{
	/* finding the end of the dest */
	while (*dest != '\0') {
		dest++;
	}

	/* copy characters from src to end of dest */
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}

	/* write '\0' at the end after copying from src to dest */
	*dest += '\0';

	return dest;
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
