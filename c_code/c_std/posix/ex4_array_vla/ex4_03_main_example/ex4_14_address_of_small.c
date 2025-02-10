/* gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_14_address_of_small.c */
/* gcc ex4_14_address_of_small.o -o program -lm */
#include <stdio.h>


int address_of_smallest(int *a, int *b, int **psmallest);

int main(int argc, char const *argv[])
{
    int num1, num2, *pnum;

    printf("enter two ints:");
    scanf("%d %d", &num1, &num2);

    address_of_smallest(&num1, &num2, &pnum);

    return 0;
}

int address_of_smallest(int *a, int *b, int **psmallest)
{
    if (*a < *b)
    {
        *psmallest = a;
    }
    else
    {
        *psmallest = b;
    }
}

