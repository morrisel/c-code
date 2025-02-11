//extern int n;

//bad: don't define global in 
//headers!
int n = 555;

void f(void);

//bad: don't define functions
//in headers (except inline)
#include <stdio.h>
void f(void) {
    puts("data::f()");
}


