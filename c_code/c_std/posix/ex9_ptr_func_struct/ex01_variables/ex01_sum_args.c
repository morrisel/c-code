/*
This program that reads arguments as integers
and prints the sum

Example:
    program 100 20 3

output:
    123

Memory:
argv:
    0          1      2     3   '\0'    (<-- index)
["./program", "100", "20", "3", NULL]

argc: 0
                    argc=4
program 100 20  3

*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ull;


int main(int argc, char *argv[])
{
    ull sum = 0;    // the resulting sum to return in the end
    ull num;        // for sscanf input
    int result;     // for sscanf result 

    for (int i=1; i<argc; ++i)
    {
        // parse the string into an integer (unsigned long long)
        result = sscanf(argv[i], "%llu", &num);

        if (result != 1)
        {
            //printf("ignoring %s (not an int)\n", argv[i]);
            fprintf(stderr, "ignoring \"%s\" (not an int)\n", argv[i]);
            continue;
        }

        sum += num;
    }

    printf("%llu\n", sum);

    puts("Hello");
    return 0;
}
