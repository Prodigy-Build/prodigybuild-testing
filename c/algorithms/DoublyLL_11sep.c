// Adding Unit Test for DoublyLL.c
#include <stdio.h>
#include <assert.h>

void test() {
    // Test Case 1: Add 1 element and display
    head = NULL; // Clear existing list
    Insert(5);
    struct Node *temp1 = head;
    assert(temp1->value == 5);
    assert(temp1->next == NULL);
    assert(temp1->prev == NULL);

    // Test Case 2: Add multiple elements and display
    head = NULL; // Clear existing list
    Insert(10);
    Insert(20);
    Insert(30);
    struct Node *temp2 = head;
    assert(temp2->value == 30);
    assert(temp2->next->value == 20);
    assert(temp2->next->next->value == 10);
    assert(temp2->next->next->next == NULL);
    assert(temp2->prev == NULL);
    assert(temp2->next->prev == temp2);
    assert(temp2->next->next->prev == temp2->next);
}

int main() {
    test();
    return 0;
}