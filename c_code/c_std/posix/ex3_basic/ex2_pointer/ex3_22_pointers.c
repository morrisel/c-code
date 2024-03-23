/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_22_pointers.c */
/* gcc ex3_22_pointers.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>


int main(void)
{
    int num1 = 100;
    int num2 = 200;
    int num3 = 300;
    int num4 = 400;

    int *p1 = NULL;
    int *p2 = NULL;
    printf("*p1 = NULL: %p = NULL\n", (void *)p1);
    printf("*p2 = NULL: %p = NULL\n", (void *)p2);
    puts("");

    // make p1 point to num3
    p1 = &num3;
    printf("address of p1 = &num3: %p <-- %p\n", (void *)p1, (void *)&num3);
    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    printf("num3: %d\n", num3);
    printf("num4: %d\n", num4);
    puts("");

    // make p2 point to num1
    p2 = &num1;
    printf("address of p2 = &num1: %p <-- %p\n", (void *)p2, (void *)&num1);
    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    printf("num3: %d\n", num3);
    printf("num4: %d\n", num4);
    puts("");

    // change value pointed by p1 to 111
    *p1 = 111;
    printf("address of *p1 = 111: %p\n", (void *)(p1));
    printf("num1: %d   address: %p\n", num1, (void *)&num1);
    printf("num2: %d   address: %p\n", num2, (void *)&num2);
    printf("num3: %d   address: %p\n", num3, (void *)&num3);
    printf("num4: %d   address: %p\n", num4, (void *)&num4);
    puts("");

    // make p1 point to the same address as p2
    p1 = p2;
    printf("address of p1 = p2: %p\n", (void *)p1);
    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    printf("num3: %d\n", num3);
    printf("num4: %d\n", num4);
    puts("");

    // make p2 point to num4
    p2 = &num4;
    printf("address of p2 = &num4: %p\n", (void *)p2);
    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    printf("num3: %d\n", num3);
    printf("num4: %d\n", num4);
    puts("");

    // set value pointed by p2
    // to be the same as the value pointed by p1
    *p2 = *p1;
    printf("address of p2 = &num4: %p\n", (void *)p2);
    printf("num1: %d\n", num1);
    printf("num2: %d\n", num2);
    printf("num3: %d\n", num3);
    printf("num4: %d\n", num4);
    puts("");

    puts("");
    return 0;
}

/* Compilation processes:
 * ----------------------
 *  gcc [-std=c89 -c -g -O0] [-pedantic -Wall -Wextra -Werror -Wshadow] [file_name].c
 *      ^                    ^                                          ^
 *      compilation          diagnostical                               filename
 *      flags                flags                                      for
 *
 * Linking processes:
 * ------------------
 *  gcc [file_name].o -o [program] [-lm -glut -gl -xlib]
 *      ^                ^         ^
 *      output           prgram    exteranl
 *      filename         name      libraries
 * ================================================================================================ */
