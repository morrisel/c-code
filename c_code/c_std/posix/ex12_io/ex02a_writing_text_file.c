#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#include <assert.h>




void my_assert(bool condition, const char *error_message)
{
  if(!condition)
  {
    fprintf(stderr, "%s\n", error_message);
    exit(EXIT_FAILURE);
  }
}


int main(void)
{
  int numbers[] =
  {
    1000,
    200,
    30,
    5
  };


  FILE *f = fopen("data/numbers2.txt", "w");
  my_assert(f != NULL, "could not open the file.");


  return 0;
}
