#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

//extern int n;//declared not defined
//int n;     //weak define as 0
//int n = 0; //strong define as 0
int n = 555;

// void f(void);
//extern void f(void);

int main(void) {
    printf("n: %d\n", n);
    // f();
    return 0;
}