/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_37_user_pass_hack.c */
/* gcc ex3_37_user_pass_hack.o -o program -lm */
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
