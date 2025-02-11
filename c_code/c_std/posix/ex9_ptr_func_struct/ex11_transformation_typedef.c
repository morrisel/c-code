#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

//TYPE
typedef void (*Transformation)(int*, int *);

//PROTO
void input(int *a, int *b) {
    printf("enter a new value for a:");
    scanf("%d", a);

    printf("enter a new value for b:");
    scanf("%d", b);
}
void cube(int *a, int *b) {
    *a = *a * *a;
    *b = *b * *b;
}
void inc(int *a, int *b) { 
    ++*a; 
    ++*b; 
}
void dec(int *a, int *b) { 
    --*a; 
    --*b; 
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp; 
}
void nothing(int *a, int *b) {}

int main(void) {

    //void (*t[5])(int *, int *) = { NULL };
    Transformation t[5] = { NULL };

    int n1 = 10, n2 = 20; //the variables to perfom transformations on
    int trans_num; //input to choose the function pointer

    puts(
        "1 - input, 2 - increase, 3 - decrease, \n"
        "4 - swap, 5 -cube, other - nothing\n"
    );

    for (size_t i = 0; i < (sizeof t/sizeof *t); ++i) {
        printf("%zu) transformation number:", i);
        scanf("%d", &trans_num);

        switch(trans_num) {
            case 1: t[i] = input; break;
            case 2: t[i] = inc; break;
            case 3: t[i] = dec; break;
            case 4: t[i] = swap; break;
            case 5: t[i] = cube; break;
            default: t[i] = nothing; break;
        }      
    }

    puts("now performing the actions on the numbers:");

    printf("n1: %3d; n2: %3d\n", n1, n2);

    for (size_t i = 0; i < (sizeof t/sizeof *t); ++i) {
        t[i](&n1, &n2);
        printf("n1: %3d; n2: %3d\n", n1, n2);
    }


    return 0;
}