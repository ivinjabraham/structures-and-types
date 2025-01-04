#ifndef LINKED_LIST
#define LINKED_LIST

#include <stddef.h>

// ---
// Struct Defintions
// ---
typedef struct Node {
        int data;
        struct Node* next;
} Node;

typedef struct LinkedList {
        Node *head;

        // Metadata
        int length;

        // Optional fields, can be disabled via methods
        Node *tail;
        Node *cache;
} LinkedList;


// ---
// Methods
// ---

LinkedList* new_list();
int pop_n(LinkedList* list, int value, int index);
int insert_n(LinkedList* list, int value, int index);
void drop_list(LinkedList* list);
void print_list(LinkedList *list);

Node* insert_front(LinkedList* list, int value);
Node* append(LinkedList *list, int value);
void _node_free(Node* node);

// Extras
int disable_tail_pointer(LinkedList *list);
int disable_cache(LinkedList *list);

#endif
