/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex3_23_pointer_and_array.c */
/* gcc ex3_23_pointer_and_array.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>


int main(void)
{
    int arr[] = {10, 20, 30};

    int *p0 = arr;
    printf("arr   %d: %p,      \t\t*p0   %d: %p\n", arr[0], (void *)&arr[0], *p0, (void *)p0);
    printf("arr   %d: %p,      \t\t*p0   %d: %p\n", arr[1], (void *)&arr[1], *p0, (void *)p0);
    printf("arr   %d: %p,      \t\t*p0   %d: %p\n", arr[2], (void *)&arr[2], *p0, (void *)p0);

    puts("");

    p0 = p0 + 1;
    printf("arr   %d: %p,      \t\t*p0   %d: %p\n", arr[0], (void *)&arr[0], *p0, (void *)p0);
    printf("arr   %d: %p,      \t\t*p0   %d: %p\n", arr[1], (void *)&arr[1], *p0, (void *)p0);
    printf("arr   %d: %p,      \t\t*p0   %d: %p\n", arr[2], (void *)&arr[2], *p0, (void *)p0);

    puts("");

    *p0 = *p0 + 2;
    printf("arr   %d: %p,      \t\t*p0   %d: %p\n", arr[0], (void *)&arr[0], *p0, (void *)p0);
    printf("arr   %d: %p,      \t\t*p0   %d: %p\n", arr[1], (void *)&arr[1], *p0, (void *)p0);
    printf("arr   %d: %p,      \t\t*p0   %d: %p\n", arr[2], (void *)&arr[2], *p0, (void *)p0);

    puts("");

    *p0 = *p0 + 55;
    printf("arr   %d: %p,      \t\t*p0   %d: %p\n", arr[0], (void *)&arr[0], *p0, (void *)p0);
    printf("arr   %d: %p,      \t\t*p0   %d: %p\n", arr[1], (void *)&arr[1], *p0, (void *)p0);
    printf("arr   %d: %p,      \t\t*p0   %d: %p\n", arr[2], (void *)&arr[2], *p0, (void *)p0);

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
