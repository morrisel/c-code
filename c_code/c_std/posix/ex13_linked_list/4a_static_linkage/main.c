#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#include "data.h"

//main has its own secret
int secret = 222;
void print_main_secret(void);
void f(void);

int main(void) {
    print_n();
    printf("value of n: %d\n", n);
    print_main_secret();

    return 0;
}

void print_main_secret(void) {
    puts("main::print_secret");
    printf("%d\n", secret);
}

void f(void) {
    puts("this is f from main");
}