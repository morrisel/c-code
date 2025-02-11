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
    uint8_t mask = (uint8_t)1 << 7;
    int ones_count = 0;

    while (mask != 0x01) {
        if ((n & mask) != 0){
            ones_count++;
        }

        mask >>= 1;
    }

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