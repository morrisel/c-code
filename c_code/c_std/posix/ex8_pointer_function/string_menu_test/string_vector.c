#include "string_vector.h"
#include "stdlib.h"
#include "string.h"

//initialize sv (array NULL length 0)
void sv_init(StringVector *sv)
{
  sv->arr = NULL;
  sv->length = 0;
}

//deallocates and clears sv as though it was initialized (array NULL length 0)
void sv_clear(StringVector *sv)
{
  for (size_t i = 0; i < sv->length; i++)
    free(sv->arr[i]); // free all line

  free(sv->arr);  // free array of pointers
  sv->arr=NULL;
  sv->length = 0;
}

//adds str as last cell of sv.
//assumes str is a dynamically allocated C-String.
void sv_add_last(StringVector *sv, char *str)
{
  sv->arr = realloc(sv->arr, (sv->length + 1) * sizeof(char*));
  if (!sv->arr) return; // handle realloc failure

  sv->arr[sv->length] = str; // str would be dynamically choosen
  sv->length++;
  
}

//remove string at index. does not shrink allocation size
void sv_remove_at(StringVector *sv, size_t index)
{
  if (index >= sv->length) return ;

  free(sv->arr[index]); // delete a string

  for (size_t i=index; i < sv->length-1; i++)
    sv->arr[i] = sv->arr[i+1];

  sv->length--;
  sv->arr = realloc(sv->arr, sv->length * sizeof(char *)); // Shrink memory
}
