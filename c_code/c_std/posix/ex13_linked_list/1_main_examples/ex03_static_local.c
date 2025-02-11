#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

int count_v2(void) {
    static int cnt = 0;
    cnt++;
    return cnt;
}

int* get_static(void) {
    static int some_value = 3;
    printf("some_value: %d\n",some_value);
    return &some_value;
}




int main(void) {
    puts("----");
    printf("%d\n", count_v2());
    printf("%d\n", count_v2());
    printf("%d\n", count_v2());
    printf("%d\n", count_v2());
    puts("----");
    int *p = get_static();
    *p = 100;
    (void)get_static();

    // static int  my_data1;
    // //int  my_data1;
    // my_data1 = 123;
    // start_thread(f, &my_data1);

    return 0;
}
