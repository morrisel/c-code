#include <stdio.h>
#include <stdlib.h>


#define MAX_SLEN 20

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
  // variable to fill with input
  Book book1;

  // variable to help read input
  int pages;

  // input:
  printf("enter title: ");
  //scanf(" %20[^\n]", book1.title);    
  scanf(" %" XSTR(MAX_SLEN) "20[^\n]", book1.title);    

  printf("enter title: ");
  //scanf(" %20[^\n]", book1.author);    
  scanf(" %" XSTR(MAX_SLEN) "20[^\n]", book1.author);    
  
  printf("enter pages: ");
  scanf("%d", &pages);
  book1.pages = pages;

  printf("enter price: ");
  scanf("%lf", &book1.price);


  Book_print(&book1);
  puts("");




  return EXIT_SUCCESS;

}
