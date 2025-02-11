// check in runtime if our computer is Big/LIttle Endian

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>


// https://commandcenter.blogspot.com/2012/04/byte-order-fallacy.html


// -----   N E T W O R K I N G   --------------------------------------------------------- 
//      
//      
//      
//     host       -->     our computer Endianness (usually Little Endian)
//     ^ 
//      
//     network    -->     Big Endian (Always!) 
//     ^ 
//      
//     short      -->     [s] - 16 bit
//     ^ 
//      
//     long       -->     [l] - 32 bit
//     ^ 
//      
//      
//     htons      -->     host-to-network-short         (16-bit)   --->   (16-bit) 
//                                                        host              B.E.   
//                                                                                 
//     ntohs      -->     network-to-host-short         (16-bit)   --->   (16-bit) 
//                                                         B.E.             host   
//                                                                                 
//                                                                                 
//                                                                                 
//     htonl      -->     host-to-network-long          (32-bit)   --->   (32-bit) 
//                                                        host              B.E.   
//                                                                                 
//     ntohl      -->     network-to-host-long          (32-bit)   --->   (32-bit) 
//                                                        B.E.              host   
//      







int main(void) {
    int n = 1; // -> 0x 00 00 00 01
    char *p = (char*)&n;

    // Little Endian : 0x 00 00 00 01
    //                             ^p
    //    Big Endian : 0x 00 00 00 01
    //                    ^p


    if (*p != 0) {
        puts("this machine is in Little Endian");
    }
    else {
        puts("this machines is in Big Endian");
    }

    return 0;
}

// 0x01020304
//
// 01 02 03 04
// 04 03 02 01
//
    
