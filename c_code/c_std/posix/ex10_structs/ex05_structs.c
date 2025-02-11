#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SLEN 35

// stringification
#define STR(X) #X
#define XSTR(X) STR(X)


typedef struct Book Book;

struct Book
{
  char title[MAX_SLEN + 1];     // 51 buffer
  char author[MAX_SLEN + 1];
  int pages;
  double price;
};

void Book_print(Book *book)
{
  printf(" title: \"%s\",\n author: \"%s\",\n pages: %d,\n price: %.2f\n",
      (*book).title,
      book->author,
      book->pages,
      book->price);
}


int main(void)
{
  Book book1 =
  {
    "title1",
    "author",
    100,
    25.50
  };

  Book book2 =
  {
    "long title 2",
    "very very long author name 2",
    555,
    67.29
  };
  Book_print(&book1);
  Book_print(&book2);
  puts("");

  // set book1's title to be the same as book2
  // book1.title <--- book2.title
  strcpy(book1.title, book2.title);
  //strncpy(book1.author, book2.author, MAX_SLEN);  //warning: initializer-string for array of chars is too long

  // set book2 title to "generic book title"
  Book_print(&book1);
  Book_print(&book2);
  puts("");




  return EXIT_SUCCESS;

}
