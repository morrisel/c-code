#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Book Book;
struct Book
{
  char   *title;     // 51 buffer
  char   *author;
  int    pages;
  double price;
};

void Book_init( Book *p_book,  const char *title,  const char *author,  int pages,  double price);
void Book_clear(Book *p_book);
void Book_set_title(Book *p_book,  const char *new_title);
void Book_print(Book *book);

// free the address allocation pointed by 'pdest'
// make an allocated copy of 'src' and store in pointer pointed by 'pdest'
void set_string(char **pdest, const char *src);

int main(void)
{
  Book book1, book2;
  Book_init(&book1, "some title1 abcd", "author1", 100, 25.50);
  
  Book_init( &book2,
             "long very long title of book2",
             "very very long author name 2",
             222,
             10.2);
  Book_print(&book1);
  Book_print(&book2);

  // set book1's title to be the same as book2
  // Book_set_title(&book1,         book2.title);
  set_string(       &book1.title ,  book2.title );
  set_string(       &book1.author,  "anonymous")  ; 

  Book_print(&book1);
  Book_print(&book2);
  
  Book_set_title(&book1, "ABCDEFG");
  Book_print(&book1);
  Book_print(&book2);

  // free books memory allocations
  Book_clear(&book1);
  Book_clear(&book2);

  puts("");

  return EXIT_SUCCESS;

}



void Book_print(Book *book)
{
  printf(" title: \"%s\",\n author: \"%s\",\n pages: %d,\n price: %.2f\n\n",
      //(*book).title,
      book->title,
      book->author,
      book->pages,
      book->price);
}

void Book_init( Book          *p_book,
                const char    *title,
                const char    *author,
                int           pages,
                double        price)
{
  p_book->pages  = pages;
  p_book->price  = price;

  p_book->title  = malloc(strlen(title) + 1);
  strcpy(p_book->title, title);

  p_book->author = malloc(strlen(author) + 1);
  strcpy(p_book->author, author);
}

void Book_clear(Book *p_book)
{
  p_book->pages = 0;
  p_book->price = 0.0;

  free(p_book->title);
  p_book->title = NULL;

  free(p_book->author);
  p_book->author = NULL;

}

void Book_set_title(Book *p_book, const char *new_title)
{
  // free(p_book->title);
  // p_book->title = malloc(strlen(new_title) + 1);

  p_book->title = realloc(p_book->title, strlen(new_title) + 1);
  strcpy(p_book->title, new_title);
}


void set_string(char **pdest, const char *src)
{
  // free(*psrc);
  // *psrc = malloc(strlen(src) + 1);

  *pdest = realloc(*pdest, strlen(src) + 1);
  strcpy(*pdest, src);
}

