#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

typedef uint32_t u32;
typedef int32_t i32;
typedef uint8_t u8;


u32 u32_to_be(u32 n) {
    u8 data[sizeof n] = {
        (u8)(n >> 24), 
        (u8)(n >> 16), 
        (u8)(n >> 8), 
        (u8)(n >> 0)
    };
    
    memcpy(&n, data, sizeof n);
    return n;
}

//assuming n contains data as big-endian
u32 u32_from_be(u32 n) {
    u8 data[sizeof n];
    memcpy(data, &n, sizeof n);

    return (u32)data[0] << 24
      | (u32)data[1] << 16  
      | (u32)data[2] <<  8  
      | (u32)data[3] <<  0;
}

i32 i32_to_be(i32 n) {
    u32 temp;
    memcpy(&temp, &n, sizeof n);

    temp = u32_to_be(temp);

    memcpy(&n, &temp, sizeof n);

    return n;
}

i32 i32_from_be(i32 n) {
    u32 temp;
    memcpy(&temp, &n, sizeof n);
    
    temp = u32_from_be(temp);

    memcpy(&n, &temp, sizeof n);

    return n;
}


int main(void) {
    /* enter code here */
    return 0;
}