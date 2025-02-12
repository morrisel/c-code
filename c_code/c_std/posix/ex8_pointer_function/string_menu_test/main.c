#include <stdio.h>
#include "string_vector.h"
#include "string_functions.h"

//TODO: ADD a typedef to StringVectorAction here
typedef void (*StringVectorAction)(StringVector *sv);


typedef struct MenuItem 
{
  const char *description;
  StringVectorAction action;
} MenuItem;



//String Vector Actions

//reads line from user and adds as a new string at end of vector
void action_add_string(StringVector *sv);

//reads index from user and deletes that string from the vector
void action_del_string(StringVector *sv);

//reads from input: index, and two characters
//inside string at index replaces all instances of the first character
//with the second character
void action_rep_char(StringVector *sv);

//reads from input: two characters
//replaces all instances of the first character
//found in any string in sv with the second character.
void action_rep_char_all(StringVector *sv);

//reads from input: two indexes
//adds a new string to sv that is a zigzag copy
//of the two string in the indexes
//(see helper.h:str_new_zigzag)
void action_zigzag_copy(StringVector *sv);

int main(void)
{
  //TODO: initialize a string vector
  StringVector sv;
  sv_init(sv);

  //TODO: initialize the menu array
  MenuItem menu[] = {
    {"add string", action_add_string},
    {"delete string", action_del_string},
    {"replace character", action_rep_char},
    {"replace character from all", action_rep_char_all},
    {"zigzag copy", action_zigzag_copy},
    {"quit", NULL}
  }; 

  //TODO: menu loop
  int option;
  do
  {
    // print the strings in the vector
    for (size_t i = 0; i < sv.length; i++)
      printf("%zu) %s\n", i, sv.arr[i]);

    // print the menu option
    for (size_t i = 0; i < sizeof(menu) / sizeof(menu[0]) - 1; i++)
      printf("%zu) %s\n", i+1, menu[i].description);
    printf("0) Quit\n");

    // get the user input for option
    printf("select option: ");
    scanf("%d", &option);

    // perform the action based on the selected option
    if(option > 0 && option <= 5)
      menu[option - 1].action(&sv);

  }
  while(option != 0);

  //TODO: make sure to free any dynamically allocated memory
  // free allocated memory before quitting
  sv_clear(&sv);
}


//TODO: complete the action_* functions below
void action_add_string(StringVector *sv)
{
  char *new_str = get_line();
  sv_add_last(sv, new_str);
}

void action_del_string(StringVector *sv)
{
  size_t index;
  printf("enter index to delete: ");
  scanf("%zu", &index);
  sv_remove_at(sv, index);
}

void action_rep_char(StringVector *sv)
{
  size_t index;
  char old_char, new_char;
  printf("enter index: ");
  scanf("%zu", &index);
  printf("enter character to replace: ");
  scanf(" %c", &old_char);
  printf("enter new character: ");
  scanf(" %c", &new_char);
  str_rep_char(sv->arr[index], old_char, new_char);
}

void action_rep_char_all(StringVector *sv)
{
  char old_char, new_char;
  printf("enter character to replace: ");
  scanf(" %c", &old_char);
  printf("enter new character: ");
  scanf(" %c", &new_char);

  for (size_t i=0; i<sv.length; i++)
    str_rep_char(sv->arr[i], old_char, new_char);
}


void action_zigzag_copy(StringVector *sv)
{
  size_t index1, index2;
    printf("Enter first index: ");
    scanf("%zu", &index1);
    printf("Enter second index: ");
    scanf("%zu", &index2);
    char *zigzag_str = str_new_zigzag(sv->arr[index1], sv->arr[index2]);
    sv_add_last(sv, zigzag_str);

}



