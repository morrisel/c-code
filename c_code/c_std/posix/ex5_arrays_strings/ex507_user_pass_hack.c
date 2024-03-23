/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex507_user_pass_hack.c */
/* gcc ex507_user_pass_hack.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
	char username_guess[10];
	char password_guess[10];
	char username_correct[10] = "david";
	char password_correct[10] = "1234";

	while (1)
	{
		printf("enter username: ");
		scanf("%s", username_guess);

		printf("enter password: ");
		scanf("%s", password_guess);

		if (strcmp(username_correct, username_guess) == 0 &&
		    strcmp(password_correct, password_guess) == 0)
		{
			printf("access granted\n");
			break;
		}
		else
		{
			puts("access denied\n");
		}

		printf("the correct username and password is:\n");
		printf("username: %s\n", username_correct);
		printf("password: %s\n", password_correct);
	}


	puts("");
	return 0;
}

/* Compilation processes:
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
 * =================================================================================== */
