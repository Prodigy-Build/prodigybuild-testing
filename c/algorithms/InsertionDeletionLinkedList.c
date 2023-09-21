#include <assert.h>
#include <string.h>

// Function Declarations for Unit Tests
void test_InsertAtBegin();
void test_InsertAtnthNode();
void test_InsertAtEnd();
void test_DeleteAtBegin();
void test_DeleteAtEnd();
void test_DeletenthNode();
void test_Display();

// Unit Tests
int main() {
    test_InsertAtBegin();
    test_InsertAtnthNode();
    test_InsertAtEnd();
    test_DeleteAtBegin();
    test_DeleteAtEnd();
    test_DeletenthNode();
    test_Display();
}

void test_InsertAtBegin() {
    head = NULL;
    InsertAtBegin(10);
    assert(head->data == 10);
    assert(head->next == NULL);
}

void test_InsertAtnthNode() {
    head = NULL;
    InsertAtBegin(10);
    InsertAtnthNode(2, 20);
    assert(head->data == 10);
    assert(head->next->data == 20);
}

void test_InsertAtEnd() {
    head = NULL;
    InsertAtBegin(10);
    InsertAtEnd(20);
    assert(head->data == 10);
    assert(head->next->data == 20);
}

void test_DeleteAtBegin() {
    head = NULL;
    InsertAtBegin(10);
    DeleteAtBegin();
    assert(head == NULL);
}

void test_DeleteAtEnd() {
    head = NULL;
    InsertAtBegin(10);
    InsertAtEnd(20);
    DeleteAtEnd();
    assert(head->data == 10);
    assert(head->next == NULL);
}

void test_DeletenthNode() {
    head = NULL;
    InsertAtBegin(10);
    InsertAtEnd(20);
    DeletenthNode(2);
    assert(head->data == 10);
    assert(head->next == NULL);
}

void test_Display() {
    head = NULL;
    InsertAtBegin(10);
    assert(head->data == 10);
    InsertAtEnd(20);
    assert(head->next->data == 20);
}