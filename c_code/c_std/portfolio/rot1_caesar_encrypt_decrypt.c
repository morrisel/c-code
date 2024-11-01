/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex1_rot1_caesar_encrypt_decrypt.c */
/* gcc ex1_rot1_caesar_encrypt_decrypt.o -o program -lm */
#include <stdio.h>

void encrypt(unsigned char *s);
void decrypt(unsigned char *s);


int main(void)
{
	unsigned char s[] = "This is a secret message!";

	encrypt(s);
	printf("%s\n", s);

	decrypt(s);
	printf("%s\n", s);	

	return 0;
}


void encrypt(unsigned char *s)
{
	size_t i;
	for (i = 0; s[i] != '\0'; ++i)
	{
		++s[i];
	}
}

void decrypt(unsigned char *s)
{
	size_t i;
	for (i = 0; s[i] != '\0'; ++i)
	{
		--s[i];
	}
}
