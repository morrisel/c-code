/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex2_rot1_caesar_encrypt_decrypt_v2.c */
/* gcc ex2_rot1_caesar_encrypt_decrypt_v2.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void encrypt_v1(unsigned char *s);
void decrypt_v1(unsigned char *s);


int main(void)
{
	unsigned char s[]="This is a secret message";

	encrypt_v1(s);
	printf("%s\n", s);

	decrypt_v1(s);
	printf("%s\n", s);

	puts("");
	return 0;
}

void encrypt_v1(unsigned char *s)
{
	for (size_t i=0; s[i]!='\0'; ++i)
	{
		++s[i];
	}
}

void encrypt_v2(unsigned char *s)
{
	while(*s)
	{
		++*s;
		++s;
	}
}

void encrypt_v3(unsigned char *s)
{
	while ((*s++)++);
	--*--s;
}

void encrypt_v4(unsigned char *s)
{
	while (*s)
	{
		++*s++;
	//                        ++ *s ++
	//                         3  1  2 
	}
}

void decrypt_v1(unsigned char *s)
{
	for (size_t i=0; s[i]!='\0'; ++i)
	{
		--s[i];
	}
}

size_t my_strlen(const char *s)
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
 * 
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 *
 * =================================================================================== */
