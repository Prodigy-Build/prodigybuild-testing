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
    // Test case 1: Inserting 5
    Insert(5);
    assert(head->value == 5);
    assert(head->next == NULL);
    assert(head->prev == NULL);

    // Test case 2: Inserting 10
    Insert(10);
    assert(head->value == 10);
    assert(head->next->value == 5);
    assert(head->next->prev == head);

    // Test case 3: Inserting 15
    Insert(15);
    assert(head->value == 15);
    assert(head->next->value == 10);
    assert(head->next->prev == head);
}

void testDisplay() {
    // Test case 1: Displaying an empty list
    Display(); // No assertions, just verifying no errors occur

    // Test case 2: Displaying a list with elements
    Insert(5);
    Insert(10);
    Insert(15);
    Display(); // No assertions, just verifying no errors occur
}

void testReverseDisplay() {
    // Test case 1: Reverse displaying an empty list
    ReverseDisplay(); // No assertions, just verifying no errors occur

    // Test case 2: Reverse displaying a list with elements
    Insert(5);
    Insert(10);
    Insert(15);
    ReverseDisplay(); // No assertions, just verifying no errors occur
}

void test() {
    testInsert();
    testDisplay();
    testReverseDisplay();
}

int main() {
    test();
    return 0;
}