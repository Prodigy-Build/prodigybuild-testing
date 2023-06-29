


// DoublyLL_test.c
#include <stdio.h>
#include <stdlib.h>
#include "DoublyLL.h"

int main() {
    // Create a doubly linked list
    DoublyLL *list = createDoublyLL();

    // Insert elements into the list
    insertAtHead(list, 10);
    insertAtHead(list, 20);
    insertAtHead(list, 30);
    insertAtTail(list, 40);
    insertAtTail(list, 50);
    insertAtTail(list, 60);

    // Print the list
    printList(list);

    // Test the search function
    int searchVal = 30;
    Node *searchNode = search(list, searchVal);
    if (searchNode != NULL) {
        printf("Found %d in the list\n", searchVal);
    } else {
        printf("%d not found in the list\n", searchVal);
    }

    // Test the delete function
    int deleteVal = 40;
    deleteNode(list, deleteVal);
    printf("After deleting %d:\n", deleteVal);
    printList(list);

    // Free the list
    freeDoublyLL(list);

    return 0;
}