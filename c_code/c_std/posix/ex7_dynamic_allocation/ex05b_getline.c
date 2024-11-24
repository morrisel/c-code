#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


char*
my_getline(void)
{
    // the string that will be returned
    char *str = malloc(sizeof(char));
    // TODO: check malloc fail
    size_t str_size = 1;
    str[0] = '\0';                   // <-- same *str = '\0';
    int c;

    c = getchar();
    while(c != EOF && c != '\n')
    {
        ++str_size;
        str= realloc(str, str_size);
        // TODO: check realloc fail
        str[str_size-2] = c;
        c = getchar();
    }

    str[str_size-1] = '\0';
    return str;
}


int main(void)
{

    printf("enter your name: ");
    char *name = my_getline();

    printf("Hello %s!\n", name);

    free(name);
    name = NULL;

    return 0;
}

