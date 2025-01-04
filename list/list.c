#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


LinkedList* new_list() {
        LinkedList* list = (LinkedList*) calloc(1, sizeof(LinkedList));
        if (list == NULL) {
                return NULL;
        }

        // Ignore cache for now, will implement later
        Node* cache = (Node*) calloc(5, sizeof(Node));
        if (cache == NULL) {
                return NULL;
        }
        list->cache = cache;

        return list;
}

int pop_n(LinkedList* list, int value, int index);
int insert_n(LinkedList* list, int value, int index);
void drop_list(LinkedList* list) {
        free(list->cache);
        Node *current_node = list->head;

        if (current_node != NULL) {
                _node_free(current_node);
        }

        free(list);
}

void _node_free(Node* node) {
        if (node->next == NULL) {
                free(node);
        } else {
                _node_free(node->next);
                free(node);
        }
}

void print_list(LinkedList *list) {
        if (list->length == 0) {
                return;
        }

        Node *current_node = list->head;
        printf("[");
        while (current_node->next != NULL) {
                printf("%d, ", current_node->data);
                current_node = current_node->next;
        }
        printf("%d]\n", current_node->data);

        return;
}

Node* insert_front(LinkedList* list, int value) {
        Node *node = (Node*) calloc(1, sizeof(Node));
        node->data = value;

        // if list is empty
        if (list->head == NULL) {
                list->head = node;
                list->tail = node;
        } else {
                Node *current_head = list->head;
                node->next = current_head;
                list->head = node;
        }
        list->length += 1;

        return node;
}

Node* append(LinkedList *list, int value) {
        Node *node = (Node*) calloc(1, sizeof(Node));
        node->next = NULL;
        node->data = value;

        // If list is empty
        if (list->head == NULL) {
                list->head = node;
                list->tail = node;
        } else {
                list->tail->next = node;
                list->tail = node;
        }

        list->length += 1;

        return node;
}
