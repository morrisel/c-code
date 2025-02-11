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
  // variable to fill with input
  Book book1;

  // variable to help read input
  int pages;
  double price;

  // input:
  //
  printf("enter title: ");
  //scanf("%s", book1.title);
  scanf("%[^\n]", book1.title);     // gets all characters up-to '\n'
  getchar();

  printf("enter title: ");
  scanf("%[^\n]", book1.author);     // gets all characters up-to '\n'


  
  printf("enter pages: ");
  scanf("%d", &pages);
  book1.pages = pages;

  printf("enter price: ");
  scanf("%lf", &price);
  book1.price = price;


  Book_print(&book1);
  puts("");




  return EXIT_SUCCESS;

}
