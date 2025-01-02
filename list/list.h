#ifndef LINKED_LIST
#define LINKED_LIST

#include <stddef.h>

// ---
// Struct Defintions
// ---
typedef struct Node {
        int data;
        Node* next;
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
int drop_list(LinkedList* list);

int insert_front(LinkedList* list, int value);
int append(LinkedList *list, int value);

// Extras
int disable_tail_pointer(LinkedList *list);
int disable_cache(LinkedList *list);

#endif
