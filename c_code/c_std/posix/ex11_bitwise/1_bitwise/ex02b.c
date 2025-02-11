// this program read an 8-bit number
// and returns if it's "valid"
//
// a number is valid if bit [0] is 1
// when bits [7:1] contain an even number of "ones"
//
// or it's valid if bit [0] is 0
// when bits [7:1] contain an odd number of "ones"
//
// otherwise the number is invalid

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "shared/bitwise_utils.h"

int NIBBLE_COUNT[] = {
     0, //0000
     1, //0001
     1, //0010
     2, //0011
     1, //0100
     2, //0101
     2, //0110
     3, //0111
     1, //1000
     2, //1001
     2, //1010
     3, //1011
     2, //1100
     3, //1101
     3, //1110
     4  //1111
};

bool validate_parity_u8(uint8_t n);

int main(void) {
    char buff[9] = "";
    uint8_t num;

    while (true) {
        printf("enter 8-bit num: ");
        scanf(" %8[01]", buff);

        num = u8_from_string(buff);
        if (validate_parity_u8(num)) {
            puts("VALID");
        }
        else {
            puts("INVALID");
        }
    }
    
    return 0;
}

bool validate_parity_u8(uint8_t n) {
    int ones_count = NIBBLE_COUNT[n & 0x0E]; //00001110
    ones_count += NIBBLE_COUNT[n>>4 & 0x0F]; //00001111

    //LSb is one
    if ((n & 0x01) != 0) {
        return ones_count % 2 == 0;
    }
    //LSb is zero
    else {
        return ones_count % 2 != 0;
    }

    //or:
    // return (ones_count % 2) != (n & 0x01)
}