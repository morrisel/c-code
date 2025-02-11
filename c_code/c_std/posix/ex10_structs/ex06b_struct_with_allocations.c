#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Book Book;
struct Book
{
  char *title;     // 51 buffer
  char *author;
  int pages;
  double price;
};

void Book_print(Book *book)
{
  printf(" title: \"%s\",\n author: \"%s\",\n pages: %d,\n price: %.2f\n\n",
      //(*book).title,
      book->title,
      book->author,
      book->pages,
      book->price);
}


int main(void)
{
  // Book 1 -----
  Book book1 = {NULL, "", 100, 25.76};
  const char *to_copy = "some title1 abc";
  book1.title = malloc(strlen(to_copy)+1);
  Book_print(&book1);

  strcpy(book1.title, to_copy);
  Book_print(&book1);

  book1.author = malloc(strlen("author1") + 1);
  strcpy(book1.author, "author1");
  Book_print(&book1);

  // Book 2 -----
  Book book2 = {NULL, NULL, 222, 10.2};               // stage1: creation + declaration
  const char *s1 = "long title 2 - this title 2 is very very long";
  const char *s2 = "very very long authour name 2";
  Book_print(&book2);

  book2.title  = malloc(strlen(s1) + 1);              // stage2: initialization
  book2.author = malloc(strlen(s2) + 1);
  Book_print(&book2);

  strcpy(book2.title, s1);                     // stage3: assign
  strcpy(book2.author, s2);
  Book_print(&book2);

  // copy title of book2 [big-size], to book1 [small-size]. we need to use with the
  //book1.title = realloc(book1.title , strlen(s2) + 1);
  book1.title = realloc(book1.title , strlen(book2.title) + 1);
  strcpy(book1.title, book2.title);
  puts("------------------------");
  Book_print(&book1);

  
  // free book1's memory allocations
  free(book1.title);
  book1.title  = NULL;
  free(book1.author);
  book1.author = NULL;

  // free book2's memory allocations
  free(book2.title);
  book2.title  = NULL;
  free(book2.author);
  book2.author = NULL;

  // free book2's memory allocations

  // a_1, a_2 ...    ... a_i-1 ,a_i, | a_i+1, .... --->          <--- ... a_j-1, a_j, a_j+1, ...    ... a_n-1, a_n
  //
  // ************ ********** ******** ****** **** **

  puts("");

  return EXIT_SUCCESS;

}
