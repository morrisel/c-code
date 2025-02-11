#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

int counter = 0;

int count_v1(void) {
    counter++;
    return counter;
}

int count_v2(void) {
    static int cnt = 0;
    cnt++;
    return cnt;
}

int count_v3(int *p_counter_memory) {
    *p_counter_memory++;
    return *p_counter_memory;
}



int main(void) {
    printf("%d\n", count_v1());
    printf("%d\n", count_v1());
    printf("%d\n", count_v1());
    printf("%d\n", count_v1());

    puts("----");
    printf("%d\n", count_v2());
    printf("%d\n", count_v2());
    printf("%d\n", count_v2());
    printf("%d\n", count_v2());

    puts("----");
    int my_counter = 70;
    printf("%d\n",count_v3(&my_counter));
    printf("%d\n",count_v3(&my_counter));
    printf("%d\n",count_v3(&my_counter));
    printf("%d\n",count_v3(&my_counter));
    printf("%d\n",count_v3(&my_counter));

    return 0;
}
