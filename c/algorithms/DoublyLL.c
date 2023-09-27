#include <assert.h>

void testInsert() {
    head = NULL;

    Insert(5);
    assert(head != NULL);
    assert(head->value == 5);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    Insert(10);
    assert(head != NULL);
    assert(head->value == 10);
    assert(head->next != NULL);
    assert(head->prev == NULL);
    assert(head->next->value == 5);
}

void runTests() {
    testInsert();
}

int main() {
    runTests();
    return 0;
}