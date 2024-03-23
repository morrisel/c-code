/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_36_string_scanf_password.c */
/* gcc ex3_36_string_scanf_password.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int main(void)
{
	char username_guess[10];
	char password_guess[10];
	char username_correct[10]="david";
	char password_correct[10]="1234";

	while (true)
	{
		printf("enter username: ");
		scanf("%s", username_guess);

		printf("enter password: ");
		scanf("%s", password_guess);

		if (strcmp(username_correct, username_guess) == 0 &&
		    strcmp(password_correct, password_guess) == 0)
		{
			puts("Access Granted!\n");
			break;
		}
		else
		{
			puts("access denied\n");
		}

		puts("The correct username and password is:");
		printf("username: %s\n", username_correct);
		printf("password: %s\n", password_correct);
	}


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
