#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef unsigned char __uint8_t;
typedef __uint8_t unint8_t;

/**
 * @brief Represents a node in a linked list.
 */
typedef struct Node {
    int data;
    struct Node *next; 
} Node;

/**
 * @brief Represents the linked list.
 */
typedef struct LinkedList {
    Node* head;
} LinkedList;

/**
 * @brief Performs necessary actions before terminating the program.
 */
void abortProgram() {
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
void* saferAlloc(size_t n) {
    void *ptr = malloc(n);

    if (ptr == NULL) {
        fprintf(stderr, "Fatal: Failed to allocate %zu bytes.\n.", n);
        abortProgram();
    }

    return ptr;
}

/*
 * @brief Creates a new, empty linked list.
 *
 * @return A pointer to a linked list struct.
 */
LinkedList newLinkedList() 
{
    LinkedList list = {
        NULL
    };

    return list;
}

/*
 * @brief Iterates through the linked list and prints data of each node to stdout.
 *
 * @param   node_ptr   A pointer to a node.
 */
void printList(Node* node_ptr) 
{
    Node* current_node = node_ptr;

    while (current_node->next != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }

    printf("%d.\n", current_node->data);
}

/*
 * @brief Adds a node to the end of the linked list.
 *
 * @param   list    A pointer to a linked list in which the new node will be added.
 * @param   node    A pointer to a node that is to be added.
 */
void appendNode(LinkedList* list, Node* node) 
{
}

/*
 * @brief Finds the length of the linked list from it's head pointer. Technically, it can find the length of a slice as well
 *        since the implementation works as long as it's a valid node. 
 *
 * @param   list    A pointer to a linked list.
 *
 * @return Length (number of nodes) of the list.
 */
uint8_t getListLength(LinkedList* list) {
    uint8_t length = 0;

    Node* current_node = list->head;
    while(current_node->next != NULL) {
        current_node = current_node->next;
        length++;
    }

    // Accounts for last node
    length++; 

    return length;
}

/*
 * @brief Deletes the initial node from a linked list.
 *
 * @param   list    Pointer to the linked list to delete from.
 */
void deleteInitialNode(Node* list) {
    Node* new_head_node = list->next; 
    free(list);
}

/* 
 * @brief Deletes a node from a linked list, given it's index.
 *
 * @param   list    Pointer to the linked list to delete from.
 * @param   index   Index of the node to be deleted.
 */
void deleteNode(Node* list, uint8_t index) 
{
    Node* current_node = (Node*)saferAlloc(sizeof(Node));

    if (index == 0) {
    } else {  
        int currentIndex = 0;
        Node* current_node = head_node;
        while (currentIndex != index - 1) {
            if (current_node->next != NULL) {
                current_node = current_node->next;
                currentIndex += 1;
            } else {
                printf("Invalid index.\n");
                return head_node;
            }
        }
        
        if ((current_node->next) == NULL) {
            free(current_node->next);
            current_node->next = NULL;
        }
        else {
            Node* addr = (current_node->next)->next;
            free(current_node->next);
            current_node->next = addr;
        }
        return head_node;
    }
}

