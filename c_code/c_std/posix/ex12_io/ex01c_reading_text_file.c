/*

*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // 1
#include <stdint.h>
#include <inttypes.h>


int main(void)
{
  char file_name[255] = "";

  printf("enter file name to read from:#_");
  scanf("%254s", file_name);

  const char *const FILE_NAME = file_name;

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
