#include <assert.h>

void testInsert() {
    // Test inserting a single element
    Insert(5);
    assert(head->value == 5);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    // Test inserting multiple elements
    Insert(10);
    assert(head->value == 10);
    assert(head->next->value == 5);
    assert(head->next->prev == head);
    assert(head->next->next == NULL);

    Insert(15);
    assert(head->value == 15);
    assert(head->next->value == 10);
    assert(head->next->prev == head);
    assert(head->next->next->value == 5);
    assert(head->next->next->prev == head->next);
    assert(head->next->next->next == NULL);
}

void testDisplay() {
    // Set up test case
    head = NULL;
    Insert(5);
    Insert(10);
    Insert(15);
    
    // Test Display()
    Display();
    // Output should be "Forward:\n15 10 5"

    // Test ReverseDisplay()
    ReverseDisplay();
    // Output should be "Backward:\n5 10 15"
}

int main() {
    testInsert();
    testDisplay();
    return 0;
}