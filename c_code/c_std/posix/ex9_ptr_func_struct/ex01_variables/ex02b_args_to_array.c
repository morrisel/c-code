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

typedef unsigned long long ull;


int main(int argc, char *argv[])
{
    ull num;        // for sscanf input
    int result;     // for sscanf result

    ull *array=NULL;        // to store dynamic array of numbers
    size_t array_cap = 0;   // to store the total availble length of the array
    size_t array_len = 0;   // to store the used length of the array

//    array_cap = (size_t)argc-1;
//    array = malloc(sizeof(ull) * array_cap);    // void *malloc(size_t size);
//    //array = malloc(sizeof(array) * array_cap);
//    if (array == NULL) {
//        fprintf(stderr, "could not allocate memory for the array");
//        exit(EXIT_FAILURE);
//    }

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
            // increase by 1:
            // ++array_cap;
            
            // or, double the size (more efficient):
            array_cap = (array_cap == 0) ? 1 : (array_cap * 2);
            // TODO: check array_cap * 2 doesn't overflow

            // array = realloc(array, sizeof(int) * array_cap);  // error
                                                                 // sometimes the compilation can pass OK, but
                                                                 // the programm can be crushed with (core dumped)!
            // array = realloc(array, sizeof(ull) * array_cap);

            array = realloc(array, (sizeof(array[0])) * array_cap);
            if (array == NULL) {
                fprintf(stderr, "could not allocate memory for the array");
                exit(EXIT_FAILURE);
            }

        }

        array[array_len - 1] = num;

       // if (array_cap < array_len)
       // {
       //     // increase by 1
       //     //++array_cap;

       //     // increase by 2: double the size (more efficient)
       //     array_cap = (array_cap == 0) ? 1 : 2;       // log increase
       //                                                 // help me to allocate with Log(n)
       //                                                 // the efficiency of growth is logarithmic
       //     // TODO: check array_cap * 2 doesn't overflow

       //     array = realloc(array, sizeof(int) * array_cap);
       //     if (array == NULL) {
       //         fprintf(stderr, "could not allocate memory for the array");
       //         exit(EXIT_FAILURE);
       //     }

       // }


    }

    for (size_t i=0; i<array_len; ++i) {
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
