#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

/*
 * @brief Creates a new, empty linked list.
 *
 * @return A pointer to a linked list struct.
 */
LinkedList* createLinkedList() 
{
    LinkedList* list = (LinkedList*)saferAlloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

/*
 * @brief Adds a node to the end of the linked list.
 *
 * @param   list    A pointer to a linked list in which the new node will be added.
 * @param   node    A pointer to a node that is to be added.
 */
void appendNode(LinkedList* list, int16_t data) 
{
    Node* node = (Node*)saferAlloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        return;
    }

    Node* current_node = list->head;

    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = node;
}

/*
 * @brief Deletes the initial node from a linked list.
 *
 * @param   list    Pointer to the linked list to delete from.
 */
void pop(LinkedList* list) 
{
}

/* 
 * @brief Deletes a node from a linked list, given it's index.
 *
 * @param   list    Pointer to the linked list to delete from.
 * @param   index   Index of the node to be deleted.
 */
void removeNode(Node* list, uint8_t index) 
{
}

/*
 * @brief Iterates through the linked list and prints data of each node to stdout.
 *
 * @param   node_ptr   A pointer to a node.
 */
void printList(LinkedList* list) 
{
    // Empty list
    if (list->head == NULL) {
        printf("The list is empty.");
        return;
    }

    const Node* current_node = list->head;

    while (current_node->next != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    // Accounts for last node
    printf("%d.\n", current_node->data);
}

/*
 * @brief Finds the length of the linked list from it's head pointer. Technically, it can find the length of a slice as well
 *        since the implementation works as long as it's a valid node. 
 *
 * @param   list    A pointer to a linked list.
 *
 * @return Length (number of nodes) of the list.
 */
size_t getLength(const LinkedList* list) 
{

    size_t length = 0;

    // Empty list
    if (list->head == NULL) {
        return length;
    }

    Node* current_node = list->head;
    while(current_node->next != NULL) {
        current_node = current_node->next;
        length++;
    }

    // Accounts for last node
    length++; 

    return length;
}

void abortProgram() 
{
    // TODO cleanup allocated memory before aborting
    abort();
}

/**
 * @brief   Error handling for malloc; will abort program cleanly if allocation fails.
 *
 * @param   n   Number of bytes to allocate
 *
 * @return  A void pointer to allocated memory if successful; otherwise, NULL;
 */
void* saferAlloc(size_t n) 
{
    void *ptr = malloc(n);

    if (ptr == NULL) {
        fprintf(stderr, "Fatal: Failed to allocate %zu bytes.\n.", n);
        abortProgram();
    }

    return ptr;
}
