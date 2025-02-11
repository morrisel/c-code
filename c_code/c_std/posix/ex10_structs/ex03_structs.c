#include <stdio.h>
#include <stdlib.h>


#define MAX_SLEN 20


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

  // input:
  printf("enter title: ");
  scanf(" %20[^\n]", book1.title);    
  getchar();

  printf("enter title: ");
  scanf(" %20[^\n]", book1.author);    
  getchar();

  
  printf("enter pages: ");
  scanf("%d", &pages);
  book1.pages = pages;

  printf("enter price: ");
  //scanf("%lf", &price);
  //book1.price = price;
  scanf("%lf", &book1.price);


  Book_print(&book1);
  puts("");




  return EXIT_SUCCESS;

}
