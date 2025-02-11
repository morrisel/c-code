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
