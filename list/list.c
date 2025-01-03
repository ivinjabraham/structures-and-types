#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


LinkedList* new_list() {
        LinkedList* list = (LinkedList*) calloc(1, sizeof(LinkedList));
        if (list == NULL) {
                return ENOMEM;
        }

        // Ignore cache for now, will implement later
        Node* cache = (Node*) calloc(5, sizeof(Node));
        if (cache == NULL) {
                return ENOMEM;
        }
        list->cache = cache;

        return list;
}

int pop_n(LinkedList* list, int value, int index);
int insert_n(LinkedList* list, int value, int index);
void drop_list(LinkedList* list) {
        free(list);
}

int insert_front(LinkedList* list, int value);
int append(LinkedList *list, int value) {
        Node *node = (Node*) calloc(1, sizeof(Node));
        node->next = NULL;
        node->data = value;

        // If list is empty
        if (list->head == NULL) {
                list->head = node;
                list->tail = node;
                list->length = 1;
        } else {
                list->tail->next = node;
                list->tail = node;
                list->length += 1;
        }
}
