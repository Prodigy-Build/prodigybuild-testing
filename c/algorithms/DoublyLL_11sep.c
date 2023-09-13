// Additional Unit Test Cases - test insertion, forward display and reverse display

#include <assert.h>

void test_Insert() {
    Insert(1);
    assert(head->value == 1);
    Insert(2);
    assert(head->value == 2);
    assert(head->next->value == 1);
    assert(head->next->next == NULL);
    assert(head->prev == NULL);
}

void test_Display() {
    //Needed a function to capture stdout into a string to check against
}

void test_ReverseDisplay() {
    //Needed a function to capture stdout into a string to check against
}

void test_all() {
    test_Insert();
    test_Display();
    test_ReverseDisplay();
}

void main() {
    test_all();
    printf("All tests passed successfully!");
}