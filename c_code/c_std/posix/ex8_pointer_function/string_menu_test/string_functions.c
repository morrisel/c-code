#include "string_functions.h"
#include <string.h>


char *get_line(void)
{
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  // Clear the input buffer before reading the line
  int c;
  while ((c = getchar()) != '\n' && c != EOF);

  // Read the line
  read = getline(&line, &len, stdin);
  if (read == -1) {
    free(line);
    return NULL;
  }

  // Remove the newline character '\n' if it exists
  if (read > 0 && line[read - 1] == '\n') {
    line[read - 1] = '\0';
  }

  puts("");
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

char *str_new_zigzag(const char *str1, const char *str2)
{
  size_t len1 = strlen(str1);
  size_t len2 = strlen(str2);
  size_t max_len = len1 > len2 ? len1 : len2;
  char *result = malloc((max_len * 2 + 1) * sizeof(char));  // +1 for null terminator
  size_t j = 0;

  for (size_t i = 0; i < max_len; i++) {
    if (i < len1) {
      result[j++] = str1[i];
    }
    if (i < len2) {
      result[j++] = str2[i];
    }
  }
  result[j] = '\0';  // Null terminate the string
  return result;
}
