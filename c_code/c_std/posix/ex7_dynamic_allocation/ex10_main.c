#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i<argc; ++i)
    {
        printf("%d) %s\n", i, argv[i]);
    }
    puts("");


    for (char **p = argv; *p != NULL; ++p)
    {
        printf("%s\n", *p);
    }
    puts("");







    return 0;
}
