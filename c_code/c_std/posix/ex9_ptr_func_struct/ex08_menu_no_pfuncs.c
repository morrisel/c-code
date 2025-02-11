#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


void action1(void) { puts("ACTION ONE"); }
void action2(void) { puts("ACTION TWO"); }
void action3(void) { puts("ACTION THREE"); }

int main(void) {
    int option;

    while (true) {
        puts(
            "1) perform action 1\n"
            "2) perform action 2\n"
            "3) perform action 3\n"
            "0) exit"
        );

        printf("option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                action1();
                break;
            }
            case 2: {
                action2();
                break;
            }
            case 3: {
                action3();
                break;
            }
            case 0: {
                puts("goodbye.");
                exit(0);
            }
            default: {
                puts("INVALID OPTION");
            }
        } //end switch
    } //end while
    
    return 0;
}