/*

*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // 1
#include <stdint.h>
#include <inttypes.h>


int main(int argc, char **argv)
{

  //const char *const FILE_NAME = "data/numbers.txt";
  const char *const FILE_NAME = argv[1];

  FILE *file = fopen(FILE_NAME, "r");
  
  long sum = 0;
  long num;

  while(true)
  {
    fscanf(file, "%ld", &num);

    if (feof(file))
    {
      break;
    }

    sum += num;
  }

  printf("%ld\n", sum);


  fclose(file);

  return 0;
}
