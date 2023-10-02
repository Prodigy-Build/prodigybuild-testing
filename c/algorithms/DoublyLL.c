// Implementing Doubly linked list.
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;

struct Node *CreateNode() {
    struct Node *new = (struct Node*) malloc(sizeof(struct Node));
    return new;
}

void Insert(int val) { /*Inserting element at head*/
    struct Node *NewNode = CreateNode(); /*NewNode is created everytime function is called*/
    NewNode->value = val; /*Value assigned to NewNode*/
    NewNode->next = head; /*NewNode's next points to head*/
    NewNode->prev = NULL; /*NewNode's previous points to NULL*/
    if (head != NULL) { 
        head->prev = NewNode;
    }
    head = NewNode;
}

void Display() {
    struct Node *temp = head;
    printf("\nForward:\n"); /*Printing normally in forward manner*/
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->next;
    }
}

void ReverseDisplay() {
    struct Node *temp = head;
    while(temp->next!=NULL) { /*Moving to the last node*/
        temp = temp->next;
    }

    printf("\nBackward:\n"); /*Printing in backward manner*/
    while(temp!=NULL) {
        printf("%d ",temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

void testInsert() {
    // Test Case 1
    Insert(1);
    assert(head->value == 1);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    // Test Case 2
    Insert(2);
    assert(head->value == 2);
    assert(head->next->value == 1);
    assert(head->next->next == NULL);
    assert(head->next->prev == head);

    // Test Case 3
    Insert(3);
    assert(head->value == 3);
    assert(head->next->value == 2);
    assert(head->next->next->value == 1);
    assert(head->next->prev == head);
    assert(head->next->next == head->prev);
    assert(head->prev == head->next->next);
}

void testDisplay() {
    // Test Case 1
    Insert(1);
    Insert(2);
    Insert(3);
    printf("\nExpected Output:\nForward:\n3 2 1");
    printf("\nActual Output:\n");
    Display();

    // Test Case 2
    printf("\nExpected Output:\nForward:\n1");
    printf("\nActual Output:\n");
    Display();
}

void testReverseDisplay() {
    // Test Case 1
    Insert(1);
    Insert(2);
    Insert(3);
    printf("\nExpected Output:\nBackward:\n1 2 3");
    printf("\nActual Output:\n");
    ReverseDisplay();

    // Test Case 2
    printf("\nExpected Output:\nBackward:\n1");
    printf("\nActual Output:\n");
    ReverseDisplay();
}

int main() {
    testInsert();
    testDisplay();
    testReverseDisplay();
    return 0;
}