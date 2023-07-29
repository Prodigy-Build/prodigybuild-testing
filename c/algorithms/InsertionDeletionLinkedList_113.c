

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Unit test cases for InsertAtBegin()
void test_InsertAtBegin() {
    struct node *head = NULL;
    InsertAtBegin(1);
    assert(head->data == 1);
    InsertAtBegin(2);
    assert(head->data == 2);
    assert(head->next->data == 1);
}

// Unit test cases for InsertAtnthNode()
void test_InsertAtnthNode() {
    struct node *head = NULL;
    InsertAtBegin(1);
    InsertAtBegin(2);
    InsertAtnthNode(2, 3);
    assert(head->data == 2);
    assert(head->next->data == 3);
    assert(head->next->next->data == 1);
}

// Unit test cases for InsertAtEnd()
void test_InsertAtEnd() {
    struct node *head = NULL;
    InsertAtBegin(1);
    InsertAtBegin(2);
    InsertAtEnd(3);
    assert(head->data == 2);
    assert(head->next->data == 1);
    assert(head->next->next->data == 3);
}

// Unit test cases for DeleteAtBegin()
void test_DeleteAtBegin() {
    struct node *head = NULL;
    InsertAtBegin(1);
    InsertAtBegin(2);
    DeleteAtBegin();
    assert(head->data == 1);
    DeleteAtBegin();
    assert(head == NULL);
}

// Unit test cases for DeleteAtEnd()
void test_DeleteAtEnd() {
    struct node *head = NULL;
    InsertAtBegin(1);
    InsertAtBegin(2);
    DeleteAtEnd();
    assert(head->data == 2);
    DeleteAtEnd();
    assert(head == NULL);
}

// Unit test cases for DeletenthNode()
void test_DeletenthNode() {
    struct node *head = NULL;
    InsertAtBegin(1);
    InsertAtBegin(2);
    InsertAtBegin(3);
    DeletenthNode(2);
    assert(head->data == 3);
    assert(head->next->data == 1);
    DeletenthNode(2);
    assert(head->data == 3);
    assert(head->next == NULL);
}

int main() {
    test_InsertAtBegin();
    test_InsertAtnthNode();
    test_InsertAtEnd();
    test_DeleteAtBegin();
    test_DeleteAtEnd();
    test_DeletenthNode();
    printf("All tests passed!\n");
    return 0;
}