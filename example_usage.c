#include <stdio.h>
#include "linked_list.h"

int main() {
    LinkedList* myLinkedList = createLinkedList();

    appendNode(myLinkedList, 42);
    appendNode(myLinkedList, 99);

    printf("Linked list length: %zu\n", getLength(myLinkedList));
    printList(myLinkedList);

    return 0;
}
