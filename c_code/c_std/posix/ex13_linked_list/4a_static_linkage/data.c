#include <stdio.h>

//publicly available
int n = 555;

int secret = 111;

void f(void) {
    puts("data::f()");
}

void print_n(void) {
    puts("data::print_n()");
    puts("calling f from here");
    f();
    printf("value of n: %d\n", n);
    puts("end of data::print_n()");
}

void print_data_secret(void) {
    puts("data::print_secret()");
    printf("value of secret: %d\n", secret);
}