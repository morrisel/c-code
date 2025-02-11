#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>


// https://www.wikipedia.org/wiki/Endianness
// https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html
//

int main(void)
{ //                                                         *p=1234   -->    *p++  
  //             LSB      MSB                                                
  //              |        |                                 *p=1235                 
  //          0x 01 02 03 04                                                       
  //                                  memory                  CPU register
  //         BE  ---------->          01 02 03 04                             *p++     
  //                                                             01     04          05   
  //         LE  <----------          04 03 02 01                02     03          03   
  //                                                             03     02          02   
  //                                                             04     01          01   
  //                                                                   
  uint32_t num = 0x01020304;

  char *p = (char *)&num;

  printf("%d\n", p[0]);
  printf("%d\n", p[1]);
  printf("%d\n", p[2]);
  printf("%d\n", p[3]);

  return 0;
}
