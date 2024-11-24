#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void simple_reallocate(void);
void advanced_reallocate(void);



int main(void)
{

    /* enter code here */

    return 0;
}


void simple_reallocate(void)
{
    int *p = malloc(sizeof (int)*10);

    p = realloc(p, sizeof (int)*200);
    // p is potentially leaked here

    if (p == NULL)
    {
        puts("could not resize to 200");
        exit(EXIT_FAILURE);
    }

}


void advanced_reallocate(void)
{
    int *p = malloc(sizeof (int)*10);

    int *temp = realloc(p, sizeof(int)*20);
    // p is not leaked

    if (p == NULL)
    {
        // we can still access p here
        //      maybe for backup
        //      or maybe in order to free p ourselves
        puts("could not resize to 20");         // we don't have to exit
        exit(EXIT_FAILURE);
    }
    else
    {
        p = temp;
    }

}
