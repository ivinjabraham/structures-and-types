#ifndef LINKED_LIST
#define LINKED_LIST

#include <stddef.h>

// ---
// Struct Defintions
// ---
typedef struct Node {
        int data;
        struct Node* next;
        struct Node* prev;
} Node;

typedef struct LinkedList {
        Node *head;
        Node *tail;

        // Metadata
        int length;

        // Not implemented yet.
        Node *cache;
} LinkedList;


// ---
// Methods
// ---

LinkedList* new_list();
int get(LinkedList* list, int index);
void pop_n(LinkedList* list, int index);
Node* insert_n(LinkedList* list, int value, int index);
void drop_list(LinkedList* list);
void print_list(LinkedList *list);

Node* insert_front(LinkedList* list, int value);
Node* append(LinkedList *list, int value);
void _node_free(Node* node);

// Not Implemented
// ---

// Extras
int disable_tail_pointer(LinkedList *list);
int disable_cache(LinkedList *list);

#endif
