#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

typedef 
union Date { 
    int simple_date;
    double exact_date;
} Date;

typedef enum DateType {
    DATE_TYPE_SIMPLE, DATE_TYPE_EXACT
} DateType;

typedef struct Person {
    int id;
    DateType dtype;
    Date date;
} Person;

int main(void) {
    Person p1 = { 
        123,
        DATE_TYPE_SIMPLE,
        100
    };

    Person p2 = { 
        123,
        DATE_TYPE_EXACT,
        12.5
    };


    return 0;
}