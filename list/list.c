#include "list.h"
#include <stdlib.h>
#include <stdio.h>


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

void pop_n(LinkedList* list, int index) {
        // Pop head
        if (list->head == NULL || index >= list->length) {
                printf("ERR: Index out of bounds.\n");
                exit(-1);
        }

        if (index == 0) {
                // This can be NULL
                Node* new_head = list->head->next;
                free(list->head);
                list->head = new_head;
                list->length -= 1;
        } else if (index == list->length - 1) {
                Node* traversal_node = list->head;

                while (traversal_node->next->next != NULL) {
                        traversal_node = traversal_node->next;
                }

                traversal_node->next = NULL;
                free(list->tail);
                list->tail = traversal_node;
                list->length -= 1;
        } else {
                int counter = 0;

                Node* current_node = list->head;
                while (counter != index - 1) {
                        current_node = current_node->next;
                        counter++;
                }

                Node* popped_node = current_node->next;
                current_node->next = popped_node->next;
                free(popped_node);
                list->length -= 1;
        }
}

Node* insert_n(LinkedList* list, int value, int index) {
        // Replace head with new node
        if (index == 0) {
                Node* new_node = insert_front(list, value);
                return new_node;

        // Add node to the end
        } else if (index == list->length) {
                Node* new_node = append(list, value);
                list->tail = new_node;
                return new_node;

        // Add node to somewhere in between
        } else {
                int counter = 0;

                // Empty list
                if (list->head == NULL) {
                        printf("ERR: Index out of bounds.\n");
                        exit(-1);
                }
                Node* current_node = list->head;
                while (counter != index - 1) {
                        // Reached end of list
                        if (current_node->next == NULL) {
                                printf("ERR: Index out of bounds.\n");
                                exit(-1);
                        }
                        current_node = current_node->next;
                        counter++;
                }

                Node* new_node = (Node*) calloc(1, sizeof(Node));
                new_node->data = value;

                Node* temp_node = current_node->next;
                current_node->next = new_node;
                new_node->next = temp_node;

                return new_node;
        }
}

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

int get(LinkedList* list, int index) {
        if (index < 0 || index >= list->length) {
                printf("ERR: Index out of bounds.\n");
                exit(-1);
        }
        int counter = 0;
        Node* current_node = list->head;

        while (counter != index) {
                current_node = current_node->next;
                counter++;
        }

        return current_node->data;
}
