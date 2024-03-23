/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex11_basic_menu_switch.c */
/* gcc ex11_basic_menu_switch.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

enum
{
	SELECTION_EXIT, SELECTION_WATER, SELECTION_COLA,
	SELECTION_COFFEE 
};

int main(void)
{
	int drink_selection;
	int result;

	printf(	"DRINKS MENU:\n"
		"------------\n"
		"1) Water Bottle\n"
		"2) Cola\n"
		"3) Coffee\n"
		"0) Exit\n"
		"\n"
		"Enter selection: ");

	result = scanf("%d", &drink_selection);

	printf("selected drink number: %d\n", drink_selection);
	printf("scanf result: %d\n", result);

	if (result != 1)
	{
		puts("error: not an int!");
	}
	else
	{
		//drink switch
		switch(drink_selection)
		{
			case SELECTION_WATER: 
				puts("You selected Water Bottle");
				break;    
			case SELECTION_COLA:
				puts("You selected Cola");
				break;
			case SELECTION_COFFEE:
				puts("You selected Coffee");
				break;
			case SELECTION_EXIT:
				puts("You selected to Exit");
				break;
			default:
				puts("Error: invalid selection number!");
				break;
		}
	}

	puts("");
	return 0;
}
