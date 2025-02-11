// this program reads a binary 32 bit number
// and print how many "ones" are in that number

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "shared/bitwise_utils.h"

int count_ones_u32_v1(uint32_t n);
int count_ones_u32_v2(uint32_t n);
int count_ones_u32_v3(uint32_t n);
int count_ones_u32_v4(uint32_t n);

int main(void) {
    char buff[33] = "";
    int result;
    uint32_t num;

    while (true) {
        printf("enter binary 32-bit: ");
        result = scanf(" %32[01]", buff);
        printf("scanf result: %d\n", result);
        
        if (result == EOF) { break; } 

        if (result == 0) {
            puts("Error: Bad input.");
            scanf("%*[^\n]");
            continue;
        }

        num = u32_from_string(buff);
        printf("%" PRIu32 "\n", num);
        print_bits_u32(num, true);
        
        //TESTING OUR FUNCTION
        printf("this number has %d ones set.\n",
            count_ones_u32_v4(num));
        
        scanf("%*[^\n]");
    }

    return 0;
}

int count_ones_u32_v1(uint32_t n) {
    uint32_t mask = (uint32_t)1 << 31;
    int ones_count = 0;

    while (mask != 0) {
        if ((n & mask) != 0) {
            ones_count++;
        }
        
        //or:
        // ones_count += (n & mask != 0);

        mask >>= 1;
    }

    return ones_count;
}

int count_ones_u32_v2(uint32_t n) {
    uint32_t mask = 0x00000001;
    //uint32_t mask = 1;

    int ones_count = 0;

    while (mask != 0) {
        if ((n & mask) != 0) {
            ones_count++;
        }
        
        //or:
        // ones_count += (n & mask != 0);

        mask <<= 1;
    }

    return ones_count;
}

int count_ones_u32_v3(uint32_t n) {
    int ones_count = 0;

    while (n != 0) {

        if ((n & 0x1) != 0) {
            ones_count++;
        }
        
        n >>= 1;
    }

    return ones_count;
}

int count_ones_u32_v4(uint32_t n) {
    int ones_count = 0;

    while (n != 0) {
        ones_count++;
        
        //clear the rightmost "1" bit set
        //          LSb
        n = n & (n-1);
        // n &= n-1;
    }

    return ones_count;
}

// num: 00010010101001010101001101010101
// msk: 10000000000000000000000000000000
//
// num: 00010010101001010101001101010101
// msk: 01000000000000000000000000000000
// 
// ...
//
// num: 00010010101001010101001101010101
// msk: 00000000000000000000000000000001
//
// (mask is zero, break)
// num: 00010010101001010101001101010101
// msk: 00000000000000000000000000000000


// num: 00010010101001010101001101010101
// msk: 00000000000000000000000000000001
//
// num: 00001001010100101010100110101010
// msk: 00000000000000000000000000000001
//
// num: 00000100101010010101010011010101
// msk: 00000000000000000000000000000001
//
// num: 00000010010101001010101001101010
// msk: 00000000000000000000000000000001
//
// ...
//
// num: 000      ...          0000001001
// msk: 00000000000000000000000000000001
// 
// num: 000      ...           000000100
// msk: 00000000000000000000000000000001
//
// num: 000      ...            00000010
// msk: 00000000000000000000000000000001
//
// num: 000      ...             0000001
// msk: 00000000000000000000000000000001
//
// (num is zero, break)
// num: 000      ...              000000
// msk: 00000000000000000000000000000001


