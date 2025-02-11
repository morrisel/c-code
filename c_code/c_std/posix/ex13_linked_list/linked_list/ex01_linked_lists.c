#include <stdio.h>
#include <stdlib.h>


typedef struct Node Node;
struct Node
{
  int  value;
  Node *next;
};

typedef struct List List;
struct List
{
  Node *head;
};

void  init_list (List *plist);
Node* create_node (int value);
void  push (List *plist, Node *node);
Node* pop (List *plist);
void  print_list (const List *plist);


int main(void)
{
  List list1 = {0};
  init_list(&list1);

  Node *node = create_node(10);
  push(&list1, node);

  push(&list1, create_node(20));
  push(&list1, create_node(30));
  
  print_list(&list1);

  push(&list1, create_node(40));
  push(&list1, create_node(50));

  print_list(&list1);


  return 0;
}


// TODO: assert pointer as arguments are not null where relevant

void init_list(List *plist)
{
  // TODO: assert list is not null

  plist->head = NULL;
}

Node* create_node(int value)
{
  Node *new_node  = malloc(sizeof(Node));
  // TODO: check new_node not NULL

  new_node->value = value;
  new_node->next  = NULL;

  return new_node;
}

void push(List *plist, Node *node)
{
  node->next  = plist->head;
  plist->head = node;
}

Node* pop(List *plist)
{
  if (plist->head == NULL)
    return NULL;

  Node *popped_node = plist->head;

  // plist->head = plist->head->next;
  plist->head = popped_node->next;

  // detach the popped node from the rest of the list
  popped_node->next = NULL;

  return popped_node;
}

void print_list(const List *plist)
{
  Node *curr = plist->head;
  while (curr != NULL)
  {
    printf("%d ", curr->value);
    curr = curr->next;
  }
  puts("");
}



/*
typedef struct Node Node;
struct Node
{
  int  value;
  Node *next;
};

typedef struct List List;
struct List
{
  Node *head;
};

*/





