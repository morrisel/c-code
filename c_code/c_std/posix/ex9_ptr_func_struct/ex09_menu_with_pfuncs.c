#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//TYPES
//

//typedef void (*Action)(); // <- this is not a function taking void
//this is a function taking an unspecified amount of parameters
//it is adviced not to use this style of function pointer. it is
//meant for older code.

typedef void (*Action)(void);

typedef struct MenuItem {
    const char *description;
    Action action;
} MenuItem;

//PROTO
//
void action1(void) { puts("ACTION ONE"); }
void action2(void) { puts("ACTION TWO"); }
void action3(void) { puts("ACTION THREE"); }
void action4(void) { puts("ACTION FOUR"); }
void action_quit(void) {
    puts("goodbye.");
    exit(0);
}

//GLOBALS
//
MenuItem menu[] = {
    {"Perform Action 1", action1},
    {"Perform Action 2", action2},
    {"Perform Action 3", action3},
    {"Perform Action 4", action4},
    {"Exit the program", action_quit},
};


//MAIN
//
int main(void) {
    size_t option;

    while (true) {
        for (size_t i = 0; i < (sizeof menu/sizeof *menu); ++i) {
            printf("%zu) %s\n", i+1, menu[i].description);
        }
        puts("");

        printf("option: ");
        scanf("%zu", &option);
        
        option--; //convert from menu number to array index

        //error if option out of range:
        if (option >= (sizeof menu/sizeof *menu)) {
            puts("invalid option number");
            continue;
        }
        
        //perform the action based on the option number
        menu[option].action();

    } //end while
    
    return 0;
}