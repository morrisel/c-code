/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_39_user_pass_protect_v2.c */
/* gcc ex3_39_user_pass_protect_v2.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SLEN 9

#define STR(X) #X
/*             ^ stringification of x . adds "" between X  */

#define XSTR(X) STR(X)
/*           ^ stringifies of x but first expands X to its macro value */

int main(void)
{
	/** gcc -std=c89 -Wall -Wextra -Wconversion -Wno-main user_pass_protect_v2.c -E
	 * check the preprocessor output of these (-E)
	 *
	puts(STR(ABCD));
	puts(STR(MAX_SLEN));
	puts(XSTR(MAX_SLEN));
	*/


	/* char username_guess[10]; */
	char username_guess[MAX_SLEN+9];

	/* char password_guess[10]; */
	char password_guess[MAX_SLEN+9];

	/* char username_correct[10] = "david"; */
	char username_correct[MAX_SLEN+9] = "david";

	/* char password_correct[10] = "1234"; */
	char password_correct[MAX_SLEN+9] = "1234";

	while (1)
	{
		printf("enter username: ");
		/* scanf("%s", username_guess); */
		
		/* scanf("%9s", username_guess); */
		scanf("%" XSTR(MAX_SLEN) "s", username_guess);

		printf("enter password: ");
		/* scanf("%s", password_guess); */

		/* scanf("%9s", username_guess); */
		scanf("%" XSTR(MAX_SLEN) "s", username_guess);

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
