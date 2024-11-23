#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int *p = malloc(sizeof (int));
    if (p == NULL)
    {
        puts("Error: out of memory.");
        //return 1;
        //return EXIT_FAILURE;
        exit(EXIT_FAILURE);     // stdlib.h
    }

    *p = 1200;

    //p = malloc(sizeof (int) * 4); // memory leak!
    
    //instead free before you re-allocate
    //free(p);
    //p = malloc(sizeof (int) * 4);


    return 0;
}
