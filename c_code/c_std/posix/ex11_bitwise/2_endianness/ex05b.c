#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>


int main(void) {
    char c0[7];
    union T {
        uint64_t n;
        char c[1024];
    };

    union T t1;

    char c1[7];

    uintptr_t p = (uintptr_t)t1.c;

    printf("%" PRIuPTR"\n", p);

    printf("%d\n", p % 16 == 0);
    printf("%d\n", p %  8 == 0);
    printf("%d\n", p %  4 == 0);
    printf("%d\n", p %  2 == 0);



    return 0;
}