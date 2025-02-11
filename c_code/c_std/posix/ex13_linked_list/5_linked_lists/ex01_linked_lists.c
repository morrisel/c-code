#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

typedef struct Node Node;
struct Node {
    int value;
    Node *next;
};

typedef struct List List;
struct List {
    Node *head;
};

void init_list(List *list);
Node* create_node(int value);
void push(List *list, Node *node);
Node* pop(List *list);
void print_list(const List *list);

int main(void) {
    List list1 = { 0 };
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


//TODO: assert pointers as arguments are not null where relevant

void init_list(List *list) {
    list->head = NULL;
}

Node* create_node(int value) {
    Node *new_node = malloc(sizeof (Node));
    //TODO: check new_node not NULL;
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}
void push(List *list, Node *node) {
    node->next = list->head;
    list->head = node;
}

Node* pop(List *list) {
    if (list->head == NULL) {
        return NULL;
    }

    Node *node = list->head;
    
    //list->head = list->head->next;
    list->head = node->next;

    //dettach the popped node from 
    //the rest of the list
    node->next = NULL;

    return node;
}

void print_list(const List *list) {
    Node *curr = list->head;

    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    puts("");
}
