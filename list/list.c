#include "list.h"
#include <stdlib.h>
#include <stdio.h>

ListResult print_error(const char* message, const ListResult err) {
        fprintf(stderr, "Error : %s\n", message);
        return err;
}

LinkedList* new_list() {
        // Every attribute is set to 0
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

ListResult pop_n(LinkedList* list, int index) {
        if (!list) {
                return print_error("List pointer is NULL", LIST_NULL_ERROR);
        }

        if (list->head == NULL || index >= list->length) {
                return print_error("Index out of bounds", LIST_INDEX_ERROR);
        }

        if (list->length == 0) {
                return print_error("List is empty", LIST_EMPTY_ERROR);
        }

        // Pop head
        if (index == 0) {
                // This can be NULL when there's only one element in the list
                Node* new_head = list->head->next;
                free(list->head);
                list->head = new_head;
                
                if (new_head) {
                        new_head->prev = NULL;
                } else {
                        list->tail = NULL;
                }

                list->length -= 1;
        // Pop last element
        } else if (index == list->length - 1) {
                Node* second_last_node = list->tail->prev;
                if (!second_last_node) {
                        list->head = NULL;
                // There is no second last node, list only has one element
                } else { 
                        second_last_node->next = NULL;
                }

                free(list->tail);
                list->tail = second_last_node;
                list->length -= 1;
        } else {
                int middle_index = (list->length - 1) / 2;

                if (index > middle_index) {
                        int current_index = list->length - 1;

                        Node* current_node = list->tail;
                        while (current_index != index) {
                                current_node = current_node->prev;

                                if (!current_node) {
                                        return print_error("Unexpected NULL pointer while traversing", LIST_UNEXP_NULL);
                                }

                                current_index--;
                        }

                        current_node->prev->next = current_node->next;
                        if (current_node->next) {
                                current_node->next->prev = current_node->prev;
                        }
                        free(current_node);

                } else {
                        int current_index = 0;

                        Node* current_node = list->head;
                        while (current_index != index - 1) {
                                current_node = current_node->next;

                                if (!current_node) {
                                        return print_error("Unexpected NULL pointer while traversing", LIST_UNEXP_NULL);
                                }

                                current_index++;
                        }

                        Node* popped_node = current_node->next;
                        current_node->next = popped_node->next;
                        if (popped_node->next) {
                                popped_node->next->prev = current_node;
                        }
                        free(popped_node);
                }

                list->length -= 1;
        }

        return LIST_SUCCESS;
}

Node* insert_n(LinkedList* list, int value, int index) {
        if (!list) {
                print_error("List pointer is NULL", LIST_NULL_ERROR);
                return NULL;
        }

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
                        print_error("Index out of bounds", LIST_INDEX_ERROR);
                        return NULL;
                }
                Node* current_node = list->head;
                while (counter != index - 1) {
                        // Reached end of list
                        if (current_node->next == NULL) {
                                print_error("Index out of bounds", LIST_INDEX_ERROR);
                                return NULL;
                        }
                        current_node = current_node->next;
                        counter++;
                }

                Node* new_node = (Node*) calloc(1, sizeof(Node));

                if (!new_node) {
                        print_error("Could not allocate memory for new node", LIST_MEMORY_ERROR);
                        return NULL;
                }

                new_node->data = value;
                new_node->prev = current_node;

                Node* temp_node = current_node->next;
                if (temp_node) {
                        temp_node->prev = new_node;
                        new_node->next = temp_node;
                }

                current_node->next = new_node;

                list->length += 1;

                return new_node;
        }
}

void drop_list(LinkedList* list) {
        if (!list) {
                print_error("List pointer is NULL", LIST_NULL_ERROR);
                return;
        }

        free(list->cache);
        Node *current_node = list->head;

        if (current_node != NULL) {
                _node_free(current_node);
        }

        free(list);
}

// Recursive functions can eat away at the stack
void _node_free(Node* node) {
        if (node->next == NULL) {
                free(node);
        } else {
                _node_free(node->next);
                free(node);
        }
}

void print_list(LinkedList *list) {
        if (!list) {
                print_error("List pointer is NULL", LIST_NULL_ERROR);
                return;
        }

        if (list->length == 0) {
                printf("\n");
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
        if (!list) {
                print_error("List pointer is NULL", LIST_NULL_ERROR);
                return NULL;
        }

        Node *node = (Node*) calloc(1, sizeof(Node));
        node->data = value;

        // if list is empty
        if (list->head == NULL) {
                list->head = node;
                list->tail = node;
        } else {
                Node *current_head = list->head;
                current_head->prev = node;
                node->next = current_head;
                list->head = node;
        }
        list->length += 1;

        return node;
}

Node* append(LinkedList *list, int value) {
        if (!list) {
                print_error("List pointer is NULL", LIST_NULL_ERROR);
                return NULL;
        }

        Node *node = (Node*) calloc(1, sizeof(Node));
        node->next = NULL;
        node->prev = list->tail;
        node->data = value;

        // If list is empty
        if (list->head == NULL) {
                list->head = node;
        } else {
                list->tail->next = node;
        }

        list->tail = node;
        list->length += 1;

        return node;
}

int get(LinkedList* list, int index) {
        if (!list) {
                return print_error("List pointer is NULL", LIST_NULL_ERROR);
        }

        if (index < 0 || index >= list->length) {
                return print_error("Index out of bounds", LIST_INDEX_ERROR);
        }

        int counter = 0;
        Node* current_node = list->head;

        while (counter != index) {
                current_node = current_node->next;
                counter++;
        }

        return current_node->data;
}
