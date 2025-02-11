#include "bitwise_utils.h"

#include <stdio.h>
#include <limits.h>  //CHAR_BIT

void print_bits_u32(uint32_t n, bool has_newline) {
    uint64_t mask = (uint32_t)1 << 31;
    //uint64_t mask = (uint32_t)1 << ((sizeof mask) * CHAR_BIT - 1);

    while (mask != 0) {
        if ((n & mask) != 0) {
            putchar('1');
        }
        else {
            putchar('0');
        }
        mask >>= 1;
    }


    if (has_newline) {
        puts("");
    }
}

void print_bits_u8(uint8_t n, bool has_newline) {
    //uint8_t mask = 1 << 7;
    uint8_t mask = 1 << ((sizeof mask) * CHAR_BIT - 1);
    
    while (mask != 0) {
        if ((n & mask) != 0) {
            putchar('1');
        }
        else {
            putchar('0');
        }
        mask >>= 1;
    }


    if (has_newline) {
        puts("");
    }
}


// "00101001" --> 41 (?)
uint8_t u8_from_string(const char *s) {
    uint8_t num = 0x00;

    for (
        uint8_t mask = 1 << 7;
        mask != 0 && *s != '\0';
        mask >>= 1, s++
    ) {
        if (*s == '1') {
            num |= mask;
        }
    }

    return num;
}

uint32_t u32_from_string(const char *s) {
    uint32_t num = 0x00;

    for (
        uint32_t mask = 1 << 31;
        mask != 0 && *s != '\0';
        mask >>= 1, s++
    ) {
        if (*s == '1') {
            num |= mask;
        }
    }

    return num;
}