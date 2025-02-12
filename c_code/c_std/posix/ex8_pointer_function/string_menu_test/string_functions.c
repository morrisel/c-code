#include "string_functions.h"


char *get_line(void)
{
  char *line = NULL;
  size_t len = 0;

  getline(&line, &len, stdin);

  // Remove trailing newline character if exists
  size_t length = strlen(line);
  if (line[length - 1] == '\n')
  {
    line[length - 1] = '\0';
  }
  return line;
}

void str_rep_char(char *str, char char_old, char char_new)
{
  for (size_t i = 0; str[i] != '\0'; i++) {
    if (str[i] == char_old) {
      str[i] = char_new;
    }
  }
}

//char *str_new_zigzag(const char *str1, const char *str2)
//{
//  return;
//}
