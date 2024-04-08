/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex1_strcat_strcpy_strncpy.c */
/* gcc ex1_strcat_strcpy_strncpy.o -o program */
#include <stdio.h>
#include <string.h>

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

/* concatenate string to the end */
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

/* copy a string n characters */
char *my_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for ( ; i < n; i++)
		dest[i] = '\0';

	return dest;
}

/* concatenate two strings */
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


int main(void)
{
	char dest[50]   = "Hello, World!";
	char src[50]    = "ZZZZZZ0123456789";
	/* char dest[50] = "0123456789"; */
	/* char src[50]  = "ABCone two three"; */
	/* size_t n = 5; */

	puts("Before:");
	printf("dest: %s\n", dest);
	printf("src:  %s\n", src);
	puts("");

	/* my_strcpy(dest, src);        // OK */
	/* strcpy(dest, src); */
	
	/* my_strcat(dest, src);	       // OK */
	/* strcat(dest, src); */
	
	/* my_strncpy(dest, src, n);    // OK */
	/* strncpy(dest, src, n); */
	
	/* my_strncat(dest, src, n);    // OK */
	/* strncat(dest,src, n); */
	
	puts("After:");
	printf("dest: %s\n", dest);
	printf("src:  %s\n", src);

	return 0;
}

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

        /*  add '\0' if n less than strlen(src) */
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
        /*  Set the pointer to the end of the destination string. */
        char *dpos = dest;

        /*  Move the pointer to the end of the destination string. */
        while (*dpos)
        {
                ++dpos;
        }

        /*  Copy characters from the source string to the destination string. */
        while (*src)
        {
                *dpos = *src;

                ++dpos;
                ++src;
        }

        /*  Add the null terminator at the end of the string. */
        *dpos = '\0';

        /*  Return the pointer to the head of the concatenated string. */
        return dest;
}

/** Concatenates the source string to the end of the destination string. */
char *my_strcat_v3(char *dest, const char *src)
{
        /*  finding the end of the dest */
        while (*dest != '\0') {
                dest++;
        }

        /*  copy characters from src to end of dest */
        while (*src != '\0') {
                *dest = *src;
                dest++;
                src++;
        }

        /*  write '\0' at the end after copying from src to dest */
        *dest += '\0';

        return dest;
}


/*
 * :%s/\(\s*\)\(.*\)/\1\/\* \2 \*\//
 * :%s/   \(\s*\)    \(.*\)   /   \1   \/\* \2 \*\//
 * :%17s#// \(.*\)#/ * \1 * /
 * %s/\/\/\(.*\)/\/ * \1 *\//gc
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
