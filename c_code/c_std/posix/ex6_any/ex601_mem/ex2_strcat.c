/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_strcat.c */
/* gcc ex2_strcat.o -o program */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

size_t my_strlen(const char *s);
size_t my_strlen_v4(const char *s);
char *my_strcat(char *dest, const char *src);
char *my_strcat_v2(char *dest, const char *src);

int main(void)
{
	char s1[255] = "ABC";
	char s2[255] = "1234";

	char *p = s1;

	printf("%s\n", s1);

	p = my_strcat_v2(p, s2);
	printf("%s\n", s1);

	p = my_strcat_v2(p, "");
	printf("%s\n", s1);

	p = my_strcat_v2(p, "qwerty");
	printf("%s\n", s1);


/* v1
	char s1[255] = "ABC";
	char s2[255] = "1234";

	printf("%s\n", s1);

	my_strcat(s1, s2);
	printf("%s\n", s1);

	my_strcat(s1, "");
	printf("%s\n", s1);

	my_strcat(s1, "qwerty");
	printf("%s\n", s1);
*/

	puts("");
	return 0;
}

char *my_strcat(char *dest, const char *src)
{
	// first position at end of dest (at '\0') "ABC"
	char *dpos = dest;
	while (*dpos)
	{
		++dpos;
		//       "ABC'\0'"  "ABC'\0'"  "ABC'\0'"  "ABC'\0'" 
		//        ^           ^           ^             ^ 
		//    ++  dpos        dpos       dpos       dpos 
	}

	// move both dpos and src forward while copying from src
	// to dpos until '\0'
	while (*src)
	{
		// copy from src to dpos
		*dpos = *src;

		// move dpos and src forward
		++dpos;
		++src;
	}

	// write '\0' at the end after copying from src to dpos
	*dpos = '\0';

	return dpos;
}

char *my_strcat_v2(char *dest, const char *src)
{
	// first position at end of dest (at '\0') "ABC"
	while (*dest)
	{
		++dest;
	}

	// move both dpos and src forward while copying from src
	// to dpos until '\0'
	while (*src)
	{
		// copy from src to dpos
		*dest = *src;

		// move dpos and src forward
		++dest;
		++src;
	}

	// write '\0' at the end after copying from src to dpos
	*dest = '\0';

	return dest;
}

size_t my_strlen(const char *s)
{
	size_t count=0;

	for (size_t i=0; s[i] != '\0'; ++i)
	{
		count++;
	}
	
	return count;
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

size_t my_strlen_v5(const char *s)
{
	size_t count=0;
	while(*s++)
	{
		++count;
	}
	
	return count;
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
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 *
 * =================================================================================== */
