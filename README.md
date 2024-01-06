# Common Data Structures, in C

# Linked List

This Linked List has two major design goals:
- To have a straightforward and easy-to-use API for users.
- To have a robust and "production-ready" implementation under the hood.

## Data Structures

### `Node`

Represents a node in a linked list.

- **Properties**
    - `data`: int16_t; data stored in the node.
    - `next`: Node\*; pointer to the next node.

### `LinkedList`

Represents the linked list.

- **Properties**
    - `head`: Node\*; pointer to the first node in the list.

## Functions

### `LinkedList* createLinkedList(void)`

Creates and initializes an empty linked list.

- **Returns:** A pointer to the newly created linked list.

### `void insertNode(LinkedList* list, uint8_t index)`

Inserts a new node at the specified index in the linked list. If the index is out of bounds, the node is appended to the end.

- **Parameters:**
  - `list`: Pointer to the linked list.
  - `index`: Index at which to insert the new node.

### `void appendNode(LinkedList* list, int16_t data)`

Appends a new node with the given data at the end of the linked list.

- **Parameters:**
  - `list`: Pointer to the linked list.
  - `data`: Data to be stored in the new node.

### `void pop(LinkedList* list)`

Removes the last node from the linked list.

- **Parameters:**
  - `list`: Pointer to the linked list.

### `void deleteNode(LinkedList* list, uint8_t index)`

Removes the node at the specified index from the linked list.

- **Parameters:**
  - `list`: Pointer to the linked list.
  - `index`: Index of the node to be removed.

### `void deleteHead(LinkedList* list)`

Deletes the head node of the linked list.

- **Parameters:**
  - `list`: Pointer to the linked list.

### `void printLinkedList(const LinkedList* list)`

Prints the elements of the linked list.

- **Parameters:**
  - `list`: Pointer to the linked list.

### `size_t getLength(const LinkedList* list)`

Returns the number of nodes in the linked list.

- **Parameters:**
  - `list`: Pointer to the linked list.
- **Returns:** Size of the linked list.

### `int isEmpty(const LinkedList* list)`

Checks if the linked list is empty.

- **Parameters:**
  - `list`: Pointer to the linked list.
- **Returns:** `1` if the list is empty, `0` otherwise.

### `void destroyLinkedList(LinkedList* list)`

Frees the memory occupied by the linked list.

- **Parameters:**
  - `list`: Pointer to the linked list.

## Example Usage

```c
#include <stdio.h>
#include <stdint.h>
#include "linked_list.h"

int main() {
    LinkedList* myLinkedList = createLinkedList();

    appendNode(myLinkedList, 42);
    appendNode(myLinkedList, 99);
    insertNode(myLinkedList, 1, 55);
    deleteHead(myLinkedList);

    printf("Linked list length: %zu\n", getLength(myLinkedList));
    printLinkedList(myLinkedList);

    destroyLinkedList(myLinkedList);

    return 0;
}
