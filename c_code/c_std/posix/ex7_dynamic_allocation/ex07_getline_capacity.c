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

char* my_getline(void)
{
    // the string that will be returned
    char *str = malloc(sizeof(char));
    my_assert(str != NULL, "my_getline: malloc failed");

    size_t str_size = 1;            // how much is used
    size_t str_capacity = 1;        // how much is allocated

    int c;

    while((c = getchar()) != EOF && c != '\n')
    {
        ++str_size;

        if (str_size > str_capacity)
        {
            str_capacity *= 2;
            str = realloc(str, str_size);
            my_assert(str != NULL, "my_getline: realloc failed");
        }

        str[str_size-2] = (char)c;
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


