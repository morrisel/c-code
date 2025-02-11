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
  const char *s1 = "long title 2";
  const char *s2 = "very very long authour name 2";

  Book_print(&book2);

  book2.title  = malloc(strlen(s1) + 1);              // stage2: initialization
  book2.author = malloc(strlen(s2) + 1);
  
  Book_print(&book2);

  strcpy(book2.title, s1);                     // stage3: assign
  strcpy(book2.author, s2);

  Book_print(&book2);

  puts("");

  return EXIT_SUCCESS;

}
