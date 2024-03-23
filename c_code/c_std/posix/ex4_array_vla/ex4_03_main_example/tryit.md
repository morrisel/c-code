$ gcc -std=c99 -c -g -O0 -pedantic -Wall -Wextra -Wshadow ex4_11_declarations.c
-------------------------------------------------------------------------------
ex4_11_declarations.c: In function ‘main’:
ex4_11_declarations.c:33:10: warning: assignment to ‘int’ from ‘int *’ makes integer from pointer without a cast [-Wint-conversion]
   33 |  *arr[0] = &b;
      |          ^
ex4_11_declarations.c:33:6: warning: ‘arr[0]’ is used uninitialized in this function [-Wuninitialized]
   33 |  *arr[0] = &b;
      |   ~~~^~~

