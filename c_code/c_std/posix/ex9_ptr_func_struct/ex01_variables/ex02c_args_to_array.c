/*
This program that reads arguments as integers
stores them in a dynamic array of ints

Example:
    program 100 20 3

output:
100 20 3


Memory:
    argv:
        0          1      2     3   '\0'    (<-- index)
    ["./program", "100", "20", "3", NULL]

    argc: 4
    num_array:
        [100, 20, 3]

*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>     // SIZE_MAX

typedef unsigned long long ull;


int main(int argc, char *argv[])
{
    ull num;        // for sscanf input
    int result;     // for sscanf result

    ull *array=NULL;        // to store dynamic array of numbers
    size_t array_cap = 0;   // to store the total availble length of the array
    size_t array_len = 0;   // to store the used length of the array

    // theoretical maximum array size of type unsigned long long
    const ull SIZE_MAX_ULL = SIZE_MAX/sizeof(ull);

    size_t j = 0;
    for (int i=1; i<argc; ++i, ++j)
    {
        // parse the string into an integer (unsigned long long)
        result = sscanf(argv[i], "%llu", &num);

        if (result != 1)
        {
            //printf("ignoring %s (not an int)\n", argv[i]);
            fprintf(stderr, "ignoring \"%s\" (not an int)\n", argv[i]);
            continue;
        }

        ++array_len;
        if (array_cap < array_len)
        {
            if(array_cap == 0)
            {
                array_cap = 1;
            }
            else if (array_cap == SIZE_MAX_ULL) 
            {
                fprintf(stderr, "reach maximum array capacity, cannot increase\n");
                exit(EXIT_FAILURE);
            }
            else if (array_cap > SIZE_MAX_ULL/2)
            {
                array_cap = SIZE_MAX_ULL;
            }
            else
            {
                array_cap *= 2;
            }
            array_cap = (array_cap == 0) ? 1 : (array_cap * 2);
            // TODO: check array_cap * 2 doesn't overflow
            if (array_cap > SIZE_MAX / sizeof(ull)*2)
            {
                
            }

            array = realloc(array, (sizeof(array[0])) * array_cap);
            if (array == NULL) {
                fprintf(stderr, "could not allocate memory for the array");
                exit(EXIT_FAILURE);
            }

        }

        array[array_len - 1] = num;
    }

    for (size_t i=0; i<array_len; ++i)
    {
        printf("%llu ", array[i]);
    }
    puts("\a");

    printf("array length %zu\n", array_len);
    printf("array capacity %zu\n", array_cap);

    free(array);
    array=NULL;
    array_cap=0;
    array_len=0;


    return 0;
}
