#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;

// Unit test for the Insert function
void testInsert() {
    Insert(1);
    Insert(2);
    Insert(3);
    
    assert(head->value == 3);
    assert(head->next->value == 2);
    assert(head->next->next->value == 1);
}

// Unit test for the Display function
void testDisplay() {
    // Assuming the list has 3 elements: 3, 2, 1
    Display(); // Expected output: 3 2 1
}

// Unit test for the ReverseDisplay function
void testReverseDisplay() {
    // Assuming the list has 3 elements: 3, 2, 1
    ReverseDisplay(); // Expected output: 1 2 3
}

// Main function to run the unit tests
int main() {
    testInsert();
    testDisplay();
    testReverseDisplay();
    return 0;
}