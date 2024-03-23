/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_13_print_array_using_pointers.c */
/* gcc ex4_13_print_array_using_pointers.o -o program -lm */
#include <stdio.h>
#include <stdbool.h>

int main(void) {                  
    //           p                  end
    int arr[] = {11,22,33,44,55}; // x
    const size_t arr_len = sizeof arr/ sizeof *arr;

    for (int *p = arr, *end = arr + arr_len;
         p != end;
         ++p
    ) {
        printf("%d ",  *p);
    }
    puts("");
    
    return 0;
}
