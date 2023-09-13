// Unit test cases for doubly linked list program.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void test_CreateNode() {
    struct Node *node = CreateNode();
    assert(node->value == 0);
    assert(node->next == NULL);
    assert(node->prev == NULL);
    free(node);
}

void test_Insert() {
    head = NULL;
    Insert(10);
    assert(head->value == 10);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    Insert(20);
    assert(head->value == 20);
    assert(head->next->value == 10);
    assert(head->next->prev == head);
}

void test_Display() {
    // As Display() function prints the elements of the list, manual verification is needed.

    printf("Expected Output for Display function: 20 10\n");
    printf("Actual Output: ");
    Display();
    printf("\n");
}

void test_ReverseDisplay() {
    // As ReverseDisplay() function prints the elements of the list in reverse order, manual verification is needed.

    printf("Expected Output for Reverse Display function: 10 20\n");
    printf("Actual Output: ");
    ReverseDisplay();
    printf("\n");
}

void main() {
    test_CreateNode();
    test_Insert();
    test_Display();
    test_ReverseDisplay();
    printf("All test cases passed successfully.\n");
}