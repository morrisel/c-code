#include <stdio.h>
#include <stdlib.h>



#define MAX_SLEN 50


typedef struct Book Book;

struct Book
{
  char title[MAX_SLEN + 1];
  char author[MAX_SLEN + 1];
  int pages;
  double price;
};




void Book_print(Book *book)
{
  printf("title: \"%s\", author: \"%s\", pages: %d, price: %.2f",
      (*book).title,
      book->author,
      book->pages,
      book->price);
}


int main(void)
{
  Book book1 = 
  {
    "The C Programming Language",
    "Dennis Ritchie",
    288,
    45.10
  };


  // C99
  Book book2 = 
  {
    .author = "Dennis Ritchie",
    .pages = 288,
    .title = "The C Programming Language",
    .price = 45.10
  };


  Book_print(&book1);
  puts("");
  Book_print(&book2);
  puts("");

  return EXIT_SUCCESS;

}
