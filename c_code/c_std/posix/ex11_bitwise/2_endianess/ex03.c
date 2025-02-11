#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

// 0x0A0B0C0D
//   FF000000
// MSB: 0A
// LSB: 0D

// 0x0A0B0C0D >> 24
// 0x0000000A

uint32_t u32_to_be(uint32_t n) {
    unsigned char data[4];

    data[0] = n >> 24;
    data[1] = n >> 16;
    data[2] = n >>  8;
    data[3] = n >>  0; //same as without shift

    memcpy(&n, data, 4);

    return n;
}

uint32_t u32_to_le(uint32_t n) {
    unsigned char data[4];

    data[3] = n >> 24;
    data[2] = n >> 16;
    data[1] = n >>  8;
    data[0] = n >>  0; //same as without shift

    memcpy(&n, data, 4);

    return n;
}

uint32_t u32_from_be(uint32_t n) {
    unsigned char data[4];

    memcpy(data, &n, 4);

    // data[0] MSB
    // data[3] LSB

    //  0    1   2   3
    //[ 1A, 2B, 3C, 4D ]

    // 1A000000
    // 002B0000   
    // 0000002B
    // 00003C00
    // 0000004D

    n  = (uint32_t)data[0] << 24;
    n |= (uint32_t)data[1] << 16;
    n |= (uint32_t)data[2] <<  8;
    n |= (uint32_t)data[3] <<  0;

    // n  = (uint32_t)data[0] << 24
    //    | (uint32_t)data[1] << 16
    //    | (uint32_t)data[2] <<  8
    //    | (uint32_t)data[3] <<  0;
}

// n = ???; 0x3D2C1B1A; [ 1A, 1B, 2C, 3D]


int main(void) {
    /* enter code here */
    return 0;
}