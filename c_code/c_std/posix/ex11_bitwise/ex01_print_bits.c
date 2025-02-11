#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

//                                                      
//          MSB (Most Significant Bit)                  
//            |                                         
//            |             LSB (List Significant Bit)  
//            |             |                           
//            1 0 1 0 1 1 0 1                           
//                                                      
//                                                      
//                                                      
//                                                      
//                                                      
void print_bits_u32(uint32_t n, bool has_newline)
{
  uint32_t mask = (uint32_t)1 << 31;  // 0x80000000

  while (mask != 0)
  {
    if ((n & mask) != 0)
    {
      putchar('1');
    }
    else
    {
      putchar('0');
    }

    // putchar (n & mask != 0) ? '1' : '0';
    // putchar((n & mask) ? '1' : '0');

    mask = mask >> 1;
    // mask >>= 1;
  }


  if (has_newline)
  {
    puts("");
  }

}

int main(void)
{
  uint32_t n1 = 0x0A1B2C3D;

  print_bits_u32(n1, true);

  while (true) 
  {
    printf("enter a u32 number:");
    scanf("%" SCNu32, &n1);

    printf("the number in bits:\n");
    print_bits_u32(n1, true);

    puts("");
  }

  return 0;
}
