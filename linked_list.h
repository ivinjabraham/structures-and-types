#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t;
typedef signed short int int16_t;

/**
 * @brief Represents a node in a linked list.
 */
typedef struct Node {
    int16_t data;
    struct Node *next; 
} Node;

/**
 * @brief Represents the linked list.
 */
typedef struct LinkedList {
    Node* head;
} LinkedList;



LinkedList* createLinkedList();

void insertNode(LinkedList* list, uint8_t index);
void appendNode(LinkedList* list, int16_t data);

void pop(LinkedList* list);
void deleteNode(LinkedList* list, uint8_t index);
void deleteHead(LinkedList* list);

void printList(LinkedList* list);
size_t getLength(const LinkedList* list);
int isEmpty(const LinkedList* list);

void destroyLinkedList(LinkedList* list);

void abortProgram();
void* saferAlloc(size_t n);

#endif
