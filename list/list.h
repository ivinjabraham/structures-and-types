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

typedef enum {
        LIST_SUCCESS = 0,
        LIST_NULL_ERROR = -1,
        LIST_INDEX_ERROR = -2,
        LIST_MEMORY_ERROR = -3,
        LIST_EMPTY_ERROR = -4,
        LIST_UNEXP_NULL = -5,
} ListResult;

// ---
// Methods
// ---

LinkedList* new_list();
int get(LinkedList* list, int index);
ListResult pop_n(LinkedList* list, int index);
Node* insert_n(LinkedList* list, int value, int index);
void drop_list(LinkedList* list);
void print_list(LinkedList* list);
ListResult clear_list(LinkedList* list);

Node* insert_front(LinkedList* list, int value);
Node* append(LinkedList *list, int value);
void _node_free(Node* node);

#endif
