#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

//first reads and discards all whitspace,
//then reads a line from input and returns
//it as a dynamically allocated string.
//
//newline in the end is discarded and not added to the string
//
char *get_line(void);

//replaces all occurances of char_old with char_new inside str
void str_rep_char(char *str, char char_old, char char_new);

//takes str1, str2, returns a dynamically allocated string
//copies str1 and str2 into the return value in alternating fashion
//
//Example:
//if  str1 is: "ABCD"
//and str2 is: "1234567"
//then the return value is: "A1B2C3D4567"
//
char *str_new_zigzag(const char *str1, const char *str2);


#endif // STRING_FUNCTIONS_H
