#include <stdio.h>

typedef struct T1
{
  char    c;       // 1B     cXXX
//  char  ch;      // 1B     cXXX
  short   h;       // 2B     hhXX
//  int   i;       // 4B     iiii
  double  d;       // 8B     dddd
} T1;              //        dddd

typedef struct T2
{
  char    c;       // 1B     cXXX
  short   h;       // 2B     hhXX
  double  d;       // 8B     dddd
} __attribute__((packed)) T2;              //        dddd

typedef struct T3
{
  double  d;       // 8B     dddd
  short   h;       // 2B     hhXX
  char    c;       // 1B     cXXX
} T3;              //        dddd

typedef long long signed int lld;

// _Alignas(double) char buffer[255] = {0};
// _Alignas(double) aligns the buffer's starting address to the alignment requirement of the 'double' type.
// This ensures that any 'double' stored within the buffer is properly aligned, 
// preventing undefined behavior on architectures requiring strict alignment.
// Without _Alignas, accessing or storing a 'double' in buffer can lead to crashes or performance penalties.

// Removing _Alignas(double) may cause unaligned access issues,
// leading to performance penalties or crashes on certain architectures.

// aligned the 'buffer' variable like double, this syntax allow us to aligned the size of double type.
// _Alignas(double) char buffer[255] = {0};

char buffer[255] = {0};


int main(void)
{
  // potentially unaligned access
  *(double *)(buffer + 100) = 12.5;

  // what is the size of T1
  printf("sizeof (T1) = %zuB\n", sizeof(T1));
  puts("");

  T1 t1 = {0};
  // NOTE: potentially non-standart offset computation
  printf("c offset of = %lld\n", (lld)&t1.c - (lld)&t1);
  printf("h offset of = %lld\n", (lld)&t1.h - (lld)&t1);
  printf("c offset of = %lld\n", (lld)&t1.d - (lld)&t1);
  puts("");

  // what is the size of T2
  printf("sizeof (T2) = %zuB\n", sizeof(T2));
  puts("");

  // what is the size of T3
  printf("sizeof (T3) = %zuB\n", sizeof(T3));
  puts("");

  return 0;
}
