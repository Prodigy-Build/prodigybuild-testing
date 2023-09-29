#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    int data;
    struct node *next;
};
struct node *head;

struct node *CreateNode() {
    struct node *new = (struct node*) malloc(sizeof(struct node));
    return new;
}

void test_InsertAtBegin() {
    head = NULL;
    InsertAtBegin(10);
    assert(head->data == 10);
    assert(head->next == NULL);
    InsertAtBegin(20);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next == NULL);
    printf("InsertAtBegin() - Passed\n");
}

void test_InsertAtnthNode() {
    head = NULL;
    InsertAtBegin(10);
    InsertAtnthNode(2, 30);
    assert(head->data == 10);
    assert(head->next->data == 30);
    assert(head->next->next == NULL);
    InsertAtnthNode(1, 20);
    assert(head->data == 20);
    assert(head->next->data == 10);
    assert(head->next->next->data == 30);
    assert(head->next->next->next == NULL);
    printf("InsertAtnthNode() - Passed\n");
}

void test_InsertAtEnd() {
    head = NULL;
    InsertAtEnd(10);
    assert(head->data == 10);
    assert(head->next == NULL);
    InsertAtEnd(20);
    assert(head->data == 10);
    assert(head->next->data == 20);
    assert(head->next->next == NULL);
    printf("InsertAtEnd() - Passed\n");
}

void test_DeleteAtBegin() {
    head = NULL;
    DeleteAtBegin();
    assert(head == NULL);
    InsertAtBegin(10);
    InsertAtBegin(20);
    DeleteAtBegin();
    assert(head->data == 10);
    assert(head->next == NULL);
    printf("DeleteAtBegin() - Passed\n");
}

void test_DeleteAtEnd() {
    head = NULL;
    DeleteAtEnd();
    assert(head == NULL);
    InsertAtBegin(10);
    InsertAtBegin(20);
    DeleteAtEnd();
    assert(head->data == 20);
    assert(head->next == NULL);
    printf("DeleteAtEnd() - Passed\n");
}

void test_DeletenthNode() {
    head = NULL;
    DeletenthNode(1);
    assert(head == NULL);
    InsertAtBegin(10);
    InsertAtBegin(20);
    InsertAtBegin(30);
    DeletenthNode(2);
    assert(head->data == 30);
    assert(head->next->data == 10);
    assert(head->next->next == NULL);
    printf("DeletenthNode() - Passed\n");
}

void test_Display() {
    head = NULL;
    Display();
    assert(head == NULL);
    InsertAtBegin(10);
    InsertAtBegin(20);
    InsertAtBegin(30);
    Display();
    printf("\nExpected Output: \nCurrent List:\n30 20 10 ");
    printf("\n\n");
    printf("Display() - Passed\n");
}

int main() {
    test_InsertAtBegin();
    test_InsertAtnthNode();
    test_InsertAtEnd();
    test_DeleteAtBegin();
    test_DeleteAtEnd();
    test_DeletenthNode();
    test_Display();
    return 0;
}