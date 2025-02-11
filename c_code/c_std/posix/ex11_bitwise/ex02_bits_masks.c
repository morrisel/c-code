#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>


typedef uint8_t u8;

// 75643210
// AABBBBCD
//
// A  0-3   [7:6] 1100 0000
#define OFFS_A 6
#define MASK_A 0xC0

// B  0-15  [5:2] 0011 1100
#define OFFS_B 2
#define MASK_B 0x3C

// C  0/1   [1]   0000 0010
#define OFFS_C 1
#define MASK_C 0x2

// D  0/1   [1]   0000 0001
#define OFFS_D 0
#define MASK_D 0x1

void print_bits_u32(uint32_t n, bool has_newline);
void print_bits_u8(u8 n);

// reg = the current registry value (copy)
// val = the value to write to the register-value
// (wirtten to section A as specified above)
//
u8 write_a(u8 reg, u8 val)
{
  reg &= ~MASK_A;
  reg |= val << OFFS_A;
  return reg;
}

u8 write_b(u8 reg, u8 val)
{
  reg &= ~MASK_B;         // ~00111100 -> 11000011
  reg |= val << OFFS_B;   // (if val=5 -> 101) val=5 -> 101) val<<2 -> 10100
  // reg = (reg & ~MASK_B) | (val << OFFS_B)
  return reg;
}

//   abcdefgh
// & 11000011                   CLEAR
//   --------
//   ab0000gh
//
// val = 5
//   00000101
// val << 2                     (offset the value)
//   00010100
// 
//   ab0000gh
//   00010100     (val << 2)    SET
//   --------
//   ab0101gh

//  X | (Y << Z)
//  2       1
//
//  X |= Z << Y     -->  X = (X) | (Z << Y)
//


u8 write_c(u8 reg, u8 val)
{
  reg &= ~MASK_C;
  reg |= val << OFFS_C;
  return reg;
}

u8 write_d(u8 reg, u8 val)
{
  reg &= ~MASK_D;
  reg |= val << OFFS_D;
  return reg;
}

u8 read_b(u8 reg)
{
  // MASK_B OFFS_B
  
  //return (reg << 2) >> 4;
  //u8 temp = (reg & ~MASK_B);

  //print_bits_u8(reg);
  //u8 temp = (reg & MASK_B);
  //print_bits_u8(temp);
  //temp >>= OFFS_B;
  //print_bits_u8(temp);
  //return temp;

  return (reg & MASK_B) >> OFFS_B;
}

void print_bits_u8(u8 n) {
  for (u8 mask = 1<<7; mask != 0; mask >>= 1) {
    putchar((n & mask) ? '1' : '0');
  }

  puts("");
}

int main(void)
{
  u8 x = 0xFA;
  u8 val;

  // read value from user for A
  printf("enter value for section A (0-3):");
  scanf("%" SCNu8, &val);
  x = write_a(x, val);

  // read value from user for B
  printf("enter value for section B (0-15):");
  scanf("%" SCNu8, &val);
  x = write_b(x, val);

  // read value from user for C
  printf("enter value for section C (0/1):");
  scanf("%" SCNu8, &val);
  x = write_c(x, val);

  // read value from user for D
  printf("enter value for section D (0/1):");
  scanf("%" SCNu8, &val);
  x = write_d(x, val);

  printf("final result in bits:\n");
  print_bits_u8(x);

  printf("the value in section B is: %d", read_b(x));

  puts("");

  return 0;
}


//int main(void)
//{
//  uint32_t n1 = 0x0A1B2C3D;
//
//  print_bits_u32(n1, true);
//
//  while (true) 
//  {
//    printf("enter a u32 number:");
//    scanf("%" SCNu32, &n1);
//
//    printf("the number in bits:\n");
//    print_bits_u32(n1, true);
//
//    puts("");
//  }
//
//  return 0;
//}


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
