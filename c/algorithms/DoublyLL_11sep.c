// Test suite for Doubly linked list.
#include <assert.h>
#include <stdio.h>

void test_CreateNode() {
    struct Node *node = CreateNode();
    assert(node->value == 0);
    assert(node->next == NULL);
    assert(node->prev == NULL);
    free(node);
}

void test_Insert() {
    Insert(5);
    assert(head->value == 5);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    Insert(10);
    assert(head->value == 10);
    assert(head->next->value == 5);
    assert(head->next->prev->value == 10);
}

void test_Display() {
    Insert(5);
    Insert(10);
    Insert(15);
    printf("\nExpected Forward Output: 15 10 5\nActual Output: ");
    Display();
}

void test_ReverseDisplay() {
    Insert(5);
    Insert(10);
    Insert(15);
    printf("\nExpected Backward Output: 5 10 15\nActual Output: ");
    ReverseDisplay();
}

void main() {
    test_CreateNode();
    test_Insert();
    test_Display();
    test_ReverseDisplay();
    printf("All Unit Test Passed!\n");
}