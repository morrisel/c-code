#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void my_assert(bool condition, const char *err_msg)
{
    if (!condition)
    {
        printf("%s\n", err_msg);
        exit(EXIT_FAILURE);
    }
}

char*
my_getline(void)
{
    // the string that will be returned
    char *str = malloc(sizeof(char));
    // TODO: check malloc fail
    my_assert(str != NULL, "my_getline: malloc failed");
    size_t str_size = 1;
    str[0] = '\0';                   // <-- same *str = '\0';
    int c;

    c = getchar();
    while(c != EOF && c != '\n')
    {
        ++str_size;
        str= realloc(str, str_size);
        // TODO: check realloc fail
        my_assert(str != NULL, "my_getline: realloc failed");
        str[str_size-2] = (char)c;
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

